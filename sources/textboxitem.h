/*
================================================
* File:         textboxitem.h
* Project:      ClipEdit
* Creation:     18/04/2018
* Brief:        Inherit from CommonGraphicsItem
*               Define a box item containing some
*               text
================================================
*/

#ifndef TEXTBOXITEM_H
#define TEXTBOXITEM_H

#include <QGraphicsItem>

class TextBoxItem
    :   public QGraphicsItem
{
    public:

        TextBoxItem();

        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif
