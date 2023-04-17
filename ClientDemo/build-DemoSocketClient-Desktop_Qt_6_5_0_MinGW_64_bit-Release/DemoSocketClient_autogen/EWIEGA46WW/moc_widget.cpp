/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../DemoSocketClient/widget.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSWidgetENDCLASS = QtMocHelpers::stringData(
    "Widget",
    "on_lineEdit_2_returnPressed",
    "",
    "on_pushButton_2_clicked",
    "showConnected",
    "on_fontComboBox_currentFontChanged",
    "f",
    "on_pushButton_4_clicked",
    "on_lineEdit_returnPressed",
    "on_pushButton_clicked",
    "handleComingData",
    "disconnectedFromServer",
    "on_pushButton_3_clicked",
    "handleSocketError",
    "QAbstractSocket::SocketError",
    "erroeCode"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSWidgetENDCLASS_t {
    uint offsetsAndSizes[32];
    char stringdata0[7];
    char stringdata1[28];
    char stringdata2[1];
    char stringdata3[24];
    char stringdata4[14];
    char stringdata5[35];
    char stringdata6[2];
    char stringdata7[24];
    char stringdata8[26];
    char stringdata9[22];
    char stringdata10[17];
    char stringdata11[23];
    char stringdata12[24];
    char stringdata13[18];
    char stringdata14[29];
    char stringdata15[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSWidgetENDCLASS_t qt_meta_stringdata_CLASSWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 6),  // "Widget"
        QT_MOC_LITERAL(7, 27),  // "on_lineEdit_2_returnPressed"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 23),  // "on_pushButton_2_clicked"
        QT_MOC_LITERAL(60, 13),  // "showConnected"
        QT_MOC_LITERAL(74, 34),  // "on_fontComboBox_currentFontCh..."
        QT_MOC_LITERAL(109, 1),  // "f"
        QT_MOC_LITERAL(111, 23),  // "on_pushButton_4_clicked"
        QT_MOC_LITERAL(135, 25),  // "on_lineEdit_returnPressed"
        QT_MOC_LITERAL(161, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(183, 16),  // "handleComingData"
        QT_MOC_LITERAL(200, 22),  // "disconnectedFromServer"
        QT_MOC_LITERAL(223, 23),  // "on_pushButton_3_clicked"
        QT_MOC_LITERAL(247, 17),  // "handleSocketError"
        QT_MOC_LITERAL(265, 28),  // "QAbstractSocket::SocketError"
        QT_MOC_LITERAL(294, 9)   // "erroeCode"
    },
    "Widget",
    "on_lineEdit_2_returnPressed",
    "",
    "on_pushButton_2_clicked",
    "showConnected",
    "on_fontComboBox_currentFontChanged",
    "f",
    "on_pushButton_4_clicked",
    "on_lineEdit_returnPressed",
    "on_pushButton_clicked",
    "handleComingData",
    "disconnectedFromServer",
    "on_pushButton_3_clicked",
    "handleSocketError",
    "QAbstractSocket::SocketError",
    "erroeCode"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSWidgetENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x08,    1 /* Private */,
       3,    0,   81,    2, 0x08,    2 /* Private */,
       4,    0,   82,    2, 0x08,    3 /* Private */,
       5,    1,   83,    2, 0x08,    4 /* Private */,
       7,    0,   86,    2, 0x08,    6 /* Private */,
       8,    0,   87,    2, 0x08,    7 /* Private */,
       9,    0,   88,    2, 0x08,    8 /* Private */,
      10,    0,   89,    2, 0x08,    9 /* Private */,
      11,    0,   90,    2, 0x08,   10 /* Private */,
      12,    0,   91,    2, 0x08,   11 /* Private */,
      13,    1,   92,    2, 0x08,   12 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QFont,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,

       0        // eod
};

Q_CONSTINIT const QMetaObject Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Widget, std::true_type>,
        // method 'on_lineEdit_2_returnPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_fontComboBox_currentFontChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QFont &, std::false_type>,
        // method 'on_pushButton_4_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_lineEdit_returnPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleComingData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'disconnectedFromServer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_3_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleSocketError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketError, std::false_type>
    >,
    nullptr
} };

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_lineEdit_2_returnPressed(); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->showConnected(); break;
        case 3: _t->on_fontComboBox_currentFontChanged((*reinterpret_cast< std::add_pointer_t<QFont>>(_a[1]))); break;
        case 4: _t->on_pushButton_4_clicked(); break;
        case 5: _t->on_lineEdit_returnPressed(); break;
        case 6: _t->on_pushButton_clicked(); break;
        case 7: _t->handleComingData(); break;
        case 8: _t->disconnectedFromServer(); break;
        case 9: _t->on_pushButton_3_clicked(); break;
        case 10: _t->handleSocketError((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
