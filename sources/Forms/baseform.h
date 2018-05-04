/*
================================================
* File:         baseform.h
* Project:      ClipEdit
* Creation:     26/04/2018
* Brief:        Base class for forms
================================================
*/

#ifndef BASEFORM_H
#define BASEFORM_H

// Includes
// --------

#include <QWidget>

// Class
// -----

class BaseForm
    :   public QWidget
{
    Q_OBJECT

    public:

        // Constructor
        explicit BaseForm(QWidget* parent = 0);

        // Translation
        virtual void retranslate() = 0;
};

#endif
