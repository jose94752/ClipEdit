#include "picturesgraphicsitem.h"


PicturesGraphicsItem::PicturesGraphicsItem( QGraphicsItem* parent)
    :   BaseGraphicItem(parent)
{
     srand(time(NULL));
    int range = 300 - (-300) + 1;
    setPos(-300 + (rand() % range) , -300 + (rand() % range));

    setRect(QRectF(-50, -50, 100, 100));
}



// Pure virtual methods implementation
// -----------------------------------

QRectF PicturesGraphicsItem::boundingRect() const
{
    return BaseGraphicItem::boundingRect();
}

void PicturesGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   // painter->(boundingRect(), m_picture);
    BaseGraphicItem::paint(painter, option, widget);
}

int PicturesGraphicsItem::type() const
{
    return Type::ImageGraphicsItem;
}
