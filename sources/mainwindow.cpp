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
#include <QApplication>
#include <QDesktopWidget>

#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Classes/save.h"
#include "Forms/resizescenedialog.h"
#include "Forms/dialogsave.h"
#include "Forms/formscreenshots.h"
#include "dialogpreferences.h"
#include "Items/picturesgraphicsitem.h"
#include "Items/numberedbulletgraphicitem.h"
#include "Items/textboxitem.h"
#include "Items/graphsgraphicsitem.h"
#include "Items/arrowsgraphicsitem.h"
#include "Items/screenshotsgraphicsitem.h"

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
    buildForms();
    buildToolBar();
    buildView();
    applyPreferences();
}


void MainWindow::buildMenu()
{
    // Connects
    connect(ui->actionSave,             SIGNAL( triggered(bool) ),  this,   SLOT( save(bool) ));
    connect(ui->actionSaveAs,           SIGNAL( triggered(bool) ),  this,   SLOT( saveAs(bool) ));
    connect(ui->actionOpen,             SIGNAL( triggered(bool) ),  this,   SLOT( openFile(bool) ));
    connect(ui->actionExportAs,         SIGNAL( triggered(bool) ),  this,   SLOT( exportView(bool) ));
    connect(ui->actionNew,              SIGNAL( triggered(bool) ),  this,   SLOT( slotNew(bool) ));
    connect(ui->actionPreferences,      SIGNAL( triggered(bool) ),  this,   SLOT( showPreferences()));
    connect(ui->actionQuit,             SIGNAL( triggered(bool) ),  this,   SLOT( close() ));

    connect(ui->actionArrow,            SIGNAL( triggered(bool) ),  this,   SLOT( actionClicked(bool) ));
    connect(ui->actionChart,            SIGNAL( triggered(bool) ),  this,   SLOT( actionClicked(bool) ));
    connect(ui->actionClipart,          SIGNAL( triggered(bool) ),  this,   SLOT( actionClicked(bool) ));
    connect(ui->actionNumberedBullets,  SIGNAL( triggered(bool) ),  this,   SLOT( actionClicked(bool) ));
    connect(ui->actionPicture,          SIGNAL( triggered(bool) ),  this,   SLOT( actionClicked(bool) ));
    connect(ui->actionScreenshot,       SIGNAL( triggered(bool) ),  this,   SLOT( actionClicked(bool) ));
    connect(ui->actionTextBox,          SIGNAL( triggered(bool) ),  this,   SLOT( actionClicked(bool) ));
    connect(ui->actionLayers,           SIGNAL( triggered(bool) ),  this,   SLOT( actionClicked(bool) ));
    connect(ui->actionAbout,            SIGNAL( triggered(bool) ),  this,   SLOT( showAboutDialog(bool) ));

    connect(ui->actionResize,           SIGNAL( triggered(bool) ),  this,               SLOT( resizeScene() ));
    connect(ui->actionContentToView,    SIGNAL( triggered(bool) ),  ui->graphicsView,   SLOT( contentToView() ));
    connect(ui->actionClear,            SIGNAL( triggered(bool) ),  ui->graphicsView,   SLOT( clear() ));
    connect(ui->actionSetBackgroundColor, SIGNAL( triggered(bool) ),  ui->graphicsView,   SLOT( changeBackgroundColor()));

    ui->actionSave->setDisabled(true);
}

