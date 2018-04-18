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
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>

#include "Components/One_Menu_Button.h"

#include "Forms/formarrows.h"
#include "Forms/formcharts.h"
#include "Forms/formcliparts.h"
#include "Forms/formlayers.h"
#include "Forms/formnumberedbullets.h"
#include "Forms/formpictures.h"
#include "Forms/formscreenshots.h"
#include "Forms/formtextboxes.h"


// Forward Declaration
namespace Ui
{
    class MainWindow;
}


// Class
// -----

class MainWindow: public QMainWindow {
    Q_OBJECT


// Constructor & Destructor
public:

    explicit MainWindow(QWidget* /*parent*/ = 0);

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

  One_Menu_Button* list_buttons[8];
  int list_indexes[8];

  size_t selected_button;


// Interface Menu
private:

    void init();

    void buildMenu();

    void buildToolBar();


private slots:

    void event_onClick(unsigned char);


// Data Members
private:

    // UI
    Ui::MainWindow* ui;

    QSplitter           splitter;
    One_Layered_Canvas  canvas;
    QStackedWidget      stacked_widget;

    FormArrows          form_arrows;
    FormCharts          form_charts;
    FormCliparts        form_cliparts;
    FormLayers          form_layers;
    FormNumberedBullets form_bullets;
    FormPictures        form_pictures;
    FormScreenshots     form_screenshots;
    FormTextBoxes       form_textboxes;


private slots:

    // Menu and toolbar
    void save(bool);
    void saveAs(bool);
    void openFile(bool);
    void exportView(bool);
    void changeLateralForm(bool);
};

#endif
