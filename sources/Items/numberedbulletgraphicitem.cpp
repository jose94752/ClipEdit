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
    eval_width (compwidth);
    eval_height (compheight);

    compwidth *= m_size;
    compheight *= m_size;

    int cote = (compwidth < compheight ? compheight:compheight);
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
    m_font.setPixelSize(m_rect.height());
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

