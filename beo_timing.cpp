/**
 *******************************************************************************
 * \file    beo_timing.cpp
 *******************************************************************************
 * \brief    Hauptklasse der Applikation
 *
 * \version		1.0
 * \date		09.06.2008
 * \author		R.Zoss
 *
 * Copyright (C) 2008 Rico Zoss
 *
 * This file is part of BEO-Timing Managementsoftware.
 *
 * BEO-Timing Managementsoftware is free software: you can redistribute
 * it and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * BEO-Timing Managementsoftware is distributed in the hope that it will
 * be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with BEO-Timing Managementsoftware.  If not, see <http://www.gnu.org/licenses/>.
 *
 *******************************************************************************
 */


#include "beo_timing.h"
#include "tableeditdialog.h"
#include "RFID_Reader/rfidinputdialog.h"
#include "RFID_Reader/RFID_CR500.h"
#include "logondialog.h"
#include "Database.h"
#include "dbThread.h"
#include "User.h"
#include "neuesrennendialog.h"
#include "passwordchangedialog.h"
#include "neueruserdialog.h"
#include "hardwarekonfiguration.h"
#include "logfilelesendialog.h"
#include "rechteanpassen.h"
#include "RFID_Reader/rfidThread.h"
#include <QtSql>
#include <QtGui>
#include <QMessageBox>
#include <QSplashScreen>
#include <QToolBar>
#include <QHeaderView>
#include <QFileDialog>

struct TAG_SETTINGS tag_settings = {0,0,0,0};



/*!
 * \brief Konstruktor
 * \param splash Pointer auf den Splashscreen
 * \param a Pointer auf die Hauptapplikation
 * \param parent Pointer auf das aufrufende Element
 */
BEO_Timing::BEO_Timing(QSplashScreen *splash, QApplication *a, QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);
	this->a=a;
	// Statusleiste erstellen
	createStatusBar();
	// Menue und Toolbar erstellen
	createMenu();
	createToolbar();
	// Diese Initialisierungen müssen so früh stattfinden, damit die Aktionen
	// mit den jeweiligen Funktionen verbunden sind

	// Datenbank Thread erstellen
	pMySQL = new Database();
	// Datenbankverbindung prüfen und Programmstart abbrechen, falls nicht verbunden.
	if(!pMySQL->getDb()->isOpen()){
		// Popup-Meldung ausgeben und Programm schliessen
		QMessageBox::critical(0,"Keine Verbindung zur Datenbank","Es besteht keine Verbindung zur Datenbank"
				"Dies kann die folgenden Ursachen haben: <br><ol>"
				"<li>Es kann keine Verbindung zum Webserver hergestellt werden. --> überprüfen der "
				"Internetverbindung.</li>"
				"<li>Die Anwendung wird von einer Firewall blockiert. --> Firewalleinstellungen "
				"überprüfen und sicherstellen, dass der Port 3306 für die BEO-Timing Managementsoftware "
				"offen ist.</li>"
				"<li>Möglicherweise besteht ein Problem mit der Datenbank, was aber eher unwahrscheinlich ist. --> "
				"Kontaktaufnahme mit dem \"<a href=\"mailto:admin@beo-timing.ch\">Admin</a>\".</li>"
				"</ol>Ohne die Verbindung zur Datenbank ist das Programm nicht lauffähig und wird deshalb mit"
				"\"OK\" beendet.");
		// Applikation beenden
		QTimer::singleShot(500, this, SLOT(close()));
		QTimer::singleShot(1000, a, SLOT(quit()));
		return;
	}

	// Datenbank Thread erstellen
	pMySQL_thread = new DB_Thread();
	pMySQL_thread->start();

	// Versionscheck durchführen
    // TODO: Version Check wieder einführen
    newVersion();
    if(version){
        QMessageBox::critical(0,"Neue Softwareversion","Auf dem Server ist eine neue "
                "Softwareversion verfügbar. Die vorliegende Software kann aus Sicherheitsgründen nicht "
                "mehr verwendet werden. Klicken Sie auf \"<a href=\"http://www.rrc-thun.ch/time/beo-timing.msi\">download</a>\" "
                "um die neue Version herunterzuladen. Mit \"OK\" wird das Programm beendet.");
        // Applikation beenden
        QTimer::singleShot(500, this, SLOT(close()));
        QTimer::singleShot(1000, a, SLOT(quit()));
        return;
    }


	// Titel des Fensters setzen
	setWindowTitle("BEO-Timing - Managementsoftware");
	Qt::Alignment topRight = Qt::AlignRight | Qt:: AlignTop;
	splash->showMessage(QObject::tr("Login eines Benutzers..."),topRight, Qt::white);
	//Neuer User-Objekt erstellen und Einloggen
	user = new User();
	LogonDialog* logon = new LogonDialog(user,a,this);
	//logon->setWindowIcon(QPixmap(":/images/icon32_t.bmp"));
	logon->setWindowTitle(tr("Login ..."));
	logon->exec();
	// Applikation beenden, falls nicht eingeloggt wurde
	if(user->getLogonSuccess())
		this->show();
	else{
		QTimer::singleShot(500, this, SLOT(close()));
		QTimer::singleShot(1000, a, SLOT(quit()));
		return;
	}
	splash->showMessage(QObject::tr("Laden der Daten aus der Datenbank..."),topRight, Qt::white);
	// Benutzerrechte im Menu umsetzen
	setUserRights();
	// Tree initialisieren
	Tree_Settings();
	Tree_Build();
	// Aktiviert den RFID-Leser (Action löst ein Signal aus, welches mit der Funtkion
	// rfidConnection(...) verbunden ist aufruft
	// Thread zum Pollen des RFID-Lesers starten (Löst ein Signal aus)
	thread = new RFID_Thread(NULL);
	CR500_verbinden();
	((RFID_Thread*)thread)->start();
	// Verbinden des Signals mit dem Slot in dieser Klasse
	// (GUI muss im Hauptthread erstellt werden!!)
	connect((RFID_Thread*)thread,SIGNAL(checkRFID()),this,SLOT(checkRFID()));
	connect(pMySQL_thread,SIGNAL(checkDB()),this,SLOT(checkDB()));
}

