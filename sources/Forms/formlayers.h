/*
================================================
* File:         formlayers.h
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to create TextBoxItem
================================================
*/

#ifndef FORMSLAYERS_H
#define FORMSLAYERS_H

// Includes
// --------

#include <QWidget>

#include "../Classes/One_Form.h"


// Forward Declaration
namespace Ui {
    class FormLayers;
}


// Class
// -----

class FormLayers: public QWidget, public One_Form {
    Q_OBJECT


    public:

        // Constructor, destructor
        explicit FormLayers(One_Layered_Canvas& /*app_canvas*/,
                            QWidget*            /*parent*/ = 0);

        ~FormLayers();

    private:

        // Ui
        Ui::FormLayers *ui;

};

#endif // FORMSLAYERS_H