void MainWindow::buildForms()
{
    m_formArrows = new FormArrows();
    m_formCharts = new FormCharts();
    m_formCliparts = new FormCliparts();
    m_formLayers = new FormLayers();
    m_formBullets = new FormNumberedBullets();
    m_formPictures = new FormPictures();
    m_formScreenshots = new FormScreenshots();
    m_formTextboxes = new FormTextBoxes();

    m_formLayers->setScene(m_scene);

    // Item connects
    connect(m_formArrows->getAddPushButtonArrow(),SIGNAL(clicked(bool)),this,SLOT(slotArrowsGraphicsItem()));
    connect(m_formPictures, SIGNAL(picture_changed()) , this, SLOT(slotTextPicture()));
    connect(m_formBullets->getGoPushButton(),SIGNAL(clicked(bool)), SLOT(slotNumberedBullets()));
    connect(m_formTextboxes->getAddButton(), SIGNAL(clicked(bool)), this, SLOT(slotTextBoxes()));
    connect(ui->actionChart, SIGNAL(triggered(bool)), this, SLOT(slotGraphs()));
    connect( m_formCharts, SIGNAL(FormCreateChart() ), this, SLOT(slotGraphs()));
    //connect(m_formCharts, SIGNAL(FormCreateChart( const GraphsInfo&)), this, SLOT(slotGraphs( const GraphsInfo&)));
    connect(ui->actionArrow, SIGNAL(triggered(bool)),this,SLOT(slotArrowsGraphicsItem()));
    connect(m_formScreenshots, SIGNAL(setBackground(QPixmap)), this, SLOT(setBackground(QPixmap)));
    connect(ui->actionLayers, SIGNAL(triggered(bool)), this, SLOT(slotLayers()));

    // Building the stacked widget
    // First, remove all useless pages
    for(int page = 0; page < ui->stackedWidgetForms->count(); ++page)
    {
        QWidget* widget = ui->stackedWidgetForms->widget(page);
        ui->stackedWidgetForms->removeWidget(widget);
        widget->deleteLater();
    }

    // Add forms and store the indexes
    m_listIndexes.insert(BUTTON_ID_ARROW, ui->stackedWidgetForms->addWidget(m_formArrows));
    m_listIndexes.insert(BUTTON_ID_CHART, ui->stackedWidgetForms->addWidget(m_formCharts));
    m_listIndexes.insert(BUTTON_ID_BULLET, ui->stackedWidgetForms->addWidget(m_formBullets));
    m_listIndexes.insert(BUTTON_ID_CLIPART, ui->stackedWidgetForms->addWidget(m_formCliparts));
    m_listIndexes.insert(BUTTON_ID_PICTURE, ui->stackedWidgetForms->addWidget(m_formPictures));
    m_listIndexes.insert(BUTTON_ID_TEXTBOX, ui->stackedWidgetForms->addWidget(m_formTextboxes));
    m_listIndexes.insert(BUTTON_ID_SCREENSHOT, ui->stackedWidgetForms->addWidget(m_formScreenshots));
    m_listIndexes.insert(BUTTON_ID_LAYERS, ui->stackedWidgetForms->addWidget(m_formLayers));

    // items <-> forms association
    m_itemForms.insert(BaseGraphicItem::CustomTypes::ArrowGraphicsItem, m_formArrows);
    m_itemForms.insert(BaseGraphicItem::CustomTypes::ChartGraphicsItem, m_formCharts);
    m_itemForms.insert(BaseGraphicItem::CustomTypes::NumberedBulletGraphicsItem, m_formBullets);
    m_itemForms.insert(BaseGraphicItem::CustomTypes::ClipartGraphicsItem, m_formCliparts);
    m_itemForms.insert(BaseGraphicItem::CustomTypes::PictureGraphicsItem, m_formPictures);
    m_itemForms.insert(BaseGraphicItem::CustomTypes::TextBoxGraphicsItem, m_formTextboxes);
    m_itemForms.insert(BaseGraphicItem::CustomTypes::ScreenshotGraphicsItem, m_formScreenshots);

    ui->stackedWidgetForms->setCurrentIndex(0);
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
    connect(m_spinBoxZoom, SIGNAL(valueChanged(int)), ui->graphicsView, SLOT(setZoomLevel(int)));

    ui->toolBar->addWidget(m_spinBoxZoom);
}

void MainWindow::buildView()
{
    QDesktopWidget *deskWidget=QApplication::desktop();
    int dpix=deskWidget->logicalDpiX();
    int dpiy=deskWidget->logicalDpiY();
    int width=210*dpix/25.4;
    int height=297*dpiy/25.4;
    QString format="None";
    QSettings s;
    int l_width,l_height;
    QString l_format;
    l_width=-1;
    l_height=-1;
    l_format="";
    l_width=s.value("sceneWidth",l_width).toInt();
    l_height=s.value("sceneHeight",l_height).toInt();
    l_format=s.value("sceneFormat",l_format).toString();
    QColor color=s.value("backgroundColor").value<QColor>();
    if(!color.isValid()){
        color=Qt::white;
    }
    if(l_width!=-1){
        width=l_width;
    }
    if(l_height!=-1){
        height=l_height;
    }
    if(l_format!=""){
        format=l_format;
    }
    m_scene.setSceneRect(QRectF(-(width+1)/2, -(height+1)/2, width+1, height+1));
    m_borderSceneItem=m_scene.addRect(QRectF(-width/2, -height/2, width, height));
    m_borderSceneItem->setBrush(QBrush(color));

    ui->graphicsView->setGraphicsRectItem(&m_borderSceneItem);
    ui->graphicsView->setNbElts(m_scene.items().count());
    ui->graphicsView->setScene(&m_scene);
    ui->graphicsView->viewport()->installEventFilter(this);

    connect(&m_scene, SIGNAL(selectionChanged()), this, SLOT(itemSelected()));
    m_resized=false;
}


