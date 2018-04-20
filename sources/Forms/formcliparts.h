/*
================================================
* File:         formcliparts.h
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to create TextBoxItem
================================================
*/

#ifndef FORMCLIPARTS_H
#define FORMCLIPARTS_H

// Includes
// --------

#include <QVector>
#include <QWidget>

// Forward Declarations
namespace Ui
{
    class FormCliparts;
}


// Class
// -----

class FormCliparts
    :   public QWidget
{
    Q_OBJECT

    // Constructor & Destructor
    public:

        explicit FormCliparts(QWidget* parent = 0);

        ~FormCliparts();


    private slots:

        void event_on_click_browse(bool);

        void event_on_click_clear(bool);


    // Data Member
    private:

        Ui::FormCliparts* ui;
};

#endif
