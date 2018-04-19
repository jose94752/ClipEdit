#ifndef PICTURESGRAPHICSITEM_H
#define PICTURESGRAPHICSITEM_H
#include <QGraphicsItem>
#include "Items/basegraphicitem.h"
#include <QPainter>

class PicturesGraphicsItem  : public BaseGraphicItem
{
public:
    PicturesGraphicsItem(QGraphicsItem* parent=0 );

    // Pure virtual methods implementation
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    int type() const ;


private:

    QPainter  m_picture;
};

#endif // PICTURESGRAPHICSITEM_H
