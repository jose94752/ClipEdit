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

#include "baseform.h"


// Forward Declaration
namespace Ui {
    class FormCollections;
}


// Class
// -----

class FormCliparts
    :   public BaseForm
{
    Q_OBJECT

    // Constructor
    public:

        explicit FormCliparts(QWidget* parent = NULL);

//      ~FormCliparts() {}

        // Load data
        void loadFromItem(BaseGraphicItem* item) const;

        // Translation
        void retranslate();

    private:

        Ui::FormCollections* ui;
};

#endif
