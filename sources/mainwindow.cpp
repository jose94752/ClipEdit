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

#include "mainwindow.h"
#include "ui_mainwindow.h"

// Constructor, destructor
// -----------------------

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    buildView();
}

///
/// \brief MainWindow::buildMenu
/// Initializations and methods calls related to the menu
///
void MainWindow::buildMenu()
{
    connect(ui->actionSave, SIGNAL(triggered(bool)), this, SLOT(save(bool)));
    connect(ui->actionSave, SIGNAL(triggered(bool)), this, SLOT(save_as(bool)));
    connect(ui->actionOpen, SIGNAL(triggered(bool)), this, SLOT(openFile(bool)));
    connect(ui->actionExports, SIGNAL(triggered(bool)), this, SLOT(exportView(bool)));
}

///
/// \brief MainWindow::buildToolBar
/// Initializations and methods calls related to the toolbar
///
void MainWindow::buildToolBar()
{
    ui->mainToolBar->addAction(ui->actionArrow);
    ui->mainToolBar->addAction(ui->actionChart);
    ui->mainToolBar->addAction(ui->actionClipart);
    ui->mainToolBar->addAction(ui->actionNumberedBullets);
    ui->mainToolBar->addAction(ui->actionPicture);
    ui->mainToolBar->addAction(ui->actionTextBox);
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(ui->actionScreenshot);
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(ui->actionNewLayer);

    // Connects
    connect(ui->actionArrow, SIGNAL(triggered(bool)), this, SLOT(changeLateralForm(bool)));
    connect(ui->actionChart, SIGNAL(triggered(bool)), this, SLOT(changeLateralForm(bool)));
    connect(ui->actionClipart, SIGNAL(triggered(bool)), this, SLOT(changeLateralForm(bool)));
    connect(ui->actionNumberedBullets, SIGNAL(triggered(bool)), this, SLOT(changeLateralForm(bool)));
    connect(ui->actionPicture, SIGNAL(triggered(bool)), this, SLOT(changeLateralForm(bool)));
    connect(ui->actionScreenshot, SIGNAL(triggered(bool)), this, SLOT(changeLateralForm(bool)));
    connect(ui->actionTextBox, SIGNAL(triggered(bool)), this, SLOT(changeLateralForm(bool)));
}

///
/// \brief MainWindow::buildView
/// Initializations and methods calls related to the main view
///
void MainWindow::buildView()
{
    int offset = 600;
    m_scene.setSceneRect((-width()-offset)/2, (-height()-offset)/2, width()+offset, height()+offset);
    ui->graphicsView->setScene(&m_scene);
}

// Slots
// -----

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
    //to do
}

///
/// \brief openFile
/// This slot is called on file open
void MainWindow::openFile(bool)
{
    // To do
}

///
/// \brief exportView
/// This slot is called on export
void MainWindow::exportView(bool)
{
    // To do
}

///
/// \brief MainWindow::changeLateralForm
/// Change stacked widget view depending on the action clicked
void MainWindow::changeLateralForm(bool)
{
    if (sender() == ui->actionArrow)
        ui->stackedWidget->setCurrentIndex(0);
    else if (sender() == ui->actionChart)
        ui->stackedWidget->setCurrentIndex(1);
    else if (sender() == ui->actionClipart)
        ui->stackedWidget->setCurrentIndex(2);
    else if (sender() == ui->actionLayers)
        ui->stackedWidget->setCurrentIndex(3);
    else if (sender() == ui->actionNumberedBullets)
        ui->stackedWidget->setCurrentIndex(4);
    else if (sender() == ui->actionPicture)
        ui->stackedWidget->setCurrentIndex(5);
    else if (sender() == ui->actionExports)
        ui->stackedWidget->setCurrentIndex(6);
    else if (sender() == ui->actionScreenshot)
        ui->stackedWidget->setCurrentIndex(7);
    else if (sender() == ui->actionTextBox)
        ui->stackedWidget->setCurrentIndex(8);
}
