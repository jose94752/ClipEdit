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


// Forward Declaration
namespace Ui
{
    class FormTextBoxes;
}


// Class
// -----

class FormTextBoxes
    :   public QWidget
{
    Q_OBJECT

    public:

        // Constructor, destructor
        explicit FormTextBoxes(QWidget* parent = 0);

        ~FormTextBoxes();

    private slots:

        void pickColor(bool);

    private:

        // Ui
        Ui::FormTextBoxes *ui;

};

#endif