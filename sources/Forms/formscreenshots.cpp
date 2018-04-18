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

FormScreenshots::FormScreenshots(One_Layered_Canvas& app_canvas, QWidget *parent) :
    QWidget(parent), One_Form(app_canvas), ui(new Ui::FormScreenshots) {

    ui->setupUi(this);
}

FormScreenshots::~FormScreenshots()
{
    delete ui;
}

