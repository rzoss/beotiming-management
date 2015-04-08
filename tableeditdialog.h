 /**
 *******************************************************************************
 * \file    tableeditdialog.h
 *******************************************************************************
 * \brief    Dieser Dialog dient dem Editieren der Eintraege.
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

#ifndef TABLEEDITDIALOG_H
#define TABLEEDITDIALOG_H

#include <QtGui/QDialog>
#include <QtSql>
#include "ui_tableeditdialog.h"
#include "User.h"
#include "BEO_Timing.h"

/*!
 * \brief Dieser Dialog dient dem Editieren der Eintraege.
 * 
 */
class TableEditDialog : public QDialog
{
    Q_OBJECT

public:
    TableEditDialog(int TeilnehmerKeyParam, User* user, QWidget *parent = 0);
    ~TableEditDialog();

private:
    enum{TeilnehmerKey, Name, Vorname, Adresse, PLZ, Ort, Jahrgang, Geschlecht, Nationalitaet, 
    	 Team_Club, Email, Telefon, Mobile, RFID_SNR};
    enum{TimeKey, Eintrag, Startzeit, Endzeit, StreckenKey, TeilnehmerKey2, Kategorie, 
    	 Fahrzeit, SNR_RFID, TimeID};
    enum{superadministrator,administrator,manager,user};
    Ui::TableEditDialogClass ui;
    BEO_Timing* mainWindow;
    QTableView* kontaktView;
    QSqlTableModel* kontaktModel;
    QTableView* resultateView;
    QSqlTableModel* resultateModel;
    QModelIndexList* kontakteChanged;
    QModelIndexList* resultateChanged;
private slots:
	void on_BestaetigenButton_released();
	void on_VerwerfenButton_released();
	void on_loeschenButton_released();
	void on_kontakte_dataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight);
	void on_resultate_dataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight);
};

#endif // TABLEEDITDIALOG_H
