/*
================================================
* File:         dialogpreferences.h
* Project:      ClipEdit
* Creation:     30/04/2018
* Brief:        Settings dialog
================================================
*/

#ifndef DIALOGPREFERENCES_H
#define DIALOGPREFERENCES_H

// Includes
// --------

#include <QDialog>

namespace Ui
{
    class DialogPreferences;
}

// Class
// -----

class DialogPreferences
    :   public QDialog
{
    Q_OBJECT

    public:

        // Constructor, destructor
        explicit DialogPreferences(QWidget* parent = 0);
        ~DialogPreferences();

    signals :

        void preferencesChanged(QString);

    private slots :

        void accept ();
        void reject ();

    private:

        // Ui
        Ui::DialogPreferences* ui;
};

#endif
