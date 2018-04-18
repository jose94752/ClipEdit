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

FormLayers::FormLayers(One_Layered_Canvas& app_canvas, QWidget *parent) :
    QWidget(parent), One_Form(app_canvas), ui(new Ui::FormLayers) {

    ui->setupUi(this);
}

FormLayers::~FormLayers()
{
    delete ui;
}

