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

#include <QDebug>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QApplication>

#include "basegraphicitem.h"
#include "itemhandler.h"

// Constructor, destructor
// -----------------------

BaseGraphicItem::BaseGraphicItem(QGraphicsItem* parent)
    :   QGraphicsItem(parent)
{
    init();

    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemSendsGeometryChanges);
    createHandlers();
}

BaseGraphicItem::BaseGraphicItem(const QRectF& rect, QGraphicsItem* parent)
    :   QGraphicsItem(parent)
{
    init();

    setRect(rect);
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemSendsGeometryChanges);
    createHandlers();
}

BaseGraphicItem::BaseGraphicItem(const QRectF& rect, bool hasHandlers, bool drawBoundingRect, QGraphicsItem* parent)
    :   QGraphicsItem(parent)
{
    init();
    m_hasHandlers = hasHandlers;
    m_drawBoundingRect = drawBoundingRect;

    setRect(rect);
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemSendsGeometryChanges);
    createHandlers();
}

BaseGraphicItem::~BaseGraphicItem()
{
    for (int i = 0; i < m_handlers.size() ; i++)
        delete m_handlers[i];
}

// Default settings
// ----------------

void BaseGraphicItem::init()
{
    m_hasHandlers = true;
    m_drawBoundingRect = true;
    m_handlerSize = 8;
    m_heightForRotationHandler = 30;
    m_current = 0;
    m_collapseMode = CollapseMode::DefaultCollapse;

    m_handlerColor = QColor(227, 227, 227);
    m_selectBorderColor = QColor(Qt::blue);

    setAcceptHoverEvents(true);
}

// Getters and setters
// -------------------

bool BaseGraphicItem::hasHandlers() const
{
    return m_hasHandlers;
}

void BaseGraphicItem::setHasHandlers(bool hasHandlers)
{
    m_hasHandlers = hasHandlers;

    // Clear existing handlers if necessary
    if (!m_hasHandlers)
    {
        for (int i = 0; i < m_handlers.size(); i++)
            delete m_handlers[i];

        m_handlers.clear();
    }
    else
    {
        // Create handlers
        createHandlers();
    }

    update();
}

bool BaseGraphicItem::drawBoundingRect() const
{
    return m_drawBoundingRect;
}

void BaseGraphicItem::setDrawBoundingRect(bool drawBoundingRect)
{
    m_drawBoundingRect = drawBoundingRect;
    update();
}

int BaseGraphicItem::handlerSize() const
{
    return m_handlerSize;
}

void BaseGraphicItem::setHandlerSize(int size)
{
    m_handlerSize = size;

    for (int i = 0; i < m_handlers.size(); i++)
        m_handlers[i]->setSize(m_handlerSize);

    update();
}

int BaseGraphicItem::heightForRotationHandler() const
{
    return m_heightForRotationHandler;
}

void BaseGraphicItem::setHeightForRotationHandler(int height)
{
    m_heightForRotationHandler = height;

    for (int i = 0; i < m_handlers.size(); i++)
    {
        if (m_handlers[i]->type() == ItemHandler::HANDLER_ROTATION)
        {
            QPointF rotation(m_rect.left() + m_rect.width()/2.0, m_rect.top() - m_heightForRotationHandler);
            m_handlers[i]->setPos(rotation);
            break;
        }
    }

    update();
}

const QRectF& BaseGraphicItem::rect() const
{
    return m_rect;
}


void BaseGraphicItem::setRect(const QRectF& rect)
{
    m_rect = rect;
    updateHandlers();
}

void BaseGraphicItem::getParameters(QSettings *settings, int itemIndex)
{
    Q_UNUSED(settings)
    Q_UNUSED(itemIndex)
    //settings->setValue("item"+QString::number(itemIndex)+"/maVariable",m_maVariable);
}

