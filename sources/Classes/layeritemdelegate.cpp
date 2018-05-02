/*
================================================
* File:         layeritemdelegate.cpp
* Project:      ClipEdit
* Creation:     29/04/2018
* Brief:        Define how cells are displayed
*               within the layer tablewidget
================================================
*/

// Includes
// --------

#include <QDebug>
#include <QPainter>

#include "layeritemdelegate.h"

// Constructor
// -----------

LayerItemDelegate::LayerItemDelegate(QObject* parent)
    :   QStyledItemDelegate(parent)
{
}

// Reimplemented virtual methods
// -----------------------------

void LayerItemDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    QStyledItemDelegate::paint(painter, option, index);
}
