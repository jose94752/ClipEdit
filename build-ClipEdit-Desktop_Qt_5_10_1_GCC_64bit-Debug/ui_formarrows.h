/********************************************************************************
** Form generated from reading UI file 'formarrows.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMARROWS_H
#define UI_FORMARROWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Classes/colorbutton.h"

QT_BEGIN_NAMESPACE

class Ui_FormArrows
{
public:
    QVBoxLayout *verticalLayout_4;
    QLabel *labelOptionsForArrows;
    QGroupBox *groupBoxAnchorArrowPoints;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButtonWithoutAnchorPoint;
    QRadioButton *radioButton1AnchorPoints;
    QRadioButton *radioButton2AnchorPoints;
    QGroupBox *groupBoxArrowSettings;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelArrowWidth;
    QSpinBox *spinBoxArrowWidthContents;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelArrowHeight;
    QSpinBox *spinBoxArrowHeightContents;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelOutlineColor;
    ColorButton *toolButtonOutlineColorContents;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelFillColor;
    ColorButton *toolButtonFillColorContents;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QLabel *labelLineThickness;
    QComboBox *comboBoxLineThicknessContents;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelHeadTypeChoice;
    QComboBox *comboBoxHeadTypeChoiceContents;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButtonBeforeShape;
    QPushButton *pushButtonDefaultShape;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *FormArrows)
    {
        if (FormArrows->objectName().isEmpty())
            FormArrows->setObjectName(QStringLiteral("FormArrows"));
        FormArrows->resize(450, 577);
        verticalLayout_4 = new QVBoxLayout(FormArrows);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        labelOptionsForArrows = new QLabel(FormArrows);
        labelOptionsForArrows->setObjectName(QStringLiteral("labelOptionsForArrows"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelOptionsForArrows->sizePolicy().hasHeightForWidth());
        labelOptionsForArrows->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(20);
        labelOptionsForArrows->setFont(font);
        labelOptionsForArrows->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(labelOptionsForArrows);

        groupBoxAnchorArrowPoints = new QGroupBox(FormArrows);
        groupBoxAnchorArrowPoints->setObjectName(QStringLiteral("groupBoxAnchorArrowPoints"));
        verticalLayout_3 = new QVBoxLayout(groupBoxAnchorArrowPoints);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        radioButtonWithoutAnchorPoint = new QRadioButton(groupBoxAnchorArrowPoints);
        radioButtonWithoutAnchorPoint->setObjectName(QStringLiteral("radioButtonWithoutAnchorPoint"));

        verticalLayout_3->addWidget(radioButtonWithoutAnchorPoint);

        radioButton1AnchorPoints = new QRadioButton(groupBoxAnchorArrowPoints);
        radioButton1AnchorPoints->setObjectName(QStringLiteral("radioButton1AnchorPoints"));

        verticalLayout_3->addWidget(radioButton1AnchorPoints);

        radioButton2AnchorPoints = new QRadioButton(groupBoxAnchorArrowPoints);
        radioButton2AnchorPoints->setObjectName(QStringLiteral("radioButton2AnchorPoints"));

        verticalLayout_3->addWidget(radioButton2AnchorPoints);


        verticalLayout_4->addWidget(groupBoxAnchorArrowPoints);

        groupBoxArrowSettings = new QGroupBox(FormArrows);
        groupBoxArrowSettings->setObjectName(QStringLiteral("groupBoxArrowSettings"));
        verticalLayout_2 = new QVBoxLayout(groupBoxArrowSettings);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelArrowWidth = new QLabel(groupBoxArrowSettings);
        labelArrowWidth->setObjectName(QStringLiteral("labelArrowWidth"));

        horizontalLayout_3->addWidget(labelArrowWidth);

        spinBoxArrowWidthContents = new QSpinBox(groupBoxArrowSettings);
        spinBoxArrowWidthContents->setObjectName(QStringLiteral("spinBoxArrowWidthContents"));

        horizontalLayout_3->addWidget(spinBoxArrowWidthContents);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        labelArrowHeight = new QLabel(groupBoxArrowSettings);
        labelArrowHeight->setObjectName(QStringLiteral("labelArrowHeight"));

        horizontalLayout_4->addWidget(labelArrowHeight);

        spinBoxArrowHeightContents = new QSpinBox(groupBoxArrowSettings);
        spinBoxArrowHeightContents->setObjectName(QStringLiteral("spinBoxArrowHeightContents"));

        horizontalLayout_4->addWidget(spinBoxArrowHeightContents);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_8->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(158, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        labelOutlineColor = new QLabel(groupBoxArrowSettings);
        labelOutlineColor->setObjectName(QStringLiteral("labelOutlineColor"));

        horizontalLayout_7->addWidget(labelOutlineColor);

        toolButtonOutlineColorContents = new ColorButton(groupBoxArrowSettings);
        toolButtonOutlineColorContents->setObjectName(QStringLiteral("toolButtonOutlineColorContents"));

        horizontalLayout_7->addWidget(toolButtonOutlineColorContents);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        labelFillColor = new QLabel(groupBoxArrowSettings);
        labelFillColor->setObjectName(QStringLiteral("labelFillColor"));

        horizontalLayout_5->addWidget(labelFillColor);

        toolButtonFillColorContents = new ColorButton(groupBoxArrowSettings);
        toolButtonFillColorContents->setObjectName(QStringLiteral("toolButtonFillColorContents"));

        horizontalLayout_5->addWidget(toolButtonFillColorContents);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelLineThickness = new QLabel(groupBoxArrowSettings);
        labelLineThickness->setObjectName(QStringLiteral("labelLineThickness"));

        horizontalLayout->addWidget(labelLineThickness);

        comboBoxLineThicknessContents = new QComboBox(groupBoxArrowSettings);
        comboBoxLineThicknessContents->setObjectName(QStringLiteral("comboBoxLineThicknessContents"));

        horizontalLayout->addWidget(comboBoxLineThicknessContents);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelHeadTypeChoice = new QLabel(groupBoxArrowSettings);
        labelHeadTypeChoice->setObjectName(QStringLiteral("labelHeadTypeChoice"));

        horizontalLayout_2->addWidget(labelHeadTypeChoice);

        comboBoxHeadTypeChoiceContents = new QComboBox(groupBoxArrowSettings);
        comboBoxHeadTypeChoiceContents->setObjectName(QStringLiteral("comboBoxHeadTypeChoiceContents"));

        horizontalLayout_2->addWidget(comboBoxHeadTypeChoiceContents);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        pushButtonBeforeShape = new QPushButton(groupBoxArrowSettings);
        pushButtonBeforeShape->setObjectName(QStringLiteral("pushButtonBeforeShape"));

        horizontalLayout_6->addWidget(pushButtonBeforeShape);

        pushButtonDefaultShape = new QPushButton(groupBoxArrowSettings);
        pushButtonDefaultShape->setObjectName(QStringLiteral("pushButtonDefaultShape"));

        horizontalLayout_6->addWidget(pushButtonDefaultShape);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_6);


        verticalLayout_4->addWidget(groupBoxArrowSettings);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        retranslateUi(FormArrows);

        QMetaObject::connectSlotsByName(FormArrows);
    } // setupUi

    void retranslateUi(QWidget *FormArrows)
    {
        FormArrows->setWindowTitle(QApplication::translate("FormArrows", "Form", nullptr));
        labelOptionsForArrows->setText(QApplication::translate("FormArrows", "Arrows", nullptr));
        groupBoxAnchorArrowPoints->setTitle(QApplication::translate("FormArrows", "Anchor points", nullptr));
        radioButtonWithoutAnchorPoint->setText(QApplication::translate("FormArrows", "Without anchor point", nullptr));
        radioButton1AnchorPoints->setText(QApplication::translate("FormArrows", "1 anchor point", nullptr));
        radioButton2AnchorPoints->setText(QApplication::translate("FormArrows", "2 anchor points", nullptr));
        groupBoxArrowSettings->setTitle(QApplication::translate("FormArrows", "Properties", nullptr));
        labelArrowWidth->setText(QApplication::translate("FormArrows", "Width", nullptr));
        labelArrowHeight->setText(QApplication::translate("FormArrows", "Height", nullptr));
        labelOutlineColor->setText(QApplication::translate("FormArrows", "Outline color", nullptr));
        toolButtonOutlineColorContents->setText(QApplication::translate("FormArrows", "...", nullptr));
        labelFillColor->setText(QApplication::translate("FormArrows", "Fill color", nullptr));
        toolButtonFillColorContents->setText(QApplication::translate("FormArrows", "...", nullptr));
        labelLineThickness->setText(QApplication::translate("FormArrows", "Line Thickness", nullptr));
        labelHeadTypeChoice->setText(QApplication::translate("FormArrows", "Head type choice", nullptr));
        pushButtonBeforeShape->setText(QApplication::translate("FormArrows", "Before shape", nullptr));
        pushButtonDefaultShape->setText(QApplication::translate("FormArrows", "Default shape", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormArrows: public Ui_FormArrows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMARROWS_H
