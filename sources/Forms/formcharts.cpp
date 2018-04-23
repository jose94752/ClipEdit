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

#include "QDebug"

#include "formcharts.h"
#include "ui_formcharts.h"

FormCharts::FormCharts(QWidget* parent)
    :   QWidget(parent), ui(new Ui::FormCharts)
{
    ui->setupUi(this);

    QStringList types;
    types << "Histogram" << "Pie" << "Area" << "Line";
    ui->qChartType->addItems(types);

    //connect(ui->qGo, SIGNAL(clicked(bool)), this, )

    //connect(ui->actionArrow, SIGNAL(triggered(bool)),this,SLOT(slotArrowsGraphicsItem()));

    connect(ui->qGo, SIGNAL(clicked(bool)), this, SLOT( createChart() ) );

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


void FormCharts::GetChartsValues( GraphsInfo &infos)
{

    infos.m_type = ui->qChartType->currentIndex();
    infos.m_title = ui->qTitle->text();
    infos.m_xAxes = ui->qXAxis->text();
    infos.m_yAxes = ui->qYAxis->text();
    infos.m_backColor = ui->qBackColor->getColor();
    infos.m_color = ui->qColor->getColor();


    infos.m_scale = ui->qScale->value();
    infos.m_rotate = ui->qRotate->value();

    //vWidth = ui->qWidth->value();
    //vHeight = ui->qHeight->value();
    infos.m_boundingRect.setRect(0,0, ui->qWidth->value(), ui->qHeight->value());

    QString val = ui->qData->text();
    QStringList sl = val.split(",");

    for (int i = 0; i < sl.size(); ++i)
    {
       int arc = sl.at(i).toInt();
       infos.m_Arcs.append(arc);
    }
   // sl.
}



 void FormCharts::createChart()
 {
     qDebug() << "charts" ;

     GraphsInfo newGraphsInfo;
     GetChartsValues( newGraphsInfo);

     qDebug() << "charts"  << newGraphsInfo.m_title ;

     emit FormCreateChart( newGraphsInfo);

 }

/*
 QPushButton *FormCharts::getGoPushButton()
 {
     return ui->qGo;
 }
*/


