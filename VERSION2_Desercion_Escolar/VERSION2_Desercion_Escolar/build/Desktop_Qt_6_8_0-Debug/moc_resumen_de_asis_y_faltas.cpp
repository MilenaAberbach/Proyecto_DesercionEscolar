/****************************************************************************
** Meta object code from reading C++ file 'resumen_de_asis_y_faltas.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../resumen_de_asis_y_faltas.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'resumen_de_asis_y_faltas.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSresumen_de_asis_y_faltasENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSresumen_de_asis_y_faltasENDCLASS = QtMocHelpers::stringData(
    "resumen_de_asis_y_faltas",
    "on_actionCambiar_cuenta_triggered",
    "",
    "on_actionVolver_triggered",
    "on_actionSalir_triggered",
    "mostrarResumenAlumno",
    "on_btnGuardar_clicked",
    "on_comboBoxAlumno_currentIndexChanged",
    "index",
    "mostrarFaltasPorMes",
    "on_comboBox_motivoRes_Alu_currentIndexChanged",
    "on_comboBox_motivoRes_Fecha_currentIndexChanged"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSresumen_de_asis_y_faltasENDCLASS[] = {

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
       1,    0,   68,    2, 0x08,    1 /* Private */,
       3,    0,   69,    2, 0x08,    2 /* Private */,
       4,    0,   70,    2, 0x08,    3 /* Private */,
       5,    0,   71,    2, 0x08,    4 /* Private */,
       6,    0,   72,    2, 0x08,    5 /* Private */,
       7,    1,   73,    2, 0x08,    6 /* Private */,
       9,    0,   76,    2, 0x08,    8 /* Private */,
      10,    1,   77,    2, 0x08,    9 /* Private */,
      11,    1,   80,    2, 0x08,   11 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

Q_CONSTINIT const QMetaObject resumen_de_asis_y_faltas::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSresumen_de_asis_y_faltasENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSresumen_de_asis_y_faltasENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSresumen_de_asis_y_faltasENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<resumen_de_asis_y_faltas, std::true_type>,
        // method 'on_actionCambiar_cuenta_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionVolver_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionSalir_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'mostrarResumenAlumno'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnGuardar_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comboBoxAlumno_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'mostrarFaltasPorMes'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comboBox_motivoRes_Alu_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_comboBox_motivoRes_Fecha_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void resumen_de_asis_y_faltas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<resumen_de_asis_y_faltas *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_actionCambiar_cuenta_triggered(); break;
        case 1: _t->on_actionVolver_triggered(); break;
        case 2: _t->on_actionSalir_triggered(); break;
        case 3: _t->mostrarResumenAlumno(); break;
        case 4: _t->on_btnGuardar_clicked(); break;
        case 5: _t->on_comboBoxAlumno_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->mostrarFaltasPorMes(); break;
        case 7: _t->on_comboBox_motivoRes_Alu_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->on_comboBox_motivoRes_Fecha_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *resumen_de_asis_y_faltas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *resumen_de_asis_y_faltas::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSresumen_de_asis_y_faltasENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int resumen_de_asis_y_faltas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
