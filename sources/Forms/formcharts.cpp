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

FormCharts::FormCharts(One_Layered_Canvas& app_canvas, QWidget *parent) :
    QWidget(parent), One_Form(app_canvas), ui(new Ui::FormCharts) {

    ui->setupUi(this);
}

FormCharts::~FormCharts()
{
    delete ui;
}
