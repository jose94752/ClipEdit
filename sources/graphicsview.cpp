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
}

void GraphicsView::setGraphicsRectItem(QGraphicsRectItem** v_graphRectItem)
{
    m_graphRectItem = v_graphRectItem;
}

void GraphicsView::setNbElts(int v_nbElts)
{
    m_nbSceneElts = v_nbElts;
}

// Events
// ------

void GraphicsView::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        // Enter drag mode
        setDragMode(QGraphicsView::ScrollHandDrag);
    }

    QGraphicsView::mousePressEvent(event);
}

void GraphicsView::mouseReleaseEvent(QMouseEvent* event)
{
    QGraphicsView::mouseReleaseEvent(event);

    if (event->button() == Qt::LeftButton)
    {
        // Leave drag mode
        setDragMode(QGraphicsView::NoDrag);
    }
}

void GraphicsView::mouseMoveEvent(QMouseEvent* event)
{
    QGraphicsView::mouseMoveEvent(event);
}

// Slots
// -----

void GraphicsView::clear()
{
    if (scene())
    {
        // Remove all items from the scene
        QRectF rect = (*m_graphRectItem)->rect();
        QBrush brush = (*m_graphRectItem)->brush();
        scene()->clear();
        //scene()->setSceneRect(QRectF(0,0,rect.width()+1,rect.height()+1));
        *m_graphRectItem = scene()->addRect(rect);
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
