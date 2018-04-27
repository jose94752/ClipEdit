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
#include <QtWidgets/QGridLayout>
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

QT_BEGIN_NAMESPACE

class Ui_FormScreenshots
{
public:
    QGridLayout *gridLayout;
    QLabel *labelScreenshots;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButtonDeskcapture;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *labelDelay;
    QSpacerItem *horizontalSpacer;
    QSpinBox *spinBoxDelay;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBoxHideWindow;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonCancel;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButtonCapture;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QWidget *FormScreenshots)
    {
        if (FormScreenshots->objectName().isEmpty())
            FormScreenshots->setObjectName(QStringLiteral("FormScreenshots"));
        FormScreenshots->resize(460, 624);
        FormScreenshots->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(FormScreenshots);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelScreenshots = new QLabel(FormScreenshots);
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

        gridLayout->addWidget(labelScreenshots, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        radioButtonDeskcapture = new QRadioButton(FormScreenshots);
        radioButtonDeskcapture->setObjectName(QStringLiteral("radioButtonDeskcapture"));

        horizontalLayout_2->addWidget(radioButtonDeskcapture);

        horizontalSpacer_2 = new QSpacerItem(148, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        groupBox = new QGroupBox(FormScreenshots);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelDelay = new QLabel(groupBox);
        labelDelay->setObjectName(QStringLiteral("labelDelay"));

        horizontalLayout->addWidget(labelDelay);

        horizontalSpacer = new QSpacerItem(168, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        spinBoxDelay = new QSpinBox(groupBox);
        spinBoxDelay->setObjectName(QStringLiteral("spinBoxDelay"));

        horizontalLayout->addWidget(spinBoxDelay);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        checkBoxHideWindow = new QCheckBox(groupBox);
        checkBoxHideWindow->setObjectName(QStringLiteral("checkBoxHideWindow"));

        horizontalLayout_4->addWidget(checkBoxHideWindow);

        horizontalSpacer_6 = new QSpacerItem(258, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_4);


        gridLayout_3->addLayout(verticalLayout_2, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButtonCancel = new QPushButton(FormScreenshots);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));

        horizontalLayout_3->addWidget(pushButtonCancel);

        horizontalSpacer_4 = new QSpacerItem(108, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        pushButtonCapture = new QPushButton(FormScreenshots);
        pushButtonCapture->setObjectName(QStringLiteral("pushButtonCapture"));
        pushButtonCapture->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	color: yellow;\n"
"	backgroud-color:  #27a9c3\n"
"	border-whidth: 0px\n"
"	border-raduis: 3px\n"
"}"));

        horizontalLayout_3->addWidget(pushButtonCapture);

        horizontalSpacer_5 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 1);


        retranslateUi(FormScreenshots);

        QMetaObject::connectSlotsByName(FormScreenshots);
    } // setupUi

    void retranslateUi(QWidget *FormScreenshots)
    {
        FormScreenshots->setWindowTitle(QApplication::translate("FormScreenshots", "Form", nullptr));
        labelScreenshots->setText(QApplication::translate("FormScreenshots", "<html><head/><body><p align=\"center\">Screenshots</p></body></html>", nullptr));
        radioButtonDeskcapture->setText(QApplication::translate("FormScreenshots", "Desk screen capture", nullptr));
        groupBox->setTitle(QApplication::translate("FormScreenshots", "Options", nullptr));
        labelDelay->setText(QApplication::translate("FormScreenshots", "Screenshot delay second", nullptr));
        checkBoxHideWindow->setText(QApplication::translate("FormScreenshots", "Hide this window", nullptr));
        pushButtonCancel->setText(QApplication::translate("FormScreenshots", "Cancel", nullptr));
        pushButtonCapture->setText(QApplication::translate("FormScreenshots", "Go", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormScreenshots: public Ui_FormScreenshots {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSCREENSHOTS_H