/*!
 * \brief Destruktor
 */
BEO_Timing::~BEO_Timing()
{
	pMySQL_thread->stop();
	pMySQL_thread->terminate();
	pMySQL_thread->wait();
	delete pMySQL_thread;
	((RFID_Thread*)thread)->stop();
	((RFID_Thread*)thread)->terminate();
	((RFID_Thread*)thread)->wait();
	delete (RFID_Thread*)thread;
	delete (RFID_CR500*)pRfid;
}

/*!
 * \brief Verbindet die Aktionen mit dem Slots (Benutzermenue)
 */
void BEO_Timing::createMenu(){
    connect(ui.actionBeenden,SIGNAL(triggered()),a, SLOT(quit()));
    connect(ui.actionEintrag_Editieren,SIGNAL(triggered()),this, SLOT(Table_Edit()));
    connect(ui.actionNeues_Rennen_erfassen,SIGNAL(triggered()),this,SLOT(NeuesRennen()));
    connect(ui.actionExportieren_als_CSV,SIGNAL(triggered()),this,SLOT(exportToCsv()));
    connect(ui.actionPasswort_ndern,SIGNAL(triggered()),this,SLOT(changePwd()));
    connect(ui.actionNeuer_Benutzer_erstellen_3,SIGNAL(triggered()),this,SLOT(neuerUser()));
    connect(ui.actionKonfiguration_erstellen,SIGNAL(triggered()),this,SLOT(buildConfiguration()));
    connect(ui.actionLog_Datei_auslesen,SIGNAL(triggered()),this,SLOT(readLogFile()));
    connect(ui.actionBenutzerrechte_ndern,SIGNAL(triggered()),this,SLOT(rechteAnpassen()));
    connect(ui.actionAbout_Qt,SIGNAL(triggered()),qApp, SLOT(aboutQt()));
    connect(ui.actionAbout,SIGNAL(triggered()),this, SLOT(about()));
    connect(ui.actionRFID_Leser,SIGNAL(toggled(bool)),this, SLOT(rfidConnection(bool)));
    connect(ui.actionRFID_Leser_verbinden,SIGNAL(triggered()),this, SLOT(CR500_verbinden()));
    connect(ui.actionDatenbank,SIGNAL(toggled(bool)),this, SLOT(mysqlConnection(bool)));
    connect(ui.actionAktualisieren,SIGNAL(triggered()),this,SLOT(Tree_Build()));
    connect(ui.actionVerwaiste_Eintr_ge_entfernen,SIGNAL(triggered()),this,SLOT(purge()));
    connect(ui.actionDatenbank_optimieren,SIGNAL(triggered()),this,SLOT(optimieren()));
    connect(ui.actionKarten_zur_cksetzen_unpers_nlich,SIGNAL(toggled(bool)),this,SLOT(tag_clear_unpers(bool)));
    connect(ui.actionKarten_zur_cksetzen_pers_nlich,SIGNAL(toggled(bool)),this,SLOT(tag_clear_pers(bool)));
    connect(ui.actionDatenbank_optimieren,SIGNAL(triggered()),this,SLOT(optimieren()));
    connect(ui.actionNeue_Karten_initialisieren_unpers_nlich,SIGNAL(toggled(bool)),this,SLOT(tag_initialisieren_unpers(bool)));
    connect(ui.actionNeue_Karten_initialisieren_pers_nlich,SIGNAL(toggled(bool)),this,SLOT(tag_initialisieren_pers(bool)));
	connect(ui.actionEintragen_der_Karte_in_die_Datenbank, SIGNAL(toggled(bool)), this, SLOT(tag_into_database(bool)));
    connect(ui.actionLog, SIGNAL(triggered()), this, SLOT(showLogDock()));
    connect(ui.actionRennen, SIGNAL(triggered()), this, SLOT(showTreeDock()));
	connect(ui.actionKarte_registrieren, SIGNAL(toggled(bool)), this, SLOT(tag_user_reg(bool)));


}

