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

        // Constructor, destructor
        TextBoxItem(const QString& text, QGraphicsItem* parent = 0);

        // Pure virtual methods implementation
        QRectF boundingRect() const;
        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

        int type() const;

    private:

        QString m_text;
};

#endif
