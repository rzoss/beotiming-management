/**
 *******************************************************************************
 * \file    rfidinputdialog.cpp
 ********************************************************************************
 * \brief    Stellt die Eingabemaske, sowie die benötigten Funktionen zum auswerten von
 * 			 RFID-Tags eines beliebigen Lesers zur Verfügung.
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

#include "rfidinputdialog.h"
#include "RFID_CR500.h"
#include <QtSql>
#include <QtGui>
#include <QMessageBox>
/*!
 * \brief Konstruktor
 * \param pRfid Pointer zur RFID-Leser Klasse
 * \param parent Pointer auf das aufrufende Objekt
 */
RFIDInputDialog::RFIDInputDialog(RFID_CR500* pRfid, QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	this->pRfid=pRfid;
	// ComboBox für Nationaliten aus der Datenbank heraus erstellen
	QStringList list;
	QSqlQuery query("SELECT name FROM nationalitaeten ORDER BY name ASC");
	query.exec();
	for(int i=0;i<query.numRowsAffected();++i){
		query.next();
		list.append(query.value(0).toString());
	}
	ui.nationalitaetComboBox->addItems(list);
	ui.nationalitaetComboBox->setCurrentIndex(ui.nationalitaetComboBox->findText("Schweiz"));
	list.clear();
	query.clear();
	// ComboBox mit den Kategorien aus der Datenbank auffüllen
	query.exec("SELECT name FROM kategorien");
	qDebug() << query.lastError();
	for(int i=0;i<query.numRowsAffected();++i){
		query.next();
		list.append(query.value(0).toString());
	}
	ui.KategoriecomboBox->addItems(list);
	// Verschiedene Labels mit den Informationen versorgen
	// Die Informationen der RFID-Karte stehen nach dem Lesen
	// in verschiedenen Attributen der Klasse des Lesers zur Verfügung.
	ui.StarttimeLabel->setText(toDateString(&pRfid->startdate));
	ui.EndtimeLabel->setText(toDateString(&pRfid->enddate));
	ui.FahrzeitLabel->setText(toDateString(&pRfid->racetime));
	ui.rfidsnrLabel->setText(pRfid->serial);
	// Informationen zur Strecke aus der Datenbank abrufen
	QStringList temp = getStreckenNameTyp(pRfid->strecke);
	ui.StreckennameLabel->setText(temp.at(0));
	ui.StreckenTypLabel->setText(temp.at(1));
	connect(ui.maenlichRadioButton,SIGNAL(pressed()),this,SLOT(checkSingularity()));
	connect(ui.weiblichRadioButton,SIGNAL(pressed()),this,SLOT(checkSingularity()));

	// Validators
	// Nur Buchstaben und Leerschläge
	QRegExp charExp ("[\\-\\w\\s]+");
	// Nur Zahlen
	QRegExp numbExp ("[\\d]+");
	// Nur Zahlen
	QRegExp telExp ("\\+[\\d]+");
	// Nur Buchstaben, Zahlen und Leerschläge
	QRegExp bothExp ("[\\w\\s]+");
	// E-mail address is validated according to RFC2821, RFC2822,
	// see http://en.wikipedia.org/wiki/E-mail_address.
	// http://www.virtualbox.org/changeset/7487?format=diff&new=7487
	QRegExp emailExp ("(([a-zA-Z0-9_\\-\\.!#$%\\*/?|^{}`~&'\\+=]*"
		                    "[a-zA-Z0-9_\\-!#$%\\*/?|^{}`~&'\\+=])|"
		                  "(\"([\\x0001-\\x0008,\\x000B,\\x000C,\\x000E-\\x0019,\\x007F,"
		                       "\\x0021,\\x0023-\\x005B,\\x005D-\\x007E,"
		                       "\\x0009,\\x0020]|"
		                     "(\\\\[\\x0001-\\x0009,\\x000B,\\x000C,"
		                            "\\x000E-\\x007F]))*\"))"
		                    "@"
		                    "[a-zA-Z0-9\\-]+(\\.[a-zA-Z0-9\\-]+)*");

	ui.nameLineEdit->setValidator (new QRegExpValidator (charExp, this));
	ui.nameLineEdit->setMaxLength (50);
	ui.vornameLineEdit->setValidator (new QRegExpValidator (charExp, this));
	ui.vornameLineEdit->setMaxLength (50);
	ui.adresseLineEdit->setValidator (new QRegExpValidator (bothExp, this));
	ui.adresseLineEdit->setMaxLength (50);
	ui.plzLineEdit->setValidator (new QRegExpValidator (numbExp, this));
	ui.plzLineEdit->setMaxLength (4);
	ui.ortLineEdit->setValidator (new QRegExpValidator (charExp, this));
	ui.ortLineEdit->setMaxLength (50);
	ui.clubLineEdit->setValidator (new QRegExpValidator (bothExp, this));
	ui.clubLineEdit->setMaxLength (50);
	ui.emailLineEdit->setValidator (new QRegExpValidator (emailExp, this));
	ui.emailLineEdit->setMaxLength (50);
	ui.telephonLineEdit->setValidator (new QRegExpValidator (telExp, this));
	ui.telephonLineEdit->setMaxLength (12);
	ui.mobileLineEdit->setValidator (new QRegExpValidator (telExp, this));
	ui.mobileLineEdit->setMaxLength (12);
	// Anpassen der Kategorie an den Default-Jahrgang
	ui.KategoriecomboBox->setCurrentIndex(
			ui.KategoriecomboBox->findText(
					calculateKategorie(ui.jahrgangSpinBox->value())
			)
	);
	// automatisches Vervollständigen einschalten
	autoInsert = true;
	TeilnehmerKeyInt=0;
}
/*!
 * \brief Destruktor
 */
