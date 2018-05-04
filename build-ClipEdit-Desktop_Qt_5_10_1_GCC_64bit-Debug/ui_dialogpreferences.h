/********************************************************************************
** Form generated from reading UI file 'dialogpreferences.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPREFERENCES_H
#define UI_DIALOGPREFERENCES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogPreferences
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *comboBoxLanguage;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogPreferences)
    {
        if (DialogPreferences->objectName().isEmpty())
            DialogPreferences->setObjectName(QStringLiteral("DialogPreferences"));
        DialogPreferences->resize(187, 76);
        verticalLayout = new QVBoxLayout(DialogPreferences);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(DialogPreferences);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        comboBoxLanguage = new QComboBox(DialogPreferences);
        comboBoxLanguage->setObjectName(QStringLiteral("comboBoxLanguage"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBoxLanguage);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(DialogPreferences);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DialogPreferences);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogPreferences, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogPreferences, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogPreferences);
    } // setupUi

    void retranslateUi(QDialog *DialogPreferences)
    {
        DialogPreferences->setWindowTitle(QApplication::translate("DialogPreferences", "Preferences", nullptr));
        label->setText(QApplication::translate("DialogPreferences", "Language", nullptr));
        comboBoxLanguage->setCurrentText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogPreferences: public Ui_DialogPreferences {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPREFERENCES_H
