/********************************************************************************
** Form generated from reading UI file 'formscreenshots.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMSCREENSHOTS_H
#define UI_FORMSCREENSHOTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormScreenshots
{
public:
    QGroupBox *groupBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *labelDelay;
    QSpacerItem *verticalSpacer_3;
    QProgressBar *progressBar;
    QSpacerItem *verticalSpacer;
    QCheckBox *checkBoxHideWindow;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QSpinBox *spinBoxDelay;
    QSpacerItem *verticalSpacer_2;
    QRadioButton *radioButtonFast;
    QRadioButton *radioButtonAverage;
    QRadioButton *radioButtonSlow;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonCancel;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButtonCapture;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelScreenshots;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButtonDeskcapture;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *FormScreenshots)
    {
        if (FormScreenshots->objectName().isEmpty())
            FormScreenshots->setObjectName(QStringLiteral("FormScreenshots"));
        FormScreenshots->resize(366, 503);
        FormScreenshots->setStyleSheet(QStringLiteral(""));
        groupBox = new QGroupBox(FormScreenshots);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(9, 238, 442, 185));
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 30, 311, 136));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelDelay = new QLabel(widget);
        labelDelay->setObjectName(QStringLiteral("labelDelay"));

        verticalLayout->addWidget(labelDelay);

        verticalSpacer_3 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        progressBar = new QProgressBar(widget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        verticalLayout->addWidget(progressBar);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        checkBoxHideWindow = new QCheckBox(widget);
        checkBoxHideWindow->setObjectName(QStringLiteral("checkBoxHideWindow"));

        verticalLayout->addWidget(checkBoxHideWindow);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        spinBoxDelay = new QSpinBox(widget);
        spinBoxDelay->setObjectName(QStringLiteral("spinBoxDelay"));

        verticalLayout_2->addWidget(spinBoxDelay);

        verticalSpacer_2 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        radioButtonFast = new QRadioButton(widget);
        radioButtonFast->setObjectName(QStringLiteral("radioButtonFast"));

        verticalLayout_2->addWidget(radioButtonFast);

        radioButtonAverage = new QRadioButton(widget);
        radioButtonAverage->setObjectName(QStringLiteral("radioButtonAverage"));

        verticalLayout_2->addWidget(radioButtonAverage);

        radioButtonSlow = new QRadioButton(widget);
        radioButtonSlow->setObjectName(QStringLiteral("radioButtonSlow"));

        verticalLayout_2->addWidget(radioButtonSlow);


        horizontalLayout->addLayout(verticalLayout_2);

        widget1 = new QWidget(FormScreenshots);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(30, 430, 300, 27));
        horizontalLayout_3 = new QHBoxLayout(widget1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButtonCancel = new QPushButton(widget1);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));

        horizontalLayout_3->addWidget(pushButtonCancel);

        horizontalSpacer_4 = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        pushButtonCapture = new QPushButton(widget1);
        pushButtonCapture->setObjectName(QStringLiteral("pushButtonCapture"));
        pushButtonCapture->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	color: yellow;\n"
"	backgroud-color:  #27a9c3\n"
"	border-whidth: 0px\n"
"	border-raduis: 3px\n"
"}"));

        horizontalLayout_3->addWidget(pushButtonCapture);

        horizontalSpacer_5 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        widget2 = new QWidget(FormScreenshots);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(20, 41, 231, 98));
        verticalLayout_3 = new QVBoxLayout(widget2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        labelScreenshots = new QLabel(widget2);
        labelScreenshots->setObjectName(QStringLiteral("labelScreenshots"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelScreenshots->sizePolicy().hasHeightForWidth());
        labelScreenshots->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(20);
        font.setBold(false);
        font.setWeight(50);
        labelScreenshots->setFont(font);

        verticalLayout_3->addWidget(labelScreenshots);

        verticalSpacer_4 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        radioButtonDeskcapture = new QRadioButton(widget2);
        radioButtonDeskcapture->setObjectName(QStringLiteral("radioButtonDeskcapture"));

        horizontalLayout_2->addWidget(radioButtonDeskcapture);

        horizontalSpacer_2 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(FormScreenshots);

        QMetaObject::connectSlotsByName(FormScreenshots);
    } // setupUi

    void retranslateUi(QWidget *FormScreenshots)
    {
        FormScreenshots->setWindowTitle(QApplication::translate("FormScreenshots", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("FormScreenshots", "Options", nullptr));
        labelDelay->setText(QApplication::translate("FormScreenshots", "Screenshot delay second", nullptr));
        checkBoxHideWindow->setText(QApplication::translate("FormScreenshots", "Hide this window", nullptr));
        radioButtonFast->setText(QApplication::translate("FormScreenshots", "Fast", nullptr));
        radioButtonAverage->setText(QApplication::translate("FormScreenshots", "Average", nullptr));
        radioButtonSlow->setText(QApplication::translate("FormScreenshots", "Slow", nullptr));
        pushButtonCancel->setText(QApplication::translate("FormScreenshots", "Cancel", nullptr));
        pushButtonCapture->setText(QApplication::translate("FormScreenshots", "Go", nullptr));
        labelScreenshots->setText(QApplication::translate("FormScreenshots", "<html><head/><body><p align=\"center\">Screenshots</p></body></html>", nullptr));
        radioButtonDeskcapture->setText(QApplication::translate("FormScreenshots", "Desk screen capture", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormScreenshots: public Ui_FormScreenshots {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSCREENSHOTS_H
