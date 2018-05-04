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


// Constructor, destructor
// -----------------------

FormCliparts::FormCliparts(QWidget* parent) : BaseFormItem(parent), ui(new Ui::FormCollections) {
    ui->setupUi(this);
}


// Load data
// ---------

void FormCliparts::loadFromItem(BaseGraphicItem* item) const
{
    (void) item;

    // TO DO : Cast the base item to your item
    // Then, import data from the casted item
}

// Translation
// -----------

void FormCliparts::retranslate()
{
    ui->retranslateUi(this);
}

// Getter add button
// -----------------

const QPushButton* FormCliparts::getAddButton() const
{
    return NULL;
}
