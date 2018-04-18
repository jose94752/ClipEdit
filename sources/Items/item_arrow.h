/*
================================================
* File:         item_arrow.h
* Project:      ClipEdit
* Creation:     18/04/2018
* Brief:        Inherited from CommonGraphicsItem
================================================
*/

#ifndef ITEM_ARROW_H
#define ITEM_ARROW_H

// Includes
// --------

#include <QGraphicsItem>

// Forward Declaration
class QPainter;

// Class
// -----

class ItemArrow : public QGraphicsItem
{
    // Constructor
    public:

        ItemArrow();


    // QGraphicsItem
    public:

        QRectF boundingRect() const;

        void paint(QPainter*                       painter,
                   const QStyleOptionGraphicsItem* option,
                   QWidget*                        widget);


    // Events
    protected:

        void mousePressEvent(QGraphicsSceneMouseEvent* event);

        void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);


    // Data Members
    private:

        bool is_pressed;
};


#endif
