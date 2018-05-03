/*
================================================
* File:         dialogsave.h
* Project:      ClipEdit
* Creation:     26/04/2018
* Brief:        Simple dialog for project saving
================================================
*/

#ifndef DIALOGSAVE_H
#define DIALOGSAVE_H

// Includes
// --------

#include <QDialog>
#include <QGraphicsItem>

namespace Ui
{
    class DialogSave;
}

// Class
// -----

class DialogSave
    :   public QDialog
{
    Q_OBJECT

    public:

        // Constructor, destructor
        explicit DialogSave(QList<QGraphicsItem*>,QGraphicsRectItem*,QWidget* parent = 0);
        ~DialogSave();

    private slots:

        void slotSaveApproved();

    private:

        // Ui
        Ui::DialogSave* ui;

        // Items
        QList<QGraphicsItem*> m_items;

        QGraphicsRectItem *m_rectItem;
};

#endif
