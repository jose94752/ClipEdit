#include "picturesgraphicsitem.h"
#include <QGraphicsRectItem>
#include <QRect>


PicturesGraphicsItem::PicturesGraphicsItem( FormPictures *ptr,QGraphicsItem* parent)
    :   BaseGraphicItem(parent)
{

    ptr->getPictureValues   (height,width,shade_grey,trans,lg_txt,lg_font,lg_size,lg_color,lg_pos);


     srand(time(NULL));
    int range = 300 - (-300) + 1;
    setPos(-300 + (rand() % range) , -300 + (rand() % range));

    setRect(QRectF(-50, -50, 100, 100));
}



// Pure virtual methods implementation
// -----------------------------------


QRectF PicturesGraphicsItem::boundingRect() const
{
    return  QRectF (0,0, width, height);

   // return BaseGraphicItem::boundingRect();
}

void PicturesGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  painter->drawText( QRectF (0,0, width, height),"coucou");
  // painter->(boundingRect(), m_picture);

    BaseGraphicItem::paint(painter, option, widget);
}

int PicturesGraphicsItem::type() const
{
    return Type::ImageGraphicsItem;
}



/*

 QGraphicsRectItem *rectItem = new QGraphicsRectItem( QRect( -25, 25, 200, 40 ), 0, &scene );
  rectItem->setPen( QPen( Qt::red, 3, Qt::DashDotLine ) );
  rectItem->setBrush( Qt::gray );

 */
