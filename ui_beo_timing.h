/********************************************************************************
** Form generated from reading ui file 'beo_timing.ui'
**
** Created: Tue 2. Sep 15:48:29 2008
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_BEO_TIMING_H
#define UI_BEO_TIMING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

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
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *vboxLayout;
    QTreeWidget *RennenTreeWidget;
    QSpacerItem *spacerItem;
    QVBoxLayout *vboxLayout1;
    QTableView *RanglistenTableView;
    QSpacerItem *spacerItem1;
    QMenuBar *menubar;
    QMenu *menuDatei;
    QMenu *menuRennadministration;
    QMenu *menuHilfe;
    QMenu *menuVerbindungen;
    QMenu *menuBenutzerverwaltung;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BEO_TimingClass)
    {
    if (BEO_TimingClass->objectName().isEmpty())
        BEO_TimingClass->setObjectName(QString::fromUtf8("BEO_TimingClass"));
    BEO_TimingClass->resize(809, 593);
    actionAktualisieren = new QAction(BEO_TimingClass);
    actionAktualisieren->setObjectName(QString::fromUtf8("actionAktualisieren"));
    const QIcon icon = QIcon(QString::fromUtf8(":/images/reload.png"));
    actionAktualisieren->setIcon(icon);
    actionBeenden = new QAction(BEO_TimingClass);
    actionBeenden->setObjectName(QString::fromUtf8("actionBeenden"));
    const QIcon icon1 = QIcon(QString::fromUtf8(":/images/beenden.png"));
    actionBeenden->setIcon(icon1);
    actionNeues_Rennen_erfassen = new QAction(BEO_TimingClass);
    actionNeues_Rennen_erfassen->setObjectName(QString::fromUtf8("actionNeues_Rennen_erfassen"));
    const QIcon icon2 = QIcon(QString::fromUtf8(":/images/new.png"));
    actionNeues_Rennen_erfassen->setIcon(icon2);
    actionAbout = new QAction(BEO_TimingClass);
    actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
    const QIcon icon3 = QIcon(QString::fromUtf8(":/images/info.png"));
    actionAbout->setIcon(icon3);
    actionEintrag_Editieren = new QAction(BEO_TimingClass);
    actionEintrag_Editieren->setObjectName(QString::fromUtf8("actionEintrag_Editieren"));
    const QIcon icon4 = QIcon(QString::fromUtf8(":/images/b_edit.png"));
    actionEintrag_Editieren->setIcon(icon4);
    actionExportieren_als_CSV = new QAction(BEO_TimingClass);
    actionExportieren_als_CSV->setObjectName(QString::fromUtf8("actionExportieren_als_CSV"));
    const QIcon icon5 = QIcon(QString::fromUtf8(":/images/export.png"));
    actionExportieren_als_CSV->setIcon(icon5);
    actionPasswort_ndern = new QAction(BEO_TimingClass);
    actionPasswort_ndern->setObjectName(QString::fromUtf8("actionPasswort_ndern"));
    const QIcon icon6 = QIcon(QString::fromUtf8(":/images/pwd.png"));
    actionPasswort_ndern->setIcon(icon6);
    actionNeuer_Benutzer_erstellen = new QAction(BEO_TimingClass);
    actionNeuer_Benutzer_erstellen->setObjectName(QString::fromUtf8("actionNeuer_Benutzer_erstellen"));
    actionNeuer_Benutzer_erstellen_2 = new QAction(BEO_TimingClass);
    actionNeuer_Benutzer_erstellen_2->setObjectName(QString::fromUtf8("actionNeuer_Benutzer_erstellen_2"));
    actionKonfiguration_erstellen = new QAction(BEO_TimingClass);
    actionKonfiguration_erstellen->setObjectName(QString::fromUtf8("actionKonfiguration_erstellen"));
    const QIcon icon7 = QIcon(QString::fromUtf8(":/images/config.png"));
    actionKonfiguration_erstellen->setIcon(icon7);
    actionLog_Datei_auslesen = new QAction(BEO_TimingClass);
    actionLog_Datei_auslesen->setObjectName(QString::fromUtf8("actionLog_Datei_auslesen"));
    const QIcon icon8 = QIcon(QString::fromUtf8(":/images/log.png"));
    actionLog_Datei_auslesen->setIcon(icon8);
    actionBenutzerrechte_ndern = new QAction(BEO_TimingClass);
    actionBenutzerrechte_ndern->setObjectName(QString::fromUtf8("actionBenutzerrechte_ndern"));
    actionRFID_Leser = new QAction(BEO_TimingClass);
    actionRFID_Leser->setObjectName(QString::fromUtf8("actionRFID_Leser"));
    actionRFID_Leser->setCheckable(true);
    actionRFID_Leser->setChecked(true);
    const QIcon icon9 = QIcon(QString::fromUtf8(":/images/icon16_t.bmp"));
    actionRFID_Leser->setIcon(icon9);
    actionDatenbank = new QAction(BEO_TimingClass);
    actionDatenbank->setObjectName(QString::fromUtf8("actionDatenbank"));
    actionDatenbank->setCheckable(true);
    actionDatenbank->setChecked(true);
    actionDatenbank->setEnabled(false);
    actionAbout_Qt = new QAction(BEO_TimingClass);
    actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
    const QIcon icon10 = QIcon(QString::fromUtf8(":/images/qt.png"));
    actionAbout_Qt->setIcon(icon10);
    actionVerwaiste_Eintr_ge_entfernen = new QAction(BEO_TimingClass);
    actionVerwaiste_Eintr_ge_entfernen->setObjectName(QString::fromUtf8("actionVerwaiste_Eintr_ge_entfernen"));
    const QIcon icon11 = QIcon(QString::fromUtf8(":/images/papierkorb.png"));
    actionVerwaiste_Eintr_ge_entfernen->setIcon(icon11);
    actionDatenbank_optimieren = new QAction(BEO_TimingClass);
    actionDatenbank_optimieren->setObjectName(QString::fromUtf8("actionDatenbank_optimieren"));
    const QIcon icon12 = QIcon(QString::fromUtf8(":/images/optimieren.png"));
    actionDatenbank_optimieren->setIcon(icon12);
    actionNeuer_Benutzer_erstellen_3 = new QAction(BEO_TimingClass);
    actionNeuer_Benutzer_erstellen_3->setObjectName(QString::fromUtf8("actionNeuer_Benutzer_erstellen_3"));
    const QIcon icon13 = QIcon(QString::fromUtf8(":/images/newuser.png"));
    actionNeuer_Benutzer_erstellen_3->setIcon(icon13);
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
    centralwidget = new QWidget(BEO_TimingClass);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    gridLayout = new QGridLayout(centralwidget);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    vboxLayout = new QVBoxLayout();
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    RennenTreeWidget = new QTreeWidget(centralwidget);
    RennenTreeWidget->setObjectName(QString::fromUtf8("RennenTreeWidget"));

    vboxLayout->addWidget(RennenTreeWidget);

    spacerItem = new QSpacerItem(131, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    vboxLayout->addItem(spacerItem);


    gridLayout->addLayout(vboxLayout, 0, 0, 1, 1);

    vboxLayout1 = new QVBoxLayout();
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    RanglistenTableView = new QTableView(centralwidget);
    RanglistenTableView->setObjectName(QString::fromUtf8("RanglistenTableView"));

    vboxLayout1->addWidget(RanglistenTableView);

    spacerItem1 = new QSpacerItem(651, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    vboxLayout1->addItem(spacerItem1);


    gridLayout->addLayout(vboxLayout1, 0, 1, 1, 1);

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
    BEO_TimingClass->setMenuBar(menubar);
    statusbar = new QStatusBar(BEO_TimingClass);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    BEO_TimingClass->setStatusBar(statusbar);

    menubar->addAction(menuDatei->menuAction());
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
    menuBenutzerverwaltung->addAction(actionNeuer_Benutzer_erstellen_3);
    menuBenutzerverwaltung->addAction(actionBenutzerrechte_ndern);
    menuBenutzerverwaltung->addAction(actionPasswort_ndern);

    retranslateUi(BEO_TimingClass);

    QMetaObject::connectSlotsByName(BEO_TimingClass);
    } // setupUi

    void retranslateUi(QMainWindow *BEO_TimingClass)
    {
    BEO_TimingClass->setWindowTitle(QApplication::translate("BEO_TimingClass", "MainWindow", 0, QApplication::UnicodeUTF8));
    actionAktualisieren->setText(QApplication::translate("BEO_TimingClass", "Ansicht aktualisieren", 0, QApplication::UnicodeUTF8));
    actionBeenden->setText(QApplication::translate("BEO_TimingClass", "Beenden", 0, QApplication::UnicodeUTF8));
    actionNeues_Rennen_erfassen->setText(QApplication::translate("BEO_TimingClass", "Neues Rennen erfassen", 0, QApplication::UnicodeUTF8));
    actionAbout->setText(QApplication::translate("BEO_TimingClass", "About", 0, QApplication::UnicodeUTF8));
    actionEintrag_Editieren->setText(QApplication::translate("BEO_TimingClass", "Eintrag Editieren", 0, QApplication::UnicodeUTF8));
    actionExportieren_als_CSV->setText(QApplication::translate("BEO_TimingClass", "Exportieren als CSV", 0, QApplication::UnicodeUTF8));
    actionPasswort_ndern->setText(QApplication::translate("BEO_TimingClass", "Passwort \303\244ndern", 0, QApplication::UnicodeUTF8));
    actionNeuer_Benutzer_erstellen->setText(QApplication::translate("BEO_TimingClass", "Neuer Benutzer erstellen", 0, QApplication::UnicodeUTF8));
    actionNeuer_Benutzer_erstellen_2->setText(QApplication::translate("BEO_TimingClass", "Neuer Benutzer erstellen", 0, QApplication::UnicodeUTF8));
    actionKonfiguration_erstellen->setText(QApplication::translate("BEO_TimingClass", "Konfiguration erstellen", 0, QApplication::UnicodeUTF8));
    actionLog_Datei_auslesen->setText(QApplication::translate("BEO_TimingClass", "Log-Datei auslesen", 0, QApplication::UnicodeUTF8));
    actionBenutzerrechte_ndern->setText(QApplication::translate("BEO_TimingClass", "Benutzerrechte \303\244ndern", 0, QApplication::UnicodeUTF8));
    actionRFID_Leser->setText(QApplication::translate("BEO_TimingClass", "RFID-Leser Verbindung", 0, QApplication::UnicodeUTF8));
    actionDatenbank->setText(QApplication::translate("BEO_TimingClass", "Datenbank", 0, QApplication::UnicodeUTF8));
    actionAbout_Qt->setText(QApplication::translate("BEO_TimingClass", "About Qt", 0, QApplication::UnicodeUTF8));
    actionVerwaiste_Eintr_ge_entfernen->setText(QApplication::translate("BEO_TimingClass", "Verwaiste Eintr\303\244ge entfernen", 0, QApplication::UnicodeUTF8));
    actionDatenbank_optimieren->setText(QApplication::translate("BEO_TimingClass", "Datenbank optimieren", 0, QApplication::UnicodeUTF8));
    actionNeuer_Benutzer_erstellen_3->setText(QApplication::translate("BEO_TimingClass", "Neuer Benutzer erstellen", 0, QApplication::UnicodeUTF8));
    actionRFID_Leser_verbinden->setText(QApplication::translate("BEO_TimingClass", "RFID-Leser verbinden", 0, QApplication::UnicodeUTF8));
    actionKarten_zur_cksetzen_unpers_nlich->setText(QApplication::translate("BEO_TimingClass", "Karten zur\303\274cksetzen (unpers\303\266nlich)", 0, QApplication::UnicodeUTF8));
    actionKarten_zur_cksetzen_pers_nlich->setText(QApplication::translate("BEO_TimingClass", "Karten zur\303\274cksetzen (pers\303\266nlich)", 0, QApplication::UnicodeUTF8));
    actionNeue_Karten_initialisieren_unpers_nlich->setText(QApplication::translate("BEO_TimingClass", "Neue Karten initialisieren (unpers\303\266nlich)", 0, QApplication::UnicodeUTF8));
    actionNeue_Karten_initialisieren_pers_nlich->setText(QApplication::translate("BEO_TimingClass", "Neue Karten initialisieren (pers\303\266nlich)", 0, QApplication::UnicodeUTF8));
    RennenTreeWidget->headerItem()->setText(0, QApplication::translate("BEO_TimingClass", "1", 0, QApplication::UnicodeUTF8));
    menuDatei->setTitle(QApplication::translate("BEO_TimingClass", "Datei", 0, QApplication::UnicodeUTF8));
    menuRennadministration->setTitle(QApplication::translate("BEO_TimingClass", "Rennadministration", 0, QApplication::UnicodeUTF8));
    menuHilfe->setTitle(QApplication::translate("BEO_TimingClass", "Hilfe", 0, QApplication::UnicodeUTF8));
    menuVerbindungen->setTitle(QApplication::translate("BEO_TimingClass", "Verbindungen", 0, QApplication::UnicodeUTF8));
    menuBenutzerverwaltung->setTitle(QApplication::translate("BEO_TimingClass", "Benutzerverwaltung", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BEO_TimingClass: public Ui_BEO_TimingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BEO_TIMING_H