void BaseGraphicItem::setParameters(QSettings *settings, int itemIndex)
{
    Q_UNUSED(settings)
    Q_UNUSED(itemIndex)
    //QVariant variantMaVariable=settings->value("item"+QString::number(itemIndex)+"/maVariable");
    //QMaVar m_maVariable=variantMaVariable.toQMaVar();
    //éventuellement fonction de rafraichissement graphique
}

// Handlers
// --------

void BaseGraphicItem::createHandlers()
{
    if (!m_hasHandlers)
        return;

    // Clear existing items
    if (m_handlers.size() > 0)
    {
        for (int i = 0; i < m_handlers.size() ; i++)
            delete m_handlers[i];

        m_handlers.clear();
    }

    QPointF top(m_rect.left() + m_rect.width()/2.0, m_rect.top());
    QPointF bottom(m_rect.left() + m_rect.width()/2.0, m_rect.bottom());
    QPointF left(m_rect.left(), m_rect.top() + m_rect.height() / 2.0);
    QPointF right(m_rect.right(), m_rect.top() + m_rect.height() / 2.0);
    QPointF rotation(m_rect.left() + m_rect.width()/2.0, m_rect.top() - m_heightForRotationHandler);

    m_handlers.append(new ItemHandler(top, ItemHandler::HANDLER_TOP, ItemHandler::HANDLER_SQUARE, m_handlerSize));
    m_handlers.append(new ItemHandler(bottom, ItemHandler::HANDLER_BOTTOM, ItemHandler::HANDLER_SQUARE, m_handlerSize));
    m_handlers.append(new ItemHandler(left, ItemHandler::HANDLER_LEFT, ItemHandler::HANDLER_SQUARE, m_handlerSize));
    m_handlers.append(new ItemHandler(right, ItemHandler::HANDLER_RIGHT, ItemHandler::HANDLER_SQUARE, m_handlerSize));
    m_handlers.append(new ItemHandler(m_rect.topLeft(), ItemHandler::HANDLER_TOP_LEFT, ItemHandler::HANDLER_SQUARE, m_handlerSize));
    m_handlers.append(new ItemHandler(m_rect.topRight(), ItemHandler::HANDLER_TOP_RIGHT, ItemHandler::HANDLER_SQUARE, m_handlerSize));
    m_handlers.append(new ItemHandler(m_rect.bottomLeft(), ItemHandler::HANDLER_BOTTOM_LEFT, ItemHandler::HANDLER_SQUARE, m_handlerSize));
    m_handlers.append(new ItemHandler(m_rect.bottomRight(), ItemHandler::HANDLER_BOTTOM_RIGHT, ItemHandler::HANDLER_SQUARE, m_handlerSize));
    m_handlers.append(new ItemHandler(rotation, ItemHandler::HANDLER_ROTATION, ItemHandler::HANDLER_CIRCLE, m_handlerSize));
}

void BaseGraphicItem::updateHandlers()
{
    if (!m_hasHandlers)
        return;

    QPointF top(m_rect.left() + m_rect.width()/2.0, m_rect.top());
    QPointF bottom(m_rect.left() + m_rect.width()/2.0, m_rect.bottom());
    QPointF left(m_rect.left(), m_rect.top() + m_rect.height() / 2.0);
    QPointF right(m_rect.right(), m_rect.top() + m_rect.height() / 2.0);
    QPoint rotation(m_rect.left() + m_rect.width()/2.0, m_rect.top() - m_heightForRotationHandler);

    for (int i = 0; i < m_handlers.size(); i++)
    {
        switch(m_handlers[i]->type())
        {
            case ItemHandler::HANDLER_TOP:
            {
                m_handlers[i]->setPos(top);
            } break;
            case ItemHandler::HANDLER_BOTTOM:
            {
                m_handlers[i]->setPos(bottom);
            } break;
            case ItemHandler::HANDLER_LEFT:
            {
                m_handlers[i]->setPos(left);
            } break;
            case ItemHandler::HANDLER_RIGHT:
            {
                m_handlers[i]->setPos(right);
            } break;
            case ItemHandler::HANDLER_TOP_LEFT:
            {
                m_handlers[i]->setPos(m_rect.topLeft());
            } break;
            case ItemHandler::HANDLER_TOP_RIGHT:
            {
                m_handlers[i]->setPos(m_rect.topRight());
            } break;
            case ItemHandler::HANDLER_BOTTOM_LEFT:
            {
                m_handlers[i]->setPos(m_rect.bottomLeft());
            } break;
            case ItemHandler::HANDLER_BOTTOM_RIGHT:
            {
               m_handlers[i]->setPos(m_rect.bottomRight());
            } break;
            case ItemHandler::HANDLER_ROTATION:
            {
                m_handlers[i]->setPos(rotation);
            } break;
        }
    }
}

