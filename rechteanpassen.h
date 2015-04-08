 /**
 *******************************************************************************
 * \file    rechteanpassen.h
 *******************************************************************************
 * \brief    Dieser Dialog dient zum anpassen der Rechte eines beliebigen Benutzers.
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

#ifndef RECHTEANPASSEN_H
#define RECHTEANPASSEN_H

#include <QDialog>
#include "ui_rechteanpassen.h"
#include "User.h"

/*!
 * \brief Dieser Dialog dient zum anpassen der Rechte eines beliebigen Benutzers.
 * 
 */
class RechteAnpassen : public QDialog
{
    Q_OBJECT

public:
    RechteAnpassen(User * user, QWidget *parent = 0);
    ~RechteAnpassen();

private:
	enum streckentypen {Rennvelo=1, Mountainbike=2, Laufen=3, Walking=4, Langlauf=5, Inline=6};
	Ui::RechteAnpassenClass ui;
	User* pUser;
	User* pChangeUser;
private slots:
	void on_comboBox_currentIndexChanged ( const QString & text );
	void on_okButton_released();
	void on_canButton_released();
};

#endif // RECHTEANPASSEN_H
