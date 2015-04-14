/**
 *******************************************************************************
 * \file    RFID_CR500.cpp
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


#include <windows.h>
#include "../beo_timing.h"
#include "MasterRD.h"
#include <QtGui>
#include <QtSql>
#include <QMessageBox>
#include <QLibrary>
#include <QtTest/QtTest>
#include "RFID_CR500.h"


/*!
 * \brief Konstruktor
 */
RFID_CR500::RFID_CR500(struct TAG_SETTINGS * tag_settings)
{
	settings=tag_settings;
	init_RFID();
    m_bConnected=false;
    m_icdev = 0;
	// auf allen 8 COM-Port versuchen zu Verbinden
    while(!m_bConnected){
		int state = 1;
        int i = 1;
        while(state != 0 && i<8)
        {
            rf_init_com = (fp_rf_init_com) MasterRD->resolve("rf_init_com");
            qDebug() << "rf_init_com before " + QString::number(i) + " address " + QString::number((int)rf_init_com);
            state = rf_init_com(i,19200);
            qDebug() << "rf_init_com after: " + QString::number(state);
			i++;
		}
        if(state != LIB_SUCCESS)
        {
			rf_ClosePort();
			qDebug() << "Nicht im Bereich von COM1...8!" << endl;
			QMessageBox msgBox;
			QPushButton *wiederholenButton = msgBox.addButton(QObject::tr("Wiederholen"), QMessageBox::ActionRole);
			QPushButton *abbrechenButton = msgBox.addButton(QObject::tr("Abbrechen"), QMessageBox::ActionRole);
			msgBox.setDefaultButton(wiederholenButton);
			msgBox.setEscapeButton(wiederholenButton);
			msgBox.setText(QObject::tr("Die Verbindung zum RFID-Leser konte nicht hergestellt werden.\n"
										"Zur Fehlerbehebung gehen Sie wie folgt vor:\n"
										"1. Ziehen Sie den Leser aus und stecken Sie ihn wieder ein.\n"
										"2. Stellen Sie sicher, dass der COM-Port im Bereich von 1-8 liegt.\n"
										"3. Stellen Sie sicher, dass die Treiber korrekt installiert sind.\n"));
			msgBox.setWindowTitle(QObject::tr("Verbindungsfehler (RFID-Leser)"));
			msgBox.setIcon(QMessageBox::Warning);
			msgBox.exec();
            if (msgBox.clickedButton()==abbrechenButton)
            {
				break;
			}
        }
        else
        {
            qDebug() << "connected";
            m_bConnected=true;
		}
	}
    qDebug() << "get device number";
	// Devicenummer abrufen
    rf_get_device_number(&m_icdev);
    qDebug() << "Nummer des Lesers: " + QString::number(m_icdev);
    // Piepsen mit dem Leser
    rf_beep(m_icdev,10);
    // Licht auf Grün
    rf_light(m_icdev,GREEN_LED);
    // Statusleiste aktualisieren
    BEO_Timing::updateRFID("CR500");
    BEO_Timing::updateMessage("RFID-Leser verbunden");
    qDebug() << "end 4";
}
/*!
 * \brief Destruktor
 */
RFID_CR500::~RFID_CR500()
{
	rf_ClosePort();
}
/*!
 * \brief Initialisieren des RFID-Lesers
 */
