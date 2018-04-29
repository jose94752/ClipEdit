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
        //ArrowsGraphicsItem(FormArrows* ptrFormArrows, QPointF *m_StartPositionItem, QPointF *m_EndPositionItem, QGraphicsItem *parent = 0);

        // Constructor 1 anchor point and Object
        //ArrowsGraphicsItem(FormArrows* ptrFormArrows, QPointF *m_StartPositionItem, BaseGraphicItem *m_EndItem, QGraphicsItem *parent = 0);

        // Constructor 2 anchors points
        //ArrowsGraphicsItem(FormArrows* ptrFormArrows, BaseGraphicItem *m_StartItem, BaseGraphicItem *m_EndItem, QGraphicsItem *parent = 0);

        // Virtual methods from BaseGraphicItem
        QRectF boundingRect() const;
        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
        int type() const { return CustomTypes::ArrowGraphicsItem; }

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
                             int &LineThickness, int &SizeHeadTypeChoice);
                            //To do others HeadTypeChoiceContents
                            // comboBoxHeadTypeChoiceContents

        void updateArrowPosition();

        //renvoie du pointeur sur la form arrow
        FormArrows* getFormArrow();

        //renvoie des positions de début et de fin de flèches
        QPointF getStartPosition();
        QPointF getEndPosition();

        //return the ArrowHeadSize
        int getArrowHeadSize();

        //return the LineThicknessSize
        int getLineThicknessSize();

        //return the Item Fill Color Arrow
        QColor getFillColor();

private:

        bool m_WithoutAnchorPoint;
        bool m_OneAnchorPoint;
        bool m_TwoAnchorPoints;

        int arrowHeadSize; // <- arrowHeadSize is First issue of Arrow Head Size and is a temporary solution
        int m_ArrowWidth;
        int m_ArrowHeight;

        int m_LineThickness;

        int m_SizeHeadTypeChoice; // m_SizeHeadTypeChoice = arrowHeadSize; for the tests and temporary solution

    //    BaseGraphicItem *m_StartItem;
    //    BaseGraphicItem *m_EndItem;

        QPointF *m_StartPositionItem;
        QPointF *m_EndPositionItem;

        QColor m_Color; // Temp for test
        QColor *ItemOutlineColorArrow;
        QColor *ItemFillColorArrow;

        QPolygonF ArrowHeadStart;
        QPolygonF ArrowHeadEnd;

        FormArrows *m_formArrows;

    private slots:


};

#endif
