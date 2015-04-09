/********************************************************************************
** Form generated from reading ui file 'logondialog.ui'
**
** Created: Tue 2. Sep 15:48:29 2008
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_LOGONDIALOG_H
#define UI_LOGONDIALOG_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QDialog>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpacerItem>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LogonDialogClass
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *spacerItem;
    QVBoxLayout *vboxLayout;
    QLabel *LoginTextlabel;
    QLabel *LoginTextlabel_2;
    QSpacerItem *spacerItem1;
    QSpacerItem *spacerItem2;
    QGridLayout *gridLayout1;
    QLabel *BenutzernameLabel;
    QLineEdit *BenutzernameEdit;
    QLabel *PasswortLabel;
    QLineEdit *PasswortLabel_2;
    QSpacerItem *spacerItem3;
    QSpacerItem *spacerItem4;
    QHBoxLayout *hboxLayout;
    QPushButton *LogonButton;
    QPushButton *BeendenButton;
    QSpacerItem *spacerItem5;

    void setupUi(QDialog *LogonDialogClass)
    {
    if (LogonDialogClass->objectName().isEmpty())
        LogonDialogClass->setObjectName(QString::fromUtf8("LogonDialogClass"));
    LogonDialogClass->setWindowModality(Qt::ApplicationModal);
    LogonDialogClass->resize(319, 243);
    gridLayout = new QGridLayout(LogonDialogClass);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(11);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    spacerItem = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(spacerItem, 0, 1, 1, 1);

    vboxLayout = new QVBoxLayout();
    vboxLayout->setSpacing(6);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    LoginTextlabel = new QLabel(LogonDialogClass);
    LoginTextlabel->setObjectName(QString::fromUtf8("LoginTextlabel"));

    vboxLayout->addWidget(LoginTextlabel);

    LoginTextlabel_2 = new QLabel(LogonDialogClass);
    LoginTextlabel_2->setObjectName(QString::fromUtf8("LoginTextlabel_2"));

    vboxLayout->addWidget(LoginTextlabel_2);


    gridLayout->addLayout(vboxLayout, 1, 1, 1, 2);

    spacerItem1 = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(spacerItem1, 2, 1, 1, 1);

    spacerItem2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout->addItem(spacerItem2, 2, 3, 2, 1);

    gridLayout1 = new QGridLayout();
    gridLayout1->setSpacing(6);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    BenutzernameLabel = new QLabel(LogonDialogClass);
    BenutzernameLabel->setObjectName(QString::fromUtf8("BenutzernameLabel"));

    gridLayout1->addWidget(BenutzernameLabel, 0, 0, 1, 1);

    BenutzernameEdit = new QLineEdit(LogonDialogClass);
    BenutzernameEdit->setObjectName(QString::fromUtf8("BenutzernameEdit"));

    gridLayout1->addWidget(BenutzernameEdit, 0, 1, 1, 1);

    PasswortLabel = new QLabel(LogonDialogClass);
    PasswortLabel->setObjectName(QString::fromUtf8("PasswortLabel"));

    gridLayout1->addWidget(PasswortLabel, 1, 0, 1, 1);

    PasswortLabel_2 = new QLineEdit(LogonDialogClass);
    PasswortLabel_2->setObjectName(QString::fromUtf8("PasswortLabel_2"));
    PasswortLabel_2->setEchoMode(QLineEdit::Password);

    gridLayout1->addWidget(PasswortLabel_2, 1, 1, 1, 1);


    gridLayout->addLayout(gridLayout1, 3, 1, 2, 2);

    spacerItem3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout->addItem(spacerItem3, 4, 0, 1, 1);

    spacerItem4 = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(spacerItem4, 5, 2, 1, 1);

    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    LogonButton = new QPushButton(LogonDialogClass);
    LogonButton->setObjectName(QString::fromUtf8("LogonButton"));

    hboxLayout->addWidget(LogonButton);

    BeendenButton = new QPushButton(LogonDialogClass);
    BeendenButton->setObjectName(QString::fromUtf8("BeendenButton"));

    hboxLayout->addWidget(BeendenButton);


    gridLayout->addLayout(hboxLayout, 6, 1, 1, 2);

    spacerItem5 = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(spacerItem5, 7, 2, 1, 1);


    retranslateUi(LogonDialogClass);
    QObject::connect(BeendenButton, SIGNAL(released()), LogonDialogClass, SLOT(close()));

    QMetaObject::connectSlotsByName(LogonDialogClass);
    } // setupUi

    void retranslateUi(QDialog *LogonDialogClass)
    {
    LogonDialogClass->setWindowTitle(QApplication::translate("LogonDialogClass", "LogonDialog", 0));
    LoginTextlabel->setText(QApplication::translate("LogonDialogClass", "Login f\303\274r die BEO-Sport-Timing", 0));
    LoginTextlabel_2->setText(QApplication::translate("LogonDialogClass", "Management-Software", 0));
    BenutzernameLabel->setText(QApplication::translate("LogonDialogClass", "Benutzername", 0));
    PasswortLabel->setText(QApplication::translate("LogonDialogClass", "Passwort", 0));
    LogonButton->setText(QApplication::translate("LogonDialogClass", "Login", 0));
    BeendenButton->setText(QApplication::translate("LogonDialogClass", "Beenden", 0));
    Q_UNUSED(LogonDialogClass);
    } // retranslateUi

};

namespace Ui {
    class LogonDialogClass: public Ui_LogonDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGONDIALOG_H
