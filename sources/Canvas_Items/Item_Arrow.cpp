#include "Item_Arrow.h"

#include <QPainter>


Item_Arrow::Item_Arrow() {
    is_pressed = false;
    setFlag(ItemIsMovable);
}


QRectF Item_Arrow::boundingRect() const {
    return QRectF(0,0,100,100);
}


void Item_Arrow::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    is_pressed = true;
    update();
    QGraphicsItem::mousePressEvent(event);
}


void Item_Arrow::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {
    is_pressed = false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}


void Item_Arrow::paint(QPainter*                       painter,
                       const QStyleOptionGraphicsItem* option,
                       QWidget*                        widget) {

    (void) option;
    (void) widget;

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
