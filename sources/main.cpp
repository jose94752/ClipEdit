/*
================================================
* File:         main.cpp
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Application entry point
================================================
*/

// Includes
// --------

#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

// Main
// ----

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QDesktopWidget *desktop=a.desktop();

    // Defining app name and version
    QApplication::setApplicationName("ClipEdit");
    QApplication::setOrganizationDomain("M2I");
    QApplication::setApplicationVersion("1.0");
    QApplication::setWindowIcon(QIcon(":/icons/icons/icon-clipedit.ico"));

    MainWindow w;
    w.show();

    return a.exec();
}
