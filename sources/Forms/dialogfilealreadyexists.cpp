#include "dialogfilealreadyexists.h"
#include "ui_dialogfilealreadyexists.h"

DialogFileAlreadyExists::DialogFileAlreadyExists(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogFileAlreadyExists)
{
    ui->setupUi(this);
    ui->label_warning->setStyleSheet("QLabel { color : red; }");
    connect(ui->pushButton_ok,SIGNAL(clicked(bool)),this,SLOT(close()));//open
}

DialogFileAlreadyExists::~DialogFileAlreadyExists()
{
    delete ui;
}
