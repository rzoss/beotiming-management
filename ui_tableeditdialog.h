/********************************************************************************
** Form generated from reading ui file 'tableeditdialog.ui'
**
** Created: Tue 2. Sep 15:48:29 2008
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_TABLEEDITDIALOG_H
#define UI_TABLEEDITDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_TableEditDialogClass
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout1;
    QTableView *KontaktdatenTable;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout2;
    QTableView *ResultateTable;
    QHBoxLayout *hboxLayout;
    QPushButton *BestaetigenButton;
    QPushButton *loeschenButton;
    QSpacerItem *spacerItem;
    QPushButton *VerwerfenButton;

    void setupUi(QDialog *TableEditDialogClass)
    {
    if (TableEditDialogClass->objectName().isEmpty())
        TableEditDialogClass->setObjectName(QString::fromUtf8("TableEditDialogClass"));
    TableEditDialogClass->resize(670, 343);
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(TableEditDialogClass->sizePolicy().hasHeightForWidth());
    TableEditDialogClass->setSizePolicy(sizePolicy);
    gridLayout = new QGridLayout(TableEditDialogClass);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(11);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    groupBox = new QGroupBox(TableEditDialogClass);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    gridLayout1 = new QGridLayout(groupBox);
    gridLayout1->setSpacing(6);
    gridLayout1->setMargin(11);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    KontaktdatenTable = new QTableView(groupBox);
    KontaktdatenTable->setObjectName(QString::fromUtf8("KontaktdatenTable"));

    gridLayout1->addWidget(KontaktdatenTable, 0, 0, 1, 1);


    gridLayout->addWidget(groupBox, 0, 0, 1, 1);

    groupBox_2 = new QGroupBox(TableEditDialogClass);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    gridLayout2 = new QGridLayout(groupBox_2);
    gridLayout2->setSpacing(6);
    gridLayout2->setMargin(11);
    gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
    ResultateTable = new QTableView(groupBox_2);
    ResultateTable->setObjectName(QString::fromUtf8("ResultateTable"));

    gridLayout2->addWidget(ResultateTable, 0, 0, 1, 1);


    gridLayout->addWidget(groupBox_2, 1, 0, 1, 1);

    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    BestaetigenButton = new QPushButton(TableEditDialogClass);
    BestaetigenButton->setObjectName(QString::fromUtf8("BestaetigenButton"));

    hboxLayout->addWidget(BestaetigenButton);

    loeschenButton = new QPushButton(TableEditDialogClass);
    loeschenButton->setObjectName(QString::fromUtf8("loeschenButton"));

    hboxLayout->addWidget(loeschenButton);

    spacerItem = new QSpacerItem(281, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem);

    VerwerfenButton = new QPushButton(TableEditDialogClass);
    VerwerfenButton->setObjectName(QString::fromUtf8("VerwerfenButton"));

    hboxLayout->addWidget(VerwerfenButton);


    gridLayout->addLayout(hboxLayout, 2, 0, 1, 1);


    retranslateUi(TableEditDialogClass);

    QMetaObject::connectSlotsByName(TableEditDialogClass);
    } // setupUi

    void retranslateUi(QDialog *TableEditDialogClass)
    {
    TableEditDialogClass->setWindowTitle(QApplication::translate("TableEditDialogClass", "TableEditDialog", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("TableEditDialogClass", "Kontaktdaten", 0, QApplication::UnicodeUTF8));
    groupBox_2->setTitle(QApplication::translate("TableEditDialogClass", "Resultate", 0, QApplication::UnicodeUTF8));
    BestaetigenButton->setText(QApplication::translate("TableEditDialogClass", "\303\204nderungen speichern", 0, QApplication::UnicodeUTF8));
    loeschenButton->setText(QApplication::translate("TableEditDialogClass", "Eintrag l\303\266schen", 0, QApplication::UnicodeUTF8));
    VerwerfenButton->setText(QApplication::translate("TableEditDialogClass", "Schliessen", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(TableEditDialogClass);
    } // retranslateUi

};

namespace Ui {
    class TableEditDialogClass: public Ui_TableEditDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEEDITDIALOG_H
