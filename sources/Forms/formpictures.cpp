/*
================================================
* File:         formpictures.cpp
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to create TextBoxItem
================================================
*/

// Includes
// --------

#include "formpictures.h"
#include "ui_formpictures.h"

// Constructor, destructor
// -----------------------

FormPictures::FormPictures(One_Layered_Canvas& app_canvas, QWidget *parent) :
    QWidget(parent), One_Form(app_canvas), ui(new Ui::FormPictures) {

    ui->setupUi(this);
}

FormPictures::~FormPictures()
{
    delete ui;
}

