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
#include<QGraphicsItem>
#include <QGraphicsRectItem>
#include<QRect>
#include<QPainter>
#include<QRectF>
#include<QRect>
#include<QPixmap>

#include<QStyle>
#include<QApplication>
#include<QDesktopWidget>
#include<QDebug>
#include "screenshotsgraphicsitem.h"

// Constructor, destructor
// -----------------------

//we subclass QGraphicItem and call the new class ScreenshotsGraphicsItem.
//The class' constructor accepts a pointer to a QGraphicItem item.
//This pointer is then passed to the constructor of the BaseGraphicItem.

ScreenshotsGraphicsItem::ScreenshotsGraphicsItem(FormScreenshots* ptr,    QGraphicsItem *parent)
        : BaseGraphicItem(parent)
 {
    Q_UNUSED(ptr)

    setFlag(BaseGraphicItem::ItemIsSelectable, true);

    //m_rect_sc(0,0,100,100) : default value.
   // setRect(QRectF(0, 0, 100, 100));

}

// Redefinition of the pure virtual methods
// -----------------------------------

QRectF ScreenshotsGraphicsItem::boundingRect() const
{
   // return BaseGraphicItem::boundingRect();
   return QRectF(0, 0, 75, 75);

}

void ScreenshotsGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        Q_UNUSED(option)
        Q_UNUSED(widget)

     qDebug() << "screenshot case";

     painter->fillRect(boundingRect(), Qt::red);

}

// Type
// ----

int ScreenshotsGraphicsItem::type() const{

    return CustomTypes::ScreenshotGraphicsItem;
}

// Getters and setters
// -------------------

//void ScreenshotsGraphicsItem::setRect(const QRectF& rect)
//{
//    if(rect == m_rect_sc)  return;

//    //This call is important to inform the scene about the coming geometry change.
//    //prepareGeometryChange();
//    //m_rect_sc = rect;
//}


//QRectF ScreenshotsGraphicsItem::getRect()
//{
//    return m_rect_sc;
//}











