/********************************************************************************
** Form generated from reading ui file 'hardwarekonfiguration.ui'
**
** Created: Tue 2. Sep 15:48:29 2008
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_HARDWAREKONFIGURATION_H
#define UI_HARDWAREKONFIGURATION_H

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
#include <QSpacerItem>
#include <QSpinBox>
#include <QTreeWidget>

QT_BEGIN_NAMESPACE

class Ui_HardwareKonfigurationClass
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout1;
    QLabel *label;
    QComboBox *stationComboBox;
    QLabel *Strecken;
    QTreeWidget *streckenTreeWidget;
    QHBoxLayout *hboxLayout;
    QCheckBox *gprsCheckBox;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout2;
    QLabel *label_3;
    QSpinBox *einSpinBox;
    QLabel *label_4;
    QSpinBox *ausSpinBox;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout3;
    QLabel *label_11;
    QLineEdit *smsLineEdit;
    QLabel *label_6;
    QLabel *ftpserverLabel;
    QLabel *label_7;
    QLabel *ftpuserLabel;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *canButton;

    void setupUi(QDialog *HardwareKonfigurationClass)
    {
    if (HardwareKonfigurationClass->objectName().isEmpty())
        HardwareKonfigurationClass->setObjectName(QString::fromUtf8("HardwareKonfigurationClass"));
    HardwareKonfigurationClass->resize(413, 472);
    gridLayout = new QGridLayout(HardwareKonfigurationClass);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(11);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    groupBox = new QGroupBox(HardwareKonfigurationClass);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    gridLayout1 = new QGridLayout(groupBox);
    gridLayout1->setSpacing(6);
    gridLayout1->setMargin(11);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    label = new QLabel(groupBox);
    label->setObjectName(QString::fromUtf8("label"));

    gridLayout1->addWidget(label, 0, 0, 1, 1);

    stationComboBox = new QComboBox(groupBox);
    stationComboBox->setObjectName(QString::fromUtf8("stationComboBox"));

    gridLayout1->addWidget(stationComboBox, 0, 1, 1, 1);

    Strecken = new QLabel(groupBox);
    Strecken->setObjectName(QString::fromUtf8("Strecken"));

    gridLayout1->addWidget(Strecken, 1, 0, 1, 1);

    streckenTreeWidget = new QTreeWidget(groupBox);
    streckenTreeWidget->setObjectName(QString::fromUtf8("streckenTreeWidget"));

    gridLayout1->addWidget(streckenTreeWidget, 1, 1, 1, 1);

    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    gprsCheckBox = new QCheckBox(groupBox);
    gprsCheckBox->setObjectName(QString::fromUtf8("gprsCheckBox"));
    gprsCheckBox->setChecked(true);

    hboxLayout->addWidget(gprsCheckBox);


    gridLayout1->addLayout(hboxLayout, 2, 1, 1, 1);


    gridLayout->addWidget(groupBox, 0, 0, 1, 1);

    groupBox_3 = new QGroupBox(HardwareKonfigurationClass);
    groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
    gridLayout2 = new QGridLayout(groupBox_3);
    gridLayout2->setSpacing(6);
    gridLayout2->setMargin(11);
    gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
    label_3 = new QLabel(groupBox_3);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    gridLayout2->addWidget(label_3, 0, 0, 1, 1);

    einSpinBox = new QSpinBox(groupBox_3);
    einSpinBox->setObjectName(QString::fromUtf8("einSpinBox"));
    einSpinBox->setValue(6);

    gridLayout2->addWidget(einSpinBox, 0, 1, 1, 1);

    label_4 = new QLabel(groupBox_3);
    label_4->setObjectName(QString::fromUtf8("label_4"));

    gridLayout2->addWidget(label_4, 0, 2, 1, 1);

    ausSpinBox = new QSpinBox(groupBox_3);
    ausSpinBox->setObjectName(QString::fromUtf8("ausSpinBox"));
    ausSpinBox->setMaximum(23);

    gridLayout2->addWidget(ausSpinBox, 0, 3, 1, 1);


    gridLayout->addWidget(groupBox_3, 1, 0, 1, 1);

    groupBox_2 = new QGroupBox(HardwareKonfigurationClass);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    gridLayout3 = new QGridLayout(groupBox_2);
    gridLayout3->setSpacing(6);
    gridLayout3->setMargin(11);
    gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
    label_11 = new QLabel(groupBox_2);
    label_11->setObjectName(QString::fromUtf8("label_11"));

    gridLayout3->addWidget(label_11, 0, 0, 1, 1);

    smsLineEdit = new QLineEdit(groupBox_2);
    smsLineEdit->setObjectName(QString::fromUtf8("smsLineEdit"));

    gridLayout3->addWidget(smsLineEdit, 0, 1, 1, 1);

    label_6 = new QLabel(groupBox_2);
    label_6->setObjectName(QString::fromUtf8("label_6"));

    gridLayout3->addWidget(label_6, 1, 0, 1, 1);

    ftpserverLabel = new QLabel(groupBox_2);
    ftpserverLabel->setObjectName(QString::fromUtf8("ftpserverLabel"));

    gridLayout3->addWidget(ftpserverLabel, 1, 1, 1, 1);

    label_7 = new QLabel(groupBox_2);
    label_7->setObjectName(QString::fromUtf8("label_7"));

    gridLayout3->addWidget(label_7, 2, 0, 1, 1);

    ftpuserLabel = new QLabel(groupBox_2);
    ftpuserLabel->setObjectName(QString::fromUtf8("ftpuserLabel"));

    gridLayout3->addWidget(ftpuserLabel, 2, 1, 1, 1);


    gridLayout->addWidget(groupBox_2, 2, 0, 1, 1);

    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setSpacing(6);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout1->addItem(spacerItem);

    okButton = new QPushButton(HardwareKonfigurationClass);
    okButton->setObjectName(QString::fromUtf8("okButton"));

    hboxLayout1->addWidget(okButton);

    canButton = new QPushButton(HardwareKonfigurationClass);
    canButton->setObjectName(QString::fromUtf8("canButton"));

    hboxLayout1->addWidget(canButton);


    gridLayout->addLayout(hboxLayout1, 3, 0, 1, 1);


    retranslateUi(HardwareKonfigurationClass);

    QMetaObject::connectSlotsByName(HardwareKonfigurationClass);
    } // setupUi

    void retranslateUi(QDialog *HardwareKonfigurationClass)
    {
    HardwareKonfigurationClass->setWindowTitle(QApplication::translate("HardwareKonfigurationClass", "HardwareKonfiguration", 0));
    groupBox->setTitle(QApplication::translate("HardwareKonfigurationClass", "Allgemein", 0));
    label->setText(QApplication::translate("HardwareKonfigurationClass", "Station Nr.:", 0));
    Strecken->setText(QApplication::translate("HardwareKonfigurationClass", "Strecken: ", 0));
    streckenTreeWidget->headerItem()->setText(0, QApplication::translate("HardwareKonfigurationClass", "1", 0));
    gprsCheckBox->setText(QApplication::translate("HardwareKonfigurationClass", "Verwende GPRS", 0));
    groupBox_3->setTitle(QApplication::translate("HardwareKonfigurationClass", "Energiesparoptionen", 0));
    label_3->setText(QApplication::translate("HardwareKonfigurationClass", "Einschaltzeit (Stunde):", 0));
    label_4->setText(QApplication::translate("HardwareKonfigurationClass", "Ausschaltzeit (Stunde):", 0));
    groupBox_2->setTitle(QApplication::translate("HardwareKonfigurationClass", "Verbindungsdaten", 0));
    label_11->setText(QApplication::translate("HardwareKonfigurationClass", "Nummer f\303\274r SMS:", 0));
    label_6->setText(QApplication::translate("HardwareKonfigurationClass", "FTP-Server:", 0));
    ftpserverLabel->setText(QApplication::translate("HardwareKonfigurationClass", "<ftp.xy.com>", 0));
    label_7->setText(QApplication::translate("HardwareKonfigurationClass", "FTP-User:", 0));
    ftpuserLabel->setText(QApplication::translate("HardwareKonfigurationClass", "<xy@xy.com>", 0));
    okButton->setText(QApplication::translate("HardwareKonfigurationClass", "Ok", 0));
    canButton->setText(QApplication::translate("HardwareKonfigurationClass", "Abbrechen", 0));
    Q_UNUSED(HardwareKonfigurationClass);
    } // retranslateUi

};

namespace Ui {
    class HardwareKonfigurationClass: public Ui_HardwareKonfigurationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HARDWAREKONFIGURATION_H
