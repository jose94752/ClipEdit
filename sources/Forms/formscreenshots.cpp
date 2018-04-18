/*
================================================
* File:         formforms.cpp
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to create TextBoxItem
================================================
*/

// Includes
// --------

#include "formscreenshots.h"
#include "ui_formscreenshots.h"

// Constructor, destructor
// -----------------------

FormScreenshots::FormScreenshots(QWidget* parent) :
    QWidget(parent), ui(new Ui::FormScreenshots)
{
    ui->setupUi(this);
}

FormScreenshots::~FormScreenshots()
{
    delete ui;
}

