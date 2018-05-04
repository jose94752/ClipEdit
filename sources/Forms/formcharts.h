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

// Includes
// --------

#include <QWidget>
#include <QString>
#include <QColor>
#include <QSettings>
#include <QTableWidgetItem>

#include "baseformitem.h"
#include "../Items/graphsgraphicsitem.h"

// Forward Declaration
namespace Ui
{
    class FormCharts;
}

// Defines
// -------

#define KFormChartsTitle            "FormCharts/title"
#define KFormChartsType             "FormCharts/type"
#define KFormChartsWidth            "FormCharts/width"
#define KFormChartsHeight           "FormCharts/height"
#define KFormChartsColor            "FormCharts/color"
#define KFormChartsBackgroundcolor  "FormCharts/backgroundcolor"
#define KFormChartsTransparent      "FormCharts/transparent"
#define KFormChartsListColors       "FormCharts/listcolors"


// Class
// -----

class FormCharts
    :   public BaseFormItem
{
    Q_OBJECT

    public:

        // Constructor, destructor
        explicit FormCharts(QWidget* parent = 0);
        ~FormCharts();

        void GetChartsValues(GraphsInfo& infos);

        // Load data
        void loadFromItem(BaseGraphicItem* item) const;

        // Translation
        void retranslate();

        // Getter add button
        const QPushButton* getAddButton() const;

    private:

        // Ui
        Ui::FormCharts* ui;

        void initTableColors();
        void CreateTableColors(const QList<QColor>& listColors);

    private slots:

        void saveDefaultTheme();
        void loadDefaultTheme();

        void tableColorChanged(QTableWidgetItem* tw);

    signals:

        //void FormCreateChart( const GraphsInfo & newGraphsInfo);

};

#endif
