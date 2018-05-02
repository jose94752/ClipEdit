/*
================================================
* File:         picturesgraphicsitem.h
* Project:      ClipEdit
* Creation:     18/04/2018
* Brief:        Inherit from BaseGraphicsItem
*               Insert a picture in the scene
================================================
*/

#ifndef PICTURESGRAPHICSITEM_H
#define PICTURESGRAPHICSITEM_H

// Includes
// --------

#include "basegraphicitem.h"
#include "../Forms/formpictures.h"

#include <QGraphicsItem>
#include <QPainter>

// Class
// -----

class PicturesGraphicsItem
    :   public BaseGraphicItem
{
    public:

        // Constructor
        PicturesGraphicsItem (FormPictures* ptr, QGraphicsItem* parent = 0);

        // Virtual methods from BaseGraphicItem
        QRectF boundingRect() const;
        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
        int type() const ;

        // Getters
        const QString& getPath() const;
        const QString& getLegend() const;
        const QString& getPosition() const;
        const QColor& getFontColor() const;
        const QFont& getFont() const;
        bool isGrayscale() const;
        int getWidth() const;
        int getHeight() const;
        int getOpacity() const;
        int getFontSize() const;

        // Edit size (@Laurent : They do nothing)
        void modification_width ();
        void modification_height();

        //saving methods
        void getParameters(QSettings* settings,int indexItem);
        void setParameters(QSettings* settings,int indexItem);

        // Properties (@Laurent: MUST BE SET TO PRIVATE LATER)
        QString path;
        int     height, width;
        int     opacity;
        bool    black_white;
        QString lg_txt;
        QFont   lg_font;
        int     lg_size;
        QColor  lg_color;
        QString lg_pos;
        QString lg_or;
};

#endif
