/*
================================================
* File:         mainwindow.cpp
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Application's main window
================================================
*/

// Includes
// --------

#include <QDebug>
#include <QFile>
#include <QFileDialog>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Classes/save.h"

#include "picturesgraphicsitem.h"
#include "numberedbulletgraphicitem.h"
#include "textboxitem.h"
#include "Classes/graphsgraphicsitem.h"
#include "Forms/resizescenedialog.h"
#include "Classes/arrowsgraphicsitem.h"
#include "Forms/dialogfilealreadyexists.h"

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QAreaSeries>

QT_CHARTS_USE_NAMESPACE

// Constructor, destructor
// -----------------------

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}


MainWindow::~MainWindow()
{
    delete ui;
}


// UI building
// -----------

void MainWindow::init()
{
    buildMenu();
    buildToolBar();
    buildView();
}

///
/// \brief MainWindow::buildMenu
/// Initializations and methods calls related to the menu
///
void MainWindow::buildMenu()
{
    // Connects
    connect(ui->actionSave,         SIGNAL( triggered(bool) ), this, SLOT( save(bool) ));
    connect(ui->actionSaveAs,       SIGNAL( triggered(bool) ), this, SLOT( saveAs(bool) ));
    connect(ui->actionOpen,         SIGNAL( triggered(bool) ), this, SLOT( openFile(bool) ));
    connect(ui->actionExports,      SIGNAL( triggered(bool) ), this, SLOT( exportView(bool) ));
    connect(ui->actionresize,       SIGNAL( triggered(bool) ), this, SLOT( resizeTold(bool) ));
    connect(ui->actionNew,          SIGNAL( triggered(bool) ), this, SLOT( slotNew(bool) ));

    connect(ui->actionArrow,           SIGNAL( triggered(bool) ), this, SLOT( actionClicked(bool) ));
    connect(ui->actionChart,           SIGNAL( triggered(bool) ), this, SLOT( actionClicked(bool) ));
    connect(ui->actionClipart,         SIGNAL( triggered(bool) ), this, SLOT( actionClicked(bool) ));
    connect(ui->actionNumberedBullets, SIGNAL( triggered(bool) ), this, SLOT( actionClicked(bool) ));
    connect(ui->actionPicture,         SIGNAL( triggered(bool) ), this, SLOT( actionClicked(bool) ));
    connect(ui->actionScreenshot,      SIGNAL( triggered(bool) ), this, SLOT( actionClicked(bool) ));
    connect(ui->actionTextBox,         SIGNAL( triggered(bool) ), this, SLOT( actionClicked(bool) ));
    connect(ui->actionLayers,          SIGNAL( triggered(bool) ), this, SLOT( actionClicked(bool) ));

    // INSERT YOUR GRAPHIC ITEMS SLOT HERE
    connect(ui->actionTextBox, SIGNAL(triggered(bool)), this, SLOT(slotTextBoxes()));
    connect(ui->actionPicture, SIGNAL(triggered(bool)), this, SLOT(slotTextPicture()));
    connect(m_formBullets.getGoPushButton(),SIGNAL(clicked(bool)), SLOT(slotNumberedBullets()));
    connect(ui->actionChart, SIGNAL(triggered(bool)), this, SLOT(slotGraphs()));
    connect(ui->actionArrow, SIGNAL(triggered(bool)),this,SLOT(slotArrowsGraphicsItem()));
}

///
/// \brief MainWindow::buildToolBar
/// Initializations and methods calls related to the toolbar
///
void MainWindow::buildToolBar()
{
    // Remove all useless pages
    for(int page = 0; page < ui->stackedWidgetForms->count(); ++page)
    {
        QWidget* widget = ui->stackedWidgetForms->widget(page);
        ui->stackedWidgetForms->removeWidget(widget);
        widget->deleteLater();
    }

    m_listIndexes.insert(BUTTON_ID_ARROW,       ui->stackedWidgetForms->addWidget(&m_formArrows));
    m_listIndexes.insert(BUTTON_ID_CHART,       ui->stackedWidgetForms->addWidget(&m_formCharts));
    m_listIndexes.insert(BUTTON_ID_BULLET,      ui->stackedWidgetForms->addWidget(&m_formBullets));
    m_listIndexes.insert(BUTTON_ID_CLIPART,     ui->stackedWidgetForms->addWidget(&m_formCliparts));
    m_listIndexes.insert(BUTTON_ID_PICTURE,     ui->stackedWidgetForms->addWidget(&m_formPictures));
    m_listIndexes.insert(BUTTON_ID_TEXTBOX,     ui->stackedWidgetForms->addWidget(&m_formTextboxes));
    m_listIndexes.insert(BUTTON_ID_SCREENSHOT,  ui->stackedWidgetForms->addWidget(&m_formScreenshots));
    m_listIndexes.insert(BUTTON_ID_LAYERS,      ui->stackedWidgetForms->addWidget(&m_formLayers));

    ui->stackedWidgetForms->setCurrentIndex(0);
}

void MainWindow::buildView()
{
    m_scene.setSceneRect(-400, -400, 800, 800);
    ui->graphicsView->setScene(&m_scene);
}

// Slots
// -----

///
/// \brief MainWindow::changeLateralForm
/// Change stacked widget view depending on the action clicked
void MainWindow::actionClicked(bool)
{
    if (sender() == ui->actionArrow) {
        ui->stackedWidgetForms->setCurrentIndex(m_listIndexes[BUTTON_ID_ARROW]);
    } else if (sender() == ui->actionChart) {
        ui->stackedWidgetForms->setCurrentIndex(m_listIndexes[BUTTON_ID_CHART]);
    } else if (sender() == ui->actionClipart) {
        ui->stackedWidgetForms->setCurrentIndex(m_listIndexes[BUTTON_ID_CLIPART]);
    } else if (sender() == ui->actionLayers) {
        ui->stackedWidgetForms->setCurrentIndex(m_listIndexes[BUTTON_ID_LAYERS]);
    } else if (sender() == ui->actionNumberedBullets) {
        ui->stackedWidgetForms->setCurrentIndex(m_listIndexes[BUTTON_ID_BULLET]);
    } else if (sender() == ui->actionPicture) {
        ui->stackedWidgetForms->setCurrentIndex(m_listIndexes[BUTTON_ID_PICTURE]);
    } else if (sender() == ui->actionExports) {
        //stacked_widget.setCurrentIndex(m_listIndexes[BUTTON_ID_PICTURE]);
    } else if (sender() == ui->actionScreenshot) {
        ui->stackedWidgetForms->setCurrentIndex(m_listIndexes[BUTTON_ID_SCREENSHOT]);
    } else if (sender() == ui->actionTextBox) {
       ui->stackedWidgetForms->setCurrentIndex(m_listIndexes[BUTTON_ID_TEXTBOX]);
    }
}

void MainWindow::resizeTold(bool)
{
    ResizeSceneDialog scenedialog(this,&m_scene);
    scenedialog.exec();
}

void MainWindow::slotNew(bool)
{
    ResizeSceneDialog scenedialog(this,&m_scene);
    scenedialog.exec();
    foreach(QGraphicsItem *item,m_scene.items())
    {
        m_scene.removeItem(item);
    }
}

void MainWindow::slotNumberedBullets()
{
  //checker le new ok
  qDebug() << "\tdans slot NumberedBullets\n" ;
  int from (0), to (0), taille (0);
  int shape (0);
  QColor buttoncolor, numbercolor;
  QFont qfont;
  m_formBullets.get_info(from, to, taille,  shape, buttoncolor, numbercolor, qfont);

  NumberedBulletGraphicItem * numberedBulletGraphicItem (NULL);
  qDebug () << "\tfrom == " << from << "\n";
  qDebug () << "\tto == " << to << "\n";
  numberedBulletGraphicItem = new NumberedBulletGraphicItem (from, to, (NumberedBulletGraphicItem::shape_e)shape, buttoncolor, numbercolor, qfont);
  m_scene.addItem(numberedBulletGraphicItem);
}