RFIDInputDialog::~RFIDInputDialog()
{

}
/*!
 * \brief Zeiten aus der Struktur zur anzeige vorbereiten
 */
QString RFIDInputDialog::toDateString(struct MYTIME* time, QString format){
	QTime* temp = new QTime();
	temp->setHMS(time->hour,time->minute,time->second,0);

	qDebug() << temp->toString(format);
	return temp->toString(format);
}
/*!
 * \brief Zeiten aus der Struktur zur anzeige vorbereiten
 */
QString RFIDInputDialog::toDateString(struct MYDATE *date, QString format){
	QTime* time = new QTime();
	time->setHMS(date->hour,date->minute,date->second,0);
	QDate* tempdate = new QDate();
	tempdate->setDate(date->year,date->month,date->day);
	QDateTime* temp = new QDateTime();
	temp->setDate(*tempdate);
	temp->setTime(*time);
	return temp->toString(format);
}
/*!
 * \brief Informationen zum Streckentyp aus der Datenbank abrufen
 * \param StreckenKey Nummer der Strecke
 * \return Liste mit den Informationen
 */
QStringList RFIDInputDialog::getStreckenNameTyp(int StreckenKey){
	QStringList temp;

	QSqlTableModel * strecke = new QSqlTableModel();
	strecke->setTable("strecken");
	strecke->setFilter("StreckenKey=" + QString::number(StreckenKey));
	strecke->select();
	QString StreckentypenKeyString = strecke->data(strecke->index(0,StreckentypKey)).toString();
	temp.append(strecke->data(strecke->index(0,Streckenname)).toString());

	QSqlTableModel * typ = new QSqlTableModel();
	typ->setTable("streckentyp");
	typ->setFilter("StreckentypKey=" + StreckentypenKeyString);
	typ->select();
	temp.append(typ->data(typ->index(0,1)).toString());
	qDebug() << temp;
	return temp;
}
/*!
 * \brief überprüfen, ob der bisherige Eintrag einzigartig ist.
 */
