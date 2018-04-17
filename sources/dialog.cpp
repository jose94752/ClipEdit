/*
================================================
* File:         dialog.cpp
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Give a description of the software,
*               its version and the sha of the git.
================================================
*/


#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
