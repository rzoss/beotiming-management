 /**
 *******************************************************************************
 * \file    passwordchangedialog.h
 *******************************************************************************
 * \brief    Dieser Dialog dient zum aendern des Passworts des angemeldeten Benutzers.
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

#ifndef PASSWORDCHANGEDIALOG_H
#define PASSWORDCHANGEDIALOG_H

#include <QDialog>
#include "ui_passwordchangedialog.h"
#include "User.h"

/*!
 * \brief Dieser Dialog dient zum aendern des Passworts des angemeldeten Benutzers.
 * 
 */
class PasswordChangeDialog : public QDialog
{
    Q_OBJECT

public:
    PasswordChangeDialog(User* pUser, QWidget *parent = 0);
    ~PasswordChangeDialog();

private:
	bool validation(QString pwd);
    Ui::PasswordChangeDialogClass ui;
    User* pUser;
private slots:
	void on_okButton_released();
	void on_canButton_released();
	void on_newLineEdit_textChanged(const QString& text);
signals:
	void valueCalculated(int value);
};

#endif // PASSWORDCHANGEDIALOG_H
