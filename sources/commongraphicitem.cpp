/*
================================================
* File:         commongraphicitem.cpp
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Redefine a custom graphic
*               item as a base of all graphic
*               items in ClipEdit
================================================
*/

// Includes
// --------

#include "commongraphicitem.h"

// Constructors, destructor
// ------------------------

CommonGraphicItem::CommonGraphicItem(QGraphicsItem* parent)
    :   QGraphicsItem(parent)
{

}

CommonGraphicItem::~CommonGraphicItem()
{
    // Nothing to do
}
