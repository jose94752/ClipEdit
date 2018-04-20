#include "dialogscreenshots.h"
#include "ui_dialogscreenshots.h"

DialogScreenShots::DialogScreenShots(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogScreenShots)
{
    ui->setupUi(this);
    //connect
    //connect (ui->

DialogScreenShots::~DialogScreenShots()
{
    delete ui;

}

void DialogScreenShots::Capture()
{

}

void DialogScreenShots::CaptureWholeScreen()
{

}
