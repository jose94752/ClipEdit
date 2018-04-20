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

    QStringList types;
    types << "Histogram" << "Pie" << "Area" << "Line";
    ui->qChartType->addItems(types);

}

FormCharts::~FormCharts()
{
    delete ui;
}


/* a mettre les axes
 */
void FormCharts::GetChartsValues(int &vChartType, QString &vChartTitle, QString &vXAxis, QString &vYAxis,
                            QColor &vBackColor, QColor &vColor, int &vWidth, int &vHeight,
                            int &vScale, int &vRotate  )
{
    vChartType = ui->qChartType->currentIndex();
    vChartTitle = ui->qTitle->text();
    vXAxis = ui->qXAxis->text();
    vYAxis = ui->qYAxis->text();
    vBackColor= ui->qBackColor->getColor();
    vColor = ui->qColor->getColor();
    vWidth = ui->qWidth->value();
    vHeight = ui->qHeight->value();
    vScale = ui->qScale->value();
    vRotate = ui->qRotate->value();

}
