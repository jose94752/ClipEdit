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

#include "Items/picturesgraphicsitem.h"
#include "Items/numberedbulletgraphicitem.h"
#include "Items/textboxitem.h"
#include "Items/graphsgraphicsitem.h"
#include "Items/arrowsgraphicsitem.h"
#include "Items/screenshotsgraphicsitem.h"
#include "Items/numberedbulletgraphicitem.h"

#include "Forms/resizescenedialog.h"
#include "Forms/dialogsave.h"
#include "Forms/baseformitem.h"
#include "Forms/formarrows.h"
#include "Forms/formcharts.h"
#include "Forms/formcliparts.h"
#include "Forms/formlayers.h"
#include "Forms/formnumberedbullets.h"
#include "Forms/formpictures.h"
#include "Forms/formscreenshots.h"
#include "Forms/formtextboxes.h"

#define INIT_BUTTON(BUTTON_ID, TEXT, PIXMAP) \
    list_buttons[BUTTON_ID]->set_text(TEXT); \
    list_buttons[BUTTON_ID]->set_pixmap(PIXMAP); \
    list_buttons[BUTTON_ID]->button_id = BUTTON_ID; \
    list_buttons[BUTTON_ID]->unselect(true); \
    \
    connect(list_buttons[BUTTON_ID], SIGNAL( on_click(unsigned char) ), this, SLOT( event_onClick(unsigned char) ));


#define INIT_SELECTED_BUTTON(BUTTON_ID, TEXT, PIXMAP) \
    list_buttons[BUTTON_ID]->set_text(TEXT); \
    list_buttons[BUTTON_ID]->set_pixmap(PIXMAP); \
    list_buttons[BUTTON_ID]->select(); \
    list_buttons[BUTTON_ID]->button_id = BUTTON_ID; \
    selected_button = BUTTON_ID; \
    \
    connect(list_buttons[BUTTON_ID], SIGNAL( on_click(unsigned char) ), this, SLOT( event_onClick(unsigned char) ));


// Constructor, destructor
// -----------------------

MainWindow::MainWindow(QWidget *parent)
    :   QMainWindow(parent), ui(new Ui::MainWindow)/*,
        form_arrows(canvas), form_charts(canvas),
        form_cliparts(canvas), form_layers(canvas),
        form_bullets(canvas), form_pictures(canvas),
        form_screenshots(canvas), form_textboxes(canvas)*/
{
    ui->setupUi(this);
    init();

    // Connects

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

    fillDynamicStrings();
    applyPreferences();
}


void MainWindow::buildMenu()
{
    // Connects
    connect(ui->actionSave,                 SIGNAL(triggered(bool)),    this,                 SLOT(save(bool)));
    connect(ui->actionSaveAs,               SIGNAL(triggered(bool)),    this,                 SLOT(saveAs(bool)));
    connect(ui->actionOpen,                 SIGNAL(triggered(bool)),    this,                 SLOT(openFile(bool)));
    connect(ui->actionExportAs,             SIGNAL(triggered(bool)),    this,                 SLOT(exportView(bool)));
    connect(ui->actionNew,                  SIGNAL(triggered(bool)),    this,                 SLOT(slotNew(bool)));
    connect(ui->actionPreferences,          SIGNAL(triggered(bool)),    this,                 SLOT(showPreferences()));
    connect(ui->actionQuit,                 SIGNAL(triggered(bool)),    this,                 SLOT(close()));

    connect(ui->actionArrow,                SIGNAL(triggered(bool)),    this,                 SLOT(actionClicked(bool)));
    connect(ui->actionChart,                SIGNAL(triggered(bool)),    this,                 SLOT(actionClicked(bool)));
    connect(ui->actionClipart,              SIGNAL(triggered(bool)),    this,                 SLOT(actionClicked(bool)));
    connect(ui->actionNumberedBullets,      SIGNAL(triggered(bool)),    this,                 SLOT(actionClicked(bool)));
    connect(ui->actionPicture,              SIGNAL(triggered(bool)),    this,                 SLOT(actionClicked(bool)));
    connect(ui->actionScreenshot,           SIGNAL(triggered(bool)),    this,                 SLOT(actionClicked(bool)));
    connect(ui->actionTextBox,              SIGNAL(triggered(bool)),    this,                 SLOT(actionClicked(bool)));
    connect(ui->actionLayers,               SIGNAL(triggered(bool)),    this,                 SLOT(actionClicked(bool)));
    connect(ui->actionAbout,                SIGNAL(triggered(bool)),    this,                 SLOT(showAboutDialog(bool)));

    connect(ui->actionResize,               SIGNAL(triggered(bool)),    this,                 SLOT(resizeScene()));
    connect(ui->actionContentToView,        SIGNAL(triggered(bool)),    ui->graphicsView,     SLOT(contentToView()));
    connect(ui->actionClear,                SIGNAL(triggered(bool)),    ui->graphicsView,     SLOT(clear()));
    connect(ui->actionSetBackgroundColor,   SIGNAL(triggered(bool)),    ui->graphicsView,     SLOT(changeBackgroundColor()));

    ui->actionSave->setDisabled(true);
}

