/*
================================================
* File:         formcharts.h
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Options for Arrows
*               Different options are proposed
*               to build arrows in ClipEdit
================================================
*/

#ifndef FORMCHARTS_H
#define FORMCHARTS_H

#include <QWidget>

#include "../Classes/One_Form.h"


// Forward Declaration
namespace Ui {
    class FormCharts;
}


// Class
// -----

class FormCharts: public QWidget, public One_Form {
    Q_OBJECT


public:
    explicit FormCharts(One_Layered_Canvas& /*app_canvas*/,
                        QWidget*            /*parent*/ = 0);

    ~FormCharts();

private:
    Ui::FormCharts *ui;
};

#endif // FORMCHARTS_H
