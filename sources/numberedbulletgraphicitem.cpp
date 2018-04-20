#include "numberedbulletgraphicitem.h"
#include <qdebug.h>

QRectF NumberedBulletGraphicItem::boundingRect() const
{
  return BaseGraphicItem::boundingRect();
}


void NumberedBulletGraphicItem::paint(QPainter *qpainter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    //notes
    //regler la fontsize pr un qpainter::write :
    //QFont font;
    //font.setPixelSize(12);
    //QFontMetrics(const QFont & font)...?
    //QFont font("times", 24);
    //QFontMetrics fm(font);
    //int pixelsWide = fm.width("What's the width of this text?");
    //int pixelsHigh = fm.height();
    qDebug () << "\tdans NumberBulletItem::paint\n";
    qDebug () << "\tm_from == " << m_from << "\n";
    qDebug () << "\tm_to == " << m_to << "\n";
    int nb_bullet (m_to + 1 - m_from);
    qDebug () << "\tnombre de bullet :" << nb_bullet << "\n";
    int num_bullet (m_from);
    QPoint center (10, 10); //milieu
    QPoint textPos;
    int rx (50), ry (rx), y (50);
    qpainter->setPen(m_bulletcolor);
    //qpainter->
    // pr tests
    //m_shape = NB_ROUNDEDRECTANGLE;
    m_shape = NB_CIRCLE;
    QString strnum;
    QRect rect;
    //m_font.setPixelSize (6* (m_taille >1?m_taille -1: 0));
    m_font.setPixelSize (4* (m_taille >1?m_taille -1: 0));
    QFontMetrics fontmetrix (m_font);
    int strwidth (0), strheight;
    qpainter->setFont(m_font);
    for (; num_bullet != m_to +1; ++num_bullet) {
        //qvar = num_bullet;
        switch (m_shape) {
        case NB_CIRCLE :
            qpainter->drawEllipse(center, rx, ry);
            break;
        case NB_RECTANGLE :
            rect.setCoords(center.x() - rx, center.y() - ry, center.x() +rx, center.y() + ry);
            qpainter->drawRect(rect);
            break;
        case NB_ROUNDEDRECTANGLE :
            rect.setCoords(center.x() - rx, center.y() - ry, center.x() +rx, center.y() + ry);
            qpainter->drawRoundedRect(rect, 10, 10);
            break;
        default :
            break;
        }
        //strnum = qvar.toString();

        //strnum = QString::number(num_bullet);
        //strnum = tr("%1").arg(myInt);

        qDebug () << "\tnumbullet == " << num_bullet << "\n";
        strnum = QString::number(num_bullet);
        qDebug () << "\tstrnum == " << strnum << "\n";
        strwidth = fontmetrix.width (strnum);
        strheight = fontmetrix.height();

        qDebug () << "strwidth == " << strwidth << "\n";
        qDebug () << "heighth == " << strheight << "\n";
        textPos.setX (center.x () - strwidth/2);
        textPos.setY (center.y () /*- strheight/2*/);
        //qpainter->drawText(textPos, strnum);

        y += 2*ry;
        center.setY(y);

    }
    BaseGraphicItem::paint(qpainter, option, widget);

}

NumberedBulletGraphicItem::NumberedBulletGraphicItem(int from, int to, shape_e bullet_shape, QColor bullet_color,
                          QColor numbercolor, const QFont font, int taille, BaseGraphicItem *parent) :
  BaseGraphicItem(parent),
  m_from (from),
  m_to (to),
  m_shape (bullet_shape),
  m_bulletcolor (bullet_color),
  m_numbercolor (numbercolor),
  m_font (font),
  m_taille (taille) {

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
