/********************************************************************************
** Form generated from reading UI file 'dialogfilealreadyexists.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGFILEALREADYEXISTS_H
#define UI_DIALOGFILEALREADYEXISTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogFileAlreadyExists
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_warning;
    QPushButton *pushButton_ok;

    void setupUi(QDialog *DialogFileAlreadyExists)
    {
        if (DialogFileAlreadyExists->objectName().isEmpty())
            DialogFileAlreadyExists->setObjectName(QStringLiteral("DialogFileAlreadyExists"));
        DialogFileAlreadyExists->resize(341, 124);
        widget = new QWidget(DialogFileAlreadyExists);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(100, 30, 190, 56));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_warning = new QLabel(widget);
        label_warning->setObjectName(QStringLiteral("label_warning"));

        verticalLayout->addWidget(label_warning);

        pushButton_ok = new QPushButton(widget);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));

        verticalLayout->addWidget(pushButton_ok);


        retranslateUi(DialogFileAlreadyExists);

        QMetaObject::connectSlotsByName(DialogFileAlreadyExists);
    } // setupUi

    void retranslateUi(QDialog *DialogFileAlreadyExists)
    {
        DialogFileAlreadyExists->setWindowTitle(QApplication::translate("DialogFileAlreadyExists", "Dialog", nullptr));
        label_warning->setText(QApplication::translate("DialogFileAlreadyExists", "Error: This fille already exists", nullptr));
        pushButton_ok->setText(QApplication::translate("DialogFileAlreadyExists", "ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogFileAlreadyExists: public Ui_DialogFileAlreadyExists {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGFILEALREADYEXISTS_H
