#ifndef GRAPHSGRAPHICSITEM_H
#define GRAPHSGRAPHICSITEM_H

#include <QWidget>
#include <QGraphicsItem>
#include <QString>

#include "Items/basegraphicitem.h"


#define NUMBERPOINTS  200


/*
int &vChartType, QString &vChartTitle, QString &vXAxis, QString &vYAxis,
                            QColor &vBackColor, QColor &vColor, int &vWidth, int &vHeight,
                            int &vScale, int &vRotate

*/



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
    int m_nbPoints;
    int m_rotate;
    int m_scale;
    QPointF m_xPoints[NUMBERPOINTS];
    QPointF m_yPoints[NUMBERPOINTS];
    QString m_legends[NUMBERPOINTS];

    QPointF m_Arcs[NUMBERPOINTS];

};


class GraphsGraphicsItem : public BaseGraphicItem
        //QGraphicsItem
{

public:
    GraphsGraphicsItem( QGraphicsItem* parent = 0);

    // Pure virtual methods implementation
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

    int type() const;

    // Getters and setters
    void setInfos(const GraphsInfo &infos);

    void drawPie(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:

    GraphsInfo m_infos;


};

#endif // GRAPHSGRAPHICSITEM_H


