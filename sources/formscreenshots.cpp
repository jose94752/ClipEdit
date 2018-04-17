#include "formscreenshots.h"
#include "ui_formscreenshots.h"

formscreenshots::formscreenshots(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::formscreenshots)
{
    ui->setupUi(this);
}

formscreenshots::~formscreenshots()
{
    delete ui;
}
