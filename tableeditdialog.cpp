 /**
 *******************************************************************************
 * \file    tableeditdialog.cpp
 *******************************************************************************
 * \brief    Dieser Dialog dient dem Editieren der Eintraege.
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
#include "tableeditdialog.h"
#include "delegates/ResultateDelegate.h"
#include "delegates/KontaktDelegate.h"
#include "User.h"
#include <QtSql>
#include <QtGui>



/*!
 * \brief Konstruktor
 * \param TeilnehmerKeyParam Primarykey des Teilnehmers
 * \param user Pointer auf den angemeldeten Benutzer
 * \param parent Pointer auf das aufrufende Objekt
 */
TableEditDialog::TableEditDialog(int TeilnehmerKeyParam, User* user, QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	// parent zu Pointer für das Hauptfenster casten
	this->mainWindow=(BEO_Timing*)parent;
	qDebug() << TeilnehmerKeyParam;
	resultateView = ui.ResultateTable;
	// Tabelle für die Kontaktdaten mit dem QSqlTableModel erstellen
	kontaktView = ui.KontaktdatenTable;
	kontaktModel = new QSqlTableModel(kontaktView);
	kontaktModel->setTable("teilnehmer");
	kontaktModel->setFilter("TeilnehmerKey='" + QString::number(TeilnehmerKeyParam) + "'");
	kontaktModel->select();
	kontaktModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
	qDebug() << kontaktModel->lastError();
	// Headerdaten der Tabelle setzen
	kontaktModel->setHeaderData(TeilnehmerKey, Qt::Horizontal, tr("TeilnehmerKey"));
	kontaktModel->setHeaderData(Name, Qt::Horizontal, tr("Name"));
	kontaktModel->setHeaderData(Vorname, Qt::Horizontal, tr("Vorname"));
	kontaktModel->setHeaderData(Adresse, Qt::Horizontal, tr("Adresse"));
	kontaktModel->setHeaderData(PLZ, Qt::Horizontal, tr("PLZ"));
	kontaktModel->setHeaderData(Ort, Qt::Horizontal, tr("Ort"));
	kontaktModel->setHeaderData(Jahrgang, Qt::Horizontal, tr("Jahrgang"));
	kontaktModel->setHeaderData(Geschlecht, Qt::Horizontal, tr("Geschlecht"));
	kontaktModel->setHeaderData(Nationalitaet, Qt::Horizontal, tr("Nationalität"));
	kontaktModel->setHeaderData(Team_Club, Qt::Horizontal, tr("Team / Club"));
	kontaktModel->setHeaderData(Email, Qt::Horizontal, tr("Email"));
	kontaktModel->setHeaderData(Telefon, Qt::Horizontal, tr("Telefon"));
	kontaktModel->setHeaderData(Mobile, Qt::Horizontal, tr("Mobile"));
	kontaktModel->setHeaderData(RFID_SNR, Qt::Horizontal, tr("RFID-Snr"));
	// Ansicht mit Modell verbinden
	kontaktView->setModel(kontaktModel);
	// Auswahlmöglichkeiten definieren
	kontaktView->setSelectionMode(QAbstractItemView::SingleSelection);
	kontaktView->setSelectionBehavior(QAbstractItemView::SelectItems);
	// Spaltenbreite einstellen
	kontaktView->resizeColumnsToContents();
	// Bearbeitungsmöglichkeiten einstellen
	kontaktView->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
	QHeaderView * header = kontaktView->horizontalHeader();
	header->setStretchLastSection(true);
	// Eigene Delegateklasse als Schnittstelle zwischen dem Modell und der Ansicht definieren
	// siehe "KontaktDelegate.cpp"
	kontaktView->setItemDelegate(new KontaktDelegate());
	
	// Erstellen der Tabelle für die Fahrzeiten mit dem QSqlTableModel
	resultateModel = new QSqlTableModel(resultateView);
	resultateModel->setTable("zeiten");
	resultateModel->setFilter("TeilnehmerKey='" + QString::number(TeilnehmerKeyParam) + "'");
	resultateModel->select();
	resultateModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
	qDebug() << resultateModel->lastError();
	// Headerdaten setzen
	resultateModel->setHeaderData(TimeKey, Qt::Horizontal, tr("TimeKey"));
	resultateModel->setHeaderData(Eintrag, Qt::Horizontal, tr("Eintrag"));
	resultateModel->setHeaderData(Startzeit, Qt::Horizontal, tr("Startzeit"));
	resultateModel->setHeaderData(Endzeit, Qt::Horizontal, tr("Endzeit"));
	resultateModel->setHeaderData(StreckenKey, Qt::Horizontal, tr("StreckenKey"));
	resultateModel->setHeaderData(TeilnehmerKey2, Qt::Horizontal, tr("TeilnehmerKey"));
	resultateModel->setHeaderData(Kategorie, Qt::Horizontal, tr("Kategorie"));
	resultateModel->setHeaderData(Fahrzeit, Qt::Horizontal, tr("Fahrzeit"));
	resultateModel->setHeaderData(SNR_RFID, Qt::Horizontal, tr("SNR_RFID"));
	resultateModel->setHeaderData(TimeID, Qt::Horizontal, tr("TimeID"));
	// Modell mit der Ansicht verbinden
	resultateView->setModel(resultateModel);
	// Auswahlmöglichkeiten beschränken
	resultateView->setSelectionMode(QAbstractItemView::SingleSelection);
	resultateView->setSelectionBehavior(QAbstractItemView::SelectItems);
	// Spaltenbreite anpassen
	resultateView->resizeColumnsToContents();
	// Bearbeitungsmöglichkeiten definieren
	resultateView->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
	header = resultateView->horizontalHeader();
	header->setStretchLastSection(true);
	// Eigene Delegateklasse als Schnittstelle zwischen dem Modell und der Ansicht definieren
	// siehe "ResultateDelegate.cpp"
	resultateView->setItemDelegate(new ResultateDelegate());
	
	// Angezeigte Spalten, je nach Berechtigung des angemeldeten Benutzers
	if(user->getUsertype() >= administrator){
		kontaktView->setColumnHidden(TeilnehmerKey,true);
		resultateView->setColumnHidden(TeilnehmerKey2,true);
		resultateView->setColumnHidden(StreckenKey,true);
		resultateView->setColumnHidden(TimeKey,true);
	}
	if(user->getUsertype() >= manager){
		kontaktView->setColumnHidden(RFID_SNR,true);
		resultateView->setColumnHidden(SNR_RFID,true);
	}
	// Ort der Änderungen speichern
    kontakteChanged = new QModelIndexList();
    resultateChanged = new QModelIndexList();
	connect(kontaktModel,
			SIGNAL(dataChanged(const QModelIndex, const QModelIndex)),
			this,
			SLOT(on_kontakte_dataChanged(const QModelIndex, const QModelIndex))
			);
	connect(resultateModel,
			SIGNAL(dataChanged(const QModelIndex, const QModelIndex)),
			this,
			SLOT(on_resultate_dataChanged(const QModelIndex, const QModelIndex))
			);
}
/*!
 * \brief Destruktor
 */
