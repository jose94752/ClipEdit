/*
================================================
* File:         mainwindow.h
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Application's main window
================================================
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Includes
// --------

#include <QMainWindow>
#include <QMap>
#include <QGraphicsScene>

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QAreaSeries>

#include "Forms/formarrows.h"
#include "Forms/formcharts.h"
#include "Forms/formcliparts.h"
#include "Forms/formlayers.h"
#include "Forms/formnumberedbullets.h"
#include "Forms/formpictures.h"
#include "Forms/formscreenshots.h"
#include "Forms/formtextboxes.h"
#include "Items/numberedbulletgraphicitem.h"

// Forward declaration
namespace Ui
{
    class MainWindow;
}


// Class
// -----

class MainWindow
    :   public QMainWindow
{
    Q_OBJECT

    public:

        // Constructor & Destructor
        explicit MainWindow(QWidget* parent = 0);
        ~MainWindow();


private:

        // Buttons Ids
        enum e_BUTTON_IDS {
            BUTTON_ID_ARROW = 0,
            BUTTON_ID_CHART,
            BUTTON_ID_BULLET,
            BUTTON_ID_CLIPART,
            BUTTON_ID_PICTURE,
            BUTTON_ID_TEXTBOX,
            BUTTON_ID_SCREENSHOT,
            BUTTON_ID_LAYERS,
            NB_BUTTONS
        };

        // UI
        Ui::MainWindow* ui;

        // Forms
        FormArrows          m_formArrows;
        FormCharts          m_formCharts;
        FormCliparts        m_formCliparts;
        FormLayers          m_formLayers;
        FormNumberedBullets m_formBullets;
        FormPictures        m_formPictures;
        FormScreenshots     m_formScreenshots;
        FormTextBoxes       m_formTextboxes;

        QMap<e_BUTTON_IDS, int> m_listIndexes;

        // Scene
        QGraphicsScene m_scene;

        // Building
        void init();
        void buildMenu();
        void buildToolBar();
        void buildView();

    private slots:

        // Menu and toolbar
        void save(bool);
        void saveAs(bool);
        void openFile(bool);
        void exportView(bool);
        void actionClicked(bool);
        void resizeTold(bool);
        void slotNew(bool);
        void showAboutDialog(bool);

        // SLOTS TEST GRAPHIC ITEM INSERTION
        void slotNumberedBullets();
        void slotTextBoxes();
        void slotTextPicture();
        void slotGraphs();
        void slotArrowsGraphicsItem();

};

#endif
