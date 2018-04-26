/********************************************************************************
** Form generated from reading UI file 'formcliparts.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCLIPARTS_H
#define UI_FORMCLIPARTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormCliparts
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *main_title;
    QSpacerItem *spacer01;
    QFrame *frame_path;
    QHBoxLayout *frame_path_layout;
    QLabel *label_path;
    QSpacerItem *frame_path_spacer01;
    QPushButton *button_clear;
    QSpacerItem *frame_path_spacer02;
    QPushButton *button_browse;
    QSpacerItem *frame_path_spacer03;
    QSpacerItem *spacer02;
    QTextEdit *edit_path;
    QSpacerItem *spacer03;
    QFrame *frame_action;
    QHBoxLayout *frame_button_layout;
    QSpacerItem *frame_action_spacer01;
    QPushButton *button_action;
    QSpacerItem *frame_action_spacer02;
    QSpacerItem *bottom_spacer;

    void setupUi(QWidget *FormCliparts)
    {
        if (FormCliparts->objectName().isEmpty())
            FormCliparts->setObjectName(QStringLiteral("FormCliparts"));
        FormCliparts->resize(520, 638);
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(12);
        FormCliparts->setFont(font);
        verticalLayout = new QVBoxLayout(FormCliparts);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        main_title = new QLabel(FormCliparts);
        main_title->setObjectName(QStringLiteral("main_title"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(main_title->sizePolicy().hasHeightForWidth());
        main_title->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(20);
        main_title->setFont(font1);
        main_title->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(main_title);

        spacer01 = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(spacer01);

        frame_path = new QFrame(FormCliparts);
        frame_path->setObjectName(QStringLiteral("frame_path"));
        frame_path->setFrameShape(QFrame::NoFrame);
        frame_path->setFrameShadow(QFrame::Plain);
        frame_path->setLineWidth(0);
        frame_path_layout = new QHBoxLayout(frame_path);
        frame_path_layout->setSpacing(0);
        frame_path_layout->setObjectName(QStringLiteral("frame_path_layout"));
        frame_path_layout->setContentsMargins(0, 0, 0, 0);
        label_path = new QLabel(frame_path);
        label_path->setObjectName(QStringLiteral("label_path"));

        frame_path_layout->addWidget(label_path);

        frame_path_spacer01 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        frame_path_layout->addItem(frame_path_spacer01);

        button_clear = new QPushButton(frame_path);
        button_clear->setObjectName(QStringLiteral("button_clear"));

        frame_path_layout->addWidget(button_clear);

        frame_path_spacer02 = new QSpacerItem(8, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        frame_path_layout->addItem(frame_path_spacer02);

        button_browse = new QPushButton(frame_path);
        button_browse->setObjectName(QStringLiteral("button_browse"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(button_browse->sizePolicy().hasHeightForWidth());
        button_browse->setSizePolicy(sizePolicy1);
        button_browse->setMinimumSize(QSize(35, 0));
        button_browse->setMaximumSize(QSize(35, 16777215));
        QFont font2;
        font2.setFamily(QStringLiteral("DejaVu Sans"));
        font2.setPointSize(12);
        button_browse->setFont(font2);
        button_browse->setFlat(false);

        frame_path_layout->addWidget(button_browse);

        frame_path_spacer03 = new QSpacerItem(8, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        frame_path_layout->addItem(frame_path_spacer03);


        verticalLayout->addWidget(frame_path);

        spacer02 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(spacer02);

        edit_path = new QTextEdit(FormCliparts);
        edit_path->setObjectName(QStringLiteral("edit_path"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(edit_path->sizePolicy().hasHeightForWidth());
        edit_path->setSizePolicy(sizePolicy2);
        edit_path->setMinimumSize(QSize(0, 70));
        edit_path->setMaximumSize(QSize(16777215, 70));
        QFont font3;
        font3.setFamily(QStringLiteral("DejaVu Serif"));
        font3.setPointSize(10);
        edit_path->setFont(font3);
        edit_path->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        edit_path->setStyleSheet(QStringLiteral("color:#000000;"));
        edit_path->setFrameShape(QFrame::Box);
        edit_path->setFrameShadow(QFrame::Plain);
        edit_path->setReadOnly(true);
        edit_path->setAcceptRichText(false);

        verticalLayout->addWidget(edit_path);

        spacer03 = new QSpacerItem(20, 12, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(spacer03);

        frame_action = new QFrame(FormCliparts);
        frame_action->setObjectName(QStringLiteral("frame_action"));
        frame_action->setFrameShape(QFrame::NoFrame);
        frame_action->setFrameShadow(QFrame::Plain);
        frame_action->setLineWidth(0);
        frame_button_layout = new QHBoxLayout(frame_action);
        frame_button_layout->setSpacing(0);
        frame_button_layout->setObjectName(QStringLiteral("frame_button_layout"));
        frame_button_layout->setContentsMargins(0, 0, 0, 0);
        frame_action_spacer01 = new QSpacerItem(280, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        frame_button_layout->addItem(frame_action_spacer01);

        button_action = new QPushButton(frame_action);
        button_action->setObjectName(QStringLiteral("button_action"));
        button_action->setEnabled(false);
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(button_action->sizePolicy().hasHeightForWidth());
        button_action->setSizePolicy(sizePolicy3);
        button_action->setFlat(false);

        frame_button_layout->addWidget(button_action);

        frame_action_spacer02 = new QSpacerItem(8, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        frame_button_layout->addItem(frame_action_spacer02);


        verticalLayout->addWidget(frame_action);

        bottom_spacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(bottom_spacer);


        retranslateUi(FormCliparts);

        QMetaObject::connectSlotsByName(FormCliparts);
    } // setupUi

    void retranslateUi(QWidget *FormCliparts)
    {
        FormCliparts->setWindowTitle(QApplication::translate("FormCliparts", "Form", nullptr));
        main_title->setText(QApplication::translate("FormCliparts", "Cliparts library", nullptr));
        label_path->setText(QApplication::translate("FormCliparts", "Path :", nullptr));
        button_clear->setText(QApplication::translate("FormCliparts", "Delete", nullptr));
        button_browse->setText(QApplication::translate("FormCliparts", "...", nullptr));
        button_action->setText(QApplication::translate("FormCliparts", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormCliparts: public Ui_FormCliparts {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCLIPARTS_H
