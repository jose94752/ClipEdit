/*
================================================
* File:         formcliparts.h
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to create TextBoxItem
================================================
*/

#ifndef FORMCLIPARTS_H
#define FORMCLIPARTS_H

// Includes
// --------

#include <QVector>
#include <QWidget>

#include <QtWidgets/QWidget>

#include "baseform.h"


// Forward Declarations
class QFrame;
class QHBoxLayout;
class QLabel;
class QPushButton;
class QSpacerItem;
class QTextEdit;
class QVBoxLayout;
class My_Img_Button;


// Class
// -----

class FormCliparts
    :   public BaseForm
{
    Q_OBJECT

    // Constructor & Destructor
    public:

        explicit FormCliparts(QWidget* parent = 0);

//      ~FormCliparts() {]}

    // Load data
    void loadFromItem(BaseGraphicItem* item) const;


    private slots:

        void event_on_click_browse(bool);

        void event_on_click_clear();


    private:
//      ui
        My_Img_Button* button_clear;

        QVBoxLayout *verticalLayout;
        QLabel *main_title;
        QSpacerItem *spacer01;
        QFrame *frame_path;
        QHBoxLayout *frame_path_layout;
        QLabel *label_path;
        QSpacerItem *frame_path_spacer01;
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
};

#endif
