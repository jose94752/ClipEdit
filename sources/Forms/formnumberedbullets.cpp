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

FormNumberedBullets::FormNumberedBullets(QWidget *parent)
    :   QWidget(parent), ui(new Ui::FormNumberedBullets)
{
    ui->setupUi(this);
}

FormNumberedBullets::~FormNumberedBullets()
{
    delete ui;
}

void FormNumberedBullets::get_info (qint8& from, qint8& to) {

}
