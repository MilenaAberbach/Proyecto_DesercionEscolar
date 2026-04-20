/****************************************************************************
** Meta object code from reading C++ file 'baja_de_alumnos.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../baja_de_alumnos.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'baja_de_alumnos.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
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
struct qt_meta_stringdata_CLASSbaja_de_alumnosENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSbaja_de_alumnosENDCLASS = QtMocHelpers::stringData(
    "baja_de_alumnos",
    "on_actionCambiar_cuenta_triggered",
    "",
    "on_actionVolver_triggered",
    "on_actionSalir_triggered",
    "on_comboBoxAlumno_currentIndexChanged",
    "on_confirmarBajaAlumno_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSbaja_de_alumnosENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x08,    1 /* Private */,
       3,    0,   45,    2, 0x08,    2 /* Private */,
       4,    0,   46,    2, 0x08,    3 /* Private */,
       5,    0,   47,    2, 0x08,    4 /* Private */,
       6,    0,   48,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject baja_de_alumnos::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSbaja_de_alumnosENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSbaja_de_alumnosENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSbaja_de_alumnosENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<baja_de_alumnos, std::true_type>,
        // method 'on_actionCambiar_cuenta_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionVolver_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionSalir_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comboBoxAlumno_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_confirmarBajaAlumno_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void baja_de_alumnos::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<baja_de_alumnos *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_actionCambiar_cuenta_triggered(); break;
        case 1: _t->on_actionVolver_triggered(); break;
        case 2: _t->on_actionSalir_triggered(); break;
        case 3: _t->on_comboBoxAlumno_currentIndexChanged(); break;
        case 4: _t->on_confirmarBajaAlumno_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *baja_de_alumnos::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *baja_de_alumnos::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSbaja_de_alumnosENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int baja_de_alumnos::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
