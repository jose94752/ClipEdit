/****************************************************************************
** Meta object code from reading C++ file 'formscreenshots.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../sources/Forms/formscreenshots.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formscreenshots.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormScreenshots_t {
    QByteArrayData data[16];
    char stringdata0[182];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormScreenshots_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormScreenshots_t qt_meta_stringdata_FormScreenshots = {
    {
QT_MOC_LITERAL(0, 0, 15), // "FormScreenshots"
QT_MOC_LITERAL(1, 16, 13), // "setBackground"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 3), // "pix"
QT_MOC_LITERAL(4, 35, 14), // "dimensionsMade"
QT_MOC_LITERAL(5, 50, 15), // "mousePressEvent"
QT_MOC_LITERAL(6, 66, 17), // "mouseReleaseEvent"
QT_MOC_LITERAL(7, 84, 12), // "timeFunction"
QT_MOC_LITERAL(8, 97, 13), // "on_changeTime"
QT_MOC_LITERAL(9, 111, 17), // "choose_screenshot"
QT_MOC_LITERAL(10, 129, 8), // "snapshot"
QT_MOC_LITERAL(11, 138, 14), // "CaptureDesktop"
QT_MOC_LITERAL(12, 153, 11), // "CaptureArea"
QT_MOC_LITERAL(13, 165, 3), // "val"
QT_MOC_LITERAL(14, 169, 1), // "a"
QT_MOC_LITERAL(15, 171, 10) // "updatehide"

    },
    "FormScreenshots\0setBackground\0\0pix\0"
    "dimensionsMade\0mousePressEvent\0"
    "mouseReleaseEvent\0timeFunction\0"
    "on_changeTime\0choose_screenshot\0"
    "snapshot\0CaptureDesktop\0CaptureArea\0"
    "val\0a\0updatehide"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormScreenshots[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    2,   72,    2, 0x06 /* Public */,
       5,    0,   77,    2, 0x06 /* Public */,
       6,    0,   78,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   79,    2, 0x0a /* Public */,
       8,    0,   80,    2, 0x0a /* Public */,
       9,    0,   81,    2, 0x0a /* Public */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    2,   84,    2, 0x08 /* Private */,
      15,    0,   89,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPixmap,    3,
    QMetaType::Void, QMetaType::Bool, QMetaType::QRect,    2,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::QRectF,   13,   14,
    QMetaType::Void,

       0        // eod
};

void FormScreenshots::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FormScreenshots *_t = static_cast<FormScreenshots *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setBackground((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 1: _t->dimensionsMade((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QRect(*)>(_a[2]))); break;
        case 2: _t->mousePressEvent(); break;
        case 3: _t->mouseReleaseEvent(); break;
        case 4: _t->timeFunction(); break;
        case 5: _t->on_changeTime(); break;
        case 6: _t->choose_screenshot(); break;
        case 7: _t->snapshot(); break;
        case 8: _t->CaptureDesktop(); break;
        case 9: _t->CaptureArea((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QRectF(*)>(_a[2]))); break;
        case 10: _t->updatehide(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (FormScreenshots::*_t)(QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormScreenshots::setBackground)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FormScreenshots::*_t)(bool , QRect );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormScreenshots::dimensionsMade)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (FormScreenshots::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormScreenshots::mousePressEvent)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (FormScreenshots::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormScreenshots::mouseReleaseEvent)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormScreenshots::staticMetaObject = {
    { &BaseForm::staticMetaObject, qt_meta_stringdata_FormScreenshots.data,
      qt_meta_data_FormScreenshots,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FormScreenshots::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormScreenshots::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormScreenshots.stringdata0))
        return static_cast<void*>(this);
    return BaseForm::qt_metacast(_clname);
}

int FormScreenshots::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseForm::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void FormScreenshots::setBackground(QPixmap _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FormScreenshots::dimensionsMade(bool _t1, QRect _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FormScreenshots::mousePressEvent()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void FormScreenshots::mouseReleaseEvent()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
