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

///
/// \brief The BaseGraphicItem class
/// This is the abstract base class for all custom graphic items in ClipEdit
/// Inheriting from BaseGraphicItem means you have to implement your own type() method.
/// To do so, you can use the Type enum below which lists all custom graphic types used as return values
/// for each items that inherits from BaseGraphicItem.
///
/// Interactivity
/// BaseGraphicItem includes ItemHandler's that allows the user to rescale or rotate the item in the scene.
/// Don't forget to call BaseGraphicItem::paintEvent() in your custom item paintEvent(..) method.
/// You can disable this behaviour by setting the hasHandler flag to false as so:
///     item->setHasHandler(false);
///
/// Note : You can also set whether or not you want to draw the global bounding rectangle, edit the handlers size or the height
/// of the rotation handler (this one is displayed a few pixels above the content rect) with the associated setter.
///
/// Understanding the bounding rectangle
/// Due to the implementation of ItemHandler's as described above, dealing with the bounding rect is a bit particular.
/// The BaseGraphicItem class use a QRectF member called m_rect. This member can be described as the content rectangle.
/// In other words, this is the member you will use do change the dimensions of your item, as well as the one you should use
/// for your QPainter calls.
///
/// To change the m_rect member please use the setRect() method to also update the handlers position.
/// To add further explanations, BaseGraphicItem::boundingRect() adjust the m_rect member to include the handlers in order to avoid
/// draw artifacts without modifying the m_rect itself. As a result, the real bounding rectangle is bigger than than the rectangle m
/// defined by m_rect but you shouldn't draw outside of the m_rect rectangle.
/// As a result, in your custom item boundingRect() method you can:
///     - Use the default implementation (return BaseGraphicsItem::boudingRect()) [RECOMMANDED]
///     - Use a custom implementation similar to what is done in BaseGraphicItem
///
/// Basic example:
/// ==============
///
/// MyCustomItem::MyCustomItem(QGraphicsItem* parent) : BaseGraphicItem(parent)
/// {
///     // Let's fix a size here
///     setRect(-50, -50, 100, 100);
/// }
///
/// QRectF MyCustomItem::boundingRect() const
/// {
///     return BaseGraphicItem::boundingRect();
/// }
///
/// void MyCustomItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
/// {
///     // Insert your draw calls here
///     // Make sure to draw inside m_rect (defined by the setRect method)
///     painter->setRenderingHint(QPainter::Antialiasing);
///     painter->drawLine(m_rect.topLeft(), m_rect.bottomRight());
///
///     // Call the base paint method to draw handlers on top of your item
///     BaseGraphicItem::paint(painter, option, widget);
/// }

class BaseGraphicItem
    :   public QGraphicsItem
{
    public:

        // Item types to be use as return value for the type() method
        enum Type
        {
            TextBoxGraphicsItem = UserType+1,
            ImageGraphicsItem,
            ArrowGraphicsItem,
            ChartGraphicsItem,
            ScreenshotGraphicsItem,
            NumberedBulletGraphicsItem
        };

        // Constructors, destructor
        BaseGraphicItem(QGraphicsItem* parent = 0);
        BaseGraphicItem(const QRectF& rect, QGraphicsItem* parent = 0);
        BaseGraphicItem(const QRectF& rect, bool hasHandlers, bool drawBoundingRect, QGraphicsItem* parent = 0);
        virtual ~BaseGraphicItem();

        // Implementation of virtual pure methods from QGraphicsItem
        virtual QRectF boundingRect() const;
        virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0);

        // Type of the item
        // Return a type from the enum (add a new one in the enum above)
        virtual int type() const = 0;

        // Item information for storage
        //QMap<QString, QVariant> infos() = 0;

        // Getters and setters
        bool hasHandlers() const;
        void setHasHandlers(bool hasHandlers);

        bool drawBoundingRect() const;
        void setDrawBoundingRect(bool drawBoundingRect);

        int handlerSize() const;
        void setHandlerSize(int size);

        int heightForRotationHandler() const;
        void setHeightForRotationHandler(int height);

        void setRect(const QRectF& rect);
        void setNuLayer(int nuLayer);

        //void QMap<QString,QVariant> getInfos()=0;

    protected:

        // Events
        //QVariant itemChange(GraphicsItemChange change, const QVariant& value);
        void mousePressEvent(QGraphicsSceneMouseEvent* event);
        void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
        void mouseMoveEvent(QGraphicsSceneMouseEvent* event);

        // Handlers methods
        void createHandlers();
        void updateHandlers();
        void restrictPositions();

        // Handlers properties
        QList<ItemHandler*> m_handlers;
        bool m_hasHandlers;
        int m_handlerSize;
        int m_heightForRotationHandler;

        // Bounding rect (use the setter to modify it)
        QRectF m_rect;
        bool m_drawBoundingRect;

    private:

        int m_nuLayer;

        ItemHandler* m_current;
};

#endif
