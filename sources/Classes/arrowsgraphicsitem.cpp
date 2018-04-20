/*
================================================
* File:         arrowsgraphicsitem.cpp
* Project:      ClipEdit
* Creation:     18/04/2018
* Brief:        Arrows GraphicsItem
*               Different options are proposed
*               to build arrows in ClipEdit
================================================
*/
#include "Classes/arrowsgraphicsitem.h"
#include "Classes/formarrows.h"
#include <QGraphicsItem>
#include "ui_mainwindow.h"

// Includes for drawing arrows
#include <QRect>
#include <QPen>
#include <QPainter>

// For Tests
#include <QDebug>



ArrowsGraphicsItem::ArrowsGraphicsItem(QGraphicsItem *parent)
    :   BaseGraphicItem(parent)
{
    // Temp dud BaseGraphicItem::paintEvent()
    //ArrowsGraphicsItem->setHasHandler(false);
    // End Temp
    //FormArrowsGetInfosArrows();

    // 3 Methods
    // Without anchor point:
    //          we need 2 points on the scene
    // 1 anchor point:
    //          we need 1 point on the scene and an object of scene
    //          or an object of scene and 1 point on the scene
    // 2 anchors points:
    //          we need 2 objects of scene

    myColor = Qt::black; // Temp for test
    //setPen(QPen(myColor, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    setPos(0, 0); // setPos for tests
    /*
For example:

  QPainter painter(this);
  QPen pen(Qt::green, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);
  painter.setPen(pen);

which is equivalent to

  QPainter painter(this);
  QPen pen;  // creates a default pen

  pen.setStyle(Qt::DashDotLine);
  pen.setWidth(3);
  pen.setBrush(Qt::green);
  pen.setCapStyle(Qt::RoundCap);
  pen.setJoinStyle(Qt::RoundJoin);

  painter.setPen(pen);



    */

}


QRectF ArrowsGraphicsItem::boundingRect() const
{
    /*
    qreal penWidth = 1;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2,
                  20 + penWidth, 20 + penWidth);
    */
    return BaseGraphicItem::boundingRect();
}

QPainterPath ArrowsGraphicsItem::shape() const
{
    // To do
//    QPainterPath path = QGraphicsLineItem::shape();
//    path.addPolygon(arrowHead);
//    return path;

}

void ArrowsGraphicsItem::paint(QPainter *arrowPainter, const QStyleOptionGraphicsItem *arrowQStyleOption, QWidget *arrowWidget)
{
    qDebug () << "\tAppel de ArrowsGraphicsItem::paint\n";

    // Examples of QRect:
    //QRect r1(100, 200, 11, 16);
    //QRect r2(QPoint(100, 200), QSize(11, 16))
    QRect *paintRectArrow = new QRect (100,200,11,16);


    BaseGraphicItem::paint(arrowPainter,arrowQStyleOption,arrowWidget);


}

void ArrowsGraphicsItem::updateArrowPosition()
{
    // Without anchor point method
    // To do

    // 1 anchor point method
    // To do

    //  2 anchors points method
    /* inactive no constructor for the moment
    QLineF line(mapFromItem(m_StartItem, 0, 0), mapFromItem(m_EndItem, 0, 0));
    setLine(line);
    */

    //Example
    //QLineF line(mapFromItem(myStartItem, 0, 0), mapFromItem(myEndItem, 0, 0));
    //setLine(line);
}