TableEditDialog::~TableEditDialog()
{
	
}
/*!
 * \brief Slot für Löschen-Button
 */
void TableEditDialog::on_loeschenButton_released(){
	int selected;
	// Warnung ausgeben 
	QMessageBox msgBox;
	QPushButton *loeschenButton = msgBox.addButton(tr("OK"), QMessageBox::ActionRole);
	QPushButton *abortButton = msgBox.addButton(tr("Abbrechen"), QMessageBox::ActionRole);
	msgBox.setDefaultButton(abortButton);
	msgBox.setEscapeButton(abortButton);
	msgBox.setText(tr("Die ausgewählte Zeile wird gelöscht. Diese Aktion kann nicht Rückgängig gemacht werden!"));
	msgBox.setWindowTitle(tr("Bestätigen des Löschvorgangs"));
	msgBox.setIcon(QMessageBox::Warning);
	msgBox.exec();
	// Zeile im Modell löschen, falls bestätigt
	if(msgBox.clickedButton() == loeschenButton){
		QItemSelectionModel* model = resultateView->selectionModel();
		if(model->hasSelection()){
			selected=model->selection().indexes().at(0).row();
			resultateModel->removeRow(selected);
		}
		// Änderungen an die DB übermitteln
		resultateModel->submitAll();
	}
}
/*!
 * \brief Slot für Bestätigen-Button
 */
