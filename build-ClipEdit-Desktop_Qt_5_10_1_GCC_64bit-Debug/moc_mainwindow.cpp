/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../sources/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[252];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 4), // "save"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 6), // "saveAs"
QT_MOC_LITERAL(4, 24, 8), // "openFile"
QT_MOC_LITERAL(5, 33, 10), // "exportView"
QT_MOC_LITERAL(6, 44, 13), // "actionClicked"
QT_MOC_LITERAL(7, 58, 11), // "resizeScene"
QT_MOC_LITERAL(8, 70, 7), // "slotNew"
QT_MOC_LITERAL(9, 78, 15), // "showAboutDialog"
QT_MOC_LITERAL(10, 94, 19), // "slotNumberedBullets"
QT_MOC_LITERAL(11, 114, 13), // "slotTextBoxes"
QT_MOC_LITERAL(12, 128, 15), // "slotTextPicture"
QT_MOC_LITERAL(13, 144, 10), // "slotGraphs"
QT_MOC_LITERAL(14, 155, 22), // "slotArrowsGraphicsItem"
QT_MOC_LITERAL(15, 178, 14), // "slotBackground"
QT_MOC_LITERAL(16, 193, 12), // "itemSelected"
QT_MOC_LITERAL(17, 206, 10), // "slotLayers"
QT_MOC_LITERAL(18, 217, 15), // "showPreferences"
QT_MOC_LITERAL(19, 233, 18) // "preferencesChanged"

    },
    "MainWindow\0save\0\0saveAs\0openFile\0"
    "exportView\0actionClicked\0resizeScene\0"
    "slotNew\0showAboutDialog\0slotNumberedBullets\0"
    "slotTextBoxes\0slotTextPicture\0slotGraphs\0"
    "slotArrowsGraphicsItem\0slotBackground\0"
    "itemSelected\0slotLayers\0showPreferences\0"
    "preferencesChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  104,    2, 0x08 /* Private */,
       3,    1,  107,    2, 0x08 /* Private */,
       4,    1,  110,    2, 0x08 /* Private */,
       5,    1,  113,    2, 0x08 /* Private */,
       6,    1,  116,    2, 0x08 /* Private */,
       7,    0,  119,    2, 0x08 /* Private */,
       8,    1,  120,    2, 0x08 /* Private */,
       9,    1,  123,    2, 0x08 /* Private */,
      10,    0,  126,    2, 0x08 /* Private */,
      11,    0,  127,    2, 0x08 /* Private */,
      12,    0,  128,    2, 0x08 /* Private */,
      13,    0,  129,    2, 0x08 /* Private */,
      14,    0,  130,    2, 0x08 /* Private */,
      15,    1,  131,    2, 0x08 /* Private */,
      16,    0,  134,    2, 0x08 /* Private */,
      17,    0,  135,    2, 0x08 /* Private */,
      18,    0,  136,    2, 0x08 /* Private */,
      19,    0,  137,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPixmap,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->save((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->saveAs((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->openFile((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->exportView((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->actionClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->resizeScene(); break;
        case 6: _t->slotNew((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->showAboutDialog((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->slotNumberedBullets(); break;
        case 9: _t->slotTextBoxes(); break;
        case 10: _t->slotTextPicture(); break;
        case 11: _t->slotGraphs(); break;
        case 12: _t->slotArrowsGraphicsItem(); break;
        case 13: _t->slotBackground((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 14: _t->itemSelected(); break;
        case 15: _t->slotLayers(); break;
        case 16: _t->showPreferences(); break;
        case 17: _t->preferencesChanged(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
