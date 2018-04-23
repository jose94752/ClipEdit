#include "picturesgraphicsitem.h"
#include <QGraphicsRectItem>
#include <QRect>
#include <QDebug>


PicturesGraphicsItem::PicturesGraphicsItem( FormPictures *ptr,QGraphicsItem* parent)
    :   BaseGraphicItem(parent)
{

    ptr->getPictureValues   (path, height,width,shade_grey,trans,lg_txt,lg_font,lg_size,lg_color,lg_pos);


    setRect(QRectF(0, 0, 300  , 300));
}



// Pure virtual methods implementation
// -----------------------------------


QRectF PicturesGraphicsItem::boundingRect() const
{
    return BaseGraphicItem::boundingRect();
}

void PicturesGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

  painter->drawPixmap( 0, 0, width, height,path);
  //painter->drawText( QRectF (0,0, width, height),"coucou");
  // painter->(boundingRect(), m_picture);


      const QRect rectangle = QRect(0, 0, 100, 50);
      QRect boundingRect;


      painter->setFont(lg_font);

      painter->drawText(rectangle, 0, lg_txt, &boundingRect);
/*
      QPen pen = painter->pen();
      pen.setStyle(Qt::DotLine);
      painter->setPen(pen);
      painter->drawRect(boundingRect.adjusted(0, 0, -pen.width(), -pen.width()));

      pen.setStyle(Qt::DashLine);
      painter->setPen(pen);
      painter->drawRect(rectangle.adjusted(0, 0, -pen.width(), -pen.width()));

*/





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
