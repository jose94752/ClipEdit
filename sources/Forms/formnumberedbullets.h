/*
=========================================================
* File:         formnumberedbullets.h
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to create NumberedBulletGraphicItem
=========================================================
*/

#ifndef FORMNUMBEREDBULLETS_H
#define FORMNUMBEREDBULLETS_H

// Includes
// --------

#include <QWidget>
#include <QPushButton>
#include <QToolButton>

#include "baseform.h"

// Forward Declaration
namespace Ui
{
    class FormNumberedBullets;
}

// Class
// -----

class FormNumberedBullets
    :   public BaseForm
{
    Q_OBJECT

    public:

        explicit FormNumberedBullets(QWidget* parent = 0);
        ~FormNumberedBullets();

        // Getters and setters
        void get_info (int& /*from*/, int& /*to*/, int& taille, int& shape, QColor& button_color, QColor& number_color, QFont&) const;
        QPushButton* getGoPushButton();
        //void setFrom (const int&);

        // Load data
        void loadFromItem(BaseGraphicItem* item) const;

        // Translation
        void retranslate();

    private slots:

        // Default theme
        void saveDefaultTheme() const;
        void loadDefaultTheme();

    private:

        // UI
        Ui::FormNumberedBullets* ui;
};

#endif
