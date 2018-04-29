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

#include <QGraphicsRectItem>

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

        // Background color
        QColor m_backgroundColor;

        void setGraphicsRectItem(QGraphicsRectItem**);
        void setNbElts(int);

    public slots:

        void clear();
        void contentToView();
        void setZoomLevel(int scale);
        void changeBackgroundColor();

    protected:

        // Events
        void mousePressEvent(QMouseEvent* event);
        void mouseReleaseEvent(QMouseEvent* event);
        void mouseMoveEvent(QMouseEvent* event);

    signals:

        void itemSelected(QGraphicsItem* item);

    private:

        // Pos for panning
        //QPointF m_oldPos;

        // Rect
        QGraphicsRectItem** m_graphRectItem;
        int m_nbSceneElts;

};

#endif
