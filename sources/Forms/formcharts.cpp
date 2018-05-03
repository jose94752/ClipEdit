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
    :   BaseForm(parent), ui(new Ui::FormCharts)
{
    ui->setupUi(this);

    QStringList types;
    types  << "Pie" << "Line" << "Histogram"  ;
    ui->qChartType->addItems(types);

    loadDefaultTheme();

    connect(ui->qGo, SIGNAL(clicked(bool)), this, SLOT( createChart() ) );
    connect(ui->qSaveTheme, SIGNAL(clicked(bool)), this, SLOT(saveDefaultTheme()));
    connect(ui->qApplyTheme, SIGNAL(clicked(bool)), this, SLOT(loadDefaultTheme()));

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
    infos.m_boundingRect.setRect(0,0, ui->qWidth->value(), ui->qHeight->value());

    infos.SetCoord( ui->qData->text() );
    infos.SetLegend( ui->qLegends->text() );

   // infos.m_Legends = ui->qLegends->text().split("," , QString::SkipEmptyParts);
    //qDebug() << "Legends numero" << infos.m_Legends.size();

}



 void FormCharts::createChart()
 {
     qDebug() << "charts" ;

     emit FormCreateChart();

 }

// Load data
// ---------

void FormCharts::loadFromItem(BaseGraphicItem* item) const
{
    if (qgraphicsitem_cast<GraphsGraphicsItem*>(item))
    {
         GraphsGraphicsItem* castedItem = qgraphicsitem_cast<GraphsGraphicsItem*>(item);

         qDebug() << "FormCharts::loadFromItem" ;

         GraphsInfo infos = castedItem->getInfos();

         // Load data into the form
         ui->qTitle->setText( infos.m_title);
         ui->qChartType->setCurrentIndex(infos.m_type);
         ui->qWidth->setValue( infos.m_boundingRect.width() );
         ui->qHeight->setValue( infos.m_boundingRect.height() );
         ui->qColor->setColor(infos.m_color);
         ui->qBackColor->setColor(infos.m_backColor);
         ui->bTransparent->setChecked(infos.m_transparent);

         ui->qData->setText(infos.GetCoord() );
         ui->qLegends->setText(infos.GetLegend() );
    }
}

// Translation
// -----------

void FormCharts::retranslate()
{
    ui->retranslateUi(this);
}



// SLOTS
// two icons on dialog, save and load
 void FormCharts::saveDefaultTheme ()
 {
     QSettings s;
     GraphsInfo infos;
     GetChartsValues( infos);

     s.setValue( KFormChartsTitle, infos.m_title);
     s.setValue( KFormChartsType, infos.m_type);
     s.setValue( KFormChartsWidth, infos.m_boundingRect.width() );
     s.setValue( KFormChartsHeight, infos.m_boundingRect.height());
     s.setValue( KFormChartsColor, infos.m_color.name());
     s.setValue( KFormChartsBackgroundcolor, infos.m_backColor.name());
     s.setValue( KFormChartsTransparent, infos.m_transparent);

     // datas not saved
}

 void FormCharts::loadDefaultTheme()
 {

     QSettings s;
     GraphsInfo infos;
     QColor color(Qt::blue), backcolor(Qt::yellow);

     infos.m_title = s.value(KFormChartsTitle).toString();
     infos.m_type = s.value(KFormChartsType, 0).toInt();
     infos.m_boundingRect.setWidth( s.value(KFormChartsWidth, 200).toInt() );
     infos.m_boundingRect.setHeight( s.value(KFormChartsHeight, 200).toInt() );
     infos.m_color.setNamedColor( s.value(KFormChartsColor, color).toString() );
     infos.m_backColor.setNamedColor( s.value(KFormChartsBackgroundcolor, backcolor).toString() );
     infos.m_transparent = s.value(KFormChartsTransparent, 1).toBool();

     ui->qTitle->setText( infos.m_title);
     ui->qChartType->setCurrentIndex(infos.m_type);
     ui->qWidth->setValue( infos.m_boundingRect.width() );
     ui->qHeight->setValue( infos.m_boundingRect.height() );
     ui->qColor->setColor(infos.m_color);
     ui->qBackColor->setColor(infos.m_backColor);

     ui->bTransparent->setChecked(infos.m_transparent);

     //datas not restored
 }
