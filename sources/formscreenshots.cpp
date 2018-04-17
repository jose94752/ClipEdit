#include "formscreenshots.h"
#include "ui_formscreenshots.h"

FormScreenShots::FormScreenShots(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormScreenShots)
{
    ui->setupUi(this);
}

FormScreenShots::~FormScreenShots()
{
    delete ui;
}
