#ifndef PICTURESGRAPHICSITEM_H
#define PICTURESGRAPHICSITEM_H

#include "Items/basegraphicitem.h"
#include "Forms/formpictures.h"

#include <QGraphicsItem>
#include <QPainter>


class PicturesGraphicsItem  : public BaseGraphicItem
{
public:

    PicturesGraphicsItem (FormPictures * ptr, QGraphicsItem* parent=0);

    // Pure virtual methods implementation
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    int type() const ;

    int     height, width, shade_grey, trans;
    QString lg_txt;
    QFont   lg_font;
    int     lg_size;
    QColor  lg_color;
    QString lg_pos;


private:

    QPainter  m_picture;
};

#endif // PICTURESGRAPHICSITEM_H
