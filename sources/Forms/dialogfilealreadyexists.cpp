#include "dialogfilealreadyexists.h"
#include "ui_dialogfilealreadyexists.h"

DialogFileAlreadyExists::DialogFileAlreadyExists(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogFileAlreadyExists)
{
    ui->setupUi(this);
}

DialogFileAlreadyExists::~DialogFileAlreadyExists()
{
    delete ui;
}
