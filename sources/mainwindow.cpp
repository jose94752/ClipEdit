#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

///slot save: This function is told when users tells to save data
void MainWindow::slot_save(bool isok)
{
    qDebug()<<"save";
}

///slot open: This function is told when users tells to open data
void MainWindow::slot_open(bool)
{
    qDebug()<<"open";
}

///slot exports: This function is told when users tells to export data
void MainWindow::slot_exports(bool)
{
    qDebug()<<"exports";
}
