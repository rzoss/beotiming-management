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
#include "RFID_CR500.h"


/*!
 * \brief Konstruktor
 */
RFID_CR500::RFID_CR500(struct TAG_SETTINGS * tag_settings)
{
	settings=tag_settings;
	init_RFID();
	connected=false;
	// auf allen 8 COM-Port versuchen zu Verbinden
	while(!connected){
		int state = 1;
		int i = 1;
		while(state != 0 && i<8){
			state = rf_init_com(i,19200);
			i++;
		}
		if(state != LIB_SUCCESS){
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
			if (msgBox.clickedButton()==abbrechenButton) {
				break;
			}
		}else{
			connected=true;
		}
	}
	// Devicenummer abrufen
	rf_get_device_number(&icdev);
	qDebug() << "Nummer des Lesers: " + icdev;
	// Piepsem mit dem Leser
	rf_beep(icdev,10);
	// Licht auf Grün
	rf_light(icdev,GREEN_LED);
	// Statusleiste aktualisieren
	BEO_Timing::updateRFID("CR500");
	BEO_Timing::updateMessage("RFID-Leser verbunden");
}
/*!
 * \brief Destruktor
 */
RFID_CR500::~RFID_CR500()
{
	rf_ClosePort();
}
/*!
 * \brief Strcat für UTF-8
 */
void RFID_CR500::myStrcat (TCHAR * op, int size) {
	int i;
	for (i=size-1;i>=0;i--) {
		if (op[i]== (TCHAR)'\\')
			break;
	}
	op[i++]=(TCHAR)'\\';
	op[i++]=(TCHAR)'M';
	op[i++]=(TCHAR)'a';
	op[i++]=(TCHAR)'s';
	op[i++]=(TCHAR)'t';
	op[i++]=(TCHAR)'e';
	op[i++]=(TCHAR)'r';
	op[i++]=(TCHAR)'R';
	op[i++]=(TCHAR)'D';
	op[i++]=(TCHAR)'.';
	op[i++]=(TCHAR)'d';
	op[i++]=(TCHAR)'l';
	op[i++]=(TCHAR)'l';
	op[i++]=(TCHAR)'\0';
}
/*!
 * \brief Ausgabe für UTF-8 String
 */
void RFID_CR500::myCout (TCHAR * op, int size){
	char out[1000];
	for(int i=0; i<size;i++){
		out[i]=(char)op[i];
		if(op[i]==0)
			break;
	}
	qDebug() << QString::fromWCharArray(op);
	qDebug() << out << endl;
}
/*!
 * \brief Initialisieren des RFID-Lesers
 */
