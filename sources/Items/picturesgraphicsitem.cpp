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
    ptr->getPictureValues(path, height, width,  black_white, opacity, lg_txt, lg_font, lg_size, lg_color, lg_pos);
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
    painter->setRenderHint(QPainter::Antialiasing);

    QPixmap img(path);
    QPixmap pixmap_img;
    QImage  image1(img.toImage());

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

    lg_font.setPointSize(lg_size);

    painter->setFont(QFont(lg_font));

    QPen penHText(lg_color);
    painter->setPen(penHText);
/*
    int pixelsWide = fm.width(lg_txt);
    int pixelsHigh = fm.height();
  const QRect rect_txt = QRect(0, 0, pixelsWide,  pixelsHigh);
*/
    const QRect rect = QRect(0, 0, width, height);


    if (lg_pos == "Left") {
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

int PicturesGraphicsItem::type() const
{
    return CustomTypes::PictureGraphicsItem;
}

// Getters
// -------

const QString& PicturesGraphicsItem::getPath() const
{
    return path;
}

const QString& PicturesGraphicsItem::getLegend() const
{
    return lg_txt;
}

const QString& PicturesGraphicsItem::getPosition() const
{
    return lg_pos;
}

const QColor& PicturesGraphicsItem::getFontColor() const
{
    return lg_color;
}

const QFont& PicturesGraphicsItem::getFont() const
{
    return lg_font;
}

bool PicturesGraphicsItem::isGrayscale() const
{
    return black_white;
}

int PicturesGraphicsItem::getWidth() const
{
    return width;
}

int PicturesGraphicsItem::getHeight() const
{
    return height;
}

int PicturesGraphicsItem::getOpacity() const
{
    return opacity;
}

int PicturesGraphicsItem::getFontSize() const
{
    return lg_size;
}


// Utils
// -----

void PicturesGraphicsItem::modification_width()
{
    QPixmap pixmap(path);
    pixmap = pixmap.scaledToWidth(width);
}


void PicturesGraphicsItem::modification_height()
{
    QPixmap pixmap(path);
    pixmap = pixmap.scaledToHeight(height);
}

