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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ResizeSceneDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_format;
    QComboBox *comboBox_format;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelWidth;
    QDoubleSpinBox *doubleSpinBoxWidth;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelHeight;
    QDoubleSpinBox *doubleSpinBoxHeight;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelUnit;
    QComboBox *comboBoxUnit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ResizeSceneDialog)
    {
        if (ResizeSceneDialog->objectName().isEmpty())
            ResizeSceneDialog->setObjectName(QStringLiteral("ResizeSceneDialog"));
        ResizeSceneDialog->resize(208, 219);
        verticalLayout_2 = new QVBoxLayout(ResizeSceneDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_format = new QLabel(ResizeSceneDialog);
        label_format->setObjectName(QStringLiteral("label_format"));

        horizontalLayout->addWidget(label_format);

        comboBox_format = new QComboBox(ResizeSceneDialog);
        comboBox_format->setObjectName(QStringLiteral("comboBox_format"));

        horizontalLayout->addWidget(comboBox_format);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelWidth = new QLabel(ResizeSceneDialog);
        labelWidth->setObjectName(QStringLiteral("labelWidth"));

        horizontalLayout_2->addWidget(labelWidth);

        doubleSpinBoxWidth = new QDoubleSpinBox(ResizeSceneDialog);
        doubleSpinBoxWidth->setObjectName(QStringLiteral("doubleSpinBoxWidth"));
        doubleSpinBoxWidth->setMaximum(1500);

        horizontalLayout_2->addWidget(doubleSpinBoxWidth);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelHeight = new QLabel(ResizeSceneDialog);
        labelHeight->setObjectName(QStringLiteral("labelHeight"));

        horizontalLayout_3->addWidget(labelHeight);

        doubleSpinBoxHeight = new QDoubleSpinBox(ResizeSceneDialog);
        doubleSpinBoxHeight->setObjectName(QStringLiteral("doubleSpinBoxHeight"));
        doubleSpinBoxHeight->setMaximum(1500);

        horizontalLayout_3->addWidget(doubleSpinBoxHeight);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        labelUnit = new QLabel(ResizeSceneDialog);
        labelUnit->setObjectName(QStringLiteral("labelUnit"));

        horizontalLayout_4->addWidget(labelUnit);

        comboBoxUnit = new QComboBox(ResizeSceneDialog);
        comboBoxUnit->setObjectName(QStringLiteral("comboBoxUnit"));

        horizontalLayout_4->addWidget(comboBoxUnit);


        verticalLayout->addLayout(horizontalLayout_4);

        buttonBox = new QDialogButtonBox(ResizeSceneDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        verticalLayout_2->addLayout(verticalLayout);

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
        label_format->setText(QApplication::translate("ResizeSceneDialog", "Format", nullptr));
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
