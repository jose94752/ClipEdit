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

    buildMenu();
    buildToolBar();
    buildView();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// UI building
// -----------

///
/// \brief MainWindow::buildMenu
/// Initializations and methods calls related to the menu
///
void MainWindow::buildMenu()
{
    connect(ui->actionSave, SIGNAL(triggered(bool)), this, SLOT(save(bool)));
    connect(ui->actionOpen, SIGNAL(triggered(bool)), this, SLOT(openFile(bool)));
    connect(ui->actionExports, SIGNAL(triggered(bool)), this, SLOT(exportView(bool)));
}

///
/// \brief MainWindow::buildToolBar
/// Initializations and methods calls related to the toolbar
///
void MainWindow::buildToolBar()
{

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
