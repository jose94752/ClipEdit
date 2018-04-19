/*
================================================
* File:         basegraphicitem.h
* Project:      ClipEdit
* Creation:     19/04/2018
* Brief:        Base class for ClipEdit items
================================================
*/

#ifndef BASEGRAPHICITEM_H
#define BASEGRAPHICITEM_H

// Includes
// --------

#include <QGraphicsItem>

class ItemHandler;

// Class
// -----

class BaseGraphicItem
    :   public QGraphicsItem
{
    public:

        // Constructor, destructor
        BaseGraphicItem(QGraphicsItem* parent = 0);
        virtual ~BaseGraphicItem();

        // Virtual pure methods
        virtual QRectF boundingRect() const;
        virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0);

        // Force a type for all subclasses
        virtual int type() const = 0;

        // Getters and setters
        void setRect(const QRectF& rect);

    protected:

        // Events
        //QVariant itemChange(GraphicsItemChange change, const QVariant& value);
        void mousePressEvent(QGraphicsSceneMouseEvent* event);
        void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
        void mouseMoveEvent(QGraphicsSceneMouseEvent* event);

        // Handlers methods
        void createHandlers();
        void updateHandlers();

        // Handlers properties
        QList<ItemHandler*> m_handlers;
        bool m_hasHandlers;
        int m_handlerSize;
        int m_heightForRotationHandler;

        // Bounding rect (use the setter to modify it)
        QRectF m_rect;
        bool m_drawBoundingRect;

    private:

        ItemHandler* m_current;
};

#endif
