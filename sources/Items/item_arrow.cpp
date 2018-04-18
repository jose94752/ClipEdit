/*
================================================
* File:         item_arrow.h
* Project:      ClipEdit
* Creation:     18/04/2018
* Brief:        Inherited from CommonGraphicsItem
================================================
*/

// Includes
// --------

#include "item_arrow.h"

#include <QPainter>


ItemArrow::ItemArrow()
{
    is_pressed = false;
    setFlag(ItemIsMovable);
}


QRectF ItemArrow::boundingRect() const
{
    return QRectF(0,0,100,100);
}


void ItemArrow::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    is_pressed = true;
    update();
    QGraphicsItem::mousePressEvent(event);
}


void ItemArrow::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    is_pressed = false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}


void ItemArrow::paint(QPainter*                       painter,
                       const QStyleOptionGraphicsItem* option,
                       QWidget*                        widget)
{

    Q_UNUSED(option);
    Q_UNUSED(widget);

    QRectF rect = boundingRect();

    if (is_pressed) {
        QPen pen(Qt::red, 3);
        painter->setPen(pen);
        painter->drawEllipse(rect);
    } else {
        QPen pen(Qt::black, 3);
        painter->setPen(pen);
        painter->drawRect(rect);
    }
}
