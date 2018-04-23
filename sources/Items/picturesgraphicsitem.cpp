/*
================================================
* File:         picturesgraphicsitem.cpp
* Project:      ClipEdit
* Creation:     18/04/2018
* Brief:        Inherit from BaseGraphicsItem
*               Insert a picture in the scene
================================================
*/

#include <QDebug>
#include <QGraphicsRectItem>
#include <QRect>

#include "picturesgraphicsitem.h"

// Constructor
// -----------

PicturesGraphicsItem::PicturesGraphicsItem(FormPictures* ptr, QGraphicsItem* parent)
    :   BaseGraphicItem(parent)
{
<<<<<<< HEAD:sources/picturesgraphicsitem.cpp

    ptr->getPictureValues   (path, height,width,shade_grey,trans,lg_txt,lg_font,lg_size,lg_color,lg_pos);


    setRect(QRectF(0, 0, 300  , 300));
=======
    ptr->getPictureValues(path, height, width, grayscale, opacity, lg_txt, lg_font, lg_size, lg_color, lg_pos);
    setRect(QRectF(0, 0, 2000, 2000));
>>>>>>> b433c96ad64c2f15f3ede207b4f041a16ca4a28c:sources/Items/picturesgraphicsitem.cpp
}


// Pure virtual methods implementation
// -----------------------------------


QRectF PicturesGraphicsItem::boundingRect() const
{
    return BaseGraphicItem::boundingRect();
}

void PicturesGraphicsItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{

  painter->drawPixmap(0, 0, width, height, path);
  //painter->drawText( QRectF (0,0, width, height),"coucou");
  // painter->(boundingRect(), m_picture);

<<<<<<< HEAD:sources/picturesgraphicsitem.cpp

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





=======
>>>>>>> b433c96ad64c2f15f3ede207b4f041a16ca4a28c:sources/Items/picturesgraphicsitem.cpp
    BaseGraphicItem::paint(painter, option, widget);
}

// Type
// ----

int PicturesGraphicsItem::type() const
{
    return Type::ImageGraphicsItem;
}



/*

 QGraphicsRectItem *rectItem = new QGraphicsRectItem( QRect( -25, 25, 200, 40 ), 0, &scene );
  rectItem->setPen( QPen( Qt::red, 3, Qt::DashDotLine ) );
  rectItem->setBrush( Qt::gray );

 */
