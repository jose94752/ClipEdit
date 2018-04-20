#include "numberedbulletgraphicitem.h"
#include <qdebug.h>

QRectF NumberedBulletGraphicItem::boundingRect() const
{
  return QRectF ();
}


void NumberedBulletGraphicItem::paint(QPainter *qpainter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    qDebug () << "\tdans NumberBulletItem::paint\n";
    qDebug () << "\tm_from == " << m_from << "\n";
    qDebug () << "\tm_to == " << m_to << "\n";
    int nb_bullet (m_to + 1 - m_from);
    qDebug () << "\tnombre de bullet :" << nb_bullet << "\n";
    int num_bullet (0);
    QPoint center (100, 100);
    int rx (50), ry (rx), y (50);
    qpainter->setPen(m_bulletcolor);
    for (; num_bullet != nb_bullet; ++num_bullet) {
        qpainter->drawEllipse(center, rx, ry);
        center.setY(y);
        y += 2*ry;

    }
    BaseGraphicItem::paint(qpainter, option, widget);
}

NumberedBulletGraphicItem::NumberedBulletGraphicItem(int from, int to, shape_e bullet_shape, QColor bullet_color,
                          QColor numbercolor, const QFont font, BaseGraphicItem *parent) :
  BaseGraphicItem(parent),
  m_from (from),
  m_to (to),
  m_shape (bullet_shape),
  m_bulletcolor (bullet_color),
  m_numbercolor (numbercolor),
  m_font (font) {

}

void NumberedBulletGraphicItem::print_debug () const {
  qDebug () << "m_from_ == " << m_from << "\n";
  qDebug () << "m_to_ == " << m_to << "\n";
  qDebug () << "m_shape == ";
  switch (m_shape) {
  case NB_CIRCLE :
      qDebug () << "CIRCLE";
      break;
  case NB_RECTANGLE :
      qDebug () << "RECTANGLE";
      break;
  case NB_ROUNDEDRECTANGLE :
      qDebug () << "ROUNDED_RECTANGLE";
  }
  qDebug () << "\n";

}

int NumberedBulletGraphicItem::type() const {
  return BaseGraphicItem::NumberedBulletGraphicsItem;
}
