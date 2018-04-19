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

        enum Type
        {
            TextBoxGraphicsItem = UserType+1,
            ImageGraphicsItem,
            ArrowGraphicsItem,
            ChartGraphicsItem,
            ScreenshotGraphicsItem,
            NumberedBulletGraphicsItem
        };

        // Constructor, destructor
        BaseGraphicItem(QGraphicsItem* parent = 0);
        BaseGraphicItem(const QRectF& rect, QGraphicsItem* parent = 0);
        BaseGraphicItem(const QRectF& rect, bool hasHandlers, bool drawBoundingRect, QGraphicsItem* parent = 0);
        virtual ~BaseGraphicItem();

        // Virtual pure methods
        virtual QRectF boundingRect() const;
        virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0);

        // Force a type for all subclasses
        virtual int type() const = 0;

        // Getters and setters
        bool hasHandlers() const;
        void setHasHandlers(bool hasHandlers);

        bool drawBoundingRect() const;
        bool setDrawBoundingRect(bool drawBoundingRect);

        int handlerSize() const;
        void setHandlerSize(int size);

        int heightForRotationHandler() const;
        void setHeightForRotationHandler(int height);

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
