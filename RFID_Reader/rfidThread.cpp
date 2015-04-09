/**
 *******************************************************************************
 * \file    rfidThread.cpp
 ********************************************************************************
 * \brief    Erstellt einen Thread, welcher alle 0.5 Sekunden prüft ob eine Karte im 
 * 			 Feld des Lesers erscheint. 
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

#include "rfidThread.h"
#include "rfidinputdialog.h"
#include "RFID_CR500.h"
#include <QtGui>

/*!
 * \brief Konstruktor
 * \param pRfid Pointer auf den RFID-Leser
 */
RFID_Thread::RFID_Thread(RFID_CR500* pRfid)
{
	stopped = false;
	this->pRfid = pRfid;
}
/*!
 * \brief Destruktor
 */
RFID_Thread::~RFID_Thread(){
	
}

/*!
 * \brief Setter für den State
 */
void RFID_Thread::setState(STATE state){
	this->state=state;
}
/*!
 * \brief Stoppen des Threads
 */
void RFID_Thread::stop(){
	stopped=true;
}
/*!
 * \brief Setzen des Pointers auf den Leser
 */
void RFID_Thread::setRFID(RFID_CR500* pRfid){
	this->pRfid=pRfid;
}
/*!
 * \brief run-Funktion des Threads
 */
void RFID_Thread::run(){
	while(!stopped){
		switch(state){
				case running: 
					emit checkRFID();
					break;
				case stopp:
					state=pause;
					break;
				case pause:
					break;
				case restart:
					state=running;
					break;
		}
		msleep(RFID_REFRESH_RATE_ms);
	}
	stopped=false;
}


