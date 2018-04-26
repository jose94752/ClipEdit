/*
================================================
* File:         formcliparts.cpp
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to create TextBoxItem
================================================
*/

// Includes
// --------

#include "formcliparts.h"

#include <QApplication>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

#include "../Classes/cpn_img_button.h"


// Constructor, destructor
// -----------------------

FormCliparts::FormCliparts(QWidget* parent):   QWidget(parent) {
//  <- setupUi
    if ( objectName().isEmpty() ) {
        setObjectName(QStringLiteral("FormCliparts"));
    }

    resize(520, 638);
    QFont font;
    font.setFamily(QStringLiteral("Arial"));
    font.setPointSize(12);
    setFont(font);
    verticalLayout = new QVBoxLayout(this);
    verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
    main_title = new QLabel(this);
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

    frame_path = new QFrame(this);
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

    button_clear = new My_Img_Button(frame_path);
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

    edit_path = new QTextEdit(this);
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

    frame_action = new QFrame(this);
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

    setWindowTitle(QApplication::translate("FormCliparts", "Form", nullptr));
    main_title->setText(QApplication::translate("FormCliparts", "Cliparts library", nullptr));
    label_path->setText(QApplication::translate("FormCliparts", "Path :", nullptr));
    button_browse->setText(QApplication::translate("FormCliparts", "...", nullptr));
    button_action->setText(QApplication::translate("FormCliparts", "Add", nullptr));

    QMetaObject::connectSlotsByName(this);
//  <- setupUi

    button_action->setEnabled(false);

    button_clear->set_image(My_Img_Button::IMG_ERASER);
    button_clear->setToolTip("Clear path");
    button_clear->setVisible(false);

    connect(button_browse, SIGNAL( clicked(bool) ), this, SLOT( event_on_click_browse(bool) ));
    connect(button_clear,  SIGNAL( on_click() ),    this, SLOT( event_on_click_clear() ));
}


void FormCliparts::event_on_click_browse(bool) {
    QString file_name = QFileDialog::getOpenFileName(this,
                                                     QStringLiteral("Sélectionner une bibliothèque"),
                                                     NULL,
                                                     QStringLiteral("Images (*.png *.jpg)"));

    if (!file_name.isEmpty()) {
        edit_path->setText(file_name);

        button_action->setEnabled(true);
        button_clear->setVisible(true);
    }
}


void FormCliparts::event_on_click_clear() {
    edit_path->clear();

    button_action->setEnabled(false);
    button_clear->setVisible(false);
}
