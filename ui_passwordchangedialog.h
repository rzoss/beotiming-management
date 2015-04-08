/********************************************************************************
** Form generated from reading ui file 'passwordchangedialog.ui'
**
** Created: Tue 2. Sep 15:48:29 2008
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PASSWORDCHANGEDIALOG_H
#define UI_PASSWORDCHANGEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PasswordChangeDialogClass
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *oldLineEdit;
    QLabel *label_2;
    QLineEdit *newLineEdit;
    QLabel *label_3;
    QLineEdit *wiederLineEdit;
    QLabel *label_4;
    QProgressBar *staerkeProgressBar;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;
    QPushButton *canButton;

    void setupUi(QWidget *PasswordChangeDialogClass)
    {
    if (PasswordChangeDialogClass->objectName().isEmpty())
        PasswordChangeDialogClass->setObjectName(QString::fromUtf8("PasswordChangeDialogClass"));
    PasswordChangeDialogClass->resize(272, 157);
    gridLayout = new QGridLayout(PasswordChangeDialogClass);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(11);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    label = new QLabel(PasswordChangeDialogClass);
    label->setObjectName(QString::fromUtf8("label"));

    gridLayout->addWidget(label, 0, 0, 1, 1);

    oldLineEdit = new QLineEdit(PasswordChangeDialogClass);
    oldLineEdit->setObjectName(QString::fromUtf8("oldLineEdit"));
    oldLineEdit->setEchoMode(QLineEdit::Password);

    gridLayout->addWidget(oldLineEdit, 0, 1, 1, 1);

    label_2 = new QLabel(PasswordChangeDialogClass);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    gridLayout->addWidget(label_2, 1, 0, 1, 1);

    newLineEdit = new QLineEdit(PasswordChangeDialogClass);
    newLineEdit->setObjectName(QString::fromUtf8("newLineEdit"));
    newLineEdit->setEchoMode(QLineEdit::Password);

    gridLayout->addWidget(newLineEdit, 1, 1, 1, 1);

    label_3 = new QLabel(PasswordChangeDialogClass);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    gridLayout->addWidget(label_3, 2, 0, 1, 1);

    wiederLineEdit = new QLineEdit(PasswordChangeDialogClass);
    wiederLineEdit->setObjectName(QString::fromUtf8("wiederLineEdit"));
    wiederLineEdit->setEchoMode(QLineEdit::Password);

    gridLayout->addWidget(wiederLineEdit, 2, 1, 1, 1);

    label_4 = new QLabel(PasswordChangeDialogClass);
    label_4->setObjectName(QString::fromUtf8("label_4"));

    gridLayout->addWidget(label_4, 3, 0, 1, 1);

    staerkeProgressBar = new QProgressBar(PasswordChangeDialogClass);
    staerkeProgressBar->setObjectName(QString::fromUtf8("staerkeProgressBar"));
    staerkeProgressBar->setValue(24);
    staerkeProgressBar->setTextVisible(false);
    staerkeProgressBar->setInvertedAppearance(false);

    gridLayout->addWidget(staerkeProgressBar, 3, 1, 1, 1);

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setSpacing(6);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer);

    okButton = new QPushButton(PasswordChangeDialogClass);
    okButton->setObjectName(QString::fromUtf8("okButton"));

    horizontalLayout->addWidget(okButton);

    canButton = new QPushButton(PasswordChangeDialogClass);
    canButton->setObjectName(QString::fromUtf8("canButton"));

    horizontalLayout->addWidget(canButton);


    gridLayout->addLayout(horizontalLayout, 4, 0, 1, 2);


    retranslateUi(PasswordChangeDialogClass);

    QMetaObject::connectSlotsByName(PasswordChangeDialogClass);
    } // setupUi

    void retranslateUi(QWidget *PasswordChangeDialogClass)
    {
    PasswordChangeDialogClass->setWindowTitle(QApplication::translate("PasswordChangeDialogClass", "PasswordChangeDialog", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("PasswordChangeDialogClass", "Altes Passwort:", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("PasswordChangeDialogClass", "Neues Passwort:", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("PasswordChangeDialogClass", "Passwort wiederholen:", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("PasswordChangeDialogClass", "Passwort st\303\244rke:", 0, QApplication::UnicodeUTF8));
    okButton->setText(QApplication::translate("PasswordChangeDialogClass", "Ok", 0, QApplication::UnicodeUTF8));
    canButton->setText(QApplication::translate("PasswordChangeDialogClass", "Abbrechen", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(PasswordChangeDialogClass);
    } // retranslateUi

};

namespace Ui {
    class PasswordChangeDialogClass: public Ui_PasswordChangeDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDCHANGEDIALOG_H