/*!
 * \brief Setzt die Benutzerrechte für die verschiedenen Aktionen
 */
void BEO_Timing::setUserRights(){
	// Benutzerrechte für Actions einstellen

	if(user->getUsertype()==user->superadministrator){
		// keine Einschränkungen

		// Zusätzliche Rechte
		ui.actionDatenbank->setEnabled(true);
	}
	if(user->getUsertype()==user->administrator){
		// keine Einschränkungen
	}
	if(user->getUsertype()==user->manager || user->getUsertype()==user->user){
		ui.actionKonfiguration_erstellen->setDisabled(true);
		ui.actionNeues_Rennen_erfassen->setDisabled(true);
		ui.actionBenutzerrechte_ndern->setDisabled(true);
	}
	if(user->getUsertype()==user->user){
		// User --> keine Möglichkeiten zur Veränderung der Datenbank nur schauen!
		ui.actionNeuer_Benutzer_erstellen_3->setDisabled(true);
		ui.actionDatenbank_optimieren->setDisabled(true);
		ui.actionEintrag_Editieren->setDisabled(true);
		ui.actionLog_Datei_auslesen->setDisabled(true);
		ui.actionVerwaiste_Eintr_ge_entfernen->setDisabled(true);
		ui.actionRFID_Leser->setDisabled(true);
		ui.actionRFID_Leser_verbinden->setDisabled(true);
		ui.actionKarten_zur_cksetzen_unpers_nlich->setDisabled(true);
		ui.actionKarten_zur_cksetzen_pers_nlich->setDisabled(true);
		ui.actionNeue_Karten_initialisieren_unpers_nlich->setDisabled(true);
		ui.actionNeue_Karten_initialisieren_pers_nlich->setDisabled(true);
	}
}

/*!
 * \brief Erstellt die Symbolliste mit den ausgewählten Aktionen
 */
void BEO_Timing::createToolbar(){
	toolbar = addToolBar(tr("&Symbolliste"));
	toolbar->addAction(ui.actionNeues_Rennen_erfassen);
	toolbar->addAction(ui.actionAktualisieren);
	toolbar->addAction(ui.actionExportieren_als_CSV);
	toolbar->addAction(ui.actionEintrag_Editieren);
	toolbar->addAction(ui.actionNeuer_Benutzer_erstellen_3);
	toolbar->addAction(ui.actionRFID_Leser);
	toolbar->addAction(ui.actionBeenden);
}

/*!
 * \brief Bereitet die Baumansicht zur Darstellung vor.
 */
void BEO_Timing::Tree_Settings(){
	raceTree = ui.RennenTreeWidget;
	// 4 Spalten
	raceTree->setColumnCount(4);
	// Namen der Spalten definieren
	raceTree->setHeaderLabels(QStringList() << tr("Rennen") << tr("Startdatum")
			<< tr("Enddatum") << tr("Streckennummer"));
	// Spaltenbreite auf automatisch stellen
    raceTree->header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    raceTree->header()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    raceTree->header()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    raceTree->header()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
	// Signal "Auswahländerung" mit Slot "Baum geändedert" verbinden
	connect(raceTree,SIGNAL(itemSelectionChanged()),this,SLOT(Tree_Changed()));
}

/*!
 * \brief Füllt die Baumansicht mit Ihalt, entsprechend der Benutzerrechte
 */
void BEO_Timing::Tree_Build(){
	raceTree = ui.RennenTreeWidget;
	// Baum leeren
	raceTree->clear();
	// Erstes Jahr mit einem Rennen finden.
	QString sql = "SELECT min(Jahr) FROM strecken";
	QSqlQuery query(sql);
	query.exec();
	query.next();
	int min_jahr = query.value(0).toInt();
	// Letztes Jahr mit einem Rennen finden
	sql = "SELECT max(Jahr) FROM strecken";
	query.prepare(sql);
	query.exec();
	query.next();
	int max_jahr = query.value(0).toInt();
	// Informationen aus dem gewählten Bereich abfragen und eintragen
	for(int jahr=min_jahr; jahr<=max_jahr; ++jahr){
		// Daten für 1 Jahr lesen (anzahl)
		query.exec("SELECT count(StreckenKey) FROM strecken WHERE Jahr='" + QString::number(jahr) + "'");
		query.next();
		// nächtes Jahr, falls keine Einträge
		if(query.value(0).toBool()){
			QTreeWidgetItem *root;
			root= new QTreeWidgetItem(raceTree->invisibleRootItem());
			root->setText(0, QString::number(jahr));
			QTreeWidgetItem *item;
			// Informationen für ein ganzes Jahr abrufen
			sql = "SELECT StreckenKey, Streckenname, Startdatum, Enddatum, Jahr, StreckentypKey "
					"FROM strecken "
					"WHERE Jahr='" + QString::number(jahr) + "'";
			qDebug() << sql;
			query.prepare(sql);
			query.exec();
			if(query.isActive()){
				int count = 0;
				while(query.next() && user->getRaceAuthority(query.value(0).toInt())){
					item = new QTreeWidgetItem(root);
					item->setText(0,query.value(1).toString() + " (" + getTimeCount(query.value(0).toInt()) + ")");
					item->setText(1,query.value(2).toDate().toString("dd.MM.yyyy"));
					item->setText(2,query.value(3).toDate().toString("dd.MM.yyyy"));
					item->setText(3,QString::number(query.value(0).toInt()));
					// Richtiges Symbol wählen
					QIcon icon;
					switch(query.value(5).toInt()){
						case Rennvelo: icon.addFile(":/images/rennrad.png"); break;
						case Mountainbike: icon.addFile(":/images/bike.png"); break;
						case Laufen: icon.addFile(":/images/plauf.png"); break;
						case Walking: icon.addFile(":/images/walking.png"); break;
						case Langlauf: icon.addFile(":/images/langlauf.png"); break;
						case Inline: icon.addFile(":/images/inline.png"); break;
						default: icon.addFile(":/images/unbekannt.png"); break;
					}
					item->setIcon(0,icon);
					raceTree->setCurrentItem(item);
					count ++;
				}
				if(count == 0)
					root->setHidden(true);
			}
		}
	}
	// Alles Expandieren
	raceTree->expandAll();
}

