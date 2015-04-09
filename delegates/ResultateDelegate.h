 /**
 *******************************************************************************
 * \file    ResultateDelegate.h
 *******************************************************************************
 * \brief    Diese Klasse bildet die Schnittstelle zwischen der Resultateeditiertabelle
 * 				und der Datenbank. Sie schränkt die Eingabemöglichkeiten ein. 
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
#ifndef RESULTATEDELEGATE_H_
#define RESULTATEDELEGATE_H_

#include <QtSql>
#include <QtGui>

/*!
 * \brief Diese Klasse bildet die Schnittstelle zwischen der Resultateeditiertabelle
 * 				und der Datenbank. Sie schränkt die Eingabemöglichkeiten ein. 
 *  
 */
class ResultateDelegate : public QItemDelegate
{
public:
	ResultateDelegate(QObject *parent = 0);

	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
	                     const QModelIndex &index) const;

	void setEditorData(QWidget *editor, const QModelIndex &index) const;
	void setModelData(QWidget *editor, QAbstractItemModel *model,
	                     const QModelIndex &index) const;
	enum{TimeKey, Eintrag, Startzeit, Endzeit, StreckenKey, TeilnehmerKey2, Kategorie, 
	       	 Fahrzeit, SNR_RFID, TimeID};
};

#endif /*RESULTATEDELEGATE_H_*/
