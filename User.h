 /**
 *******************************************************************************
 * \file    User.h
 *******************************************************************************
 * \brief    Diese Klasse symbolisiert einen Benutzer und stellt Funktionen bereit.
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
 #ifndef USER_H_
#define USER_H_

#include <QtGui>
#include <QtSql>

/*!
 * \brief Diese Klasse symbolisiert einen Benutzer und stellt Funktionen bereit.
 * 
 */
class User
{
public:
	User();
	virtual ~User();
	int getUsertype();
    void Init(QString username, QString password) throw (QString);
    void Init(QString username);
	bool checkPassword(QString password);
	bool getRaceAuthority(int race);
	bool getLogonSuccess();
	enum{superadministrator,administrator,manager,user};
protected:
	QString username;
	QString name;
	QString email;
	QString password;
	int usertype;
	QString rennen;
	bool logonSuccess;
	friend class PasswordChangeDialog;
	friend class NeuerUserDialog;
	friend class RechteAnpassen;
};

#endif /*USER_H_*/
