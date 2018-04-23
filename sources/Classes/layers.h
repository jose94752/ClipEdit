#ifndef LAYERS_H
#define LAYERS_H

#include <QGraphicsScene>

class Layers
{
public:
    explicit Layers(QGraphicsScene * scene);
    ~Layers();

private:
    QGraphicsScene *m_scene;

};

#endif // LAYERS_H
