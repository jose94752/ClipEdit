/*
================================================
* File:         textboxitem.cpp
* Project:      ClipEdit
* Creation:     18/04/2018
* Brief:        Inherit from BaseGraphicsItem
*               Define a box item containing some
*               text
================================================
*/

// Includes
// --------

#include <QPainter>
#include <ctime>
#include <cstdlib>

#include "textboxitem.h"


// Constructor, destructor
// -----------------------

TextBoxItem::TextBoxItem(QGraphicsItem* parent)
    :   QGraphicsItem(parent)
{
    srand(time(NULL));
    setPos(rand() % 300, rand() % 300);
}


// Pure virtual methods implementation
// -----------------------------------

QRectF TextBoxItem::boundingRect() const
{
    return QRectF(0,0,100,100);
}

void TextBoxItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawText(boundingRect(), "Test");
}
