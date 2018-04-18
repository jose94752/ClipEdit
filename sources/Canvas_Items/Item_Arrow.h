#ifndef ITEM_ARROW_H
#define ITEM_ARROW_H

#include <QGraphicsItem>


// Forward Declaration
class QPainter;


class Item_Arrow : public QGraphicsItem {
// Constructor
public:

    Item_Arrow();


// QGraphicsItem
public:

    QRectF boundingRect() const;

    void paint(QPainter*                       painter,
               const QStyleOptionGraphicsItem* option,
               QWidget*                        widget);


// Events
protected:

    void mousePressEvent(QGraphicsSceneMouseEvent* event);

    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);


// Data Members
private:

    bool is_pressed;
};


#endif // ITEM_ARROW_H