void MainWindow::buildForms()
{
    FormArrows* formArrows = new FormArrows();
    FormCharts* formCharts = new FormCharts();
    FormCliparts* formCliparts = new FormCliparts();
    FormLayers* formLayers = new FormLayers();
    FormNumberedBullets* formBullets = new FormNumberedBullets();
    FormPictures* formPictures = new FormPictures();
    FormScreenshots* formScreenshots = new FormScreenshots();
    FormTextBoxes* formTextboxes = new FormTextBoxes();

    formLayers->setScene(m_scene);

    // Item connects

    connect(formArrows->getAddButton(),         SIGNAL(clicked(bool)),      this,   SLOT(slotArrows()));
    connect(formPictures->getAddButton(),       SIGNAL(clicked(bool)),      this,   SLOT(slotPictures()));
    connect(formBullets->getAddButton(),        SIGNAL(clicked(bool)),      this,   SLOT(slotNumberedBullets()));
    connect(formTextboxes->getAddButton(),      SIGNAL(clicked(bool)),      this,   SLOT(slotTextBoxes()));
    connect(formCharts->getAddButton(),         SIGNAL(clicked(bool)),      this,   SLOT(slotGraphs()));
    connect(formScreenshots->getAddButton(),    SIGNAL(clicked(bool)),      this,   SLOT(slotScreenshots()));

    connect(formScreenshots, SIGNAL(adjustWindowVisibility(bool)), this, SLOT(setVisible(bool)));
    connect(formScreenshots, SIGNAL(requestScreenshot(bool)), this, SLOT(takeScreenshot(bool)));
    connect(this, SIGNAL(screenshotTaken(QPixmap)), formScreenshots, SLOT(screenshotReceived(QPixmap)));
    connect(ui->actionLayers, SIGNAL(triggered(bool)), this, SLOT(slotLayers()));

    // Building the stacked widget
    // First, remove all useless pages
    for(int page = 0; page < ui->stackedWidgetForms->count(); ++page)
    {
        QWidget* widget = ui->stackedWidgetForms->widget(page);
        ui->stackedWidgetForms->removeWidget(widget);
        widget->deleteLater();
    }

    // Add forms to the stacked widget
    ui->stackedWidgetForms->addWidget(formArrows);
    ui->stackedWidgetForms->addWidget(formCharts);
    ui->stackedWidgetForms->addWidget(formBullets);
    ui->stackedWidgetForms->addWidget(formCliparts);
    ui->stackedWidgetForms->addWidget(formPictures);
    ui->stackedWidgetForms->addWidget(formTextboxes);
    ui->stackedWidgetForms->addWidget(formScreenshots);
    ui->stackedWidgetForms->addWidget(formLayers);

    // Store forms by button id
    m_forms.insert(BUTTON_ID_ARROW, formArrows);
    m_forms.insert(BUTTON_ID_CHART, formCharts);
    m_forms.insert(BUTTON_ID_BULLET, formBullets);
    m_forms.insert(BUTTON_ID_CLIPART, formCliparts);
    m_forms.insert(BUTTON_ID_PICTURE, formPictures);
    m_forms.insert(BUTTON_ID_TEXTBOX, formTextboxes);
    m_forms.insert(BUTTON_ID_SCREENSHOT, formScreenshots);
    m_forms.insert(BUTTON_ID_LAYERS, formLayers);

    // Bind item types to button id
    m_bounds.insert(BaseGraphicItem::CustomTypes::ArrowGraphicsItem, BUTTON_ID_ARROW);
    m_bounds.insert(BaseGraphicItem::CustomTypes::ChartGraphicsItem, BUTTON_ID_CHART);
    m_bounds.insert(BaseGraphicItem::CustomTypes::NumberedBulletGraphicsItem, BUTTON_ID_BULLET);
    m_bounds.insert(BaseGraphicItem::CustomTypes::ClipartGraphicsItem, BUTTON_ID_CLIPART);
    m_bounds.insert(BaseGraphicItem::CustomTypes::PictureGraphicsItem, BUTTON_ID_PICTURE);
    m_bounds.insert(BaseGraphicItem::CustomTypes::TextBoxGraphicsItem, BUTTON_ID_TEXTBOX);
    m_bounds.insert(BaseGraphicItem::CustomTypes::ScreenshotGraphicsItem, BUTTON_ID_SCREENSHOT);

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
    connect(m_spinBoxZoom, SIGNAL(valueChanged(int)), ui->graphicsView, SLOT(setZoomLevel(int)));

    ui->toolBar->addWidget(m_spinBoxZoom);
}

void MainWindow::buildView()
{
    QSettings s;

    // Screen dpi
    QDesktopWidget* deskWidget = QApplication::desktop();
    int dpix = deskWidget->logicalDpiX();
    int dpiy = deskWidget->logicalDpiY();

    // Size and format
    int default_width = 210*dpix/25.4;
    int default_height = 297*dpiy/25.4;
    QString default_format="None";
    int width = s.value("sceneWidth", default_width).toInt();
    int height = s.value("sceneHeight", default_height).toInt();
    QString format = s.value("sceneFormat", default_format).toString();

    // Rect color
    QColor color = s.value("backgroundColor").value<QColor>();
    if (!color.isValid())
    {
        color = Qt::white;
    }

    m_scene.setSceneRect(QRectF(-(width+1)/2, -(height+1)/2, width+1, height+1));
    m_borderSceneItem = m_scene.addRect(QRectF(-width/2, -height/2, width, height));
    m_borderSceneItem->setBrush(QBrush(color));

    ui->graphicsView->setGraphicsRectItem(&m_borderSceneItem);
    ui->graphicsView->setNbElts(m_scene.items().count());
    ui->graphicsView->setScene(&m_scene);
    ui->graphicsView->viewport()->installEventFilter(this);

    connect(&m_scene, SIGNAL(selectionChanged()), this, SLOT(itemSelected()));
    m_resized = false;
}

void MainWindow::fillDynamicStrings()
{
    m_spinBoxZoom->setToolTip(tr("Zoom level"));
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
        // Translate main ui
        ui->retranslateUi(this);

        // Dynamic strings retranslation
        fillDynamicStrings();

        // Retranslate all forms
        foreach (BaseForm* bf, m_forms)
        {
            bf->retranslate();
        }
    }
    else
    {
        QMainWindow::changeEvent(event);
    }
}


void MainWindow::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Delete)
    {
        QList<QGraphicsItem*> selectedItems = m_scene.selectedItems();

        // Delete all selected items
        for (int i = 0; i < selectedItems.size(); i++)
        {
            m_scene.removeItem(selectedItems[i]);
            delete selectedItems[i];
        }
    }
    else
    {
        QMainWindow::keyPressEvent(event);
    }
}

// Slots
// -----

