/**
 *******************************************************************************
 * \file    beo_timing.H
 *******************************************************************************
 * \brief    Hauptklasse der Applikation
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


#ifndef BEOTIMING_H
#define BEOTIMING_H

#include <QtGui>
#include <QSplashScreen>
#include "ui_beo_timing.h"
#include "beo_timing.h"
#include "RFID_Reader/rfidinputdialog.h"
#include "RFID_Reader/RFID_CR500.h"
#include "Database.h"
#include "dbThread.h"
#include "User.h"
#include "passwordchangedialog.h"
#include "neueruserdialog.h"
#include "neuesrennendialog.h"
#include "hardwarekonfiguration.h"
#include "logfilelesendialog.h"
#include "rechteanpassen.h"
//#include "RFID_Reader/rfidThread.h"
#include <QtSql>


#define 	VERSION 	"1.0"

struct TAG_SETTINGS {
 	int tag_reset;
   	int tag_init;
};


/*!
 *  \brief Hauptklasse der Applikation
 *
 */
class BEO_Timing : public QMainWindow
{
    Q_OBJECT

public:
	BEO_Timing(QSplashScreen *splash, QApplication *a, QWidget *parent = 0);
    ~BEO_Timing();
    void Read_Race(int StreckenKey);
    void Tree_Settings();
    static void updateUserStatus(QString username){userLabel->setText("Benutzer: " + username);};
    static void updateRFID(QString rfid){connectionLabel->setText("RFID-Leser: " + rfid);};
    static void updateMessage(QString message){messageLabel->setText("Letzte Meldung: " + message);};
    void addRow(int columns);
    QString getTimeCount(int StreckenKey);

protected:
	// Deklaration als Membervariablen, damit Umbrello die Verbindungen im Klassendiagramm
	// automatisch erstellt.
	RechteAnpassen* rechte;
	LogfileLesenDialog* logfile;
	HardwareKonfiguration* config;
	NeuerUserDialog* newUser;
	PasswordChangeDialog* pwd;
	NeuesRennenDialog* neu;


private:
	enum streckentypen {Rennvelo=1, Mountainbike=2, Laufen=3, Walking=4, Langlauf=5, Inline=6};
    enum teilnehmer {Name, Vorname, Adresse, PLZ, Ort, Nationalitaet,
    	 Jahrgang, Geschlecht, Email, Telefon, Mobile,
    	 Team_Club, Kategorie, Fahrzeit, Rueckstand, RFID_SNR,
    	 StreckenKey, TimeID, TimeKey, TeilnehmerKey};
    enum tag_action {Nichts, Neu_persoenlich, Neu_unpersoenlich, Res_persoenlich, Res_unpersoenlich};
    Ui::BEO_TimingClass ui;
    User* user;
    QApplication* a;
    void* thread; // cast to "RFID_Thread"
    void createStatusBar();
    void createMenu();
    void createToolbar();
    void setUserRights();
    void newVersion();
    static QLabel* userLabel;
    static QLabel* connectionLabel;
    static QLabel* messageLabel;
    QTableView* view;
    QTreeWidget* raceTree;
    Database* pMySQL;
    DB_Thread* pMySQL_thread;
    QToolBar* toolbar;
    void* pRfid;	// cast to "RFID_CR500"
    bool version;

public slots:
	void Tree_Build();

private slots:
    void Tree_Changed();
	void Table_Edit();
	void checkRFID();
	void checkDB();
	void NeuesRennen();
	void exportToCsv();
	void changePwd();
	void neuerUser();
	void buildConfiguration();
	void readLogFile();
	void rechteAnpassen();
	void about();
	void rfidConnection(bool);
	void mysqlConnection(bool);
	void purge();
	void optimieren();
	void CR500_verbinden();
	void tag_initialisieren_pers(bool);
	void tag_clear_pers(bool);
	void tag_initialisieren_unpers(bool);
	void tag_clear_unpers(bool);

};

#endif // BEOTIMING_H
