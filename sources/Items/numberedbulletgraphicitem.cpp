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
    //qDebug () << "\tnombre de bullet :" << nb_bullet << "\n";
    //QPoint center (10, 10); //milieu
    QPointF center (m_rect.center());
    QPointF textPos;
    //int rx (50), ry (rx), y (50);
    int rx(m_rect.width()/2);
    //int ry(m_rect.height()/3);
    int ry (rx);
    qDebug () << "m_bulletcolor == " << m_bulletcolor.name() << "\n";
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
    {
        //qvar = num_bullet;
        switch (m_shape) {
        case NB_CIRCLE :
            qpainter->setBrush(m_bulletcolor);
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

        strnum = QString::number(m_num);
        strwidth = fontmetrix.width (strnum);
        strheight = fontmetrix.height();
        qDebug () << "m_numbercolor == " << m_bulletcolor.name() << "\n";
        qpainter->setPen(m_numbercolor);
        textPos.setX (center.x () - strwidth/2);
        textPos.setY (center.y () /*- strheight/2*/);
        //textPos.setY (strheight > m_taille/2 ?)
        qpainter->drawText(textPos, strnum);
        //y += 2*ry;
        //center.setY(y);

    }
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
    //QFontMetrics qmf (m_font);
    eval_width (compwidth);
    eval_height (compheight);

    compwidth *= m_taille;
    compheight *= m_taille;
    qDebug () << "NB : compwidth == " << compwidth << "\n";
    qDebug () << "NB : compheigth == " << compheight << "\n";
    //...setRect
    QRectF qrect(0, 0, compwidth, compheight);
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
