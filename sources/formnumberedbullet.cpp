#include "formnumberedbullet.h"
#include "ui_formnumberedbullet.h"

FormNumberedBullet::FormNumberedBullet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormNumberedBullet)
{
    ui->setupUi(this);
}

FormNumberedBullet::~FormNumberedBullet()
{
    delete ui;
}