void BaseGraphicItem::restrictPositions()
{
    if (!m_current)
        return;

    if (m_collapseMode == CollapseMode::DefaultCollapse)
    {
        if (m_current->type() & ItemHandler::HANDLER_TOP)
        {
            if (m_rect.top() > m_rect.bottom())
                m_rect.setTop(m_rect.bottom());
        }
        else if (m_current->type() & ItemHandler::HANDLER_BOTTOM)
        {
            if (m_rect.top() > m_rect.bottom())
                m_rect.setBottom(m_rect.top());
        }

        if (m_current->type() & ItemHandler::HANDLER_LEFT)
        {
            if (m_rect.left() > m_rect.right())
                m_rect.setLeft(m_rect.right());
        }
        else if (m_current->type() & ItemHandler::HANDLER_RIGHT)
        {
            if (m_rect.left() > m_rect.right())
                m_rect.setRight(m_rect.left());
        }
    }
    if (m_collapseMode == CollapseMode::ReverseCollapse)
    {
        if (m_current->type() & ItemHandler::HANDLER_TOP)
        {
            if (m_rect.top() > m_rect.bottom())
            {
               QTransform t(transform());
               int dx = m_rect.center().x();
               int dy = m_rect.bottom();
               t.translate(dx, dy);
               t.scale(1, -1);
               t.translate(-dx, -dy);
               setTransform(t, false);
            }
        }
        else if (m_current->type() & ItemHandler::HANDLER_BOTTOM)
        {
            if (m_rect.top() > m_rect.bottom())
            {
               QTransform t(transform());
               int dx = m_rect.center().x();
               int dy = m_rect.top();
               t.translate(dx, dy);
               t.scale(1, -1);
               t.translate(-dx, -dy);
               setTransform(t, false);
            }
        }

        if (m_current->type() & ItemHandler::HANDLER_LEFT)
        {
            if (m_rect.left() > m_rect.right())
            {
                QTransform t(transform());
                int dx = m_rect.right();
                int dy = m_rect.center().y();
                t.translate(dx, dy);
                t.scale(-1, 1);
                t.translate(-dx, -dy);
                setTransform(t, false);
            }
        }
        else if (m_current->type() & ItemHandler::HANDLER_RIGHT)
        {
            if (m_rect.left() > m_rect.right())
            {
                QTransform t(transform());
                int dx = m_rect.left();
                int dy = m_rect.center().y();
                t.translate(dx, dy);
                t.scale(-1, 1);
                t.translate(-dx, -dy);
                setTransform(t, false);
            }
        }
    }
}