void RFID_CR500::init_RFID(){
	HINSTANCE m_hInstMaster;
	TCHAR szBuf[1000];
	GetModuleFileName(NULL, (LPTSTR)szBuf, 1000);
	qDebug() << sizeof(szBuf) << endl;

	myStrcat(szBuf, sizeof(szBuf)/sizeof(TCHAR));
	myCout(szBuf, sizeof(szBuf)/sizeof(TCHAR));
	// Laden der "MasterRD.dll" über die Windows-API
	m_hInstMaster = LoadLibrary((LPTSTR)szBuf);
	// Bereitstellen der Adressen für die Funktionen in der DLL
	if(m_hInstMaster){
        /*  System Functions */
		(FARPROC&)lib_ver               = GetProcAddress(m_hInstMaster,("lib_ver"));
		(FARPROC&)rf_init_com           = GetProcAddress(m_hInstMaster,("rf_init_com"));
		(FARPROC&)rf_init_device_number = GetProcAddress(m_hInstMaster,("rf_init_device_number"));
		(FARPROC&)rf_get_device_number  = GetProcAddress(m_hInstMaster,("rf_get_device_number"));
		(FARPROC&)rf_get_model          = GetProcAddress(m_hInstMaster,("rf_get_model"));
		(FARPROC&)rf_beep               = GetProcAddress(m_hInstMaster,("rf_beep"));
		(FARPROC&)rf_init_type          = GetProcAddress(m_hInstMaster,("rf_init_type"));
		(FARPROC&)rf_antenna_sta        = GetProcAddress(m_hInstMaster,("rf_antenna_sta"));
		(FARPROC&)rf_light              = GetProcAddress(m_hInstMaster,("rf_light"));
		(FARPROC&)rf_ClosePort          = GetProcAddress(m_hInstMaster,("rf_ClosePort"));
		(FARPROC&)rf_get_snr            = GetProcAddress(m_hInstMaster,("rf_get_snr"));
		(FARPROC&)rf_init_sam           = GetProcAddress(m_hInstMaster,("rf_init_sam"));
		(FARPROC&)rf_sam_rst            = GetProcAddress(m_hInstMaster,("rf_sam_rst"));
		(FARPROC&)rf_sam_cos            = GetProcAddress(m_hInstMaster,("rf_sam_cos"));
		(FARPROC&)rf_GetErrorMessage    = GetProcAddress(m_hInstMaster,("rf_GetErrorMessage"));
		/* DES Functions */
		(FARPROC&)des_encrypt           = GetProcAddress(m_hInstMaster,("des_encrypt"));
		(FARPROC&)des_decrypt           = GetProcAddress(m_hInstMaster,("des_decrypt"));
		/* ISO14443A FUNCTION -  Mifare UltraLight */
		(FARPROC&)rf_request            = GetProcAddress(m_hInstMaster,("rf_request"));
		(FARPROC&)rf_ul_select          = GetProcAddress(m_hInstMaster,("rf_ul_select"));
		(FARPROC&)rf_M1_read            = GetProcAddress(m_hInstMaster,("rf_M1_read"));
		(FARPROC&)rf_ul_write           = GetProcAddress(m_hInstMaster,("rf_ul_write"));
		(FARPROC&)rf_halt               = GetProcAddress(m_hInstMaster,("rf_halt"));
		/* ISO14443A FUNCTION -  Mifare Std*/
		(FARPROC&)rf_anticoll           = GetProcAddress(m_hInstMaster,("rf_anticoll"));
		(FARPROC&)rf_select             = GetProcAddress(m_hInstMaster,("rf_select"));
		(FARPROC&)rf_download_key       = GetProcAddress(m_hInstMaster,("rf_download_key"));
		(FARPROC&)rf_M1_authentication1 = GetProcAddress(m_hInstMaster,("rf_M1_authentication1"));
		(FARPROC&)rf_M1_authentication2 = GetProcAddress(m_hInstMaster,("rf_M1_authentication2"));
		(FARPROC&)rf_M1_write           = GetProcAddress(m_hInstMaster,("rf_M1_write"));
		(FARPROC&)rf_M1_initval         = GetProcAddress(m_hInstMaster,("rf_M1_initval"));
		(FARPROC&)rf_M1_readval         = GetProcAddress(m_hInstMaster,("rf_M1_readval"));
		(FARPROC&)rf_M1_decrement       = GetProcAddress(m_hInstMaster,("rf_M1_decrement"));
		(FARPROC&)rf_M1_increment       = GetProcAddress(m_hInstMaster,("rf_M1_increment"));
		(FARPROC&)rf_M1_restore         = GetProcAddress(m_hInstMaster,("rf_M1_restore"));
		(FARPROC&)rf_M1_transfer        = GetProcAddress(m_hInstMaster,("rf_M1_transfer"));
		(FARPROC&)rf_typea_rst          = GetProcAddress(m_hInstMaster,("rf_typea_rst"));
		(FARPROC&)rf_cos_command        = GetProcAddress(m_hInstMaster,("rf_cos_command"));
		(FARPROC&)rf_atqb               = GetProcAddress(m_hInstMaster,("rf_atqb"));
		(FARPROC&)rf_attrib             = GetProcAddress(m_hInstMaster,("rf_attrib"));
		(FARPROC&)rf_typeb_cos          = GetProcAddress(m_hInstMaster,("rf_typeb_cos"));
		(FARPROC&)rf_hltb               = GetProcAddress(m_hInstMaster,("rf_hltb"));
		(FARPROC&)rf_at020_check        = GetProcAddress(m_hInstMaster,("rf_at020_check"));
		(FARPROC&)rf_at020_read         = GetProcAddress(m_hInstMaster,("rf_at020_read"));
		(FARPROC&)rf_at020_write        = GetProcAddress(m_hInstMaster,("rf_at020_write"));
		(FARPROC&)rf_at020_lock         = GetProcAddress(m_hInstMaster,("rf_at020_lock"));
		(FARPROC&)rf_at020_count        = GetProcAddress(m_hInstMaster,("rf_at020_count"));
		(FARPROC&)rf_at020_deselect     = GetProcAddress(m_hInstMaster,("rf_at020_deselect"));
		// Testen der Adressen
		if( /* System Functions */
		    NULL == lib_ver               ||
			NULL == rf_init_com           ||
			NULL == rf_init_device_number ||
			NULL == rf_get_device_number  ||
			NULL == rf_get_model		  ||
			NULL == rf_beep				  ||
			NULL == rf_antenna_sta        ||
			NULL == rf_light              ||
			NULL == rf_ClosePort          ||
			NULL == rf_get_snr            ||
			NULL == rf_init_type          ||
			NULL == rf_init_sam           ||
			NULL == rf_sam_rst            ||
			NULL == rf_sam_cos            ||
			NULL == rf_GetErrorMessage	  ||
			/* DES Functions */
			NULL == des_encrypt           ||
			NULL == des_decrypt           ||
			/* ISO14443A FUNCTION -  Mifare UltraLight */
			NULL == rf_request            ||
			NULL == rf_ul_select          ||
			NULL == rf_M1_read            ||
			NULL == rf_ul_write           ||
			NULL == rf_halt               ||
			/* ISO14443A FUNCTION -  Mifare Std */
			NULL == rf_anticoll           ||
			NULL == rf_select             ||
			NULL == rf_download_key       ||
			NULL == rf_M1_authentication1 ||
			NULL == rf_M1_authentication2 ||
			NULL == rf_M1_write           ||
			NULL == rf_M1_initval         ||
			NULL == rf_M1_readval         ||
			NULL == rf_M1_decrement       ||
			NULL == rf_M1_increment       ||
			NULL == rf_M1_restore         ||
			NULL == rf_M1_transfer        ||
			NULL == rf_typea_rst          ||
			NULL == rf_cos_command        ||
			NULL == rf_atqb               ||
			NULL == rf_attrib             ||
			NULL == rf_typeb_cos          ||
			NULL == rf_hltb               ||
			NULL == rf_at020_check        ||
			NULL == rf_at020_read         ||
			NULL == rf_at020_write        ||
			NULL == rf_at020_lock         ||
			NULL == rf_at020_count        ||
			NULL == rf_at020_deselect){
			qDebug() << "Load MasterRD.dll failed !";
		}
	}
	else{
		qDebug() << "Load MasterRD.dll failed !";

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

	if(!connected) // keine Verbindung
		return false;

	status = rf_request(icdev,mode,&TagType);//search all card
	if(status){//error
		rf_light(icdev,GREEN_LED);
		return false;
	}
	status = rf_anticoll(icdev,bcnt,Snr,&len);//return serial number of card
	if(status || len != 4)  //error
		return false;


	status = rf_ul_select(icdev,Snr,&len);//lock ISO14443-3 TYPE_A
	if(status) //error
		return false;
	rf_light(icdev,NO_LED);
	rf_light(icdev,YELLOW_LED);
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

	if (!connected) // keine Verbindung
		return false;

	if(oldSerial.compare(serial)==0){
		// Gleiche Karte wie zuvor
		return false;
	}
	// Lesen der Statusbits
	state = rf_M1_read(icdev, RFID_ADR_STATUS, pData, &cLen);
	if (state || cLen != 16) {
		QMessageBox::critical(
				0,
				QObject::tr("Lesefehler"),
				QObject::tr("Die Daten auf der Karte konnten nicht gelesen werden,\n"
							"die Karte ist eventuell defekt!"));
		return false;
	}
	
	// Karte in DB eintragen
	if (settings->tag_enterDB) {
		// Aktuelle Softwareversion aus der Datenbank lesen
		QSqlQuery query;
		query.exec("SELECT id FROM rfidtags WHERE SNR_RFID='" + serial + "'");
		//qDebug() << query.lastError();
		if (!query.next()) { // Falls die Serienummer noch nicht eingetragen wurde:
			query.exec("INSERT INTO rfidtags ("
				"id, "
				"SNR_RFID, "
				"active "
				")"
				"VALUES ("
				"NULL , '" + serial + "', '1'"
				");");
		}
	}

	// Starte den Dialog zum Registrieren
	qDebug() << "tag_init: " << settings->register_in_DB;
	if (settings->register_in_DB) {
		// Karte Persönlich machen und true zurücksenden.
		// Rest wird in BEO_Timing::checkRFID() und RFIDInputDialog
		// gemacht.
		setPersonalFlag();
	}

	qDebug() << "tag_init: " << settings->tag_reset;
	if(settings->tag_reset == Res_persoenlich){
		// In diesem Fall soll die Karte zurückgesetzt werden
		// hier muss das Statusbyte gelöscht werden!
		memset(pData,0,16); // 16 Datenbytes auf '0x00' setzen
		// Persönlich Flag setzen
		*pData |= TAG_STATUS_REGISTERED;
		state = rf_ul_write(icdev,RFID_ADR_STATUS,pData); // Page 4 mit '0' + Personal überschreiben
		*pData &= ~TAG_STATUS_REGISTERED;
		for(int i=1; i<9;i++){
			state = rf_ul_write(icdev,RFID_ADR_STATUS+i,pData); // Page 5-11 mit '0' überschreiben
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
			state = rf_ul_write(icdev,RFID_ADR_STATUS+i,pData); // Page 4-11 mit '0' überschreiben
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
		bool registred = false;
		if (query.next()) {
			kontakt = "Der Inhaber ist: \n" + query.value(0).toString() + " "
					+ query.value(1).toString() + ", "
					+ query.value(2).toString() + ", "
					+ query.value(3).toString() + " "
					+ query.value(4).toString() + ", "
					+ query.value(5).toString() + ", "
					+ query.value(6).toString() + ", "
					+ query.value(7).toString();
			registred = true;
		} else {
			kontakt
					= "Kein Teilnehmer in der Datenbank. \nRetournieren Sie diese Karte an den Administrator.";
			registred = false;
		}

		if (!registred) {
			QMessageBox::critical(0, QObject::tr("Persönliche Karte"),


					QObject::tr("Diese Karte ist als Persönlich registriert. ")
							+ kontakt);
			if (settings->register_in_DB)
				return true;
			else
				return false;
		} else if (registred) {
			QMessageBox msgBox;
			QPushButton *entfernenButton = msgBox.addButton(QObject::tr(
					"Registrierung Entfernen"), QMessageBox::ActionRole);
			QPushButton *okButton = msgBox.addButton(QObject::tr(
					"Registrierung bestehen lassen"), QMessageBox::ActionRole);
			msgBox.setDefaultButton(entfernenButton);
			msgBox.setEscapeButton(okButton);

			msgBox.setText("Diese Karte ist als Persönlich registriert. "
					+ kontakt);
			msgBox.setWindowTitle("Persönliche Karte");
			msgBox.setIcon(QMessageBox::Question);
			msgBox.exec();
			if (msgBox.clickedButton() == entfernenButton) {
				// Registrierung entfernen
				QSqlQuery query(
						"SELECT TeilnehmerKey FROM teilnehmer WHERE SNR_RFID='"
								+ serial + "'");
				query.exec();
				query.next();
				query.exec(
						"UPDATE teilnehmer SET SNR_RFID = NULL WHERE TeilnehmerKey="
								+ query.value(0).toString());
				if (settings->register_in_DB)
					return true;
				else
					return false;
			} else {
				// Registrierung bestehen lassen
				return false;
			}
		}


	// TODO: Reagieren auf Auswahl im Menue "Verbindung"

	}else if(pData[0] == 0xFF && pData[1] == 0xFF && settings->tag_init == Neu_persoenlich){
		// In diesem Fall wurde eine neue Karte vorgehalten
		// hier müssen die Statusbyte gelöscht werden!
		memset(pData,0,4); // 4 Datenbytes auf '0x00' setzen
		// Persönlich Flag setzen, da die Karte als erstes Persönlich ist, da sie noch keine Etikette trägt.
		*pData |= TAG_STATUS_REGISTERED;
		state = rf_ul_write(icdev,RFID_ADR_STATUS,pData); // Page 4 mit '0' überschreiben
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
			state = rf_ul_write(icdev,RFID_ADR_STATUS,pData); // Page 4 mit '0' überschreiben
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
	state = rf_M1_read(icdev, RFID_ADR_ENDTIME, pData+16, &cLen);
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

 * \brief Setzen des Persönlich Flags und löschen aller andern
 */
bool RFID_CR500::setPersonalFlag() {
	int state = 1;
	unsigned char pData[64];
	unsigned char cLen;

	if (!connected) // keine Verbindung
		return false;

	if (!findCard()) {// Keine Karte gefunden
		QMessageBox::critical(
				0,
				QObject::tr("Keine RFID-Karte"),
				QObject::tr(
						"Es liegt keine Karte im Feld des Lesers. Legen Sie die Karte mit der Seriennummer \"")
						+ oldSerial + "\" auf!");
		return false;
	}
	if (oldSerial.compare(serial) != 0) { // Falsche Karte
		QMessageBox::critical(0, QObject::tr("Falsche RFID-Karte"),
				QObject::tr("Es liegt nicht die Karte mit der Seriennummer \"")
						+ oldSerial + "\" auf!");
		return false;
	}
	// Andere Statusbits lesen
	state = rf_M1_read(icdev, RFID_ADR_STATUS, pData, &cLen);
	if (state || cLen != 16) {
		return false;
	}
	// Gewählte löschen und alle neu schreiben
	*pData = 0; // Alle Flags löschen und Registred setzen
	*pData |= TAG_STATUS_REGISTERED; // erstes Byte löschen (Valid Data Flag)
	state = rf_ul_write(icdev, RFID_ADR_STATUS, pData);
	rf_light(icdev, GREEN_LED);
	return true;
}

/*!

 * \brief Löschen der Flags, um die Karte als ausgewertet kennzuzeichnen
 */
bool RFID_CR500::clearValidFlag() {
	int state = 1;
	unsigned char pData[64];
	unsigned char cLen;

	if (!connected) // keine Verbindung
		return false;

	if (!findCard()) {// Keine Karte gefunden
		QMessageBox::critical(
				0,
				QObject::tr("Keine RFID-Karte"),
				QObject::tr(
						"Es liegt keine Karte im Feld des Lesers. Legen Sie die Karte mit der Seriennummer \"")
						+ oldSerial + "\" auf!");
		return false;
	}
	if (oldSerial.compare(serial) != 0) { // Falsche Karte
		QMessageBox::critical(0, QObject::tr("Falsche RFID-Karte"),
				QObject::tr("Es liegt nicht die Karte mit der Seriennummer \"")
						+ oldSerial + "\" auf!");
		return false;
	}
	// Andere Statusbits lesen
	state = rf_M1_read(icdev, RFID_ADR_STATUS, pData, &cLen);
	if (state || cLen != 16) {
		return false;
	}
	// Gewählte löschen und alle neu schreiben
	*pData &= ~(TAG_STATUS_STRECKENVALID | TAG_STATUS_STARTVALID
			| TAG_STATUS_ENDVALID); // erstes Byte löschen (Valid Data Flag)
	state = rf_ul_write(icdev, RFID_ADR_STATUS, pData);
	rf_light(icdev, GREEN_LED);
	return true;
}
/*!
 * \brief Stellt die LED des Lesers auf Grün
 */
void RFID_CR500::greenLED() {
	rf_light(icdev, GREEN_LED);
}

/*!
 * \brief Funktion zum Testen der Verbindung zum Leser
 */
bool RFID_CR500::isConnected(){
	unsigned char version[100];
	unsigned char len;
	char error;
	error = rf_get_model(icdev,version, &len);
	if(error)
		connected = false;
	else
		connected = true;
	return connected;
}


