/*
================================================
* File:         textboxitem.h
* Project:      ClipEdit
* Creation:     18/04/2018
* Brief:        Inherit from BaseGraphicsItem
*               Define a box item containing some
*               text
================================================
*/

#ifndef TEXTBOXITEM_H
#define TEXTBOXITEM_H

// Includes
// --------

#include <QGraphicsItem>

#include "Items/basegraphicitem.h"

// Class
// -----

class TextBoxItem
    :   public BaseGraphicItem
{
    public:

        // Constructors, destructor
        TextBoxItem(QGraphicsItem* parent = 0);
        TextBoxItem(const QString& text, QGraphicsItem* parent = 0);

        // Virtual methods from BaseGraphicItem
        QRectF boundingRect() const;
        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
        int type() const;

        // Determine the best size from the members
        void textToRect();

        // Setters
        void setText(const QString& text);
        void setFont(const QFont& font);
        void setBackgroundColor(const QColor& color);
        void setTextColor(const QColor& color);
        void setHasBorders(bool hasBorders);
        void setBorderWidth(int width);
        void setBorderRadius(int radius);

    private:

        // Text-related members
        QString m_text;
        QFont m_font;
        Qt::AlignmentFlag m_alignmentFlags;

        // Style
        QColor m_backgroundColor, m_fontColor, m_borderColor;
        bool m_hasBorders;
        int m_borderWidth, m_borderRadius;
};

#endif
