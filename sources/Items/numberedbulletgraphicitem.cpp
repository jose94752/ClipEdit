#include "numberedbulletgraphicitem.h"
#include <qdebug.h>

QRectF NumberedBulletGraphicItem::boundingRect() const
{
  return BaseGraphicItem::boundingRect();
}

void NumberedBulletGraphicItem::paint(QPainter *qpainter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    qpainter->setRenderHint(QPainter::Antialiasing);
    qpainter->setBrush(m_bulletcolor);

    switch (m_shape) {
    case NB_CIRCLE :
        qpainter->drawEllipse(m_rect);
        break;
    case NB_RECTANGLE :
        qpainter->drawRect(m_rect);
        break;
    case NB_ROUNDEDRECTANGLE :
        qpainter->drawRoundedRect(m_rect, 10, 10);
        break;
    default :
        break;
    }


    QString strnum;
    strnum = QString::number(m_num);
    QTextOption qto;
    qto.setAlignment(Qt::AlignCenter);
    m_font.setPixelSize(/*m_taille*/m_rect.height());
    qpainter->setFont(m_font);
    qpainter->setPen(m_numbercolor);
    qpainter->drawText(m_rect, strnum, qto);
    //qpainter->drawText(m_rect, strnum);
    BaseGraphicItem::paint(qpainter, option, widget);
}

NumberedBulletGraphicItem::NumberedBulletGraphicItem(int num, shape_e bullet_shape, QColor bullet_color,
                          QColor numbercolor, const QFont font, int taille, BaseGraphicItem *parent) :
  BaseGraphicItem(parent),
  m_num (num),
  m_shape (bullet_shape),
  m_bulletcolor (bullet_color),
  m_numbercolor (numbercolor),
  m_font (font),
  m_taille (taille),
  m_qfm (m_font) {
    int compwidth (0), compheight (0);
    eval_width (compwidth);
    eval_height (compheight);

    compwidth *= m_taille;
    compheight *= m_taille;

    int cote = (compwidth < compheight ? compheight:compheight);
    qDebug () << "NB : compwidth == " << compwidth << "\n";
    qDebug () << "NB : compheigth == " << compheight << "\n";
    //...setRect
    //QRectF qrect(0, 0, compwidth, compheight);
    QRectF qrect (0, 0, cote, cote);
    setRect(qrect);
    //static QPointF pos (0, 0);
    //static QPoint decal (100, 0);
    //setPos()
    //pos.operator +=(decal);
}

void NumberedBulletGraphicItem::eval_height(int& height) {
    height = m_qfm.height();
}

void NumberedBulletGraphicItem::eval_width(int& width) {
    width = 0;
    QString strnum;
    strnum = QString::number(m_num);
    width = m_qfm.width(strnum);
}

void NumberedBulletGraphicItem::print_debug () const {
  qDebug () << "m_num == " << m_num << "\n";
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
