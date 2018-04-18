/*
================================================
* File:         formcharts.cpp
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Options for Arrows
*               Different options are proposed
*               to build arrows in ClipEdit
================================================
*/

#include "formcharts.h"
#include "ui_formcharts.h"

FormCharts::FormCharts(QWidget* parent)
    :   QWidget(parent), ui(new Ui::FormCharts)
{
    ui->setupUi(this);
}

FormCharts::~FormCharts()
{
    delete ui;
}