void RFIDInputDialog::checkSingularity(){
	if(!autoInsert) // Verlassen, wenn das automatische Vervollständigen ausgeschaltet ist
		return;
	int count=0;
	bool first=true;
	QString sql = "SELECT count(name) FROM teilnehmer WHERE ";
	if(ui.nameLineEdit->isModified()){
		sql += "name LIKE '" + ui.nameLineEdit->text() + "\%' ";
		first=false;
	}
	if(ui.vornameLineEdit->isModified()){
		if(!first)
			sql += "AND ";
		sql += "vorname LIKE '" + ui.vornameLineEdit->text() + "\%' ";
		first=false;
	}
	if(ui.adresseLineEdit->isModified()){
		if(!first)
			sql += "AND ";
		sql += "adresse LIKE '" + ui.adresseLineEdit->text() + "\%' ";
		first=false;
	}
	if(ui.plzLineEdit->isModified()){
		if(!first)
			sql += "AND ";
		sql += "plz LIKE '" + ui.plzLineEdit->text() + "\%' ";
		first=false;
	}
	if(ui.ortLineEdit->isModified()){
		if(!first)
			sql += "AND ";
		sql += "Ort LIKE '" + ui.ortLineEdit->text() + "\%' ";
		first=false;
	}
	if(ui.clubLineEdit->isModified()){
		if(!first)
			sql += "AND ";
		sql += "Club LIKE '" + ui.clubLineEdit->text() + "\%' ";
		first=false;
	}
	if(ui.emailLineEdit->isModified()){
		if(!first)
			sql += "AND ";
		sql += "EMail LIKE '" + ui.emailLineEdit->text() + "\%' ";
		first=false;
	}
	if(ui.telephonLineEdit->isModified()){
		if(!first)
			sql += "AND ";
		sql += "Telefon LIKE '" + ui.telephonLineEdit->text() + "\%' ";
		first=false;
	}
	if(ui.mobileLineEdit->isModified()){
		if(!first)
			sql += "AND ";
		sql += "Mobile LIKE '" + ui.mobileLineEdit->text() + "\%' ";
		first=false;
	}

	qDebug() << sql;
	QSqlQuery query(sql);
	query.exec();
	query.next();
	count=query.value(0).toInt();

	if(count==1){ // Eintrag ist Einzigartig
		qDebug() << "Eintrag ist einzigartig";
		sql.replace("count(name)","TeilnehmerKey, Name, Vorname, Adresse, PLZ, Ort, Jahrgang, Geschlecht, Nationalitaet, Club, EMail, Telefon, Mobile, SNR_RFID");
		qDebug() << sql;
		query.exec(sql);
		query.next();
		QMessageBox msgBox;
		QPushButton *eintragenButton = msgBox.addButton(QObject::tr("Teilnehmer übernehmen und eintragen"), QMessageBox::ActionRole);
		QPushButton *uebernehmenButton = msgBox.addButton(QObject::tr("Teilnehmer übernehmen und verändern"), QMessageBox::ActionRole);
		QPushButton *vorschlagButton = msgBox.addButton(QObject::tr("Vorschlag als Vorlage für neunen Teilnehmer benutzen"), QMessageBox::ActionRole);
		QPushButton *abbrechenButton = msgBox.addButton(QObject::tr("Vorschlag verwerfen"), QMessageBox::ActionRole);
		msgBox.setDefaultButton(uebernehmenButton);
		msgBox.setEscapeButton(abbrechenButton);

		msgBox.setText("In der Datenbank befindet sich nur ein Benutzer der mit der bisherigen Eingabe übereinstimmt:\n"
				"\nName: " + query.value(Name).toString() + "\nVorname: " + query.value(Vorname).toString() +
				"\nAdresse: " + query.value(Adresse).toString() + "\nPLZ: " + query.value(PLZ).toString() +
				"\nWohnort: " + query.value(Ort).toString() + "\nNationalität: " + query.value(Nationalitaet).toString() +
				"\nJahrgang: " + query.value(Jahrgang).toString() + "\nGeschlecht: " + query.value(Geschlecht).toString() +
				"\nTeam / Club: " + query.value(Team_Club).toString() + "\nEMail: " + query.value(Email).toString() +
				"\nTelefon: " + query.value(Telefon).toString() + "\nMobile: " + query.value(Mobile).toString()
				);

		msgBox.setWindowTitle(QObject::tr("Einmaliger Eintrag in der Datenbank"));
		msgBox.setIcon(QMessageBox::Question);
		msgBox.exec();
		if(msgBox.clickedButton() == eintragenButton) {
			// Kategorie berechnen
			TeilnehmerKeyInt = query.value(TeilnehmerKey).toInt();
			ui.KategoriecomboBox->setCurrentIndex(
					ui.KategoriecomboBox->findText(
							calculateKategorie(query.value(Jahrgang).toInt())
					)
			);
			if(!clearValidFlag()) // Funktion beenden, falls nicht erfolgreich (Dialog bleibt)
				return;
			// Zeit für erkannten Teilnehmer in die Datenbank einfügen
			insertRacetime(TeilnehmerKeyInt);
			// Dialog schliessen
			this->close();
		}else if(msgBox.clickedButton() == uebernehmenButton){
			// Teilnehmer ID speichern
			TeilnehmerKeyInt = query.value(TeilnehmerKey).toInt();
			// Dialogfelder ausfüllen
			fillForm(&query);
			// AutoInsert ausschalten
			ui.autoCheckBox->setChecked(false);
			autoInsert=false;
		}else if(msgBox.clickedButton() == vorschlagButton){
			// Teilnehmer ID !nicht! speichern
			TeilnehmerKeyInt = 0;
			// Dialogfelder ausfüllen
			fillForm(&query);
			// AutoInsert ausschalten
			ui.autoCheckBox->setChecked(false);
			autoInsert=false;
		}else{
			// nichts tun
			// AutoInsert ausschalten
			ui.autoCheckBox->setChecked(false);
			autoInsert=false;
		}
	}

}
/*!
 * \brief Ausfüllen des gewählten Vorschlags in die Textfelder
 */