void RFID_CR500::init_RFID(){
    MasterRD = new QLibrary();
    MasterRD->setFileName("MasterRD");
    MasterRD->setLoadHints(QLibrary::ResolveAllSymbolsHint | QLibrary::ExportExternalSymbolsHint);
    MasterRD->load();
    lib_ver = (fp_lib_ver) MasterRD->resolve("lib_ver");
    rf_init_com = (fp_rf_init_com) MasterRD->resolve("rf_init_com");
    rf_ClosePort = (fp_rf_ClosePort) MasterRD->resolve("rf_ClosePort");
    rf_get_model = (fp_rf_get_model) MasterRD->resolve("rf_get_model");
    rf_get_device_number = (fp_rf_get_device_number) MasterRD->resolve("rf_get_device_number");
    rf_light = (fp_rf_light) MasterRD->resolve("rf_light");
    rf_beep = (fp_rf_beep) MasterRD->resolve("rf_beep");
    rf_request = (fp_rf_request) MasterRD->resolve("rf_request");
    rf_ul_select = (fp_rf_ul_select) MasterRD->resolve("rf_ul_select");
    rf_M1_read = (fp_rf_M1_read) MasterRD->resolve("rf_M1_read");
    rf_ul_write = (fp_rf_ul_write) MasterRD->resolve("rf_ul_write");
    rf_anticoll = (fp_rf_anticoll) MasterRD->resolve("rf_anticoll");

    if(NULL != lib_ver              ||
       NULL != rf_init_com          ||
       NULL != rf_ClosePort         ||
       NULL != rf_get_model         ||
       NULL != rf_get_device_number ||
       NULL != rf_light             ||
       NULL != rf_beep              ||
       NULL != rf_request           ||
       NULL != rf_ul_select         ||
       NULL != rf_M1_read           ||
       NULL != rf_ul_write          ||
       NULL != rf_anticoll)
    {
        unsigned int ver = 0;
        unsigned int state = 0;
        lib_ver(&ver);

        lib_ver(&ver);
        lib_ver(&ver);
        lib_ver(&ver);
        lib_ver(&ver);
        lib_ver(&ver);
        lib_ver(&ver);
        lib_ver(&ver);
        lib_ver(&ver);
        lib_ver(&ver);
        lib_ver(&ver);
        qDebug() << "1";
        state = rf_init_com(1,19200);
        qDebug() << "2";
        state = rf_init_com(2,19200);
        qDebug() << "3";
        state = rf_init_com(3,19200);
        qDebug() << "4";
        state = rf_init_com(4,19200);
        qDebug() << "5";
        state = rf_init_com(5,19200);
        qDebug() << "6";
        state = rf_init_com(6,19200);
        qDebug() << "7";
        state = rf_init_com(7,19200);
        qDebug() << "8";
        state = rf_init_com(8,19200);

        qDebug() << "Load MasterRD.dll with QLibrary successfull. Version: " << QString::number(ver);
    }
    else
    {
        qDebug() << "Load MasterRD.dll with QLibrary failed !";
    }
}

/*!
 * \brief Karte im Feld suchen
 */
bool RFID_CR500::findCard(){
	unsigned char mode = 0x52;
	int status;
	unsigned short TagType;
	unsigned char bcnt = 0x04;//mifare card use 0x04
	unsigned char Snr[7];
	unsigned char len;

    if(!m_bConnected) // keine Verbindung
		return false;

    status = rf_request(m_icdev,mode,&TagType);//search all card
	if(status){//error
        rf_light(m_icdev,GREEN_LED);
		return false;
	}
    status = rf_anticoll(m_icdev,bcnt,Snr,&len);//return serial number of card
	if(status || len != 4)  //error
		return false;


    status = rf_ul_select(m_icdev,Snr,&len);//lock ISO14443-3 TYPE_A
	if(status) //error
		return false;
    rf_light(m_icdev,NO_LED);
    rf_light(m_icdev,YELLOW_LED);
	oldSerial = serial;
	serial = QByteArray::fromRawData((const char*)Snr,len).toHex();
	BEO_Timing::updateMessage("RFID-Karte gefunden (" + serial + ")");
	qDebug() << serial;
	qDebug() << oldSerial.compare(serial);
	if(oldSerial.compare(serial)==0){
		// Gleiche Karte wie zuvor
		return true;
	}
	return true;
}

/*!
 * \brief Lesen der gefundenen Karte
 */
