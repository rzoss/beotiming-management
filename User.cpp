 /**
 *******************************************************************************
 * \file    User.cpp
 *******************************************************************************
 * \brief    Diese Klasse symbolisiert einen Benutzer und stellt Funktionen bereit.
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
#include "User.h"
#include <QtGui>
#include <QSqlDatabase>
#include <QtSql>
#include <QtDebug>

/*!
 * \brief Konstruktor
 */
User::User()
{	
	logonSuccess=false;
}
/*!
 * \brief Destruktor
 */
User::~User()
{
}

/*!
 * \brief Initialisierung des Benutzers. Diese Methode wirft eine Exception, 
 * 		  im Falle eines falschen Benutzernames oder Passworts.
 * \param username Benutzername des Benutzers
 * \param password Passwort des Benutzers
 */
void User::Init(QString username, QString password) throw (QString)
 {
	this->username=username;
	QSqlQuery query;
	// Informationen zum Benutzer aus der Datenbank abrufen
	QString
			sql = "SELECT name, email, password, usertype, Rennen FROM user  WHERE user.username='"
					+ username + "'";
	qDebug() << sql;
	query.exec(sql);
	if (query.next()) {
		name=query.value(0).toString();
		email=query.value(1).toString();
		this->password=query.value(2).toString();
		usertype=query.value(3).toInt();
		rennen=query.value(4).toString();
	} else {
		// Werfen der Exception, falls der Benutzername nicht bekannt ist. 
		throw (QString)"Unbekannter Benutzername";
	}
	qDebug() << query.lastError();

	qDebug() << name << " "<< email << " "<< this->password<< " "<< usertype
			<< " "<< rennen;
	// Passwort vergleichen 
	if (password!=this->password) {
		throw (QString)"Falsches Passwort";
	}
	// Login war erfolgreich
	logonSuccess=true;
}
/*!
 * \brief Initialisieren über den Benutzernamen
 */
void User::Init(QString username)
 {
	this->username=username;
	QSqlQuery query;
	QString
			sql = "SELECT name, email, password, usertype, Rennen FROM user  WHERE user.username='"
					+ username + "'";
	qDebug() << sql;
	query.exec(sql);
	if (query.next()) {
		name=query.value(0).toString();
		email=query.value(1).toString();
		password=query.value(2).toString();
		usertype=query.value(3).toInt();
		rennen=query.value(4).toString();
	}
	qDebug() << query.lastError();
}
/*!
 * \brief LogonSuccess überprüfen
 */
bool User::getLogonSuccess(){
	return logonSuccess;
}
/*!
 * \brief Prüfen, ob der Benutzer die Berechtigung für ein Rennen hat.
 * \param race zu überprüfendes Rennen 
 */
bool User::getRaceAuthority(int race){
	bool authority = false;
	QStringList tokens = rennen.split(';');
	for(int i=0;i<tokens.size();++i){
		authority = authority || (tokens.at(i).toInt()==race);
	}
	// Berechtigung für alle Rennen
	if(rennen=="0")
		return true;
	return authority;
}
/*!
 * \brief Gibt den Usertype zurück
 * \return Typ des Benutzers (int) 
 */
int User::getUsertype(){
	return usertype;
}
