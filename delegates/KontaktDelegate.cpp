 /**
 *******************************************************************************
 * \file    KontaktDelegate.cpp
 *******************************************************************************
 * \brief    Diese Klasse bildet die Schnittstelle zwischen der Kontakteditiertabelle
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
#include "KontaktDelegate.h"
#include <QtSql>
#include <QtGui>
#include <QSpinBox>
#include <QLineEdit>

/*!
 * \brief Konstruktor
 */
KontaktDelegate::KontaktDelegate(QObject *parent)
	: QItemDelegate(parent)  {}

/*!
 * \brief Einstellungen für die Anzeige und Manipulation
 */
QWidget* KontaktDelegate::createEditor(QWidget *parent,
            const QStyleOptionViewItem &option,
            const QModelIndex &index) const
    {
		// ComboBox für Geschlecht
    	if(index.column() == Geschlecht){
    		QComboBox *editor = new QComboBox(parent);
    		editor->addItems(QStringList() << "Maennlich" << "Weiblich");
    		return editor;
    	}
    	// ComboBox für Nationalität mit den Informationen aus der Datenbank erstellen 
    	if(index.column() == Nationalitaet){
    		QComboBox *editor = new QComboBox(parent);
    		QStringList list;
    		QSqlQuery query("SELECT name FROM nationalitaeten ORDER BY name ASC");
    		query.exec();
    		for(int i=0;i<query.numRowsAffected();++i){
    			query.next();
    			list.append(query.value(0).toString());
    		}
    		editor->addItems(list);
    		return editor;
    	}
    	// SpinBox für den Jahrgang erstellen und den Wertebereich einschränken
    	if(index.column() == Jahrgang){
    		QSpinBox *editor = new QSpinBox(parent);
    		editor->setRange(1900,2050);
    		return editor;
    	}
    	QLineEdit *editor = new QLineEdit(parent);
    	return editor;
    }
/*!
 * \brief Setzen der spezifischen Typen gemäss den Daten im Modell
 */
   void KontaktDelegate::setEditorData(QWidget *editor,
		const QModelIndex &index) const {
    	QLineEdit *edit = qobject_cast<QLineEdit *>(editor);
    	QComboBox *comboEditor = qobject_cast<QComboBox *>(editor);
    	QSpinBox *spinEditor = qobject_cast<QSpinBox *>(editor);
    	if (edit) {
    		edit->setText(index.model()->data(index, Qt::EditRole).toString());
    	} else if (comboEditor) {
    		comboEditor->setCurrentIndex(
    				comboEditor->findText(
    						index.model()->data(
    								index, Qt::EditRole).toString()));
    	} else if (spinEditor) {
    		spinEditor->setValue(index.model()->data(index, Qt::EditRole).toInt());
    	}
    }
   /*!
    * \brief Setzen der Information im Modell
    */
    void KontaktDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
        const QModelIndex &index) const
    {
    	QLineEdit *edit = qobject_cast<QLineEdit *>(editor);
    	QComboBox *comboEditor = qobject_cast<QComboBox *>(editor);
    	QSpinBox *spinEditor = qobject_cast<QSpinBox *>(editor);
    	if (edit) {
            model->setData(index, edit->text());
        } else if (comboEditor) {
            model->setData(index,comboEditor->currentText());
        } else if (spinEditor) {
        	model->setData(index,spinEditor->value());
    	}
    }
