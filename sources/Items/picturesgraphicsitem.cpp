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

    ptr->getPictureValues(path, height, width, grayscale, opacity, lg_txt, lg_font, lg_size, lg_color, lg_pos);
    setRect(QRectF(0, 0, 2000, 2000));
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

  const QRect rectangle = QRect(0, 0, 100, 50);
  QRect boundingRect;


  painter->setFont(lg_font);
  painter->drawText(rectangle, 0, lg_txt, &boundingRect);

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
