 /**
 *******************************************************************************
 * \file    ResultateDelegate.cpp
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
#include "ResultateDelegate.h"
#include <QtSql>
#include <QtGui>

/*!
 * \brief Konstruktor
 */
ResultateDelegate::ResultateDelegate(QObject *parent)
	: QItemDelegate(parent)  {}

/*!
 * \brief Einstellungen für die Anzeige und Manipulation
 */
QWidget* ResultateDelegate::createEditor(QWidget *parent,
            const QStyleOptionViewItem &option,
            const QModelIndex &index) const
    {
    	if(index.column() == Kategorie){
    		QComboBox *editor = new QComboBox(parent);
    		QStringList list;
    		QSqlQuery query("SELECT name FROM kategorien");
    		query.exec();
    		for(int i=0;i<query.numRowsAffected();++i){
    			query.next();
    			list.append(query.value(0).toString());
    		}
    		editor->addItems(list);
    		return editor;
    	}
    	if(index.column() == Eintrag ||
    	   index.column() == Startzeit ||
    	   index.column() == Endzeit){
    		QDateTimeEdit *editor = new QDateTimeEdit(parent);
            editor->setDisplayFormat("dd.MM.yyyy hh:mm:ss");
            editor->setCalendarPopup(true);
            return editor;
    	}
    	if(index.column() == Fahrzeit){
    		QTimeEdit *editor = new QTimeEdit(parent);
    		editor->setDisplayFormat("hh:mm:ss");
    		editor->setCalendarPopup(false);
    		return editor;
    	}
    	QLineEdit *editor = new QLineEdit(parent);
    	return editor;
    }
/*!
 * \brief Einstellungen für die Anzeige und Manipulation
 */
   void ResultateDelegate::setEditorData(QWidget *editor,
		const QModelIndex &index) const {
    	QLineEdit *edit = qobject_cast<QLineEdit *>(editor);
    	QDateTimeEdit *dateEditor = qobject_cast<QDateTimeEdit *>(editor);
    	QComboBox *comboEditor = qobject_cast<QComboBox *>(editor);
    	QTimeEdit *timeEditor = qobject_cast<QTimeEdit *>(editor);
    	if (edit) {
    		edit->setText(index.model()->data(index, Qt::EditRole).toString());
    	} else if (dateEditor) {
    		dateEditor->setDateTime(index.model()->data(index, Qt::EditRole).toDateTime());
    		if(index.column() == Fahrzeit)
    			timeEditor->setTime(index.model()->data(index, Qt::EditRole).toTime());
    	} else if (comboEditor) {
    		comboEditor->setCurrentIndex(
    				comboEditor->findText(
    						index.model()->data(
    								index, Qt::EditRole).toString()));
    	}
    }
   /*!
    * \brief Setzen der spezifischen Typen gemäss den Daten im Modell
    */
    void ResultateDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
        const QModelIndex &index) const
    {
    	QLineEdit *edit = qobject_cast<QLineEdit *>(editor);
    	QDateTimeEdit *dateEditor = qobject_cast<QDateTimeEdit *>(editor);
    	QComboBox *comboEditor = qobject_cast<QComboBox *>(editor);
    	if (edit) {
            model->setData(index, edit->text());
        }
        else if (dateEditor) {
        	model->setData(index, dateEditor->dateTime());
        	if(index.column() == Fahrzeit)
        		model->setData(index, dateEditor->time());
        } else if (comboEditor) {
            model->setData(index,comboEditor->currentText());
        } 
    }

