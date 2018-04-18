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

#include "../Classes/One_Form.h"


// Forward Declaration
namespace Ui {
    class FormArrows;
}


// Class
// -----

class FormArrows: public QWidget, public One_Form {
    Q_OBJECT


    public:

        // Constructors, destructor
        explicit FormArrows(One_Layered_Canvas& /*app_canvas*/,
                            QWidget*            /*parent*/ = 0);

        ~FormArrows();

    private:

        // UI
        Ui::FormArrows *ui;
};

#endif
