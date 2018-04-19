#ifndef ARROWSGRAPHICSITEM_H
#define ARROWSGRAPHICSITEM_H

#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>

class ArrowsGraphicsItem
        : public QGraphicsItem
{
    public:
    ArrowsGraphicsItem();

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

private:


private slots:
    //new

};

#endif // ARROWSGRAPHICSITEM_H
