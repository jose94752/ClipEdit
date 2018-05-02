/*
================================================
* File:         mainwindow.h
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Application's main window
================================================
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Includes
// --------

#include <QMainWindow>
#include <QMap>
#include <QGraphicsScene>
#include <QRectF>

#include "Forms/formarrows.h"
#include "Forms/formcharts.h"
#include "Forms/formcliparts.h"
#include "Forms/formlayers.h"
#include "Forms/formnumberedbullets.h"
#include "Forms/formpictures.h"
#include "Forms/formscreenshots.h"
#include "Forms/formtextboxes.h"
#include "Items/numberedbulletgraphicitem.h"
#include "Items/basegraphicitem.h"
#include "dialogpreferences.h"

class QToolButton;

// Forward declaration
namespace Ui
{
    class MainWindow;
}


// Class
// -----

class MainWindow
    :   public QMainWindow
{
    Q_OBJECT

    public:

        // Constructor & Destructor
        explicit MainWindow(QWidget* parent = 0);
        ~MainWindow();

    private:

   int  m_height ;
   int  m_width ;

        // Buttons Ids
        enum e_BUTTON_IDS {
            BUTTON_ID_ARROW = 0,
            BUTTON_ID_CHART,
            BUTTON_ID_BULLET,
            BUTTON_ID_CLIPART,
            BUTTON_ID_PICTURE,
            BUTTON_ID_TEXTBOX,
            BUTTON_ID_SCREENSHOT,
            BUTTON_ID_LAYERS,
            NB_BUTTONS
        };

        // UI
        Ui::MainWindow* ui;

        // Forms
        FormArrows*          m_formArrows;
        FormCharts*          m_formCharts;
        FormCliparts*        m_formCliparts;
        FormLayers*          m_formLayers;
        FormNumberedBullets* m_formBullets;
        FormPictures*        m_formPictures;
        FormScreenshots*     m_formScreenshots;
        FormTextBoxes*       m_formTextboxes;

        QMap<e_BUTTON_IDS, int> m_listIndexes;
        QMap<BaseGraphicItem::CustomTypes, BaseForm*> m_itemForms;

        // Scene
        QGraphicsScene m_scene;

        QGraphicsRectItem *m_borderSceneItem;

        //int nbSceneElts;

        // Zoom
        QSpinBox* m_spinBoxZoom;

        //Preferences
        DialogPreferences* m_dialogPreferences;
        // Building
        void init();
        void buildMenu();
        void buildToolBar();
        void buildForms();
        void buildView();

    protected:

        bool eventFilter(QObject* watched, QEvent* event);

    private slots:

        // Menu and toolbar
        void save(bool);
        void saveAs(bool);
        void openFile(bool);
        void exportView(bool);
        void actionClicked(bool);
        void resizeScene();
        void slotNew(bool);
        void showAboutDialog(bool);

        // Items
        void slotNumberedBullets();
        void slotTextBoxes();
        void slotTextPicture();
        //void slotGraphs(const GraphsInfo &infos);
        void slotGraphs();
        void slotArrowsGraphicsItem();

        //
        void setBackground(const QPixmap& pix);

        void itemSelected();

        // Layers
        void slotLayers();
        void preferences ();

        void slot_language (QString lang);
};

#endif
