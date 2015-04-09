 /**
 *******************************************************************************
 * \file    Database.h
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

#ifndef DATABASE_H_
#define DATABASE_H_

#include <QtSql>
/*!
 *  \brief Diese Klasse symbolisiert die Datenbank. Sie erstellt die Verbindung und 
 * 			 stellt verschiedene Servicefunktionen bereit.
 * 
 */
class Database
{

public:
	
	Database();
	Database(QString host, QString dbname, QString user, QString password);
	virtual ~Database();
	void TestWrite();
	void TestRead();
	QSqlDatabase* getDb(){return &db;};
	bool getDbStatus(){return db.isOpen();};
protected:
	QSqlDatabase db;


};
#endif /*DATABASE_H_*/
