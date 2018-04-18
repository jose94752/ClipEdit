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
#include "ui_formcliparts.h"

//#include "../Items/item_arrow.h"

// Constructor, destructor
// -----------------------

FormCliparts::FormCliparts(QWidget* parent)
    :   QWidget(parent), ui(new Ui::FormCliparts)
{

    ui->setupUi(this);

    connect(ui->test_button, SIGNAL( clicked(bool) ), this, SLOT( event_onClick(bool) ));
}


FormCliparts::~FormCliparts()
{
    delete ui;

    //list_arrows.clear();
}


void FormCliparts::event_onClick(bool)
{
//    ItemArrow* arrow = new ItemArrow();

//    if (arrow != NULL)
//    {
//        list_arrows.append(arrow);

//        canvas.add_widget(arrow);
//    }
}
