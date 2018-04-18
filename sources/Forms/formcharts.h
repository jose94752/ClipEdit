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

// Forward Declaration
namespace Ui
{
    class FormCharts;
}


// Class
// -----

class FormCharts
    :   public QWidget
{
    Q_OBJECT

    public:

        explicit FormCharts(QWidget* parent = 0);

        ~FormCharts();

    private:

        Ui::FormCharts *ui;
};

#endif
