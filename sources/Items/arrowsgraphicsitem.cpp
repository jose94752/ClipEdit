/*
================================================
* File:         arrowsgraphicsitem.cpp
* Project:      ClipEdit
* Creation:     18/04/2018
* Brief:        Arrows GraphicsItem
*               Different options are proposed
*               to build arrows in ClipEdit
================================================
*/

#include <QDebug>
#include <QGraphicsItem>
#include <QRect>
#include <QPen>
#include <QPainter>
#include <QtMath>

#include "arrowsgraphicsitem.h"
#include "../Forms/formarrows.h"
#include "ui_mainwindow.h"


ArrowsGraphicsItem::ArrowsGraphicsItem(QGraphicsItem *parent)
    :   BaseGraphicItem(parent)
{
    // Temp dud BaseGraphicItem::paintEvent()
    //ArrowsGraphicsItem->setHasHandler(false);
    // End Temp
    //FormArrowsGetInfosArrows();

    // 3 Methods
    // Without anchor point:
    //          we need 2 points on the scene
    // 1 anchor point:
    //          we need 1 point on the scene and an object of scene
    //          or an object of scene and 1 point on the scene
    // 2 anchors points:
    //          we need 2 objects of scene


    //m_StartItem = startItem;
    //m_EndItem = endItem;
    //m_StartPositionItem = startItem.{à définir}scenePos();
    //m_m_EndPositionItem =  endItem.{à définir}scenePos();

   // myColor = Qt::black; // Temp for test

    setRect(QRectF(-50, -50, 100, 100));
}


QRectF ArrowsGraphicsItem::boundingRect() const
{
    return BaseGraphicItem::boundingRect();
}

void ArrowsGraphicsItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    // @José: Juste un exemple de dessin trouvé dans un exemple (elastic nodes)
    // Pour rappel ton rectangle de dessin est m_rect, si tu sors de ce rectangle tu auras des artefacts lors du déplacement de l'item
    // Par ailleurs le crash venait de ta méthode shape(), car tu avais tout commenté dedans et ça, ça lui plaisait pas... il lui faut un retour absolument
    // Je pense pas que tu en as besoin d'ailleurs, shape() ça sert surtout à redéfinir une forme plus précise pour ton item, notamment quand tu veux faire de la
    // détection de collision / click, la forme de base étant un rectangle. Après tu peux le faire si tu veux hein !


    painter->setRenderHint(QPainter::Antialiasing);
    painter->save();
    QPointF sourcePoint = m_rect.topLeft(); // Test
    QPointF destPoint = m_rect.bottomRight(); // Test

    QLineF line(sourcePoint, destPoint);
    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->drawLine(line);

    double angle = qAtan2(-line.dy(), line.dx());

    QPointF sourceArrowP1 = sourcePoint + QPointF(qSin(angle + M_PI / 3) * 10, qCos(angle + M_PI / 3) * 10);
    QPointF sourceArrowP2 = sourcePoint + QPointF(qSin(angle + M_PI - M_PI / 3) * 10, qCos(angle + M_PI - M_PI / 3) * 10);
    QPointF destArrowP1 = destPoint + QPointF(qSin(angle - M_PI / 3) * 10, qCos(angle - M_PI / 3) * 10);
    QPointF destArrowP2 = destPoint + QPointF(qSin(angle - M_PI + M_PI / 3) * 10, qCos(angle - M_PI + M_PI / 3) * 10);

    painter->setBrush(Qt::black);
    painter->drawPolygon(QPolygonF() << line.p1() << sourceArrowP1 << sourceArrowP2);
    painter->drawPolygon(QPolygonF() << line.p2() << destArrowP1 << destArrowP2);
    painter->restore();

    BaseGraphicItem::paint(painter,option,widget);
}

void ArrowsGraphicsItem::updateArrowPosition()
{
    // Without anchor point method
    // To do

    // 1 anchor point method
    // To do

    //  2 anchors points method
    /* inactive no constructor for the moment
    QLineF line(mapFromItem(m_StartItem, 0, 0), mapFromItem(m_EndItem, 0, 0));
    setLine(line);
    */

    //Example
    //QLineF line(mapFromItem(myStartItem, 0, 0), mapFromItem(myEndItem, 0, 0));
    //setLine(line);
}