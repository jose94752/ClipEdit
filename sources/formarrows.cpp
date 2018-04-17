#include "formarrows.h"
#include "ui_formarrows.h"

FormArrows::FormArrows(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormArrows)
{
    ui->setupUi(this);
}

FormArrows::~FormArrows()
{
    delete ui;
}
