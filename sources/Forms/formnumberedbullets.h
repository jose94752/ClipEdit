/*
================================================
* File:         formnumberedbullets.h
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to create TextBoxItem
================================================
*/

#ifndef FORMNUMBEREDBULLETS_H
#define FORMNUMBEREDBULLETS_H

#include <QWidget>
#include <QPushButton>


// Forward Declaration
namespace Ui
{
    class FormNumberedBullets;
}


// Class
// -----

class FormNumberedBullets: public QWidget
{
    Q_OBJECT


    public:

        explicit FormNumberedBullets(QWidget* parent = 0);

        ~FormNumberedBullets();
        void get_info (int& /*from*/, int& /*to*/, int& taille, int& shape, QColor& button_color, QColor& number_color, QFont&);

        QPushButton *getGoPushButton();
    private:

        // UI
        Ui::FormNumberedBullets *ui;
};

#endif
