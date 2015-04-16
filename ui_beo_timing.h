/********************************************************************************
** Form generated from reading ui file 'beo_timing.ui'
**
** Created: Thu 19. Mar 10:50:44 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_BEO_TIMING_H
#define UI_BEO_TIMING_H

#include <QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QDockWidget>
#include <QGridLayout>
#include <QGroupBox>
#include <QHeaderView>
#include <QListWidget>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QTableView>
#include <QTextEdit>
#include <QTreeWidget>
#include <QVBoxLayout>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_BEO_TimingClass
{
public:
    QAction *actionAktualisieren;
    QAction *actionBeenden;
    QAction *actionNeues_Rennen_erfassen;
    QAction *actionAbout;
    QAction *actionEintrag_Editieren;
    QAction *actionExportieren_als_CSV;
    QAction *actionPasswort_ndern;
    QAction *actionNeuer_Benutzer_erstellen;
    QAction *actionNeuer_Benutzer_erstellen_2;
    QAction *actionKonfiguration_erstellen;
    QAction *actionLog_Datei_auslesen;
    QAction *actionBenutzerrechte_ndern;
    QAction *actionRFID_Leser;
    QAction *actionDatenbank;
    QAction *actionAbout_Qt;
    QAction *actionVerwaiste_Eintr_ge_entfernen;
    QAction *actionDatenbank_optimieren;
    QAction *actionNeuer_Benutzer_erstellen_3;
    QAction *actionRFID_Leser_verbinden;
    QAction *actionKarten_zur_cksetzen_unpers_nlich;
    QAction *actionKarten_zur_cksetzen_pers_nlich;
    QAction *actionNeue_Karten_initialisieren_unpers_nlich;
    QAction *actionNeue_Karten_initialisieren_pers_nlich;
    QAction *actionEintragen_der_Karte_in_die_Datenbank;
    QAction *actionKarte_registrieren;
    QAction *actionRennen;
    QAction *actionLog;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QDockWidget *dockRennen;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout;
    QTreeWidget *RennenTreeWidget;
    QDockWidget *dockLog;
    QWidget *dockWidgetContents_2;
    QGridLayout *gridLayout1;
    QGroupBox *groupBox;
    QGridLayout *gridLayout2;
    QListWidget *listWidget;
    QTextEdit *textEdit;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout3;
    QTableView *RanglistenTableView;
    QMenuBar *menubar;
    QMenu *menuDatei;
    QMenu *menuRennadministration;
    QMenu *menuHilfe;
    QMenu *menuVerbindungen;
    QMenu *menuBenutzerverwaltung;
    QMenu *menuAnsicht;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BEO_TimingClass)
    {
        if (BEO_TimingClass->objectName().isEmpty())
            BEO_TimingClass->setObjectName(QString::fromUtf8("BEO_TimingClass"));
        BEO_TimingClass->resize(809, 593);
        actionAktualisieren = new QAction(BEO_TimingClass);
        actionAktualisieren->setObjectName(QString::fromUtf8("actionAktualisieren"));
        QIcon icon;
        icon.addPixmap(QPixmap(QString::fromUtf8(":/images/reload.png")), QIcon::Normal, QIcon::Off);
        actionAktualisieren->setIcon(icon);
        actionBeenden = new QAction(BEO_TimingClass);
        actionBeenden->setObjectName(QString::fromUtf8("actionBeenden"));
        QIcon icon1;
        icon1.addPixmap(QPixmap(QString::fromUtf8(":/images/beenden.png")), QIcon::Normal, QIcon::Off);
        actionBeenden->setIcon(icon1);
        actionNeues_Rennen_erfassen = new QAction(BEO_TimingClass);
        actionNeues_Rennen_erfassen->setObjectName(QString::fromUtf8("actionNeues_Rennen_erfassen"));
        QIcon icon2;
        icon2.addPixmap(QPixmap(QString::fromUtf8(":/images/new.png")), QIcon::Normal, QIcon::Off);
        actionNeues_Rennen_erfassen->setIcon(icon2);
        actionAbout = new QAction(BEO_TimingClass);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon3;
        icon3.addPixmap(QPixmap(QString::fromUtf8(":/images/info.png")), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon3);
        actionEintrag_Editieren = new QAction(BEO_TimingClass);
        actionEintrag_Editieren->setObjectName(QString::fromUtf8("actionEintrag_Editieren"));
        QIcon icon4;
        icon4.addPixmap(QPixmap(QString::fromUtf8(":/images/b_edit.png")), QIcon::Normal, QIcon::Off);
        actionEintrag_Editieren->setIcon(icon4);
        actionExportieren_als_CSV = new QAction(BEO_TimingClass);
        actionExportieren_als_CSV->setObjectName(QString::fromUtf8("actionExportieren_als_CSV"));
        QIcon icon5;
        icon5.addPixmap(QPixmap(QString::fromUtf8(":/images/export.png")), QIcon::Normal, QIcon::Off);
        actionExportieren_als_CSV->setIcon(icon5);
        actionPasswort_ndern = new QAction(BEO_TimingClass);
        actionPasswort_ndern->setObjectName(QString::fromUtf8("actionPasswort_ndern"));
        QIcon icon6;
        icon6.addPixmap(QPixmap(QString::fromUtf8(":/images/pwd.png")), QIcon::Normal, QIcon::Off);
        actionPasswort_ndern->setIcon(icon6);
        actionNeuer_Benutzer_erstellen = new QAction(BEO_TimingClass);
        actionNeuer_Benutzer_erstellen->setObjectName(QString::fromUtf8("actionNeuer_Benutzer_erstellen"));
        actionNeuer_Benutzer_erstellen_2 = new QAction(BEO_TimingClass);
        actionNeuer_Benutzer_erstellen_2->setObjectName(QString::fromUtf8("actionNeuer_Benutzer_erstellen_2"));
        QIcon icon7;
        icon7.addPixmap(QPixmap(), QIcon::Normal, QIcon::Off);
        actionNeuer_Benutzer_erstellen_2->setIcon(icon7);
        actionKonfiguration_erstellen = new QAction(BEO_TimingClass);
        actionKonfiguration_erstellen->setObjectName(QString::fromUtf8("actionKonfiguration_erstellen"));
        QIcon icon8;
        icon8.addPixmap(QPixmap(QString::fromUtf8(":/images/config.png")), QIcon::Normal, QIcon::Off);
        actionKonfiguration_erstellen->setIcon(icon8);
        actionLog_Datei_auslesen = new QAction(BEO_TimingClass);
        actionLog_Datei_auslesen->setObjectName(QString::fromUtf8("actionLog_Datei_auslesen"));
        QIcon icon9;
        icon9.addPixmap(QPixmap(QString::fromUtf8(":/images/log.png")), QIcon::Normal, QIcon::Off);
        actionLog_Datei_auslesen->setIcon(icon9);
        actionBenutzerrechte_ndern = new QAction(BEO_TimingClass);
        actionBenutzerrechte_ndern->setObjectName(QString::fromUtf8("actionBenutzerrechte_ndern"));
        actionRFID_Leser = new QAction(BEO_TimingClass);
        actionRFID_Leser->setObjectName(QString::fromUtf8("actionRFID_Leser"));
        actionRFID_Leser->setCheckable(true);
        actionRFID_Leser->setChecked(true);
        QIcon icon10;
        icon10.addPixmap(QPixmap(QString::fromUtf8(":/images/icon16_t.bmp")), QIcon::Normal, QIcon::Off);
        actionRFID_Leser->setIcon(icon10);
        actionDatenbank = new QAction(BEO_TimingClass);
        actionDatenbank->setObjectName(QString::fromUtf8("actionDatenbank"));
        actionDatenbank->setCheckable(true);
        actionDatenbank->setChecked(true);
        actionDatenbank->setEnabled(false);
        actionAbout_Qt = new QAction(BEO_TimingClass);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        QIcon icon11;
        icon11.addPixmap(QPixmap(QString::fromUtf8(":/images/qt.png")), QIcon::Normal, QIcon::Off);
        actionAbout_Qt->setIcon(icon11);
        actionVerwaiste_Eintr_ge_entfernen = new QAction(BEO_TimingClass);
        actionVerwaiste_Eintr_ge_entfernen->setObjectName(QString::fromUtf8("actionVerwaiste_Eintr_ge_entfernen"));
        QIcon icon12;
        icon12.addPixmap(QPixmap(QString::fromUtf8(":/images/papierkorb.png")), QIcon::Normal, QIcon::Off);
        actionVerwaiste_Eintr_ge_entfernen->setIcon(icon12);
        actionDatenbank_optimieren = new QAction(BEO_TimingClass);
        actionDatenbank_optimieren->setObjectName(QString::fromUtf8("actionDatenbank_optimieren"));
        QIcon icon13;
        icon13.addPixmap(QPixmap(QString::fromUtf8(":/images/optimieren.png")), QIcon::Normal, QIcon::Off);
        actionDatenbank_optimieren->setIcon(icon13);
        actionNeuer_Benutzer_erstellen_3 = new QAction(BEO_TimingClass);
        actionNeuer_Benutzer_erstellen_3->setObjectName(QString::fromUtf8("actionNeuer_Benutzer_erstellen_3"));
        QIcon icon14;
        icon14.addPixmap(QPixmap(QString::fromUtf8(":/images/newuser.png")), QIcon::Normal, QIcon::Off);
        actionNeuer_Benutzer_erstellen_3->setIcon(icon14);
        actionRFID_Leser_verbinden = new QAction(BEO_TimingClass);
        actionRFID_Leser_verbinden->setObjectName(QString::fromUtf8("actionRFID_Leser_verbinden"));
        actionKarten_zur_cksetzen_unpers_nlich = new QAction(BEO_TimingClass);
        actionKarten_zur_cksetzen_unpers_nlich->setObjectName(QString::fromUtf8("actionKarten_zur_cksetzen_unpers_nlich"));
        actionKarten_zur_cksetzen_unpers_nlich->setCheckable(true);
        actionKarten_zur_cksetzen_pers_nlich = new QAction(BEO_TimingClass);
        actionKarten_zur_cksetzen_pers_nlich->setObjectName(QString::fromUtf8("actionKarten_zur_cksetzen_pers_nlich"));
        actionKarten_zur_cksetzen_pers_nlich->setCheckable(true);
        actionNeue_Karten_initialisieren_unpers_nlich = new QAction(BEO_TimingClass);
        actionNeue_Karten_initialisieren_unpers_nlich->setObjectName(QString::fromUtf8("actionNeue_Karten_initialisieren_unpers_nlich"));
        actionNeue_Karten_initialisieren_unpers_nlich->setCheckable(true);
        actionNeue_Karten_initialisieren_pers_nlich = new QAction(BEO_TimingClass);
        actionNeue_Karten_initialisieren_pers_nlich->setObjectName(QString::fromUtf8("actionNeue_Karten_initialisieren_pers_nlich"));
        actionNeue_Karten_initialisieren_pers_nlich->setCheckable(true);
        actionEintragen_der_Karte_in_die_Datenbank = new QAction(BEO_TimingClass);
        actionEintragen_der_Karte_in_die_Datenbank->setObjectName(QString::fromUtf8("actionEintragen_der_Karte_in_die_Datenbank"));
        actionEintragen_der_Karte_in_die_Datenbank->setCheckable(true);
        actionKarte_registrieren = new QAction(BEO_TimingClass);
        actionKarte_registrieren->setObjectName(QString::fromUtf8("actionKarte_registrieren"));
        actionKarte_registrieren->setCheckable(true);
        actionRennen = new QAction(BEO_TimingClass);
        actionRennen->setObjectName(QString::fromUtf8("actionRennen"));
        actionRennen->setCheckable(false);
        actionRennen->setChecked(false);
        actionLog = new QAction(BEO_TimingClass);
        actionLog->setObjectName(QString::fromUtf8("actionLog"));
        actionLog->setCheckable(false);
        actionLog->setChecked(false);
        centralwidget = new QWidget(BEO_TimingClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        dockRennen = new QDockWidget(centralwidget);
        dockRennen->setObjectName(QString::fromUtf8("dockRennen"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dockRennen->sizePolicy().hasHeightForWidth());
        dockRennen->setSizePolicy(sizePolicy);
        dockRennen->setMinimumSize(QSize(100, 250));
        dockRennen->setBaseSize(QSize(0, 0));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        gridLayout = new QGridLayout(dockWidgetContents);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        RennenTreeWidget = new QTreeWidget(dockWidgetContents);
        RennenTreeWidget->setObjectName(QString::fromUtf8("RennenTreeWidget"));

        gridLayout->addWidget(RennenTreeWidget, 0, 0, 1, 1);

        dockRennen->setWidget(dockWidgetContents);

        verticalLayout->addWidget(dockRennen);

        dockLog = new QDockWidget(centralwidget);
        dockLog->setObjectName(QString::fromUtf8("dockLog"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        gridLayout1 = new QGridLayout(dockWidgetContents_2);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        groupBox = new QGroupBox(dockWidgetContents_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout2 = new QGridLayout(groupBox);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        listWidget = new QListWidget(groupBox);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout2->addWidget(listWidget, 0, 0, 1, 1);

        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout2->addWidget(textEdit, 1, 0, 1, 1);


        gridLayout1->addWidget(groupBox, 0, 0, 1, 1);

        dockLog->setWidget(dockWidgetContents_2);

        verticalLayout->addWidget(dockLog);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout3 = new QGridLayout(groupBox_2);
        gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
        RanglistenTableView = new QTableView(groupBox_2);
        RanglistenTableView->setObjectName(QString::fromUtf8("RanglistenTableView"));
        RanglistenTableView->setMinimumSize(QSize(500, 0));

        gridLayout3->addWidget(RanglistenTableView, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 0, 1, 1, 1);

        BEO_TimingClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BEO_TimingClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 809, 21));
        menuDatei = new QMenu(menubar);
        menuDatei->setObjectName(QString::fromUtf8("menuDatei"));
        menuRennadministration = new QMenu(menubar);
        menuRennadministration->setObjectName(QString::fromUtf8("menuRennadministration"));
        menuHilfe = new QMenu(menubar);
        menuHilfe->setObjectName(QString::fromUtf8("menuHilfe"));
        menuVerbindungen = new QMenu(menubar);
        menuVerbindungen->setObjectName(QString::fromUtf8("menuVerbindungen"));
        menuBenutzerverwaltung = new QMenu(menubar);
        menuBenutzerverwaltung->setObjectName(QString::fromUtf8("menuBenutzerverwaltung"));
        menuAnsicht = new QMenu(menubar);
        menuAnsicht->setObjectName(QString::fromUtf8("menuAnsicht"));
        BEO_TimingClass->setMenuBar(menubar);
        statusbar = new QStatusBar(BEO_TimingClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        BEO_TimingClass->setStatusBar(statusbar);

        menubar->addAction(menuDatei->menuAction());
        menubar->addAction(menuAnsicht->menuAction());
        menubar->addAction(menuRennadministration->menuAction());
        menubar->addAction(menuBenutzerverwaltung->menuAction());
        menubar->addAction(menuVerbindungen->menuAction());
        menubar->addAction(menuHilfe->menuAction());
        menuDatei->addAction(actionAktualisieren);
        menuDatei->addAction(actionExportieren_als_CSV);
        menuDatei->addSeparator();
        menuDatei->addAction(actionBeenden);
        menuRennadministration->addAction(actionNeues_Rennen_erfassen);
        menuRennadministration->addAction(actionEintrag_Editieren);
        menuRennadministration->addSeparator();
        menuRennadministration->addAction(actionKonfiguration_erstellen);
        menuRennadministration->addAction(actionLog_Datei_auslesen);
        menuRennadministration->addSeparator();
        menuRennadministration->addAction(actionVerwaiste_Eintr_ge_entfernen);
        menuRennadministration->addAction(actionDatenbank_optimieren);
        menuHilfe->addAction(actionAbout);
        menuHilfe->addAction(actionAbout_Qt);
        menuVerbindungen->addAction(actionRFID_Leser_verbinden);
        menuVerbindungen->addAction(actionRFID_Leser);
        menuVerbindungen->addAction(actionDatenbank);
        menuVerbindungen->addSeparator();
        menuVerbindungen->addAction(actionKarten_zur_cksetzen_unpers_nlich);
        menuVerbindungen->addAction(actionKarten_zur_cksetzen_pers_nlich);
        menuVerbindungen->addSeparator();
        menuVerbindungen->addAction(actionNeue_Karten_initialisieren_unpers_nlich);
        menuVerbindungen->addAction(actionNeue_Karten_initialisieren_pers_nlich);
        menuVerbindungen->addSeparator();
        menuVerbindungen->addAction(actionEintragen_der_Karte_in_die_Datenbank);
        menuBenutzerverwaltung->addAction(actionNeuer_Benutzer_erstellen_3);
        menuBenutzerverwaltung->addAction(actionBenutzerrechte_ndern);
        menuBenutzerverwaltung->addAction(actionPasswort_ndern);
        menuBenutzerverwaltung->addSeparator();
        menuBenutzerverwaltung->addAction(actionKarte_registrieren);
        menuAnsicht->addAction(actionRennen);
        menuAnsicht->addAction(actionLog);

        retranslateUi(BEO_TimingClass);

        QMetaObject::connectSlotsByName(BEO_TimingClass);
    } // setupUi

    void retranslateUi(QMainWindow *BEO_TimingClass)
    {
        BEO_TimingClass->setWindowTitle(QApplication::translate("BEO_TimingClass", "MainWindow", 0));
        actionAktualisieren->setText(QApplication::translate("BEO_TimingClass", "Ansicht aktualisieren", 0));
        actionBeenden->setText(QApplication::translate("BEO_TimingClass", "Beenden", 0));
        actionNeues_Rennen_erfassen->setText(QApplication::translate("BEO_TimingClass", "Neues Rennen erfassen", 0));
        actionAbout->setText(QApplication::translate("BEO_TimingClass", "About", 0));
        actionEintrag_Editieren->setText(QApplication::translate("BEO_TimingClass", "Eintrag Editieren", 0));
        actionExportieren_als_CSV->setText(QApplication::translate("BEO_TimingClass", "Exportieren als CSV", 0));
        actionPasswort_ndern->setText(QApplication::translate("BEO_TimingClass", "Passwort \303\244ndern", 0));
        actionNeuer_Benutzer_erstellen->setText(QApplication::translate("BEO_TimingClass", "Neuer Benutzer erstellen", 0));
        actionNeuer_Benutzer_erstellen_2->setText(QApplication::translate("BEO_TimingClass", "Neuer Benutzer erstellen", 0));
        actionKonfiguration_erstellen->setText(QApplication::translate("BEO_TimingClass", "Konfiguration erstellen", 0));
        actionLog_Datei_auslesen->setText(QApplication::translate("BEO_TimingClass", "Log-Datei auslesen", 0));
        actionBenutzerrechte_ndern->setText(QApplication::translate("BEO_TimingClass", "Benutzerrechte \303\244ndern", 0));
        actionRFID_Leser->setText(QApplication::translate("BEO_TimingClass", "RFID-Leser Verbindung", 0));
        actionDatenbank->setText(QApplication::translate("BEO_TimingClass", "Datenbank", 0));
        actionAbout_Qt->setText(QApplication::translate("BEO_TimingClass", "About Qt", 0));
        actionVerwaiste_Eintr_ge_entfernen->setText(QApplication::translate("BEO_TimingClass", "Verwaiste Eintr\303\244ge entfernen", 0));
        actionDatenbank_optimieren->setText(QApplication::translate("BEO_TimingClass", "Datenbank optimieren", 0));
        actionNeuer_Benutzer_erstellen_3->setText(QApplication::translate("BEO_TimingClass", "Neuer Benutzer erstellen", 0));
        actionRFID_Leser_verbinden->setText(QApplication::translate("BEO_TimingClass", "RFID-Leser verbinden", 0));
        actionKarten_zur_cksetzen_unpers_nlich->setText(QApplication::translate("BEO_TimingClass", "Karten zur\303\274cksetzen (unpers\303\266nlich)", 0));
        actionKarten_zur_cksetzen_pers_nlich->setText(QApplication::translate("BEO_TimingClass", "Karten zur\303\274cksetzen (pers\303\266nlich)", 0));
        actionNeue_Karten_initialisieren_unpers_nlich->setText(QApplication::translate("BEO_TimingClass", "Neue Karten initialisieren (unpers\303\266nlich)", 0));
        actionNeue_Karten_initialisieren_pers_nlich->setText(QApplication::translate("BEO_TimingClass", "Neue Karten initialisieren (pers\303\266nlich)", 0));
        actionEintragen_der_Karte_in_die_Datenbank->setText(QApplication::translate("BEO_TimingClass", "Eintragen der Karte in die Datenbank", 0));
        actionKarte_registrieren->setText(QApplication::translate("BEO_TimingClass", "Karte registrieren", 0));
        actionRennen->setText(QApplication::translate("BEO_TimingClass", "Rennen Dock einblenden", 0));
        actionLog->setText(QApplication::translate("BEO_TimingClass", "Log Dock Einblenden", 0));
        QTreeWidgetItem *___qtreewidgetitem = RennenTreeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("BEO_TimingClass", "1", 0));
        groupBox->setTitle(QApplication::translate("BEO_TimingClass", "Log", 0));
        groupBox_2->setTitle(QApplication::translate("BEO_TimingClass", "Rangliste", 0));
        menuDatei->setTitle(QApplication::translate("BEO_TimingClass", "Datei", 0));
        menuRennadministration->setTitle(QApplication::translate("BEO_TimingClass", "Rennadministration", 0));
        menuHilfe->setTitle(QApplication::translate("BEO_TimingClass", "Hilfe", 0));
        menuVerbindungen->setTitle(QApplication::translate("BEO_TimingClass", "Verbindungen", 0));
        menuBenutzerverwaltung->setTitle(QApplication::translate("BEO_TimingClass", "Benutzerverwaltung", 0));
        menuAnsicht->setTitle(QApplication::translate("BEO_TimingClass", "Ansicht", 0));
    } // retranslateUi

};

namespace Ui {
    class BEO_TimingClass: public Ui_BEO_TimingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BEO_TIMING_H
