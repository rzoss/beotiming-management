/**
 *******************************************************************************
 * \file    RFID_CR500.h
 *******************************************************************************
 * \brief    Enthält alle Eigenschaften des RFID-Lesers CR500-USB.
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

#ifndef RFID_CR500_H_
#define RFID_CR500_H_

#include <windows.h>
#include <QtGui>
#include "rfidinputdialog.h"
#include "../beo_timing.h"

/**\brief Pagenummer des Statusbits in der RFID-Karte*/
#define RFID_ADR_STATUS			4
/**\brief Pagenummer der Streckennummer in der RFID-Karte*/
#define RFID_ADR_STRECKE		5
/**\brief Pagenummer der Startzeit in der RFID-Karte*/
#define RFID_ADR_STARTTIME		6
/**\brief Pagenummer der Endzeit in der RFID-Karte*/
#define RFID_ADR_ENDTIME		8
/**\brief Pagenummer der Fahrzeit in der RFID-Karte*/
#define RFID_ADR_RACETIME		10

// Tag-Status Masks
/**\brief Gültige Streckennr. aud der Karte*/
#define TAG_STATUS_STRECKENVALID  (1<<0)
/**\brief Gültige Startzeit auf der Karte*/
#define TAG_STATUS_STARTVALID  (1<<1)
/**\brief Gültige Endzeit auf der Karte*/
#define TAG_STATUS_ENDVALID   (1<<2)
/**\brief Karte ist Manuel gelöscht worden*/
#define TAG_STATUS_MANUALCLEARED (1<<3)
/**\brief Karte ist Persönlich*/
#define TAG_STATUS_REGISTERED  (1<<4)

enum{NO_LED,RED_LED,GREEN_LED,YELLOW_LED};



/**
 * @brief Struktur fuer die Fahrzeit (Groesse 4 Byte)
 */
struct MYTIME{
    unsigned char day;
    unsigned char hour;
    unsigned char minute;
    unsigned char second;
};

/**
 * @brief Struktur fuer die Start- und Endzeit (Groesse 7 Byte)
 */
struct MYDATE{
    short year;
    unsigned char month;
    unsigned char day;
    unsigned char hour;
    unsigned char minute;
    unsigned char second;
};
/*!
 * \brief Enthält alle Eigenschaften des RFID-Lesers CR500-USB.
 *
 */
class RFID_CR500
{

public:
	RFID_CR500(struct TAG_SETTINGS * tag_settings);
	virtual ~RFID_CR500();
	bool findCard();
	bool readData();
	bool clearValidFlag();
	bool setPersonalFlag();
	void greenLED();
	bool isConnected();

	struct TAG_SETTINGS * settings;

private:
	enum tag_action {Nichts, Neu_persoenlich, Neu_unpersoenlich, Res_persoenlich, Res_unpersoenlich};
	void myStrcat (TCHAR * op, int size);
	void myCout (TCHAR * op, int size);
	void init_RFID();
	bool connected;
	unsigned short icdev;
	QString serial;
	QString oldSerial;
	qint16 strecke;
	struct MYDATE startdate, enddate;
	struct MYTIME racetime;
	friend class RFIDInputDialog;
};

#endif /*RFID_CR500_H_*/
