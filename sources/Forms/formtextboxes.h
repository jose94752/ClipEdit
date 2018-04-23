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

#include <QWidget>
#include <QMap>

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

        // Getters
        QString getText() const;
        QMap<QString, QVariant> getInfos();

    private:

        // Ui
        Ui::FormTextBoxes* ui;

};

#endif
