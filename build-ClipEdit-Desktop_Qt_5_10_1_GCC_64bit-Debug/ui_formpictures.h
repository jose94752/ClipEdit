/********************************************************************************
** Form generated from reading UI file 'formpictures.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPICTURES_H
#define UI_FORMPICTURES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Classes/colorbutton.h"

QT_BEGIN_NAMESPACE

class Ui_FormPictures
{
public:
    QVBoxLayout *verticalLayout_8;
    QLabel *label_2;
    QGroupBox *groupBox_picture;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLineEdit *lineEdit_pic_path;
    QToolButton *toolButton_path;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QSpinBox *spinBox_pic_h;
    QCheckBox *checkBox_pic_black_white;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_4;
    QSpinBox *spinBox_pic_w;
    QSlider *horizontalSlider_pic_opacity;
    QGroupBox *groupBox_legend;
    QFormLayout *formLayout;
    QLabel *label_10;
    QLineEdit *lineEdit_lg_txt;
    QLabel *label_13;
    QLabel *label_11;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_9;
    QComboBox *comboBox_lg_or;
    QSpacerItem *horizontalSpacer;
    QLabel *label_8;
    QComboBox *comboBox_lg_pos;
    QFontComboBox *fontComboBox_lg_font;
    QSpinBox *spinBox_lg_size;
    ColorButton *toolButton_color;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_save;
    QPushButton *pushButton_restore;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_ok;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *FormPictures)
    {
        if (FormPictures->objectName().isEmpty())
            FormPictures->setObjectName(QStringLiteral("FormPictures"));
        FormPictures->resize(401, 584);
        verticalLayout_8 = new QVBoxLayout(FormPictures);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_2 = new QLabel(FormPictures);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(20);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_2);

        groupBox_picture = new QGroupBox(FormPictures);
        groupBox_picture->setObjectName(QStringLiteral("groupBox_picture"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_picture);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_6 = new QLabel(groupBox_picture);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);

        lineEdit_pic_path = new QLineEdit(groupBox_picture);
        lineEdit_pic_path->setObjectName(QStringLiteral("lineEdit_pic_path"));
        lineEdit_pic_path->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEdit_pic_path);

        toolButton_path = new QToolButton(groupBox_picture);
        toolButton_path->setObjectName(QStringLiteral("toolButton_path"));

        horizontalLayout_3->addWidget(toolButton_path);


        verticalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(groupBox_picture);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_4 = new QLabel(groupBox_picture);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        spinBox_pic_h = new QSpinBox(groupBox_picture);
        spinBox_pic_h->setObjectName(QStringLiteral("spinBox_pic_h"));
        spinBox_pic_h->setMaximum(10000);

        verticalLayout_2->addWidget(spinBox_pic_h);

        checkBox_pic_black_white = new QCheckBox(groupBox_picture);
        checkBox_pic_black_white->setObjectName(QStringLiteral("checkBox_pic_black_white"));

        verticalLayout_2->addWidget(checkBox_pic_black_white);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_3 = new QLabel(groupBox_picture);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        label_5 = new QLabel(groupBox_picture);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_3->addWidget(label_5);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        spinBox_pic_w = new QSpinBox(groupBox_picture);
        spinBox_pic_w->setObjectName(QStringLiteral("spinBox_pic_w"));
        spinBox_pic_w->setMaximum(10000);

        verticalLayout_4->addWidget(spinBox_pic_w);

        horizontalSlider_pic_opacity = new QSlider(groupBox_picture);
        horizontalSlider_pic_opacity->setObjectName(QStringLiteral("horizontalSlider_pic_opacity"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(horizontalSlider_pic_opacity->sizePolicy().hasHeightForWidth());
        horizontalSlider_pic_opacity->setSizePolicy(sizePolicy1);
        horizontalSlider_pic_opacity->setMaximum(255);
        horizontalSlider_pic_opacity->setValue(255);
        horizontalSlider_pic_opacity->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(horizontalSlider_pic_opacity);


        horizontalLayout_2->addLayout(verticalLayout_4);


        verticalLayout_6->addLayout(horizontalLayout_2);


        horizontalLayout_4->addLayout(verticalLayout_6);


        verticalLayout_8->addWidget(groupBox_picture);

        groupBox_legend = new QGroupBox(FormPictures);
        groupBox_legend->setObjectName(QStringLiteral("groupBox_legend"));
        formLayout = new QFormLayout(groupBox_legend);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_10 = new QLabel(groupBox_legend);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_10);

        lineEdit_lg_txt = new QLineEdit(groupBox_legend);
        lineEdit_lg_txt->setObjectName(QStringLiteral("lineEdit_lg_txt"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_lg_txt);

        label_13 = new QLabel(groupBox_legend);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_13);

        label_11 = new QLabel(groupBox_legend);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_11);

        label_7 = new QLabel(groupBox_legend);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_9 = new QLabel(groupBox_legend);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_5->addWidget(label_9);

        comboBox_lg_or = new QComboBox(groupBox_legend);
        comboBox_lg_or->setObjectName(QStringLiteral("comboBox_lg_or"));

        horizontalLayout_5->addWidget(comboBox_lg_or);

        horizontalSpacer = new QSpacerItem(18, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        label_8 = new QLabel(groupBox_legend);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_5->addWidget(label_8);

        comboBox_lg_pos = new QComboBox(groupBox_legend);
        comboBox_lg_pos->setObjectName(QStringLiteral("comboBox_lg_pos"));

        horizontalLayout_5->addWidget(comboBox_lg_pos);


        formLayout->setLayout(6, QFormLayout::SpanningRole, horizontalLayout_5);

        fontComboBox_lg_font = new QFontComboBox(groupBox_legend);
        fontComboBox_lg_font->setObjectName(QStringLiteral("fontComboBox_lg_font"));

        formLayout->setWidget(1, QFormLayout::FieldRole, fontComboBox_lg_font);

        spinBox_lg_size = new QSpinBox(groupBox_legend);
        spinBox_lg_size->setObjectName(QStringLiteral("spinBox_lg_size"));
        spinBox_lg_size->setMinimum(6);

        formLayout->setWidget(3, QFormLayout::FieldRole, spinBox_lg_size);

        toolButton_color = new ColorButton(groupBox_legend);
        toolButton_color->setObjectName(QStringLiteral("toolButton_color"));

        formLayout->setWidget(4, QFormLayout::FieldRole, toolButton_color);


        verticalLayout_8->addWidget(groupBox_legend);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        pushButton_save = new QPushButton(FormPictures);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icons/save-theme-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_save->setIcon(icon);

        horizontalLayout_6->addWidget(pushButton_save);

        pushButton_restore = new QPushButton(FormPictures);
        pushButton_restore->setObjectName(QStringLiteral("pushButton_restore"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/icons/apply-theme-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_restore->setIcon(icon1);

        horizontalLayout_6->addWidget(pushButton_restore);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        pushButton_ok = new QPushButton(FormPictures);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));

        horizontalLayout_6->addWidget(pushButton_ok);


        verticalLayout_8->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer);


        retranslateUi(FormPictures);

        QMetaObject::connectSlotsByName(FormPictures);
    } // setupUi

    void retranslateUi(QWidget *FormPictures)
    {
        FormPictures->setWindowTitle(QApplication::translate("FormPictures", "Form", nullptr));
        label_2->setText(QApplication::translate("FormPictures", "Pictures", nullptr));
        groupBox_picture->setTitle(QApplication::translate("FormPictures", "General", nullptr));
        label_6->setText(QApplication::translate("FormPictures", "Path", nullptr));
        toolButton_path->setText(QApplication::translate("FormPictures", "...", nullptr));
        label->setText(QApplication::translate("FormPictures", "Height", nullptr));
        label_4->setText(QApplication::translate("FormPictures", "black / white", nullptr));
        checkBox_pic_black_white->setText(QString());
        label_3->setText(QApplication::translate("FormPictures", "Width", nullptr));
        label_5->setText(QApplication::translate("FormPictures", "Opacity", nullptr));
        groupBox_legend->setTitle(QApplication::translate("FormPictures", "Legend", nullptr));
        label_10->setText(QApplication::translate("FormPictures", "Text", nullptr));
        label_13->setText(QApplication::translate("FormPictures", "Font", nullptr));
        label_11->setText(QApplication::translate("FormPictures", "Font Size", nullptr));
        label_7->setText(QApplication::translate("FormPictures", "Font Color", nullptr));
        label_9->setText(QApplication::translate("FormPictures", "Orientation", nullptr));
        label_8->setText(QApplication::translate("FormPictures", "Position", nullptr));
        toolButton_color->setText(QApplication::translate("FormPictures", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_save->setToolTip(QApplication::translate("FormPictures", "Save as default theme", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_save->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_restore->setToolTip(QApplication::translate("FormPictures", "Apply default theme", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_restore->setText(QString());
        pushButton_ok->setText(QApplication::translate("FormPictures", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormPictures: public Ui_FormPictures {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPICTURES_H
