#ifndef ONE_LAYERED_CANVAS_H
#define ONE_LAYERED_CANVAS_H

#include <QGraphicsView>


// Forward Declaration
namespace Ui {
    class One_Layered_Canvas;
}


class One_Layered_Canvas : public QFrame {
    Q_OBJECT


// Constructor & Destructor
public:

    explicit One_Layered_Canvas(QWidget* parent = 0);

    ~One_Layered_Canvas();


// Public Interface
public:

//  XXX : Just a stub
    void add_widget(QGraphicsItem*);

    void init();

//  XXX TODO
    void remove_widget(QGraphicsItem*) {}


// Data Members
private:

    Ui::One_Layered_Canvas* ui;

    QGraphicsScene scene;
};


#endif // ONE_LAYERED_CANVAS_H
