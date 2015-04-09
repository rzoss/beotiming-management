 /**
 *******************************************************************************
 * \file    hardwarekonfiguration.cpp
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
#include "hardwarekonfiguration.h"
#include <QtGui>
#include <QtSql>
#include "User.h"
#include <QHeaderView>
#include <QFileDialog>
#include <QMessageBox>

/*!
 * \brief Konstruktor
 */
HardwareKonfiguration::HardwareKonfiguration(User* user, QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	
	// ComboBox mit verfügbaren Stationen füllen
	QSqlQuery query;
	QStringList list;
	query.exec("SELECT funktion, sim_pin, sim_puk, sms_center, server_ip, "
			   "server_port, gprs_username, gprs_pwd, ftp_server, "
			   "ftp_username, ftp_pwd FROM stationen");
	for (int i=0; i< query.numRowsAffected() ; ++i){
		query.next();
		list.append("Station-Nr " + QString::number(i+1) + " (" + query.value(0).toString()+ ")");
		qDebug() << list.at(i);
		funktion = query.value(0).toString();
	}
	ui.stationComboBox->addItems(list);
	
	// Labels mit Daten füllen
	ui.ftpserverLabel->setText(query.value(8).toString());
	ui.ftpuserLabel->setText(query.value(9).toString());
	
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
					ui.streckenTreeWidget->clearSelection ();
					count++;
				}
				if(count == 0)
					root->setHidden(true);
			}
		}
	}
	ui.streckenTreeWidget->collapseAll();
	ui.streckenTreeWidget->expandItem(act_year);
	ui.streckenTreeWidget->clearSelection ();
	
	// default GPRS verwenden
	use_gprs=true;
	
	// SMS Nummer einschränken
	QRegExp telExp ("\\+[\\d]+");
	ui.smsLineEdit->setValidator (new QRegExpValidator (telExp, this));
	ui.smsLineEdit->setMaxLength (12);	
	

}
/*!
 * \brief Destruktor
 */
HardwareKonfiguration::~HardwareKonfiguration()
{

}
/*!
 * \brief aktuelle Sommerzeit aus der Datenbank lesen
 */
QStringList HardwareKonfiguration::getSommertime(){
	// Sommerzeit ein/aus Datum aus Datenbank holen
	QStringList list;
	QString streckenkey_str = ui.streckenTreeWidget->currentItem()->data(3,Qt::DisplayRole).toString();
	QSqlQuery query;
	query.exec("SELECT Startdatum FROM strecken WHERE StreckenKey='" + streckenkey_str + "'");
	query.next();
	int year = query.value(0).toDate().year();
	int month = query.value(0).toDate().month();
	
	qDebug() << year << " " << month;
	query.exec("SELECT sommerzeit, winterzeit FROM sommerzeit WHERE jahr='" +
			   QString::number(year) + "' OR jahr='" + QString::number(year+1) + "'");
	query.next();
	// Sommerzeitwechsel schreiben
	if(month>3){ // März ist vorbei, Sommerzeit vom nächsten Jahr schreiben
		query.next();
		list.append(query.value(0).toString());
		query.previous();
	}else{ // März ist noch nicht vorbei
		list.append(query.value(0).toString());
	}
	// Winterzeitwechsel schreiben
	if(month>10){ // Oktober ist vorbei, Sommerzeit vom nächsten Jahr schreiben
		query.next();
		list.append(query.value(0).toString());
		query.previous();
	}else{ // Oktober ist noch nicht vorbei
		list.append(query.value(0).toString());
	}
	return list;
}


/*!
 * \brief ausgewählte Rennen im Baum bestimmen
 */
QStringList HardwareKonfiguration::getSelectedRennen(){
	QList<QTreeWidgetItem*> selected = ui.streckenTreeWidget->selectedItems ();
	QStringList list;
	QSqlQuery query;
	qDebug () << query.lastError();
	for(int i=0; i<selected.count(); ++i){
		query.exec("SELECT Typ FROM streckentyp, strecken WHERE "
						"strecken.StreckentypKey =streckentyp.streckentypKey AND "
						"strecken.StreckenKey='" + selected.at(i)->data(3,Qt::DisplayRole).toString() + "'");
		query.next();
		list.append(selected.at(i)->data(3,Qt::DisplayRole).toString());
		list.append(query.value(0).toString());
	}
	return list;
}


/*!
 * \brief Slot für OK-Button
 */
