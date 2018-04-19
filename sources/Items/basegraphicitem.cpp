/*
================================================
* File:         basegraphicitem.cpp
* Project:      ClipEdit
* Creation:     19/04/2018
* Brief:        Base class for ClipEdit items
================================================
*/

// Includes
// --------

#include <QPainter>
#include <QGraphicsSceneMouseEvent>

#include "basegraphicitem.h"
#include "itemhandler.h"

// Constructor, destructor
// -----------------------

BaseGraphicItem::BaseGraphicItem(QGraphicsItem* parent)
    :   QGraphicsItem(parent)
{
    m_hasHandlers = true;
    m_drawBoundingRect = false;
    m_handlerSize = 10;
    m_heightForRotationHandler = 30;

    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemSendsGeometryChanges);
    createHandlers();
}

BaseGraphicItem::~BaseGraphicItem()
{
    for (int i = 0; i < m_handlers.size() ; i++)
        delete m_handlers[i];
}

// Handlers
// --------

void BaseGraphicItem::createHandlers()
{
    QPointF top(m_rect.left() + m_rect.width()/2.0, m_rect.top());
    QPointF bottom(m_rect.left() + m_rect.width()/2.0, m_rect.bottom());
    QPointF left(m_rect.left(), m_rect.top() + m_rect.height() / 2.0);
    QPointF right(m_rect.right() + m_rect.width()/2.0, m_rect.top() + m_rect.height() / 2.0);
    QPoint rotation(m_rect.left() + m_rect.width()/2.0, m_rect.top() - m_heightForRotationHandler);

    m_handlers.append(new ItemHandler(m_rect.topLeft(), ItemHandler::HANDLER_TOP_LEFT, ItemHandler::HANDLER_SQUARE, m_handlerSize));
    m_handlers.append(new ItemHandler(top, ItemHandler::HANDLER_TOP, ItemHandler::HANDLER_SQUARE, m_handlerSize));
    m_handlers.append(new ItemHandler(m_rect.topRight(), ItemHandler::HANDLER_TOP_RIGHT, ItemHandler::HANDLER_SQUARE, m_handlerSize));
    m_handlers.append(new ItemHandler(left, ItemHandler::HANDLER_LEFT, ItemHandler::HANDLER_SQUARE, m_handlerSize));
    m_handlers.append(new ItemHandler(right, ItemHandler::HANDLER_RIGHT, ItemHandler::HANDLER_SQUARE, m_handlerSize));
    m_handlers.append(new ItemHandler(m_rect.bottomLeft(), ItemHandler::HANDLER_BOTTOM_LEFT, ItemHandler::HANDLER_SQUARE, m_handlerSize));
    m_handlers.append(new ItemHandler(bottom, ItemHandler::HANDLER_BOTTOM, ItemHandler::HANDLER_SQUARE, m_handlerSize));
    m_handlers.append(new ItemHandler(m_rect.bottomRight(), ItemHandler::HANDLER_BOTTOM_RIGHT, ItemHandler::HANDLER_SQUARE, m_handlerSize));
    m_handlers.append(new ItemHandler(rotation, ItemHandler::HANDLER_ROTATION, ItemHandler::HANDLER_CIRCLE, m_handlerSize));
}

// Pure virtual methods override
// -----------------------------

QRectF BaseGraphicItem::boundingRect() const
{
    // Adjust the bounding rect to include the handlers
    // For inheriting class please call BaseGraphicItem::boundingRect() after setting the size in your custom item boudingRect() method
    return m_rect.adjusted(-m_handlerSize/2.0, -m_handlerSize/2.0 - m_heightForRotationHandler, m_handlerSize, m_handlerSize);
}

void BaseGraphicItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    // TO DO
}

// Events
// ------

// <TO DO>
