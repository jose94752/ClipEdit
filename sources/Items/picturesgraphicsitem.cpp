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
#include <QPixmap>
#include <QPainter>

#include "picturesgraphicsitem.h"

// Constructor
// -----------

PicturesGraphicsItem::PicturesGraphicsItem(FormPictures* ptr, QGraphicsItem* parent)
    :   BaseGraphicItem(parent)
{
    //connect (  , SIGNAL(picture_changed_w_h( w_h)), this, SLOT(change_w_h(w_h)));


    ptr->getPictureValues(path, height, width, w_h_fixed, w_h, black_white, opacity, lg_txt, lg_font, lg_size, lg_color, lg_pos);

    ptr_1 = ptr;

    qDebug() <<"PicturesGraphicsItem (1), height ="  <<height  <<",  w_h = "  <<w_h  ;



    setRect(QRectF(0, 0, width, height));


}


// Pure virtual methods implementation
// -----------------------------------


QRectF PicturesGraphicsItem::boundingRect() const
{
    return BaseGraphicItem::boundingRect();
}

void PicturesGraphicsItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{


 //painter->drawPixmap(0, 0, width, height, path);
 //painter->drawText( QRectF (0,0, width, height),"coucou");
 // painter->(boundingRect(), m_picture);


 ptr_1->getPictureValues(path, height, width, w_h_fixed, w_h, black_white, opacity, lg_txt, lg_font, lg_size, lg_color, lg_pos);

 qDebug() <<"PicturesGraphicsItem (2), height = "  <<height <<",  width =" <<width  <<", w_h=" <<w_h;

  if (w_h == ' ')
  {
      painter->drawPixmap(0, 0, width, height, path);
      qDebug() <<"PicturesGraphicsItem (2a) (blanc) , Fixed="  <<w_h_fixed    <<", w_h = " <<w_h   ;
  }
  else {
      if (w_h_fixed) {
         switch ( w_h )
            {case 'w':
             modification_width(painter);

             case 'h':
             modification_height(painter);

             //default:
         }
      }
  }

    w_h = ' ';
    w_h_fixed = false;


    lg_font.setPointSize(lg_size);

   //painter->setFont(QFont("times",22));
    painter->setFont(QFont(lg_font));


    QFontMetrics fm(lg_font);

    QPen penHText(lg_color);
    painter->setPen(penHText);
/*
    int pixelsWide = fm.width(lg_txt);
    int pixelsHigh = fm.height();
  const QRect rect_txt = QRect(0, 0, pixelsWide,  pixelsHigh);
*/
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
    return CustomTypes::ImageGraphicsItem;
}

void PicturesGraphicsItem::modification_width (QPainter* p){
     qDebug() <<"modification_width, 2w";
     QPixmap pixmap(path);
     pixmap = pixmap.scaledToWidth( width );

     p->drawPixmap(0,0,pixmap );
}


void PicturesGraphicsItem::modification_height (QPainter* p){
        qDebug() <<"modification_height 2h";
        QPixmap pixmap(path);
        pixmap = pixmap.scaledToHeight( height );

        p->drawPixmap(0,0,pixmap );
}



void PicturesGraphicsItem::change_w_h(char w_h){
      qDebug() <<"dans PictureGraphic Slot, w_h="  <<w_h ;
}
/*

 QGraphicsRectItem *rectItem = new QGraphicsRectItem( QRect( -25, 25, 200, 40 ), 0, &scene );
  rectItem->setPen( QPen( Qt::red, 3, Qt::DashDotLine ) );
  rectItem->setBrush( Qt::gray );

 */
