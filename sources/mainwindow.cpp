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
#include <QtWidgets>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QAreaSeries>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Classes/save.h"
#include "Forms/resizescenedialog.h"
#include "Forms/dialogfilealreadyexists.h"
#include "Forms/dialogsave.h"
#include "Items/picturesgraphicsitem.h"
#include "Items/numberedbulletgraphicitem.h"
#include "Items/textboxitem.h"
#include "Items/graphsgraphicsitem.h"
#include "Items/arrowsgraphicsitem.h"
#include "Items/screenshotsgraphicsitem.h"

QT_CHARTS_USE_NAMESPACE

// Constructor, destructor
// -----------------------

MainWindow::MainWindow(QWidget *parent)
    :   QMainWindow(parent), ui(new Ui::MainWindow)
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
    buildStackedWidget();
    buildView();
    m_width=800;
    m_height=800;
}


void MainWindow::buildMenu()
{
    // Connects
    connect(ui->actionSave,             SIGNAL( triggered(bool) ),  this,   SLOT( save(bool) ));
    connect(ui->actionSaveAs,           SIGNAL( triggered(bool) ),  this,   SLOT( saveAs(bool) ));
    connect(ui->actionOpen,             SIGNAL( triggered(bool) ),  this,   SLOT( openFile(bool) ));
    connect(ui->actionExportAs,         SIGNAL( triggered(bool) ),  this,   SLOT( exportView(bool) ));
    connect(ui->actionNew,              SIGNAL( triggered(bool) ),  this,   SLOT( slotNew(bool) ));
    connect(ui->actionSetBackgroundColor, SIGNAL( triggered(bool) ),  ui->graphicsView,   SLOT( changeBackgroundColor(bool)));

    connect(ui->actionArrow,            SIGNAL( triggered(bool) ),  this,   SLOT( actionClicked(bool) ));
    connect(ui->actionChart,            SIGNAL( triggered(bool) ),  this,   SLOT( actionClicked(bool) ));
    connect(ui->actionClipart,          SIGNAL( triggered(bool) ),  this,   SLOT( actionClicked(bool) ));
    connect(ui->actionNumberedBullets,  SIGNAL( triggered(bool) ),  this,   SLOT( actionClicked(bool) ));
    connect(ui->actionPicture,          SIGNAL( triggered(bool) ),  this,   SLOT( actionClicked(bool) ));
    connect(ui->actionScreenshot,       SIGNAL( triggered(bool) ),  this,   SLOT( actionClicked(bool) ));
    connect(ui->actionTextBox,          SIGNAL( triggered(bool) ),  this,   SLOT( actionClicked(bool) ));
    connect(ui->actionLayers,           SIGNAL( triggered(bool) ),  this,   SLOT( actionClicked(bool) ));
    connect(ui->actionAbout,            SIGNAL( triggered(bool) ),  this,   SLOT( showAboutDialog(bool) ));

    connect(ui->actionResize,           SIGNAL( triggered(bool) ),  this,               SLOT( resizeTold(bool) ));
    connect(ui->actionContentToView,    SIGNAL( triggered(bool) ),  ui->graphicsView,   SLOT( contentToView() ));
    connect(ui->actionClear,            SIGNAL( triggered(bool) ),  ui->graphicsView,   SLOT( clear() ));

    ui->actionSave->setDisabled(true);

    // Item insertion connects
    connect(&m_formPictures, SIGNAL(picture_changed()) , this, SLOT(slotTextPicture()));
    connect(m_formBullets.getGoPushButton(),SIGNAL(clicked(bool)), SLOT(slotNumberedBullets()));
    connect(m_formTextboxes.getAddButton(), SIGNAL(clicked(bool)), this, SLOT(slotTextBoxes(bool)));
    connect(ui->actionChart, SIGNAL(triggered(bool)), this, SLOT(slotGraphs()));
    connect(ui->actionArrow, SIGNAL(triggered(bool)),this,SLOT(slotArrowsGraphicsItem()));
    connect(&m_formCharts, SIGNAL(FormCreateChart( const GraphsInfo&)), this, SLOT(slotGraphs( const GraphsInfo&)));
    connect(&m_formScreenshots, SIGNAL(InsertImageText(QString)), this, SLOT(slotScreenShot()));

    // Layers
    connect(ui->actionLayers, SIGNAL(triggered(bool)), this, SLOT(slotLayers()));

}

