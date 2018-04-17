/*
================================================
* File:         formtextboxes.cpp
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to create TextBoxItem
================================================
*/

// Includes
// --------

#include "formtextboxes.h"
#include "ui_formtextboxes.h"

// Constructor, destructor
// -----------------------

FormTextBoxes::FormTextBoxes(QWidget *parent)
    :   QWidget(parent),
        ui(new Ui::FormTextBoxes)
{
    ui->setupUi(this);
}

FormTextBoxes::~FormTextBoxes()
{
    delete ui;
}
