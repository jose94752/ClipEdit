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

#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QRect>
#include <QPainter>
#include <QRectF>
#include <QRect>
#include <QPixmap>

#include <QStyle>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>

// Constructor, destructor
// -----------------------

//we subclass QGraphicItem and call the new class ScreenshotsGraphicsItem.
//The class' constructor accepts a pointer to a QGraphicItem item.
//This pointer is then passed to the constructor of the BaseGraphicItem.

ScreenshotsGraphicsItem::ScreenshotsGraphicsItem(QPixmap pix, QGraphicsItem *parent)
        : BaseGraphicItem(parent)
 {
   // Q_UNUSED(pix)

    m_pix = pix;


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
        Q_UNUSED(option);
        Q_UNUSED(widget);

//      qDebug() << m_rect_sc;

       // painter->drawPixmap(m_rect_sc.toRect(),m_pix);
       //painter->drawPixmap(m_rect_sc.toRect(),  m_pix);
       painter->drawPixmap(((painter->viewport().width()  - m_pix.rect().width())  / 1.33333f),
                           ((painter->viewport().height() - m_pix.rect().height()) * 1.66666f),
                           m_pix);





}

// Type
// ----

int ScreenshotsGraphicsItem::type() const{

    return CustomTypes::ScreenshotGraphicsItem;
}

// Getters and setters
// -------------------

void ScreenshotsGraphicsItem::setRect(const QRectF& rect)
{
    if(rect == m_rect_sc)  return;

    //This call is important to inform the scene about the coming geometry change.
    //prepareGeometryChange();
    m_rect_sc = rect;
}


QRectF ScreenshotsGraphicsItem::getRect()
{
    return m_rect_sc;
}