void BaseGraphicItem::restrictMovement(QGraphicsSceneMouseEvent* event)
{
    if (!m_current)
        return;

    // Act according to mode

    if (m_collapseMode == CollapseMode::DefaultCollapse)
    {
        // Merge but no reverse

        int dx = event->pos().x() - event->lastPos().x();
        int dy = event->pos().y() - event->lastPos().y();

        if (m_current->type() & ItemHandler::HANDLER_TOP)
        {
            if (m_rect.top() + dy >= m_rect.bottom())
            {
                event->setPos(QPointF(event->pos().x(), m_rect.bottom()));
                event->setLastPos(event->pos());
            }
        }
        else if (m_current->type() & ItemHandler::HANDLER_BOTTOM)
        {
            if (m_rect.bottom() + dy <= m_rect.top())
            {
                event->setPos(QPointF(event->pos().x(), m_rect.top()));
                event->setLastPos(event->pos());
            }
        }

        if (m_current->type() & ItemHandler::HANDLER_LEFT)
        {
            if (m_rect.left() + dx >= m_rect.right())
            {
                event->setPos(QPointF(m_rect.right(), event->pos().y()));
                event->setLastPos(event->pos());
            }
        }
        else if (m_current->type() & ItemHandler::HANDLER_RIGHT)
        {
            if (m_rect.right() + dx <= m_rect.left())
            {
                event->setPos(QPointF(m_rect.left(), event->pos().y()));
                event->setLastPos(event->pos());
            }
        }
    }
    else if (m_collapseMode == CollapseMode::ReverseCollapse)
    {
        // Reverse if a handler reach its opposite handler
    }
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
    Q_UNUSED(option)
    Q_UNUSED(widget)

    if (isSelected())
    {
        QBrush brush(Qt::NoBrush);
        QPen pen(Qt::black);
        painter->setPen(pen);
        painter->setBrush(brush);

        // Save painter state
        painter->save();

        pen.setColor(m_selectBorderColor);
        painter->setPen(pen);
        painter->setBrush(brush);
        painter->setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

        // Bounding rectangle
        if (m_drawBoundingRect)
        {
            painter->drawRect(m_rect);
        }

        QPointF p1, p2;
        for (int i = 0; i < m_handlers.size(); i++)
        {
            if (m_handlers[i]->type() == ItemHandler::HANDLER_TOP)
            {
                p1 = m_handlers[i]->pos();
            }
            else if (m_handlers[i]->type() == ItemHandler::HANDLER_ROTATION)
            {
                p2 = m_handlers[i]->pos();
            }
        }

        // Draw the line between the rect and the rotation handler
        painter->drawLine(p1, p2);

        pen.setColor(Qt::black);
        painter->setPen(pen);

        // Handlers
        for (int i = 0; i < m_handlers.size(); i++)
        {
            if (m_handlers[i]->shape() == ItemHandler::HANDLER_SQUARE)
            {
                painter->drawRect(m_handlers[i]->boundingRect());
                painter->fillRect(m_handlers[i]->boundingRect(), m_handlerColor);
            }
            else if (m_handlers[i]->shape() == ItemHandler::HANDLER_CIRCLE)
            {
                QPainterPath path;
                path.addEllipse(m_handlers[i]->boundingRect());
                painter->fillPath(path, m_handlerColor);
                painter->drawPath(path);
                //painter->drawEllipse(m_handlers[i]->boundingRect());
            }
        }

        // Restore painter state
        painter->restore();
    }
}

// Shape
// -----

QPainterPath BaseGraphicItem::shape() const
{
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);

    if (this->isSelected())
    {
        foreach (ItemHandler* handle, m_handlers)
        {
            switch (handle->shape())
            {
                case ItemHandler::HANDLER_SQUARE:
                {
                    path.addRect(handle->boundingRect());
                } break;
                case ItemHandler::HANDLER_CIRCLE:
                {
                    path.addEllipse(handle->boundingRect());
                } break;
            }
        }
    }

    path.addRect(m_rect);
    return path;
}


// Events
// ------

void BaseGraphicItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsItem::mousePressEvent(event);

    // Find the selected handler
    if (event->buttons() == Qt::LeftButton)
    {
        for (int i = 0; i < m_handlers.size(); i++)
        {
            if (m_handlers[i]->boundingRect().contains(event->pos()))
            {
                m_current = m_handlers[i];
                break;
            }
        }
    }
}

