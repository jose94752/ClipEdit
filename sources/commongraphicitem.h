/*
================================================
* File:         commongraphicitem.h
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Redefine a custom graphic
*               item as a base of all graphic
*               items in ClipEdit
================================================
*/

#ifndef COMMONGRAPHICITEM_H
#define COMMONGRAPHICITEM_H

// Includes
// --------

#include <QGraphicsItem>

// Class
// -----

class CommonGraphicItem
    : public QGraphicsItem
{
    public:

        // Constructors, destructor
        CommonGraphicItem(QGraphicsItem* parent);
        virtual ~CommonGraphicItem();

        // Pure virtual methods
        virtual QRectF boudingRect() const = 0;
        virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0) = 0;

    protected:

        // Protected section
        // Shared attributes go here

    private:

        // Private section
};

#endif
