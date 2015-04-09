 /**
 *******************************************************************************
 * \file    passwordchangedialog.cpp
 *******************************************************************************
 * \brief    Dieser Dialog dient zum aendern des Passworts des angemeldeten Benutzers.
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
#include "passwordchangedialog.h"
#include "User.h"
#include <QtSql>
#include <QtGui>
#include "md5/md5.h"
#include <math.h>
#include <QMessageBox>

/*!
 * \brief Konstruktor
 * \param pUser Pointer auf den angemeldeten Benutzer
 * \param parent Pointer auf das aufrufende Objekt
 */
PasswordChangeDialog::PasswordChangeDialog(User* pUser, QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	this->pUser=pUser;
	// Keine begrenzung der Eingabe nötig, da der MD5-hash immer 128-bit lang ist.
	
	ui.staerkeProgressBar->setMaximum(20);
	ui.staerkeProgressBar->setMinimum(0); 
}

/*!
 * \brief Destruktor
 */
PasswordChangeDialog::~PasswordChangeDialog()
{

}

/*!
 * \brief Slot für Ok-Button
 */
void PasswordChangeDialog::on_okButton_released(){
	// MD5-Hash aus altem Password erstellen 
	QString oldPassword = ui.oldLineEdit->text();
	char md5_password_char [17];
    md5_buffer(oldPassword.toLatin1().data(),oldPassword.length(),md5_password_char);
	oldPassword = QByteArray::fromRawData(md5_password_char,16).toHex(); 
	// Altes Passwort vergleichen
	if(pUser->password.compare(oldPassword)!=0){
		QMessageBox::critical(this, QObject::tr("Fehler"),QObject::tr("Das alte Passwort ist falsch!"));
		return;
	}
	// Beide neuen Passwörter vergleichen
	if(ui.newLineEdit->text().compare(ui.wiederLineEdit->text())!=0){
		QMessageBox::critical(this, QObject::tr("Fehler"),QObject::tr("Geben Sie zweimal dasselbe Passwort ein!"));
		return;		
	}
	// MD5-Hash aus neuem Passwort erstellen
	QString newPassword = ui.newLineEdit->text();
    md5_buffer(newPassword.toLatin1().data(),newPassword.length(),md5_password_char);
	newPassword = QByteArray::fromRawData(md5_password_char,16).toHex(); 
	// Passwort in der Datenbank akualisieren
	QSqlQuery query;
	QString sql = "UPDATE user SET password = '" + newPassword + 
				  "' WHERE username = '" + pUser->username + "'";
	qDebug() << sql;
	query.exec(sql);
	QMessageBox::information(this, QObject::tr("Passwort geändert"),QObject::tr("Das Passwort wurde erfolgreich geändert!"));
	this->close();
}
/*!
 * \brief Slot für den Abbrechen-Button
 */
void PasswordChangeDialog::on_canButton_released(){
	this->close();
}
/*!
 * \brief Validierung der Einträge
 * \param pwd Neues Passwort
 */
bool PasswordChangeDialog::validation(QString pwd){
	bool valid = true;
	QString error = "Folgende Punkte wurden bei der Wahl des Passworts nicht eingehalten:\n";
	// Midestens 6 Zeichen lang
	if(pwd.length()<=6){
		error += "- Die Länge beträgt mindestens 6 Zeichen\n";
		valid = false;
	}
	return valid;
}

/*!
 * \brief Slot für die Änderungen im Texteingabefeld
 * \param text aktueller Text im Feld
 */
void PasswordChangeDialog::on_newLineEdit_textChanged(const QString& text)
{
   qDebug() << text;   
   int gb=text.count(QRegExp("[A-Z]+"));
   int kb=text.count(QRegExp("[a-z]+"));
   int zahl=text.count(QRegExp("[0-9]+"));
   int fremd=text.count(QRegExp("[^°!§$%&=?`´+*~#,.-_:;]+"));
   // Einfacher Algorithmus, um die Stärke des Passwortes zu definieren
   int value = (int)(log10(pow(26,gb))+log10(pow(26,kb))+log10(pow(10,zahl))+log10(pow(20,fremd)));
   ui.staerkeProgressBar->setValue(value);
   qDebug() << value;
} 

