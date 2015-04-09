 /**
 *******************************************************************************
 * \file    neueruserdialog.cpp
 *******************************************************************************
 * \brief    Dieser Dialog dient zum erstellen eines neuen Benutzers.
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

#include "neueruserdialog.h"
#include <QtSql>
#include <QtGui>
#include "User.h"
#include "md5/md5.h"
#include <QHeaderView>
#include <QMessageBox>
#include <QInputDialog>

/*!
 * \brief Konstruktor
 * \param user Pointer auf den angemeldeten Benutzer
 * \param parent Pointer auf das aufrufende Objekt
 */
NeuerUserDialog::NeuerUserDialog(User* user, QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	this->pUser=user;
	
	// Validators
	// Nur Buchstaben und Leerschläge
	QRegExp charExp ("[\\-\\w\\s]+");
	// Nur 5 kleine Buchstaben und 1 Zahl
	QRegExp userExp ("[a-z][a-z][a-z][a-z][a-z][0-9]");
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
	ui.usernameLineEdit->setValidator(new QRegExpValidator (userExp, this));
	ui.usernameLineEdit->setMaxLength(6);
	ui.nameLineEdit->setValidator (new QRegExpValidator (charExp, this));
	ui.nameLineEdit->setMaxLength (50);
	ui.emailLineEdit->setValidator (new QRegExpValidator (emailExp, this));
	ui.emailLineEdit->setMaxLength (50);
		
	// Usertypen ComboBox erstellen
	QStringList list;
	QString sql="SELECT name FROM usertype WHERE id>" + QString::number(user->usertype);
	qDebug() << QString::number(user->usertype);
	QSqlQuery query(sql);
	query.exec();
	for(int i=0;i<query.numRowsAffected();++i){
		query.next();
		list.append(query.value(0).toString());
	}
	ui.typComboBox->addItems(list);
	ui.typComboBox->setCurrentIndex(ui.typComboBox->findText("manager"));
	// Offset für ComboBox setzen
	if(user->getUsertype()==user->administrator)
			usertype_offset=1;
	else if(user->getUsertype()==user->manager)
			usertype_offset=2;
	// Baum aufbauen
	ui.streckenTreeWidget->setColumnCount(4);
	ui.streckenTreeWidget->setHeaderLabels(QStringList() << tr("Rennen") << tr("Startdatum")
			<< tr("Enddatum") << tr("Streckennummer"));
    ui.streckenTreeWidget->header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui.streckenTreeWidget->header()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui.streckenTreeWidget->header()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui.streckenTreeWidget->header()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
	
	// ermögliche mehrfachauswahl
	ui.streckenTreeWidget->setSelectionMode(QAbstractItemView::MultiSelection);
	
	sql = "SELECT min(Jahr) FROM strecken";
	query.exec(sql);
	query.next();
	int min_jahr = query.value(0).toInt();
	sql = "SELECT max(Jahr) FROM strecken";
	query.prepare(sql);
	query.exec();
	query.next();
	int max_jahr = query.value(0).toInt();
	
	QTreeWidgetItem* act_year = NULL; // Pointer auf aktuelles Jahr
	for(int jahr=min_jahr; jahr<=max_jahr; ++jahr){
		query.exec("SELECT count(StreckenKey) FROM strecken WHERE Jahr='" + QString::number(jahr) + "'");
		query.next();
		if(query.value(0).toBool()){
			QTreeWidgetItem *root;
			root= new QTreeWidgetItem(ui.streckenTreeWidget->invisibleRootItem());
			root->setText(0, QString::number(jahr));
			if(QString::number(jahr)==QDate::currentDate().toString("yyyy")){
				// Pointer auf WidgetItem für aktuelles Jahr
				act_year=root;
			}
			QTreeWidgetItem *item;
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
					item->setText(0,query.value(1).toString());
					item->setText(1,query.value(2).toDate().toString("dd.MM.yyyy"));
					item->setText(2,query.value(3).toDate().toString("dd.MM.yyyy"));
					item->setText(3,QString::number(query.value(0).toInt()));
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
					ui.streckenTreeWidget->setCurrentItem(item);
					count++;
				}
				if(count == 0)
					root->setHidden(true);
			}
		}
	}
	// Aktuelles Jahr expandieren
	ui.streckenTreeWidget->collapseAll();
	ui.streckenTreeWidget->expandItem(act_year);
	ui.streckenTreeWidget->clearSelection ();
}
/*!
 * \brief Destruktor
 */
NeuerUserDialog::~NeuerUserDialog()
{

}

