#-------------------------------------------------
#
# Project created by QtCreator 2018-04-12T12:01:54
#
#-------------------------------------------------

QT       += core gui
QT       += charts
QT       += xml


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ClipEdit
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    mainwindow.cpp \
    Forms/formarrows.cpp \
    Forms/formcharts.cpp \
    Forms/formcliparts.cpp \
    Forms/formlayers.cpp \
    Forms/formnumberedbullets.cpp \
    Forms/formpictures.cpp \
    Forms/formscreenshots.cpp \
    Forms/formtextboxes.cpp \
    Forms/dialogfilealreadyexists.cpp \
    Forms/resizescenedialog.cpp \
    Forms/dialogsave.cpp \
    Classes/save.cpp \
    Classes/colorbutton.cpp \
    Items/basegraphicitem.cpp \
    Items/itemhandler.cpp \
    Items/numberedbulletgraphicitem.cpp \
    Items/picturesgraphicsitem.cpp \
    Items/screenshotsgraphicsitem.cpp \
    Items/textboxitem.cpp \
    Items/arrowsgraphicsitem.cpp \
    Items/graphsgraphicsitem.cpp \
    Classes/layers.cpp


HEADERS += \
    mainwindow.h \
    Forms/formarrows.h \
    Forms/formcharts.h \
    Forms/formcliparts.h \
    Forms/formlayers.h \
    Forms/formnumberedbullets.h \
    Forms/formpictures.h \
    Forms/formscreenshots.h \
    Forms/formtextboxes.h \
    Forms/resizescenedialog.h \
    Forms/dialogsave.h \
    Forms/dialogfilealreadyexists.h \
    Classes/save.h \
    Classes/colorbutton.h \
    Items/basegraphicitem.h \
    Items/itemhandler.h \
    Items/numberedbulletgraphicitem.h \
    Items/picturesgraphicsitem.h \
    Items/screenshotsgraphicsitem.h \
    Items/textboxitem.h \
    Items/arrowsgraphicsitem.h \
    Items/graphsgraphicsitem.h \
    Classes/layers.h


FORMS += \
    mainwindow.ui \
    Forms/formarrows.ui \
    Forms/formcharts.ui \
    Forms/formcliparts.ui \
    Forms/formlayers.ui \
    Forms/formnumberedbullets.ui \
    Forms/formpictures.ui \
    Forms/formscreenshots.ui \
    Forms/formtextboxes.ui \
    Forms/dialogfilealreadyexists.ui \
    Forms/resizescenedialog.ui \
    Forms/dialogsave.ui


RESOURCES += \
    resources/resources.qrc
