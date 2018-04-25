/*
==================================================
* File:         resizescenedialog.h
* Project:      ClipEdit
* Creation:     24/04/2018
* Brief:        Dialog to edit the scene dimension
==================================================
*/

#ifndef RESIZESCENEDIALOG_H
#define RESIZESCENEDIALOG_H

// Includes
// --------

#include <QGraphicsScene>
#include <QDialog>

namespace Ui
{
    class ResizeSceneDialog;
}

// Class
// -----

class ResizeSceneDialog
    :   public QDialog
{
    Q_OBJECT

    public:

        // Constructor, destructor
        explicit ResizeSceneDialog(QGraphicsScene*, QWidget* parent = 0);//(parent,precedent width,precedent height)
        ~ResizeSceneDialog();

    public slots:

        // Slots
        void sizeChanged();
        void unitChanged(const QString& unit);

    private:

        Ui::ResizeSceneDialog* ui;
        QGraphicsScene* m_scene;
        int* m_width;
        int* m_height;
        int m_dpix;
        int m_dpiy;
};

#endif
