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
    m_text = "Sample Text";
    m_font = QFont();
    m_alignmentFlags = Qt::AlignLeft;
    m_hasBorders = true;
    m_borderWidth = 1;
    m_borderRadius = 0;

    textToRect();
    setPos(0, 0);
}

TextBoxItem::TextBoxItem(const QString& text, QGraphicsItem* parent)
    :   BaseGraphicItem(parent)
{
    m_text = text;
    m_font = QFont();
    m_alignmentFlags = Qt::AlignLeft;
    m_borderWidth = 1;
    m_borderRadius = 0;

    textToRect();
    setPos(0, 0);
}


// Virtual methods from BaseGraphicItem
// ------------------------------------

QRectF TextBoxItem::boundingRect() const
{
    return BaseGraphicItem::boundingRect();
}

void TextBoxItem::paint(QPainter* painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    // Text
    QRectF textRect = m_rect.adjusted(m_borderWidth + m_handlerSize/2.0, m_borderWidth + m_handlerSize/2.0, -2*m_borderWidth - m_handlerSize, -2*m_borderWidth - m_handlerSize);
    painter->drawText(textRect, m_alignmentFlags, m_text);

    // Border
    if (m_hasBorders)
    {
        painter->drawRoundedRect(m_rect, m_borderRadius, m_borderRadius);
    }

    BaseGraphicItem::paint(painter, option, widget);
}

int TextBoxItem::type() const
{
    return Type::TextBoxGraphicsItem;
}

// Utils
// -----

void TextBoxItem::textToRect()
{
   QFontMetrics fm(m_font);
   QRectF rect = fm.boundingRect(m_text);

   rect.adjust(-m_handlerSize/2.0 - m_borderWidth, -m_handlerSize/2.0 - m_borderWidth, m_handlerSize + 2*m_borderWidth, m_handlerSize + 2*m_borderWidth);
   setRect(rect);
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

