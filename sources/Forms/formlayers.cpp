/*
================================================
* File:         formlayers.cpp
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to create TextBoxItem
================================================
*/

// Includes
// --------

#include "formlayers.h"
#include "ui_formlayers.h"

// Constructor, destructor
// -----------------------

FormLayers::FormLayers(QWidget *parent)
    :   QWidget(parent), ui(new Ui::FormLayers)
{
    ui->setupUi(this);
}

FormLayers::~FormLayers()
{
    delete ui;
}

