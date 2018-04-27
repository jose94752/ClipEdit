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
    types  << "Pie" << "Line" ;  // "Histogram"  ;
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
    infos.m_backColor = ui->qBackColor->getColor();
    infos.m_color = ui->qColor->getColor();

    infos.m_transparent = ui->bTransparent->isChecked();

    //vWidth = ui->qWidth->value();
    //vHeight = ui->qHeight->value();
    infos.m_boundingRect.setRect(0,0, ui->qWidth->value(), ui->qHeight->value());

    QString val = ui->qData->text();
    QStringList sl = val.split(",", QString::SkipEmptyParts);
    for (int i = 0; i < sl.size(); ++i)
    {
       double arc = sl.at(i).toDouble();
       infos.m_Arcs.append(arc);
       qDebug() << "points arcs added " << arc;
    }

    //points values for lines and histogrames
    //space on x axis for points
    //int dist =20;

    for (int i = 0; i < sl.size(); ++i)
    {
       //qDebug() << "points Y added " << sl.at(i) ;

       QPointF p (i, infos.m_Arcs.at(i) );        //dist*i
       infos.m_Points.append(p);
       //qDebug() << "points added " << p.x() << " " << p.y();
    }

    //colors
    infos.m_Colors << Qt::red << Qt::darkRed << Qt::green << Qt::darkGreen
                   << Qt::blue << Qt::darkBlue << Qt::cyan
            << Qt::darkCyan << Qt::magenta << Qt::darkMagenta
            << Qt::yellow << Qt::darkYellow
            << Qt::gray<< Qt::darkGray ;


    infos.m_titleFont.setFamily("times");
    infos.m_titleFont.setPointSize(18);

    infos.m_legendFont.setFamily("times");
    infos.m_legendFont.setPointSize(10);

    infos.m_Legends = ui->qLegends->text().split("," , QString::SkipEmptyParts);

    qDebug() << "Legends numero" << infos.m_Legends.size();

}



 void FormCharts::createChart()
 {
     qDebug() << "charts" ;

     GraphsInfo newGraphsInfo;
     GetChartsValues( newGraphsInfo);

     qDebug() << "charts"  << newGraphsInfo.m_title ;

     emit FormCreateChart( newGraphsInfo);

 }