bool RFID_CR500::readData() {
	int state = 1;
	unsigned char pData[64];
	unsigned char cLen;

    if (!m_bConnected) // keine Verbindung
		return false;

	if(oldSerial.compare(serial)==0){
		// Gleiche Karte wie zuvor
		return false;
	}
	// Lesen der Statusbits
    state = rf_M1_read(m_icdev, RFID_ADR_STATUS, pData, &cLen);
	if (state || cLen != 16) {
		QMessageBox::critical(
				0,
				QObject::tr("Lesefehler"),
				QObject::tr("Die Daten auf der Karte konnten nicht gelesen werden,\n"
							"die Karte ist eventuell defekt!"));
		return false;
	}
	qDebug() << "tag_init: " << settings->tag_reset;
	if(settings->tag_reset == Res_persoenlich){
		// In diesem Fall soll die Karte zurückgesetzt werden
		// hier muss das Statusbyte gelöscht werden!
		memset(pData,0,16); // 16 Datenbytes auf '0x00' setzen
		// Persönlich Flag setzen
		*pData |= TAG_STATUS_REGISTERED;
        state = rf_ul_write(m_icdev,RFID_ADR_STATUS,pData); // Page 4 mit '0' + Personal überschreiben
		*pData &= ~TAG_STATUS_REGISTERED;
		for(int i=1; i<9;i++){
            state = rf_ul_write(m_icdev,RFID_ADR_STATUS+i,pData); // Page 5-11 mit '0' überschreiben
		}
		BEO_Timing::updateMessage("Page 4 - 11 der Karte zurückgesetzt.");

		QMessageBox msgBox;
		msgBox.setText("Page 4 - 11 der Karte \"" + serial + "\" wurde zurückgesetzt. Sie ist als persönlich Markiert!");
		msgBox.setWindowTitle(QObject::tr("Tag zurückgesetzt"));
		msgBox.setIcon(QMessageBox::Information);
		msgBox.exec();
		QTimer::singleShot(2500,&msgBox, SLOT(close()));
		return false;
	}else if(settings->tag_reset == Res_unpersoenlich){
		// In diesem Fall soll die Karte zurückgesetzt werden
		// hier muss das Statusbyte gelöscht werden!
		memset(pData,0,16); // 16 Datenbytes auf '0x00' setzen
		for(int i=0; i<9;i++){
            state = rf_ul_write(m_icdev,RFID_ADR_STATUS+i,pData); // Page 4-11 mit '0' überschreiben
		}

		BEO_Timing::updateMessage("Page 4 - 11 der Karte zurückgesetzt.");

		QMessageBox msgBox;
		msgBox.setText("Page 4 - 11 der Karte \"" + serial + "\" wurde zurückgesetzt. Sie ist als unpersönlich Markiert!");
		msgBox.setWindowTitle(QObject::tr("Tag zurückgesetzt"));
		msgBox.setIcon(QMessageBox::Information);
		msgBox.exec();
		QTimer::singleShot(2500,&msgBox, SLOT(close()));
		return false;

	}


	// Statusflags überprüfen
    if(pData[0] == ((TAG_STATUS_STRECKENVALID | TAG_STATUS_STARTVALID | TAG_STATUS_ENDVALID) &
					~TAG_STATUS_MANUALCLEARED &
					~TAG_STATUS_REGISTERED)){
		// --> Auswerten
    }else if(pData[0] == ((TAG_STATUS_STRECKENVALID | TAG_STATUS_STARTVALID | TAG_STATUS_ENDVALID | TAG_STATUS_MANUALCLEARED) &
					~TAG_STATUS_REGISTERED)){
		// --> Zeit manuell gelöscht
		QMessageBox::critical(
						0,
						QObject::tr("Zeit wurde gelöscht"),
						QObject::tr("Der Teilnehmer hat die Zeiten auf der Karte manuell gelöscht. ") +
						QObject::tr("Die Karte kann ohne weitere Massnahmen wieder verwendet werden."));
		return false;
	}else if(pData[0] & TAG_STATUS_REGISTERED && pData[1] == 0x00){
		// --> Persönliche Karte
		QSqlQuery query;
		query.exec("SELECT name, vorname, adresse, PLZ, ort, email, telefon, mobile "
				   "FROM teilnehmer WHERE SNR_RFID='" + serial + "'");
		QString kontakt;
		if(query.next()){
			kontakt = "Der Inhaber ist: \n" + query.value(0).toString() + " " +
			query.value(1).toString() + ", " + query.value(2).toString() +
			", " + query.value(3).toString() + " " + query.value(4).toString() +
			", " + query.value(5).toString() + ", " + query.value(6).toString() +
			", " + query.value(7).toString();
		}else{
			kontakt = "Kein Teilnehmer in der Datenbank. \nRetournieren Sie diese Karte an den Administrator.";
		}

		QMessageBox::critical(
				0,
				QObject::tr("Persönliche Karte"),
				QObject::tr("Diese Karte ist als Persönlich registriert. ") + kontakt);
		return false;


	// TODO: Reagieren auf Auswahl im Menue "Verbindung"

	}else if(pData[0] == 0xFF && pData[1] == 0xFF && settings->tag_init == Neu_persoenlich){
		// In diesem Fall wurde eine neue Karte vorgehalten
		// hier müssen die Statusbyte gelöscht werden!
		memset(pData,0,4); // 4 Datenbytes auf '0x00' setzen
		// Persönlich Flag setzen, da die Karte als erstes Persönlich ist, da sie noch keine Etikette trägt.
		*pData |= TAG_STATUS_REGISTERED;
        state = rf_ul_write(m_icdev,RFID_ADR_STATUS,pData); // Page 4 mit '0' überschreiben
		BEO_Timing::updateMessage("Page 4 einer neuen Karte gelöscht.");

		QMessageBox msgBox;
		msgBox.setText("Page 4 der Karte \"" + serial + "\" gelöscht. Diese Karte war neu und wurde noch nie verwendet. Sie ist jetzt als persönlich Markiert!");
		msgBox.setWindowTitle(QObject::tr("Page 4 gelöscht"));
		msgBox.setIcon(QMessageBox::Information);
		msgBox.exec();
		QTimer::singleShot(2500,&msgBox, SLOT(close()));


		return false;

	}else if(pData[0] == 0xFF && pData[1] == 0xFF && settings->tag_init == Neu_unpersoenlich){
			// In diesem Fall wurde eine neue Karte vorgehalten
			// hier müssen die Statusbyte gelöscht werden!
			memset(pData,0,4); // 4 Datenbytes auf '0x00' setzen
			// Persönlich Flag NICHT setzen, da die Karte eine Etikette trägt.
            state = rf_ul_write(m_icdev,RFID_ADR_STATUS,pData); // Page 4 mit '0' überschreiben
			BEO_Timing::updateMessage("Page 4 einer neuen Karte gelöscht.");

			QMessageBox msgBox;
			msgBox.setText("Page 4 der Karte \"" + serial + "\" gelöscht. Diese Karte war neu und wurde noch nie verwendet. Sie ist jetzt als unpersönlich Markiert!");
			msgBox.setWindowTitle(QObject::tr("Page 4 gelöscht"));
			msgBox.setIcon(QMessageBox::Information);
			msgBox.exec();
			QTimer::singleShot(2500,&msgBox, SLOT(close()));
			return false;

	}else{
		QMessageBox::critical(
				0,
				QObject::tr("Lesefehler"),
				QObject::tr("Die Daten auf der Karte konnten nicht gelesen werden,\n"
					"oder sind nicht Gültig! Wahrscheinlich wurde diese Karte bereits ausgewertet."));
		return false;
	}

	// Weitere Daten aus der Karte lesen, falls die Statusbits dies zulassen
    state = rf_M1_read(m_icdev, RFID_ADR_ENDTIME, pData+16, &cLen);
	if (state || cLen != 16) {
		QMessageBox::critical(
				0,
				QObject::tr("Lesefehler"),
				QObject::tr("Die Daten auf der Karte konnten nicht gelesen werden,\n"
					"die Karte ist eventuell defekt!"));
	    return false;
	} else {
		// Gelesene Binärdaten in die Strukturen kopieren, um zu interpretieren
		memcpy(&strecke,pData+4,2);
		memcpy(&startdate, pData+8, 7);
		memcpy(&enddate, pData+16, 7);
		memcpy(&racetime, pData+24, 4);
	}
	return true;
}
/*!
 * \brief Löschen der Flags, um die Karte als ausgewertet kennzuzeichnen
 */