void MainWindow::buildToolBar()
{
    // Left side built from the designer

    // Inserting a spacer widget
    QWidget* spacer = new QWidget();
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->toolBar->addWidget(spacer);

    // Zoom
    m_spinBoxZoom = new QSpinBox(this);
    m_spinBoxZoom->setMinimum(10);
    m_spinBoxZoom->setMaximum(400);
    m_spinBoxZoom->setValue(100);
    m_spinBoxZoom->setSingleStep(10);
    m_spinBoxZoom->setSuffix("%");
    m_spinBoxZoom->setAlignment(Qt::AlignHCenter);
    m_spinBoxZoom->setToolTip(tr("Zoom level"));
    //m_spinBoxZoom->setButtonSymbols(QAbstractSpinBox::NoButtons);
    connect(m_spinBoxZoom, SIGNAL(valueChanged(int)), ui->graphicsView, SLOT(setZoomLevel(int)));

    ui->toolBar->addWidget(m_spinBoxZoom);
}

void MainWindow::buildStackedWidget()
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

    connect(ui->graphicsView, SIGNAL(itemSelected(QGraphicsItem*)), this, SLOT(itemSelected(QGraphicsItem*)));
}

// Slots
// -----

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
    } else if (sender() == ui->actionScreenshot) {
        ui->stackedWidgetForms->setCurrentIndex(m_listIndexes[BUTTON_ID_SCREENSHOT]);
    } else if (sender() == ui->actionTextBox) {
       ui->stackedWidgetForms->setCurrentIndex(m_listIndexes[BUTTON_ID_TEXTBOX]);
    }
}

void MainWindow::resizeTold(bool)
{
    ResizeSceneDialog scenedialog(this,&m_scene,&m_width,&m_height);
    scenedialog.exec();
}

void MainWindow::slotNew(bool)
{
    DialogSave dialogSave(this,m_scene.items());
    dialogSave.exec();
    ResizeSceneDialog scenedialog(this,&m_scene,&m_width,&m_height);
    scenedialog.exec();
    foreach(QGraphicsItem *item, m_scene.items())
    {
        m_scene.removeItem(item);
    }
}

///
/// \brief MainWindow::slotNumberedBullets
///creates bullets items from...to
void MainWindow::slotNumberedBullets()
{
  //checker le new ok
  qDebug() << "\tdans slot NumberedBullets\n" ;
  int from (0), to (0), taille (0);
  int shape (0);
  QColor bulletcolor, numbercolor;
  QFont qfont;
  m_formBullets.get_info(from, to, taille,  shape, bulletcolor, numbercolor, qfont);
  NumberedBulletGraphicItem * numberedBulletGraphicItem (NULL);
  qDebug () << "\tfrom == " << from << "\n";
  qDebug () << "\tto == " << to << "\n";
  int numbullet (from);
  QPointF scene_topleft (m_scene.sceneRect().topLeft());
  QPointF scene_topright (m_scene.sceneRect().topRight());
  QPointF bulletpos (scene_topleft);
  qreal delta (0);
  delta = scene_topright.y() - scene_topleft.y();
  bulletpos.setY(scene_topleft.y () + delta /5);
  //qreal posx (0), posy (50), delta (100);
  for (; numbullet != to+1; ++numbullet) {
    numberedBulletGraphicItem = new NumberedBulletGraphicItem (numbullet, (NumberedBulletGraphicItem::shape_e)shape, bulletcolor, numbercolor, qfont, taille);
    //numberedBulletGraphicItem->setPos(posx, posy);
    numberedBulletGraphicItem->setPos (bulletpos);
    m_scene.addItem(numberedBulletGraphicItem);
    delta = numberedBulletGraphicItem->rect ().width ();
    if (bulletpos.x () + delta < scene_topright.x ()) {
      bulletpos.setX(bulletpos.x() + delta);
    }
  }
}

void MainWindow::slotTextBoxes(bool)
{
    // Retrieve data from the form
    QMap<QString, QVariant> data = m_formTextboxes.getInfos();
    m_scene.addItem(new TextBoxItem(data));
}

void MainWindow::slotTextPicture()
{
    PicturesGraphicsItem  * PictureItem = new PicturesGraphicsItem (&m_formPictures);
    m_scene.clear();
    m_scene.addItem(PictureItem);
}


