/**
 *******************************************************************************
 * \file    rfidinputdialog.h
 ********************************************************************************
 * \brief    Stellt die Eingabemaske, sowie die benötigten Funktionen zum auswerten von
 * 			 RFID-Tags eines beliebigen Lesers zur Verfügung. 
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

#ifndef RFIDINPUTDIALOG_H
#define RFIDINPUTDIALOG_H


#include <QtGui>
#include <QtSql>
#include "ui_rfidinputdialog.h"
#include "RFID_Reader/RFID_CR500.h"


class RFID_CR500;
/*!
 * \brief Stellt die Eingabemaske, sowie die benötigten Funktionen zum auswerten von
 * 			 RFID-Tags eines beliebigen Lesers zur Verfügung.  
 * 
 */
class RFIDInputDialog : public QDialog
{
    Q_OBJECT

public:
    RFIDInputDialog(RFID_CR500* pRfid, QWidget *parent = 0);
    ~RFIDInputDialog();

private:
    Ui::RFIDInputDialogClass ui;
    QString toDateString(struct MYTIME* time, QString format = "hh:mm:ss");
    QString toDateString(struct MYDATE* date, QString format = "dd. MMMM yyyy hh:mm:ss");
    QStringList getStreckenNameTyp(int StreckenKey);
    bool insertRacetime(int TeilnehmerKeyInt);
    bool insertPersonAndTime();
    bool updatePerson(int TeilnehmerKeyInt);
    void fillForm(QSqlQuery* query);
    QString calculateKategorie(int jahrgang);
    bool validation();
    bool clearValidFlag();
    QSqlTableModel* teilnehmer;
    enum strecken {StreckenKey, Streckenname, Startdatum, Enddatum, Jahr, StreckentypKey};
    
    enum teilnehmer {TeilnehmerKey, Name, Vorname, Adresse, PLZ, Ort, Jahrgang, Geschlecht, Nationalitaet, 
    	 Team_Club, Email, Telefon, Mobile, RFID_SNR};	
    QString text;
    int TeilnehmerKeyInt;
	int index;
	RFID_CR500* pRfid;
	bool autoInsert;
private slots:
	void on_okButton_released();
	void on_canButton_released();
	void checkSingularity();
	void on_nameLineEdit_textEdited();
	void on_vornameLineEdit_textEdited();
	void on_adresseLineEdit_textEdited();
	void on_plzLineEdit_textEdited();
	void on_ortLineEdit_textEdited();
	void on_telephonLineEdit_textEdited();
	void on_mobileLineEdit_textEdited();
	void on_emailLineEdit_textEdited();
	void on_clubLineEdit_textEdited();
	void on_nationalitaetComboBox_currentIndexChanged();
	void on_jahrgangSpinBox_valueChanged();
	void on_autoCheckBox_stateChanged();
};

#endif // RFIDINPUTDIALOG_H
