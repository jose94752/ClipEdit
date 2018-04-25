/*
================================================
* File:         screenshotsgraphicsitem.cpp
* Project:      ClipEdit
* Creation:     18/04/2018
* Brief:        Inherit from BaseGraphicsItem
*               Manage graphic view screenshots
================================================
*/

// Includes
// --------
#include "screenshotsgraphicsitem.h"

#include<QGraphicsItem>
#include <QGraphicsRectItem>
#include<QRect>
#include<QPainter>
#include<QRectF>
#include<QRect>

#include<QStyle>
#include<QApplication>
#include<QDesktopWidget>

// Constructor, destructor
// -----------------------

//we subclass QGraphicItem and call the new class ScreenshotsGraphicsItem.
//The class' constructor accepts a pointer to a QGraphicItem item.
//This pointer is then passed to the constructor of the QGraphicItem.
ScreenshotsGraphicsItem::ScreenshotsGraphicsItem(FormScreenshots* ptr,    QGraphicsItem *parent)
        : BaseGraphicItem(parent)
 {
    Q_UNUSED(ptr)

    setFlag(BaseGraphicItem::ItemIsSelectable, true);
    //m_rect_sc(0,0,100,100) : default value.
    setRect(QRectF(0, 0, 100, 100));
}


// Getters and setters
// -------------------

void ScreenshotsGraphicsItem::setRect(const QRectF& rect)
{
    if(rect == m_rect_sc)  return;

    //This call is important to inform the scene about the coming geometry change.
    //prepareGeometryChange();
    //m_rect_sc = rect;
}


QRectF ScreenshotsGraphicsItem::getRect()
{
    return m_rect_sc;
}


// Pure virtual methods implementation
// -----------------------------------

QRectF ScreenshotsGraphicsItem::boundingRect() const
{
    return m_rect_sc;
}

void ScreenshotsGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->fillRect(boundingRect(), Qt::red);
}










