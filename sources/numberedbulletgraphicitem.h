#ifndef NUMBEREDBULLETGRAPHICITEM_H
#define NUMBEREDBULLETGRAPHICITEM_H
#include <QGraphicsItem>
#include <QRectF>
#include <qfont.h>
class NumberedBulletGraphicItem : public QGraphicsItem
{
public:
    QRectF boundingRect() const;
    enum shape_e {
      NB_CIRCLE = 0,
      NB_RECTANGLE,
      NB_ROUNDEDRECTANGLE
    };
    NumberedBulletGraphicItem(int from = 0, int to = 0, shape_e button_shape = NB_CIRCLE, QColor button_color = QColor (),
                              QColor numbercolor = QColor (), const QFont font = QFont ());

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void print_debug () const;
private :
    int m_from;
    int m_to;
    shape_e m_shape;
    QColor m_buttoncolor;
    QColor m_numbercolor;
    QFont m_font;
};

#endif // NUMBEREDBULLETGRAPHICITEM_H
