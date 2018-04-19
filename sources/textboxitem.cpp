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

#include <QDebug>
#include <QPainter>
#include <ctime>
#include <cstdlib>

#include "textboxitem.h"


// Constructor, destructor
// -----------------------

TextBoxItem::TextBoxItem(const QString& text, QGraphicsItem* parent)
    :   BaseGraphicItem(parent)
{
    m_text = text;
    srand(time(NULL));
    int range = 300 - (-300) + 1;
    setPos(-300 + (rand() % range) , -300 + (rand() % range));

    setRect(QRectF(-50, -50, 100, 100));
}


// Pure virtual methods implementation
// -----------------------------------

QRectF TextBoxItem::boundingRect() const
{
    return BaseGraphicItem::boundingRect();
}

void TextBoxItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter->drawText(m_rect, m_text);
    BaseGraphicItem::paint(painter, option, widget);
}

int TextBoxItem::type() const
{
    return UserType + 1;
}