// Events
// ------

bool MainWindow::eventFilter(QObject* watched, QEvent* event)
{
    if (watched == ui->graphicsView->viewport() && event->type() == QEvent::Wheel)
    {
        QWheelEvent* e = static_cast<QWheelEvent*>(event);

        if (!e)
            return false;

        if (e->modifiers() == Qt::ControlModifier)
        {
            QPoint delta = e->angleDelta();
            int degrees = delta.y() / 8;
            int steps = degrees / 15;

            m_spinBoxZoom->setValue(m_spinBoxZoom->value() + (steps*m_spinBoxZoom->singleStep()));

            return true;
        }
    }

    return QMainWindow::eventFilter(watched, event);
}

void MainWindow::changeEvent(QEvent* event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);

        foreach (BaseForm* bf, m_itemForms)
        {
            bf->retranslate();
        }
    }
    else
    {
        QMainWindow::changeEvent(event);
    }
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

void MainWindow::resizeScene()
{
    ResizeSceneDialog scenedialog(&m_scene, &m_borderSceneItem, ui->graphicsView->m_backgroundColor, false,&m_resized, this);
    scenedialog.exec();
}

void MainWindow::slotNew(bool)
{
    if (m_scene.items().count() > 1)
    {
        DialogSave dialogSave(m_scene.items(),m_scene.sceneRect(),m_borderSceneItem,this);
        dialogSave.exec();
    }

    ResizeSceneDialog scenedialog(&m_scene, &m_borderSceneItem, ui->graphicsView->m_backgroundColor, true, &m_resized,this);
    scenedialog.exec();
    QRectF rectf = m_borderSceneItem->rect();
    QBrush brush = m_borderSceneItem->brush();
    m_scene.clear();
    m_borderSceneItem = m_scene.addRect(rectf);
    m_borderSceneItem->setBrush(brush);
}

