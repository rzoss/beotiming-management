 /**
 *******************************************************************************
 * \file    logfilelesendialog.cpp
 *******************************************************************************
 * \brief    Dieser Dialog sucht eine Log-Datei einer Zielstation nach nicht 
 * uebermittelten Eintraegen ab.
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
#include "logfilelesendialog.h"
#include <QtGui>
#include <QtSql>
#include <QFileDialog>
#include <QMessageBox>

/*!
 * \brief Konstruktor
 */
LogfileLesenDialog::LogfileLesenDialog(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	
	// Listen verhalten anpassen
	ui.neuListWidget->setSelectionMode(QAbstractItemView::MultiSelection);
	ui.delListWidget->setSelectionMode(QAbstractItemView::MultiSelection);
	
	// Log File auswählen
	QString fileName = QFileDialog::getOpenFileName(this, tr("Log-Datei öffnen"),
	                                                     " ",
	                                                     tr("Log-Datei (*.log)"));
	int linecount=0;
	if(!fileName.isEmpty()){
		QFile file(fileName);
		if(!file.open(QIODevice::ReadOnly)){
			QMessageBox::warning(this, tr("Log-Datei öffnen"),
									tr("Kann die Datei %1 nicht öffnen;\n%2")
									.arg(file.fileName()).arg(file.errorString()));
			this->close();
			return;
		}
		QTextStream in(&file);
		// Zeilenweises auslesen der Datei
		while(1){
			QString line = in.readLine();
			qDebug() << line;
			// Abbrechen, wenn End-Of-File erreicht
			if(line.isNull())
				break; // EOF
			line.remove(0,21); // Zeitstempel entfernen
			QStringList list = line.split(";");
			qDebug() << list.at(0);
			// Entscheiden, ob der Eintrag eine Zeit ist
			if(list.at(0).contains("TIM")){ // Zeile ist eine Zeit 
				QSqlQuery query;
				QString sql = "SELECT count(*) FROM zeiten WHERE Startzeit='" + list.at(2) + "' AND StreckenKey='" + list.at(1) + "' AND SNR_RFID='" + list.at(5) + "'";
				qDebug() << sql;
				query.exec(sql);
				query.next();
				// Vorhanden in DB
				if(query.value(0).toInt()==1){
					// Zeit ist bereits in Datenbank vorhanden
					qDebug() << "Zeit ist in DB vorhanden";
					if(list.at(0).contains("TIMW")){
						// Zeile ignorieren, da bereits alles eingetragen ist
					}else{
						// Zeile in Liste eintragen und zur Auswahl bereitstellen
						ui.delListWidget->addItem(createItem(line));
						add.append(line); // gelesene Zeile in Variable sichern
					}
				// nicht vorhanden in DB
				}else if(query.value(0).toInt()==0){
					// Zeit ist in der Datenbank nicht vorhanden
					qDebug() << "Zeit ist in DB nicht vorhanden";
					if(list.at(0).contains("TIMD")){
						// Zeile ignorieren, da bereits gelöscht
					}else{
						// Zeile in Liste eintragen und zur Auswahl bereitstellen
						ui.neuListWidget->addItem(createItem(line));
						remove.append(line);
					}
					
				}else{
					// Problem: Zeit mehrfach vorhanden
					qDebug() << "Zeit ist in DB mehrfach vorhanden";
				}
			}else{
				// ingoriere Zeile, da keine Zeit
			}
			linecount++;
			
		}
		file.close();
		// Inforamtionen ausgeben, wenn keine Einträge vorhanden
		if(!linecount){
			QMessageBox::warning(this, tr("Keine neuen Einträge"),
							tr("In der Datei %1 hat es keine Einträge, die eine Anpassung "
									"der Datenbank erfordern.")
							.arg(file.fileName()));
			this->close();
		}
					
	}
	
}

/*!
 * \brief Destruktor
 */
LogfileLesenDialog::~LogfileLesenDialog()
{

}

/*!
 * \brief Inhalt der Listen erstellen
 * \param line String aus der Logdatei
 * \return Listenelement
 */
QListWidgetItem* LogfileLesenDialog::createItem(QString line){
	QListWidgetItem* item = new QListWidgetItem();
	// Spliten des Strings
	QStringList list = line.split(";");
	
	QSqlQuery query;
	// Streckentyp zu Strecke finden
	QString sql = "SELECT StreckentypKey FROM strecken WHERE strecken.StreckenKey='" +
					list.at(1) + "'";
	qDebug() << sql;
	query.exec(sql);
	// und Symbol definieren
	QIcon icon;
	query.next();
	switch(query.value(0).toInt()){
		case Rennvelo: icon.addFile(":/images/rennrad.png"); break;
		case Mountainbike: icon.addFile(":/images/bike.png"); break;
		case Laufen: icon.addFile(":/images/plauf.png"); break;
		case Walking: icon.addFile(":/images/walking.png"); break;
		case Langlauf: icon.addFile(":/images/langlauf.png"); break;
		case Inline: icon.addFile(":/images/inline.png"); break;
		default: icon.addFile(":/images/unbekannt.png"); break;
	}
	item->setIcon(icon);
	// Herausfinden, ob die Karte persönlich ist oder nicht
	query.exec("SELECT name, vorname FROM teilnehmer WHERE SNR_RFID='" + list.at(5) + "'");
	if(query.next())
		item->setText(query.value(0).toString() + " " + query.value(1).toString() + 
				", Fahrzeit: " + list.at(4) + " (" + line + ")");
	else 
		item->setText("Unbekannt, Fahrzeit: " + list.at(4) + " (" + line + ")");
	// ListenElement zurückgeben
	return item;
}
/*!
 * \brief Slot für die Reaktion auf Änderungen der CheckBox
 * \param state Status der CheckBox
 */
