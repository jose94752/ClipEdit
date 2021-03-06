/*
================================================
* File:         formtextboxes.h
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to create text boxes
================================================
*/

#ifndef FORMTEXTBOXES_H
#define FORMTEXTBOXES_H

// Includes
// --------

#include "baseformitem.h"

class QPushButton;

// Forward Declaration
namespace Ui
{
    class FormTextBoxes;
}

// Class
// -----

class FormTextBoxes
    :   public BaseFormItem
{
    Q_OBJECT

    public:

        // Constructor, destructor
        explicit FormTextBoxes(QWidget* parent = 0);
        ~FormTextBoxes();

        // Getters and setters
        const QPushButton* getAddButton() const;

        QVariant getItemData() const;
        //void setItemData(const QVariant& data);

        // Load data
        void loadFromItem(BaseGraphicItem* item) const;

        // Translation
        void retranslate();

    private slots:

        void saveDefaultTheme();
        void loadDefaultTheme();

    private:

        // Ui
        Ui::FormTextBoxes* ui;

};

#endif
