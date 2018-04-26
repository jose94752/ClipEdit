/********************************************************************************
** Form generated from reading UI file 'formnumberedbullets.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMNUMBEREDBULLETS_H
#define UI_FORMNUMBEREDBULLETS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Classes/colorbutton.h"

QT_BEGIN_NAMESPACE

class Ui_FormNumberedBullets
{
public:
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_From;
    QLabel *label_to;
    QVBoxLayout *verticalLayout_8;
    QSpinBox *spinBox_From;
    QSpinBox *spinBox_To;
    QGroupBox *groupBox_Bullet;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_Size;
    QLabel *label_Shape;
    QLabel *label_BulletColor;
    QVBoxLayout *verticalLayout_3;
    QSpinBox *spinBox_Size;
    QComboBox *comboBox_Shape;
    ColorButton *ColorButton_BulletColor;
    QGroupBox *groupBox_Number;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QLabel *label_Color;
    QLabel *label_Font;
    QVBoxLayout *verticalLayout_5;
    ColorButton *ColorBullet_NumberColor;
    QFontComboBox *fontComboBox;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *toolButton_saveBulletConfig;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButtonCreateBullet;

    void setupUi(QWidget *FormNumberedBullets)
    {
        if (FormNumberedBullets->objectName().isEmpty())
            FormNumberedBullets->setObjectName(QStringLiteral("FormNumberedBullets"));
        FormNumberedBullets->resize(418, 442);
        horizontalLayout_7 = new QHBoxLayout(FormNumberedBullets);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label = new QLabel(FormNumberedBullets);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setTextFormat(Qt::PlainText);

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_11->addLayout(horizontalLayout_2);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        groupBox = new QGroupBox(FormNumberedBullets);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_9 = new QVBoxLayout(groupBox);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_From = new QLabel(groupBox);
        label_From->setObjectName(QStringLiteral("label_From"));

        verticalLayout_7->addWidget(label_From);

        label_to = new QLabel(groupBox);
        label_to->setObjectName(QStringLiteral("label_to"));

        verticalLayout_7->addWidget(label_to);


        horizontalLayout->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        spinBox_From = new QSpinBox(groupBox);
        spinBox_From->setObjectName(QStringLiteral("spinBox_From"));
        spinBox_From->setMinimum(1);
        spinBox_From->setMaximum(100000);

        verticalLayout_8->addWidget(spinBox_From);

        spinBox_To = new QSpinBox(groupBox);
        spinBox_To->setObjectName(QStringLiteral("spinBox_To"));
        spinBox_To->setMinimum(1);
        spinBox_To->setMaximum(100000);
        spinBox_To->setValue(1);

        verticalLayout_8->addWidget(spinBox_To);


        horizontalLayout->addLayout(verticalLayout_8);


        verticalLayout_9->addLayout(horizontalLayout);


        horizontalLayout_6->addWidget(groupBox);

        groupBox_Bullet = new QGroupBox(FormNumberedBullets);
        groupBox_Bullet->setObjectName(QStringLiteral("groupBox_Bullet"));
        verticalLayout_4 = new QVBoxLayout(groupBox_Bullet);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_Size = new QLabel(groupBox_Bullet);
        label_Size->setObjectName(QStringLiteral("label_Size"));

        verticalLayout_2->addWidget(label_Size);

        label_Shape = new QLabel(groupBox_Bullet);
        label_Shape->setObjectName(QStringLiteral("label_Shape"));

        verticalLayout_2->addWidget(label_Shape);

        label_BulletColor = new QLabel(groupBox_Bullet);
        label_BulletColor->setObjectName(QStringLiteral("label_BulletColor"));

        verticalLayout_2->addWidget(label_BulletColor);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        spinBox_Size = new QSpinBox(groupBox_Bullet);
        spinBox_Size->setObjectName(QStringLiteral("spinBox_Size"));
        spinBox_Size->setMinimum(1);
        spinBox_Size->setValue(10);

        verticalLayout_3->addWidget(spinBox_Size);

        comboBox_Shape = new QComboBox(groupBox_Bullet);
        comboBox_Shape->addItem(QString());
        comboBox_Shape->addItem(QString());
        comboBox_Shape->addItem(QString());
        comboBox_Shape->setObjectName(QStringLiteral("comboBox_Shape"));

        verticalLayout_3->addWidget(comboBox_Shape);

        ColorButton_BulletColor = new ColorButton(groupBox_Bullet);
        ColorButton_BulletColor->setObjectName(QStringLiteral("ColorButton_BulletColor"));

        verticalLayout_3->addWidget(ColorButton_BulletColor);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_3);


        horizontalLayout_6->addWidget(groupBox_Bullet);


        verticalLayout_10->addLayout(horizontalLayout_6);

        groupBox_Number = new QGroupBox(FormNumberedBullets);
        groupBox_Number->setObjectName(QStringLiteral("groupBox_Number"));
        verticalLayout_6 = new QVBoxLayout(groupBox_Number);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_Color = new QLabel(groupBox_Number);
        label_Color->setObjectName(QStringLiteral("label_Color"));

        verticalLayout->addWidget(label_Color);

        label_Font = new QLabel(groupBox_Number);
        label_Font->setObjectName(QStringLiteral("label_Font"));

        verticalLayout->addWidget(label_Font);


        horizontalLayout_5->addLayout(verticalLayout);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        ColorBullet_NumberColor = new ColorButton(groupBox_Number);
        ColorBullet_NumberColor->setObjectName(QStringLiteral("ColorBullet_NumberColor"));

        verticalLayout_5->addWidget(ColorBullet_NumberColor);

        fontComboBox = new QFontComboBox(groupBox_Number);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));

        verticalLayout_5->addWidget(fontComboBox);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));

        verticalLayout_5->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout_5);

        toolButton_saveBulletConfig = new QToolButton(groupBox_Number);
        toolButton_saveBulletConfig->setObjectName(QStringLiteral("toolButton_saveBulletConfig"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icons/save-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_saveBulletConfig->setIcon(icon);

        verticalLayout_6->addWidget(toolButton_saveBulletConfig);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        pushButtonCreateBullet = new QPushButton(groupBox_Number);
        pushButtonCreateBullet->setObjectName(QStringLiteral("pushButtonCreateBullet"));

        verticalLayout_6->addWidget(pushButtonCreateBullet);


        verticalLayout_10->addWidget(groupBox_Number);


        verticalLayout_11->addLayout(verticalLayout_10);


        horizontalLayout_7->addLayout(verticalLayout_11);


        retranslateUi(FormNumberedBullets);

        QMetaObject::connectSlotsByName(FormNumberedBullets);
    } // setupUi

    void retranslateUi(QWidget *FormNumberedBullets)
    {
        FormNumberedBullets->setWindowTitle(QApplication::translate("FormNumberedBullets", "Form", nullptr));
        label->setText(QApplication::translate("FormNumberedBullets", "Bullets", nullptr));
        groupBox->setTitle(QApplication::translate("FormNumberedBullets", "Numbering", nullptr));
        label_From->setText(QApplication::translate("FormNumberedBullets", "From", nullptr));
        label_to->setText(QApplication::translate("FormNumberedBullets", "to", nullptr));
        groupBox_Bullet->setTitle(QApplication::translate("FormNumberedBullets", "Bullet", nullptr));
        label_Size->setText(QApplication::translate("FormNumberedBullets", "Size", nullptr));
        label_Shape->setText(QApplication::translate("FormNumberedBullets", "Shape", nullptr));
        label_BulletColor->setText(QApplication::translate("FormNumberedBullets", "Color", nullptr));
        comboBox_Shape->setItemText(0, QApplication::translate("FormNumberedBullets", "circle", nullptr));
        comboBox_Shape->setItemText(1, QApplication::translate("FormNumberedBullets", "rectangle", nullptr));
        comboBox_Shape->setItemText(2, QApplication::translate("FormNumberedBullets", "rounded rectangle", nullptr));

        ColorButton_BulletColor->setText(QApplication::translate("FormNumberedBullets", "...", nullptr));
        groupBox_Number->setTitle(QApplication::translate("FormNumberedBullets", "Number", nullptr));
        label_Color->setText(QApplication::translate("FormNumberedBullets", "Color", nullptr));
        label_Font->setText(QApplication::translate("FormNumberedBullets", "Font", nullptr));
        ColorBullet_NumberColor->setText(QApplication::translate("FormNumberedBullets", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButton_saveBulletConfig->setToolTip(QApplication::translate("FormNumberedBullets", "save as default", nullptr));
#endif // QT_NO_TOOLTIP
        toolButton_saveBulletConfig->setText(QString());
        pushButtonCreateBullet->setText(QApplication::translate("FormNumberedBullets", "Go", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormNumberedBullets: public Ui_FormNumberedBullets {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMNUMBEREDBULLETS_H
