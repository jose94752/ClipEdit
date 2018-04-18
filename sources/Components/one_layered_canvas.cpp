#include "Components/one_layered_canvas.h"
#include "ui_one_layered_canvas.h"

#include <QGraphicsItem>


#include <cstdlib> // <- XXX Debug
#include <ctime>   // <- XXX Debug


One_Layered_Canvas::One_Layered_Canvas(QWidget* parent) : QFrame(parent),
                    ui(new Ui::One_Layered_Canvas) {

    ui->setupUi(this);

    srand( time(NULL) ); // <- XXX Debug
}


One_Layered_Canvas::~One_Layered_Canvas() {
    delete ui;
}


// XXX : Just a stub
void One_Layered_Canvas::add_widget(QGraphicsItem* item) {
    if (item != NULL) {
        scene.addItem(item);
        item->setPos((rand() % 300), (rand() % 300)); // <- XXX Debug

        ui->canvas->update();
    }
}


void One_Layered_Canvas::init() {
    ui->canvas->setScene(&scene);
}
