/*
================================================
* File:         arrowsgraphicsitem.h
* Project:      ClipEdit
* Creation:     18/04/2018
* Brief:        Arrows GraphicsItem
*               Different options are proposed
*               to build arrows in ClipEdit
================================================
*/
#ifndef ARROWSGRAPHICSITEM_H
#define ARROWSGRAPHICSITEM_H

#include "Items/basegraphicitem.h"
#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QColor>

class ArrowsGraphicsItem
        //: public QGraphicsItem
        : public BaseGraphicItem
{
public:
    // 4 Type of Thickness outline lines 4 choices possibilities (1 - 4)
    enum { Type = UserType + 3 };

    ArrowsGraphicsItem(BaseGraphicItem *parent = 0);



    // Overriding of the Type
    int type() const override { return Type; }

    // Virtual method redefinition
    QRectF boundingRect() const override;

    QPainterPath shape() const override;

    // Set Fill Color of the Arrow
    //void setColor(const QColor &color) { ItemFillColorArrow = color; }

    // Set Outline Color of the Arrow
    //void setColorOutline(const QColor &color) { ItemOutlineColorArrow = color; }

    /* // For 2 objects anchors
    BaseGraphicItem *startItem() const { return m_StartItem; }
    BaseGraphicItem *endItem() const { return m_EndItem; }
    */

    void updateArrowPosition();


protected:
    // Virtual method redefinition
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;



private:
    BaseGraphicItem *m_StartItem;
    BaseGraphicItem *m_EndItem;

    //PositionItem *m_StartPositionItem;
    //PositionItem *m_EndPositionItem;

    QColor ItemOutlineColorArrow;
    QColor ItemFillColorArrow;



private slots:


};

#endif // ARROWSGRAPHICSITEM_H
