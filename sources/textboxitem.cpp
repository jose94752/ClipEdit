/*
================================================
* File:         textboxitem.cpp
* Project:      ClipEdit
* Creation:     18/04/2018
* Brief:        Inherit from CommonGraphicsItem
*               Define a box item containing some
*               text
================================================
*/

#include <QPainter>
#include <ctime>
#include <cstdlib>

#include "textboxitem.h"


TextBoxItem::TextBoxItem()
{
    srand(time(NULL));
    setPos(rand() % 300, rand() % 300);
}


QRectF TextBoxItem::boundingRect() const
{
    return QRectF(0,0,100,100);
}

void TextBoxItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawText(boundingRect(), "Test");
}
