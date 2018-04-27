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
#include <QSettings>

#include "basegraphicitem.h"

#define BAR     15        //pour les histogrames, la larguer d'une bare et la distance entre deux bares
#define SPACE   BAR/3



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
    QList<double> m_Arcs;

    //values for line
    QList<QPointF> m_Points;

    QFont m_titleFont;
    QFont m_legendFont;

    QList<QString> m_Legends;
    QList<QColor> m_Colors;
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

        QRectF m_pictRect;  //le rectangle a afficher, a l'ecran
        QRectF m_graphRect; //les coordonnes a afficher

        double m_heightBar;        //pour les histogrames, la larguer d'une bare et la distance entre deux bares
        double m_heightSpace;

        //values for pie
        QList< double> m_GraphArcs;

        //values for line and histogram
        QList<QPointF> m_GraphPoints;

        // Drawing
        void drawPie(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
        void drawHisto(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        void drawLine(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


        //void drawArea(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        void drawTitle(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        void drawLegend(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

        void calculRects();

        void drawAxis(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

        void calcSizesLine();
        void calcSizesHisto();

        //pour les lignes et histogrames
        QPointF transformPoint( const QPointF &pointGraph) const;
        void transformPointsLine();

        //pour les pies
        void transformArcsPie();

        //histogrames
        void transformPointsHisto();

        void getParameters(QSettings *settings,int itemIndex);
        void setParameters(QSettings *settings,int itemIndex);
};

#endif


