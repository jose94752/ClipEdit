/*
====================================================
* File:         graphsgraphicsitem.h
* Project:      ClipEdit
* Creation:     18/04/2018
* Brief:        Inherit from BaseGraphicsItem
*               Define charts and related properties
====================================================
*/

#ifndef GRAPHSGRAPHICSITEM_H
#define GRAPHSGRAPHICSITEM_H

// Includes
// --------

#include <QWidget>
#include <QGraphicsItem>
#include <QString>

#include "basegraphicitem.h"


// Defines
// -------

// Classes
// -------
class GraphsInfo
{
public :
    QString m_title;
    QRectF m_boundingRect;
    QColor m_backColor;
    QColor m_color;

    int m_type;

    bool m_transparent;

    //values for pie and histogram
    QList<int> m_Arcs;

    //values for line
    QList<QPoint> m_Points;

    QFont m_titleFont;
    QFont m_legendFont;

    QList<QString> m_Legends;
    QList<QColor> m_Colors;


    QString m_xAxes;
    QString m_yAxes;
    //second serie for area
    //QList<QPoint> m_Points2;

};

class GraphsGraphicsItem : public BaseGraphicItem
{
    public:

        // Constructor
        GraphsGraphicsItem( QGraphicsItem* parent = 0);

        // Virtual methods from BaseGraphicItem
        QRectF boundingRect() const;
        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
        int type() const;

        // Getters and setters
        void setInfos(const GraphsInfo& infos);

    private:

        GraphsInfo m_infos;

        // local variables for drawing
        QRectF m_titleRect;
        QRectF m_legendRect;
        QRectF m_pictRect;

        // Drawing
        void drawPie(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
        void drawHisto(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        void drawLine(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


        //void drawArea(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        void drawTitle(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        void drawLegend(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

        void calculRects();

        void drawAxis(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif


