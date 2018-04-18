/*
================================================
* File:         formnumberedbullets.cpp
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to create TextBoxItem
================================================
*/

#include "formnumberedbullets.h"
#include "ui_formnumberedbullets.h"

FormNumberedBullets::FormNumberedBullets(One_Layered_Canvas& app_canvas, QWidget *parent) :
    QWidget(parent), One_Form(app_canvas), ui(new Ui::FormNumberedBullets) {

    ui->setupUi(this);
}

FormNumberedBullets::~FormNumberedBullets()
{
    delete ui;
}
