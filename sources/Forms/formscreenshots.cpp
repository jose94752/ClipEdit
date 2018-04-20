/*
================================================
* File:         formforms.cpp
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to create TextBoxItem
================================================
*/


#include "formscreenshots.h"
#include "ui_formscreenshots.h"

//add
#include<QTimer>
#include<QWindow>
#include<QDesktopWidget>
#include<QApplication>

// Constructor, destructor
// -----------------------

FormScreenshots::FormScreenshots(QWidget* parent) :
    QWidget(parent), ui(new Ui::FormScreenshots)
{
    ui->setupUi(this);

    //connect for the firs signal
    connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(Capture()));
    //
    m_buttongroup.addButton(ui->radioButton);
}

FormScreenshots::~FormScreenshots()
{
    delete ui;
}

void FormScreenshots::Capture()
{
    if(m_typecapture == WholeScreen) {
        QTimer::singleShot(200, this, SLOT(CaptureWholeScreen()));
    }


}

void FormScreenshots::CaptureWholeScreen()
{
    QScreen *screen = QGuiApplication::primaryScreen();

    if(const QWindow *window = windowHandle()) screen = window->screen();

    if(!screen) return;

 //  m_pixmap = screen

}



