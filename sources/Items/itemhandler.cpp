/*
================================================
* File:         itemhandler.cpp
* Project:      ClipEdit
* Creation:     19/04/2018
* Brief:        An interactible grip to manipulate
*               items in the scene
================================================
*/

// Includes
// --------

#include "itemhandler.h"

// Constructor
// -----------

ItemHandler::ItemHandler(QPointF pos, HandlerType type, HandlerShape shape, int size)
    :   m_pos(pos), m_type(type), m_shape(shape), m_size(size)
{
    // Define the bounding rect
    updateRect();
}

// Update bounding box
// -------------------

void ItemHandler::updateRect()
{
    m_rect.setRect(m_pos.x() - m_size / 2.0, m_pos.y() - m_size / 2.0, m_size, m_size);
}

// Getters and setters
// -------------------

QPointF ItemHandler::pos()
{
    return m_pos;
}

void ItemHandler::setPos(QPointF pos)
{
    m_pos = pos;
    updateRect();
}

ItemHandler::HandlerType ItemHandler::type()
{
    return m_type;
}

void ItemHandler::setType(ItemHandler::HandlerType type)
{
    m_type = type;
}

ItemHandler::HandlerShape ItemHandler::shape()
{
    return m_shape;
}

void ItemHandler::setShape(ItemHandler::HandlerShape shape)
{
    m_shape = shape;
}

int ItemHandler::size()
{
    return m_size;
}

void ItemHandler::setSize(int size)
{
    m_size = size;
    updateRect();
}

QRectF ItemHandler::boundingRect() const
{
    return m_rect;
}

