/**
 *******************************************************************************
 * \file    rfidThread.h
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

#ifndef RFIDTHREAD_H_
#define RFIDTHREAD_H_

#include "RFID_CR500.h"
#include <QtGui>

#define RFID_REFRESH_RATE_ms	500

/*!
 * \brief Erstellt einen Thread, welcher alle 0.5 Sekunden prüft ob eine Karte im 
 * 			 Feld des Lesers erscheint. 
 * 
 */
class RFID_Thread : public QThread
{
	Q_OBJECT

	
public:
	RFID_Thread(RFID_CR500* pRfid);
	~RFID_Thread();
	void stop();
	typedef enum _state{running, stopp, pause, restart} STATE;
	void setState(STATE state);
	void setRFID(RFID_CR500* pRfid);
protected:
	void run();
private: 
	volatile bool stopped;
	volatile STATE state;
	RFID_CR500* pRfid;
signals:
	void checkRFID();
};

#endif /*RFIDTHREAD_H_*/
