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

class QPushButton;

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

        // Getters and setters
        const QPushButton* getAddButton();

        QVariant getItemData() const;
        void setItemData(const QVariant& data);

    private slots:

        void saveDefaultTheme();
        void loadDefaultTheme();

    private:

        // Ui
        Ui::FormTextBoxes* ui;

};

#endif
