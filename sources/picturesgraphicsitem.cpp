#include "picturesgraphicsitem.h"
#include <QGraphicsRectItem>
#include <QRect>


PicturesGraphicsItem::PicturesGraphicsItem( QGraphicsItem* parent)
    :   BaseGraphicItem(parent)
{
     srand(time(NULL));
    int range = 300 - (-300) + 1;
    setPos(-300 + (rand() % range) , -300 + (rand() % range));

    setRect(QRectF(-50, -50, 100, 100));
}



// Pure virtual methods implementation
// -----------------------------------

QRectF PicturesGraphicsItem::boundingRect() const
{
    int     height, width, shade_grey, trans;
    QString lg_txt;
    QFont   lg_font;
    int     lg_size;
    QColor  lg_color;
    QString lg_pos;


    //getPictureValues( height,  width,  shade_grey,  trans,  lg_txt, lg_font, lg_size,  lg_color,  lg_pos);



 //    QRectF r1(height, width, 0, 0);


    return BaseGraphicItem::boundingRect();
}

void PicturesGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    void getPictureValues(int &heigh, int &width, int &shade_grey, int &trans, QString &lg_txt, QFont &lg_font, int &lg_size, QColor &lg_color, QString &lg_pos);

   // painter->(boundingRect(), m_picture);

    BaseGraphicItem::paint(painter, option, widget);
}

int PicturesGraphicsItem::type() const
{
    return Type::ImageGraphicsItem;
}



/*

 QGraphicsRectItem *rectItem = new QGraphicsRectItem( QRect( -25, 25, 200, 40 ), 0, &scene );
  rectItem->setPen( QPen( Qt::red, 3, Qt::DashDotLine ) );
  rectItem->setBrush( Qt::gray );

 */
