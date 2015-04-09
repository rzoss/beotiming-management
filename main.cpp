 /**
 *******************************************************************************
 * \file    main.cpp
 *******************************************************************************
 * \brief    Das main Initialisiert das Programm und erstellt den Hauptdialog.
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

#include "beo_timing.h"
#include "logondialog.h"

#include <QtGui>
#include <QApplication>
#include <QtDebug>
#include <iostream>




// Einstiegspunkt in das Programm
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	// Splashscreen erstellen
	QSplashScreen *splash = new QSplashScreen;
	QPixmap pic;
	qDebug() << pic.load(":/images/splash.png");
	qDebug() << pic.isNull();
	splash->setPixmap(pic);
	splash->show();
	Qt::Alignment topRight = Qt::AlignRight | Qt:: AlignTop;
	splash->showMessage(QObject::tr("Starten des Programms..."),topRight, Qt::white);
	// Hauptfenster erstellen
	BEO_Timing* mainwindow = new BEO_Timing(splash, &a,0);
    //mainwindow->setWindowIcon(QPixmap(":/images/icon32_t.bmp"));
	// Schliessen des Programms, wenn alle Fenster geschlossen werden, initialisieren
    a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));
    // Splashscreen ausblenden und löschen
    splash->finish(mainwindow);
    delete splash;
    // Hauptfenster Modal ausführen
    return a.exec();
}



