/****************************************************************************
** Meta object code from reading C++ file 'formlayers.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../sources/Forms/formlayers.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formlayers.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormLayers_t {
    QByteArrayData data[14];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormLayers_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormLayers_t qt_meta_stringdata_FormLayers = {
    {
QT_MOC_LITERAL(0, 0, 10), // "FormLayers"
QT_MOC_LITERAL(1, 11, 13), // "cellActivated"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 3), // "row"
QT_MOC_LITERAL(4, 30, 6), // "column"
QT_MOC_LITERAL(5, 37, 11), // "contextMenu"
QT_MOC_LITERAL(6, 49, 3), // "pos"
QT_MOC_LITERAL(7, 53, 13), // "ActionClicked"
QT_MOC_LITERAL(8, 67, 4), // "line"
QT_MOC_LITERAL(9, 72, 3), // "col"
QT_MOC_LITERAL(10, 76, 8), // "ActionUp"
QT_MOC_LITERAL(11, 85, 10), // "ActionDown"
QT_MOC_LITERAL(12, 96, 9), // "ActionAdd"
QT_MOC_LITERAL(13, 106, 10) // "ActionSupp"

    },
    "FormLayers\0cellActivated\0\0row\0column\0"
    "contextMenu\0pos\0ActionClicked\0line\0"
    "col\0ActionUp\0ActionDown\0ActionAdd\0"
    "ActionSupp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormLayers[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x08 /* Private */,
       5,    1,   54,    2, 0x08 /* Private */,
       7,    2,   57,    2, 0x08 /* Private */,
      10,    0,   62,    2, 0x08 /* Private */,
      11,    0,   63,    2, 0x08 /* Private */,
      12,    0,   64,    2, 0x08 /* Private */,
      13,    0,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QPoint,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FormLayers::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FormLayers *_t = static_cast<FormLayers *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cellActivated((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->contextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 2: _t->ActionClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->ActionUp(); break;
        case 4: _t->ActionDown(); break;
        case 5: _t->ActionAdd(); break;
        case 6: _t->ActionSupp(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormLayers::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FormLayers.data,
      qt_meta_data_FormLayers,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FormLayers::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormLayers::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormLayers.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FormLayers::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