/*!
 * \brief Reagiert auf eine Änderung der Auswahl im Baum
 */
void BEO_Timing::Tree_Changed(){
	// Bestimmt die neue Position im Baum und ruft die Funktion Read_Race,
	// um die Rangliste zu erstellen.
	Read_Race(raceTree->currentItem()->text(3).toInt());
	qDebug() << raceTree->currentItem()->text(3);
}

/*!
 * \brief Bestimmt die Anzahl Fahrzeiten für eine Strecke
 * \param StreckenKey Streckennummer
 */
QString BEO_Timing::getTimeCount(int StreckenKey){
	QSqlQuery query("SELECT count(TimeKey) FROM zeiten WHERE StreckenKey='"
			+ QString::number(StreckenKey) + "'");
	query.exec();
	query.next();
	return (query.value(0).toString());
}

/*!
 * \brief Stellt die Rangliste dar
 * \param StreckenNummer Strecke, welche dargestellt werden soll.
 */
void BEO_Timing::Read_Race(int StreckenNummer){
	view = ui.RanglistenTableView;
	// Falls keine StreckenNummer definiert wurde, wird die aktuell gewählte dargestellt
	if(StreckenNummer == 0){
		StreckenNummer=ui.RennenTreeWidget->currentItem()->data(3,Qt::DisplayRole).toInt();
	}
	// Modell für die Daten bezogen auf die Tabelle
	QStandardItemModel* model = new QStandardItemModel(view);
	// 20 Spalten mit Namen versehen
	model->insertColumns(0,20);
	model->setHeaderData(Name, Qt::Horizontal, tr("Name"));
	model->setHeaderData(Vorname, Qt::Horizontal, tr("Vorname"));
	model->setHeaderData(Adresse, Qt::Horizontal, tr("Adresse"));
	model->setHeaderData(PLZ, Qt::Horizontal, tr("PLZ"));
	model->setHeaderData(Ort, Qt::Horizontal, tr("Ort"));
	model->setHeaderData(Nationalitaet, Qt::Horizontal, tr("Nationalität"));
	model->setHeaderData(Jahrgang, Qt::Horizontal, tr("Jahrgang"));
	model->setHeaderData(Geschlecht, Qt::Horizontal, tr("Geschlecht"));
	model->setHeaderData(Email, Qt::Horizontal, tr("Email"));
	model->setHeaderData(Telefon, Qt::Horizontal, tr("Telefon"));
	model->setHeaderData(Mobile, Qt::Horizontal, tr("Mobile"));
	model->setHeaderData(Team_Club, Qt::Horizontal, tr("Team / Club"));
	model->setHeaderData(Kategorie, Qt::Horizontal, tr("Kategorie"));
	model->setHeaderData(Fahrzeit, Qt::Horizontal, tr("Fahrzeit"));
	model->setHeaderData(Rueckstand, Qt::Horizontal, tr("Rückstand"));
	model->setHeaderData(RFID_SNR, Qt::Horizontal, tr("RFID-Snr"));
	model->setHeaderData(StreckenKey, Qt::Horizontal, tr("Strecken-Nr"));
	model->setHeaderData(TimeID, Qt::Horizontal, tr("TimeID"));
	model->setHeaderData(TimeKey, Qt::Horizontal, tr("TimeKey"));
	model->setHeaderData(TeilnehmerKey, Qt::Horizontal, tr("TeilnehmerKey"));
	// Model mit der Tabelle verbinden
	view->setModel(model); // Modell der Tabelle zuweisen
	// Auswahlmöglichkeiten einschränken
	view->setSelectionMode(QAbstractItemView::SingleSelection);
	view->setSelectionBehavior(QAbstractItemView::SelectRows);
	// Spaltenbreite auf automatisch
	view->resizeColumnsToContents();
	// Editiermöglichkeiten einschränken (keine)
	view->setEditTriggers(QAbstractItemView::NoEditTriggers);
	QHeaderView * header = view->horizontalHeader();
	header->setStretchLastSection(true);
	// SQL-Statement für die Rangliste
	QString sql = "SELECT teilnehmer.name, teilnehmer.vorname, teilnehmer.adresse, "
			"teilnehmer.PLZ, teilnehmer.ort, teilnehmer.nationalitaet, "
			"teilnehmer.jahrgang, teilnehmer.geschlecht, teilnehmer.email, teilnehmer.telefon, "
			"teilnehmer.mobile, teilnehmer.club, zeiten.kategorie, min(zeiten.fahrzeit) AS fahrzeit, "
			"TIMEDIFF(min(zeiten.fahrzeit),(SELECT min(zeiten.fahrzeit) FROM zeiten WHERE Streckenkey = "
			+ QString::number(StreckenNummer) + ")) AS rueckstand, "
			"teilnehmer.SNR_RFID, zeiten.StreckenKey, zeiten.TimeID, zeiten.TimeKey, zeiten.TeilnehmerKey "
			"FROM strecken, zeiten , teilnehmer "
			"WHERE zeiten.StreckenKey = strecken.StreckenKey "
			"AND zeiten.TeilnehmerKey = teilnehmer.TeilnehmerKey "
			"AND strecken.StreckenKey = " + QString::number(StreckenNummer) + " "
			"GROUP BY teilnehmer.TeilnehmerKey "
			"ORDER BY min(zeiten.fahrzeit)";
	qDebug() << sql;
	QSqlQuery query(sql);
	if(query.isActive()){
		query.exec();
		qDebug() << model->insertRows(0,query.numRowsAffected());
		qDebug() << "Rec.count(): " << query.numRowsAffected() << " -> " << model->rowCount();
		// Einfügen der gelesenen Daten in das Modell
		for(int j=0; j< query.numRowsAffected(); ++j){
			query.next();
			for(int i=0;i<20;++i){
			   model->setData(model->index(j,i),query.value(i));
			   qDebug() << query.value(i).toString();
			}
		}
	}
	qDebug() << query.lastError();
	view->resizeColumnsToContents();
	//connect(view,SIGNAL(doubleClicked()),this,SLOT(Table_Edit()));

}

