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
    types  << "Pie" << "Histogram" << "Line" << "Area" ;
    ui->qChartType->addItems(types);

    ui->qColor->setColor( Qt::darkBlue);
    ui->qBackColor->setColor( Qt::yellow);

    connect(ui->qGo, SIGNAL(clicked(bool)), this, SLOT( createChart() ) );

}

FormCharts::~FormCharts()
{
    delete ui;
}


void FormCharts::GetChartsValues( GraphsInfo &infos)
{

    infos.m_type = ui->qChartType->currentIndex();
    infos.m_title = ui->qTitle->text();
    infos.m_xAxes = ui->qXAxis->text();
    infos.m_yAxes = ui->qYAxis->text();
    infos.m_backColor = ui->qBackColor->getColor();
    infos.m_color = ui->qColor->getColor();

    infos.m_transparent = ui->bTransparent->isChecked();

    //vWidth = ui->qWidth->value();
    //vHeight = ui->qHeight->value();
    infos.m_boundingRect.setRect(0,0, ui->qWidth->value(), ui->qHeight->value());

    QString val = ui->qData->text();
    QStringList sl = val.split(",");
    for (int i = 0; i < sl.size(); ++i)
    {
       int arc = sl.at(i).toInt();
       infos.m_Arcs.append(arc);
       //qDebug() << "points arcs added " << arc;
    }

    //points values for lines
    //space on x axis for points
    int dist =20;

    for (int i = 0; i < sl.size(); ++i)
    {
       //qDebug() << "points Y added " << sl.at(i) ;

       QPoint p( dist*i, infos.m_Arcs.at(i) );
       infos.m_Points.append(p);
       //qDebug() << "points added " << p.x() << " " << p.y();
    }

/*
    //Y values for line et area
    val = ui->qDataY->text();
    sl = val.split(",");

    for (int i = 0; i < sl.size(); ++i)
    {
       //qDebug() << "points Y added " << sl.at(i) ;

       QPoint p( infos.m_Arcs.at(i), sl.at(i).toInt() );
       infos.m_Points.append(p);
       //qDebug() << "points added " << p.x() << " " << p.y();
    }

    //second points series for area chart
    QString valX2 = ui->qDataX2->text();
    QStringList slX2 = valX2.split(",");

    QString valY2 = ui->qDataY2->text();
    QStringList slY2 = valY2.split(",");

    for (int i = 0; i < slX2.size(); ++i)
    {
       QPoint p( slX2.at(i).toInt(), slY2.at(i).toInt() );
       infos.m_Points2.append(p);
       qDebug() << "points added second serie" << p.x() << " " << p.y();
    }
*/

}



 void FormCharts::createChart()
 {
     qDebug() << "charts" ;

     GraphsInfo newGraphsInfo;
     GetChartsValues( newGraphsInfo);

     qDebug() << "charts"  << newGraphsInfo.m_title ;

     emit FormCreateChart( newGraphsInfo);

 }



