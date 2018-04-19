#include "dialogscreenshots.h"
#include "ui_dialogscreenshots.h"

DialogScreenShots::DialogScreenShots(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogScreenShots)
{
    ui->setupUi(this);
}

DialogScreenShots::~DialogScreenShots()
{
    delete ui;
}
