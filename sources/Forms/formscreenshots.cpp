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
#include<QGraphicsScene>
#include<QScreen>
#include<QKeyEvent>

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

   connect(ui->checkBox_2, SIGNAL(clicked(bool)),
           this, SLOT(update()));



}

FormScreenshots::~FormScreenshots()
{
    delete ui;
}



void FormScreenshots::mousePressEvent(QMouseEvent *ev)
{
   //code
    m_buttonpressed=true;
    m_point0=ev->pos();
    m_point1=m_point0;
}

void FormScreenshots::mouseMoveEvent(QMouseEvent *ev)
{
    //code
    if(m_buttonpressed )
    {
        m_point1 =ev->pos();

    }
}

void FormScreenshots::mouseReleaseEvent(QMouseEvent *ev)
{
    //code

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

    if(const QWindow *window = windowHandle())
        screen = window->screen();

    if(!screen) return;

     m_pixmap = screen->grabWindow(0);

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


void FormScreenshots::ChangeHeight(int)
{

}

void FormScreenshots::ChangeWidth(int)
{

}



