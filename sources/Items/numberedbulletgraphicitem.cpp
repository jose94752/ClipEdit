/*
==========================================================
* File:         numberedbulletgraphicitem.cpp
* Project:      ClipEdit
* Creation:     18/04/2018
* Brief:        Inherit from BaseGraphicsItem
*               Define a set of bubbles containing numbers
==========================================================
*/

// Includes
// --------

#include <QDebug>
#include <QPainter>

#include "numberedbulletgraphicitem.h"

// Constructor
// -----------

NumberedBulletGraphicItem::NumberedBulletGraphicItem(int num, shape_e bullet_shape, QColor bullet_color,
                          QColor numbercolor, const QFont font, int size, BaseGraphicItem *parent) :
    BaseGraphicItem(parent),
    m_num(num),
    m_shape(bullet_shape),
    m_bulletcolor(bullet_color),
    m_numbercolor(numbercolor),
    m_font(font),
    m_size(size)
{
    int compwidth (0), compheight (0);
    m_font.setPixelSize(m_size);

    eval_width (compwidth);
    eval_height (compheight);

    //compwidth *= m_size;
    //compheight *= m_size;

    int cote = (compwidth < compheight ? compheight:compwidth);
    //cote du rectangle entourant le carre entourant la chaine du chiffre
    //cote *= 1/0.785; //1 / (pi/4)
    cote *= 1.2;
    //cote *=2;
    //qDebug () << "NB : compwidth == " << compwidth << "\n";
    //qDebug () << "NB : compheigth == " << compheight << "\n";

    // Setting the size
    QRectF qrect (0, 0, cote, cote);
    setRect(qrect);
}

// Virtual methods from BaseGraphicItem
// ------------------------------------

QRectF NumberedBulletGraphicItem::boundingRect() const
{
    return BaseGraphicItem::boundingRect();
}

void NumberedBulletGraphicItem::paint(QPainter* qpainter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    qpainter->setRenderHint(QPainter::Antialiasing);
    qpainter->setBrush(m_bulletcolor);
    qpainter->setPen(m_numbercolor);

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

    QString strnum = QString::number(m_num);
    QTextOption qto;
    qto.setAlignment(Qt::AlignCenter);
    //m_font.setPixelSize(m_rect.height());
    qpainter->setFont(m_font);

    qpainter->drawText(m_rect, strnum, qto);

    BaseGraphicItem::paint(qpainter, option, widget);
}

int NumberedBulletGraphicItem::type() const
{
    return BaseGraphicItem::NumberedBulletGraphicsItem;
}

// Size calculations
// -----------------

void NumberedBulletGraphicItem::eval_height(int& height)
{
    QFontMetrics fm(m_font);
    height = fm.height();
}

void NumberedBulletGraphicItem::eval_width(int& width)
{
    width = 0;
    QString strnum;
    QFontMetrics fm(m_font);

    strnum = QString::number(m_num);
    width = fm.width(strnum);
}

// Getters
// -------

int NumberedBulletGraphicItem::getNum() const
{
    return m_num;
}

NumberedBulletGraphicItem::shape_e NumberedBulletGraphicItem::getShape() const
{
    return m_shape;
}

const QColor& NumberedBulletGraphicItem::getBulletColor() const
{
    return m_bulletcolor;
}

const QColor& NumberedBulletGraphicItem::getNumberColor() const
{
    return m_numbercolor;
}

const QFont& NumberedBulletGraphicItem::getFont() const
{
    return m_font;
}

int NumberedBulletGraphicItem::getSize() const
{
    return m_size;
}

// Debug
// -----

