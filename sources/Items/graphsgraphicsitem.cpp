/*
====================================================
* File:         graphsgraphicsitem.cpp
* Project:      ClipEdit
* Creation:     18/04/2018
* Brief:        Inherit from BaseGraphicsItem
*               Define charts and related properties
====================================================
*/

// Includes
// --------

#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>

#include <QPaintDevice>
#include <QApplication>

#include "graphsgraphicsitem.h"


// Constructor
// -----------

GraphsGraphicsItem::GraphsGraphicsItem(QGraphicsItem* parent) : BaseGraphicItem( parent )
{
    //m_infos.m_boundingRect = {-100,-100,200,200};

    // setRect( QRectF(-50, -50, 100, 100));

    //setRect( QRectF(m_infos.m_boundingRect));
}


// Pure virtual methods implementation
// -----------------------------------

QRectF GraphsGraphicsItem::boundingRect() const
{
    //m_infos.m_boundingRect = {-100,-100,200,200};
    //return QRectF(0,0,500,500);

    //return m_infos.m_boundingRect;

    return BaseGraphicItem::boundingRect();
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

// Getters and setters
// -------------------

void  GraphsGraphicsItem::setInfos(const GraphsInfo& infos)
{
    qDebug() << "Set Infos";

    m_infos = infos;
    setRect( QRectF(m_infos.m_boundingRect));
    qDebug() << "Set Infos title " << m_infos.m_title;
}

// Drawing
// -------

/*
void GraphsGraphicsItem::drawPie(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    qDebug() << "Draw Pie";

    QColor col[] = {Qt::red, Qt::darkRed, Qt::green, Qt::darkGreen, Qt::blue, Qt::darkBlue, Qt::cyan,
            Qt::darkCyan, Qt::magenta, Qt::darkMagenta, Qt::yellow, Qt::darkYellow,
            Qt::gray, Qt::darkGray };

    //m_infos.m_boundingRect = {-100,-100,200,200};

    QBrush brush( m_infos.m_backColor);     //Qt::yellow
    painter->setBackground(m_infos.m_backColor);
    painter->fillRect(m_infos.m_boundingRect, brush);

    double rat = 10.0;
    for(int i = 0; i < rat; i++)
    {
        //QPen pen(0x059605);
        QPen pen( col[i]);
        pen.setWidth(3);
        painter->setPen(pen);
        //QBrush brush(0x059605);
        QBrush brush( col[i]);

        painter->setBrush(brush);
        double startArc = (double)i*360.0/rat*16.0, endArc = 360.0/rat*16.0;
        painter->drawPie(m_infos.m_boundingRect, startArc, endArc);
    }

    //    painter->drawPie(m_infos.m_boundingRect, 0, 10);
    BaseGraphicItem::paint(painter, option, widget);
}
*/


void GraphsGraphicsItem::drawPie(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    qDebug() << "Draw Pie";

    QColor col[] = {Qt::red, Qt::darkRed, Qt::green, Qt::darkGreen, Qt::blue, Qt::darkBlue, Qt::cyan,
            Qt::darkCyan, Qt::magenta, Qt::darkMagenta, Qt::yellow, Qt::darkYellow,
            Qt::gray, Qt::darkGray };

    //m_infos.m_boundingRect = {-100,-100,200,200};

    int nbPoints = m_infos.m_Arcs.size();
    //QRectF pictRect = m_infos.m_boundingRect;
    QRectF pictRect = m_rect;

    QFont font("times", 14);
    QFontMetrics fm(font);
    //pictRect.setWidth(pictRect.width()-fm.width());
    pictRect.setHeight(pictRect.height()-fm.height());

    //Qt::NoBrush
    Qt::BrushStyle style = Qt::SolidPattern; ;
    if( m_infos.m_transparent)
    {
        style = Qt::NoBrush;

    }
    QBrush brush( m_infos.m_backColor, style);     //Qt::yellow

    painter->setBackground(m_infos.m_backColor);
    painter->fillRect( pictRect, brush);

    int localArc = 0;
    int i = 0;
    if( m_infos.m_transparent)
    {
        style = Qt::Dense3Pattern;

    }
    for( i = 0; i < nbPoints; i++)
    {
        //QPen pen(0x059605);
        QPen pen( col[i]);
        pen.setWidth(0);
        painter->setPen(pen);
        //QBrush brush(0x059605);
        QBrush brush( col[i], style);
        painter->setBrush(brush);
        painter->drawPie( pictRect, localArc*16, m_infos.m_Arcs.at(i)*16);
        localArc += m_infos.m_Arcs.at(i);
    }
    if( localArc < 360)
    {
        QPen pen( col[i]);
        pen.setWidth(0);
        painter->setPen(pen);
        //QBrush brush(0x059605);
        QBrush brush( col[i], style);
        painter->setBrush(brush);
        painter->drawPie( pictRect, localArc*16, (360-localArc)*16);
    }

    QPen pen( m_infos.m_color);
    painter->setPen(pen);
    painter->setFont(font);

    QPoint tp ( pictRect.x()+pictRect.width()/2 - fm.width( m_infos.m_title)/2, pictRect.bottomRight().y()+fm.height());
    painter->drawText(tp, m_infos.m_title);

    BaseGraphicItem::paint(painter, option, widget);
}

