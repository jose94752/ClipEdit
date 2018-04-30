/*
================================================
* File:         layeritemdelegate.h
* Project:      ClipEdit
* Creation:     29/04/2018
* Brief:        Define how cells are displayed
*               within the layer tablewidget
================================================
*/

#ifndef LAYERITEMDELEGATE_H
#define LAYERITEMDELEGATE_H

// Includes
// --------

#include <QStyledItemDelegate>

class LayerItemDelegate
    :   public QStyledItemDelegate
{
    Q_OBJECT

    public:

        // Constructor
        LayerItemDelegate(QObject* parent = 0);

        // Reimplemented virtual methods
        void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;
};

#endif
