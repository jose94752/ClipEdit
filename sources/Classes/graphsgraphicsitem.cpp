#include "graphsgraphicsitem.h"

#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QAreaSeries>

#include <QPaintDevice>
#include <QApplication>

QT_CHARTS_USE_NAMESPACE

GraphsGraphicsItem::GraphsGraphicsItem(QGraphicsItem* parent) : BaseGraphicItem( parent )
{

    //m_infos.m_boundingRect = {-100,-100,200,200};
}


// Pure virtual methods implementation
// -----------------------------------

QRectF GraphsGraphicsItem::boundingRect() const
{
    //m_infos.m_boundingRect = {-100,-100,200,200};
    //return QRectF(0,0,500,500);
    return m_infos.m_boundingRect;
}



void GraphsGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                               QWidget *widget)
{
    qDebug () << "paint GraphsGraphicsItem"  << endl;

    BaseGraphicItem::paint(painter, option, widget);

    this->drawPie(painter, option, widget);

}


int GraphsGraphicsItem::type() const
{
    return BaseGraphicItem::ChartGraphicsItem;
}


void  GraphsGraphicsItem::setInfos(const GraphsInfo &infos)
{
    m_infos = infos;
}


void GraphsGraphicsItem::drawPie(QPainter *painter, const QStyleOptionGraphicsItem *option,
                               QWidget *widget)
{

    qDebug() << "Draw Pie";


    QColor col[] = {Qt::red, Qt::darkRed, Qt::green, Qt::darkGreen, Qt::blue, Qt::darkBlue, Qt::cyan,
            Qt::darkCyan, Qt::magenta, Qt::darkMagenta, Qt::yellow, Qt::darkYellow,
            Qt::gray, Qt::darkGray };

    //m_infos.m_boundingRect = {-100,-100,200,200};

    QBrush brush( m_infos.m_backColor);     //Qt::yellow
    painter->setBackground(m_infos.m_backColor);
    painter->fillRect(m_infos.m_boundingRect, brush);

    for(int i = 0; i < 12; i++)
    {
        //QPen pen(0x059605);
        QPen pen( col[i]);
        pen.setWidth(3);
        painter->setPen(pen);
        //QBrush brush(0x059605);
        QBrush brush( col[i]);

        painter->setBrush(brush);
        painter->drawPie(m_infos.m_boundingRect, i*360/12*16, 360/12*16);
    }

//    painter->drawPie(m_infos.m_boundingRect, 0, 10);
}