///
/// \brief MainWindow::slotNumberedBullets
///creates bullets items from...to
void MainWindow::slotNumberedBullets()
{
  int from (0), to (0), taille (0);
  int shape (0);
  QColor bulletcolor, numbercolor;
  QFont qfont;
  m_formBullets->get_info(from, to, taille,  shape, bulletcolor, numbercolor, qfont);
  NumberedBulletGraphicItem* numberedBulletGraphicItem (NULL);

  if (to < from) {
      qDebug () << "invalid interval\n";
      return;
  }

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

void MainWindow::slotTextBoxes()
{
    // Retrieve data from the form
    QVariant data = m_formTextboxes->getItemData();
    TextBoxItem* item = new TextBoxItem();
    item->setItemData(data);
    m_scene.addItem(item);
}

void MainWindow::slotTextPicture()
{
    PicturesGraphicsItem* PictureItem = new PicturesGraphicsItem (m_formPictures);
    m_scene.addItem(PictureItem);
}


// removed parametre
void MainWindow::slotGraphs( )
{
    GraphsInfo infos;
    // Retrieve data from the form
    m_formCharts->GetChartsValues(infos);
    int nbPoints = infos.m_Arcs.size();
    if( nbPoints > 0 )
    {
        qDebug() << "added graph mainWindow Slot Graphs";

        GraphsGraphicsItem *g = new GraphsGraphicsItem();
        g->setInfos(infos);
        m_scene.addItem(g);
     }
}


///
/// \brief MainWindow::slotArrowsGraphicsItem
///creates arrows items
/// 3 Methods
/// Without anchor point:
///          we need 2 points on the scene
/// 1 anchor point:
///          we need 1 point on the scene and an object of scene
///          or an object of scene and 1 point on the scene
/// 2 anchors points:
///          we need 2 objects of scene
///
/// Actual version work only without anchor point
///
void MainWindow::slotArrowsGraphicsItem()
{

    // Control of the size of scene vs size of the arrows
    bool WithoutAnchorPoint(true), OneAnchorPoint(false), TwoAnchorPoints(false);
    int ArrowWidth(0), ArrowHeight(0);
    QColor ArrowOutlineColor, ArrowFillColor;
    int LineThickness(0), SizeHeadTypeChoice(0);

    m_formArrows->GetInfosArrows(WithoutAnchorPoint, OneAnchorPoint, TwoAnchorPoints,
                                 ArrowWidth, ArrowHeight,
                                 ArrowOutlineColor, ArrowFillColor,
                                 LineThickness, SizeHeadTypeChoice);
                                //To do others HeadTypeChoiceContents
                                // comboBoxHeadTypeChoiceContents

    qDebug() << "LineThickness =" << LineThickness;


    // Define new ArrowsGraphicsItem on the scene
    ArrowsGraphicsItem  * ArrowItem = new ArrowsGraphicsItem(m_formArrows);

    QPointF scene_TopLeft (m_scene.sceneRect().topLeft());
    QPointF scene_BottomRight (m_scene.sceneRect().bottomRight());


    //    BaseGraphicItem *m_StartItem;
    //    BaseGraphicItem *m_EndItem;

    QPointF *arrow_StartPositionItem = new QPointF();
    *arrow_StartPositionItem = ArrowItem->getStartPosition();
    qDebug() << "arrow_StartPositionItem"
             << "x = " << arrow_StartPositionItem->x()
             << "y = " << arrow_StartPositionItem->y();

    QPointF *arrow_EndPositionItem = new QPointF();
    *arrow_EndPositionItem = ArrowItem->getEndPosition();
    qDebug() << "arrow_EndPositionItem"
             << "x = " << arrow_EndPositionItem->x()
             << "y = " << arrow_EndPositionItem->y();

    qreal Min_Xpos(0), Max_Xpos (0), Min_Ypos(0), Max_Ypos (0);
    /// TopLeft
    ///                         -Y
    ///     The scene limits     |   The scene limits
    ///       for the arrows     |    for the arrows
    ///        1/4 = X, -Y       |      2/4 = X, -Y
    ///                          |
    /// -X ----------------------0----------------------> X
    ///                          |
    ///     The scene limits     |   The scene limits
    ///      for the arrows      |    for the arrows
    ///        3/4 = -X, Y       |      4/4 = X, Y
    ///                          V
    ///                          Y
    ///                                          BottomRight

    // To Test the Max Width and the Max Height for the scene
    Max_Ypos = scene_BottomRight.y() - scene_TopLeft.y();
    //qDebug()<< "Max_Ypos =" << Max_Ypos;
    Max_Xpos = scene_BottomRight.x() - scene_TopLeft.x();
    //qDebug()<< "Max_Xpos =" << Max_Xpos;

    // Work on progress
     if (ArrowWidth > Max_Xpos)
          ArrowWidth = Max_Xpos;

     if (ArrowHeight > Max_Ypos)
          ArrowHeight = Max_Ypos;

    Min_Ypos = scene_TopLeft.y();
    qDebug()<< "Min_Ypos =" << Min_Ypos;
    Min_Xpos = scene_TopLeft.x();
    qDebug()<< "Min_Xpos =" << Min_Xpos;

/*  // Work on progress
    //    To do debug
   //     /home/formation/ClipEdit/sources/mainwindow.cpp:459: erreur : invalid type argument of unary ‘*’ (have ‘qreal {aka double}’)
   //  if (*arrow_StartPositionItem->y() < Min_Ypos)
   //                                 ^
   ///home/formation/ClipEdit/sources/mainwindow.cpp:460: erreur : void value not ignored as it ought to be
   //      *arrow_StartPositionItem->setY(Min_Ypos);
   //       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~
   //

    // Check the Arrows on the scene and fix it
    if (*arrow_StartPositionItem->y() < Min_Ypos)
        *arrow_StartPositionItem->setY(Min_Ypos);
    if (*arrow_StartPositionItem->x() < Min_Xpos)
        *arrow_StartPositionItem->setX(Min_Xpos);
    if (*arrow_EndPositionItem->y() < Min_Ypos)
        *arrow_EndPositionItem->setY(Min_Ypos);
    if (*arrow_EndPositionItem->x() < Min_Xpos)
        *arrow_EndPositionItem->setX(Min_Xpos);
*/
    // Add Arrow on the scene
    //m_scene.addItem(new ArrowsGraphicsItem());
    m_scene.addItem(ArrowItem);

/*  // Work on progress
    delta = numberedBulletGraphicItem->rect ().width ();
    if (bulletpos.x () + delta < scene_topright.x ()) {
      bulletpos.setX(bulletpos.x() + delta);
    }

*/
}


void MainWindow::setBackground(const QPixmap& pix)
{
     //Get screen background.
    qDebug () << "msg from the mainWindow slot of the Screenshot";

    ScreenshotsGraphicsItem  *sc = new ScreenshotsGraphicsItem (pix);
    m_scene.addItem(sc);

    m_height=pix.height();
    m_width=pix.width();
    this->adjustSize();
}

void MainWindow::itemSelected()
{
    QList<QGraphicsItem*> items = m_scene.selectedItems();

    if (items.isEmpty())
        return;

    if (ui->stackedWidgetForms->currentIndex() != m_listIndexes[BUTTON_ID_LAYERS])
    {
        // Casting the first selected item
        QGraphicsItem* item = items[0];
        BaseGraphicItem* castedItem = dynamic_cast<BaseGraphicItem*>(item);

        if (!castedItem)
            return;

        // Retrieve the type
        BaseGraphicItem::CustomTypes itemType = (BaseGraphicItem::CustomTypes)item->type();

        if (m_itemForms.contains(itemType))
        {
            // Use it to switch lateral form and load data into it
            ui->stackedWidgetForms->setCurrentWidget(m_itemForms[itemType]);
            m_itemForms[itemType]->loadFromItem(castedItem);
        }
    }
    else
    {
        // For Layers, it must select the corresponding layer
        // TO DO: emit itemSelected ???
    }
}

// Layers
void MainWindow::slotLayers()
{
    m_formLayers->updateLayers();
}

void MainWindow::exportView(bool)
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Export as image"), "output.png" , tr("Image File (*.png)"));

    if (fileName.isEmpty())
        return;

    QString extfilename = Save::verifyExtension(fileName, "png");
    QFile fileToSave(extfilename);

    if (fileName != extfilename && fileToSave.exists())
    {
        QMessageBox::warning(this, tr("Warning"), tr("File %1 already exists").arg(fileToSave.fileName()));
    }
    else
    {
        m_scene.clearSelection();
        QSize size=m_scene.sceneRect().size().toSize();
        QImage image(size, QImage::Format_ARGB32);
        image.fill(Qt::white);

        QPainter painter(&image);
        QGraphicsItem *item=0;
        m_scene.setFocusItem(item);
        m_scene.render(&painter);
        image.save(extfilename);
    }
}


