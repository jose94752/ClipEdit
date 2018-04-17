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
#include <QWidget>


// Namespace for FormArrows
// ------------------------

 namespace Ui {
    class FormArrows;
}

// Class
// -----

class FormArrows : public QWidget
{
    Q_OBJECT

public:
    // Constructors, destructor
    explicit FormArrows(QWidget *parent = 0);
    ~FormArrows();

private:
    // Private
    Ui::FormArrows *ui;
};

#endif // FORMARROWS_H
