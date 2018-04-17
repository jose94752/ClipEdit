#include "numberedbullets.h"
#include "ui_numberedbullets.h"

NumberedBullets::NumberedBullets(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NumberedBullets)
{
    ui->setupUi(this);
}

NumberedBullets::~NumberedBullets()
{
    delete ui;
}