void HardwareKonfiguration::on_okButton_released(){
	// Validierung
	if(!validation())
		return;
	
	// Speichern der Informationen in eine config.ini file
	QString fileName = QFileDialog::getSaveFileName(this,
								tr("Speichere konfiguration"), "config.ini", 
								tr("Configurations Datei (*.ini)"));
	// relevante Daten aus der Datenbank lesen
	QSqlQuery query;
	QStringList list;
	QString sql = "SELECT funktion, sim_pin, sim_puk, sms_center, wapapn, server_ip, "
			   "server_port, gprs_username, gprs_pwd, ftp_server, "
			   "ftp_username, ftp_pwd FROM stationen WHERE StationenKey='" + 
			   QString::number(ui.stationComboBox->currentIndex()+1) + "'";
	qDebug() << sql;
	query.exec(sql);
	query.next();
	funktion=query.value(0).toString();
	for(int i=1;i<=11;++i)
		list.append(query.value(i).toString());
	// Konfiguration in Datei speichern 
	if(!fileName.isEmpty()){
		QFile file(fileName);
		if(!file.open(QIODevice::WriteOnly)){
			QMessageBox::warning(this, tr("Exportieren nach CSV"),
									tr("Kann die Datei %1 nicht schreiben;\n%2")
									.arg(file.fileName()).arg(file.errorString()));
			return;
		}
		QTextStream out(&file);
		// Daten in Datei schreiben
		QStringList timechange = getSommertime();
		if(funktion.compare("start")==0){
			out << "STARTorFINISH=0" << "\r\n";
		}else{
			out << "STARTorFINISH=1" << "\r\n";
		}
		out << "WINTERTIME_DAY=" << timechange.at(1) << "\r\n";
		out << "SUMMERTIME_DAY=" << timechange.at(0) << "\r\n";
		out << "SIM_PIN=" << list.at(0) << "\r\n";
		out << "SIM_PUK=" << list.at(1) << "\r\n";
		out << "SMS_NR=" << ui.smsLineEdit->text() << "\r\n";
		out << "SMS_CENTER=" << list.at(2) << "\r\n";
		out << "WAPAPN=" << list.at(3) << "\r\n";
		out << "SERVER_IP=" << list.at(4) << "\r\n";
		out << "SERVER_PORT=" << list.at(5) << "\r\n";
		out << "GPRS_USERNAME=" << list.at(6) << "\r\n";
		out << "GPRS_PWD=" << list.at(7) << "\r\n";
		out << "FTP_SERVER=" << list.at(8) << "\r\n";
		out << "FTP_USERNAME=" << list.at(9) << "\r\n";
		out << "FTP_PWD=" << list.at(10) << "\r\n";
		
		out << "GOODNIGHT_TIME=" << ui.ausSpinBox->value() << "\r\n";
		out << "WAKEUP_TIME=" << ui.einSpinBox->value() << "\r\n";
		if(ui.gprsCheckBox->isChecked())
			out << "USE_GPRS=1" << "\r\n";
		else
			out << "USE_GPRS=0" << "\r\n";
		
		QStringList strecken = getSelectedRennen();
		qDebug() << strecken.count();
		out << "STRECKENKEY_1=" << strecken.at(0) << "\r\n";
		out << "STRECKENSTRING_1=" << strecken.at(1) << "\r\n";
		if(strecken.count()>2){
			out << "STRECKENKEY_2=" << strecken.at(2) << "\r\n";
			out << "STRECKENSTRING_2=" << strecken.at(3) << "\r\n";
		}else{
			out << "STRECKENKEY_2=0" << "\r\n";
			out << "STRECKENSTRING_2=0" << "\r\n";
		}
		if(strecken.count()>4){
			out << "STRECKENKEY_3=" << strecken.at(4) << "\r\n";
			out << "STRECKENSTRING_3=" << strecken.at(5) << "\r\n";
		}else{
			out << "STRECKENKEY_3=0" << "\r\n";
			out << "STRECKENSTRING_3=0" << "\r\n";			
		}
		 
		file.flush();
		file.close();
	}
	this->close();
	
}
/*!
 * \brief Slot für Abbrechen-Button
 */
void HardwareKonfiguration::on_canButton_released(){
	// Fenster schliessen
	this->close();
}
/*!
 * \brief Slot für Änderungen in der Baumauswahl
 */
void HardwareKonfiguration::on_streckenTreeWidget_currentItemChanged(QTreeWidgetItem * current, QTreeWidgetItem * previous){
	qDebug() << ui.streckenTreeWidget->selectedItems ().count();
	// Warnung, wenn mehr als 3 Rennen gewählt werden
	if(ui.streckenTreeWidget->selectedItems ().count()>=3){
		QMessageBox::critical(this, QObject::tr("Zu viele Strecken"),QObject::tr("Sie können nicht mehr als 3 Strecken auf eine Anlage laden!"));
		ui.streckenTreeWidget->clearSelection();
	}
}
/*!
 * \brief Validierung für den Dialog
 */
bool HardwareKonfiguration::validation(){
	bool valid = true;
	QString error = "Die folgenden Felder benötigen noch einen korrekten Inhalt:\n";
	if(getSelectedRennen().isEmpty()){
		error += "Streckenauswahl, ";
		valid = false;
	}
	if(ui.smsLineEdit->text()=="" || ui.smsLineEdit->text().length()!=12){
		error += "SMS-Nr, ";
		valid = false;
	}
	// entfernt 2 Zeichen am Ende des Strings
	error.chop(2);
	if(!valid)
		QMessageBox::critical(0,QObject::tr("Fehlende Einträge"),error);
	return valid;
}