void RFIDInputDialog::fillForm(QSqlQuery* query){
	ui.nameLineEdit->setText(query->value(Name).toString());
	ui.vornameLineEdit->setText(query->value(Vorname).toString());
	ui.adresseLineEdit->setText(query->value(Adresse).toString());
	ui.plzLineEdit->setText(query->value(PLZ).toString());
	ui.ortLineEdit->setText(query->value(Ort).toString());
	ui.telephonLineEdit->setText(query->value(Telefon).toString());
	ui.mobileLineEdit->setText(query->value(Mobile).toString());
	ui.emailLineEdit->setText(query->value(Email).toString());
	ui.clubLineEdit->setText(query->value(Team_Club).toString());
	ui.nationalitaetComboBox->setCurrentIndex(
			ui.nationalitaetComboBox->findText(
					query->value(Nationalitaet).toString()
			)
	);
	ui.jahrgangSpinBox->setValue(query->value(Jahrgang).toInt());
	if(query->value(Geschlecht).toString()=="Maennlich")
		ui.maenlichRadioButton->setChecked(true);
	else
		ui.weiblichRadioButton->setChecked(true);
}
/*!
 * \brief Einfügen der Fahrzeit in die Datenbank
 * \param TeilnehmerKeyInt Nummer des Teilnehmers
 */
bool RFIDInputDialog::insertRacetime(int TeilnehmerKeyInt){
	QSqlQuery query;
	QString sql = "SELECT TeilnehmerKey FROM zeiten WHERE Startzeit='" +
				   toDateString(&pRfid->startdate,"yyyy-MM-dd hh:mm:ss") +
				   "' AND StreckenKey='"+ QString::number(pRfid->strecke) +
				   "' AND Endzeit='" + toDateString(&pRfid->enddate,"yyyy-MM-dd hh:mm:ss") + "'" ;
	qDebug() << sql;
	query.exec(sql);
	if(query.next()){
		// Zeit wurde per FTP übermittelt
		// "(Noch nicht ausgewertet)" Teilnehmer löschen
		sql = "DELETE FROM teilnehmer WHERE TeilnehmerKey=" + query.value(0).toString();
		qDebug() << sql;
		query.exec(sql);
		sql = "UPDATE zeiten SET TeilnehmerKey='" + QString::number(TeilnehmerKeyInt) + "', Kategorie='" +
				   ui.KategoriecomboBox->currentText() + "' WHERE Startzeit='" +
				   toDateString(&pRfid->startdate,"yyyy-MM-dd hh:mm:ss") +
				   "' AND StreckenKey='"+ QString::number(pRfid->strecke) +
				   "' AND Endzeit='" + toDateString(&pRfid->enddate,"yyyy-MM-dd hh:mm:ss") + "'" ;
		qDebug() << sql;
		if(query.exec(sql))
			return true;
		qDebug()<<query.lastError();
		return false;

	}else{
		// Zeit wurde nicht übertragen
		sql = "INSERT INTO zeiten ("
				"TimeKey, Eintrag, Startzeit, Endzeit, StreckenKey, TeilnehmerKey, Kategorie, Fahrzeit, SNR_RFID, TimeID "
				")VALUES("
				"NULL, CURRENT_TIMESTAMP , '" + toDateString(&pRfid->startdate,"yyyy-MM-dd hh:mm:ss") + "', '" +
				toDateString(&pRfid->enddate,"yyyy-MM-dd hh:mm:ss") + "', '" + QString::number(pRfid->strecke) +
				"', '" + QString::number(TeilnehmerKeyInt) + "', '" + ui.KategoriecomboBox->currentText() + "', '" +
				toDateString(&pRfid->racetime) + "', NULL , '1')";
		qDebug() << sql;
		query.exec("LOCK TABLES zeiten WRITE");
		if(query.exec(sql)){
			query.exec("UNLOCK TABLES");
			return true;
		}
		query.exec("UNLOCK TABLES");
		qDebug()<<query.lastError();
		return false;
	}
}
/*!
 * \brief Eintragen des neuen Teilnehmers und der Zeit
 */
