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
//#include "commongraphicitem.h"

#include <QWidget>

#include "../Classes/One_Form.h"


// Forward Declaration
namespace Ui {
    class FormNumberedBullets;
}


// Class
// -----

class FormNumberedBullets: public QWidget, public One_Form {
    Q_OBJECT


public:
    explicit FormNumberedBullets(One_Layered_Canvas& /*app_canvas*/,
                                 QWidget*            /*parent*/ = 0);

    ~FormNumberedBullets();

private:
    Ui::FormNumberedBullets *ui;
};

#endif // FORMNUMBEREDBULLETS_H
