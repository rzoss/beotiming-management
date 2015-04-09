 /**
 *******************************************************************************
 * \file    Database.cpp
 *******************************************************************************
 * \brief    Diese Klasse symbolisiert die Datenbank. Sie erstellt die Verbindung und 
 * 			 stellt verschiedene Servicefunktionen bereit.
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
#include <QSqlDatabase>
#include <QtSql>
#include <QMessageBox>
#include "Database.h"

/*!
 * \brief Konstruktor für standard DB
 */
Database::Database()
{
	qDebug() << "MySQL-Test";
	
	db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("ricozo6.mysql.db.hostpoint.ch"); // "www.rrc-thun.ch"
    db.setDatabaseName("ricozo6_beotimingtime");
    db.setUserName("ricozo6_beotim");
    db.setPassword("KGloQyRd");
	// Versuche eine SSL-Verschlüsselung zu initialisieren
	db.setConnectOptions("CLIENT_SSL");
	// Daten Komprimiert senden
	db.setConnectOptions("CLIENT_COMPRESS");
	if(!db.open()){
		QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
	}
}
/*!
 * \brief Konstruktor mit Paramtern für beliebige DB
 * \param host Hostname der Datenbank
 * \param dbname Name der Datenbank
 * \param user Benutzer für die Datenbank
 * \param password Passwort für den Benutzer
 */
Database::Database(QString host, QString dbname, QString user, QString password)
{
	qDebug() << "MySQL-Test";
	
	db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName(host);
	db.setDatabaseName(dbname);
	db.setUserName(user);
	db.setPassword(password);
	// Versuche eine SSL-Verschlüsselung zu initialisieren
	db.setConnectOptions("CLIENT_SSL");
	// Daten Komprimiert senden
	db.setConnectOptions("CLIENT_COMPRESS");
	if(!db.open()){
		QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
	}
	
}

/*!
 * \brief Destruktor
 */
Database::~Database()
{
	db.close();
	db.removeDatabase("QMYSQL");
}


//void Database::TestWrite(){
//	QSqlQuery query;
//	query.prepare("INSERT INTO person (id, forename, surname) "
//	                   "VALUES (:id, :forename, :surname)");
//	query.bindValue(":id", 1002);
//	query.bindValue(":forename", "Bart");
//	query.bindValue(":surname", "Simpson");
//	
//	if (!query.exec())
//	   qDebug() << query.lastError();
//}
//
//void Database::TestRead(){
//	if(db.isOpen()){
//
//	}
//
//}





