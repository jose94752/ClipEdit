#include "screenshotsgraphicsitem.h"

#include<QGraphicsItem>
#include<QPainter>
#include<QRectF>
#include<QRect>

//we subclass QGraphicItem and call the new class ScreenshotsGraphicsItem.
//The class' constructor accepts a pointer to a QGraphicItem item.
//This pointer is then passed to the constructor of the QGraphicItem.
ScreenshotsGraphicsItem::ScreenshotsGraphicsItem(QGraphicsItem *parent)
        : QGraphicsItem(parent)
        , m_rect_sc(0,0,75,25){//m_rect_sc(0,0,75,25) : default value.

    setFlag(QGraphicsItem::ItemIsSelectable, true);
}

QRectF ScreenshotsGraphicsItem::boundingRect() const
{
    return m_rect_sc;
}


void ScreenshotsGraphicsItem::setRect(const QRectF& rect)
{
        if(rect == m_rect_sc)  return;

        //This call is important to inform the scene about the coming geometry change.
        prepareGeometryChange();
        m_rect_sc = rect;

}

QRectF ScreenshotsGraphicsItem::getRect()
{
    return m_rect_sc;
}

// Second Pure virtual method implementation

void ScreenshotsGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->fillRect(boundingRect(), Qt::red);
}








