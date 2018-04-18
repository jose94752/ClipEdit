/*
================================================
* File:         mainwindow.cpp
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Application's main window
================================================
*/

// Includes
// --------

#include <QDebug>
#include <QFile>
#include <QFileDialog>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Classes/save.h"


#define INIT_BUTTON(BUTTON_ID, TEXT, PIXMAP) \
    list_buttons[BUTTON_ID]->set_text(TEXT); \
    list_buttons[BUTTON_ID]->set_pixmap(PIXMAP); \
    list_buttons[BUTTON_ID]->button_id = BUTTON_ID; \
    list_buttons[BUTTON_ID]->unselect(true); \
     \
    connect(list_buttons[BUTTON_ID], SIGNAL( on_click(unsigned char) ), this, SLOT( event_onClick(unsigned char) ));


#define INIT_SELECTED_BUTTON(BUTTON_ID, TEXT, PIXMAP) \
    list_buttons[BUTTON_ID]->set_text(TEXT); \
    list_buttons[BUTTON_ID]->set_pixmap(PIXMAP); \
    list_buttons[BUTTON_ID]->select(); \
    list_buttons[BUTTON_ID]->button_id = BUTTON_ID; \
    selected_button = BUTTON_ID; \
     \
    connect(list_buttons[BUTTON_ID], SIGNAL( on_click(unsigned char) ), this, SLOT( event_onClick(unsigned char) ));


// Constructor, destructor
// -----------------------

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow), form_arrows(canvas),
    form_charts(canvas), form_cliparts(canvas), form_layers(canvas),
    form_bullets(canvas), form_pictures(canvas), form_screenshots(canvas),
    form_textboxes(canvas) {

    ui->setupUi(this);

    splitter.setObjectName(QStringLiteral("splitter"));
    splitter.setOrientation(Qt::Horizontal);

    canvas.setObjectName(QStringLiteral("canvas"));
    canvas.setMinimumSize(QSize(400, 0));
    canvas.init();

    splitter.addWidget(&canvas);

    stacked_widget.setObjectName(QStringLiteral("stacked_widget"));
    splitter.addWidget(&stacked_widget);

    ui->centralLayout->addWidget(&splitter);

    init();
}


MainWindow::~MainWindow()
{
    delete ui;
}


// UI building
// -----------

void MainWindow::init()
{
    buildMenu();
    buildToolBar();
}

///
/// \brief MainWindow::buildMenu
/// Initializations and methods calls related to the menu
///
void MainWindow::buildMenu()
{
    // Connects
    connect(ui->actionSave,    SIGNAL( triggered(bool) ), this, SLOT( save(bool) ));
    connect(ui->actionSave_as,    SIGNAL( triggered(bool) ), this, SLOT( saveAs(bool) ));
    connect(ui->actionOpen,    SIGNAL( triggered(bool) ), this, SLOT( openFile(bool) ));
    connect(ui->actionExports, SIGNAL( triggered(bool) ), this, SLOT( exportView(bool) ));

    connect(ui->actionArrow,           SIGNAL( triggered(bool) ), this, SLOT( changeLateralForm(bool) ));
    connect(ui->actionChart,           SIGNAL( triggered(bool) ), this, SLOT( changeLateralForm(bool) ));
    connect(ui->actionClipart,         SIGNAL( triggered(bool) ), this, SLOT( changeLateralForm(bool) ));
    connect(ui->actionNumberedBullets, SIGNAL( triggered(bool) ), this, SLOT( changeLateralForm(bool) ));
    connect(ui->actionPicture,         SIGNAL( triggered(bool) ), this, SLOT( changeLateralForm(bool) ));
    connect(ui->actionScreenshot,      SIGNAL( triggered(bool) ), this, SLOT( changeLateralForm(bool) ));
    connect(ui->actionTextBox,         SIGNAL( triggered(bool) ), this, SLOT( changeLateralForm(bool) ));
}