// Extra instanzierung der statischen Variabeln
QLabel* BEO_Timing::connectionLabel;
QLabel* BEO_Timing::userLabel;
QLabel* BEO_Timing::messageLabel;

/*!
 * \brief Erstellt die Statusbar mit den drei Labeln.
 *
 */
void BEO_Timing::createStatusBar(){
	// Label für den Benutzernamen
	userLabel = new QLabel("Benutzer:      ");
	userLabel->setAlignment(Qt::AlignHCenter);
	userLabel->setMinimumSize(userLabel->sizeHint());
	// Label für die Verbindungsanzeigen
	connectionLabel = new QLabel("RFID-Leser:      ");
	connectionLabel->setAlignment(Qt::AlignLeft);
	connectionLabel->setMinimumSize(connectionLabel->sizeHint());
	// Label für diverse Informationen
	messageLabel = new QLabel("Letzte Meldung:                  ");
	messageLabel->setIndent(3);
	// Labels mit der Statusliste verbinden
	statusBar()->addWidget(userLabel);
	statusBar()->addWidget(connectionLabel,1);
	statusBar()->addWidget(messageLabel);
}

/*!
 * \brief Aufrufen des TableEdit-Dialogs mit den richtigen Parametern
 *
 */
void BEO_Timing::Table_Edit(){
	int selected = 0;
	QItemSelectionModel* model = view->selectionModel();
	// Falls eine Zeile ausgewählt ist, wird der Dialog gestartet.
	if(model->hasSelection()){
		selected=view->selectionModel()->selection().indexes().at(0).row();
		// Aufrufen des Konstruktors des Dialogs und übergabe der Parameter
		TableEditDialog* tableEdit = new TableEditDialog(
				view->model()->data(view->model()->index(selected,TeilnehmerKey)).toInt(),
				user,this);
		qDebug() << view->model()->data(view->model()->index(selected,TeilnehmerKey)).toString();
		// Symbol setzen
		tableEdit->setWindowIcon(QPixmap(":/images/icon32_t.bmp"));
		// Titel definieren
		tableEdit->setWindowTitle(tr("Editieren der Daten"));
		// Dialog modal ausführen
		tableEdit->exec();
		// Dialog löschen, speicher freigeben
		delete tableEdit;
	}
}

/*!
 * \brief Aufrufen des NeuesRennen-Dialogs
 *
 */
void BEO_Timing::NeuesRennen(){
	// Dialog erstellen
    qDebug() << "Neues Rennen erfassen dialog starten";
	neu = new NeuesRennenDialog(this);
	// Singal aus den Dialog mit dem Baum-Update verbinden
	connect(neu,SIGNAL(tree_update()),this,SLOT(Tree_Build()));
//	neu->setWindowIcon(QPixmap(":/images/icon32_t.bmp"));
	neu->setWindowTitle(tr("Neues Rennen erfassen"));
	// Dialog modal ausführen
	neu->exec();
	// Die Verbindung zum Signal aufheben
	disconnect(neu,SIGNAL(tree_update()),this,SLOT(Tree_Build()));
	// Dialog löschen
	delete neu;
}