void MainWindow::slotTextBoxes()
{
    // Retrieve information from the textboxform
    QString text = m_formTextboxes.getText();

    if (!text.isEmpty())
        m_scene.addItem(new TextBoxItem(text));
}

void MainWindow::slotTextPicture()
{
    PicturesGraphicsItem  * PictureItem = new PicturesGraphicsItem (&m_formPictures);
    m_scene.addItem(PictureItem);
}

///
/// \brief slotGraphs
/// This slot is called on graphs
void MainWindow::slotGraphs()
{
    //m_scene.addItem(new GraphsGraphicsItem());
    //m_scene.addItem(new GraphsGraphicsItem());

    //GraphsGraphicsItem *g = new GraphsGraphicsItem();

    createChart(true);
}


void MainWindow::slotArrowsGraphicsItem()
{
    // 3 Methods
    // Without anchor point:
    //          we need 2 points on the scene
    // 1 anchor point:
    //          we need 1 point on the scene and an object of scene
    //          or an object of scene and 1 point on the scene
    // 2 anchors points:
    //          we need 2 objects of scene
    //m_scene.addItem(new ArrowsGraphicsItem());

    ArrowsGraphicsItem  * ArrowItem = new ArrowsGraphicsItem();
    m_scene.addItem(ArrowItem);



    //ArrowsGraphicsItem::paint(arrowPainter,arrowQStyleOption,arrowWidget);



}


///
/// \brief exportView
/// This slot is called on export
void MainWindow::exportView(bool)
{
    // To do
}


///
/// \brief openFile
/// This slot is called on file open
void MainWindow::openFile(bool)
{
    // To do
}


///
/// \brief save
/// This slot is called on save
///
void MainWindow::save(bool)
{
    Save save(this->m_scene.items());
}


///
/// \brief MainWindow::saveAs
///
void MainWindow::saveAs(bool)
{
    QString fileName=QFileDialog::getSaveFileName(this,tr("Save File"),"project.ini",tr("Init File (*.ini)"));
    if(fileName!=""){
        QString extfilename=Save::verifyExtension(fileName);
        QFile fileToSave(extfilename);
        if(fileName!=extfilename && fileToSave.exists()){
            DialogFileAlreadyExists dfae;
            dfae.exec();
        }else{
            ui->actionSave->setEnabled(true);
            Save save(this->m_scene.items(),extfilename);
        }
    }
}



void MainWindow::createChart(bool)
{
//![1]
    QLineSeries *series0 = new QLineSeries();
    QLineSeries *series1 = new QLineSeries();
//![1]

//![2]
    *series0 << QPointF(-1000, 500) << QPointF(-300, 700) << QPointF(700, 600);
             //<< QPointF(90, 70) << QPointF(120, 600)
             //<< QPointF(160, 70) << QPointF(180, 50);
    *series1 << QPointF(-100, 300) << QPointF(-300, 400) << QPointF(700, 300);
             //<< QPointF(80, 200) << QPointF(120, 300)
             //<< QPointF(160, 4) << QPointF(180, 300);
//![2]

//![3]
    QAreaSeries *series = new QAreaSeries(series0, series1);
    series->setName("Batman");
    QPen pen(0x059605);
    pen.setWidth(3);
    series->setPen(pen);

    QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1000));
    gradient.setColorAt(0.0, 0x3cc63c);
    gradient.setColorAt(1.0, 0x26f626);
    gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
    series->setBrush(gradient);
//![3]

//![4]
    QChart*chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Simple areachart example");
    chart->createDefaultAxes();
    chart->axisX()->setRange(-200, 800);
    chart->axisY()->setRange(-200, 800);
//4

//    QChartView *qv = new  QChartView();
//    qv->setChart( chart);

    m_scene.addItem(chart);

}
