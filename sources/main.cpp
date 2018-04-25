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
#include <QSettings>

// Main
// ----

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // App properties
    QApplication::setApplicationName("ClipEdit");
    QApplication::setOrganizationDomain("M2I");
    QApplication::setApplicationVersion("1.0");
    QApplication::setWindowIcon(QIcon(":/icons/icons/icon-clipedit.ico"));

    // Ini as default settings format
    QSettings::setDefaultFormat(QSettings::IniFormat);

    // Main window building and loop
    MainWindow w;
    w.show();

    return a.exec();
}
