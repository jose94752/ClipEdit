/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "graphicsview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionOpen;
    QAction *actionExportAs;
    QAction *actionAbout;
    QAction *actionArrow;
    QAction *actionChart;
    QAction *actionClipart;
    QAction *actionNumberedBullets;
    QAction *actionPicture;
    QAction *actionTextBox;
    QAction *actionNewLayer;
    QAction *actionQuit;
    QAction *actionSaveAs;
    QAction *actionScreenshot;
    QAction *actionLayers;
    QAction *actionResize;
    QAction *actionNew;
    QAction *actionClear;
    QAction *actionContentToView;
    QAction *actionSetBackgroundColor;
    QAction *actionPreferences;
    QAction *actionPreferences_2;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    GraphicsView *graphicsView;
    QStackedWidget *stackedWidgetForms;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menufile;
    QMenu *menuHelp;
    QMenu *menuEdit;
    QMenu *menuTools;
    QMenu *menuInsert;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(516, 359);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icons/save-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/icons/open-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionExportAs = new QAction(MainWindow);
        actionExportAs->setObjectName(QStringLiteral("actionExportAs"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/icons/export-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExportAs->setIcon(icon2);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/icons/about-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon3);
        actionArrow = new QAction(MainWindow);
        actionArrow->setObjectName(QStringLiteral("actionArrow"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/icons/arrow-icon-2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionArrow->setIcon(icon4);
        actionChart = new QAction(MainWindow);
        actionChart->setObjectName(QStringLiteral("actionChart"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/icons/chart-icon-2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChart->setIcon(icon5);
        actionClipart = new QAction(MainWindow);
        actionClipart->setObjectName(QStringLiteral("actionClipart"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icons/icons/clipart-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClipart->setIcon(icon6);
        actionNumberedBullets = new QAction(MainWindow);
        actionNumberedBullets->setObjectName(QStringLiteral("actionNumberedBullets"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icons/icons/numbered-bullet-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNumberedBullets->setIcon(icon7);
        actionPicture = new QAction(MainWindow);
        actionPicture->setObjectName(QStringLiteral("actionPicture"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/icons/icons/picture-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPicture->setIcon(icon8);
        actionTextBox = new QAction(MainWindow);
        actionTextBox->setObjectName(QStringLiteral("actionTextBox"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/icons/icons/textbox-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTextBox->setIcon(icon9);
        actionNewLayer = new QAction(MainWindow);
        actionNewLayer->setObjectName(QStringLiteral("actionNewLayer"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/icons/icons/layer-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewLayer->setIcon(icon10);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        actionSaveAs->setIcon(icon);
        actionScreenshot = new QAction(MainWindow);
        actionScreenshot->setObjectName(QStringLiteral("actionScreenshot"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/icons/icons/screenshot-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionScreenshot->setIcon(icon11);
        actionLayers = new QAction(MainWindow);
        actionLayers->setObjectName(QStringLiteral("actionLayers"));
        actionLayers->setIcon(icon10);
        actionResize = new QAction(MainWindow);
        actionResize->setObjectName(QStringLiteral("actionResize"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/icons/icons/resize-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionResize->setIcon(icon12);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/icons/icons/new-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon13);
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/icons/icons/clear-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon14);
        actionContentToView = new QAction(MainWindow);
        actionContentToView->setObjectName(QStringLiteral("actionContentToView"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/icons/icons/fit-in-view-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionContentToView->setIcon(icon15);
        actionSetBackgroundColor = new QAction(MainWindow);
        actionSetBackgroundColor->setObjectName(QStringLiteral("actionSetBackgroundColor"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/icons/icons/background-color-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSetBackgroundColor->setIcon(icon16);
        actionPreferences = new QAction(MainWindow);
        actionPreferences->setObjectName(QStringLiteral("actionPreferences"));
        actionPreferences_2 = new QAction(MainWindow);
        actionPreferences_2->setObjectName(QStringLiteral("actionPreferences_2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        graphicsView = new GraphicsView(splitter);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMinimumSize(QSize(400, 0));
        splitter->addWidget(graphicsView);
        stackedWidgetForms = new QStackedWidget(splitter);
        stackedWidgetForms->setObjectName(QStringLiteral("stackedWidgetForms"));
        splitter->addWidget(stackedWidgetForms);

        verticalLayout->addWidget(splitter);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 516, 22));
        menufile = new QMenu(menuBar);
        menufile->setObjectName(QStringLiteral("menufile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuInsert = new QMenu(menuTools);
        menuInsert->setObjectName(QStringLiteral("menuInsert"));
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menufile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menufile->addAction(actionNew);
        menufile->addAction(actionOpen);
        menufile->addSeparator();
        menufile->addAction(actionSave);
        menufile->addAction(actionSaveAs);
        menufile->addAction(actionExportAs);
        menufile->addSeparator();
        menufile->addAction(actionQuit);
        menuHelp->addAction(actionAbout);
        menuEdit->addAction(actionResize);
        menuEdit->addAction(actionSetBackgroundColor);
        menuEdit->addAction(actionContentToView);
        menuEdit->addAction(actionClear);
        menuTools->addAction(menuInsert->menuAction());
        menuTools->addSeparator();
        menuTools->addAction(actionScreenshot);
        menuTools->addSeparator();
        menuTools->addAction(actionLayers);
        menuTools->addSeparator();
        menuTools->addAction(actionPreferences_2);
        menuInsert->addAction(actionArrow);
        menuInsert->addAction(actionChart);
        menuInsert->addAction(actionClipart);
        menuInsert->addAction(actionNumberedBullets);
        menuInsert->addAction(actionPicture);
        menuInsert->addAction(actionTextBox);
        toolBar->addAction(actionArrow);
        toolBar->addAction(actionChart);
        toolBar->addAction(actionClipart);
        toolBar->addAction(actionNumberedBullets);
        toolBar->addAction(actionPicture);
        toolBar->addAction(actionTextBox);
        toolBar->addSeparator();
        toolBar->addAction(actionScreenshot);
        toolBar->addSeparator();
        toolBar->addAction(actionLayers);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ClipEdit", nullptr));
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", nullptr));
        actionExportAs->setText(QApplication::translate("MainWindow", "Export as", nullptr));
#ifndef QT_NO_TOOLTIP
        actionExportAs->setToolTip(QApplication::translate("MainWindow", "Export the view as a file", nullptr));
#endif // QT_NO_TOOLTIP
        actionAbout->setText(QApplication::translate("MainWindow", "About", nullptr));
#ifndef QT_NO_TOOLTIP
        actionAbout->setToolTip(QApplication::translate("MainWindow", "Show about dialog", nullptr));
#endif // QT_NO_TOOLTIP
        actionArrow->setText(QApplication::translate("MainWindow", "Arrow", nullptr));
#ifndef QT_NO_TOOLTIP
        actionArrow->setToolTip(QApplication::translate("MainWindow", "Insert Arrow", nullptr));
#endif // QT_NO_TOOLTIP
        actionChart->setText(QApplication::translate("MainWindow", "Chart", nullptr));
#ifndef QT_NO_TOOLTIP
        actionChart->setToolTip(QApplication::translate("MainWindow", "Insert Chart", nullptr));
#endif // QT_NO_TOOLTIP
        actionClipart->setText(QApplication::translate("MainWindow", "Cliparts", nullptr));
#ifndef QT_NO_TOOLTIP
        actionClipart->setToolTip(QApplication::translate("MainWindow", "Insert Clipart", nullptr));
#endif // QT_NO_TOOLTIP
        actionNumberedBullets->setText(QApplication::translate("MainWindow", "Numbered Bullets", nullptr));
#ifndef QT_NO_TOOLTIP
        actionNumberedBullets->setToolTip(QApplication::translate("MainWindow", "Insert Numbered Bullets", nullptr));
#endif // QT_NO_TOOLTIP
        actionPicture->setText(QApplication::translate("MainWindow", "Picture", nullptr));
#ifndef QT_NO_TOOLTIP
        actionPicture->setToolTip(QApplication::translate("MainWindow", "Insert Picture", nullptr));
#endif // QT_NO_TOOLTIP
        actionTextBox->setText(QApplication::translate("MainWindow", "TextBox", nullptr));
#ifndef QT_NO_TOOLTIP
        actionTextBox->setToolTip(QApplication::translate("MainWindow", "Insert TextBox", nullptr));
#endif // QT_NO_TOOLTIP
        actionNewLayer->setText(QApplication::translate("MainWindow", "New layer", nullptr));
#ifndef QT_NO_TOOLTIP
        actionNewLayer->setToolTip(QApplication::translate("MainWindow", "Layers", nullptr));
#endif // QT_NO_TOOLTIP
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", nullptr));
#ifndef QT_NO_TOOLTIP
        actionQuit->setToolTip(QApplication::translate("MainWindow", "Quit ClipEdit", nullptr));
#endif // QT_NO_TOOLTIP
        actionSaveAs->setText(QApplication::translate("MainWindow", "Save as", nullptr));
        actionScreenshot->setText(QApplication::translate("MainWindow", "Screenshot", nullptr));
#ifndef QT_NO_TOOLTIP
        actionScreenshot->setToolTip(QApplication::translate("MainWindow", "Take a screenshot", nullptr));
#endif // QT_NO_TOOLTIP
        actionLayers->setText(QApplication::translate("MainWindow", "Layers", nullptr));
        actionResize->setText(QApplication::translate("MainWindow", "Resize scene", nullptr));
#ifndef QT_NO_TOOLTIP
        actionResize->setToolTip(QApplication::translate("MainWindow", "Resize the scene", nullptr));
#endif // QT_NO_TOOLTIP
        actionNew->setText(QApplication::translate("MainWindow", "New", nullptr));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("MainWindow", "Create a new document", nullptr));
#endif // QT_NO_TOOLTIP
        actionClear->setText(QApplication::translate("MainWindow", "Clear", nullptr));
#ifndef QT_NO_TOOLTIP
        actionClear->setToolTip(QApplication::translate("MainWindow", "Delete all items from the scene", nullptr));
#endif // QT_NO_TOOLTIP
        actionContentToView->setText(QApplication::translate("MainWindow", "Content to view", nullptr));
#ifndef QT_NO_TOOLTIP
        actionContentToView->setToolTip(QApplication::translate("MainWindow", "Scale the scene to show all items", nullptr));
#endif // QT_NO_TOOLTIP
        actionSetBackgroundColor->setText(QApplication::translate("MainWindow", "Set background color", nullptr));
        actionPreferences->setText(QApplication::translate("MainWindow", "Preferences", nullptr));
        actionPreferences_2->setText(QApplication::translate("MainWindow", "Preferences", nullptr));
        menufile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", nullptr));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", nullptr));
        menuInsert->setTitle(QApplication::translate("MainWindow", "Insert", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
