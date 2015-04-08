/********************************************************************************
** Form generated from reading ui file 'neuesrennendialog.ui'
**
** Created: Tue 2. Sep 15:48:29 2008
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_NEUESRENNENDIALOG_H
#define UI_NEUESRENNENDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_NeuesRennenDialogClass
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *nameLineEdit;
    QDateEdit *startdatumDateEdit;
    QDateEdit *enddatumDateEdit;
    QComboBox *streckentypComboBox;
    QLabel *label_5;
    QTextEdit *beschreibungTextEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;
    QPushButton *canButton;

    void setupUi(QDialog *NeuesRennenDialogClass)
    {
    if (NeuesRennenDialogClass->objectName().isEmpty())
        NeuesRennenDialogClass->setObjectName(QString::fromUtf8("NeuesRennenDialogClass"));
    NeuesRennenDialogClass->resize(353, 289);
    gridLayout_2 = new QGridLayout(NeuesRennenDialogClass);
    gridLayout_2->setSpacing(6);
    gridLayout_2->setMargin(11);
    gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
    groupBox = new QGroupBox(NeuesRennenDialogClass);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    gridLayout = new QGridLayout(groupBox);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(11);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    label = new QLabel(groupBox);
    label->setObjectName(QString::fromUtf8("label"));

    gridLayout->addWidget(label, 0, 0, 1, 1);

    label_2 = new QLabel(groupBox);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    gridLayout->addWidget(label_2, 1, 0, 1, 1);

    label_3 = new QLabel(groupBox);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    gridLayout->addWidget(label_3, 2, 0, 1, 1);

    label_4 = new QLabel(groupBox);
    label_4->setObjectName(QString::fromUtf8("label_4"));

    gridLayout->addWidget(label_4, 3, 0, 1, 1);

    nameLineEdit = new QLineEdit(groupBox);
    nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));

    gridLayout->addWidget(nameLineEdit, 0, 1, 1, 1);

    startdatumDateEdit = new QDateEdit(groupBox);
    startdatumDateEdit->setObjectName(QString::fromUtf8("startdatumDateEdit"));
    startdatumDateEdit->setCalendarPopup(true);

    gridLayout->addWidget(startdatumDateEdit, 1, 1, 1, 1);

    enddatumDateEdit = new QDateEdit(groupBox);
    enddatumDateEdit->setObjectName(QString::fromUtf8("enddatumDateEdit"));
    enddatumDateEdit->setCalendarPopup(true);

    gridLayout->addWidget(enddatumDateEdit, 2, 1, 1, 1);

    streckentypComboBox = new QComboBox(groupBox);
    streckentypComboBox->setObjectName(QString::fromUtf8("streckentypComboBox"));

    gridLayout->addWidget(streckentypComboBox, 3, 1, 1, 1);

    label_5 = new QLabel(groupBox);
    label_5->setObjectName(QString::fromUtf8("label_5"));

    gridLayout->addWidget(label_5, 4, 0, 1, 1);

    beschreibungTextEdit = new QTextEdit(groupBox);
    beschreibungTextEdit->setObjectName(QString::fromUtf8("beschreibungTextEdit"));

    gridLayout->addWidget(beschreibungTextEdit, 4, 1, 1, 1);


    gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setSpacing(6);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer);

    okButton = new QPushButton(NeuesRennenDialogClass);
    okButton->setObjectName(QString::fromUtf8("okButton"));

    horizontalLayout->addWidget(okButton);

    canButton = new QPushButton(NeuesRennenDialogClass);
    canButton->setObjectName(QString::fromUtf8("canButton"));

    horizontalLayout->addWidget(canButton);


    gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);


    retranslateUi(NeuesRennenDialogClass);

    streckentypComboBox->setCurrentIndex(-1);


    QMetaObject::connectSlotsByName(NeuesRennenDialogClass);
    } // setupUi

    void retranslateUi(QDialog *NeuesRennenDialogClass)
    {
    NeuesRennenDialogClass->setWindowTitle(QApplication::translate("NeuesRennenDialogClass", "NeuesRennenDialog", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("NeuesRennenDialogClass", "Neues Rennen", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("NeuesRennenDialogClass", "Name:", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("NeuesRennenDialogClass", "Startdatum:", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("NeuesRennenDialogClass", "Enddatum:", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("NeuesRennenDialogClass", "Streckentyp:", 0, QApplication::UnicodeUTF8));
    enddatumDateEdit->setDisplayFormat(QApplication::translate("NeuesRennenDialogClass", "dd.MM.yyyy", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("NeuesRennenDialogClass", "Beschreibung (optional):", 0, QApplication::UnicodeUTF8));
    okButton->setText(QApplication::translate("NeuesRennenDialogClass", "Ok", 0, QApplication::UnicodeUTF8));
    canButton->setText(QApplication::translate("NeuesRennenDialogClass", "Abbrechen", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(NeuesRennenDialogClass);
    } // retranslateUi

};

namespace Ui {
    class NeuesRennenDialogClass: public Ui_NeuesRennenDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEUESRENNENDIALOG_H
