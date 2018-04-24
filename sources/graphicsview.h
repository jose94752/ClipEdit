/*
================================================
* File:         graphicsview.h
* Project:      ClipEdit
* Creation:     24/04/2018
* Brief:        Custom QGraphicsView implementation
================================================
*/

#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

// Includes
// --------

#include <QGraphicsView>

// Class
// -----

class GraphicsView
    :   public QGraphicsView
{
    Q_OBJECT

    public:

        // Constructor
        GraphicsView(QWidget* parent = 0);

    public slots:

        void clear();
        void contentToView();
        void setZoomLevel(int zoom);

    protected:

        // Events
        void mouseDoubleClickEvent(QMouseEvent* event);
        void mousePressEvent(QMouseEvent* event);
        void mouseReleaseEvent(QMouseEvent* event);
        void mouseMoveEvent(QMouseEvent* event);

    signals:

        void itemSelected(QGraphicsItem* item);

    private:

        // Pos for panning
        QPointF m_oldPos;

        //color de fond
        QColor m_backgroundColor;
};

#endif
