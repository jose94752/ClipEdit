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

#include "baseformitem.h"


// Forward Declaration
namespace Ui {
    class FormCollections;
}


// Class
// -----

class FormCliparts
    :   public BaseFormItem
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

        // Getter add button
        const QPushButton* getAddButton() const;

    private:

        // Ui
        Ui::FormCollections* ui;
};

#endif
