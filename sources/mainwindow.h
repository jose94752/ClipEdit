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

namespace Ui
{
    class MainWindow;
}

// Class
// -----

class MainWindow
    :   public QMainWindow
{
    Q_OBJECT

    public:

        // Constructor, destructor
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private:

        // UI
        Ui::MainWindow *ui;

        // UI building
        void buildMenu();
        void buildToolBar();

    private slots:

        // Menu slots
        void save(bool);
        void openFile(bool);
        void exportView(bool);
};

#endif
