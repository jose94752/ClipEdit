#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ///connection between signals and slots when users select save, open or exports in the menu
    connect(ui->actionSave,SIGNAL(triggered(bool)),this,SLOT(slot_save(bool)));//save
    connect(ui->actionOpen,SIGNAL(triggered(bool)),this,SLOT(slot_open(bool)));//open
    connect(ui->actionExports,SIGNAL(triggered(bool)),this,SLOT(slot_exports(bool)));//exports
}

MainWindow::~MainWindow()
{
    delete ui;
}

///slot save: This function is told when users tells to save data
void MainWindow::slot_save(bool isok)
{
    //qDebug()<<"save";
}

///slot open: This function is told when users tells to open data
void MainWindow::slot_open(bool)
{
    //qDebug()<<"open";
}

///slot exports: This function is told when users tells to export data
void MainWindow::slot_exports(bool)
{
    //qDebug()<<"exports";
}
