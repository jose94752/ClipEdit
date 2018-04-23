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
#include <QFontMetrics>

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

    lg_font.setPointSize(lg_size);

   //painter->setFont(QFont("times",22));
    painter->setFont(QFont(lg_font));


    QFontMetrics fm(lg_font);

    QPen penHText(lg_color);
    painter->setPen(penHText);

    int pixelsWide = fm.width(lg_txt);
    int pixelsHigh = fm.height();
  const QRect rect_txt = QRect(0, 0, pixelsWide,  pixelsHigh);

  const QRect rect     = QRect(0, 0, width, height);

  QRect boundingRect;

  /*
   *
Qt::AlignLeft
Qt::AlignRight
Qt::AlignHCenter
Qt::AlignJustify
Qt::AlignTop
Qt::AlignBottom
Qt::AlignVCenter
Qt::AlignCenter
*/



   //painter->drawText(rect, 0, lg_txt, &boundingRect);



         if (lg_pos == "Left")    {
             painter->drawText(rect,  Qt::AlignLeft   , lg_txt);
             }
    else if (lg_pos == "Right")   {
             painter->drawText(rect,  Qt::AlignRight  , lg_txt);
             }
    else if (lg_pos == "HCenter") {
             painter->drawText(rect,  Qt::AlignHCenter, lg_txt);
             }
    else if (lg_pos == "Justify") {
             painter->drawText(rect,  Qt::AlignJustify, lg_txt);
             }
    else if (lg_pos == "Top")     {
             painter->drawText(rect,  Qt::AlignTop    , lg_txt);
             }
    else if (lg_pos == "Bottom")  {
             painter->drawText(rect,  Qt::AlignBottom , lg_txt);
             }
    else if (lg_pos == "VCenter") {
             painter->drawText(rect,  Qt::AlignVCenter, lg_txt);
             }
    else if (lg_pos == "Center")  {
             painter->drawText(rect,  Qt::AlignRight  , lg_txt);
             }
    else qDebug()  <<"choix alignement  invalide"  << lg_pos;




  // painter.drawText(5, 50 - (5*(i+1)) - 10, 20, 30, Qt::AlignHCenter | Qt::AlignVCenter, strNumber);
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
