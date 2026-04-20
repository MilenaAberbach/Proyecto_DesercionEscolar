/********************************************************************************
** Form generated from reading UI file 'menu_herramientas.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_HERRAMIENTAS_H
#define UI_MENU_HERRAMIENTAS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menu_herramientas
{
public:
    QAction *actionCambiarCuenta;
    QAction *actionSalir;
    QAction *actionAlta;
    QAction *actionBaja;
    QAction *actionModificacion;
    QAction *actionListado;
    QAction *actionRegistro_de_asistencias;
    QAction *actionResumen_asistencias_faltas;
    QAction *actionPosibles_abandonantes;
    QAction *actionReuniones;
    QWidget *centralwidget;
    QLabel *label_nombreUsuario;
    QLabel *label_3;
    QFrame *line;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_cargoUsuario;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_degrade;
    QLabel *label_fondo;
    QLabel *label_degrade_2;
    QLabel *label_5;
    QMenuBar *menubar;
    QMenu *menuOpciones;
    QMenu *menuABML;
    QMenu *menuAsistencias;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *menu_herramientas)
    {
        if (menu_herramientas->objectName().isEmpty())
            menu_herramientas->setObjectName("menu_herramientas");
        menu_herramientas->resize(900, 520);
        QFont font;
        font.setBold(false);
        menu_herramientas->setFont(font);
        actionCambiarCuenta = new QAction(menu_herramientas);
        actionCambiarCuenta->setObjectName("actionCambiarCuenta");
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("x-office-address-book")));
        actionCambiarCuenta->setIcon(icon);
        actionSalir = new QAction(menu_herramientas);
        actionSalir->setObjectName("actionSalir");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        actionSalir->setIcon(icon1);
        actionAlta = new QAction(menu_herramientas);
        actionAlta->setObjectName("actionAlta");
        actionAlta->setEnabled(true);
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::ListAdd));
        actionAlta->setIcon(icon2);
        actionBaja = new QAction(menu_herramientas);
        actionBaja->setObjectName("actionBaja");
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::DialogError));
        actionBaja->setIcon(icon3);
        actionModificacion = new QAction(menu_herramientas);
        actionModificacion->setObjectName("actionModificacion");
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::EditCut));
        actionModificacion->setIcon(icon4);
        actionListado = new QAction(menu_herramientas);
        actionListado->setObjectName("actionListado");
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen));
        actionListado->setIcon(icon5);
        actionRegistro_de_asistencias = new QAction(menu_herramientas);
        actionRegistro_de_asistencias->setObjectName("actionRegistro_de_asistencias");
        QIcon icon6(QIcon::fromTheme(QString::fromUtf8("accessories-text-editor")));
        actionRegistro_de_asistencias->setIcon(icon6);
        actionResumen_asistencias_faltas = new QAction(menu_herramientas);
        actionResumen_asistencias_faltas->setObjectName("actionResumen_asistencias_faltas");
        QIcon icon7(QIcon::fromTheme(QString::fromUtf8("dialog-information")));
        actionResumen_asistencias_faltas->setIcon(icon7);
        actionPosibles_abandonantes = new QAction(menu_herramientas);
        actionPosibles_abandonantes->setObjectName("actionPosibles_abandonantes");
        QIcon icon8(QIcon::fromTheme(QString::fromUtf8("dialog-warning")));
        actionPosibles_abandonantes->setIcon(icon8);
        actionReuniones = new QAction(menu_herramientas);
        actionReuniones->setObjectName("actionReuniones");
        QIcon icon9(QIcon::fromTheme(QString::fromUtf8("phone")));
        actionReuniones->setIcon(icon9);
        centralwidget = new QWidget(menu_herramientas);
        centralwidget->setObjectName("centralwidget");
        label_nombreUsuario = new QLabel(centralwidget);
        label_nombreUsuario->setObjectName("label_nombreUsuario");
        label_nombreUsuario->setGeometry(QRect(530, 30, 441, 31));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        label_nombreUsuario->setFont(font1);
        label_nombreUsuario->setStyleSheet(QString::fromUtf8("color: rgb(255, 120, 0);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(530, 67, 311, 21));
        QFont font2;
        font2.setPointSize(16);
        font2.setWeight(QFont::DemiBold);
        label_3->setFont(font2);
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 50, 521, 16));
        line->setStyleSheet(QString::fromUtf8("color: rgb(198, 70, 0);"));
        line->setFrameShadow(QFrame::Shadow::Plain);
        line->setLineWidth(3);
        line->setFrameShape(QFrame::Shape::HLine);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(530, 130, 281, 311));
        QFont font3;
        font3.setPointSize(16);
        font3.setBold(false);
        label_2->setFont(font3);
        label_2->setTextFormat(Qt::TextFormat::RichText);
        label_2->setScaledContents(false);
        label_2->setAlignment(Qt::AlignmentFlag::AlignJustify|Qt::AlignmentFlag::AlignTop);
        label_2->setWordWrap(true);
        label_2->setMargin(0);
        label_2->setOpenExternalLinks(false);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 130, 81, 41));
        QFont font4;
        font4.setPointSize(20);
        font4.setWeight(QFont::DemiBold);
        label_4->setFont(font4);
        label_cargoUsuario = new QLabel(centralwidget);
        label_cargoUsuario->setObjectName("label_cargoUsuario");
        label_cargoUsuario->setGeometry(QRect(130, 130, 271, 41));
        QFont font5;
        font5.setPointSize(20);
        font5.setBold(true);
        label_cargoUsuario->setFont(font5);
        label_cargoUsuario->setStyleSheet(QString::fromUtf8("color: rgb(53, 132, 228);"));
        label_cargoUsuario->setWordWrap(true);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(30, 200, 100, 100));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/logos/IMAGENES/iconoDeAlta.png")));
        label_6->setScaledContents(true);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(150, 200, 100, 100));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/logos/IMAGENES/iconoDeBaja.png")));
        label_7->setScaledContents(true);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(250, 190, 120, 120));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/logos/IMAGENES/iconoDeModificacion.png")));
        label_8->setScaledContents(true);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(370, 200, 101, 91));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/logos/IMAGENES/iconoDeListado.png")));
        label_9->setScaledContents(true);
        label_degrade = new QLabel(centralwidget);
        label_degrade->setObjectName("label_degrade");
        label_degrade->setGeometry(QRect(0, -150, 1041, 721));
        label_degrade->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0.485, y1:0, x2:0.48, y2:1, stop:0 rgba(255, 255, 255, 172), stop:1 rgba(255, 255, 255, 173));"));
        label_fondo = new QLabel(centralwidget);
        label_fondo->setObjectName("label_fondo");
        label_fondo->setGeometry(QRect(0, 0, 1021, 581));
        label_fondo->setPixmap(QPixmap(QString::fromUtf8(":/logos/IMAGENES/fondito_preceptores.jpg")));
        label_fondo->setScaledContents(true);
        label_degrade_2 = new QLabel(centralwidget);
        label_degrade_2->setObjectName("label_degrade_2");
        label_degrade_2->setGeometry(QRect(0, 260, 1041, 461));
        label_degrade_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0.515, y1:1, x2:0.435, y2:0, stop:0 rgba(61, 56, 70, 173), stop:1 rgba(255, 255, 255, 0));"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 120, 461, 61));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(153, 193, 241);\n"
"border-radius: 30px;"));
        menu_herramientas->setCentralWidget(centralwidget);
        label_fondo->raise();
        label_degrade->raise();
        label_nombreUsuario->raise();
        label_3->raise();
        line->raise();
        label_2->raise();
        label_6->raise();
        label_7->raise();
        label_5->raise();
        label_cargoUsuario->raise();
        label_4->raise();
        label_8->raise();
        label_degrade_2->raise();
        label_9->raise();
        menubar = new QMenuBar(menu_herramientas);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 900, 29));
        QFont font6;
        font6.setPointSize(15);
        font6.setBold(false);
        menubar->setFont(font6);
        menubar->setStyleSheet(QString::fromUtf8("color: rgb(255, 120, 0);\n"
"alternate-background-color: rgb(255, 190, 111);\n"
"selection-background-color: rgb(255, 190, 111);"));
        menuOpciones = new QMenu(menubar);
        menuOpciones->setObjectName("menuOpciones");
        QFont font7;
        font7.setPointSize(13);
        menuOpciones->setFont(font7);
        menuOpciones->setStyleSheet(QString::fromUtf8("selection-color: rgb(0, 0, 0);\n"
"color: rgb(0, 0, 0);"));
        menuABML = new QMenu(menubar);
        menuABML->setObjectName("menuABML");
        menuABML->setFont(font7);
        menuABML->setStyleSheet(QString::fromUtf8("selection-color: rgb(0, 0, 0);\n"
"color: rgb(0, 0, 0);"));
        menuAsistencias = new QMenu(menubar);
        menuAsistencias->setObjectName("menuAsistencias");
        menuAsistencias->setFont(font7);
        menuAsistencias->setStyleSheet(QString::fromUtf8("selection-color: rgb(0, 0, 0);\n"
"color: rgb(0, 0, 0);"));
        menu_herramientas->setMenuBar(menubar);
        statusbar = new QStatusBar(menu_herramientas);
        statusbar->setObjectName("statusbar");
        menu_herramientas->setStatusBar(statusbar);

        menubar->addAction(menuOpciones->menuAction());
        menubar->addAction(menuABML->menuAction());
        menubar->addAction(menuAsistencias->menuAction());
        menuOpciones->addAction(actionCambiarCuenta);
        menuOpciones->addSeparator();
        menuOpciones->addAction(actionSalir);
        menuABML->addAction(actionAlta);
        menuABML->addSeparator();
        menuABML->addAction(actionBaja);
        menuABML->addSeparator();
        menuABML->addAction(actionModificacion);
        menuABML->addSeparator();
        menuABML->addAction(actionListado);
        menuAsistencias->addAction(actionRegistro_de_asistencias);
        menuAsistencias->addSeparator();
        menuAsistencias->addAction(actionResumen_asistencias_faltas);
        menuAsistencias->addSeparator();
        menuAsistencias->addAction(actionPosibles_abandonantes);
        menuAsistencias->addSeparator();
        menuAsistencias->addAction(actionReuniones);

        retranslateUi(menu_herramientas);

        QMetaObject::connectSlotsByName(menu_herramientas);
    } // setupUi

    void retranslateUi(QMainWindow *menu_herramientas)
    {
        menu_herramientas->setWindowTitle(QCoreApplication::translate("menu_herramientas", "MainWindow", nullptr));
        actionCambiarCuenta->setText(QCoreApplication::translate("menu_herramientas", "   Cambiar cuenta", nullptr));
        actionSalir->setText(QCoreApplication::translate("menu_herramientas", "   Salir", nullptr));
        actionAlta->setText(QCoreApplication::translate("menu_herramientas", "   Alta", nullptr));
        actionBaja->setText(QCoreApplication::translate("menu_herramientas", "   Baja", nullptr));
        actionModificacion->setText(QCoreApplication::translate("menu_herramientas", "   Modificaci\303\263n", nullptr));
        actionListado->setText(QCoreApplication::translate("menu_herramientas", "   Listado", nullptr));
        actionRegistro_de_asistencias->setText(QCoreApplication::translate("menu_herramientas", "   Registro de asistencias", nullptr));
        actionResumen_asistencias_faltas->setText(QCoreApplication::translate("menu_herramientas", "   Resumen de asistencias y faltas", nullptr));
        actionPosibles_abandonantes->setText(QCoreApplication::translate("menu_herramientas", "  Posibles abandonantes", nullptr));
        actionReuniones->setText(QCoreApplication::translate("menu_herramientas", "   Reuniones", nullptr));
        label_nombreUsuario->setText(QCoreApplication::translate("menu_herramientas", "<html><head/><body><p><span style=\" color:#ff7800;\">Nombre completo</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("menu_herramientas", "<html><head/><body><p><span style=\" color:#823a13;\">Sea bienvenid@ a BackToLearn!</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("menu_herramientas", "<html><head/><body><p><span style=\" color:#3d3846;\">En este apartado, </span><span style=\" font-weight:700; color:#3d3846;\">dependiendo del cargo que ejerce en la escuela</span><span style=\" color:#3d3846;\">, podr\303\241 utilizar varias herramientas para </span><span style=\" font-weight:700; color:#3d3846;\">analizar el flujo de asistencias de los alumnos</span><span style=\" color:#3d3846;\">; o tambi\303\251n, ser\303\241 capaz de </span><span style=\" font-weight:700; color:#3d3846;\">darlos de alta, baja, modificar sus datos e incluso observarlos a trav\303\251s de una ventana que funciona como listado.</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("menu_herramientas", "<html><head/><body><p><span style=\" color:#1c71d8;\">Cargo:</span></p></body></html>", nullptr));
        label_cargoUsuario->setText(QCoreApplication::translate("menu_herramientas", "<html><head/><body><p><span style=\" color:#3584e4;\">Preceptor / DOE</span></p></body></html>", nullptr));
        label_6->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
        label_9->setText(QString());
        label_degrade->setText(QString());
        label_fondo->setText(QString());
        label_degrade_2->setText(QString());
        label_5->setText(QString());
        menuOpciones->setTitle(QCoreApplication::translate("menu_herramientas", "Opciones", nullptr));
        menuABML->setTitle(QCoreApplication::translate("menu_herramientas", "ABML", nullptr));
        menuAsistencias->setTitle(QCoreApplication::translate("menu_herramientas", "Asistencias", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menu_herramientas: public Ui_menu_herramientas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_HERRAMIENTAS_H
