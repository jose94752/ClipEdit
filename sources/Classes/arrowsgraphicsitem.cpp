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
#include <QGraphicsItem>
#include "ui_mainwindow.h"

ArrowsGraphicsItem::ArrowsGraphicsItem(BaseGraphicItem *parent)
    :   BaseGraphicItem(parent)
{

    // 3 Methods
    // Without anchor point:
    //          we need 2 points on the scene
    // 1 anchor point:
    //          we need 1 point on the scene and an object of scene
    //          or an object of scene and 1 point on the scene
    // 2 anchors points:
    //          we need 2 objects of scene
}


QRectF ArrowsGraphicsItem::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2,
                  20 + penWidth, 20 + penWidth);
}

QPainterPath ArrowsGraphicsItem::shape() const
{
    // To do
}

void ArrowsGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->drawRoundedRect(-10, -10, 20, 20, 5, 5);
    painter->drawRoundedRect(-10, -10, 20, 20, 5, 5);
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

}
