/*
==========================================================
* File:         numberedbulletgraphicitem.h
* Project:      ClipEdit
* Creation:     18/04/2018
* Brief:        Inherit from BaseGraphicsItem
*               Define a set of bubbles containing numbers
==========================================================
*/

#ifndef NUMBEREDBULLETGRAPHICITEM_H
#define NUMBEREDBULLETGRAPHICITEM_H

// Includes
// --------

#include <QGraphicsEllipseItem>
#include <QFont>
#include <QFontMetrics>

#include "basegraphicitem.h"
#include <qsettings.h>
// Class
// -----

class NumberedBulletGraphicItem
    :   public BaseGraphicItem
{
    public:

        enum shape_e
        {
          NB_CIRCLE = 0,
          NB_RECTANGLE,
          NB_ROUNDEDRECTANGLE
        };

        enum const_e
        {
            MAXPUCES = 5
        };

        // Constructor
        NumberedBulletGraphicItem(int m_num = 0, shape_e bullet_shape = NB_CIRCLE, QColor bullet_color = QColor(),
                                  QColor numbercolor = QColor(), const QFont font = QFont(), int size = 12, BaseGraphicItem* parent = NULL);

        // Virtual methods from BaseGraphicItem
        QRectF boundingRect() const;
        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
        int type() const;

        // Getters
        int getNum() const;
        shape_e getShape() const;
        const QColor& getBulletColor() const;
        const QColor& getNumberColor() const;
        const QFont& getFont() const;
        int getSize() const;

        // Debug
        void print_debug() const;
        void setParameters(QSettings *settings,int itemIndex);
        void getParameters(QSettings *settings,int itemIndex);
    private :

        // Properties
        int m_num;
        shape_e m_shape;
        QColor m_bulletcolor;
        QColor m_numbercolor;
        QFont m_font;
        int m_size;

        // Size calculations
        void eval_width(int&);
        void eval_height(int&);
};

#endif
