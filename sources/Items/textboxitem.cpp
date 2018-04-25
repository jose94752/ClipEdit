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
#include <QApplication>
#include <QDesktopWidget>
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

    m_backgroundColor = QColor(Qt::white);
    m_fontColor = QColor(Qt::black);
    m_borderColor = QColor(Qt::black);
    m_hasBorders = true;
    m_borderWidth = 1;
    m_borderRadius = 0;

    textToRect();
    setPos(0, 0);
}

TextBoxItem::TextBoxItem(const QMap<QString, QVariant>& data, QGraphicsItem* parent)
    :   BaseGraphicItem(parent)
{
    if (data.contains("text"))
        m_text = data["text"].toString();

    if (data.contains("font"))
        m_font.fromString(data["font"].toString());

    if (data.contains("alignment"))
        m_alignmentFlags = (Qt::AlignmentFlag)data["alignment"].toInt();
    else
        m_alignmentFlags = Qt::AlignLeft;

    if (data.contains("background-color"))
        m_backgroundColor = QColor(data["background-color"].toString());


    if (data.contains("font-color"))
        m_fontColor = QColor(data["font-color"].toString());


    if (data.contains("border-color"))
        m_borderColor = QColor(data["border-color"].toString());


    if (data.contains("border-visible"))
        m_hasBorders = data["border-visible"].toBool();
    else
        m_hasBorders = true;


    if (data.contains("border-width"))
        m_borderWidth = data["border-width"].toInt();
    else
        m_borderWidth = 1;


    if (data.contains("border-radius"))
        m_borderRadius = data["border-radius"].toInt();
    else
        m_borderRadius = 5;

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

    QRectF borderRect = m_rect.adjusted(m_borderWidth/2.0, m_borderWidth/2.0, -m_borderWidth/2.0, -m_borderWidth/2.0);
    QRectF textRect = m_rect.adjusted(m_borderWidth+2, m_borderWidth+2, -m_borderWidth-2, -m_borderWidth-2);

    QPen pen(m_borderColor, m_borderWidth);
    painter->setPen(pen);

    QPainterPath path;
    path.addRoundedRect(borderRect, m_borderRadius, m_borderRadius);

    // Background
    painter->fillPath(path, m_backgroundColor);

    // Border
    if (m_hasBorders)
        painter->drawPath(path);

    // Text
    pen.setColor(m_fontColor);
    pen.setWidth(1);
    painter->setFont(m_font);
    painter->setPen(pen);
    painter->drawText(textRect, m_alignmentFlags, m_text);

    BaseGraphicItem::paint(painter, option, widget);
}

int TextBoxItem::type() const
{
    return CustomTypes::TextBoxGraphicsItem;
}

// Utils
// -----

void TextBoxItem::textToRect()
{
   QFontMetrics fm(m_font);
   QRectF rect = fm.boundingRect(QApplication::desktop()->geometry(), Qt::AlignLeft | Qt::TextWordWrap | Qt::TextExpandTabs, m_text, 4);
   rect.adjust(-m_borderWidth - 2, -m_borderWidth - 2, m_borderWidth + 2, m_borderWidth + 2);

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
