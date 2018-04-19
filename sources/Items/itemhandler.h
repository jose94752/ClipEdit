/*
================================================
* File:         itemhandler.h
* Project:      ClipEdit
* Creation:     19/04/2018
* Brief:        An interactible grip to manipulate
*               items in the scene
================================================
*/

#ifndef ITEMHANDLER_H
#define ITEMHANDLER_H

// Includes
// --------

#include <QRectF>
#include <QPointF>

// Class
// -----

class ItemHandler
{
    public:

        // Handler types
        enum HandlerType {
            HANDLER_TOP = 1,
            HANDLER_BOTTOM = 2,
            HANDLER_LEFT = 4,
            HANDLER_RIGHT = 8,
            HANDLER_TOP_LEFT = HANDLER_TOP | HANDLER_LEFT,
            HANDLER_TOP_RIGHT = HANDLER_TOP | HANDLER_RIGHT,
            HANDLER_BOTTOM_LEFT = HANDLER_BOTTOM | HANDLER_LEFT,
            HANDLER_BOTTOM_RIGHT = HANDLER_BOTTOM | HANDLER_RIGHT,
            HANDLER_ROTATION
        };

        // Handler shapes
        enum HandlerShape {
            HANDLER_SQUARE,
            HANDLER_CIRCLE
        };

        // Constructor
        ItemHandler(QPointF pos, HandlerType type, HandlerShape shape, int size = 10);

        // Update bounding box
        void updateRect();

        // Getters and setters
        QPointF pos();
        void setPos(QPointF pos);

        HandlerType type();
        void setType(HandlerType type);

        HandlerShape shape();
        void setShape(HandlerShape shape);

        int size();
        void setSize(int size);

        QRectF boundingRect() const;


    private:

        // Basic properties
        QPointF m_pos;
        HandlerType m_type;
        HandlerShape m_shape;
        QRectF m_rect;
        int m_size;

};

#endif
