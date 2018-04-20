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

#include "textboxitem.h"


// Constructors, destructor
// -----------------------

TextBoxItem::TextBoxItem(QGraphicsItem* parent)
    :   BaseGraphicItem(parent)
{
    m_font = QFont();

    setText("Sample Text");
    setPos(0, 0);

}

TextBoxItem::TextBoxItem(const QString& text, QGraphicsItem* parent)
    :   BaseGraphicItem(parent)
{
    m_text = text;
    srand(time(NULL));
    setPos(0, 0);

    setRect(QRectF(-50, -50, 100, 100));
}


// Virtual methods from BaseGraphicItem
// ------------------------------------

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
    return Type::TextBoxGraphicsItem;
}

// Utils
// -----

QRectF TextBoxItem::textToRect()
{
    return QRectF();
}

// Setters
// -------


void TextBoxItem::setText(const QString& text)
{
    m_text = text;

}

void TextBoxItem::setFont(const QFont& font)
{
    m_font = font;
}

void TextBoxItem::setBackgroundColor(const QColor& color)
{
    m_backgroundColor = color;
    update();
}

void TextBoxItem::setTextColor(const QColor& color)
{
    m_backgroundColor = color;
    update();
}

void TextBoxItem::setHasBorders(bool hasBorders)
{
    m_hasBorders = hasBorders;
    update();
}

void TextBoxItem::setBorderWidth(int width)
{
    m_borderWidth = width;
}

void TextBoxItem::setBorderRadius(int radius)
{
    m_borderRadius = radius;
    update();
}


