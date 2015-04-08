/********************************************************************************
** Form generated from reading ui file 'neueruserdialog.ui'
**
** Created: Tue 2. Sep 15:48:29 2008
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_NEUERUSERDIALOG_H
#define UI_NEUERUSERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTreeWidget>

QT_BEGIN_NAMESPACE

class Ui_NeuerUserDialogClass
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout1;
    QLabel *label;
    QLineEdit *usernameLineEdit;
    QLabel *label_8;
    QLineEdit *nameLineEdit;
    QLabel *label_2;
    QLineEdit *pwdLineEdit;
    QLabel *label_3;
    QLineEdit *pwdwLineEdit;
    QLabel *label_4;
    QLineEdit *emailLineEdit;
    QLabel *label_5;
    QComboBox *typComboBox;
    QLabel *label_6;
    QTreeWidget *streckenTreeWidget;
    QLabel *label_7;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *canButton;

    void setupUi(QDialog *NeuerUserDialogClass)
    {
    if (NeuerUserDialogClass->objectName().isEmpty())
        NeuerUserDialogClass->setObjectName(QString::fromUtf8("NeuerUserDialogClass"));
    NeuerUserDialogClass->resize(375, 418);
    gridLayout = new QGridLayout(NeuerUserDialogClass);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(11);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    groupBox = new QGroupBox(NeuerUserDialogClass);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    gridLayout1 = new QGridLayout(groupBox);
    gridLayout1->setSpacing(6);
    gridLayout1->setMargin(11);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    label = new QLabel(groupBox);
    label->setObjectName(QString::fromUtf8("label"));

    gridLayout1->addWidget(label, 0, 0, 1, 1);

    usernameLineEdit = new QLineEdit(groupBox);
    usernameLineEdit->setObjectName(QString::fromUtf8("usernameLineEdit"));

    gridLayout1->addWidget(usernameLineEdit, 0, 1, 1, 1);

    label_8 = new QLabel(groupBox);
    label_8->setObjectName(QString::fromUtf8("label_8"));

    gridLayout1->addWidget(label_8, 1, 0, 1, 1);

    nameLineEdit = new QLineEdit(groupBox);
    nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));

    gridLayout1->addWidget(nameLineEdit, 1, 1, 1, 1);

    label_2 = new QLabel(groupBox);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    gridLayout1->addWidget(label_2, 2, 0, 1, 1);

    pwdLineEdit = new QLineEdit(groupBox);
    pwdLineEdit->setObjectName(QString::fromUtf8("pwdLineEdit"));
    pwdLineEdit->setEchoMode(QLineEdit::Password);

    gridLayout1->addWidget(pwdLineEdit, 2, 1, 1, 1);

    label_3 = new QLabel(groupBox);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    gridLayout1->addWidget(label_3, 3, 0, 1, 1);

    pwdwLineEdit = new QLineEdit(groupBox);
    pwdwLineEdit->setObjectName(QString::fromUtf8("pwdwLineEdit"));
    pwdwLineEdit->setEchoMode(QLineEdit::Password);

    gridLayout1->addWidget(pwdwLineEdit, 3, 1, 1, 1);

    label_4 = new QLabel(groupBox);
    label_4->setObjectName(QString::fromUtf8("label_4"));

    gridLayout1->addWidget(label_4, 4, 0, 1, 1);

    emailLineEdit = new QLineEdit(groupBox);
    emailLineEdit->setObjectName(QString::fromUtf8("emailLineEdit"));

    gridLayout1->addWidget(emailLineEdit, 4, 1, 1, 1);

    label_5 = new QLabel(groupBox);
    label_5->setObjectName(QString::fromUtf8("label_5"));

    gridLayout1->addWidget(label_5, 5, 0, 1, 1);

    typComboBox = new QComboBox(groupBox);
    typComboBox->setObjectName(QString::fromUtf8("typComboBox"));

    gridLayout1->addWidget(typComboBox, 5, 1, 1, 1);

    label_6 = new QLabel(groupBox);
    label_6->setObjectName(QString::fromUtf8("label_6"));

    gridLayout1->addWidget(label_6, 6, 0, 1, 1);

    streckenTreeWidget = new QTreeWidget(groupBox);
    streckenTreeWidget->setObjectName(QString::fromUtf8("streckenTreeWidget"));

    gridLayout1->addWidget(streckenTreeWidget, 6, 1, 2, 1);

    label_7 = new QLabel(groupBox);
    label_7->setObjectName(QString::fromUtf8("label_7"));

    gridLayout1->addWidget(label_7, 7, 0, 1, 1);


    gridLayout->addWidget(groupBox, 0, 0, 1, 1);

    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    spacerItem = new QSpacerItem(158, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem);

    okButton = new QPushButton(NeuerUserDialogClass);
    okButton->setObjectName(QString::fromUtf8("okButton"));

    hboxLayout->addWidget(okButton);

    canButton = new QPushButton(NeuerUserDialogClass);
    canButton->setObjectName(QString::fromUtf8("canButton"));

    hboxLayout->addWidget(canButton);


    gridLayout->addLayout(hboxLayout, 1, 0, 1, 1);


    retranslateUi(NeuerUserDialogClass);

    QMetaObject::connectSlotsByName(NeuerUserDialogClass);
    } // setupUi

    void retranslateUi(QDialog *NeuerUserDialogClass)
    {
    NeuerUserDialogClass->setWindowTitle(QApplication::translate("NeuerUserDialogClass", "NeuerUserDialog", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("NeuerUserDialogClass", "Neuer Benutzer", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("NeuerUserDialogClass", "Benutzername:", 0, QApplication::UnicodeUTF8));
    label_8->setText(QApplication::translate("NeuerUserDialogClass", "Name / Vorname:", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("NeuerUserDialogClass", "Passwort:", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("NeuerUserDialogClass", "Passwort wiederholen:", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("NeuerUserDialogClass", "Email:", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("NeuerUserDialogClass", "Typ:", 0, QApplication::UnicodeUTF8));
    label_6->setText(QApplication::translate("NeuerUserDialogClass", "Berechtigungen:", 0, QApplication::UnicodeUTF8));
    streckenTreeWidget->headerItem()->setText(0, QApplication::translate("NeuerUserDialogClass", "1", 0, QApplication::UnicodeUTF8));
    label_7->setText(QApplication::translate("NeuerUserDialogClass", "(mehrfachauswahl m\303\266glich)", 0, QApplication::UnicodeUTF8));
    okButton->setText(QApplication::translate("NeuerUserDialogClass", "Ok", 0, QApplication::UnicodeUTF8));
    canButton->setText(QApplication::translate("NeuerUserDialogClass", "Abbrechen", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(NeuerUserDialogClass);
    } // retranslateUi

};

namespace Ui {
    class NeuerUserDialogClass: public Ui_NeuerUserDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEUERUSERDIALOG_H