void TableEditDialog::on_BestaetigenButton_released(){
	// Änderungen anzeigen
	QMessageBox msgBox;
	QPushButton *bestaetigenButton = msgBox.addButton(tr("OK"), QMessageBox::ActionRole);
	QPushButton *abortButton = msgBox.addButton(tr("Abbrechen"), QMessageBox::ActionRole);
	msgBox.setDefaultButton(abortButton);
	msgBox.setEscapeButton(abortButton);
	QString text = "Die folgenden Änderungen werden übernommen:\n\n";
	text += "Kontaktinformationen (Zeile, Spalte):\n";
	// (Kontakte) Anzeigen, falls nicht leer
	if(!kontakteChanged->empty()){
		for(int i=0;i<kontakteChanged->count();++i){
			text += kontaktModel->data(kontakteChanged->at(i)).toString() + " (" +
				QString::number(kontakteChanged->at(i).row()+1) + ", " +
				QString::number(kontakteChanged->at(i).column()+1) + ")\n";
		}
		// Speicher zurücksetzen
		kontakteChanged->clear();
	}else{
		text += "keine\n";
	}
	text += "\nResultate (Zeile, Spalte):\n";
	if(!resultateChanged->empty()){
		// (Zeiten) Anzeigen, falls nicht leer
		for(int i=0;i<resultateChanged->count();++i){
			text += resultateModel->data(resultateChanged->at(i)).toString() + " (" +
				QString::number(resultateChanged->at(i).row()+1) + ", " +
				QString::number(resultateChanged->at(i).column()+1) + ")\n";
		}
		// Speicher zurücksetzen
		resultateChanged->clear();
	}
	text += "\nDiese Aktion kann nicht Rückgängig gemacht werden!";
	msgBox.setText(text);
	msgBox.setWindowTitle(tr("Bestätigen der Änderungen"));
	msgBox.setIcon(QMessageBox::Question);
	msgBox.exec();
	// Übermitteln, falls bestätigt
	if(msgBox.clickedButton() == bestaetigenButton){
		kontaktModel->submitAll();
		resultateModel->submitAll();
	}
	// Argument '0' bedeutet in Baum ausgewähltes Rennen neu vom Server lesen
	mainWindow->Read_Race(0);
}
/*!
 * \brief Slot für Verwerfen-Button
 */
void TableEditDialog::on_VerwerfenButton_released(){
	// Änderungen im Model verwerfen und Dialog schliessen
	kontaktModel->revertAll();
	resultateModel->revertAll();
	this->close();
}
/*!
 * \brief Slot um Datenänderungen im Model in einer Liste zu speichern
 * \param topLeft linke, obere Ecke der Auswahl
 * \param bottomRight rechte, untere Ecke der Auswahl
 */
void TableEditDialog::on_kontakte_dataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight){
	kontakteChanged->append(topLeft);
}
/*!
 * \brief Slot um Datenänderungen im Model in einer Liste zu speichern
 * \param topLeft linke, obere Ecke der Auswahl
 * \param bottomRight rechte, untere Ecke der Auswahl
 */
void TableEditDialog::on_resultate_dataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight){
	resultateChanged->append(topLeft);
}
