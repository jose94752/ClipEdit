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
#include <QString>
#include <QColor>


#include "Classes/graphsgraphicsitem.h"


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

    void GetChartsValues(int &vChartType, QString &vChartTitle, QString &vXAxis, QString &vYAxis,
                         QColor &vBackColor, QColor &vColor, int &vWidth, int &vHeight,
                         int &vScale, int &vRotate);

    void GetChartsValues( GraphsInfo &infos);

public slots:
    void createChart();
private:

        Ui::FormCharts *ui;
};

#endif
