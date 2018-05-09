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
#include <QSettings>
#include "basegraphicitem.h"

// Class
// -----

class TextBoxItem
    :   public BaseGraphicItem
{
    public:

        // Constructors, destructor
        TextBoxItem(QGraphicsItem* parent = 0);

        // Destructor Virtual method from BaseGraphicsItem
        // The virtual destructor makes sure that it gets called even if the class
        // is getting deleted through a base class pointer.
        virtual ~TextBoxItem() {};

        // Virtual methods from BaseGraphicItem
        QRectF boundingRect() const;
        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
        const QVariant itemData() const;
        void setItemData(const QVariant& data);
        int type() const;

        // Determine the best size from the members
        void textToRect();

        // Getters
        const QString& text() const;
        const QFont& font() const;
        Qt::AlignmentFlag alignment() const;
        const QColor& backgroundColor() const;
        const QColor& textColor() const;
        const QColor& borderColor() const;
        bool hasBorders() const;
        int borderWidth() const;
        int borderRadius() const;
        int margin() const;
        void getParameters(QSettings*,int);
        void setParameters(QSettings*,int);

    private:

        // Text-related members
        QString m_text;
        QFont m_font;
        Qt::AlignmentFlag m_alignmentFlag;
        int m_margin;

        // Style
        QColor m_backgroundColor, m_textColor, m_borderColor;
        bool m_hasBorders;
        int m_borderWidth, m_borderRadius;
};

#endif
