/****************************************************************************
** Meta object code from reading C++ file 'formpictures.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../sources/Forms/formpictures.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formpictures.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormPictures_t {
    QByteArrayData data[10];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormPictures_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormPictures_t qt_meta_stringdata_FormPictures = {
    {
QT_MOC_LITERAL(0, 0, 12), // "FormPictures"
QT_MOC_LITERAL(1, 13, 15), // "picture_changed"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 19), // "picture_changed_w_h"
QT_MOC_LITERAL(4, 50, 4), // "w_h1"
QT_MOC_LITERAL(5, 55, 13), // "chose_picture"
QT_MOC_LITERAL(6, 69, 9), // "legend_ok"
QT_MOC_LITERAL(7, 79, 20), // "picture_modification"
QT_MOC_LITERAL(8, 100, 22), // "picture_modification_w"
QT_MOC_LITERAL(9, 123, 22) // "picture_modification_h"

    },
    "FormPictures\0picture_changed\0\0"
    "picture_changed_w_h\0w_h1\0chose_picture\0"
    "legend_ok\0picture_modification\0"
    "picture_modification_w\0picture_modification_h"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormPictures[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    1,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   53,    2, 0x0a /* Public */,
       6,    1,   54,    2, 0x0a /* Public */,
       7,    0,   57,    2, 0x0a /* Public */,
       8,    0,   58,    2, 0x0a /* Public */,
       9,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Char,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FormPictures::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FormPictures *_t = static_cast<FormPictures *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->picture_changed(); break;
        case 1: _t->picture_changed_w_h((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 2: _t->chose_picture(); break;
        case 3: _t->legend_ok((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->picture_modification(); break;
        case 5: _t->picture_modification_w(); break;
        case 6: _t->picture_modification_h(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (FormPictures::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormPictures::picture_changed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FormPictures::*_t)(char );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormPictures::picture_changed_w_h)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormPictures::staticMetaObject = {
    { &BaseForm::staticMetaObject, qt_meta_stringdata_FormPictures.data,
      qt_meta_data_FormPictures,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FormPictures::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormPictures::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormPictures.stringdata0))
        return static_cast<void*>(this);
    return BaseForm::qt_metacast(_clname);
}

int FormPictures::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseForm::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void FormPictures::picture_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FormPictures::picture_changed_w_h(char _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