void BaseGraphicItem::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsItem::mouseReleaseEvent(event);

    // Reset the current handler
    m_current = 0;
}

void BaseGraphicItem::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    // Here we are going to edit the bouding rect according to
    // the current handler movement

    if ((event->buttons() == Qt::LeftButton) && m_current)
    {
        prepareGeometryChange();
        //restrictMovement(event);

        switch(m_current->type())
        {
            case ItemHandler::HANDLER_TOP:
            {
                m_rect.setTop(event->pos().y());
            } break;
            case ItemHandler::HANDLER_BOTTOM:
            {
                m_rect.setBottom(event->pos().y());
            } break;
            case ItemHandler::HANDLER_LEFT:
            {
                m_rect.setLeft(event->pos().x());
            } break;
            case ItemHandler::HANDLER_RIGHT:
            {
                m_rect.setRight(event->pos().x());
            } break;
            case ItemHandler::HANDLER_TOP_LEFT:
            {
                m_rect.setTopLeft(event->pos());
            } break;
            case ItemHandler::HANDLER_TOP_RIGHT:
            {
                m_rect.setTopRight(event->pos());
            } break;
            case ItemHandler::HANDLER_BOTTOM_LEFT:
            {
                m_rect.setBottomLeft(event->pos());
            } break;
            case ItemHandler::HANDLER_BOTTOM_RIGHT:
            {
                m_rect.setBottomRight(event->pos());
            } break;
            case ItemHandler::HANDLER_ROTATION:
            {
                QPointF center = m_rect.center();

                // Transformation, move to the center then rotate
                int sign = (transform().det() > 0) ? 1 : -1;

                QTransform rotationTransform;
                rotationTransform.translate(center.x(), center.y());
                rotationTransform.rotate(sign * (-QLineF(event->scenePos(),mapToScene(center)).angle() + QLineF(event->lastScenePos(),mapToScene(center)).angle()));
                rotationTransform.translate(-center.x(), -center.y());
                setTransform(rotationTransform, true);
            } break;
            default:
            {
                QGraphicsItem::mouseMoveEvent(event);
            } break;
        }

        // Now we need to update the handlers position
        restrictPositions();
        updateHandlers();

        update();
    }
    else
    {
        QGraphicsItem::mouseMoveEvent(event);
    }
}

void BaseGraphicItem::hoverMoveEvent(QGraphicsSceneHoverEvent* event)
{
    for (int i = 0; i < m_handlers.size(); i++)
    {
        if (m_handlers[i]->boundingRect().contains(event->pos()))
        {
            switch (m_handlers[i]->type())
            {
                case ItemHandler::HANDLER_TOP:
                case ItemHandler::HANDLER_BOTTOM:
                    QApplication::setOverrideCursor(Qt::SizeVerCursor);
                break;
                case ItemHandler::HANDLER_LEFT:
                case ItemHandler::HANDLER_RIGHT:
                    QApplication::setOverrideCursor(Qt::SizeHorCursor);
                break;
                case ItemHandler::HANDLER_TOP_LEFT:
                case ItemHandler::HANDLER_BOTTOM_RIGHT:
                    QApplication::setOverrideCursor(Qt::SizeFDiagCursor);
                break;
                case ItemHandler::HANDLER_TOP_RIGHT:
                case ItemHandler::HANDLER_BOTTOM_LEFT:
                    QApplication::setOverrideCursor(Qt::SizeBDiagCursor);
                break;
                default:
                    QApplication::setOverrideCursor(Qt::ArrowCursor);
                break;
            }

            return;
        }
        else
        {
            QApplication::restoreOverrideCursor();
        }
    }
}

void BaseGraphicItem::hoverLeaveEvent(QGraphicsSceneHoverEvent* event)
{
    Q_UNUSED(event)

    QApplication::restoreOverrideCursor();
}

