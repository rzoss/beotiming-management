 /**
 *******************************************************************************
 * \file    dbThread.h
 *******************************************************************************
 * \brief    Dieser Thread ueberprueft alle 5 Sekunden die Verbindung zur Datenbank.
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

#ifndef DBTHREAD_H_
#define DBTHREAD_H_

#include "database.h"

#define DB_REFRESH_RATE_ms	5000

/*!
 * \brief Dieser Thread ueberprueft alle 5 Sekunden die Verbindung zur Datenbank.
 * 
 */
class DB_Thread : public QThread
{
	Q_OBJECT

	
public:
	DB_Thread();
	~DB_Thread();
	typedef enum __state{running, stopp, pause, restart}STATE;
	void stop();
	void setState(STATE state);
	int getState();
	
protected:
	void run();
private: 
	volatile bool stopped;
	volatile STATE state;
	Database * pMySQL;
signals:
	void checkDB();
};

#endif /*DBTHREAD_H_*/
