/********************************************************************************
** Form generated from reading ui file 'rfidinputdialog.ui'
**
** Created: Tue 2. Sep 15:48:29 2008
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_RFIDINPUTDIALOG_H
#define UI_RFIDINPUTDIALOG_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QCheckBox>
#include <QComboBox>
#include <QDialog>
#include <QGridLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QSpacerItem>
#include <QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_RFIDInputDialogClass
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupRenndaten;
    QGridLayout *gridLayout;
    QLabel *StarttimeLabel;
    QLabel *EndtimeLabel;
    QLabel *FahrzeitLabel;
    QLabel *rfidsnrLabel;
    QLabel *StreckennameLabel;
    QLabel *StreckenTypLabel;
    QLabel *label_14;
    QComboBox *KategoriecomboBox;
    QGroupBox *groupBox;
    QGridLayout *gridLayout1;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QLabel *label_2;
    QLineEdit *vornameLineEdit;
    QLabel *label_3;
    QLineEdit *adresseLineEdit;
    QSpacerItem *spacerItem;
    QRadioButton *maenlichRadioButton;
    QRadioButton *weiblichRadioButton;
    QLabel *label_4;
    QLineEdit *plzLineEdit;
    QLabel *label_5;
    QLineEdit *ortLineEdit;
    QLabel *label_6;
    QComboBox *nationalitaetComboBox;
    QLabel *label_11;
    QLabel *label_8;
    QLineEdit *telephonLineEdit;
    QLabel *label_9;
    QLineEdit *mobileLineEdit;
    QLabel *label_10;
    QLineEdit *emailLineEdit;
    QLabel *label_7;
    QLineEdit *clubLineEdit;
    QSpinBox *jahrgangSpinBox;
    QGridLayout *gridLayout2;
    QCheckBox *autoCheckBox;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *spacerItem1;
    QPushButton *okButton;
    QPushButton *canButton;

    void setupUi(QDialog *RFIDInputDialogClass)
    {
    if (RFIDInputDialogClass->objectName().isEmpty())
        RFIDInputDialogClass->setObjectName(QString::fromUtf8("RFIDInputDialogClass"));
    RFIDInputDialogClass->resize(423, 389);
    gridLayout_2 = new QGridLayout(RFIDInputDialogClass);
    gridLayout_2->setSpacing(6);
    gridLayout_2->setMargin(11);
    gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
    groupRenndaten = new QGroupBox(RFIDInputDialogClass);
    groupRenndaten->setObjectName(QString::fromUtf8("groupRenndaten"));
    gridLayout = new QGridLayout(groupRenndaten);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(11);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    StarttimeLabel = new QLabel(groupRenndaten);
    StarttimeLabel->setObjectName(QString::fromUtf8("StarttimeLabel"));

    gridLayout->addWidget(StarttimeLabel, 0, 0, 1, 1);

    EndtimeLabel = new QLabel(groupRenndaten);
    EndtimeLabel->setObjectName(QString::fromUtf8("EndtimeLabel"));

    gridLayout->addWidget(EndtimeLabel, 0, 1, 1, 1);

    FahrzeitLabel = new QLabel(groupRenndaten);
    FahrzeitLabel->setObjectName(QString::fromUtf8("FahrzeitLabel"));

    gridLayout->addWidget(FahrzeitLabel, 1, 0, 1, 1);

    rfidsnrLabel = new QLabel(groupRenndaten);
    rfidsnrLabel->setObjectName(QString::fromUtf8("rfidsnrLabel"));

    gridLayout->addWidget(rfidsnrLabel, 1, 1, 1, 1);

    StreckennameLabel = new QLabel(groupRenndaten);
    StreckennameLabel->setObjectName(QString::fromUtf8("StreckennameLabel"));

    gridLayout->addWidget(StreckennameLabel, 2, 0, 1, 1);

    StreckenTypLabel = new QLabel(groupRenndaten);
    StreckenTypLabel->setObjectName(QString::fromUtf8("StreckenTypLabel"));

    gridLayout->addWidget(StreckenTypLabel, 2, 1, 1, 1);

    label_14 = new QLabel(groupRenndaten);
    label_14->setObjectName(QString::fromUtf8("label_14"));

    gridLayout->addWidget(label_14, 3, 0, 1, 1);

    KategoriecomboBox = new QComboBox(groupRenndaten);
    KategoriecomboBox->setObjectName(QString::fromUtf8("KategoriecomboBox"));

    gridLayout->addWidget(KategoriecomboBox, 3, 1, 1, 1);


    gridLayout_2->addWidget(groupRenndaten, 0, 0, 1, 1);

    groupBox = new QGroupBox(RFIDInputDialogClass);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    gridLayout1 = new QGridLayout(groupBox);
    gridLayout1->setSpacing(6);
    gridLayout1->setMargin(11);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    label = new QLabel(groupBox);
    label->setObjectName(QString::fromUtf8("label"));

    gridLayout1->addWidget(label, 0, 0, 1, 1);

    nameLineEdit = new QLineEdit(groupBox);
    nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));

    gridLayout1->addWidget(nameLineEdit, 0, 1, 1, 1);

    label_2 = new QLabel(groupBox);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    gridLayout1->addWidget(label_2, 0, 2, 1, 2);

    vornameLineEdit = new QLineEdit(groupBox);
    vornameLineEdit->setObjectName(QString::fromUtf8("vornameLineEdit"));

    gridLayout1->addWidget(vornameLineEdit, 0, 4, 1, 2);

    label_3 = new QLabel(groupBox);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    gridLayout1->addWidget(label_3, 1, 0, 1, 1);

    adresseLineEdit = new QLineEdit(groupBox);
    adresseLineEdit->setObjectName(QString::fromUtf8("adresseLineEdit"));

    gridLayout1->addWidget(adresseLineEdit, 1, 1, 1, 1);

    spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout1->addItem(spacerItem, 1, 2, 1, 1);

    maenlichRadioButton = new QRadioButton(groupBox);
    maenlichRadioButton->setObjectName(QString::fromUtf8("maenlichRadioButton"));

    gridLayout1->addWidget(maenlichRadioButton, 1, 3, 1, 2);

    weiblichRadioButton = new QRadioButton(groupBox);
    weiblichRadioButton->setObjectName(QString::fromUtf8("weiblichRadioButton"));

    gridLayout1->addWidget(weiblichRadioButton, 1, 5, 1, 1);

    label_4 = new QLabel(groupBox);
    label_4->setObjectName(QString::fromUtf8("label_4"));

    gridLayout1->addWidget(label_4, 2, 0, 1, 1);

    plzLineEdit = new QLineEdit(groupBox);
    plzLineEdit->setObjectName(QString::fromUtf8("plzLineEdit"));

    gridLayout1->addWidget(plzLineEdit, 2, 1, 1, 1);

    label_5 = new QLabel(groupBox);
    label_5->setObjectName(QString::fromUtf8("label_5"));

    gridLayout1->addWidget(label_5, 2, 2, 1, 2);

    ortLineEdit = new QLineEdit(groupBox);
    ortLineEdit->setObjectName(QString::fromUtf8("ortLineEdit"));

    gridLayout1->addWidget(ortLineEdit, 2, 4, 1, 2);

    label_6 = new QLabel(groupBox);
    label_6->setObjectName(QString::fromUtf8("label_6"));

    gridLayout1->addWidget(label_6, 3, 0, 1, 1);

    nationalitaetComboBox = new QComboBox(groupBox);
    nationalitaetComboBox->setObjectName(QString::fromUtf8("nationalitaetComboBox"));
    nationalitaetComboBox->setAutoFillBackground(false);
    nationalitaetComboBox->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);

    gridLayout1->addWidget(nationalitaetComboBox, 3, 1, 1, 1);

    label_11 = new QLabel(groupBox);
    label_11->setObjectName(QString::fromUtf8("label_11"));

    gridLayout1->addWidget(label_11, 3, 2, 1, 2);

    label_8 = new QLabel(groupBox);
    label_8->setObjectName(QString::fromUtf8("label_8"));

    gridLayout1->addWidget(label_8, 4, 0, 1, 1);

    telephonLineEdit = new QLineEdit(groupBox);
    telephonLineEdit->setObjectName(QString::fromUtf8("telephonLineEdit"));

    gridLayout1->addWidget(telephonLineEdit, 4, 1, 1, 1);

    label_9 = new QLabel(groupBox);
    label_9->setObjectName(QString::fromUtf8("label_9"));

    gridLayout1->addWidget(label_9, 4, 2, 1, 2);

    mobileLineEdit = new QLineEdit(groupBox);
    mobileLineEdit->setObjectName(QString::fromUtf8("mobileLineEdit"));

    gridLayout1->addWidget(mobileLineEdit, 4, 4, 1, 2);

    label_10 = new QLabel(groupBox);
    label_10->setObjectName(QString::fromUtf8("label_10"));

    gridLayout1->addWidget(label_10, 5, 0, 1, 1);

    emailLineEdit = new QLineEdit(groupBox);
    emailLineEdit->setObjectName(QString::fromUtf8("emailLineEdit"));

    gridLayout1->addWidget(emailLineEdit, 5, 1, 1, 1);

    label_7 = new QLabel(groupBox);
    label_7->setObjectName(QString::fromUtf8("label_7"));

    gridLayout1->addWidget(label_7, 5, 2, 1, 2);

    clubLineEdit = new QLineEdit(groupBox);
    clubLineEdit->setObjectName(QString::fromUtf8("clubLineEdit"));

    gridLayout1->addWidget(clubLineEdit, 5, 4, 1, 2);

    jahrgangSpinBox = new QSpinBox(groupBox);
    jahrgangSpinBox->setObjectName(QString::fromUtf8("jahrgangSpinBox"));
    jahrgangSpinBox->setMinimum(1900);
    jahrgangSpinBox->setMaximum(2050);
    jahrgangSpinBox->setValue(1980);

    gridLayout1->addWidget(jahrgangSpinBox, 3, 4, 1, 2);


    gridLayout_2->addWidget(groupBox, 1, 0, 1, 1);

    gridLayout2 = new QGridLayout();
    gridLayout2->setSpacing(6);
    gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
    autoCheckBox = new QCheckBox(RFIDInputDialogClass);
    autoCheckBox->setObjectName(QString::fromUtf8("autoCheckBox"));
    autoCheckBox->setChecked(true);
    autoCheckBox->setTristate(false);

    gridLayout2->addWidget(autoCheckBox, 0, 0, 1, 1);

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setSpacing(6);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    spacerItem1 = new QSpacerItem(234, 28, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout->addItem(spacerItem1);

    okButton = new QPushButton(RFIDInputDialogClass);
    okButton->setObjectName(QString::fromUtf8("okButton"));

    horizontalLayout->addWidget(okButton);

    canButton = new QPushButton(RFIDInputDialogClass);
    canButton->setObjectName(QString::fromUtf8("canButton"));

    horizontalLayout->addWidget(canButton);


    gridLayout2->addLayout(horizontalLayout, 1, 0, 1, 1);


    gridLayout_2->addLayout(gridLayout2, 2, 0, 1, 1);


    retranslateUi(RFIDInputDialogClass);

    QMetaObject::connectSlotsByName(RFIDInputDialogClass);
    } // setupUi

    void retranslateUi(QDialog *RFIDInputDialogClass)
    {
    RFIDInputDialogClass->setWindowTitle(QApplication::translate("RFIDInputDialogClass", "RFIDInputDialog", 0));
    groupRenndaten->setTitle(QApplication::translate("RFIDInputDialogClass", "Renndaten", 0));

#ifndef QT_NO_WHATSTHIS
    StarttimeLabel->setWhatsThis(QApplication::translate("RFIDInputDialogClass", "Startzeit", 0));
#endif // QT_NO_WHATSTHIS

    StarttimeLabel->setText(QApplication::translate("RFIDInputDialogClass", "<Starttime>", 0));

#ifndef QT_NO_WHATSTHIS
    EndtimeLabel->setWhatsThis(QApplication::translate("RFIDInputDialogClass", "Endzeit", 0));
#endif // QT_NO_WHATSTHIS

    EndtimeLabel->setText(QApplication::translate("RFIDInputDialogClass", "<Endtime>", 0));

#ifndef QT_NO_WHATSTHIS
    FahrzeitLabel->setWhatsThis(QApplication::translate("RFIDInputDialogClass", "Fahrzeit", 0));
#endif // QT_NO_WHATSTHIS

    FahrzeitLabel->setText(QApplication::translate("RFIDInputDialogClass", "<Racetime>", 0));

#ifndef QT_NO_WHATSTHIS
    rfidsnrLabel->setWhatsThis(QApplication::translate("RFIDInputDialogClass", "Seriennummer der RFID-Karte", 0));
#endif // QT_NO_WHATSTHIS

    rfidsnrLabel->setText(QApplication::translate("RFIDInputDialogClass", "<RFID_SNR>", 0));
    StreckennameLabel->setText(QApplication::translate("RFIDInputDialogClass", "<StreckenName>", 0));
    StreckenTypLabel->setText(QApplication::translate("RFIDInputDialogClass", "<SteckenTyp>", 0));
    label_14->setText(QApplication::translate("RFIDInputDialogClass", "Kategorie:", 0));
    groupBox->setTitle(QApplication::translate("RFIDInputDialogClass", "Kontaktdaten", 0));
    label->setText(QApplication::translate("RFIDInputDialogClass", "Name:", 0));

#ifndef QT_NO_WHATSTHIS
    nameLineEdit->setWhatsThis(QApplication::translate("RFIDInputDialogClass", "Name des Teilnehmers", 0));
#endif // QT_NO_WHATSTHIS

    label_2->setText(QApplication::translate("RFIDInputDialogClass", "Vorname:", 0));

#ifndef QT_NO_WHATSTHIS
    vornameLineEdit->setWhatsThis(QApplication::translate("RFIDInputDialogClass", "Vorname des Teilnehmers", 0));
#endif // QT_NO_WHATSTHIS

    label_3->setText(QApplication::translate("RFIDInputDialogClass", "Adresse:", 0));

#ifndef QT_NO_WHATSTHIS
    adresseLineEdit->setWhatsThis(QApplication::translate("RFIDInputDialogClass", "Adresse des Teilnehmers", 0));
#endif // QT_NO_WHATSTHIS

    maenlichRadioButton->setText(QApplication::translate("RFIDInputDialogClass", "M\303\244nnlich", 0));
    weiblichRadioButton->setText(QApplication::translate("RFIDInputDialogClass", "Weiblich", 0));
    label_4->setText(QApplication::translate("RFIDInputDialogClass", "PLZ:", 0));

#ifndef QT_NO_WHATSTHIS
    plzLineEdit->setWhatsThis(QApplication::translate("RFIDInputDialogClass", "Postleitzahl des Teilnehmers", 0));
#endif // QT_NO_WHATSTHIS

    label_5->setText(QApplication::translate("RFIDInputDialogClass", "Wohnort:", 0));

#ifndef QT_NO_WHATSTHIS
    ortLineEdit->setWhatsThis(QApplication::translate("RFIDInputDialogClass", "Wohnort des Teilnehmers", 0));
#endif // QT_NO_WHATSTHIS

    label_6->setText(QApplication::translate("RFIDInputDialogClass", "Nationalit\303\244t:", 0));

#ifndef QT_NO_WHATSTHIS
    nationalitaetComboBox->setWhatsThis(QApplication::translate("RFIDInputDialogClass", "Liste der Nationalit\303\244ten", 0));
#endif // QT_NO_WHATSTHIS

    label_11->setText(QApplication::translate("RFIDInputDialogClass", "Jahrgang:", 0));
    label_8->setText(QApplication::translate("RFIDInputDialogClass", "Telefon:", 0));

#ifndef QT_NO_WHATSTHIS
    telephonLineEdit->setWhatsThis(QApplication::translate("RFIDInputDialogClass", "Telefon des Teilnehmers", 0));
#endif // QT_NO_WHATSTHIS

    label_9->setText(QApplication::translate("RFIDInputDialogClass", "Mobile:", 0));

#ifndef QT_NO_WHATSTHIS
    mobileLineEdit->setWhatsThis(QApplication::translate("RFIDInputDialogClass", "Mobile des Teilnehmers", 0));
#endif // QT_NO_WHATSTHIS

    label_10->setText(QApplication::translate("RFIDInputDialogClass", "Email:", 0));

#ifndef QT_NO_WHATSTHIS
    emailLineEdit->setWhatsThis(QApplication::translate("RFIDInputDialogClass", "Email des Teilnehmers", 0));
#endif // QT_NO_WHATSTHIS

    label_7->setText(QApplication::translate("RFIDInputDialogClass", "Team / Club:", 0));

#ifndef QT_NO_WHATSTHIS
    clubLineEdit->setWhatsThis(QApplication::translate("RFIDInputDialogClass", "Team / Club des Teilnehmers", 0));
#endif // QT_NO_WHATSTHIS

    autoCheckBox->setText(QApplication::translate("RFIDInputDialogClass", "automatisches Vervollst\303\244ndigen (Standardm\303\244ssig aktiviert)", 0));

#ifndef QT_NO_WHATSTHIS
    okButton->setWhatsThis(QApplication::translate("RFIDInputDialogClass", "Mit Ok werden die Information zur Datenbank hinzugef\303\274gt", 0));
#endif // QT_NO_WHATSTHIS

    okButton->setText(QApplication::translate("RFIDInputDialogClass", "Ok", 0));

#ifndef QT_NO_WHATSTHIS
    canButton->setWhatsThis(QApplication::translate("RFIDInputDialogClass", "Verl\303\244sst diesen Dialog ohne \303\204nderungen", 0));
#endif // QT_NO_WHATSTHIS

    canButton->setText(QApplication::translate("RFIDInputDialogClass", "Abbrechen", 0));
    Q_UNUSED(RFIDInputDialogClass);
    } // retranslateUi

};

namespace Ui {
    class RFIDInputDialogClass: public Ui_RFIDInputDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RFIDINPUTDIALOG_H
