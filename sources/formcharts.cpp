#include "formcharts.h"
#include "ui_formcharts.h"

FormCharts::FormCharts(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCharts)
{
    ui->setupUi(this);
}

FormCharts::~FormCharts()
{
    delete ui;
}
