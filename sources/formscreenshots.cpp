#include "formscreenshots.h"
#include "ui_formscreenshots.h"

Formscreenshots::Formscreenshots(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Formscreenshots)
{
    ui->setupUi(this);
}

Formscreenshots::~Formscreenshots()
{
    delete ui;
}