void LogfileLesenDialog::on_neuCheckBox_stateChanged ( int state ){
	if(state==Qt::Checked){
		ui.neuListWidget->selectAll();	
	}else{
		ui.neuListWidget->clearSelection();
	}
}

/*!
 * \brief Slot für die Reaktion auf Änderungen der CheckBox
 * \param state Status der CheckBox
 */
void LogfileLesenDialog::on_delCheckBox_stateChanged ( int state ){
	if(state==Qt::Checked){
		ui.delListWidget->selectAll();	
	}else{
		ui.delListWidget->clearSelection();
	}
}

/*!
 * \brief Slot für den Ok-Button
 */
void LogfileLesenDialog::on_okButton_released(){
	// Falls eine Selektion gemacht wurde
	if (ui.neuListWidget->selectionModel()->hasSelection()) {
		QList<QListWidgetItem*> neulist = ui.neuListWidget->selectedItems();
		// Ausgewählte eintragen
		qDebug() << neulist.count();
		// Liste für Neueintragungen abarbeiten
		for (int i=0; i<neulist.count() ; ++i) {
			int TeilnehmerKey = 0;
			QString str = neulist.at(i)->data(Qt::DisplayRole).toString();
			str.remove(0, str.indexOf("(TIM")+1);
			str.chop(1);
			qDebug() << str;
			QStringList list = str.split(";");
			QSqlQuery query;
			query.exec("SELECT TeilnehmerKey"
				"FROM teilnehmer"
				"WHERE SNR_RFID = '" + list.at(5) + "' AND name!='(noch'");
			if (query.next()) {
				// Nummer fix vergeben
				TeilnehmerKey = query.value(0).toInt();
			} else {
				// (Noch nicht ausgewertet) - User erstellen
				QString sql = "INSERT INTO teilnehmer("
					"TeilnehmerKey, Name, Vorname, Adresse, PLZ, Ort, Jahrgang, "
					"Geschlecht, Nationalitaet, Club, EMail, Telefon, Mobile, "
					"SNR_RFID ) VALUES ( NULL , '(noch', 'nicht', 'n/a', '0', 'ausgewertet)', "
					"'0', '0', 'Schweiz', NULL , NULL , NULL , NULL , '"
						+ list.at(5) + "')";
				qDebug() << sql;
				query.exec("LOCK TABLES teilnehmer WRITE");
				query.exec(sql);
				query.exec("UNLOCK TABLES");
				sql = "SELECT TeilnehmerKey FROM teilnehmer "
					"WHERE SNR_RFID = '" + list.at(5)
						+ "' AND name='(noch' ORDER BY TeilnehmerKey DESC";
				qDebug() << sql;
				query.exec(sql);
				query.next();
				TeilnehmerKey = query.value(0).toInt();
			}
			// Teilnehmer eintragen
			query.exec("LOCK TABLES zeiten WRITE");
			query.exec("INSERT INTO zeiten(TimeKey, Eintrag, Startzeit, "
				"Endzeit, StreckenKey, TeilnehmerKey, Kategorie, Fahrzeit, SNR_RFID) "
				"VALUES (NULL, CURRENT_TIMESTAMP, '" + list.at(2) + "', '"
					+ list.at(3) + "', '"+ list.at(1) + "', '"
					+ QString::number(TeilnehmerKey) + "',' ', '"+ list.at(4)
					+ "', '"+ list.at(5) + "')");
			query.exec("UNLOCK TABLES");
			// ListWidgedItem entfernen
			ui.neuListWidget->removeItemWidget(neulist.at(i));
		}
	}
	// Falls eine Auswahl gemacht wurde für das Löschen
	if (ui.delListWidget->selectionModel()->hasSelection()) {
		QList<QListWidgetItem*> dellist = ui.delListWidget->selectedItems();
		// Ausgewählte löschen
		qDebug() << dellist.count();
		// Abarbeiten der Liste für die zu Löschenden Einträge
		for (int i=0; i<dellist.count() ; ++i) {
			int TeilnehmerKey = 0;
			QString str = dellist.at(i)->data(Qt::DisplayRole).toString();
			str.remove(0, str.indexOf("(TIM")+1);
			str.chop(1);
			qDebug() << str;
			QStringList list = str.split(";");
			QSqlQuery query;
			query.exec("SELECT TeilnehmerKey"
				"FROM teilnehmer"
				"WHERE SNR_RFID = '" + list.at(5) + "' AND name!='(noch'");
			if (!query.next()) {
				// "(noch nicht ausgewertet)" - User in DB löschen
				QString
						sql = "SELECT TeilnehmerKey FROM zeiten WHERE Startzeit='"
								+ list.at(2) + "' AND StreckenKey='"
								+ list.at(1) + "'";
				qDebug() << sql;
				query.exec(sql);
				query.next();
				TeilnehmerKey = query.value(0).toInt();
				sql = "DELETE FROM teilnehmer WHERE TeilnehmerKey="
						+ QString::number(TeilnehmerKey);
				qDebug() << sql;
				query.exec(sql);
			}
			// Zeit löschen
			QString sql = "DELETE FROM zeiten WHERE Startzeit='" + list.at(2)
					+ "' AND StreckenKey='"+ list.at(1) + "' AND Endzeit='" + list.at(3) + "'" ;
			qDebug() << sql;
			query.exec(sql);
			// ListWidgedItem entfernen
			ui.delListWidget->removeItemWidget(dellist.at(i));
		}
	}
	this->close();
}

/*!
 * \brief Slot für den Abbrechen-Button
 */
void LogfileLesenDialog::on_canButton_released(){
	// Fenster schliessen
	this->close();
}

