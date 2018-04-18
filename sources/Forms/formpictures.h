/*
================================================
* File:         formpictures.h
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to create TextBoxItem
================================================
*/

#ifndef FORMPICTURES_H
#define FORMPICTURES_H

// Includes
// --------

#include <QWidget>

#include "../Classes/One_Form.h"


// Forward Declaration
namespace Ui {
    class FormPictures;
}


// Class
// -----

class FormPictures: public QWidget, public One_Form {
    Q_OBJECT


    public:

        // Constructor, destructor
        explicit FormPictures(One_Layered_Canvas& /*app_canvas*/,
                              QWidget*            /*parent*/ = 0);

        ~FormPictures();

    private:

        // Ui
        Ui::FormPictures *ui;

};

#endif // FORMPICTURES_H
