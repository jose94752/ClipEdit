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
#include <QRectF>
#include <QGraphicsItem>

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
    explicit ResizeSceneDialog(QGraphicsScene*, QWidget*,QGraphicsRectItem**);
    ~ResizeSceneDialog();

public slots:
    void sizeChanged();
    void unitChanged(const QString&);

private:
    Ui::ResizeSceneDialog *ui;
    QGraphicsScene *m_scene;
    int *m_width;
    int *m_height;
    int m_dpix;
    int m_dpiy;
    QGraphicsRectItem **m_borderSceneItem;
};

#endif
