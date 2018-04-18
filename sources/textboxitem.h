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

// Includes
// --------

#include <QGraphicsItem>

// Class
// -----

class TextBoxItem
    :   public QGraphicsItem
{
    public:

        // Constructor, destructor
        TextBoxItem(QGraphicsItem* parent = 0);

        // Pure virtual methods implementation
        QRectF boundingRect() const;
        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

#endif
