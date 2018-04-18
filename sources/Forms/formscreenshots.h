/*
================================================
* File:         formscreenshots.h
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to create TextBoxItem
================================================
*/

#ifndef FORMSCREENSHOOTS_H
#define FORMSCREENSHOOTS_H

// Includes
// --------

#include <QWidget>

#include "../Classes/One_Form.h"


// Forward Declaration
namespace Ui {
    class FormScreenshots;
}


// Class
// -----

class FormScreenshots: public QWidget, public One_Form {
    Q_OBJECT


    public:

        // Constructor, destructor
        explicit FormScreenshots(One_Layered_Canvas& /*app_canvas*/,
                                 QWidget*            /*parent*/ = 0);

        ~FormScreenshots();

    private:

        // Ui
        Ui::FormScreenshots *ui;

};

#endif // FORMSCREENSHOOTS_H
