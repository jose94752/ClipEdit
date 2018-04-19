#ifndef NUMBEREDBULLETGRAPHICITEM_H
#define NUMBEREDBULLETGRAPHICITEM_H
#include <QGraphicsItem>
#include <QRectF>

class NumberedBulletGraphicItem : public QGraphicsItem
{
public:
    NumberedBulletGraphicItem();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private :

};

#endif // NUMBEREDBULLETGRAPHICITEM_H
