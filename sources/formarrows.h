/*
================================================
* File:         formarrows.h
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Options for Arrows
*               Different options are proposed
*               to build arrows in ClipEdit
================================================
*/

#ifndef FORMARROWS_H
#define FORMARROWS_H

// Includes
// --------
#include <QGraphicsLineItem>

// Herit QWidget from commongraphicsitem
#include "commongraphicitem.h"

// Namespace for FormArrows
// ------------------------
namespace Ui {
    class CommonGraphicItem;
    class FormArrows;
}

// Class
// -----

class FormArrows : public CommonGraphicItem
{
    Q_OBJECT

public:
    // Constructors, destructor
    explicit FormArrows(CommonGraphicItem *parent = 0);
    ~FormArrows();

    // Re-use of Pure virtual methods
    QRectF boundingRect() const = 0;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, CommonGraphicItem* widget = 0) = 0;

protected:

    // Protected section
    // Shared attributes set here

private:
    // Private
    Ui::FormArrows *ui;
};

#endif // FORMARROWS_H