/*!
 * \brief Prüfen ob eine RFID-Karte im Feld ist.
 *
 */
void BEO_Timing::checkRFID(){
	qDebug() << "Signal ausgelöst";
	// Variable zum Blockieren der RFID-Thread aktivitäten, während der Dialog aktiv ist.
	static bool active = false;
	// Verbindung prüfen
	// Falls OK, Karte suchen
	// Falls OK, Karte lesen
	// Falls OK, Dialog erstellen
	if(!active && ((RFID_CR500*)pRfid)->isConnected() && ((RFID_CR500*)pRfid)->findCard() && ((RFID_CR500*)pRfid)->readData()){
		active = true;
		// Dialog erstellen
		RFIDInputDialog* rfidDialog = new RFIDInputDialog((RFID_CR500*)pRfid);
		// Symbol setzen
		rfidDialog->setWindowIcon(QPixmap(":/images/icon32_t.bmp"));
		// Titel definieren
		rfidDialog->setWindowTitle("RFID-Karte auswerten");
		// Dialog modal öffnen
		rfidDialog->exec();
		// Dialog löschen
		delete rfidDialog;
		// Funktion freigeben für RFID-Thread
		active = false;
	}
}

/*!
 * \brief Datenbankverbindung ueberpruefen
 *
 */
void BEO_Timing::checkDB(){
	static bool active = false;
	if(!active){
		active = true;
		switch(pMySQL_thread->getState()){
		case DB_Thread::running:
			static bool active = false;
			if(!active && !pMySQL->getDb()->isOpen()){
				// Datenbankverbindung abgerissen
				active=true;
				// Versuchen die Verbindung aufzubauen
				if(pMySQL->getDb()->open())
					QMessageBox::critical(0, QObject::tr("Database Error"),
								"Die Verbindung zur Datenbank ist abgebrochen. Bitte überprüfen Sie Ihre Internetverbindung "
								"und bestätigen Sie mit Ok.\n\n" + pMySQL->getDb()->lastError().text());
				active=false;
			}
			break;
		case DB_Thread::stopp:
			pMySQL->getDb()->close();
			break;
		case DB_Thread::restart:
			pMySQL->getDb()->open();
			break;
		}
		active=false;	} // end if(!active)
}

/*!
 * \brief Exportieren der Rangliste im CSV-Format
 *
 */
void BEO_Timing::exportToCsv(){
	QAbstractItemModel* model = view->model();
	// Headerdaten schreiben
	QString csv = "Name;Vorname;Adresse;PLZ;Wohnort;Nationalität;"
		          "Jahrgang;Geschlecht;Email;Telefon;Mobile;Club-Team;"
		          "Kategorie;Fahrzeit;Rückstand;RFID_SNR;\n";
	// Tabelle auslesen: Spaltentrennung mit ';' und Zeilen mit '\n'
	for (int row = 0; row < model->rowCount(); ++row) {
	 for (int field = 0; field < model->columnCount(); ++field) {
	   csv += model->data(model->index(row,field)).toString() + ";";
	 }
	 csv += "\n";
	}
	qDebug() << csv;
	// Speichern unter - Dialog öffnen
	QString fileName = QFileDialog::getSaveFileName(this,
							tr("Speichere Rangliste"), ".",
							tr("Comma separated value Datei (*.csv)"));
	if(!fileName.isEmpty()){
		QFile file(fileName);
		if(!file.open(QIODevice::WriteOnly)){
			QMessageBox::warning(this, tr("Exportieren nach CSV"),
									tr("Kann die Datei %1 nicht schreiben;\n%2")
									.arg(file.fileName()).arg(file.errorString()));
			return;
		}
		// Stream für ASCII-File öffnen
		QTextStream out(&file);
		// Daten schreiben
		out << csv;
		file.flush();
		file.close();
	}
}

/*!
 * \brief Passwort ändern Dialog öffnen
 *
 */
void BEO_Timing::changePwd(){
	// Dialog erstellen mit dem Parameter user
	pwd = new PasswordChangeDialog(user, this);
//	pwd->setWindowIcon(QPixmap(":/images/icon32_t.bmp"));
	pwd->setWindowTitle(tr("Password ändern"));
	// Dialog modal starten
	pwd->exec();
	// Dialog löschen
	delete pwd;
}

/*!
 * \brief Neuer Benutzer - Dialog öffnen
 *
 */
void BEO_Timing::neuerUser(){
	// Dialog erstellen, mit dem Paramter user
	newUser = new NeuerUserDialog(user, this);
//	newUser->setWindowIcon(QPixmap(":/images/icon32_t.bmp"));
	newUser->setWindowTitle(tr("Neuer Benutzer erstellen"));
	// Dialog modal starten
	newUser->exec();
	delete newUser;
}

/*!
 * \brief Konfiguration erstellen - Dialog öffnen
 *
 */
