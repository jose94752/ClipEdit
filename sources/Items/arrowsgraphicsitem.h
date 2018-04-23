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

#include "basegraphicitem.h"
#include "../Forms/formarrows.h"
#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QColor>
#include <QPolygonF>


class ArrowsGraphicsItem
    :   public BaseGraphicItem
{
    public:

        // 4 Type of Thickness outline lines 4 choices possibilities (1 - 4)
        // 3 Methods
        // Without anchor point:
        //          we need 2 points on the scene
        // 1 anchor point:
        //          we need 1 point on the scene and an object of scene
        //          or an object of scene and 1 point on the scene
        // 2 anchors points:
        //          we need 2 objects of scene

        // Construtor Test
        //ArrowsGraphicsItem(BaseGraphicItem *parent = 0);
        ArrowsGraphicsItem(FormArrows* ptrFormArrows, QGraphicsItem* parent = 0);

        // Constructor Without anchor point
        //ArrowsGraphicsItem(QPointF *m_StartPositionItem, QPointF *m_EndPositionItem, QGraphicsItem *parent = 0);

        // Constructor 1 anchor point and Object
        //ArrowsGraphicsItem(QPointF *m_StartPositionItem, BaseGraphicItem *m_EndItem, QGraphicsItem *parent = 0);

        // Constructor 2 anchors points
        //ArrowsGraphicsItem(BaseGraphicItem *m_StartItem, BaseGraphicItem *m_EndItem, QGraphicsItem *parent = 0);

        // Overriding of the Type
        int type() const { return Type::ArrowGraphicsItem; }

        // Virtual method redefinition
        QRectF boundingRect() const;


        // Set Fill Color of the Arrow
        //void setColor(const QColor &color) { ItemFillColorArrow = color; }

        // Set Outline Color of the Arrow
        //void setColorOutline(const QColor &color) { ItemOutlineColorArrow = color; }

        /* // For 2 objects anchors
        BaseGraphicItem *startItem() const { return m_StartItem; }
        BaseGraphicItem *endItem() const { return m_EndItem; }
        */

        void GetInfosArrows(bool &WithoutAnchorPoint, bool &OneAnchorPoint, bool &TwoAnchorPoints,
                            int &ArrowWidth, int &ArrowHeight,
                            QColor &ArrowOutlineColor, QColor &ArrowFillColor,
                             int &LineThickness);
                            //To do
                            // comboBoxHeadTypeChoiceContents

        void updateArrowPosition();


    protected:

        // Virtual method redefinition
        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);


    private:

        bool m_WithoutAnchorPoint;
        bool m_OneAnchorPoint;
        bool m_TwoAnchorPoints;

        int m_ArrowWidth;
        int m_ArrowHeight;

        int m_LineThickness;

    //    BaseGraphicItem *m_StartItem;
    //    BaseGraphicItem *m_EndItem;

        QPointF *m_StartPositionItem;
        QPointF *m_EndPositionItem;

        QColor *ItemOutlineColorArrow;
        QColor *ItemFillColorArrow;

        QPolygonF ArrowHeadStart;
        QPolygonF ArrowHeadEnd;


        QColor m_Color; // Temp for test

    private slots:


};

#endif
