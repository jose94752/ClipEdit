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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Classes/colorbutton.h"

QT_BEGIN_NAMESPACE

class Ui_FormNumberedBullets
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox;
    QFormLayout *formLayout_2;
    QLabel *label_From;
    QSpinBox *spinBox_From;
    QLabel *label_to;
    QSpinBox *spinBox_To;
    QGroupBox *groupBox_Bullet;
    QFormLayout *formLayout_3;
    QLabel *label_Size;
    QSpinBox *spinBox_Size;
    QLabel *label_Shape;
    QComboBox *comboBox_Shape;
    QLabel *label_BulletColor;
    ColorButton *ColorButton_BulletColor;
    QGroupBox *groupBox_Number;
    QFormLayout *formLayout;
    QLabel *label_Color;
    ColorButton *ColorBullet_NumberColor;
    QLabel *label_Font;
    QFontComboBox *fontComboBox;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_saveBulletTheme;
    QPushButton *pushButton_loadBulletTheme;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonCreateBullet;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *FormNumberedBullets)
    {
        if (FormNumberedBullets->objectName().isEmpty())
            FormNumberedBullets->setObjectName(QStringLiteral("FormNumberedBullets"));
        FormNumberedBullets->resize(418, 357);
        verticalLayout = new QVBoxLayout(FormNumberedBullets);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
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


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        groupBox = new QGroupBox(FormNumberedBullets);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        formLayout_2 = new QFormLayout(groupBox);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_From = new QLabel(groupBox);
        label_From->setObjectName(QStringLiteral("label_From"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_From);

        spinBox_From = new QSpinBox(groupBox);
        spinBox_From->setObjectName(QStringLiteral("spinBox_From"));
        spinBox_From->setMinimum(1);
        spinBox_From->setMaximum(100000);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, spinBox_From);

        label_to = new QLabel(groupBox);
        label_to->setObjectName(QStringLiteral("label_to"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_to);

        spinBox_To = new QSpinBox(groupBox);
        spinBox_To->setObjectName(QStringLiteral("spinBox_To"));
        spinBox_To->setMinimum(1);
        spinBox_To->setMaximum(100000);
        spinBox_To->setValue(1);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, spinBox_To);


        horizontalLayout_6->addWidget(groupBox);

        groupBox_Bullet = new QGroupBox(FormNumberedBullets);
        groupBox_Bullet->setObjectName(QStringLiteral("groupBox_Bullet"));
        formLayout_3 = new QFormLayout(groupBox_Bullet);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label_Size = new QLabel(groupBox_Bullet);
        label_Size->setObjectName(QStringLiteral("label_Size"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_Size);

        spinBox_Size = new QSpinBox(groupBox_Bullet);
        spinBox_Size->setObjectName(QStringLiteral("spinBox_Size"));
        spinBox_Size->setMinimum(1);
        spinBox_Size->setValue(10);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, spinBox_Size);

        label_Shape = new QLabel(groupBox_Bullet);
        label_Shape->setObjectName(QStringLiteral("label_Shape"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_Shape);

        comboBox_Shape = new QComboBox(groupBox_Bullet);
        comboBox_Shape->addItem(QString());
        comboBox_Shape->addItem(QString());
        comboBox_Shape->addItem(QString());
        comboBox_Shape->setObjectName(QStringLiteral("comboBox_Shape"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, comboBox_Shape);

        label_BulletColor = new QLabel(groupBox_Bullet);
        label_BulletColor->setObjectName(QStringLiteral("label_BulletColor"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_BulletColor);

        ColorButton_BulletColor = new ColorButton(groupBox_Bullet);
        ColorButton_BulletColor->setObjectName(QStringLiteral("ColorButton_BulletColor"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, ColorButton_BulletColor);


        horizontalLayout_6->addWidget(groupBox_Bullet);


        verticalLayout->addLayout(horizontalLayout_6);

        groupBox_Number = new QGroupBox(FormNumberedBullets);
        groupBox_Number->setObjectName(QStringLiteral("groupBox_Number"));
        formLayout = new QFormLayout(groupBox_Number);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_Color = new QLabel(groupBox_Number);
        label_Color->setObjectName(QStringLiteral("label_Color"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_Color);

        ColorBullet_NumberColor = new ColorButton(groupBox_Number);
        ColorBullet_NumberColor->setObjectName(QStringLiteral("ColorBullet_NumberColor"));

        formLayout->setWidget(0, QFormLayout::FieldRole, ColorBullet_NumberColor);

        label_Font = new QLabel(groupBox_Number);
        label_Font->setObjectName(QStringLiteral("label_Font"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_Font);

        fontComboBox = new QFontComboBox(groupBox_Number);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, fontComboBox);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));

        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_4);


        verticalLayout->addWidget(groupBox_Number);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton_saveBulletTheme = new QPushButton(FormNumberedBullets);
        pushButton_saveBulletTheme->setObjectName(QStringLiteral("pushButton_saveBulletTheme"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icons/save-theme-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_saveBulletTheme->setIcon(icon);

        horizontalLayout_5->addWidget(pushButton_saveBulletTheme);

        pushButton_loadBulletTheme = new QPushButton(FormNumberedBullets);
        pushButton_loadBulletTheme->setObjectName(QStringLiteral("pushButton_loadBulletTheme"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/icons/apply-theme-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_loadBulletTheme->setIcon(icon1);

        horizontalLayout_5->addWidget(pushButton_loadBulletTheme);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        pushButtonCreateBullet = new QPushButton(FormNumberedBullets);
        pushButtonCreateBullet->setObjectName(QStringLiteral("pushButtonCreateBullet"));

        horizontalLayout_5->addWidget(pushButtonCreateBullet);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(FormNumberedBullets);

        QMetaObject::connectSlotsByName(FormNumberedBullets);
    } // setupUi

    void retranslateUi(QWidget *FormNumberedBullets)
    {
        FormNumberedBullets->setWindowTitle(QApplication::translate("FormNumberedBullets", "Form", nullptr));
        label->setText(QApplication::translate("FormNumberedBullets", "Bullets", nullptr));
        groupBox->setTitle(QApplication::translate("FormNumberedBullets", "Numbering", nullptr));
        label_From->setText(QApplication::translate("FormNumberedBullets", "From", nullptr));
        label_to->setText(QApplication::translate("FormNumberedBullets", "To", nullptr));
        groupBox_Bullet->setTitle(QApplication::translate("FormNumberedBullets", "Bullet", nullptr));
        label_Size->setText(QApplication::translate("FormNumberedBullets", "Size", nullptr));
        label_Shape->setText(QApplication::translate("FormNumberedBullets", "Shape", nullptr));
        comboBox_Shape->setItemText(0, QApplication::translate("FormNumberedBullets", "Circle", nullptr));
        comboBox_Shape->setItemText(1, QApplication::translate("FormNumberedBullets", "Rectangle", nullptr));
        comboBox_Shape->setItemText(2, QApplication::translate("FormNumberedBullets", "Rounded rectangle", nullptr));

        label_BulletColor->setText(QApplication::translate("FormNumberedBullets", "Color", nullptr));
        ColorButton_BulletColor->setText(QApplication::translate("FormNumberedBullets", "...", nullptr));
        groupBox_Number->setTitle(QApplication::translate("FormNumberedBullets", "Number", nullptr));
        label_Color->setText(QApplication::translate("FormNumberedBullets", "Color", nullptr));
        ColorBullet_NumberColor->setText(QApplication::translate("FormNumberedBullets", "...", nullptr));
        label_Font->setText(QApplication::translate("FormNumberedBullets", "Font", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_saveBulletTheme->setToolTip(QApplication::translate("FormNumberedBullets", "Save as default theme", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_saveBulletTheme->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_loadBulletTheme->setToolTip(QApplication::translate("FormNumberedBullets", "Apply default theme", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_loadBulletTheme->setText(QString());
        pushButtonCreateBullet->setText(QApplication::translate("FormNumberedBullets", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormNumberedBullets: public Ui_FormNumberedBullets {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMNUMBEREDBULLETS_H
