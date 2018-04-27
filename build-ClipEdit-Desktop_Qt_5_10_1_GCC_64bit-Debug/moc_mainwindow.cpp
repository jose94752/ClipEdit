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
    QByteArrayData data[23];
    char stringdata0[256];
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
QT_MOC_LITERAL(7, 58, 10), // "resizeTold"
QT_MOC_LITERAL(8, 69, 7), // "slotNew"
QT_MOC_LITERAL(9, 77, 15), // "showAboutDialog"
QT_MOC_LITERAL(10, 93, 19), // "slotNumberedBullets"
QT_MOC_LITERAL(11, 113, 13), // "slotTextBoxes"
QT_MOC_LITERAL(12, 127, 15), // "slotTextPicture"
QT_MOC_LITERAL(13, 143, 10), // "slotGraphs"
QT_MOC_LITERAL(14, 154, 10), // "GraphsInfo"
QT_MOC_LITERAL(15, 165, 5), // "infos"
QT_MOC_LITERAL(16, 171, 22), // "slotArrowsGraphicsItem"
QT_MOC_LITERAL(17, 194, 13), // "setBackground"
QT_MOC_LITERAL(18, 208, 3), // "pix"
QT_MOC_LITERAL(19, 212, 12), // "itemSelected"
QT_MOC_LITERAL(20, 225, 14), // "QGraphicsItem*"
QT_MOC_LITERAL(21, 240, 4), // "item"
QT_MOC_LITERAL(22, 245, 10) // "slotLayers"

    },
    "MainWindow\0save\0\0saveAs\0openFile\0"
    "exportView\0actionClicked\0resizeTold\0"
    "slotNew\0showAboutDialog\0slotNumberedBullets\0"
    "slotTextBoxes\0slotTextPicture\0slotGraphs\0"
    "GraphsInfo\0infos\0slotArrowsGraphicsItem\0"
    "setBackground\0pix\0itemSelected\0"
    "QGraphicsItem*\0item\0slotLayers"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x08 /* Private */,
       3,    1,   97,    2, 0x08 /* Private */,
       4,    1,  100,    2, 0x08 /* Private */,
       5,    1,  103,    2, 0x08 /* Private */,
       6,    1,  106,    2, 0x08 /* Private */,
       7,    1,  109,    2, 0x08 /* Private */,
       8,    1,  112,    2, 0x08 /* Private */,
       9,    1,  115,    2, 0x08 /* Private */,
      10,    0,  118,    2, 0x08 /* Private */,
      11,    1,  119,    2, 0x08 /* Private */,
      12,    0,  122,    2, 0x08 /* Private */,
      13,    1,  123,    2, 0x08 /* Private */,
      16,    0,  126,    2, 0x08 /* Private */,
      17,    1,  127,    2, 0x08 /* Private */,
      19,    1,  130,    2, 0x08 /* Private */,
      22,    0,  133,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPixmap,   18,
    QMetaType::Void, 0x80000000 | 20,   21,
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
        case 5: _t->resizeTold((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->slotNew((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->showAboutDialog((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->slotNumberedBullets(); break;
        case 9: _t->slotTextBoxes((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->slotTextPicture(); break;
        case 11: _t->slotGraphs((*reinterpret_cast< const GraphsInfo(*)>(_a[1]))); break;
        case 12: _t->slotArrowsGraphicsItem(); break;
        case 13: _t->setBackground((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 14: _t->itemSelected((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 15: _t->slotLayers(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
