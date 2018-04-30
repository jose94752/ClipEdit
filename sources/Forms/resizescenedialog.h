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

        explicit ResizeSceneDialog(QGraphicsScene* vscene, QGraphicsRectItem** v_borderSceneItem, const QColor& v_backgroundColor, bool isNew, QWidget* parent = 0);
        ~ResizeSceneDialog();
        void detectFormat();

    public slots:

        void sizeChanged();
        void valuesChanged();
        void unitChanged(const QString& unit);
        void formatChanged(const QString& format);

    protected:

        void resizeEvent(QResizeEvent*);

    private:

        Ui::ResizeSceneDialog *ui;
        QGraphicsScene *m_scene;
        int m_width;
        int m_height;
        int m_dpix;
        int m_dpiy;
        QGraphicsRectItem **m_borderSceneItem;
        QColor m_backGroundColor;
        static QString m_format;
        bool m_format_changed;
        bool m_isNew;
};

#endif
