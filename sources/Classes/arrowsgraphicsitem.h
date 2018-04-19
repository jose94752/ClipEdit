#ifndef ARROWSGRAPHICSITEM_H
#define ARROWSGRAPHICSITEM_H

#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QColor>

class ArrowsGraphicsItem
        : public QGraphicsItem
{
    public:
    ArrowsGraphicsItem();

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

private:
    QColor ItemOutlineColorArrow;
    QColor ItemFillColorArrow;


private slots:


};

#endif // ARROWSGRAPHICSITEM_H
