#include "picturesgraphicsitem.h"
#include <QGraphicsRectItem>
#include <QRect>
#include <QDebug>


PicturesGraphicsItem::PicturesGraphicsItem( FormPictures *ptr,QGraphicsItem* parent)
    :   BaseGraphicItem(parent)
{

    ptr->getPictureValues   (path, height,width,shade_grey,trans,lg_txt,lg_font,lg_size,lg_color,lg_pos);


    setRect(QRectF(0, 0, 2000, 2000));
}



// Pure virtual methods implementation
// -----------------------------------


QRectF PicturesGraphicsItem::boundingRect() const
{
    return BaseGraphicItem::boundingRect();
}

void PicturesGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

  painter->drawPixmap( 0,0, width, height,path);
  //painter->drawText( QRectF (0,0, width, height),"coucou");
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