bool RFIDInputDialog::insertPersonAndTime(){
	QString sql = "INSERT INTO teilnehmer ("
			"TeilnehmerKey , Name , Vorname , Adresse , PLZ , Ort , Jahrgang ,"
			"Geschlecht , Nationalitaet , Club , EMail , Telefon , Mobile , SNR_RFID"
			")VALUES(NULL, ";
	sql += "'" + ui.nameLineEdit->text() + "', ";
	sql += "'" + ui.vornameLineEdit->text() + "', ";
	sql += "'" + ui.adresseLineEdit->text() + "', ";
	sql += "'" + ui.plzLineEdit->text() + "', ";
	sql += "'" + ui.ortLineEdit->text() + "', ";
	sql += "'" + QString::number(ui.jahrgangSpinBox->value()) + "', ";
	if(ui.maenlichRadioButton->isChecked())
		sql += "'Maennlich', ";
	else
		sql += "'Weiblich', ";
	sql += "'" + ui.nationalitaetComboBox->itemText(ui.nationalitaetComboBox->currentIndex()) + "', ";
	if(ui.clubLineEdit->text()!="")
		sql += "'" + ui.clubLineEdit->text() + "', ";
	else
		sql += "NULL, ";
	if(ui.emailLineEdit->text()!="")
		sql += "'" + ui.emailLineEdit->text() + "', ";
	else
		sql += "NULL, ";
	if(ui.telephonLineEdit->text()!="")
		sql += "'" + ui.telephonLineEdit->text() + "', ";
	else
		sql += "NULL, ";
	if(ui.mobileLineEdit->text()!="")
		sql += "'" + ui.mobileLineEdit->text() + "', ";
	else
		sql += "NULL, ";
	sql += "NULL)";
	qDebug() << sql;
	QSqlQuery query;
	query.exec("LOCK TABLES teilnehmer WRITE");
	query.exec(sql);
	query.exec("UNLOCK TABLES");
	// TeilnehmerKey des soeben erstellten Benutzers finden
	sql = "SELECT TeilnehmerKey FROM teilnehmer WHERE ";
	sql += "name ='" + ui.nameLineEdit->text() + "' AND ";
	sql += "vorname ='" + ui.vornameLineEdit->text() + "' AND ";
	sql += "adresse ='" + ui.adresseLineEdit->text() + "' AND ";
	sql += "plz ='" + ui.plzLineEdit->text() + "' AND ";
	sql += "ort ='" + ui.ortLineEdit->text() + "' ";

	qDebug() << sql;
	query.exec(sql);
	query.next();
	// Fahrzeit mit zuordnung zum erstellten Teilnehmers eintragen
	insertRacetime(query.value(0).toInt());
	return true;
}

/*!
 * \brief Änderungen der Benutzerdaten in die Datenbank übertragen
 */
