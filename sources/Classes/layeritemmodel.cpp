/*
================================================
* File:         layeritemmodel.cpp
* Project:      ClipEdit
* Creation:     29/04/2018
* Brief:        Custom model for the table widget
*               in the layer section
================================================
*/

// Includes
// --------

#include "layeritemmodel.h"

// Constructors
// ------------

LayerItemModel::LayerItemModel(QObject* parent)
    :   QStandardItemModel(parent)
{

}

LayerItemModel::LayerItemModel(int rows, int columns, QObject* parent)
    :   QStandardItemModel(rows, columns, parent)
{

}

// Reimplemented virtual methods
// -----------------------------

QVariant LayerItemModel::data(const QModelIndex& proxyIndex, int role) const
{
    if (role == Qt::TextAlignmentRole)
    {
        return Qt::AlignCenter;
    }
    else
    {
        return QStandardItemModel::data(proxyIndex, role);
    }
}
