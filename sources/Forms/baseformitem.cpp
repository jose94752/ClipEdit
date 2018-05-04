/*
================================================
* File:         baseformitem.cpp
* Project:      ClipEdit
* Creation:     04/05/2018
* Brief:        Inherit from BaseForm
*               Abstract class for item forms
================================================
*/

// Includes
// --------

#include "baseformitem.h"

// Constructor, destructor
// -----------------------

BaseFormItem::BaseFormItem(QWidget* parent)
    :   BaseForm(parent)
{

}

BaseFormItem::~BaseFormItem()
{
    // Nothing to do
}
