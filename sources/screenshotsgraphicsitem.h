#ifndef SCREENSHOTSGRAPHICSITEM_H
#define SCREENSHOTSGRAPHICSITEM_H

//add
#include <QGraphicsItem>
//#include "Items/itemhandler.h"
#include <QRectF>
#include <QPointF>



class ScreenshotsGraphicsItem : public QGraphicsItem
{

public:
    // The Constructor and thedestructor
    explicit ScreenshotsGraphicsItem(QGraphicsItem *parent = 0);


    //the virtual destructor makes sure that it gets called even if the class
    //is getting deleted through a base class pointer.
    virtual ~ScreenshotsGraphicsItem() {}

public:
    // Pure virtual methods implementation
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    //QRect
   // QRect::getRect() const;

private:
    QRectF m_rect_sc;

};

#endif // SCREENSHOTSGRAPHICSITEM_H
