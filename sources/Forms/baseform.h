/*
================================================
* File:         baseform.h
* Project:      ClipEdit
* Creation:     26/04/2018
* Brief:        Base class for item forms
================================================
*/

#ifndef BASEFORM_H
#define BASEFORM_H

// Includes
// --------

#include <QWidget>

#include "../Items/basegraphicitem.h"

// Class
// -----

class BaseForm
    :   public QWidget
{
    Q_OBJECT

    public:

        // Constructor
        explicit BaseForm(QWidget* parent = 0);

        // Load
        virtual void loadFromItem(BaseGraphicItem* item) const = 0;

};

#endif
