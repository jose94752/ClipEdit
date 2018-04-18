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


// Forward Declaration
namespace Ui
{
    class FormPictures;
}


// Class
// -----

class FormPictures: public QWidget
{
    Q_OBJECT


    public:

        // Constructor, destructor
        explicit FormPictures(QWidget* parent = 0);

        ~FormPictures();

    private:

        // Ui
        Ui::FormPictures *ui;

};

#endif
