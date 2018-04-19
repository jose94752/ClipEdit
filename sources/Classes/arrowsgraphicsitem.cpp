#include "Classes/arrowsgraphicsitem.h"
#include<QGraphicsItem>
#include "mainwindow.h"
#include "ui_mainwindow.h"

ArrowsGraphicsItem::ArrowsGraphicsItem()

{

}


QRectF ArrowsGraphicsItem::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2,
                  20 + penWidth, 20 + penWidth);
}

void ArrowsGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRoundedRect(-10, -10, 20, 20, 5, 5);
}
