 /**
 *******************************************************************************
 * \file    logondialog.cpp
 *******************************************************************************
 * \brief    Dieser Dialog ist das Login des Programms. Es dient zur Authentifizierung 
 * des Benutzers.
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

#include "logondialog.h"
#include "beo_timing.h"
#include "Database.h"
#include "User.h"
#include <QtGui>
#include "md5/md5.h"

/*!
 * \brief Konstruktor
 * \param user Pointer auf den angemeldeten Benutzer
 * \param a Pointer auf die Hauptapplikation
 * \param w Pointer auf das Hauptfenster
 * \param parent Pointer auf parent
 */
LogonDialog::LogonDialog(User* user, QApplication *a, BEO_Timing* w, QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	this->user=user;
	this->a=a;
	this->w=w;
	//ui.BenutzernameEdit->setText("zossr1");
	//ui.PasswortLabel_2->setText("******");
}


/*!
 * \brief Destruktor
 */
LogonDialog::~LogonDialog()
{
	
}

/*!
 * \brief Slot für Beenden-Button
 */
void LogonDialog::on_BeendenButton_released() {
	this->close();
}
/*!
 * \brief Slot für Logon-Button
 */
void LogonDialog::on_LogonButton_released() {
	// Textfelder auslesen
	QString username = ui.BenutzernameEdit->text().toLower();
	QString password = ui.PasswortLabel_2->text();
	// MD5-Hash aus Passwort erstellen
	char md5_password_char [17];
	md5_t md5_struct;
	md5_init(&md5_struct);
	md5_buffer(password.toAscii().data(),password.length(),md5_password_char);
	QString md5_password = QByteArray::fromRawData(md5_password_char,16).toHex(); 
	password=md5_password; 
	qDebug() << md5_password;
	// Falls keines der Felder leer ist ...
	if (!username.isEmpty() && !password.isEmpty()) {
		try{
			// Benutzer mit den Werten initialisieren
			user->Init(username,md5_password);
			// Statusleiste aktualisieren
			w->updateUserStatus(username);
			// Fenster schliessen
			this->close();
		}
			// Exception auffangen und bearbeiten
			catch (QString error){
			qDebug() << error;
			// Fehler ausgeben
			QMessageBox::critical(0,QObject::tr("Identifikation Fehlgeschlagen"),error);
			// Passwortfeld leeren
			ui.PasswortLabel_2->setText(""); // Eigabefeld leeren
		}
	}else{
		// Fehler ausgeben
		QMessageBox::critical(0,QObject::tr("Identifikation Fehlgeschlagen"),
								QObject::tr("Geben Sie einen Benutzername und ein Passwort ein!"));
	}
}

