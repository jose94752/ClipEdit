/********************************************************************************
** Form generated from reading UI file 'resizescenedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESIZESCENEDIALOG_H
#define UI_RESIZESCENEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ResizeSceneDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelWidth;
    QDoubleSpinBox *doubleSpinBoxWidth;
    QDoubleSpinBox *doubleSpinBoxHeight;
    QLabel *labelHeight;
    QComboBox *comboBoxUnit;
    QLabel *labelUnit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ResizeSceneDialog)
    {
        if (ResizeSceneDialog->objectName().isEmpty())
            ResizeSceneDialog->setObjectName(QStringLiteral("ResizeSceneDialog"));
        ResizeSceneDialog->resize(187, 152);
        verticalLayout = new QVBoxLayout(ResizeSceneDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        labelWidth = new QLabel(ResizeSceneDialog);
        labelWidth->setObjectName(QStringLiteral("labelWidth"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelWidth);

        doubleSpinBoxWidth = new QDoubleSpinBox(ResizeSceneDialog);
        doubleSpinBoxWidth->setObjectName(QStringLiteral("doubleSpinBoxWidth"));
        doubleSpinBoxWidth->setMaximum(1500);

        formLayout->setWidget(0, QFormLayout::FieldRole, doubleSpinBoxWidth);

        doubleSpinBoxHeight = new QDoubleSpinBox(ResizeSceneDialog);
        doubleSpinBoxHeight->setObjectName(QStringLiteral("doubleSpinBoxHeight"));
        doubleSpinBoxHeight->setMaximum(1500);

        formLayout->setWidget(1, QFormLayout::FieldRole, doubleSpinBoxHeight);

        labelHeight = new QLabel(ResizeSceneDialog);
        labelHeight->setObjectName(QStringLiteral("labelHeight"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelHeight);

        comboBoxUnit = new QComboBox(ResizeSceneDialog);
        comboBoxUnit->setObjectName(QStringLiteral("comboBoxUnit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBoxUnit);

        labelUnit = new QLabel(ResizeSceneDialog);
        labelUnit->setObjectName(QStringLiteral("labelUnit"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelUnit);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(ResizeSceneDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        labelWidth->setBuddy(doubleSpinBoxWidth);
        labelHeight->setBuddy(doubleSpinBoxHeight);
        labelUnit->setBuddy(comboBoxUnit);
#endif // QT_NO_SHORTCUT

        retranslateUi(ResizeSceneDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ResizeSceneDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ResizeSceneDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ResizeSceneDialog);
    } // setupUi

    void retranslateUi(QDialog *ResizeSceneDialog)
    {
        ResizeSceneDialog->setWindowTitle(QApplication::translate("ResizeSceneDialog", "Resize scene", nullptr));
        labelWidth->setText(QApplication::translate("ResizeSceneDialog", "&Width", nullptr));
        labelHeight->setText(QApplication::translate("ResizeSceneDialog", "&Height", nullptr));
        labelUnit->setText(QApplication::translate("ResizeSceneDialog", "&Unit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResizeSceneDialog: public Ui_ResizeSceneDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESIZESCENEDIALOG_H
