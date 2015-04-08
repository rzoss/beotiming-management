 /**
 *******************************************************************************
 * \file    dbThread.cpp
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
#include "database.h"
#include "dbThread.h"
#include "beo_timing.h"

/*!
 * \brief Konstruktor
 */
DB_Thread::DB_Thread()
{
	stopped = false;
	state = running;

}
/*!
 * \brief Destruktor
 */
DB_Thread::~DB_Thread(){

}
/*!
 * \brief Stoppen des Threads
 */
void DB_Thread::stop(){
	stopped=true;
}
/*!
 * \brief setzen des States der Zustandsmaschine
 */
void DB_Thread::setState(STATE state){
	this->state=state;
}
/*!
 * \brief lesen des States der Zustandsmaschine
 */
int DB_Thread::getState(){
	return state;
}

/*!
 * \brief Überschreiben der vererbten Funktion "run"
 */
void DB_Thread::run(){
	while(!stopped){
		switch(state){
		case running:
			emit checkDB();
			break;
		case stopp:
			emit checkDB();
			state=pause;
			break;
		case pause: 
			break;
		case restart:
			emit checkDB();
			state=running;
			break;
		}
		msleep(DB_REFRESH_RATE_ms);
	}
	stopped=false;
}


