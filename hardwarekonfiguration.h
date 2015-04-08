 /**
 *******************************************************************************
 * \file    hardwarekonfiguration.h
 *******************************************************************************
 * \brief    Dieser Dialog erstellt eine Konfiguration fuer eine Anlage.
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
#ifndef HARDWAREKONFIGURATION_H
#define HARDWAREKONFIGURATION_H

#include <QDialog>
#include "ui_hardwarekonfiguration.h"
#include "User.h"

/*!
 * \brief Dieser Dialog erstellt eine Konfiguration fuer eine Anlage.
 * 
 */
class HardwareKonfiguration : public QDialog
{
    Q_OBJECT

public:
    HardwareKonfiguration(User* user, QWidget *parent = 0);
    ~HardwareKonfiguration();

private:
	enum stationen{StationenKey, typ, sim_pin, sim_puk, sms_center,
		server_ip, server_port, gprs_username, gprs_pwd, 
		ftp_server, ftp_username, ftp_pwd};
	enum streckentypen {Rennvelo=1, Mountainbike=2, Laufen=3, Walking=4, Langlauf=5, Inline=6};
	QStringList getSelectedRennen();
	bool validation();
	bool use_gprs;
	QString funktion;
	QStringList getSommertime();
    Ui::HardwareKonfigurationClass ui;
    
    
private slots:
	void on_okButton_released();
	void on_canButton_released();
	void on_streckenTreeWidget_currentItemChanged(QTreeWidgetItem * current, QTreeWidgetItem * previous);
};

#endif // HARDWAREKONFIGURATION_H