void BEO_Timing::buildConfiguration(){
	// Dialog erstellen
	config = new HardwareKonfiguration(user, this);
	config->setWindowIcon(QPixmap(":/images/icon32_t.bmp"));
	config->setWindowTitle(tr("Neue Konfiguration für eine Station erstellen"));
	// Dialog modal öffnen
	config->exec();
	// Dialog löschen
	delete config;
}

/*!
 * \brief Log-Datei Lesen - Dialog öffnen
 *
 */
void BEO_Timing::readLogFile(){
	logfile = new LogfileLesenDialog(this);
	logfile->setWindowIcon(QPixmap(":/images/icon32_t.bmp"));
	logfile->setWindowTitle(tr("Zeiten aus der Log-Datei interpretieren"));
	// Dialog modal starten
	logfile->exec();
	// Dialog löschen
	delete logfile;
}

/*!
 * \brief Benutzerreche anpassen - Dialog öffnen
 *
 */
void BEO_Timing::rechteAnpassen(){
	rechte = new RechteAnpassen(user, this);
//	rechte->setWindowIcon(QPixmap(":/images/icon32_t.bmp"));
	rechte->setWindowTitle(tr("Rechte eines Benutzer anpassen"));
	// Dialog modal starten
	rechte->exec();
	// Dialog löschen
	delete rechte;
}

/*!
 * \brief About - Dialog der Managementsoftware anzeigen
 *
 */
void BEO_Timing::about(){
	QMessageBox::about(this, tr("BEO-Timing Management-Software"),
                            tr("<h2>BEO-Timing Management-Software 1.2 </h2>"
							   "<p>Copyright &copy; 2008 <a href=\"http://www.rrc-thun.ch/\">RRC-Thun</a> "
							   "und <a href=\"http://www.rc-steffisburg.ch/\">RC-Steffisburg</a> "
							   "<p>Diese Software bietet die Möglichkeiten zur Auswertung von RFID-Karten, "
							   "der Konfiguration der Stationen, Wartung und Administration der Datenbank und stellt "
							   "eine Benutzerverwaltung zur Verfügung."
							   "<p>Diese Software wurde im Rahmen der Bachelor-Thesis von Rico Zoss und "
							   "Moritz Leiser an der Berner Fachhochschule Technik und Informatik im Fachbereich "
							   "Elektrotechnik erstellt."));
}

/*!
 * \brief Verbindung zum RFID-Leser herstellen bzw. trennen
 *
 */
void BEO_Timing::rfidConnection(bool checked){
	if(checked){
		pRfid = new RFID_CR500(&tag_settings);
		((RFID_Thread*)thread)->setRFID((RFID_CR500*)pRfid);
		((RFID_Thread*)thread)->setState(RFID_Thread::restart);
	}else{
		((RFID_Thread*)thread)->setState(RFID_Thread::stopp);
		delete (RFID_CR500*)pRfid;
	}
}

/*!
 * \brief Verbindung zur Datenbank herstellen bzw. trennen (experimentell, nur Superadmin)
 *
 */
void BEO_Timing::mysqlConnection(bool checked){
	if(checked){
		pMySQL_thread->setState(DB_Thread::restart);
	}else{
		pMySQL_thread->setState(DB_Thread::stopp);
	}
}

/*!
 * \brief Versionscheck
 *
 */
void BEO_Timing::newVersion(){
	// Aktuelle Softwareversion aus der Datenbank lesen
	QSqlQuery query;
	query.exec("SELECT nummer FROM version");
	query.next();
	// und mit der Definition im Sourcecode vergleichen
	version = (query.value(0).toString().compare(VERSION)!=0);
}

/*!
 * \brief Datenbank bereinigen. Alle "(Noch nicht ausgewertet)"-Einträge entfernen.
 *
 */
void BEO_Timing::purge(){
	QSqlQuery query;
	// Alle Einträge, die älter sind als Heute um Mitternacht, darstellen.
	query.exec("SELECT zeiten.TeilnehmerKey FROM zeiten, teilnehmer WHERE "
			   "Eintrag < '" + QDate::currentDate().toString("yyyy-MM-dd") + " 00:00:00' "
			   "AND zeiten.TeilnehmerKey=teilnehmer.TeilnehmerKey AND name='(noch'");
	// Liste mit dem TeilnehmerKeys erstellen
	QStringList keylist;
	for(int i=0; i<query.numRowsAffected();++i){
		query.next();
		keylist.append(query.value(0).toString());
	}
	qDebug() << keylist;
	// Warnung ausgeben und den Vorgang bestätigen lassen
	QMessageBox msgBox;
	QPushButton *loeschenButton = msgBox.addButton(tr("Löschen"), QMessageBox::ActionRole);
	QPushButton *canButton = msgBox.addButton(tr("Abbrechen"), QMessageBox::ActionRole);
	msgBox.setDefaultButton(canButton);
	msgBox.setEscapeButton(canButton);
	msgBox.setText(tr("Alle unzugeordneten Einträge, welche vor dem heutigen Datum gemacht wurden, "
					  "werden gelöscht. Diese Aktion sollte nur ausgeführt werden, wenn alle Karten "
					  "bis zum heutigen Tag ausgewertet sind.\n\n Diese Aktion kann nicht Rückgängig gemacht werden!"));
	msgBox.setWindowTitle(tr("Bestätigen des Löschvorgangs"));
	msgBox.setIcon(QMessageBox::Warning);
	msgBox.exec();
	// Löschen der Einträge, falls bestätigt
	if(msgBox.clickedButton() == loeschenButton){
		for(int i=0;i<keylist.count();++i)
			query.exec("DELETE FROM zeiten WHERE TeilnehmerKey=" + keylist.at(i));
		for(int i=0;i<keylist.count();++i)
			query.exec("DELETE FROM teilnehmer WHERE TeilnehmerKey=" + keylist.at(i));
	}
}

