#-------------------------------------------------
#
# Project created by QtCreator 2018-04-12T12:01:54
#
#-------------------------------------------------

QT       += core gui
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ClipEdit
TEMPLATE = app
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


CLASS_DIRECTORY    = Classes
ITEM_DIRECTORY     = Items
FORM_DIRECTORY     = Forms
RESOURCE_DIRECTORY = resources


SOURCES += \
    main.cpp \
    mainwindow.cpp \
    $${FORM_DIRECTORY}/baseform.cpp \
    $${FORM_DIRECTORY}/dialogsave.cpp \
    $${FORM_DIRECTORY}/formarrows.cpp \
    $${FORM_DIRECTORY}/formcharts.cpp \
    $${FORM_DIRECTORY}/formcliparts.cpp \
    $${FORM_DIRECTORY}/formlayers.cpp \
    $${FORM_DIRECTORY}/formnumberedbullets.cpp \
    $${FORM_DIRECTORY}/formpictures.cpp \
    $${FORM_DIRECTORY}/formscreenshots.cpp \
    $${FORM_DIRECTORY}/formtextboxes.cpp \
    $${FORM_DIRECTORY}/resizescenedialog.cpp \
    $${CLASS_DIRECTORY}/colorbutton.cpp \
    $${CLASS_DIRECTORY}/layeritemdelegate.cpp \
    $${CLASS_DIRECTORY}/layeritemmodel.cpp \
    $${CLASS_DIRECTORY}/save.cpp \
    $${ITEM_DIRECTORY}/basegraphicitem.cpp \
    $${ITEM_DIRECTORY}/arrowsgraphicsitem.cpp \
    $${ITEM_DIRECTORY}/graphsgraphicsitem.cpp \
    $${ITEM_DIRECTORY}/itemhandler.cpp \
    $${ITEM_DIRECTORY}/numberedbulletgraphicitem.cpp \
    $${ITEM_DIRECTORY}/picturesgraphicsitem.cpp \
    $${ITEM_DIRECTORY}/screenshotsgraphicsitem.cpp \
    $${ITEM_DIRECTORY}/textboxitem.cpp \
    graphicsview.cpp \
    dialogpreferences.cpp \
    Forms/baseformitem.cpp


HEADERS += \
    mainwindow.h \
    $${FORM_DIRECTORY}/baseform.h \
    $${FORM_DIRECTORY}/dialogsave.h \
    $${FORM_DIRECTORY}/formarrows.h \
    $${FORM_DIRECTORY}/formcharts.h \
    $${FORM_DIRECTORY}/formcliparts.h \
    $${FORM_DIRECTORY}/formlayers.h \
    $${FORM_DIRECTORY}/formnumberedbullets.h \
    $${FORM_DIRECTORY}/formpictures.h \
    $${FORM_DIRECTORY}/formscreenshots.h \
    $${FORM_DIRECTORY}/formtextboxes.h \
    $${FORM_DIRECTORY}/resizescenedialog.h \
    $${CLASS_DIRECTORY}/colorbutton.h \
    $${CLASS_DIRECTORY}/layeritemdelegate.h \
    $${CLASS_DIRECTORY}/layeritemmodel.h \
    $${CLASS_DIRECTORY}/save.h \
    $${ITEM_DIRECTORY}/basegraphicitem.h \
    $${ITEM_DIRECTORY}/arrowsgraphicsitem.h \
    $${ITEM_DIRECTORY}/graphsgraphicsitem.h \
    $${ITEM_DIRECTORY}/itemhandler.h \
    $${ITEM_DIRECTORY}/numberedbulletgraphicitem.h \
    $${ITEM_DIRECTORY}/picturesgraphicsitem.h \
    $${ITEM_DIRECTORY}/screenshotsgraphicsitem.h \
    $${ITEM_DIRECTORY}/textboxitem.h \
    graphicsview.h \
    dialogpreferences.h \
    Forms/baseformitem.h


FORMS += \
    mainwindow.ui \
    $${FORM_DIRECTORY}/dialogsave.ui \
    $${FORM_DIRECTORY}/formarrows.ui \
    $${FORM_DIRECTORY}/formcharts.ui \
    $${FORM_DIRECTORY}/formcliparts.ui \
    $${FORM_DIRECTORY}/formlayers.ui \
    $${FORM_DIRECTORY}/formnumberedbullets.ui \
    $${FORM_DIRECTORY}/formpictures.ui \
    $${FORM_DIRECTORY}/formscreenshots.ui \
    $${FORM_DIRECTORY}/formtextboxes.ui \
    $${FORM_DIRECTORY}/resizescenedialog.ui \
    dialogpreferences.ui


RESOURCES += \
    $${RESOURCE_DIRECTORY}/resources.qrc

DISTFILES += \
    Bugs.txt

TRANSLATIONS += \
    $${RESOURCE_DIRECTORY}/lang/clipedit_en.ts \
    $${RESOURCE_DIRECTORY}/lang/clipedit_fr.ts \
    $${RESOURCE_DIRECTORY}/lang/clipedit_de.ts
