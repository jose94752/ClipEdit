/*
================================================
* File:         formscreenshots.cpp
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to manage sceenshots capture
================================================
*/


#include "formscreenshots.h"
#include "ui_formscreenshots.h"
#include "../Items/screenshotsgraphicsitem.h"

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
#include<QRect>
#include<QRectF>
#include<QPointF>
#include<QGraphicsView>
#include<QDir>
#include<QFileDialog>
#include<QGraphicsScene>



// Constructor, destructor
// -----------------------

FormScreenshots::FormScreenshots(QWidget* parent)
    :   BaseForm(parent), ui(new Ui::FormScreenshots)
{
    ui->setupUi(this);

    //spinBox
    ui->spinBoxDelay->setSuffix(" s "); //OK it works

    //connection to radioButton
    connect(ui->radioButtonFast, SIGNAL(clicked(bool)),
            this, SLOT(on_changeTime()));
    connect(ui->radioButtonAverage, SIGNAL(clicked(bool)),
            this, SLOT(on_changeTime()));
    connect(ui->radioButtonSlow, SIGNAL(clicked(bool)),
            this, SLOT(on_changeTime()));

    //display the value on the spinBox
    ui->spinBoxDelay->setMaximum(300);

    //we create an instanace of the QTimer
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()),
            this, SLOT(timeFunction()));

    m_timer->setInterval(100);

    m_timer->start();

    //connect for Cancel button
    connect(ui->pushButtonCancel, SIGNAL(clicked(bool)),
            this, SLOT(quit()));





    //THis makes Qt delete this widget when the widget has accepted the close even.
   // this->setAttribute(Qt::WA_DeleteOnClose);

    //Some of these flags depend on whether the underlying window manager supports them
    //Produces a borderless window. The user cannot move or resize a borderless
    //window via the window system.
    //setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);

    //Indicates that the widget has no background, i.e. when the widget receives paint events,
    //the background is not automatically repainted.
    // setAttribute(Qt::WA_NoSystemBackground, true);

    //Indicates that the widget should have a translucent background,
    //i.e., any non-opaque regions of the widgets will be translucent
    //because the widget will have an alpha channel.
    //Setting this flag causes WA_NoSystemBackground to be set
   // setAttribute(Qt::WA_TranslucentBackground);

    //Shows the widget in full-screen mode.
   //  this->showFullScreen();

    //put here the signal that point to the mainwindow class
    //create a pixmap

    //open a directory
   // connect(ui->pushButtonCapture, SIGNAL(clicked(bool)), this, SLOT);

    //open a directory
    //connect(ui->pushButtonCapture, SIGNAL(clicked(bool)), this, SLOT(choose_screenshot()));

 //   connect(ui->radioButtonRegion, SIGNAL(clicked(bool)),
 //           this, SLOT(CaptureRegion()));



    //This property holds the cursor shape for this widget.
   // m_savedcursor=cursor();

    //A crosshair cursor is used to help the user accurately
    //select a point on the screen.
    //setCursor(Qt::CrossCursor);

    //connect pour tempo: option

    connect(ui->pushButtonCancel, SIGNAL(clicked(bool)),
            this, SLOT(close()));
}

FormScreenshots::~FormScreenshots()
{
    //delete the object
   delete m_timer;
   delete ui;
}


void FormScreenshots::timeFunction()
{
    //we get the current value
    int val = ui->spinBoxDelay->value();
    val++;
    ui->spinBoxDelay->setValue(val);
    ui->progressBar->setValue(val%100);


}

void FormScreenshots::on_changeTime()
{
    if (ui->radioButtonSlow->isChecked()) m_timer->setInterval(1000);
       else if (ui->radioButtonAverage->isChecked()) m_timer->setInterval(500);
    else if(ui->radioButtonFast->isChecked()) m_timer->setInterval(100);
}

void FormScreenshots::quit()
{
    this->close();

}

//1
void FormScreenshots::CaptureDesktop()
{
    //step1:
    //hide();
   // QTimer::singleShot(300, this, SLOT(snapshot()));  // long enough for window manager effects
}

//2
void FormScreenshots::CaptureArea(bool val, QRectF area)
{
//    this->close();
//    if (val)
//    {
//     m_area=area;
//     QTimer::singleShot(300,this,SLOT(snapshot()));
//    }

}

