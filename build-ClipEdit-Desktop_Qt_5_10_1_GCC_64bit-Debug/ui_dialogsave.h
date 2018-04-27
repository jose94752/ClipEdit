/********************************************************************************
** Form generated from reading UI file 'dialogsave.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSAVE_H
#define UI_DIALOGSAVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogSave
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_yes;
    QPushButton *pushButton_no;

    void setupUi(QDialog *DialogSave)
    {
        if (DialogSave->objectName().isEmpty())
            DialogSave->setObjectName(QStringLiteral("DialogSave"));
        DialogSave->resize(282, 140);
        widget = new QWidget(DialogSave);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 20, 213, 58));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_yes = new QPushButton(widget);
        pushButton_yes->setObjectName(QStringLiteral("pushButton_yes"));

        horizontalLayout->addWidget(pushButton_yes);

        pushButton_no = new QPushButton(widget);
        pushButton_no->setObjectName(QStringLiteral("pushButton_no"));

        horizontalLayout->addWidget(pushButton_no);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DialogSave);

        QMetaObject::connectSlotsByName(DialogSave);
    } // setupUi

    void retranslateUi(QDialog *DialogSave)
    {
        DialogSave->setWindowTitle(QApplication::translate("DialogSave", "Dialog", nullptr));
        label->setText(QApplication::translate("DialogSave", "Do you want to save the projet?", nullptr));
        pushButton_yes->setText(QApplication::translate("DialogSave", "Yes", nullptr));
        pushButton_no->setText(QApplication::translate("DialogSave", "No", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSave: public Ui_DialogSave {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSAVE_H
