/****************************************************************************
** Meta object code from reading C++ file 'login.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../login.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'login.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Login_t {
    QByteArrayData data[22];
    char stringdata0[304];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Login_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Login_t qt_meta_stringdata_Login = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Login"
QT_MOC_LITERAL(1, 6, 13), // "RegisterReply"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 7), // "content"
QT_MOC_LITERAL(4, 29, 7), // "timeout"
QT_MOC_LITERAL(5, 37, 12), // "timeoutslots"
QT_MOC_LITERAL(6, 50, 19), // "on_main_btn_clicked"
QT_MOC_LITERAL(7, 70, 19), // "on_face_btn_clicked"
QT_MOC_LITERAL(8, 90, 12), // "displayImage"
QT_MOC_LITERAL(9, 103, 5), // "image"
QT_MOC_LITERAL(10, 109, 20), // "on_enter_btn_clicked"
QT_MOC_LITERAL(11, 130, 22), // "on_paizhao_btn_clicked"
QT_MOC_LITERAL(12, 153, 19), // "on_open_btn_clicked"
QT_MOC_LITERAL(13, 173, 13), // "replyFinished"
QT_MOC_LITERAL(14, 187, 14), // "QNetworkReply*"
QT_MOC_LITERAL(15, 202, 5), // "reply"
QT_MOC_LITERAL(16, 208, 23), // "on_open_pic_btn_clicked"
QT_MOC_LITERAL(17, 232, 23), // "on_register_btn_clicked"
QT_MOC_LITERAL(18, 256, 17), // "FaceRegisterReply"
QT_MOC_LITERAL(19, 274, 12), // "FaceRegister"
QT_MOC_LITERAL(20, 287, 8), // "group_id"
QT_MOC_LITERAL(21, 296, 7) // "user_id"

    },
    "Login\0RegisterReply\0\0content\0timeout\0"
    "timeoutslots\0on_main_btn_clicked\0"
    "on_face_btn_clicked\0displayImage\0image\0"
    "on_enter_btn_clicked\0on_paizhao_btn_clicked\0"
    "on_open_btn_clicked\0replyFinished\0"
    "QNetworkReply*\0reply\0on_open_pic_btn_clicked\0"
    "on_register_btn_clicked\0FaceRegisterReply\0"
    "FaceRegister\0group_id\0user_id"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Login[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    0,   87,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   88,    2, 0x08 /* Private */,
       6,    0,   89,    2, 0x08 /* Private */,
       7,    0,   90,    2, 0x08 /* Private */,
       8,    2,   91,    2, 0x08 /* Private */,
      10,    0,   96,    2, 0x08 /* Private */,
      11,    0,   97,    2, 0x08 /* Private */,
      12,    0,   98,    2, 0x08 /* Private */,
      13,    1,   99,    2, 0x08 /* Private */,
      16,    0,  102,    2, 0x08 /* Private */,
      17,    0,  103,    2, 0x08 /* Private */,
      18,    1,  104,    2, 0x08 /* Private */,
      19,    3,  107,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QImage,    2,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, QMetaType::QImage, QMetaType::QString, QMetaType::QString,    9,   20,   21,

       0        // eod
};

void Login::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Login *_t = static_cast<Login *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->RegisterReply((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->timeout(QPrivateSignal()); break;
        case 2: _t->timeoutslots(); break;
        case 3: _t->on_main_btn_clicked(); break;
        case 4: _t->on_face_btn_clicked(); break;
        case 5: _t->displayImage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QImage(*)>(_a[2]))); break;
        case 6: _t->on_enter_btn_clicked(); break;
        case 7: _t->on_paizhao_btn_clicked(); break;
        case 8: _t->on_open_btn_clicked(); break;
        case 9: _t->replyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 10: _t->on_open_pic_btn_clicked(); break;
        case 11: _t->on_register_btn_clicked(); break;
        case 12: _t->FaceRegisterReply((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 13: _t->FaceRegister((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Login::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Login::RegisterReply)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Login::*_t)(QPrivateSignal);
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Login::timeout)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Login::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Login.data,
      qt_meta_data_Login,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Login::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Login::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Login.stringdata0))
        return static_cast<void*>(const_cast< Login*>(this));
    return QWidget::qt_metacast(_clname);
}

int Login::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Login::RegisterReply(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Login::timeout(QPrivateSignal)
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
