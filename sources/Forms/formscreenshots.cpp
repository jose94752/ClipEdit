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
#include<QPointF>
#include<QGraphicsView>
#include<QDir>
#include<QFileDialog>



// Constructor, destructor
// -----------------------

FormScreenshots::FormScreenshots(QWidget* parent)
    :   BaseForm(parent), ui(new Ui::FormScreenshots)
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
     //this->showFullScreen();

    //put here the signal that point to the mainwindow class
    //create a pixmap

    connect(ui->pushButtonCapture, SIGNAL(clicked(bool)), this, SLOT(choose_screenshot()));

 //   connect(ui->radioButtonRegion, SIGNAL(clicked(bool)),
 //           this, SLOT(CaptureRegion()));

    connect(ui->radioButtonWholecapture, SIGNAL(clicked(bool)),
            this, SLOT(CaptureDesktop()));



    //This property holds the cursor shape for this widget.
   // m_savedcursor=cursor();

    //A crosshair cursor is used to help the user accurately
    //select a point on the screen.
    //setCursor(Qt::CrossCursor);

    ui->spinBoxDelay->setSuffix(" s "); //OK it works
    ui->spinBoxDelay->setMaximum(60);   //idem
    ui->spinBoxDelay->setValue(1);

    //connect pour tempo: option
//    connect(m_delayspinbox, QOverload<int>::of(&QSpinBox::valueChanged),
//            this, &FormScreenshots::updatehide);
    //OK
    connect(ui->pushButtonCancel, SIGNAL(clicked(bool)),
            this, SLOT(close()));

}

FormScreenshots::~FormScreenshots()
{
    //delete the object
   //setCursor(m_savedcursor);
   delete ui;
}

//1
void FormScreenshots::CaptureDesktop()
{
    //step1:
    //hide();
    QTimer::singleShot(300, this, SLOT(snapshot()));  // long enough for window manager effects
}

//2
void FormScreenshots::CaptureArea(bool val, QRect area)
{
    this->close();
    if (val)
    {
     m_area=area;
     QTimer::singleShot(300,this,SLOT(snapshot()));
    }
}

//3
void FormScreenshots::snapshot()
{
/**
    //step1
    static int count = 0;

    QPixmap p = QPixmap::grabWindow(QApplication::desktop()->winId());
    p.save(QString("/home/toumi/doCapture/screenshot%1.png").arg(count));
    count++;
    show();

    //qApp is global pointer referring to the unique application object.
    QTimer::singleShot(300, qApp, SLOT(quit())); // close the app in 0,3 secs

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

    //step3
    QScreen *screen = QGuiApplication::primaryScreen();
    if (const QWindow *window = windowHandle())
         screen = window->screen();
    if (!screen)
           return;
    this->hide();
    m_pixmap = screen->grabWindow(0);
    QRect rec(m_region.x()+1,m_region.y()+1,m_region.width()-1,m_region.height()-1);
    QPixmap pix=m_pixmap.copy(rec);
    m_pixmap=pix;
    if ( ui->checkBoxHideAncestor->isChecked()) emit showAncestors();
    DialogScreenShotCompose *w= new DialogScreenShotCompose(this);
    connect (w,SIGNAL(InsertImageText(QString)),this,SIGNAL(InsertImageText(QString)));
    w->setBackground(m_pixmap);
    w->exec();

  */

  //
    QScreen *m_screen = QGuiApplication::primaryScreen();
    if (const QWindow *window = windowHandle())
         m_screen = window->screen();

    if (!m_screen)
           return;

    this->hide();
    m_pix = m_screen->grabWindow(0);
    QRect rec(m_area.x()+1,m_area.y()+1,m_area.width()-1,m_area.height()-1);
    QPixmap pix=m_pix.copy(rec);
    m_pix=pix;


    //?
    FormScreenshots *w= new FormScreenshots(this);


    connect (w,SIGNAL(InsertImageText(QPixmap)),this,SIGNAL(InsertImageText(QPixmap)));
    w->setBackground(m_pix);
    w->show();

/**
    //new test
    QScreen *QSCREEN = QGuiApplication::primaryScreen();
    QPixmap qpix = QSCREEN->grabWindow(this->winId(), 0, 0, QApplication::desktop()->width(),
                  QApplication::desktop()->height());
    qpix.save("/home/formation/doCapture/Hello.png");
 */
}


void FormScreenshots::mousePressEvent(QMouseEvent *event)
{
    //Whole screen capture
   // CaptureWholeScreen();

    //QMouseEvent::button() const : Returns the button that caused the event.
    if(event->button() == Qt::LeftButton) {
        qDebug() << "left clicked";


        x=m_point->x();
        qDebug()<<x;
        y= m_point->y();
        qDebug()<<y;
        qDebug()<<m_point;

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





