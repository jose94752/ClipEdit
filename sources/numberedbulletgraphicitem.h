#ifndef NUMBEREDBULLETGRAPHICITEM_H
#define NUMBEREDBULLETGRAPHICITEM_H

#include <QRectF>
#include <qfont.h>
#include <qpainter.h>
#include <QGraphicsEllipseItem>
#include "Items/basegraphicitem.h"
#include <qrect.h>
class NumberedBulletGraphicItem : public BaseGraphicItem
{
public:
    QRectF boundingRect() const;
    enum shape_e {
      NB_CIRCLE = 0,
      NB_RECTANGLE,
      NB_ROUNDEDRECTANGLE
    };
    enum const_e {
        MAXPUCES = 5
    };
    NumberedBulletGraphicItem(int from = 0, int to = 0, shape_e bullet_shape = NB_CIRCLE, QColor bullet_color = QColor (),
                              QColor numbercolor = QColor (), const QFont font = QFont (), BaseGraphicItem *parent = NULL);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void print_debug () const;
    int type() const;
private :
    int m_from;
    int m_to;
    shape_e m_shape;
    QColor m_bulletcolor;
    QColor m_numbercolor;
    QFont m_font;

};

#endif // NUMBEREDBULLETGRAPHICITEM_H
