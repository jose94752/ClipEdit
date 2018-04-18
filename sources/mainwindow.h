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

#include "Forms/formarrows.h"
#include "Forms/formcharts.h"
#include "Forms/formcliparts.h"
#include "Forms/formlayers.h"
#include "Forms/formnumberedbullets.h"
#include "Forms/formpictures.h"
#include "Forms/formscreenshots.h"
#include "Forms/formtextboxes.h"


// Forward declaration
namespace Ui
{
    class MainWindow;
}


// Class
// -----

class MainWindow: public QMainWindow
{
    Q_OBJECT


    // Constructor & Destructor
    public:

        explicit MainWindow(QWidget* parent = 0);

        ~MainWindow();


    // Buttons Ids
    private:

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


    // Main Menu
    private:

      QMap<e_BUTTON_IDS, int> m_listIndexes;

      int m_selectedForm;



    private:

        void init();

        void buildMenu();

        void buildToolBar();


    // Data Members
    private:

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


    private slots:

        // Menu and toolbar
        void save(bool);
        void saveAs(bool);
        void openFile(bool);
        void exportView(bool);
        void changeLateralForm(bool);
};

#endif