void MainWindow::openFile(bool)
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open ClipEdit Project"), QDir::homePath(), tr("ClipEdit Files (*.cle)"));

    if (!fileName.isEmpty())
    {
        Save save(&m_scene, fileName);
        m_borderSceneItem=save.open();
    }
}


void MainWindow::save(bool)
{
    Save save(this->m_scene.items(),m_borderSceneItem->rect(),m_scene.sceneRect(),m_borderSceneItem->brush().color(),m_resized);
    save.save();
}


void MainWindow::saveAs(bool)
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),"project.cle", tr("ClipEdit File (*.cle)"));

    if (!fileName.isEmpty())
    {
        QString extfilename=Save::verifyExtension(fileName, "cle");
        QFile fileToSave(extfilename);

        if (fileName != extfilename && fileToSave.exists())
        {
            QMessageBox::warning(this, tr("Warning"), tr("File %1 already exists").arg(fileToSave.fileName()));
        }
        else
        {
            ui->actionSave->setEnabled(true);
            Save save(this->m_scene.items(), extfilename,m_scene.sceneRect(),m_borderSceneItem->rect(),m_borderSceneItem->brush().color(),m_resized);
            save.save();
        }
    }
}

void MainWindow::showAboutDialog(bool)
{
    QString content =   "<b>" + QApplication::applicationName() + " " + QApplication::applicationVersion() + "</b><br><br>"
                        "" + tr("A simple document editor") + "<br>"
                        "" + tr("Developed by the M2I Team") + "<br>"
                        "" + tr("Copyright (c) 2018");
    QMessageBox::about(this, tr("About ") + QApplication::applicationName(), content);
}

void MainWindow::showPreferences()
{
    DialogPreferences d(this);
    connect(&d, SIGNAL(preferencesChanged()), this, SLOT(applyPreferences()));
    d.exec();
}

void MainWindow::applyPreferences()
{
    QSettings s;
    QString lang = s.value("Settings/lang", "en").toString();

    // Language
    qApp->removeTranslator(&m_translator);
    if(m_translator.load(QString(":/lang/lang/clipedit_%1").arg(lang)))
        qApp->installTranslator(&m_translator);
}
