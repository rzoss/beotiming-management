 /**
 *******************************************************************************
 * \file    neueruserdialog.h
 *******************************************************************************
 * \brief    Dieser Dialog dient zum erstellen eines neuen Benutzers.
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

#ifndef NEUERUSERDIALOG_H
#define NEUERUSERDIALOG_H

#include <QDialog>
#include "ui_neueruserdialog.h"
#include "User.h"
/*!
 * \brief Dieser Dialog dient zum erstellen eines neuen Benutzers.
 * 
 */
class NeuerUserDialog : public QDialog
{
    Q_OBJECT

public:
    NeuerUserDialog(User* user, QWidget *parent = 0);
    ~NeuerUserDialog();

private:
	enum streckentypen {Rennvelo=1, Mountainbike=2, Laufen=3, Walking=4, Langlauf=5, Inline=6};
	bool validation();    
    Ui::NeuerUserDialogClass ui;
    User * pUser;
    int usertype_offset;
    
private slots:
	void on_okButton_released();
	void on_canButton_released();

};

#endif // NEUERUSERDIALOG_H