/*!
 * \brief Optimieren der Tabellen in der Datenbank
 *
 */
void BEO_Timing::optimieren(){
	QSqlQuery query;
	// SQL-Statement für die Optimierung
	query.exec("OPTIMIZE TABLE kategorien, nationalitaeten, sommerzeit, stationen, "
			   "strecken, streckentyp, teilnehmer, user, usertype, version, zeiten");
	QString feedback;
	for(int i=0; i< query.numRowsAffected();++i){
		query.next();
		feedback += "- " + query.value(0).toString() + ": " + query.value(3).toString() + "\n";
	}
	// Ausgabe der Resultate
	QMessageBox::information(0, QObject::tr("Optimieren der Datenbank"),
				"Die Datenbank wurde Optimiert:\n\n" + feedback);
}

/*!
 * \brief Verbinden des RFID-Lesers
 *
 */
void BEO_Timing::CR500_verbinden(){
	pRfid = new RFID_CR500(&tag_settings);
	((RFID_Thread*)thread)->setRFID((RFID_CR500*)pRfid);
	if(((RFID_CR500*)pRfid)->isConnected()){
		ui.actionRFID_Leser->setEnabled(true);
		ui.actionRFID_Leser_verbinden->setDisabled(true);
		((RFID_Thread*)thread)->setState(RFID_Thread::running);
	}else{
		((RFID_Thread*)thread)->setState(RFID_Thread::pause);
		ui.actionRFID_Leser->setDisabled(true);
		ui.actionRFID_Leser_verbinden->setEnabled(true);
		delete (RFID_CR500*)pRfid;
	}
}

void BEO_Timing::tag_initialisieren_pers(bool checked){
	if(checked){
		ui.actionNeue_Karten_initialisieren_unpers_nlich->setChecked(false);
		ui.actionKarten_zur_cksetzen_pers_nlich->setChecked(false);
		ui.actionKarten_zur_cksetzen_unpers_nlich->setChecked(false);
		tag_settings.tag_init=Neu_persoenlich;
		tag_settings.tag_reset=Nichts;
	}else{
		tag_settings.tag_reset=Nichts;
		tag_settings.tag_init=Nichts;
	}
}

void BEO_Timing::tag_clear_pers(bool checked){
	if(checked){
	ui.actionNeue_Karten_initialisieren_pers_nlich->setChecked(false);
	ui.actionNeue_Karten_initialisieren_unpers_nlich->setChecked(false);
	ui.actionKarten_zur_cksetzen_pers_nlich->setChecked(true);
	ui.actionKarten_zur_cksetzen_unpers_nlich->setChecked(false);
	tag_settings.tag_init=Nichts;
	tag_settings.tag_reset=Res_persoenlich;
	}else{
			tag_settings.tag_reset=Nichts;
			tag_settings.tag_init=Nichts;
		}
}

void BEO_Timing::tag_initialisieren_unpers(bool checked){
	if(checked){
		ui.actionNeue_Karten_initialisieren_pers_nlich->setChecked(false);
		ui.actionKarten_zur_cksetzen_pers_nlich->setChecked(false);
		ui.actionKarten_zur_cksetzen_unpers_nlich->setChecked(false);
		tag_settings.tag_init=Neu_unpersoenlich;
		tag_settings.tag_reset=Nichts;
	}else{
		tag_settings.tag_reset=Nichts;
		tag_settings.tag_init=Nichts;
	}
}

void BEO_Timing::tag_clear_unpers(bool checked){
	if(checked){
		ui.actionNeue_Karten_initialisieren_pers_nlich->setChecked(false);
		ui.actionNeue_Karten_initialisieren_unpers_nlich->setChecked(false);
		ui.actionKarten_zur_cksetzen_pers_nlich->setChecked(false);
		tag_settings.tag_init=Nichts;
		tag_settings.tag_reset=Res_unpersoenlich;
	}else{
		tag_settings.tag_reset=Nichts;
		tag_settings.tag_init=Nichts;
	}
	qDebug() << "tag_init: " << tag_settings.tag_reset;
}

void BEO_Timing::tag_into_database(bool checked) {
	if (checked) {
		tag_settings.tag_enterDB = true;
	} else {
		tag_settings.tag_enterDB = false;
	}
	qDebug() << "tag_enterDB: " << tag_settings.tag_enterDB;
}

void BEO_Timing::tag_user_reg(bool checked) {
	checked ? tag_settings.register_in_DB = true : tag_settings.register_in_DB
			= false;
}

