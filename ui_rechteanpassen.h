/********************************************************************************
** Form generated from reading ui file 'rechteanpassen.ui'
**
** Created: Tue 2. Sep 15:48:29 2008
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_RECHTEANPASSEN_H
#define UI_RECHTEANPASSEN_H

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
#include <QPushButton>
#include <QSpacerItem>
#include <QTreeWidget>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RechteAnpassenClass
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout1;
    QLabel *label;
    QComboBox *comboBox;
    QVBoxLayout *vboxLayout;
    QLabel *label_6;
    QLabel *label_7;
    QCheckBox *altCheckBox;
    QTreeWidget *streckenTreeWidget;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *canButton;

    void setupUi(QDialog *RechteAnpassenClass)
    {
    if (RechteAnpassenClass->objectName().isEmpty())
        RechteAnpassenClass->setObjectName(QString::fromUtf8("RechteAnpassenClass"));
    RechteAnpassenClass->resize(456, 326);
    gridLayout = new QGridLayout(RechteAnpassenClass);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(11);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    groupBox = new QGroupBox(RechteAnpassenClass);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    gridLayout1 = new QGridLayout(groupBox);
    gridLayout1->setSpacing(6);
    gridLayout1->setMargin(11);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    label = new QLabel(groupBox);
    label->setObjectName(QString::fromUtf8("label"));

    gridLayout1->addWidget(label, 0, 0, 1, 1);

    comboBox = new QComboBox(groupBox);
    comboBox->setObjectName(QString::fromUtf8("comboBox"));

    gridLayout1->addWidget(comboBox, 0, 1, 1, 1);

    vboxLayout = new QVBoxLayout();
    vboxLayout->setSpacing(6);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    label_6 = new QLabel(groupBox);
    label_6->setObjectName(QString::fromUtf8("label_6"));

    vboxLayout->addWidget(label_6);

    label_7 = new QLabel(groupBox);
    label_7->setObjectName(QString::fromUtf8("label_7"));

    vboxLayout->addWidget(label_7);

    altCheckBox = new QCheckBox(groupBox);
    altCheckBox->setObjectName(QString::fromUtf8("altCheckBox"));

    vboxLayout->addWidget(altCheckBox);


    gridLayout1->addLayout(vboxLayout, 1, 0, 1, 1);

    streckenTreeWidget = new QTreeWidget(groupBox);
    streckenTreeWidget->setObjectName(QString::fromUtf8("streckenTreeWidget"));

    gridLayout1->addWidget(streckenTreeWidget, 1, 1, 1, 1);


    gridLayout->addWidget(groupBox, 0, 0, 1, 1);

    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem);

    okButton = new QPushButton(RechteAnpassenClass);
    okButton->setObjectName(QString::fromUtf8("okButton"));

    hboxLayout->addWidget(okButton);

    canButton = new QPushButton(RechteAnpassenClass);
    canButton->setObjectName(QString::fromUtf8("canButton"));

    hboxLayout->addWidget(canButton);


    gridLayout->addLayout(hboxLayout, 1, 0, 1, 1);


    retranslateUi(RechteAnpassenClass);

    QMetaObject::connectSlotsByName(RechteAnpassenClass);
    } // setupUi

    void retranslateUi(QDialog *RechteAnpassenClass)
    {
    RechteAnpassenClass->setWindowTitle(QApplication::translate("RechteAnpassenClass", "RechteAnpassen", 0));
    groupBox->setTitle(QApplication::translate("RechteAnpassenClass", "Benutzerrechte \303\244ndern", 0));
    label->setText(QApplication::translate("RechteAnpassenClass", "Benutzer (ohne Administratoren):", 0));
    label_6->setText(QApplication::translate("RechteAnpassenClass", "neue Berechtigungen:", 0));
    label_7->setText(QApplication::translate("RechteAnpassenClass", "(mehrfachauswahl m\303\266glich)", 0));
    altCheckBox->setText(QApplication::translate("RechteAnpassenClass", "Alte Berechtigungen l\303\266schen", 0));
    streckenTreeWidget->headerItem()->setText(0, QApplication::translate("RechteAnpassenClass", "1", 0));
    okButton->setText(QApplication::translate("RechteAnpassenClass", "Ok", 0));
    canButton->setText(QApplication::translate("RechteAnpassenClass", "Abbrechen", 0));
    Q_UNUSED(RechteAnpassenClass);
    } // retranslateUi

};

namespace Ui {
    class RechteAnpassenClass: public Ui_RechteAnpassenClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECHTEANPASSEN_H
