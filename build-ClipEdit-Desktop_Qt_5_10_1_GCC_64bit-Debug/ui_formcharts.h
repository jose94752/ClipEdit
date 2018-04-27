/********************************************************************************
** Form generated from reading UI file 'formcharts.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCHARTS_H
#define UI_FORMCHARTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Classes/colorbutton.h"

QT_BEGIN_NAMESPACE

class Ui_FormCharts
{
public:
    QVBoxLayout *verticalLayout_8;
    QLabel *label_10;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_13;
    QSpacerItem *verticalSpacer;
    QLabel *label_3;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_4;
    QComboBox *qChartType;
    QLineEdit *qData;
    QTableView *gGraphColors;
    QLineEdit *qTitle;
    QLineEdit *qLegends;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QLabel *label_4;
    QCheckBox *bTransparent;
    QVBoxLayout *verticalLayout_2;
    ColorButton *qColor;
    ColorButton *qBackColor;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_11;
    QLabel *label_12;
    QVBoxLayout *verticalLayout_7;
    QSpinBox *qHeight;
    QSpinBox *qWidth;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *qGo;

    void setupUi(QWidget *FormCharts)
    {
        if (FormCharts->objectName().isEmpty())
            FormCharts->setObjectName(QStringLiteral("FormCharts"));
        FormCharts->resize(658, 708);
        verticalLayout_8 = new QVBoxLayout(FormCharts);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_10 = new QLabel(FormCharts);
        label_10->setObjectName(QStringLiteral("label_10"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(20);
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_10);

        groupBox = new QGroupBox(FormCharts);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_3->addWidget(label);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout_3->addWidget(label_13);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_3->addWidget(label_6);


        horizontalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        qChartType = new QComboBox(groupBox);
        qChartType->setObjectName(QStringLiteral("qChartType"));

        verticalLayout_4->addWidget(qChartType);

        qData = new QLineEdit(groupBox);
        qData->setObjectName(QStringLiteral("qData"));

        verticalLayout_4->addWidget(qData);

        gGraphColors = new QTableView(groupBox);
        gGraphColors->setObjectName(QStringLiteral("gGraphColors"));

        verticalLayout_4->addWidget(gGraphColors);

        qTitle = new QLineEdit(groupBox);
        qTitle->setObjectName(QStringLiteral("qTitle"));

        verticalLayout_4->addWidget(qTitle);

        qLegends = new QLineEdit(groupBox);
        qLegends->setObjectName(QStringLiteral("qLegends"));

        verticalLayout_4->addWidget(qLegends);


        horizontalLayout_5->addLayout(verticalLayout_4);


        horizontalLayout_2->addLayout(horizontalLayout_5);


        verticalLayout_8->addWidget(groupBox);

        groupBox_2 = new QGroupBox(FormCharts);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_9 = new QHBoxLayout(groupBox_2);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout->addWidget(label_7);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        bTransparent = new QCheckBox(groupBox_2);
        bTransparent->setObjectName(QStringLiteral("bTransparent"));
        bTransparent->setChecked(true);

        verticalLayout->addWidget(bTransparent);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        qColor = new ColorButton(groupBox_2);
        qColor->setObjectName(QStringLiteral("qColor"));

        verticalLayout_2->addWidget(qColor);

        qBackColor = new ColorButton(groupBox_2);
        qBackColor->setObjectName(QStringLiteral("qBackColor"));

        verticalLayout_2->addWidget(qBackColor);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);


        horizontalLayout_8->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_6->addWidget(label_11);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_6->addWidget(label_12);


        horizontalLayout_3->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        qHeight = new QSpinBox(groupBox_2);
        qHeight->setObjectName(QStringLiteral("qHeight"));
        qHeight->setMaximum(400);
        qHeight->setSingleStep(20);
        qHeight->setValue(200);

        verticalLayout_7->addWidget(qHeight);

        qWidth = new QSpinBox(groupBox_2);
        qWidth->setObjectName(QStringLiteral("qWidth"));
        qWidth->setMaximum(400);
        qWidth->setSingleStep(20);
        qWidth->setValue(200);

        verticalLayout_7->addWidget(qWidth);


        horizontalLayout_3->addLayout(verticalLayout_7);


        horizontalLayout_8->addLayout(horizontalLayout_3);


        horizontalLayout_9->addLayout(horizontalLayout_8);


        verticalLayout_8->addWidget(groupBox_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        qGo = new QPushButton(FormCharts);
        qGo->setObjectName(QStringLiteral("qGo"));

        horizontalLayout_6->addWidget(qGo);


        verticalLayout_8->addLayout(horizontalLayout_6);

        QWidget::setTabOrder(qChartType, qLegends);

        retranslateUi(FormCharts);

        QMetaObject::connectSlotsByName(FormCharts);
    } // setupUi

    void retranslateUi(QWidget *FormCharts)
    {
        FormCharts->setWindowTitle(QApplication::translate("FormCharts", "Form", nullptr));
        label_10->setText(QApplication::translate("FormCharts", "Charts", nullptr));
        groupBox->setTitle(QApplication::translate("FormCharts", "Data", nullptr));
        label->setText(QApplication::translate("FormCharts", "Chart Type", nullptr));
        label_2->setText(QApplication::translate("FormCharts", "Data", nullptr));
        label_13->setText(QApplication::translate("FormCharts", "Colors", nullptr));
        label_3->setText(QApplication::translate("FormCharts", "Chart Title", nullptr));
        label_6->setText(QApplication::translate("FormCharts", "Legends", nullptr));
        qLegends->setText(QString());
        groupBox_2->setTitle(QApplication::translate("FormCharts", "Properties", nullptr));
        label_7->setText(QApplication::translate("FormCharts", "Chart Color", nullptr));
        label_4->setText(QApplication::translate("FormCharts", "Backround Color", nullptr));
        bTransparent->setText(QApplication::translate("FormCharts", "Transparent", nullptr));
        qColor->setText(QString());
        qBackColor->setText(QString());
        label_11->setText(QApplication::translate("FormCharts", "Height", nullptr));
        label_12->setText(QApplication::translate("FormCharts", "Width", nullptr));
        qGo->setText(QApplication::translate("FormCharts", "Go", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormCharts: public Ui_FormCharts {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCHARTS_H
