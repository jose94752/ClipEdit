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

#include <QColorDialog>
#include <QModelIndex>


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

 //   connect(ui->gGraphColors, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(tableColorChanged(QModelIndex) ) );
    connect(ui->gGraphColors, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(tableColorChanged( QTableWidgetItem*) ) );

}

FormCharts::~FormCharts()
{
    delete ui;
}

void FormCharts::initTableColors()
{
    QList<QColor> colors;
    colors << Qt::red << Qt::darkRed << Qt::green << Qt::darkGreen
           << Qt::blue << Qt::darkBlue << Qt::cyan
        << Qt::darkCyan << Qt::magenta << Qt::darkMagenta
        << Qt::yellow << Qt::darkYellow
        << Qt::gray<< Qt::darkGray ;

    qDebug() << "colors.size " << colors.size();

    CreateTableColors(colors);
}


//QTableWidgetItem*
//void FormCharts::tableColorChanged( QModelIndex model)
void FormCharts::tableColorChanged( QTableWidgetItem *tw)
{
    QBrush brush = tw->background();
    QColor color = QColorDialog::getColor( brush.color(), this);

    if ( color.isValid())
    {
        brush.setColor(color);
        tw->setBackground( brush);

       // m_color = color;
       // emit colorChanged(m_color);
       tw->setSelected(false);

       update();
    }
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

    infos.SetColors( ui->gGraphColors );

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
     qDebug() << "saveDefaultTheme CreateTableColors" << infos.GetColors() ;

     s.setValue( KFormChartsListColors, infos.GetColors() );

     // datas not saved
}


 //QList<QColor> *listColors

 void FormCharts::CreateTableColors( const QList<QColor> &listColors)
 {

     qDebug() << "colors.size " << listColors.size();
     QTableWidget *tw =  ui->gGraphColors;

     tw->clear();
     tw->setRowCount( listColors.size());
     tw->setColumnCount(1);
     tw->showGrid();

     for(int i=0; i < listColors.size(); i++)
     {
         QTableWidgetItem * newItem = new QTableWidgetItem( "");
         QBrush brush( listColors.at(i));
         newItem->setBackground( brush );
         tw->setItem( i /*row*/, 0 /*column*/, newItem );

      }
     tw->horizontalHeader()->hide();
     //tw->horizontalHeader()->show();
     tw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

     tw->verticalHeader()->hide();
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
     infos.m_transparent = s.value( KFormChartsTransparent, 1).toBool();

     QString strColors = s.value( KFormChartsListColors).toString();
     infos.SetColors( strColors);

     ui->qTitle->setText( infos.m_title);
     ui->qChartType->setCurrentIndex(infos.m_type);
     ui->qWidth->setValue( infos.m_boundingRect.width() );
     ui->qHeight->setValue( infos.m_boundingRect.height() );
     ui->qColor->setColor(infos.m_color);
     ui->qBackColor->setColor(infos.m_backColor);

     ui->bTransparent->setChecked(infos.m_transparent);

     qDebug() << "loadDefaultTheme CreateTableColors";

     CreateTableColors(infos.m_Colors);

     //datas not restored
 }


 /*
 QTableWidgetItem * newItem = new QTableWidgetItem( tr("%1").arg( (row + 1) * (column + 1) ) );
 tableWidget->setItem( row, column, newItem );

 tableWidget->setItem(8, 0, new QTableWidgetItem);
 tableWidget->item(8, 0)->setBackground(Qt::red);
*/
