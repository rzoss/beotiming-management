 /**
 *******************************************************************************
 * \file    logfilelesendialog.h
 *******************************************************************************
 * \brief    Dieser Dialog sucht eine Log-Datei einer Zielstation nach nicht 
 * uebermittelten Eintraegen ab.
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
#ifndef LOGFILELESENDIALOG_H
#define LOGFILELESENDIALOG_H

#include <QDialog>
#include "ui_logfilelesendialog.h"
/*!
 * \brief Dieser Dialog sucht eine Log-Datei einer Zielstation nach nicht 
 * uebermittelten Eintraegen ab.
 * 
 */
class LogfileLesenDialog : public QDialog
{
    Q_OBJECT

public:
    LogfileLesenDialog(QWidget *parent = 0);
    ~LogfileLesenDialog();

private:
	QListWidgetItem* createItem(QString line);
	enum streckentypen {Rennvelo=1, Mountainbike=2, Laufen=3, Walking=4, Langlauf=5, Inline=6};
    Ui::LogfileLesenDialogClass ui;
    QStringList add;
    QStringList remove;
private slots:
	void on_okButton_released();
	void on_canButton_released();
	void on_neuCheckBox_stateChanged ( int state );
	void on_delCheckBox_stateChanged ( int state );
	
};

#endif // LOGFILELESENDIALOG_H
