/********************************************************************************
** Form generated from reading UI file 'alta_de_alumnos.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALTA_DE_ALUMNOS_H
#define UI_ALTA_DE_ALUMNOS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_alta_de_alumnos
{
public:
    QAction *actionCambiar_cuenta;
    QAction *actionSalir;
    QAction *actionAlta;
    QAction *actionBaja;
    QAction *actionModificacion;
    QAction *actionListado;
    QAction *actionRegistro_de_asistencias;
    QAction *actionMotivos_de_faltas;
    QAction *actionRegistro_de_asistencias_2;
    QAction *actionReuniones;
    QAction *actionVolver;
    QWidget *centralwidget;
    QPushButton *confirmarAltaAlumno;
    QLabel *labelContextoAlu;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *camposAlumno;
    QLabel *label_NomAlu;
    QLabel *label_ApeAlu;
    QLabel *label_EdadAlu;
    QLabel *labelFondo1;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *completarCamposAlumno;
    QLineEdit *lEdit_NombreAlu;
    QLineEdit *lEdit_ApellidoAlu;
    QSpinBox *sBox_EdadAlumno;
    QLabel *label_cargoUsuario;
    QLabel *label_2;
    QLabel *label_nombreUsuario;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_idUsuario;
    QLabel *label_idCurso;
    QMenuBar *menubar;
    QMenu *menuOpciones;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *alta_de_alumnos)
    {
        if (alta_de_alumnos->objectName().isEmpty())
            alta_de_alumnos->setObjectName("alta_de_alumnos");
        alta_de_alumnos->resize(800, 375);
        actionCambiar_cuenta = new QAction(alta_de_alumnos);
        actionCambiar_cuenta->setObjectName("actionCambiar_cuenta");
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("x-office-address-book")));
        actionCambiar_cuenta->setIcon(icon);
        actionSalir = new QAction(alta_de_alumnos);
        actionSalir->setObjectName("actionSalir");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        actionSalir->setIcon(icon1);
        actionAlta = new QAction(alta_de_alumnos);
        actionAlta->setObjectName("actionAlta");
        actionBaja = new QAction(alta_de_alumnos);
        actionBaja->setObjectName("actionBaja");
        actionModificacion = new QAction(alta_de_alumnos);
        actionModificacion->setObjectName("actionModificacion");
        actionListado = new QAction(alta_de_alumnos);
        actionListado->setObjectName("actionListado");
        actionRegistro_de_asistencias = new QAction(alta_de_alumnos);
        actionRegistro_de_asistencias->setObjectName("actionRegistro_de_asistencias");
        actionMotivos_de_faltas = new QAction(alta_de_alumnos);
        actionMotivos_de_faltas->setObjectName("actionMotivos_de_faltas");
        actionRegistro_de_asistencias_2 = new QAction(alta_de_alumnos);
        actionRegistro_de_asistencias_2->setObjectName("actionRegistro_de_asistencias_2");
        actionReuniones = new QAction(alta_de_alumnos);
        actionReuniones->setObjectName("actionReuniones");
        actionVolver = new QAction(alta_de_alumnos);
        actionVolver->setObjectName("actionVolver");
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::EditUndo));
        actionVolver->setIcon(icon2);
        centralwidget = new QWidget(alta_de_alumnos);
        centralwidget->setObjectName("centralwidget");
        confirmarAltaAlumno = new QPushButton(centralwidget);
        confirmarAltaAlumno->setObjectName("confirmarAltaAlumno");
        confirmarAltaAlumno->setGeometry(QRect(540, 200, 151, 41));
        QFont font;
        font.setBold(true);
        confirmarAltaAlumno->setFont(font);
        confirmarAltaAlumno->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(222, 221, 218);\n"
"border-radius: 20px;"));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::ListAdd));
        confirmarAltaAlumno->setIcon(icon3);
        labelContextoAlu = new QLabel(centralwidget);
        labelContextoAlu->setObjectName("labelContextoAlu");
        labelContextoAlu->setGeometry(QRect(540, 110, 151, 71));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        labelContextoAlu->setFont(font1);
        labelContextoAlu->setStyleSheet(QString::fromUtf8("color: rgb(198, 70, 0);\n"
"background-color: rgb(255, 190, 111);\n"
"border-radius: 25px;\n"
"padding-left: 10px;"));
        labelContextoAlu->setFrameShape(QFrame::Shape::NoFrame);
        labelContextoAlu->setLineWidth(1);
        labelContextoAlu->setMidLineWidth(0);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(20, 130, 201, 151));
        camposAlumno = new QVBoxLayout(verticalLayoutWidget);
        camposAlumno->setSpacing(20);
        camposAlumno->setObjectName("camposAlumno");
        camposAlumno->setContentsMargins(0, 0, 0, 0);
        label_NomAlu = new QLabel(verticalLayoutWidget);
        label_NomAlu->setObjectName("label_NomAlu");
        label_NomAlu->setFont(font1);
        label_NomAlu->setStyleSheet(QString::fromUtf8("color: rgb(98, 160, 234);"));

        camposAlumno->addWidget(label_NomAlu);

        label_ApeAlu = new QLabel(verticalLayoutWidget);
        label_ApeAlu->setObjectName("label_ApeAlu");
        label_ApeAlu->setFont(font1);
        label_ApeAlu->setStyleSheet(QString::fromUtf8("color: rgb(98, 160, 234);"));

        camposAlumno->addWidget(label_ApeAlu);

        label_EdadAlu = new QLabel(verticalLayoutWidget);
        label_EdadAlu->setObjectName("label_EdadAlu");
        label_EdadAlu->setFont(font1);
        label_EdadAlu->setStyleSheet(QString::fromUtf8("color: rgb(98, 160, 234);"));

        camposAlumno->addWidget(label_EdadAlu);

        labelFondo1 = new QLabel(centralwidget);
        labelFondo1->setObjectName("labelFondo1");
        labelFondo1->setGeometry(QRect(10, 110, 501, 191));
        labelFondo1->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 246, 255);"));
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(230, 130, 261, 151));
        completarCamposAlumno = new QVBoxLayout(verticalLayoutWidget_2);
        completarCamposAlumno->setSpacing(30);
        completarCamposAlumno->setObjectName("completarCamposAlumno");
        completarCamposAlumno->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        completarCamposAlumno->setContentsMargins(0, 0, 0, 0);
        lEdit_NombreAlu = new QLineEdit(verticalLayoutWidget_2);
        lEdit_NombreAlu->setObjectName("lEdit_NombreAlu");
        lEdit_NombreAlu->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        completarCamposAlumno->addWidget(lEdit_NombreAlu);

        lEdit_ApellidoAlu = new QLineEdit(verticalLayoutWidget_2);
        lEdit_ApellidoAlu->setObjectName("lEdit_ApellidoAlu");
        lEdit_ApellidoAlu->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        completarCamposAlumno->addWidget(lEdit_ApellidoAlu);

        sBox_EdadAlumno = new QSpinBox(verticalLayoutWidget_2);
        sBox_EdadAlumno->setObjectName("sBox_EdadAlumno");
        sBox_EdadAlumno->setEnabled(true);
        sBox_EdadAlumno->setFont(font1);
        sBox_EdadAlumno->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        sBox_EdadAlumno->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        sBox_EdadAlumno->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        sBox_EdadAlumno->setReadOnly(false);
        sBox_EdadAlumno->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::UpDownArrows);
        sBox_EdadAlumno->setCorrectionMode(QAbstractSpinBox::CorrectionMode::CorrectToNearestValue);
        sBox_EdadAlumno->setProperty("showGroupSeparator", QVariant(false));
        sBox_EdadAlumno->setMinimum(13);
        sBox_EdadAlumno->setMaximum(20);
        sBox_EdadAlumno->setDisplayIntegerBase(10);

        completarCamposAlumno->addWidget(sBox_EdadAlumno);

        label_cargoUsuario = new QLabel(centralwidget);
        label_cargoUsuario->setObjectName("label_cargoUsuario");
        label_cargoUsuario->setGeometry(QRect(560, 20, 221, 61));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        label_cargoUsuario->setFont(font2);
        label_cargoUsuario->setStyleSheet(QString::fromUtf8("color: rgb(53, 132, 228);"));
        label_cargoUsuario->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        label_cargoUsuario->setWordWrap(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(290, 50, 121, 31));
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(53, 132, 228);"));
        label_2->setWordWrap(true);
        label_nombreUsuario = new QLabel(centralwidget);
        label_nombreUsuario->setObjectName("label_nombreUsuario");
        label_nombreUsuario->setGeometry(QRect(200, 20, 331, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Ubuntu")});
        font3.setPointSize(20);
        font3.setBold(true);
        label_nombreUsuario->setFont(font3);
        label_nombreUsuario->setStyleSheet(QString::fromUtf8("color: rgb(153, 193, 241);"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(200, 50, 41, 31));
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("color: rgb(53, 132, 228);"));
        label->setWordWrap(true);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(-10, 0, 841, 91));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 113, 216);"));
        label_idUsuario = new QLabel(centralwidget);
        label_idUsuario->setObjectName("label_idUsuario");
        label_idUsuario->setGeometry(QRect(240, 50, 31, 31));
        label_idUsuario->setFont(font2);
        label_idUsuario->setStyleSheet(QString::fromUtf8("color: rgb(53, 132, 228);"));
        label_idUsuario->setWordWrap(true);
        label_idCurso = new QLabel(centralwidget);
        label_idCurso->setObjectName("label_idCurso");
        label_idCurso->setGeometry(QRect(410, 50, 31, 31));
        label_idCurso->setFont(font2);
        label_idCurso->setStyleSheet(QString::fromUtf8("color: rgb(53, 132, 228);"));
        label_idCurso->setWordWrap(true);
        alta_de_alumnos->setCentralWidget(centralwidget);
        label_4->raise();
        label_2->raise();
        labelFondo1->raise();
        confirmarAltaAlumno->raise();
        labelContextoAlu->raise();
        verticalLayoutWidget->raise();
        verticalLayoutWidget_2->raise();
        label_cargoUsuario->raise();
        label_idCurso->raise();
        label_idUsuario->raise();
        label_nombreUsuario->raise();
        label->raise();
        menubar = new QMenuBar(alta_de_alumnos);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 29));
        QFont font4;
        font4.setPointSize(15);
        font4.setWeight(QFont::Medium);
        menubar->setFont(font4);
        menubar->setStyleSheet(QString::fromUtf8("color: rgb(255, 120, 0);\n"
"alternate-background-color: rgb(255, 190, 111);\n"
"selection-background-color: rgb(255, 190, 111);"));
        menuOpciones = new QMenu(menubar);
        menuOpciones->setObjectName("menuOpciones");
        QFont font5;
        font5.setPointSize(13);
        menuOpciones->setFont(font5);
        menuOpciones->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(0, 0, 0);\n"
"selection-color: rgb(0, 0, 0);\n"
"color: rgb(0, 0, 0);"));
        alta_de_alumnos->setMenuBar(menubar);
        statusbar = new QStatusBar(alta_de_alumnos);
        statusbar->setObjectName("statusbar");
        alta_de_alumnos->setStatusBar(statusbar);

        menubar->addAction(menuOpciones->menuAction());
        menuOpciones->addAction(actionCambiar_cuenta);
        menuOpciones->addSeparator();
        menuOpciones->addAction(actionVolver);
        menuOpciones->addSeparator();
        menuOpciones->addAction(actionSalir);

        retranslateUi(alta_de_alumnos);

        QMetaObject::connectSlotsByName(alta_de_alumnos);
    } // setupUi

    void retranslateUi(QMainWindow *alta_de_alumnos)
    {
        alta_de_alumnos->setWindowTitle(QCoreApplication::translate("alta_de_alumnos", "MainWindow", nullptr));
        actionCambiar_cuenta->setText(QCoreApplication::translate("alta_de_alumnos", "   Cambiar cuenta", nullptr));
        actionSalir->setText(QCoreApplication::translate("alta_de_alumnos", "   Salir", nullptr));
        actionAlta->setText(QCoreApplication::translate("alta_de_alumnos", "Alta", nullptr));
        actionBaja->setText(QCoreApplication::translate("alta_de_alumnos", "Baja", nullptr));
        actionModificacion->setText(QCoreApplication::translate("alta_de_alumnos", "Modificaci\303\263n", nullptr));
        actionListado->setText(QCoreApplication::translate("alta_de_alumnos", "Listado", nullptr));
        actionRegistro_de_asistencias->setText(QCoreApplication::translate("alta_de_alumnos", "Registro de asistencias", nullptr));
        actionMotivos_de_faltas->setText(QCoreApplication::translate("alta_de_alumnos", "Motivos de faltas", nullptr));
        actionRegistro_de_asistencias_2->setText(QCoreApplication::translate("alta_de_alumnos", "Registro de asistencias", nullptr));
        actionReuniones->setText(QCoreApplication::translate("alta_de_alumnos", "Reuniones", nullptr));
        actionVolver->setText(QCoreApplication::translate("alta_de_alumnos", "   Volver", nullptr));
        confirmarAltaAlumno->setText(QCoreApplication::translate("alta_de_alumnos", "   CONFIRMAR", nullptr));
        labelContextoAlu->setText(QCoreApplication::translate("alta_de_alumnos", "DATOS DEL\n"
"ALUMNO", nullptr));
        label_NomAlu->setText(QCoreApplication::translate("alta_de_alumnos", "Nombre del alumno:", nullptr));
        label_ApeAlu->setText(QCoreApplication::translate("alta_de_alumnos", "Apellido del alumno:", nullptr));
        label_EdadAlu->setText(QCoreApplication::translate("alta_de_alumnos", "Edad del alumno:", nullptr));
        labelFondo1->setText(QString());
        sBox_EdadAlumno->setSuffix(QString());
        label_cargoUsuario->setText(QCoreApplication::translate("alta_de_alumnos", "<html><head/><body><p><span style=\" color:#ffffff;\">Preceptor / DOE</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("alta_de_alumnos", "<html><head/><body><p><span style=\" color:#ffffff;\">ID Curso:</span></p></body></html>", nullptr));
        label_nombreUsuario->setText(QCoreApplication::translate("alta_de_alumnos", "<html><head/><body><p><span style=\" color:#99c1f1;\">Nombre completo</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("alta_de_alumnos", "<html><head/><body><p><span style=\" color:#ffffff;\">ID:</span></p></body></html>", nullptr));
        label_4->setText(QString());
        label_idUsuario->setText(QCoreApplication::translate("alta_de_alumnos", "<html><head/><body><p><span style=\" color:#99c1f1;\">0</span></p></body></html>", nullptr));
        label_idCurso->setText(QCoreApplication::translate("alta_de_alumnos", "<html><head/><body><p><span style=\" color:#99c1f1;\">0</span></p></body></html>", nullptr));
        menuOpciones->setTitle(QCoreApplication::translate("alta_de_alumnos", "Opciones", nullptr));
    } // retranslateUi

};

namespace Ui {
    class alta_de_alumnos: public Ui_alta_de_alumnos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALTA_DE_ALUMNOS_H