//3
void FormScreenshots::snapshot()
{
/**
    //step1 : OK but not local screen shot.
    static int count = 0;

   if(ui->radioButtonDeskcapture->isChecked() ){


    connect(m_delayspinbox, QOverload<int>::of(&QSpinBox::valueChanged),
                                                        this, &FormScreenshots::snapshot) ;

    QPixmap pix;
    pix = QPixmap::grabWindow(QApplication::desktop()->winId());

    pix.save(QString("/home/formation/doCapture/screenshot%1.png").arg(count));
    count++;

    //qApp is global pointer referring to the unique application object.
   // QTimer::singleShot(100, qApp, SLOT(quit())); // close the app in 0,3 secs
 }
*/

/**
    //new test
    if(ui->radioButtonDeskcapture->isChecked()) {
    QScreen *screen = QGuiApplication::primaryScreen();
    QPixmap qpix = screen->grabWindow(this->winId(), 0, 0, QApplication::desktop()->width(),
                  QApplication::desktop()->height());
    qpix.save("/home/formation/doCapture/Hello.png");
    this->show();
    }
*/

 /**
    //step2
    if (ui->radioButtonWholecapture->isChecked()) m_typecapture=Desktop;
   // updatehide();
    if ( m_typecapture==Desktop)
         QTimer::singleShot(200,this,SLOT(CaptureDesktop()));
    else
        {
        // m_formScreenshots = new FormScreenshots(0);
         connect(this ,SIGNAL(dimensionsMade(bool,QRect)),this,SLOT(CaptureArea(bool,QRect)));
         this->show();
        }
*/


  //step4
//    QScreen *m_screen = QGuiApplication::primaryScreen();
//    if (const QWindow *window = windowHandle())
//         m_screen = window->screen();

//    if (!m_screen)
//           return;

//    this->hide();
//    m_pix = m_screen->grabWindow(0);
//    QRect rec(m_area.x()+1,m_area.y()+1,m_area.width()-1,m_area.height()-1);
//    QPixmap pix=m_pix.copy(rec);
//    m_pix=pix;


//    //?
//    FormScreenshots *w= new FormScreenshots(this);


//    connect (this,SIGNAL(setBackground(QPixmap)),this,SIGNAL(setBackground(QPixmap)));
//    this->setBackground(m_pix);
//    this->show();

}


void FormScreenshots::mousePressEvent(QMouseEvent *event)
{
    //Whole screen capture
   // CaptureWholeScreen();

    //QMouseEvent::button() const : Returns the button that caused the event.
//    if(event->button() == Qt::LeftButton) {
//        qDebug() << "left clicked";


//        x=m_point0->x();
//        y=m_point0->y();
//        qDebug()<<x;


//        x=m_point1->x();
//        y=m_point1->y();
//        qDebug()<<y;

//         //QRect QRect::normalized() const : rectangle that has a non-negative width and height.
//        QRectF m_area;
//        m_area=QRectF(m_point0->x(),m_point0->y(),m_point1->x()-m_point0->x(),m_point1->y()-m_point0->y()).normalized();

        //
//        QScreen *screen = QGuiApplication::primaryScreen();
//        if (const QWindow *window = windowHandle())
//             screen = window->screen();
//        if (!screen)
//               return;

//        m_pixmap = screen->grabWindow(0);

//        QRect rec(m_area.x()+1,
//                  m_area.y()+1,
//                  m_area.width()-1,
//                  m_area.height()-1);

//        QPixmap p=m_pixmap.copy(rec);

//        m_pixmap=p;

         //  m_scene->setSceneRect(QRectF(0, 0, 5000, 5000));
         //  connect(m_scene, SIGNAL(itemInserted(Item*)), this, SLOT(itemInserted(tem*)));

}

void FormScreenshots::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
//    QPoint m_point1;
//    m_point1 = event->globalPos();//get global position according to ur parent-child relationship
//    QPainter m_painter(this);

//    p->drawRect(point1, point2);

//    emit mouseReleaseEvent();
//    m_buttonpressed=false;
//    emit dimensionsMade(true, m_region);
//    close();

//    if(event->MouseButtonRelease)
//    {
//         qDebug () << "released";
//        // QPointF point1= ui->graphicsView->mapFromScene(e->posF());
//         QPoint point1;
//         x1=point1.x();
//         qDebug()<<x1;
//         y1= point1.y();
//         qDebug()<<y1;
//         qDebug()<<point1;
    //    }
}


void FormScreenshots::choose_screenshot()
{
    QString homepath = QDir::homePath();

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open ClipEdit Project"), homepath, tr("ClipEdit Files (*.png)"));

    if(fileName.isEmpty())
        return;
    QPixmap pix (fileName);

    emit setBackground(pix);
}

void FormScreenshots::updatehide()
{
    m_delayspinbox = new QSpinBox(this);

    if (m_delayspinbox->value()== 0)
    {
       m_hidewindow->setDisabled(true);
       m_hidewindow->setChecked(false);
    }
    else
    {
        m_hidewindow->setDisabled(false);
    }
}

// Load data
// ---------

void FormScreenshots::loadFromItem(BaseGraphicItem* item) const
{
    if (qgraphicsitem_cast<ScreenshotsGraphicsItem*>(item))
    {
        ScreenshotsGraphicsItem* castedItem = qgraphicsitem_cast<ScreenshotsGraphicsItem*>(item);

        // Load data into the form
    }
}

// Translation
// -----------

void FormScreenshots::retranslate()
{
    ui->retranslateUi(this);
}