void MainWindow::slotGraphs(const GraphsInfo &infos)
{
    qDebug () << "mainWindow Slot Graphs";

    //m_scene.addItem(new GraphsGraphicsItem());
    //m_scene.addItem(new GraphsGraphicsItem());

//    GraphsInfo infos;
//    m_formCharts.GetChartsValues( infos);

//    GraphsGraphicsItem *g = new GraphsGraphicsItem();
//    g->setInfos(infos);
//    m_scene.addItem(g);

    GraphsGraphicsItem *g = new GraphsGraphicsItem();
    g->setInfos(infos);

    m_scene.addItem(g);
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

    // Define new ArrowsGraphicsItem on the scene
    ArrowsGraphicsItem  * ArrowItem = new ArrowsGraphicsItem(&m_formArrows);
    m_scene.addItem(ArrowItem);

}

void MainWindow::slotScreenShot()
{
     //Get screen capture

    qDebug () << "mainWindow slot of the Screenshot";

    //ScreenshotsGraphicsItem  *sc = new ScreenshotsGraphicsItem (&m_formScreenshots);
    //m_scene.clear();
    //m_scene.addItem(sc);

}

void MainWindow::slotLayers()
{
//    qDebug() << "MainWindow::slotLayers()" ;

    m_formLayers.setScene(m_scene);
}
void MainWindow::itemSelected(QGraphicsItem* item)
{
    // An item have been selected
    // Three steps from now
    // 1. Check type
    // 2. Load associated form
    // 3. Fill the form

    // Really dirty, would like to make it cleaner in the future

    switch (item->type())
    {
        case BaseGraphicItem::Type::TextBoxGraphicsItem:
        {
            //TextBoxItem* textItem = qgraphicsitem_cast<TextBoxItem*>(item);
            //ui->stackedWidgetForms->setCurrentIndex(m_listIndexes[BUTTON_ID_TEXTBOX]);

            // Load item info into the form

        } break;
        case BaseGraphicItem::Type::ArrowGraphicsItem:
        {

        } break;

    }
}

void MainWindow::exportView(bool)
{
    QString fileName=QFileDialog::getSaveFileName(this,tr("Export Image"),"project.png",tr("Image File (*.png)"));
    if(fileName!=""){
        QString extfilename=Save::verifyExtension(fileName,"png");
        QFile fileToSave(extfilename);
        if(fileName!=extfilename && fileToSave.exists()){
            DialogFileAlreadyExists dfae;
            dfae.exec();
        }else{
            QImage image(m_scene.sceneRect().size().toSize(), QImage::Format_ARGB32);  // Create the image with the exact size of the shrunk scene
            image.fill(Qt::white);                                              // Start all pixels transparent

            QPainter painter(&image);
            m_scene.render(&painter);
            image.save(extfilename);
        }
    }
}


void MainWindow::openFile(bool)
{
    QString fileName = QFileDialog::getOpenFileName(this,
          tr("Open ClipEdit Project"), "/home", tr("ClipEdit Files (*.cle)"));
    if(fileName!=""){
        Save save(&m_scene,fileName);
        //save.setFormsPoints(&m_formArrows,&m_formCharts,&m_formCliparts,&m_formLayers,&m_formBullets,&m_formPictures,&m_formScreenshots,&m_formTextboxes);
        //save.open();
    }
}


void MainWindow::save(bool)
{
    Save save(this->m_scene.items());
    //save.save();
}


void MainWindow::saveAs(bool)
{
    QString fileName=QFileDialog::getSaveFileName(this,tr("Save File"),"project.cle",tr("ClipEdit File (*.cle)"));
    if(fileName!=""){
        QString extfilename=Save::verifyExtension(fileName,"cle");
        QFile fileToSave(extfilename);
        if(fileName!=extfilename && fileToSave.exists()){
            DialogFileAlreadyExists dfae;
            dfae.exec();
        }else{
            ui->actionSave->setEnabled(true);
            Save save(this->m_scene.items(),extfilename);
            //save.save();
        }
    }
}

void MainWindow::showAboutDialog(bool)
{
    QString content =   "<b>" + QApplication::applicationName() + " " + QApplication::applicationVersion() + "</b><br><br>"
                        "" + tr("A simple document editor") + "<br>"
                        "" + tr("Developed by the M2I Team") + "<br>"
                        "Copyright (c) 2018";
    QMessageBox::about(this, tr("About ") + QApplication::applicationName(), content);
}
