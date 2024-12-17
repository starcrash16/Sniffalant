/****************************************************************************
** Meta object code from reading C++ file 'menu_program.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../menu_program.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menu_program.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.1. It"
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
struct qt_meta_tag_ZN12menu_programE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN12menu_programE = QtMocHelpers::stringData(
    "menu_program",
    "agregarPaquete",
    "",
    "QList<QStandardItem*>",
    "fila",
    "on_tableView_clicked",
    "QModelIndex",
    "index",
    "on_btnUDP_clicked",
    "on_btnTCP_clicked",
    "on_btnOtros_clicked",
    "on_btnLimpiarF_clicked",
    "mostrarEstadisticas",
    "abrirPaginaWeb",
    "finalizarCaptura"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN12menu_programE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x08,    1 /* Private */,
       5,    1,   71,    2, 0x08,    3 /* Private */,
       8,    0,   74,    2, 0x08,    5 /* Private */,
       9,    0,   75,    2, 0x08,    6 /* Private */,
      10,    0,   76,    2, 0x08,    7 /* Private */,
      11,    0,   77,    2, 0x08,    8 /* Private */,
      12,    0,   78,    2, 0x08,    9 /* Private */,
      13,    0,   79,    2, 0x08,   10 /* Private */,
      14,    0,   80,    2, 0x08,   11 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject menu_program::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_ZN12menu_programE.offsetsAndSizes,
    qt_meta_data_ZN12menu_programE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN12menu_programE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<menu_program, std::true_type>,
        // method 'agregarPaquete'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<QStandardItem*> &, std::false_type>,
        // method 'on_tableView_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'on_btnUDP_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnTCP_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnOtros_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnLimpiarF_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'mostrarEstadisticas'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'abrirPaginaWeb'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'finalizarCaptura'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void menu_program::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<menu_program *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->agregarPaquete((*reinterpret_cast< std::add_pointer_t<QList<QStandardItem*>>>(_a[1]))); break;
        case 1: _t->on_tableView_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 2: _t->on_btnUDP_clicked(); break;
        case 3: _t->on_btnTCP_clicked(); break;
        case 4: _t->on_btnOtros_clicked(); break;
        case 5: _t->on_btnLimpiarF_clicked(); break;
        case 6: _t->mostrarEstadisticas(); break;
        case 7: _t->abrirPaginaWeb(); break;
        case 8: _t->finalizarCaptura(); break;
        default: ;
        }
    }
}

const QMetaObject *menu_program::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *menu_program::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN12menu_programE.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int menu_program::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