void NumberedBulletGraphicItem::print_debug() const
{
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

//on recoit param ext
void NumberedBulletGraphicItem::setParameters(QSettings *settings,int itemIndex) {
    QString path;// = "Items";
    {
        //QVariant temp = (int) NumberedBulletGraphicsItem;
        //path += temp.toString();
        path = "item"+QString::number(itemIndex);
    }
    path += QString ("/");
    //num
    {
      QString pathnum (path);
      pathnum += QString ("num");

      QVariant vnum;
      settings->value(pathnum, vnum);
      m_num = vnum.toInt();
    }
    //shape
    {
        QString pathshape (path);
        pathshape += QString ("shape");

        QVariant vshape;
        settings->value(pathshape, vshape);
        m_shape = (shape_e) vshape.toInt();
    }
    //bulletcolor
    {
      QString pathbulletcolor (path);
      pathbulletcolor += QString ("bulletcolor");

      QVariant v_bulletcolor;
      settings->value(pathbulletcolor, v_bulletcolor);
      /*QString str_bulletcolor = v_bulletcolor.toString();
      qDebug()<<"bullet color:"<<str_bulletcolor;*/
      int r,g,b,a;
      r=settings->value(pathbulletcolor+"/r", r).toInt();
      g=settings->value(pathbulletcolor+"/g", g).toInt();
      b=settings->value(pathbulletcolor+"/b", b).toInt();
      a=settings->value(pathbulletcolor+"/a", a).toInt();
      //m_bulletcolor.setNamedColor(str_bulletcolor);
      m_bulletcolor=QColor(r,g,b,a);
    }
    //numbercolor
    {
      QString pathnumbercolor (path);
      pathnumbercolor += QString ("numbercolor");

      QVariant v_numbercolor;
      settings->value(pathnumbercolor, v_numbercolor);
      QString str_numbercolor = v_numbercolor.toString();
      m_numbercolor.setNamedColor(str_numbercolor);
    }
    //m_font
    {
      QString pathfont (path);
      pathfont += QString ("font");

      QVariant vfontname;
      settings->value (pathfont, vfontname);
      QString stringfont = vfontname.toString();
      m_font.fromString (stringfont);
    }
    //m_size
    {
        QString pathsize (path);
        pathsize += QString ("size");

        QVariant vsize = m_size;
        settings->setValue(pathsize, vsize);
    }
}

//on ecrit dans Msettinr les params
void NumberedBulletGraphicItem::getParameters(QSettings *settings,int itemIndex) {

    QString path;// = "Items";
    {
        //QVariant temp = (int) NumberedBulletGraphicsItem;
        //path += temp.toString();
        path = "item"+QString::number(itemIndex);
    }
    path += QString ("/");
    //num
    {
      QString pathnum (path);
      pathnum += QString ("num");

      QVariant vnum = m_num;
      settings->setValue(pathnum, vnum);
    }
    //shape
    {
      QString pathshape (path);
      pathshape += QString ("shape");

      QVariant vshape = (int) m_shape;
      settings->setValue(pathshape, vshape);
    }
    //bulletcolor
    {
      QString pathbulletcolor (path);
      pathbulletcolor += QString ("bulletcolor");

      //QString str_bulletcolor (m_bulletcolor.name());
      //QVariant vbulletcolor = str_bulletcolor;
      int r,g,b,a;
      m_bulletcolor.getRgb(&r,&g,&b,&a);
      settings->setValue(pathbulletcolor+"/r", r);
      settings->setValue(pathbulletcolor+"/g", g);
      settings->setValue(pathbulletcolor+"/b", b);
      settings->setValue(pathbulletcolor+"/a", a);
    }
    //numbercolor
    {
      QString pathnumbercolor (path);
      pathnumbercolor += QString ("numbercolor");

      QString str_numbercolor (m_numbercolor.name());
      QVariant vnumbercolor = str_numbercolor;
      settings->setValue(pathnumbercolor, vnumbercolor);
    }
    //m_font
    {
      QString pathfont (path);
      pathfont += QString ("font");

      QVariant vfontname = m_font.toString();
      settings->setValue(pathfont, vfontname);
    }
    //m_size
    {
        QString pathsize (path);
        pathsize += QString ("size");

        QVariant vsize = m_size;
        settings->setValue(pathsize, vsize);
    }
}
