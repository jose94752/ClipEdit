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

// Class
// -----

namespace Ui {
class FormTextBoxes;
}

class FormTextBoxes
    :   public QWidget
{
    Q_OBJECT

    public:

        // Constructor, destructor
        explicit FormTextBoxes(QWidget *parent = 0);
        ~FormTextBoxes();

    private:

        // Ui
        Ui::FormTextBoxes *ui;
};

#endif
