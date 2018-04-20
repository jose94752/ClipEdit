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

    //connect pour tempo
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(hide()));

    //the different frames of radioButton
   // m_buttongroup.addButton(ui->radioButton);

   //m_delayspinbox->setValue(6);
}

FormScreenshots::~FormScreenshots()
{
    delete ui;
}

void FormScreenshots::Capture()
{
    if(m_typecapture == WholeScreen) {
        QTimer::singleShot(m_delayspinbox->value() * 1000,
                           this, SLOT(CaptureWholeScreen()));
    }


}

void FormScreenshots::CaptureWholeScreen()
{
    QScreen *screen = QGuiApplication::primaryScreen();

    if(const QWindow *window = windowHandle()) screen = window->screen();

    if(!screen) return;

 //  m_pixmap = screen

}

void FormScreenshots::hide()
{
    //1
    m_delayspinbox = new QSpinBox(this);
    m_delayspinbox->setSuffix(tr("s"));
    m_delayspinbox->setMaximum(60);

    if (m_delayspinbox->value() == 0) {
        m_hidewindow->setDisabled(true);
        m_hidewindow->setChecked(false);
    } else {
        m_hidewindow->setDisabled(false);
    }

}



