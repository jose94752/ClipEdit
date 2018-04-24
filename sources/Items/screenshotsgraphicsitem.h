/*
================================================
* File:         screenshotsgraphicsitem.h
* Project:      ClipEdit
* Creation:     18/04/2018
* Brief:        Inherit from BaseGraphicsItem
*               Manage graphic view screenshots
================================================
*/

#ifndef SCREENSHOTSGRAPHICSITEM_H
#define SCREENSHOTSGRAPHICSITEM_H

// Includes
// --------
#include "basegraphicitem.h"
#include "../Forms/formscreenshots.h"

#include <QGraphicsItem>
#include <QRectF>
#include <QPointF>

// Class
// -----

class ScreenshotsGraphicsItem
    :   public QGraphicsItem
{
    public:

        // Constructor, destructor
        explicit ScreenshotsGraphicsItem(QGraphicsItem *parent = 0);


        // The virtual destructor makes sure that it gets called even if the class
        // is getting deleted through a base class pointer.
        virtual ~ScreenshotsGraphicsItem() {}

    public:

        // Pure virtual methods implementation
        QRectF boundingRect() const;
        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

        // Getters and setters
        QRectF getRect();
        void setRect(const QRectF& rect);

    private:

        QRectF m_rect_sc;

};

#endif
