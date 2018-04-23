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
#include<QScreen>
#include<QEvent>
#include<QKeyEvent>
#include<QCursor>
#include<QPixmap>
#include<QLabel>
#include<QPainter>
#include<QDebug>
#include<exception>

// Constructor, destructor
// -----------------------

FormScreenshots::FormScreenshots(QWidget* parent) :
    QWidget(parent), ui(new Ui::FormScreenshots)
{
    ui->setupUi(this);


    //THis makes Qt delete this widget when the widget has accepted the close even.
    this->setAttribute(Qt::WA_DeleteOnClose);

    //Some of these flags depend on whether the underlying window manager supports them
    //Produces a borderless window. The user cannot move or resize a borderless
    //window via the window system.
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);

    //Indicates that the widget has no background, i.e. when the widget receives paint events,
    //the background is not automatically repainted.
     setAttribute(Qt::WA_NoSystemBackground, true);

    //Indicates that the widget should have a translucent background,
    //i.e., any non-opaque regions of the widgets will be translucent
    //because the widget will have an alpha channel.
    //Setting this flag causes WA_NoSystemBackground to be set
    setAttribute(Qt::WA_TranslucentBackground);

    //Shows the widget in full-screen mode.
     this->showFullScreen();

    //Go QPushButton
    //connect(ui->pushButtonCapture, SIGNAL(clicked(bool)),
   // this, SLOT(Capture()));
    connect(ui->pushButtonCapture, SIGNAL(clicked(bool)),
            this, SLOT(Capture()));

    connect(ui->radioButtonRegion, SIGNAL(clicked(bool)),
            this, SLOT(CaptureRegion()));

    connect(ui->radioButtonWhole, SIGNAL(clicked(bool)),
            this, SLOT(CaptureWholeScreen()));



    //This property holds the cursor shape for this widget.
    m_savedcursor=cursor();

    //A crosshair cursor is used to help the user accurately
    //select a point on the screen.
    setCursor(Qt::CrossCursor);



    ui->spinBox->setSuffix(" s "); //OK it works
    ui->spinBox->setMaximum(60);   //idem

    //connect pour tempo: option
  //  connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(Capture()));

    //connect for cancel button: hide this window: OK
    connect(ui->checkBox, SIGNAL(clicked(bool)),
            this, SLOT(hide()));

    //OK
    connect(ui->pushButtonCancel, SIGNAL(clicked(bool)),
            this, SLOT(close()));

}



FormScreenshots::~FormScreenshots()
{
    //delete the object
   setCursor(m_savedcursor);
    delete ui;
}



void FormScreenshots::Capture()
{
     enum TypeCapture { WholeScreen, Region };

     switch (WholeScreen) {
     case WholeScreen:
         if(ui->radioButtonWhole->isChecked()){

                //CaptureWholeScreen();
             m_formscreenshot = new FormScreenshots(0);
             connect(m_formscreenshot, SIGNAL(mousePressEvent(QMoveEvent *event(bool))),
                     this, SLOT(CaptureWholeScreen()));

             QTimer::singleShot(m_delayspinbox->value() * 3000,
                                this, SLOT(CaptureWholeScreen()));
         }

         break;
      case Region:
         if(ui->radioButtonRegion->isChecked()) {

               // CaptureRegion();
              m_formscreenshot = new FormScreenshots(0);
              connect(m_formscreenshot, SIGNAL(mouseMoveEvent()),
                      this, SLOT(CaptureRegion(bool,QRect)));

             connect(m_formscreenshot, SIGNAL(dimensionsMade(bool,QRect)),
                     this, SLOT(CaptureRegion(bool,QRect)));
             m_formscreenshot->show();
         }

         break;
     default:
         close();
         break;
     }
}

void FormScreenshots::CaptureWholeScreen()
{
    QScreen *screen = QGuiApplication::primaryScreen();

    if(const QWindow *window = windowHandle())
        screen = window->screen();

    if(!screen) return;

     //The grabWindow() function grabs pixels from the screen, not from the window.
     m_pixmap = screen->grabWindow(0);

     FormScreenshots *w = new FormScreenshots(this);

    connect(w, SIGNAL(InsertImageText(QString)),
            this, SIGNAL(InsertImageText(QString)));

     //
   //  w->setBackgroundRole(m_pixmap);
     w->show();

}

void FormScreenshots::CaptureRegion(bool ok, QRect region)
{
    m_formscreenshot->close();
    if(ok)
    {
        m_region=region;
        QTimer::singleShot(m_delayspinbox->value() * 3000, this,
                           SLOT(CaptureRegion()));
    }

    QScreen *screen = QGuiApplication::primaryScreen();
    if(const QWindow *window = windowHandle())
        screen = window->screen();

    if(!screen) return;
    this->hide();

    m_pixmap = screen->grabWindow(0);

    QRect rec(m_region.x()+1,m_region.y()+1,m_region.width()-1,m_region.height()-1);
    QPixmap pix=m_pixmap.copy(rec);
    m_pixmap=pix;

    FormScreenshots *w = new FormScreenshots(this);


    connect(w,SIGNAL(InsertImageText(QString)),
            this, SIGNAL(InsertImageText(QString)));

  // w->setBackgroundRole(m_pixmap);
    w->show();

}

void FormScreenshots::mousePressEvent(QMouseEvent *event)
{
   //code: if m_point0 = m_point1 we get the whole screen.
    FormScreenshots::mousePressEvent(event);

    m_buttonpressed=true;
    m_point0=event->pos();
    m_point1=m_point0;
}

void FormScreenshots::mouseMoveEvent(QMouseEvent *event)
{
    //code
    //FormScreenshots::mouseMoveEvent(event);
    this->x = event->x();
    this->y = event->y();

    if(m_buttonpressed )
    {
        //Returns the position of the mouse cursor,
        //relative to the widget that received the event.
        //A widget that is not embedded in a parent widget is called a window.
        m_point1 =event->pos();
        update();
    }
}

void FormScreenshots::mouseReleaseEvent(QMouseEvent *event)
{
    //code
    //FormScreenshots::mouseReleaseEvent(event);

    emit mouseReleaseEvent();

    m_buttonpressed=false;
    emit dimensionsMade(true, m_region);
    close();
}

//void FormScreenshots::onMouseEvent(const QString &eventName, const QPoint &pos)
//{

//}

void FormScreenshots::hide()
{
    //
    m_delayspinbox = new QSpinBox(this);
    if (m_delayspinbox->value()== 0) {
       m_hidewindow->setDisabled(true);
        m_hidewindow->setChecked(false);
    } else {
        m_hidewindow->setDisabled(false);
    }
}








