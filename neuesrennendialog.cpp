 /**
 *******************************************************************************
 * \file    neuesrennendialog.cpp
 *******************************************************************************
 * \brief    Dieser Dialog dient zum erstellen eines neunen Rennens.
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

#include "neuesrennendialog.h"
#include <QtSql>
#include <QtGui>
#include "beo_timing.h"
/*!
 * \brief Konstruktor
 */
NeuesRennenDialog::NeuesRennenDialog(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	// Nur Buchstaben und Leerschläge
	QRegExp charExp ("[\\-\\w\\s]+");
	ui.nameLineEdit->setValidator (new QRegExpValidator (charExp, this));
	// Maximale Länge = 50 Zeichen
	ui.nameLineEdit->setMaxLength (50);
	// Heutiges Datum setzen 
	ui.startdatumDateEdit->setDate(QDate::currentDate());
	ui.enddatumDateEdit->setDate(QDate::currentDate());
	// Verfügbare Streckentypen aus der Datenbank lesen	
	// und mit Icon in ComboBox zu Verfügung stellen
	QSqlQuery query("SELECT StreckentypKey, Typ FROM streckentyp");
	query.exec();
	for(int i=0;i<query.numRowsAffected();++i){
		query.next();
		// Symbol auswählen
		QIcon icon;
		switch(query.value(0).toInt()){
			case Rennvelo: icon.addFile(":/images/rennrad.png"); break;
			case Mountainbike: icon.addFile(":/images/bike.png"); break;
			case Laufen: icon.addFile(":/images/plauf.png"); break;
			case Walking: icon.addFile(":/images/walking.png"); break;
			case Langlauf: icon.addFile(":/images/langlauf.png"); break;
			case Inline: icon.addFile(":/images/inline.png"); break;
			default: icon.addFile(":/images/unbekannt.png"); break;
		}
		ui.streckentypComboBox->addItem(icon,query.value(1).toString());
	}
	// Default auf Rennvelo setzen 
	ui.streckentypComboBox->setCurrentIndex(
			ui.streckentypComboBox->findText("Rennvelo")
	);
	
}
/*!
 * \brief Destruktor
 */
NeuesRennenDialog::~NeuesRennenDialog()
{

}

/*!
 * \brief Slot für Ok-Button
 */
void NeuesRennenDialog::on_okButton_released(){
	// Einträge überprüfen
	if(!validation())
		return;
	// Rennen in Datenbank eintragen
	QSqlQuery query;
	QString sql = "INSERT INTO strecken ("
			"StreckenKey, Streckenname, Startdatum, Enddatum, Jahr, StreckentypKey, Beschreibung "			
			")VALUES(NULL, ";
	sql += "'" + ui.nameLineEdit->text() + "', ";
	sql += "'" + ui.startdatumDateEdit->date().toString("yyyy-MM-dd") + "', ";
	sql += "'" + ui.enddatumDateEdit->date().toString("yyyy-MM-dd") + "', ";
	sql += "'" + ui.startdatumDateEdit->date().toString("yyyy") + "', ";
	if(!query.exec("SELECT StreckentypKey FROM streckentyp WHERE Typ='" +
			       ui.streckentypComboBox->itemText(ui.streckentypComboBox->currentIndex()) + "'") )
		qDebug()<<query.lastError();
	query.next();
	sql += "'" + query.value(0).toString() + "', ";
	
	if(ui.beschreibungTextEdit->toPlainText()!="")
		sql += "'" + ui.beschreibungTextEdit->toPlainText() + "') ";
	else
		sql += "NULL) ";
	qDebug() << sql;
	query.clear();
	query.exec("LOCK TABLES strecken WRITE");
	if(!query.exec(sql))
		qDebug()<<query.lastError();
	query.exec("UNLOCK TABLES");
	// TreeWidged in Hauptapplikation updaten
	emit tree_update();
	// Dialog schliessen
	this->close();
}

/*!
 * \brief Slot für Abbrechen-Button
 */
void NeuesRennenDialog::on_canButton_released(){
	// Dialog schliessen
	this->close();
}
/*!
 * \brief Valisierung der Eingaben
 */
bool NeuesRennenDialog::validation(){
	// Überprüfen ob die nötigen Einträge gemacht wurden
	bool valid = true;
	QString error = "Die folgenden Felder benötigen noch einen Inhalt:\n";
	if(ui.nameLineEdit->text()==""){
		error += "Name, ";
		valid = false;
	}
	// überprüft, ob das Startdatum früher als das Enddatum ist
	if(ui.startdatumDateEdit->date() > ui.enddatumDateEdit->date() ){
		error += "Datum (Startdatum > Enddatum), ";
		valid = false;
	}
	// entfernt 2 Zeichen am Ende des Strings
	error.chop(2);
	
	if(!valid)
		QMessageBox::critical(0,QObject::tr("Fehlende Einträge"),error);
	return valid;
}
