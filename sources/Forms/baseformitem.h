/*
================================================
* File:         baseformitem.h
* Project:      ClipEdit
* Creation:     04/05/2018
* Brief:        Inherit from BaseForm
*               Abstract class for item forms
================================================
*/

#ifndef BASEFORMITEM_H
#define BASEFORMITEM_H

// Includes
// --------

#include "baseform.h"
#include "Items/basegraphicitem.h"

class QPushButton;

// Class
// -----

class BaseFormItem
    :   public BaseForm
{
    Q_OBJECT

    public:

        // Constructor, destructor
        explicit BaseFormItem(QWidget* parent = 0);
        virtual ~BaseFormItem();

        // Load
        virtual void loadFromItem(BaseGraphicItem* item) const = 0;

        // Getter
        virtual const QPushButton* getAddButton() const = 0;

        // (Will be enabled in the future for global uniformisation)
        //virtual QVariant getItemData() = 0;
        // or
        // virtual BaseGraphicItem* getItem() = 0;
};

#endif
