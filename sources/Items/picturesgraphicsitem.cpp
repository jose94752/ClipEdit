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
#include <QImage>
#include <QRgb>


#include "picturesgraphicsitem.h"

// Constructor
// -----------

PicturesGraphicsItem::PicturesGraphicsItem(FormPictures* ptr, QGraphicsItem* parent)
    :   BaseGraphicItem(parent)
{
    //connect (  , SIGNAL(picture_changed_w_h( w_h)), this, SLOT(change_w_h(w_h)));


    ptr->getPictureValues(path, height, width, w_h_fixed, w_h, black_white, opacity, lg_txt, lg_font, lg_size, lg_color, lg_pos);


    setRect(QRectF(0, 0, width, height));

}


// Virtual methods from BaseGraphicItem
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



     if (w_h != ' ') {
         if (w_h_fixed) {
                 switch (w_h) {
                    case 'w':
                    modification_width();
                    break;

                    case 'h':
                    modification_height();
                    break;

                 }
         }
     }




  //   Pixmap qPix = QPixmap::grabWidget(ui->myWidget);
  //       QImage image(qPix.toImage());
  //       QColor color(image.pixel(0, 1));


     QPixmap img(path);
     QPixmap pixmap_img;

     QImage  image1(img.toImage());
     QColor  color(image1.pixel(0, 1));

     qDebug() <<"picturegraphics ; color  pixel 0-1 =" <<color;


     if (black_white) {
         qDebug() <<"black - white (1)";
         for (int i = 0; i < width; i++) {
             for (int j = 0; j < height; j++) {
                 int gray = qGray(image1.pixel(i, j));
                 image1.setPixel(i, j, QColor(gray, gray, gray).rgb());
             }
         }


           qDebug() <<"black - white (2)";

           pixmap_img.convertFromImage(image1);
           painter->drawPixmap(m_rect.toRect(),pixmap_img);
     }
      else {
           painter->drawPixmap(m_rect.toRect(),img);
      }


 //    qDebug() <<"picturegraphics: avt paint drawPixmap ===";
 //    painter->drawPixmap(m_rect.toRect(),img);

    w_h         = ' ';
    w_h_fixed   = false;
    black_white = false;

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


  BaseGraphicItem::paint(painter, option, widget);
}

// Type

int PicturesGraphicsItem::type() const
{
    return CustomTypes::PictureGraphicsItem;
}

// Utils
// -----

void PicturesGraphicsItem::modification_width () {
     qDebug() <<"modification_width, 2w";
     QPixmap pixmap(path);
     pixmap = pixmap.scaledToWidth( width );


}


void PicturesGraphicsItem::modification_height () {
        qDebug() <<"modification_height 2h";
        QPixmap pixmap(path);
        pixmap = pixmap.scaledToHeight( height );


}

//void PicturesGraphicsItem::change_w_h(char w_h){
//      qDebug() <<"dans PictureGraphic Slot, w_h="  <<w_h ;
//}
/*

 QGraphicsRectItem *rectItem = new QGraphicsRectItem( QRect( -25, 25, 200, 40 ), 0, &scene );
  rectItem->setPen( QPen( Qt::red, 3, Qt::DashDotLine ) );
  rectItem->setBrush( Qt::gray );

 */