void MainWindow::actionClicked(bool)
{
    if (sender() == ui->actionArrow) {
        ui->stackedWidgetForms->setCurrentWidget(m_forms[BUTTON_ID_ARROW]);
    } else if (sender() == ui->actionChart) {
        ui->stackedWidgetForms->setCurrentWidget(m_forms[BUTTON_ID_CHART]);
    } else if (sender() == ui->actionClipart) {
        ui->stackedWidgetForms->setCurrentWidget(m_forms[BUTTON_ID_CLIPART]);
    } else if (sender() == ui->actionLayers) {
        ui->stackedWidgetForms->setCurrentWidget(m_forms[BUTTON_ID_LAYERS]);
    } else if (sender() == ui->actionNumberedBullets) {
        ui->stackedWidgetForms->setCurrentWidget(m_forms[BUTTON_ID_BULLET]);
    } else if (sender() == ui->actionPicture) {
        ui->stackedWidgetForms->setCurrentWidget(m_forms[BUTTON_ID_PICTURE]);
    } else if (sender() == ui->actionScreenshot) {
        ui->stackedWidgetForms->setCurrentWidget(m_forms[BUTTON_ID_SCREENSHOT]);
    } else if (sender() == ui->actionTextBox) {
       ui->stackedWidgetForms->setCurrentWidget(m_forms[BUTTON_ID_TEXTBOX]);
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
    FormNumberedBullets* form = 0;
    if (m_forms.contains(BUTTON_ID_BULLET))
    {
        form = dynamic_cast<FormNumberedBullets*>(m_forms[BUTTON_ID_BULLET]);

        if (!form)
            return;
    }

  int from (0), to (0), taille (0);
  int shape (0);
  QColor bulletcolor, numbercolor;
  QFont qfont;
  form->get_info(from, to, taille,  shape, bulletcolor, numbercolor, qfont);
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
    FormTextBoxes* form = 0;
    if (m_forms.contains(BUTTON_ID_TEXTBOX))
    {
        form = dynamic_cast<FormTextBoxes*>(m_forms[BUTTON_ID_TEXTBOX]);

        if (!form)
            return;
    }

    // Retrieve data from the form
    QVariant data = form->getItemData();
    TextBoxItem* item = new TextBoxItem();
    item->setItemData(data);
    m_scene.addItem(item);
}

void MainWindow::slotPictures()
{
    FormPictures* form = 0;
    if (m_forms.contains(BUTTON_ID_PICTURE))
    {
        form = dynamic_cast<FormPictures*>(m_forms[BUTTON_ID_PICTURE]);

        if (!form)
            return;
    }

    PicturesGraphicsItem* PictureItem = new PicturesGraphicsItem(form);
    m_scene.addItem(PictureItem);
}

void MainWindow::slotGraphs()
{
    FormCharts* form = 0;
    if (m_forms.contains(BUTTON_ID_CHART))
    {
        form = dynamic_cast<FormCharts*>(m_forms[BUTTON_ID_CHART]);

        if (!form)
            return;
    }

    // Retrieve data from the form
    GraphsInfo infos;
    form->GetChartsValues(infos);
    int nbPoints = infos.m_Arcs.size();
    if( nbPoints > 0 )
    {
        GraphsGraphicsItem* g = new GraphsGraphicsItem();
        g->setInfos(infos);
        m_scene.addItem(g);
     }
}


///
/// \brief MainWindow::slotArrows
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
void MainWindow::slotArrows()
{
    FormArrows* form = 0;
    if (m_forms.contains(BUTTON_ID_ARROW))
    {
        form = dynamic_cast<FormArrows*>(m_forms[BUTTON_ID_ARROW]);

        if (!form)
            return;
    }


    // Control of the size of scene vs size of the arrows
    // with default sizes set for:
    // ArrowWidth = 50, ArrowHeight = 50
    // LineThickness = 1, SizeHeadTypeChoice 10
    // To Do after correcting arrows bugs size use QColor::QColor() to set invalid color
    // for ArrowOutlineColor, ArrowFillColor
    bool WithoutAnchorPoint(true), OneAnchorPoint(false), TwoAnchorPoints(false);
    int ArrowWidth(50), ArrowHeight(50);
    QColor ArrowOutlineColor, ArrowFillColor;
    int LineThickness(1), SizeHeadTypeChoice(10);

    form->GetInfosArrows(WithoutAnchorPoint, OneAnchorPoint, TwoAnchorPoints,
                                 ArrowWidth, ArrowHeight,
                                 ArrowOutlineColor, ArrowFillColor,
                                 LineThickness, SizeHeadTypeChoice);
                                //To do others HeadTypeChoiceContents
                                // comboBoxHeadTypeChoiceContents

    //qDebug() << "MainWindow::slotArrowsGraphicsItem LineThickness =" << LineThickness;
    qDebug() << "MainWindow::slotArrowsGraphicsItem ArrowWidth =" << ArrowWidth;
    qDebug() << "MainWindow::slotArrowsGraphicsItem ArrowHeight =" << ArrowHeight;


    // Define new ArrowsGraphicsItem on the scene
    ArrowsGraphicsItem  * ArrowItem = new ArrowsGraphicsItem(form);

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
    qDebug()<< "Max_Ypos =" << Max_Ypos;
    Max_Xpos = scene_BottomRight.x() - scene_TopLeft.x();
    qDebug()<< "Max_Xpos =" << Max_Xpos;

    // Checks if the Arrows Max Width and Max Height exceeds the size of the scene and fix it
     if (ArrowWidth > Max_Xpos)
         ArrowWidth = Max_Xpos;

     if (ArrowHeight > Max_Ypos)
         ArrowHeight = Max_Ypos;
     // end checks Arrows Max Width and Max Height

    // To Test the Min Width and the Min Height for the scene
    Min_Ypos = scene_TopLeft.y();
    qDebug()<< "Min_Ypos =" << Min_Ypos;
    Min_Xpos = scene_TopLeft.x();
    qDebug()<< "Min_Xpos =" << Min_Xpos;

    // Checks if the Arrows Start Position Item on the scene and fix it
    if (arrow_StartPositionItem->y() < Min_Ypos)
        arrow_StartPositionItem->setY(Min_Ypos);

    if (arrow_StartPositionItem->x() < Min_Xpos)
        arrow_StartPositionItem->setX(Min_Xpos);
    // end checks Arrows Start Position Item

    // Check if the Arrows End Position Item on the scene and fix it
    if (arrow_EndPositionItem->y() < Min_Ypos)
        arrow_EndPositionItem->setY(Min_Ypos);

    if (arrow_EndPositionItem->x() < Min_Xpos)
        arrow_EndPositionItem->setX(Min_Xpos);
    // end checks Arrows End Position Item

    // Add Arrow on the scene
    //m_scene.addItem(new ArrowsGraphicsItem());
    //qDebug() << "Before add the Item on scene MainWindow::slotArrowsGraphicsItem LineThickness =" << LineThickness;
    m_scene.addItem(ArrowItem);
}

void MainWindow::slotScreenshots()
{
    FormScreenshots* form = 0;
    if (m_forms.contains(BUTTON_ID_SCREENSHOT))
    {
        form = dynamic_cast<FormScreenshots*>(m_forms[BUTTON_ID_SCREENSHOT]);

        if (!form)
            return;
    }

    const QPixmap screenshot = form->getScreenshot();

    ScreenshotsGraphicsItem* sc = new ScreenshotsGraphicsItem(screenshot);
    m_scene.addItem(sc);
}


void MainWindow::takeScreenshot(bool wholeScreen)
{
    WId id = wholeScreen ? 0 : this->winId();

    QScreen* screen = QGuiApplication::primaryScreen();
    QPixmap screenshot = screen->grabWindow(id);

    emit screenshotTaken(screenshot);
}

void MainWindow::itemSelected()
{
    QList<QGraphicsItem*> items = m_scene.selectedItems();


    if (items.isEmpty())
        return;

    if (ui->stackedWidgetForms->currentWidget() != m_forms[BUTTON_ID_LAYERS])
    {
        // Casting the first selected item
        QGraphicsItem* item = items[0];
        BaseGraphicItem* castedItem = dynamic_cast<BaseGraphicItem*>(item);

        if (!castedItem)
            return;

        // Retrieve the type
        BaseGraphicItem::CustomTypes itemType = (BaseGraphicItem::CustomTypes)item->type();

        if (m_bounds.contains(itemType))
        {
            if (m_forms.contains(m_bounds[itemType]))
            {
                BaseFormItem* form = dynamic_cast<BaseFormItem*>(m_forms[m_bounds[itemType]]);

                if (form)
                {
                    // Use it to switch lateral form and load data into it
                    ui->stackedWidgetForms->setCurrentWidget(form);
                    form->loadFromItem(castedItem);
                }
            }
        }
    }
    else
    {
        FormLayers* layers = dynamic_cast<FormLayers*>(m_forms[BUTTON_ID_LAYERS]);

        if (layers)
        {
            layers->selectItem();
        }
    }
}



// Layers
void MainWindow::slotLayers()
{
    if (m_forms.contains(BUTTON_ID_LAYERS))
    {
        FormLayers* layers = dynamic_cast<FormLayers*>(m_forms[BUTTON_ID_LAYERS]);

        if (layers)
        {
            layers->updateLayers();
        }
    }
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
        ui->actionSave->setEnabled(true);
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
