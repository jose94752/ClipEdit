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

//#define NUMBERPOINTS  200


/*
int &vChartType, QString &vChartTitle, QString &vXAxis, QString &vYAxis,
                            QColor &vBackColor, QColor &vColor, int &vWidth, int &vHeight,
                            int &vScale, int &vRotate

*/

// Classes
// -------

class GraphsInfo
{
public :
    QString m_title;
    QRectF m_boundingRect;
    QColor m_backColor;
    QColor m_color;
    QString m_xAxes;
    QString m_yAxes;
    int m_type;

    int m_rotate;
    int m_scale;

    //int m_nbPoints;
    //QPointF m_xPoints[NUMBERPOINTS];
    //QPointF m_yPoints[NUMBERPOINTS];
    //QString m_legends[NUMBERPOINTS];

    QList<int> m_Arcs;

};

class GraphsGraphicsItem
    :   public BaseGraphicItem
{
    public:

        // Constructor
        GraphsGraphicsItem(QGraphicsItem* parent = 0);

        // Pure virtual methods implementation
        QRectF boundingRect() const;
        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

        int type() const;

        // Getters and setters
        void setInfos(const GraphsInfo& infos);

        // Drawing
        void drawPie(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

    private:

        GraphsInfo m_infos;
};

#endif


