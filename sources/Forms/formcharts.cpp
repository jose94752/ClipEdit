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
    types  << "Pie" << "Line" ;  // "Histogram"  ;
    ui->qChartType->addItems(types);

    //ui->qColor->setColor( Qt::darkBlue);
    //ui->qBackColor->setColor( Qt::yellow);

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

    //qDebug() << "Legends numero" << infos.m_Legends.size();

}



 void FormCharts::createChart()
 {
     qDebug() << "charts" ;

     GraphsInfo newGraphsInfo;
     GetChartsValues( newGraphsInfo);

     qDebug() << "charts"  << newGraphsInfo.m_title ;

     emit FormCreateChart( newGraphsInfo);

 }

 // Load data
 // ---------

 void FormCharts::loadFromItem(BaseGraphicItem* item) const
 {
     if (qgraphicsitem_cast<GraphsGraphicsItem*>(item))
     {
         GraphsGraphicsItem* castedItem = qgraphicsitem_cast<GraphsGraphicsItem*>(item);

         // Load data into the form
     }
 }



 // SLOTS

 void FormCharts::saveDefaultTheme ()
 //const
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

}

 void FormCharts::loadDefaultTheme()
 {
     //QColor
 /*
     QSettings q;
     int from(1), to(1), taille(1);
     from = q.value("FormNumberedBullets/from", from).toInt();
     to = q.value("FormNumberedBullets/to", to).toInt ();
     taille = q.value("FormNumberedBullets/size", taille).toInt ();

     QColor bulletcolor(Qt::blue), numbercolor(Qt::red);
     QString str_bulletcolor (bulletcolor.name()), str_numbercolor (numbercolor.name());
     str_bulletcolor = q.value("FormNumberedBullets/bulletcolor", str_bulletcolor).toString();
     str_numbercolor = q.value("FormNumberedBullets/numbercolor", str_numbercolor).toString ();
     bulletcolor.setNamedColor(str_bulletcolor);
     numbercolor.setNamedColor(str_numbercolor);

     int qfont_index(0);
     qfont_index = q.value("FormNumberedBullets/font", qfont_index).toInt();

     int index_shape(0);
     index_shape = q.value("FormNumberedBullets/shape", index_shape).toInt();

     ui->spinBox_From->setValue(from);
     ui->spinBox_To->setValue(to);
     ui->spinBox_Size->setValue (taille);
     ui->ColorButton_BulletColor->setColor(bulletcolor);
     ui->ColorBullet_NumberColor->setColor(numbercolor);
     ui->fontComboBox->setCurrentIndex(qfont_index);
     ui->comboBox_Shape->setCurrentIndex(index_shape);
 */

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

 }
