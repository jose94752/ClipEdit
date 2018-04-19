#include "numberedbulletgraphicitem.h"
#include <qdebug.h>

QRectF NumberedBulletGraphicItem::boundingRect() const
{
  return QRectF ();
}


void NumberedBulletGraphicItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
   QPoint A (0, 0), D (100, 100);
   QRect qrect (A, D);
   painter->drawText(qrect, "NumberedBullet");
}

NumberedBulletGraphicItem::NumberedBulletGraphicItem(int from, int to, shape_e button_shape, QColor button_color,
                          QColor numbercolor, const QFont font) : /*QGraphicsItem (*this)*/
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
