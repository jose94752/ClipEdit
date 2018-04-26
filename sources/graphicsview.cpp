/*
================================================
* File:         graphicsview.h
* Project:      ClipEdit
* Creation:     24/04/2018
* Brief:        Custom QGraphicsView implementation
================================================
*/

// Includes
// --------

#include <QDebug>
#include <QMouseEvent>
#include <QScrollBar>
#include <QColorDialog>
#include <QApplication>
#include <QDesktopWidget>
#include <QRectF>
#include <QBrush>

#include "graphicsview.h"

// Constructor
// -----------

GraphicsView::GraphicsView(QWidget* parent)
    :   QGraphicsView(parent)
{
    m_backgroundColor = Qt::white;
    connect(this->scene(),SIGNAL(changed(QList<QRectF>)),this,SLOT(sceneModified()));
}

void GraphicsView::setGraphicsRectItem(QGraphicsRectItem **v_graphRectItem)
{
    m_graphRectItem = v_graphRectItem;
}

// Events
// ------

void GraphicsView::mouseDoubleClickEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (itemAt(event->pos()))
        {
            // Item under the cursor
            QGraphicsItem* item = itemAt(event->pos());
            emit itemSelected(item);
        }
    }
}

void GraphicsView::mousePressEvent(QMouseEvent* event)
{
//    if (event->button() == Qt::RightButton)
//    {
//        setCursor(Qt::ClosedHandCursor);
//        m_oldPos = event->pos();
//    }

    if (event->button() == Qt::LeftButton)
    {
        // Enter drag mode
        setDragMode(QGraphicsView::ScrollHandDrag);
    }

    QGraphicsView::mousePressEvent(event);
}

void GraphicsView::mouseReleaseEvent(QMouseEvent* event)
{
//    if (event->button() == Qt::RightButton)
//    {
//        setCursor(Qt::ArrowCursor);
//    }

    if (event->button() == Qt::LeftButton)
    {
        // Leave drag mode
        setDragMode(QGraphicsView::NoDrag);
    }

    QGraphicsView::mouseReleaseEvent(event);
}

void GraphicsView::mouseMoveEvent(QMouseEvent* event)
{
//    if (event->buttons() & Qt::RightButton)
//    {
//        QPointF delta = event->pos() - m_oldPos;
//        horizontalScrollBar()->setValue(horizontalScrollBar()->value() + delta.x());
//        verticalScrollBar()->setValue(verticalScrollBar()->value() + delta.y());

//        m_oldPos = event->pos();
//    }

    QGraphicsView::mouseMoveEvent(event);
}

// Slots
// -----

void GraphicsView::clear()
{
    if (scene())
    {
        // Remove all items from the scene
        QRectF rect=(*m_graphRectItem)->rect();
        QBrush brush=(*m_graphRectItem)->brush();
        scene()->clear();
        scene()->setSceneRect(QRectF(0,0,rect.width()+1,rect.height()+1));
        *m_graphRectItem=scene()->addRect(rect);
        (*m_graphRectItem)->setBrush(brush);
    }
}

void GraphicsView::contentToView()
{
    if (scene())
    {
        // Rescale so that viewport shows all items
        fitInView(scene()->itemsBoundingRect());
        //emit scalingChanged()
    }
}

void GraphicsView::setZoomLevel(int zoom)
{
    qreal newScale = zoom / 100.f;

    // Rescale according from the current pos
    QMatrix oldMatrix = matrix();
    resetMatrix();
    translate(oldMatrix.dx(), oldMatrix.dy());
    scale(newScale, newScale);
}

void GraphicsView::changeBackgroundColor()
{
   QColor color = QColorDialog::getColor(m_backgroundColor, this);
   if(color.isValid())
   {
       m_backgroundColor = color;
       //this->setBackgroundBrush(QBrush(m_backgroundColor, Qt::SolidPattern));
       (*m_graphRectItem)->setBrush(QBrush(m_backgroundColor));
   }
}

void GraphicsView::sceneModified()
{
    //code
}
