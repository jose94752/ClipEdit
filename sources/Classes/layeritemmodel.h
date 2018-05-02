/*
================================================
* File:         layeritemmodel.h
* Project:      ClipEdit
* Creation:     29/04/2018
* Brief:        Custom model for the table widget
*               in the layer section
================================================
*/

#ifndef LAYERITEMMODEL_H
#define LAYERITEMMODEL_H

// Includes
// --------

#include <QStandardItemModel>

// Class
// -----

class LayerItemModel
    :   public QStandardItemModel
{

    public:

        // Constructor
        LayerItemModel(QObject* parent = 0);
        LayerItemModel(int rows, int columns, QObject* parent = 0);

        // Reimplemented virtual methods
        QVariant data(const QModelIndex& proxyIndex, int role) const;
};

#endif