///
/// \brief MainWindow::buildToolBar
/// Initializations and methods calls related to the toolbar
///
void MainWindow::buildToolBar() {
    list_buttons[BUTTON_ID_ARROW]      = ui->button_arrow;
    list_buttons[BUTTON_ID_CHART]      = ui->button_chart;
    list_buttons[BUTTON_ID_BULLET]     = ui->button_bullet;
    list_buttons[BUTTON_ID_CLIPART]    = ui->button_clipart;
    list_buttons[BUTTON_ID_PICTURE]    = ui->button_picture;
    list_buttons[BUTTON_ID_TEXTBOX]    = ui->button_textbox;
    list_buttons[BUTTON_ID_SCREENSHOT] = ui->button_screenshot;
    list_buttons[BUTTON_ID_LAYERS]     = ui->button_layers;

    INIT_BUTTON(BUTTON_ID_ARROW,      "Draw\nArrow",      ":/icons/icons/arrow-icon.png")
    INIT_BUTTON(BUTTON_ID_CHART,      "Draw\nChart",      ":/icons/icons/chart-icon.png")
    INIT_BUTTON(BUTTON_ID_BULLET,     "Draw\nBullet",     ":/icons/icons/numbered-bullet-icon.png")
    INIT_SELECTED_BUTTON(BUTTON_ID_CLIPART, "Insert\nClipart", ":/icons/icons/clipart-icon.png")
    INIT_BUTTON(BUTTON_ID_PICTURE,    "Insert\nPicture",  ":/icons/icons/chart-icon.png")
    INIT_BUTTON(BUTTON_ID_TEXTBOX,    "Insert\nTextbox",  ":/icons/icons/textbox-icon.png")
    INIT_BUTTON(BUTTON_ID_SCREENSHOT, "Take\nScreenshot", ":/icons/icons/screenshot-icon.png")
    INIT_BUTTON(BUTTON_ID_LAYERS,     "Manage\nLayers",   ":/icons/icons/layer-icon.png")

//  Remove all useless pages
    for(int page = 0; page < stacked_widget.count(); ++page) {
        QWidget* widget = stacked_widget.widget(page);
        stacked_widget.removeWidget(widget);
        widget->deleteLater();
    }

    list_indexes[BUTTON_ID_ARROW]      = stacked_widget.addWidget(&form_arrows);
    list_indexes[BUTTON_ID_CHART]      = stacked_widget.addWidget(&form_charts);
    list_indexes[BUTTON_ID_BULLET]     = stacked_widget.addWidget(&form_bullets);
    list_indexes[BUTTON_ID_CLIPART]    = stacked_widget.addWidget(&form_cliparts);
    list_indexes[BUTTON_ID_PICTURE]    = stacked_widget.addWidget(&form_pictures);
    list_indexes[BUTTON_ID_TEXTBOX]    = stacked_widget.addWidget(&form_textboxes);
    list_indexes[BUTTON_ID_SCREENSHOT] = stacked_widget.addWidget(&form_screenshots);
    list_indexes[BUTTON_ID_LAYERS]     = stacked_widget.addWidget(&form_layers);

    stacked_widget.setCurrentIndex(list_indexes[selected_button]);
}


// Slots
// -----

///
/// \brief MainWindow::changeLateralForm
/// Change stacked widget view depending on the action clicked
void MainWindow::changeLateralForm(bool)
{
    if (sender() == ui->actionArrow) {
        stacked_widget.setCurrentIndex(list_indexes[BUTTON_ID_ARROW]);
    } else if (sender() == ui->actionChart) {
        stacked_widget.setCurrentIndex(list_indexes[BUTTON_ID_CHART]);
    } else if (sender() == ui->actionClipart) {
        stacked_widget.setCurrentIndex(list_indexes[BUTTON_ID_CLIPART]);
    } else if (sender() == ui->actionLayers) {
        stacked_widget.setCurrentIndex(list_indexes[BUTTON_ID_LAYERS]);
    } else if (sender() == ui->actionNumberedBullets) {
        stacked_widget.setCurrentIndex(list_indexes[BUTTON_ID_BULLET]);
    } else if (sender() == ui->actionPicture) {
        stacked_widget.setCurrentIndex(list_indexes[BUTTON_ID_PICTURE]);
    } else if (sender() == ui->actionExports) {
        stacked_widget.setCurrentIndex(list_indexes[BUTTON_ID_PICTURE]);
    } else if (sender() == ui->actionScreenshot) {
    } else if (sender() == ui->actionTextBox) {
        stacked_widget.setCurrentIndex(list_indexes[BUTTON_ID_TEXTBOX]);
    }
}


void MainWindow::event_onClick(unsigned char clicked_button) {
    if (selected_button != clicked_button) {
        list_buttons[clicked_button]->select();
        list_buttons[selected_button]->unselect();

        selected_button = clicked_button;

        stacked_widget.setCurrentIndex(list_indexes[selected_button]);
    }
}


///
/// \brief exportView
/// This slot is called on export
void MainWindow::exportView(bool)
{
    // To do
}


///
/// \brief openFile
/// This slot is called on file open
void MainWindow::openFile(bool)
{
    // To do
}


///
/// \brief save
/// This slot is called on save
///
void MainWindow::save(bool)
{
    // To do
}


///
/// \brief MainWindow::saveAs
///
void MainWindow::saveAs(bool)
{
    QString fileName=QFileDialog::getSaveFileName(this,tr("Save File"),"project.clipEdit",tr("ClipEdit (*.clipEdit)"));
    if(fileName!=""){
        QString extfilename=Save::verifyExtension(fileName);
        QFile fileToSave(fileName);
        if(fileName!=extfilename && fileToSave.exists()){
            //DialogFileAlreadyExists dfae;
            //dfae.exec();
        }else{
            ui->actionSave->setEnabled(true);
            Save save(fileName);
        }
    }
}