bool RFIDInputDialog::updatePerson(int TeilnehmerKeyInt){
	QString sql = "UPDATE teilnehmer SET ";
	bool first=true;
	if(ui.nameLineEdit->isModified()){
		sql += "name = '" + ui.nameLineEdit->text() + "' ";
		first=false;
	}
	if(ui.vornameLineEdit->isModified()){
		if(!first)
			sql += ", ";
		sql += "vorname = '" + ui.vornameLineEdit->text() + "' ";
		first=false;
	}
	if(ui.adresseLineEdit->isModified()){
		if(!first)
			sql += ", ";
		sql += "adresse = '" + ui.adresseLineEdit->text() + "' ";
		first=false;
	}
	if(ui.plzLineEdit->isModified()){
		if(!first)
			sql += ", ";
		sql += "plz = '" + ui.plzLineEdit->text() + "' ";
		first=false;
	}
	if(ui.ortLineEdit->isModified()){
		if(!first)
			sql += ", ";
		sql += "Ort = '" + ui.ortLineEdit->text() + "' ";
		first=false;
	}
	if(ui.clubLineEdit->isModified()){
		if(!first)
			sql += ", ";
		sql += "Club = '" + ui.clubLineEdit->text() + "' ";
		first=false;
	}
	if(ui.emailLineEdit->isModified()){
		if(!first)
			sql += ", ";
		sql += "EMail = '" + ui.emailLineEdit->text() + "' ";
		first=false;
	}
	if(ui.telephonLineEdit->isModified()){
		if(!first)
			sql += ", ";
		sql += "Telefon = '" + ui.telephonLineEdit->text() + "' ";
		first=false;
	}
	if(ui.mobileLineEdit->isModified()){
		if(!first)
			sql += ", ";
		sql += "Mobile = '" + ui.mobileLineEdit->text() + "' ";
		first=false;
	}
	if(!first)
		sql += ", ";
	sql += "Nationalitaet = '" + ui.nationalitaetComboBox->itemText(ui.nationalitaetComboBox->currentIndex()) + "' ";
	first=false;
	sql += ", Jahrgang = '" + QString::number(ui.jahrgangSpinBox->value()) + "' ";
	if(ui.maenlichRadioButton->isChecked())
		sql += ", Geschlecht = 'Maennlich' ";
	else
		sql += ", Geschlecht = 'Weiblich' ";
	sql += "WHERE TeilnehmerKey = " + QString::number(TeilnehmerKeyInt);

	qDebug() << sql;
	QSqlQuery query;
	if(query.exec(sql))
		return true;
	qDebug()<<query.lastError();
	return false;
}
/*!
 * \brief Slot für Textänderungen
 */
void RFIDInputDialog::on_nameLineEdit_textEdited(){
	qDebug() << "Name Edited";
	checkSingularity();
}
/*!
 * \brief Slot für Textänderungen
 */
void RFIDInputDialog::on_vornameLineEdit_textEdited(){
	qDebug() << "Vorname Edited";
	checkSingularity();
}
/*!
 * \brief Slot für Textänderungen
 */
void RFIDInputDialog::on_adresseLineEdit_textEdited(){
	qDebug() << "adresse Edited";
	checkSingularity();
}
/*!
 * \brief Slot für Textänderungen
 */
void RFIDInputDialog::on_plzLineEdit_textEdited(){
	qDebug() << "PLZ Edited";
	checkSingularity();
}
/*!
 * \brief Slot für Textänderungen
 */
void RFIDInputDialog::on_ortLineEdit_textEdited(){
	qDebug() << "Ort Edited";
	checkSingularity();
}
/*!
 * \brief Slot für Textänderungen
 */
void RFIDInputDialog::on_telephonLineEdit_textEdited(){
	qDebug() << "telefon Edited";
	checkSingularity();
}
/*!
 * \brief Slot für Textänderungen
 */
void RFIDInputDialog::on_mobileLineEdit_textEdited(){
	qDebug() << "mobile Edited";
	checkSingularity();
}
/*!
 * \brief Slot für Textänderungen
 */
void RFIDInputDialog::on_emailLineEdit_textEdited(){
	qDebug() << "email Edited";
	checkSingularity();
}
/*!
 * \brief Slot für Textänderungen
 */
void RFIDInputDialog::on_clubLineEdit_textEdited(){
	qDebug() << "club Edited";
	checkSingularity();
}
/*!
 * \brief Slot für Textänderungen
 */
