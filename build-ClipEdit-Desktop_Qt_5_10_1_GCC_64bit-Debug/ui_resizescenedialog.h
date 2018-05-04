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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include "Classes/colorbutton.h"

QT_BEGIN_NAMESPACE

class Ui_ResizeSceneDialog
{
public:
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelUnit;
    QComboBox *comboBoxUnit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelWidth;
    QDoubleSpinBox *doubleSpinBoxWidth;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelHeight;
    QDoubleSpinBox *doubleSpinBoxHeight;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_format;
    QComboBox *comboBox_format;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_color;
    ColorButton *colorButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonSaveTheme;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ResizeSceneDialog)
    {
        if (ResizeSceneDialog->objectName().isEmpty())
            ResizeSceneDialog->setObjectName(QStringLiteral("ResizeSceneDialog"));
        ResizeSceneDialog->resize(216, 282);
        horizontalLayout_7 = new QHBoxLayout(ResizeSceneDialog);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelUnit = new QLabel(ResizeSceneDialog);
        labelUnit->setObjectName(QStringLiteral("labelUnit"));

        horizontalLayout_2->addWidget(labelUnit);

        comboBoxUnit = new QComboBox(ResizeSceneDialog);
        comboBoxUnit->setObjectName(QStringLiteral("comboBoxUnit"));

        horizontalLayout_2->addWidget(comboBoxUnit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelWidth = new QLabel(ResizeSceneDialog);
        labelWidth->setObjectName(QStringLiteral("labelWidth"));

        horizontalLayout_3->addWidget(labelWidth);

        doubleSpinBoxWidth = new QDoubleSpinBox(ResizeSceneDialog);
        doubleSpinBoxWidth->setObjectName(QStringLiteral("doubleSpinBoxWidth"));
        doubleSpinBoxWidth->setMaximum(10000);

        horizontalLayout_3->addWidget(doubleSpinBoxWidth);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        labelHeight = new QLabel(ResizeSceneDialog);
        labelHeight->setObjectName(QStringLiteral("labelHeight"));

        horizontalLayout_4->addWidget(labelHeight);

        doubleSpinBoxHeight = new QDoubleSpinBox(ResizeSceneDialog);
        doubleSpinBoxHeight->setObjectName(QStringLiteral("doubleSpinBoxHeight"));
        doubleSpinBoxHeight->setMaximum(10000);

        horizontalLayout_4->addWidget(doubleSpinBoxHeight);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_format = new QLabel(ResizeSceneDialog);
        label_format->setObjectName(QStringLiteral("label_format"));

        horizontalLayout_5->addWidget(label_format);

        comboBox_format = new QComboBox(ResizeSceneDialog);
        comboBox_format->setObjectName(QStringLiteral("comboBox_format"));

        horizontalLayout_5->addWidget(comboBox_format);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_color = new QLabel(ResizeSceneDialog);
        label_color->setObjectName(QStringLiteral("label_color"));

        horizontalLayout_6->addWidget(label_color);

        colorButton = new ColorButton(ResizeSceneDialog);
        colorButton->setObjectName(QStringLiteral("colorButton"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(colorButton->sizePolicy().hasHeightForWidth());
        colorButton->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(colorButton);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonSaveTheme = new QPushButton(ResizeSceneDialog);
        pushButtonSaveTheme->setObjectName(QStringLiteral("pushButtonSaveTheme"));
        pushButtonSaveTheme->setMaximumSize(QSize(35, 35));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icons/save-theme-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSaveTheme->setIcon(icon);

        horizontalLayout->addWidget(pushButtonSaveTheme);

        buttonBox = new QDialogButtonBox(ResizeSceneDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy1);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_7->addLayout(verticalLayout);

#ifndef QT_NO_SHORTCUT
        labelUnit->setBuddy(comboBoxUnit);
        labelWidth->setBuddy(doubleSpinBoxWidth);
        labelHeight->setBuddy(doubleSpinBoxHeight);
        label_format->setBuddy(comboBox_format);
        label_color->setBuddy(colorButton);
#endif // QT_NO_SHORTCUT

        retranslateUi(ResizeSceneDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ResizeSceneDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ResizeSceneDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ResizeSceneDialog);
    } // setupUi

    void retranslateUi(QDialog *ResizeSceneDialog)
    {
        ResizeSceneDialog->setWindowTitle(QApplication::translate("ResizeSceneDialog", "Resize scene", nullptr));
        labelUnit->setText(QApplication::translate("ResizeSceneDialog", "&Unit", nullptr));
        labelWidth->setText(QApplication::translate("ResizeSceneDialog", "&Width", nullptr));
        labelHeight->setText(QApplication::translate("ResizeSceneDialog", "&Height", nullptr));
        label_format->setText(QApplication::translate("ResizeSceneDialog", "&Format", nullptr));
        label_color->setText(QApplication::translate("ResizeSceneDialog", "&Color", nullptr));
        colorButton->setText(QString());
        pushButtonSaveTheme->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ResizeSceneDialog: public Ui_ResizeSceneDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESIZESCENEDIALOG_H
