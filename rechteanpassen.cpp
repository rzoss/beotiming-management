 /**
 *******************************************************************************
 * \file    rechteanpassen.cpp
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
#include "rechteanpassen.h"
#include <QtSql>
#include <QtGui>
#include "User.h"
#include "md5/md5.h"
#include <QHeaderView>
#include <QLineEdit>
#include <QMessageBox>
#include <QInputDialog>

/*!
 * \brief Slot für die Reaktion auf Änderungen der CheckBox
 * \param user Pointer auf den angemeldeten Benutzer
 * \param parent Pointer auf das aufrufende Objekt
 */
RechteAnpassen::RechteAnpassen(User* user, QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	this->pUser=user;
	
	// ComboBox mit aktuellen Benutzern abfüllen
	QSqlQuery query;
	QStringList list;
	query.exec("SELECT username, user.name, usertype.name typ FROM "
			   "user, usertype WHERE usertype=id AND id>=2");
	for(int i=0;i<query.numRowsAffected();++i){
		query.next();
		list.append(query.value(1).toString() + " (" + query.value(0).toString() + 
				    ", " +  query.value(2).toString() + ")");
	}
	ui.comboBox->addItems(list);
	
	// Baum aufbauen
	ui.streckenTreeWidget->setColumnCount(4);
	ui.streckenTreeWidget->setHeaderLabels(QStringList() << tr("Rennen") << tr("Startdatum")
			<< tr("Enddatum") << tr("Streckennummer"));
    ui.streckenTreeWidget->header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui.streckenTreeWidget->header()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui.streckenTreeWidget->header()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui.streckenTreeWidget->header()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
	
	// ermögliche mehrfachauswahl
	ui.streckenTreeWidget->setSelectionMode(QAbstractItemView::MultiSelection);
	
	QString sql = "SELECT min(Jahr) FROM strecken";
	query.exec(sql);
	query.next();
	int min_jahr = query.value(0).toInt();
	sql = "SELECT max(Jahr) FROM strecken";
	query.prepare(sql);
	query.exec();
	query.next();
	int max_jahr = query.value(0).toInt();
	
	QTreeWidgetItem* act_year; // Pointer auf aktuelles Jahr
	for(int jahr=min_jahr; jahr<=max_jahr; ++jahr){
		query.exec("SELECT count(StreckenKey) FROM strecken WHERE Jahr='" + QString::number(jahr) + "'");
		query.next();
		if(query.value(0).toBool()){
			QTreeWidgetItem *root;
			root= new QTreeWidgetItem(ui.streckenTreeWidget->invisibleRootItem());
			root->setText(0, QString::number(jahr));
			if(QString::number(jahr)==QDate::currentDate().toString("yyyy")){
				// Pointer auf WidgetItem für aktuelles Jahr
				act_year=root;
			}
			QTreeWidgetItem *item;
			sql = "SELECT StreckenKey, Streckenname, Startdatum, Enddatum, Jahr, StreckentypKey "
					"FROM strecken "
					"WHERE Jahr='" + QString::number(jahr) + "'";
			qDebug() << sql;
			query.prepare(sql);
			query.exec();
			if(query.isActive()){
				int count = 0;
				while(query.next() && user->getRaceAuthority(query.value(0).toInt())){
					item = new QTreeWidgetItem(root);
					item->setText(0,query.value(1).toString());
					item->setText(1,query.value(2).toDate().toString("dd.MM.yyyy"));
					item->setText(2,query.value(3).toDate().toString("dd.MM.yyyy"));
					item->setText(3,QString::number(query.value(0).toInt()));
					QIcon icon;
					switch(query.value(5).toInt()){
						case Rennvelo: icon.addFile(":/images/rennrad.png"); break;
						case Mountainbike: icon.addFile(":/images/bike.png"); break;
						case Laufen: icon.addFile(":/images/plauf.png"); break;
						case Walking: icon.addFile(":/images/walking.png"); break;
						case Langlauf: icon.addFile(":/images/langlauf.png"); break;
						case Inline: icon.addFile(":/images/inline.png"); break;
						default: icon.addFile(":/images/unbekannt.png"); break;
					}
					item->setIcon(0,icon);
					ui.streckenTreeWidget->setCurrentItem(item);
					count++;
				}
				if(count == 0)
					root->setHidden(true);
			}
		}
	}
	// Aktuelles Jahr aufklappen
	ui.streckenTreeWidget->collapseAll();
	ui.streckenTreeWidget->expandItem(act_year);
	ui.streckenTreeWidget->clearSelection ();
	
}
/*!
 * \brief Destruktor
 */
RechteAnpassen::~RechteAnpassen()
{

}
/*!
 * \brief Slot für die Änderungen der Selektion der ComboBox
 * \param text Referenz auf den gewählten Text
 */
void RechteAnpassen::on_comboBox_currentIndexChanged ( const QString & text ){
	ui.altCheckBox->setChecked(false);
}

/*!
 * \brief Slot für OK-Button
 */
void RechteAnpassen::on_okButton_released(){
	char md5_password_char [17];
	
	// Passwortabfrage zur Identifikation	
	QString pwd = QInputDialog::getText(this, tr("Identifizierung als Administrator"),
		                                          tr("Passwort des angemeldeten Administrators:"), 
		                                          QLineEdit::Password);
	// überprüfen, falls eingegeben
	if(!pwd.isEmpty()){
        md5_buffer(pwd.toLatin1().data(),pwd.length(),md5_password_char);
		pwd = QByteArray::fromRawData(md5_password_char,16).toHex(); 
		if(pUser->password.compare(pwd)!=0){
			// Zurück zum Eingabe Dialog
			QMessageBox::critical(this, QObject::tr("Passwortabfrage"),QObject::tr("Das Passwort war nicht Korrekt!"));
			return;
		}
	}else{
		QMessageBox::critical(this, QObject::tr("Fehler"),QObject::tr("Sie haben kein Passwort eingegeben!"));
		return;
	}
	
	// Erstellen des Strings für die Berechtigungen
	QList<QTreeWidgetItem*> list = ui.streckenTreeWidget->selectedItems();
	QString newrights;
	for(int i=0;i<list.count();++i){
		newrights += list.at(i)->data(3,Qt::DisplayRole).toString() + ";";
	}
	newrights.chop(1); // letzter ';' wegschneiden
	qDebug() << newrights;
	
	// Userobjekt für zu bearbeitenden User erstellen
	QString line = ui.comboBox->currentText();
	QString username = line.mid(line.indexOf("(")+1,6);
	pChangeUser = new User();
	pChangeUser->Init(username);
	// alte und neue oder nur neue Rechte ?
	if(!ui.altCheckBox->isChecked())
		newrights += ";" + pChangeUser->rennen;
	// Datenbank updaten
	QSqlQuery query;
	query.exec("UPDATE user SET Rennen = '" + newrights + "' WHERE username='" + username + "'");
	// Userobjekt löschen
	delete pChangeUser;
	
	// Fenster schliessen
	this->close();	
}
/*!
 * \brief Slot für Abbrechen-Button
 */
void RechteAnpassen::on_canButton_released(){
	// Fenster schliessen 
	this->close();
}