void RFIDInputDialog::on_nationalitaetComboBox_currentIndexChanged(){
	qDebug() << "Nationalität Edit";

}
/*!
 * \brief Slot für Jahrgangsänderungen (aktualisieren der Kategorie)
 */
void RFIDInputDialog::on_jahrgangSpinBox_valueChanged() {
	qDebug() << "Jahrgang Spin";
	ui.KategoriecomboBox->setCurrentIndex(
			ui.KategoriecomboBox->findText(
					calculateKategorie(ui.jahrgangSpinBox->value())
			)
	);
}
/*!
 * \brief Berechne die Kategorie aufgrund der Altersbereiche in der Datenbank
 */
/*!
 * \brief Slot für CheckBox "automatisches Vervollständigen"
 */
QString RFIDInputDialog::calculateKategorie(int jahrgang){
	QDate current(QDate::currentDate());
	qDebug() << current.toString("dd.MM.yyyy");
	qDebug() << current.year();
	int alter = current.year()-jahrgang;

	QString sql = "SELECT name FROM kategorien WHERE von<='" + QString::number(alter) + "' AND bis>='" + QString::number(alter) + "'";
	QSqlQuery query(sql);
	query.exec();
	qDebug() << query.lastError();
	query.next();
	return query.value(0).toString();
}

void RFIDInputDialog::on_autoCheckBox_stateChanged(){
	autoInsert = ui.autoCheckBox->isChecked();
	qDebug() << autoInsert;
	if(autoInsert)
		checkSingularity();
}
/*!
 * \brief Slot für Ok-Button
 */
void RFIDInputDialog::on_okButton_released(){
	qDebug() << "Ok Clicked";
	if(!validation()) // Funktion beenden, falls nicht gültig (Dialog bleibt)
		return;
	if(TeilnehmerKeyInt==0){
		if(!clearValidFlag()) // Funktion beenden, falls nicht erfolgreich (Dialog bleibt)
			return;
		qDebug() << "neuer Teilnehmer erstellt";
		// Neuer Teilnehmer und dessen Zeit hinzufügen
		insertPersonAndTime();
		this->close();
	}else{
		if(!clearValidFlag()) // Funktion beenden, falls nicht erfolgreich (Dialog bleibt)
			return;
		qDebug() << "Teilnehmer " << TeilnehmerKeyInt << "updated";
		// Teilnehmer Daten aktualisieren
		updatePerson(TeilnehmerKeyInt);
		// Zeit hinzufügen
		insertRacetime(TeilnehmerKeyInt);
		this->close();
	}
}
/*!
 * \brief Validierung der Einträge
 */
bool RFIDInputDialog::validation(){
	bool valid = true;
	QString error = "Die folgenden Felder benötigen noch einen Inhalt:\n";
	if(ui.nameLineEdit->text()==""){
		error += "Name, ";
		valid = false;
	}
	if(ui.vornameLineEdit->text()==""){
		error += "Vorname, ";
		valid = false;
	}
	if(ui.adresseLineEdit->text()==""){
		error += "Adresse, ";
		valid = false;
	}
	if(ui.plzLineEdit->text()==""){
		error += "PLZ, ";
		valid = false;
	}
	if(ui.ortLineEdit->text()==""){
		error += "Wohnort, ";
		valid = false;
	}

	if(!ui.maenlichRadioButton->isChecked() && !ui.weiblichRadioButton->isChecked()){
		error += "Geschlecht, ";
		valid = false;
	}
	// entfernt 2 Zeichen am Ende des Strings
	error.chop(2);
	if(!valid)
		QMessageBox::critical(0,QObject::tr("Fehlende Einträge"),error);
	return valid;
}
/*!
 * \brief Löschen der Statusbits der Karte nach dem Auswerten
 */
bool RFIDInputDialog::clearValidFlag(){
	if(!pRfid->clearValidFlag()){
		qDebug() << "Valid Flag nicht gelöscht";
		return false;
	}else{
		qDebug() << "Valid Flag gelöscht";
		return true;
	}
}
/*!
 * \brief Slot für Abbrechen-Button
 */
void RFIDInputDialog::on_canButton_released(){
	qDebug() << "Abbrechen Clicked";
	pRfid->greenLED();
	this->close();
}
