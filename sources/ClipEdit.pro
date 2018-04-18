#-------------------------------------------------
#
# Project created by QtCreator 2018-04-12T12:01:54
#
#-------------------------------------------------

QT       += core gui
QT       += charts


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
    about.cpp \
    Canvas_Items/Item_Arrow.cpp \
    Forms/formarrows.cpp \
    Forms/formcharts.cpp \
    Forms/formcliparts.cpp \
    Forms/formlayers.cpp \
    Forms/formnumberedbullets.cpp \
    Forms/formpictures.cpp \
    Forms/formscreenshots.cpp \
    Forms/formtextboxes.cpp \
    Components/one_menu_button.cpp \
    Components/one_layered_canvas.cpp

HEADERS += \
    mainwindow.h \
    about.h \
    Canvas_Items/Item_Arrow.h \
    Classes/One_Form.h \
    Forms/formarrows.h \
    Forms/formcharts.h \
    Forms/formcliparts.h \
    Forms/formlayers.h \
    Forms/formnumberedbullets.h \
    Forms/formpictures.h \
    Forms/formscreenshots.h \
    Forms/formtextboxes.h \
    Components/one_menu_button.h \
    Components/one_layered_canvas.h

FORMS += \
    mainwindow.ui \
    about.ui \
    Forms/formarrows.ui \
    Forms/formcharts.ui \
    Forms/formcliparts.ui \
    Forms/formlayers.ui \
    Forms/formnumberedbullets.ui \
    Forms/formpictures.ui \
    Forms/formscreenshots.ui \
    Forms/formtextboxes.ui \
    Components/one_menu_button.ui \
    Components/one_layered_canvas.ui

RESOURCES += \
    resources/resources.qrc
