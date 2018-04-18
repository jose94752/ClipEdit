/*
================================================
* File:         formtextboxes.h
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to create TextBoxItem
================================================
*/

#ifndef FORMTEXTBOXES_H
#define FORMTEXTBOXES_H

// Includes
// --------

#include <QWidget>

#include "../Classes/One_Form.h"


// Forward Declaration
namespace Ui {
    class FormTextBoxes;
}


// Class
// -----

class FormTextBoxes: public QWidget, public One_Form {
    Q_OBJECT


    public:

        // Constructor, destructor
        explicit FormTextBoxes(One_Layered_Canvas& /*app_canvas*/,
                               QWidget*            /*parent*/ = 0);

        ~FormTextBoxes();

    private slots:

        void pickColor(bool);

    private:

        // Ui
        Ui::FormTextBoxes *ui;

};

#endif
