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

    connect(ui->actionSave,SIGNAL(triggered(bool)),this,SLOT(save(bool)));//save
    connect(ui->actionOpen,SIGNAL(triggered(bool)),this,SLOT(openFile(bool)));//open
    connect(ui->actionExports,SIGNAL(triggered(bool)),this,SLOT(exportView(bool)));//exports
}

MainWindow::~MainWindow()
{
    delete ui;
}

// UI building
// -----------

///
/// \brief MainWindow::buildToolBar
/// Initializations and methods calls related to the menu
///
void MainWindow::buildMenu()
{

}

///
/// \brief MainWindow::buildToolBar
/// Initializations and methods calls related to the toolbar
///
void MainWindow::buildToolBar()
{

}

// Slots
// -----

///
/// \brief save
/// This function is called on save
///
void MainWindow::save(bool isok)
{
    // To do
}

///slot open: This function is told when users tells to open data
void MainWindow::openFile(bool)
{
    // To do
}

///slot exports: This function is told when users tells to export data
void MainWindow::exportView(bool)
{
    // To do
}
