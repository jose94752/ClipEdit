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

#include "graphicsview.h"

// Constructor
// -----------

GraphicsView::GraphicsView(QWidget* parent)
    :   QGraphicsView(parent)
{
    m_backgroundColor=Qt::white;
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
    if (event->button() == Qt::RightButton)
    {
        setCursor(Qt::ClosedHandCursor);
        m_oldPos = event->pos();
    }

    QGraphicsView::mousePressEvent(event);
}

void GraphicsView::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::RightButton)
    {
        setCursor(Qt::ArrowCursor);
    }

    QGraphicsView::mouseReleaseEvent(event);
}

void GraphicsView::mouseMoveEvent(QMouseEvent* event)
{
    if (event->buttons() & Qt::RightButton)
    {
        QPointF delta = event->pos() - m_oldPos;
        horizontalScrollBar()->setValue(horizontalScrollBar()->value() + delta.x());
        verticalScrollBar()->setValue(verticalScrollBar()->value() + delta.y());

        m_oldPos = event->pos();
    }

    QGraphicsView::mouseMoveEvent(event);

}

// Slots
// -----

void GraphicsView::clear()
{
    if (scene())
    {
        // Remove all items from the scene
        scene()->clear();
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
    qreal s = zoom / 100.f;

    // Rescale
    resetMatrix();
    scale(s, s);
    /*QDesktopWidget *deskWidget=QApplication::desktop();
    int dpix=deskWidget->logicalDpiX();
    int dpiy=deskWidget->logicalDpiY();
    int width=210*dpix/25.4*s*1.01;
    int height=297*dpiy/25.4*s*1.01;
    setMaximumSize(width,height);*/
}

void GraphicsView::changeBackgroundColor()
{
   QColor color = QColorDialog::getColor(m_backgroundColor, this);
   if(color.isValid())
   {
       m_backgroundColor = color;
       this->setBackgroundBrush(QBrush(m_backgroundColor, Qt::SolidPattern));
   }
}
