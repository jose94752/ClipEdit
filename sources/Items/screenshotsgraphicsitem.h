/*
================================================
* File:         screenshotsgraphicsitem.h
* Project:      ClipEdit
* Creation:     18/04/2018
* Brief:        Inherit from BaseGraphicsItem
*               Manage screenshot items
================================================
*/

#ifndef SCREENSHOTSGRAPHICSITEM_H
#define SCREENSHOTSGRAPHICSITEM_H

// Includes
// --------

#include "basegraphicitem.h"
#include "../Forms/formscreenshots.h"

// Class
// -----

class ScreenshotsGraphicsItem
    :   public BaseGraphicItem
{
    public:

        // Constructor, destructor
        explicit ScreenshotsGraphicsItem(const QPixmap& pix, QGraphicsItem* parent = 0);
        virtual ~ScreenshotsGraphicsItem() {}

        // Virtual methods from BaseGraphicItem
        QRectF boundingRect() const;
        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
        int type() const ;

        // Getters and setters
        void setScreenshot(const QPixmap& screenshot);

    private:

        QPixmap m_screenshot;
};

#endif
