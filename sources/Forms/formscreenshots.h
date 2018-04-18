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

// Forward Declaration
namespace Ui
{
    class FormScreenshots;
}


// Class
// -----

class FormScreenshots
    :   public QWidget
{
    Q_OBJECT

    public:

        // Constructor, destructor
        explicit FormScreenshots(QWidget* parent = 0);

        ~FormScreenshots();

    private:

        // Ui
        Ui::FormScreenshots *ui;

};

#endif // FORMSCREENSHOOTS_H
