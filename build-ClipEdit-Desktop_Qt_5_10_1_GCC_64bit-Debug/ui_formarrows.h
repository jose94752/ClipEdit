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
#include <QtWidgets/QFormLayout>
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
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *labelOptionsForArrows;
    QGroupBox *groupBoxAnchorArrowPoints;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButtonWithoutAnchorPoint;
    QRadioButton *radioButton1AnchorPoints;
    QRadioButton *radioButton2AnchorPoints;
    QGroupBox *groupBoxArrowSettings;
    QFormLayout *formLayout;
    QLabel *labelArrowWidth;
    QSpinBox *spinBoxArrowWidthContents;
    QLabel *labelArrowHeight;
    QLabel *labelOutlineColor;
    QLabel *labelFillColor;
    QLabel *labelLineThickness;
    QLabel *labelHeadTypeChoice;
    QSpinBox *spinBoxArrowHeightContents;
    ColorButton *toolButtonOutlineColorContents;
    ColorButton *toolButtonFillColorContents;
    QComboBox *comboBoxLineThicknessContents;
    QComboBox *comboBoxHeadTypeChoiceContents;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonBeforeShape;
    QPushButton *pushButtonDefaultShape;
    QPushButton *pushButtonAddArrow;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *FormArrows)
    {
        if (FormArrows->objectName().isEmpty())
            FormArrows->setObjectName(QStringLiteral("FormArrows"));
        FormArrows->resize(253, 614);
        verticalLayout_5 = new QVBoxLayout(FormArrows);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
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

        verticalLayout->addWidget(labelOptionsForArrows);

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


        verticalLayout->addWidget(groupBoxAnchorArrowPoints);


        verticalLayout_2->addLayout(verticalLayout);

        groupBoxArrowSettings = new QGroupBox(FormArrows);
        groupBoxArrowSettings->setObjectName(QStringLiteral("groupBoxArrowSettings"));
        formLayout = new QFormLayout(groupBoxArrowSettings);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        labelArrowWidth = new QLabel(groupBoxArrowSettings);
        labelArrowWidth->setObjectName(QStringLiteral("labelArrowWidth"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelArrowWidth);

        spinBoxArrowWidthContents = new QSpinBox(groupBoxArrowSettings);
        spinBoxArrowWidthContents->setObjectName(QStringLiteral("spinBoxArrowWidthContents"));

        formLayout->setWidget(0, QFormLayout::FieldRole, spinBoxArrowWidthContents);

        labelArrowHeight = new QLabel(groupBoxArrowSettings);
        labelArrowHeight->setObjectName(QStringLiteral("labelArrowHeight"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelArrowHeight);

        labelOutlineColor = new QLabel(groupBoxArrowSettings);
        labelOutlineColor->setObjectName(QStringLiteral("labelOutlineColor"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelOutlineColor);

        labelFillColor = new QLabel(groupBoxArrowSettings);
        labelFillColor->setObjectName(QStringLiteral("labelFillColor"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelFillColor);

        labelLineThickness = new QLabel(groupBoxArrowSettings);
        labelLineThickness->setObjectName(QStringLiteral("labelLineThickness"));

        formLayout->setWidget(4, QFormLayout::LabelRole, labelLineThickness);

        labelHeadTypeChoice = new QLabel(groupBoxArrowSettings);
        labelHeadTypeChoice->setObjectName(QStringLiteral("labelHeadTypeChoice"));

        formLayout->setWidget(5, QFormLayout::LabelRole, labelHeadTypeChoice);

        spinBoxArrowHeightContents = new QSpinBox(groupBoxArrowSettings);
        spinBoxArrowHeightContents->setObjectName(QStringLiteral("spinBoxArrowHeightContents"));

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBoxArrowHeightContents);

        toolButtonOutlineColorContents = new ColorButton(groupBoxArrowSettings);
        toolButtonOutlineColorContents->setObjectName(QStringLiteral("toolButtonOutlineColorContents"));

        formLayout->setWidget(2, QFormLayout::FieldRole, toolButtonOutlineColorContents);

        toolButtonFillColorContents = new ColorButton(groupBoxArrowSettings);
        toolButtonFillColorContents->setObjectName(QStringLiteral("toolButtonFillColorContents"));

        formLayout->setWidget(3, QFormLayout::FieldRole, toolButtonFillColorContents);

        comboBoxLineThicknessContents = new QComboBox(groupBoxArrowSettings);
        comboBoxLineThicknessContents->setObjectName(QStringLiteral("comboBoxLineThicknessContents"));

        formLayout->setWidget(4, QFormLayout::FieldRole, comboBoxLineThicknessContents);

        comboBoxHeadTypeChoiceContents = new QComboBox(groupBoxArrowSettings);
        comboBoxHeadTypeChoiceContents->setObjectName(QStringLiteral("comboBoxHeadTypeChoiceContents"));

        formLayout->setWidget(5, QFormLayout::FieldRole, comboBoxHeadTypeChoiceContents);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonBeforeShape = new QPushButton(groupBoxArrowSettings);
        pushButtonBeforeShape->setObjectName(QStringLiteral("pushButtonBeforeShape"));

        horizontalLayout->addWidget(pushButtonBeforeShape);

        pushButtonDefaultShape = new QPushButton(groupBoxArrowSettings);
        pushButtonDefaultShape->setObjectName(QStringLiteral("pushButtonDefaultShape"));

        horizontalLayout->addWidget(pushButtonDefaultShape);


        formLayout->setLayout(6, QFormLayout::SpanningRole, horizontalLayout);

        pushButtonAddArrow = new QPushButton(groupBoxArrowSettings);
        pushButtonAddArrow->setObjectName(QStringLiteral("pushButtonAddArrow"));

        formLayout->setWidget(7, QFormLayout::LabelRole, pushButtonAddArrow);


        verticalLayout_2->addWidget(groupBoxArrowSettings);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        verticalLayout_5->addLayout(verticalLayout_4);


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
        labelFillColor->setText(QApplication::translate("FormArrows", "Fill color", nullptr));
        labelLineThickness->setText(QApplication::translate("FormArrows", "Line Thickness", nullptr));
        labelHeadTypeChoice->setText(QApplication::translate("FormArrows", "Head type choice", nullptr));
        toolButtonOutlineColorContents->setText(QApplication::translate("FormArrows", "...", nullptr));
        toolButtonFillColorContents->setText(QApplication::translate("FormArrows", "...", nullptr));
        pushButtonBeforeShape->setText(QApplication::translate("FormArrows", "Before shape", nullptr));
        pushButtonDefaultShape->setText(QApplication::translate("FormArrows", "Default shape", nullptr));
        pushButtonAddArrow->setText(QApplication::translate("FormArrows", "Add Arrow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormArrows: public Ui_FormArrows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMARROWS_H
