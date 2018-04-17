#include "formscreenshots.h"
#include "ui_formscreenshots.h"

Formscreenshots::Formscreenshots(CommonGraphicItem *parent) :
    CommonGraphicItem(parent),
    ui(new Ui::Formscreenshots)
{
    ui->setupUi(this);
    //

}

Formscreenshots::~Formscreenshots()
{
    delete ui;
}
