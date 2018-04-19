#ifndef ARROWSGRAPHICSITEM_H
#define ARROWSGRAPHICSITEM_H

#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QColor>

class ArrowsGraphicsItem
        : public QGraphicsItem
{
public:
    // 4 Type of Thickness outline lines 4 choices possibilities (1 - 4)
    //enum { Type = UserType + 4 };

    ArrowsGraphicsItem();

    // Overriding of the Type
    //int type() const override { return Type; }

    QRectF boundingRect() const;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);



private:
    //DiagramItem *StI;


    QColor ItemOutlineColorArrow;
    QColor ItemFillColorArrow;



private slots:


};

#endif // ARROWSGRAPHICSITEM_H
