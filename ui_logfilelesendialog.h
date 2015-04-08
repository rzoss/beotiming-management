/********************************************************************************
** Form generated from reading ui file 'logfilelesendialog.ui'
**
** Created: Tue 2. Sep 15:48:29 2008
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_LOGFILELESENDIALOG_H
#define UI_LOGFILELESENDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_LogfileLesenDialogClass
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout1;
    QListWidget *neuListWidget;
    QCheckBox *neuCheckBox;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout2;
    QListWidget *delListWidget;
    QCheckBox *delCheckBox;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *canButton;

    void setupUi(QDialog *LogfileLesenDialogClass)
    {
    if (LogfileLesenDialogClass->objectName().isEmpty())
        LogfileLesenDialogClass->setObjectName(QString::fromUtf8("LogfileLesenDialogClass"));
    LogfileLesenDialogClass->resize(402, 389);
    gridLayout = new QGridLayout(LogfileLesenDialogClass);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(11);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    groupBox = new QGroupBox(LogfileLesenDialogClass);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    gridLayout1 = new QGridLayout(groupBox);
    gridLayout1->setSpacing(6);
    gridLayout1->setMargin(11);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    neuListWidget = new QListWidget(groupBox);
    neuListWidget->setObjectName(QString::fromUtf8("neuListWidget"));

    gridLayout1->addWidget(neuListWidget, 0, 0, 1, 1);

    neuCheckBox = new QCheckBox(groupBox);
    neuCheckBox->setObjectName(QString::fromUtf8("neuCheckBox"));

    gridLayout1->addWidget(neuCheckBox, 1, 0, 1, 1);


    gridLayout->addWidget(groupBox, 0, 0, 1, 1);

    groupBox_2 = new QGroupBox(LogfileLesenDialogClass);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    gridLayout2 = new QGridLayout(groupBox_2);
    gridLayout2->setSpacing(6);
    gridLayout2->setMargin(11);
    gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
    delListWidget = new QListWidget(groupBox_2);
    delListWidget->setObjectName(QString::fromUtf8("delListWidget"));

    gridLayout2->addWidget(delListWidget, 0, 0, 1, 1);

    delCheckBox = new QCheckBox(groupBox_2);
    delCheckBox->setObjectName(QString::fromUtf8("delCheckBox"));

    gridLayout2->addWidget(delCheckBox, 1, 0, 1, 1);


    gridLayout->addWidget(groupBox_2, 1, 0, 1, 1);

    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem);

    okButton = new QPushButton(LogfileLesenDialogClass);
    okButton->setObjectName(QString::fromUtf8("okButton"));

    hboxLayout->addWidget(okButton);

    canButton = new QPushButton(LogfileLesenDialogClass);
    canButton->setObjectName(QString::fromUtf8("canButton"));

    hboxLayout->addWidget(canButton);


    gridLayout->addLayout(hboxLayout, 2, 0, 1, 1);


    retranslateUi(LogfileLesenDialogClass);

    QMetaObject::connectSlotsByName(LogfileLesenDialogClass);
    } // setupUi

    void retranslateUi(QDialog *LogfileLesenDialogClass)
    {
    LogfileLesenDialogClass->setWindowTitle(QApplication::translate("LogfileLesenDialogClass", "LogfileLesenDialog", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("LogfileLesenDialogClass", "Neue Zeiten", 0, QApplication::UnicodeUTF8));
    neuCheckBox->setText(QApplication::translate("LogfileLesenDialogClass", "Alle Zeiten ausw\303\244hlen", 0, QApplication::UnicodeUTF8));
    groupBox_2->setTitle(QApplication::translate("LogfileLesenDialogClass", "Zu l\303\266schende Zeiten", 0, QApplication::UnicodeUTF8));
    delCheckBox->setText(QApplication::translate("LogfileLesenDialogClass", "Alle Zeiten ausw\303\244hlen", 0, QApplication::UnicodeUTF8));
    okButton->setText(QApplication::translate("LogfileLesenDialogClass", "Datenbank \303\244ndern", 0, QApplication::UnicodeUTF8));
    canButton->setText(QApplication::translate("LogfileLesenDialogClass", "Abbrechen", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(LogfileLesenDialogClass);
    } // retranslateUi

};

namespace Ui {
    class LogfileLesenDialogClass: public Ui_LogfileLesenDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGFILELESENDIALOG_H