/*!
 * \brief Slot für OK-Button
 */
void NeuerUserDialog::on_okButton_released(){
	char md5_password_char [17];
	// Validieren der Einträge
	if(!validation())
		return;
	// Benutzername testen
	QSqlQuery query;
	query.exec("SELECT username FROM user WHERE username='" + ui.usernameLineEdit->text() + "'");
	if(query.numRowsAffected()!=0){
		// Benutzername bereits vergeben
		QMessageBox::critical(this, QObject::tr("Benutzername"),QObject::tr("Dieser Benutzername ist bereits vorhanden! Erhöhen Sie die Nummer am Ende des Namens."));
		return;
	}
	// Passwörter vergleichen
	if(ui.pwdLineEdit->text().compare(ui.pwdwLineEdit->text())!=0){
		QMessageBox::critical(this, QObject::tr("Fehler"),QObject::tr("Geben Sie zweimal dasselbe Passwort ein!"));
		// zurück zum Eingabedialog
		return;		
	}
	// Abfrage des Adminpasswortes
	QString pwd = QInputDialog::getText(this, tr("Identifizierung als Administrator"),
	                                          tr("Passwort des angemeldeten Administrators:"), 
	                                          QLineEdit::Password);
	// Passwortabfrage zur Identifikation - MD5-Hash
	if(!pwd.isEmpty()){
        md5_buffer(pwd.toLatin1().data(),pwd.length(),md5_password_char);
		pwd = QByteArray::fromRawData(md5_password_char,16).toHex(); 
		if(pUser->password.compare(pwd)!=0){
			// Zurück zum Eingabe Dialog
			QMessageBox::critical(this, QObject::tr("Passwortabfrage"),QObject::tr("Das Passwort war nicht Korrekt!"));
			return;
		}
	}else{
		QMessageBox::critical(this, QObject::tr("Fehler"),QObject::tr("Sie haben kein Passwort eingegeben!"));
		return;
	}
	
	// Erstellen des Strings für die Berechtigungen
	QList<QTreeWidgetItem*> list = ui.streckenTreeWidget->selectedItems();
	QString rights;
	for(int i=0;i<list.count();++i){
		rights += list.at(i)->data(3,Qt::DisplayRole).toString() + ";";
	}
	rights.chop(1); // letzter ';' wegschneiden
	qDebug() << rights;
	
	// MD5-hash vom Passwort des Users erstellen
	QString userpwd = ui.pwdLineEdit->text();
    md5_buffer(userpwd.toLatin1().data(),userpwd.length(),md5_password_char);
	userpwd = QByteArray::fromRawData(md5_password_char,16).toHex(); 
	
	// Eintragen der neuen Daten
	QString sql = "INSERT INTO user ("
			"UserKey, username, name, email, password, usertype, Rennen "
			")VALUES( NULL, ";
	sql += "'" + ui.usernameLineEdit->text() + "', ";
	sql += "'" + ui.nameLineEdit->text() + "', ";
	sql += "'" + ui.emailLineEdit->text() + "', ";
	sql += "'" + userpwd + "', ";
	sql += "'" + QString::number(ui.typComboBox->currentIndex()+usertype_offset+1) + "', ";
	sql += "'" + rights + "')";
	qDebug() << sql;
	query.exec("LOCK TABLES user WRITE");
	query.exec(sql);
	query.exec("UNLOCK TABLES");
	qDebug() << query.lastError();
	this->close();	
}

/*!
 * \brief Slot für Abbrechen-Button
 */
void NeuerUserDialog::on_canButton_released(){
	// Fenster schliessen
	this->close();
}

/*!
 * \brief Validierung der Einträge
 */
bool NeuerUserDialog::validation(){
	bool valid = true;
	QString error = "Die folgenden Felder benötigen noch einen Inhalt:\n";
	if(ui.usernameLineEdit->text()==""){
		error += "Benutzername, ";
		valid = false;
	}
	if(ui.nameLineEdit->text()==""){
		error += "Name, ";
		valid = false;
	}
	if(ui.pwdLineEdit->text()==""){
		error += "Passwort, ";
		valid = false;
	}
	if(ui.pwdwLineEdit->text()==""){
		error += "Passwort wiederholen, ";
		valid = false;
	}
	if(ui.emailLineEdit->text()==""){
		error += "E-Mail, ";
		valid = false;
	}
	// entfernt 2 Zeichen am Ende des Strings
	error.chop(2);
	if(!valid)
		QMessageBox::critical(0,QObject::tr("Fehlende Einträge"),error);
	return valid;
}