bool RFID_CR500::clearValidFlag(){
	int state = 1;
	unsigned char pData[64];
	unsigned char cLen;

    if (!m_bConnected) // keine Verbindung
		return false;

	if(!findCard()){// Keine Karte gefunden
		QMessageBox::critical(0,QObject::tr("Keine RFID-Karte"),
				QObject::tr("Es liegt keine Karte im Feld des Lesers. Legen Sie die Karte mit der Seriennummer \"") + oldSerial + "\" auf!");
		return false;
	}
	if(oldSerial.compare(serial)!=0){ // Falsche Karte
		QMessageBox::critical(0,QObject::tr("Falsche RFID-Karte"),
				QObject::tr("Es liegt nicht die Karte mit der Seriennummer \"") + oldSerial + "\" auf!");
		return false;
	}
	// Andere Statusbits lesen
    state = rf_M1_read(m_icdev, RFID_ADR_STATUS, pData, &cLen);
	if (state || cLen != 16) {
		return false;
	}
	// Gewählte löschen und alle neu schreiben
	*pData &= ~(TAG_STATUS_STRECKENVALID | TAG_STATUS_STARTVALID | TAG_STATUS_ENDVALID); // erstes Byte löschen (Valid Data Flag)
    state = rf_ul_write(m_icdev,RFID_ADR_STATUS,pData);
    rf_light(m_icdev,GREEN_LED);
	return true;
}
/*!
 * \brief Stellt die LED des Lesers auf Grün
 */
void RFID_CR500::greenLED(){
    rf_light(m_icdev,GREEN_LED);
}

/*!
 * \brief Funktion zum Testen der Verbindung zum Leser
 */
bool RFID_CR500::isConnected(){
	unsigned char version[100];
	unsigned char len;
	char error;
    error = rf_get_model(m_icdev,version, &len);
	if(error)
        m_bConnected = false;
	else
        m_bConnected = true;
    return m_bConnected;
}


