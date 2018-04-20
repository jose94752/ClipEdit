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
    for (; num_bullet != nb_bullet; ++num_bullet) {
    }
}

NumberedBulletGraphicItem::NumberedBulletGraphicItem(int from, int to, shape_e button_shape, QColor button_color,
                          QColor numbercolor, const QFont font) :
  m_from (from),
  m_to (to),
  m_shape (button_shape),
  m_buttoncolor (button_color),
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
