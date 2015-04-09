 /**
 *******************************************************************************
 * \file    logondialog.h
 *******************************************************************************
 * \brief    Dieser Dialog ist das Login des Programms. Es dient zur Authentifizierung 
 * des Benutzers.
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
 *******************************************************************************
 */
#ifndef LOGONDIALOG_H
#define LOGONDIALOG_H

#include <QDialog>
#include "ui_logondialog.h"
#include "Database.h"
#include "beo_timing.h"
#include "User.h"
/*!
 * \brief Dieser Dialog ist das Login des Programms. Es dient zur Authentifizierung 
 * des Benutzers.
 * 
 */
class LogonDialog : public QDialog
{
    Q_OBJECT

public:
    LogonDialog(User* user, QApplication *a, BEO_Timing *w, QWidget *parent = 0);
    ~LogonDialog();

protected:
	QApplication*a;
	BEO_Timing*w;
	User* user;
    Ui::LogonDialogClass ui;
private slots:
	void on_LogonButton_released();
	void on_BeendenButton_released();
	
};

#endif // LOGONDIALOG_H
