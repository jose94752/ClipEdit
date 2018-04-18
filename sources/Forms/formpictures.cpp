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

FormPictures::FormPictures(QWidget *parent)
    :   QWidget(parent), ui(new Ui::FormPictures)
{
    ui->setupUi(this);
}

FormPictures::~FormPictures()
{
    delete ui;
}

