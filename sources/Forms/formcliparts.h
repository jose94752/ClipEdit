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

class Item_Arrow;


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

    // Event
    private slots:

        void event_onClick(bool);


    // Data Members
    private:

        Ui::FormCliparts* ui;

        QVector<Item_Arrow*> list_arrows;
};

#endif
