/********************************************************************************
** Form generated from reading UI file 'listado_de_alumnos.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTADO_DE_ALUMNOS_H
#define UI_LISTADO_DE_ALUMNOS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_listado_de_alumnos
{
public:
    QAction *actionCambiar_cuenta;
    QAction *actionVolver;
    QAction *actionSalir;
    QWidget *centralwidget;
    QLineEdit *lEdit_barraBusqueda;
    QLabel *label_tituloVentana;
    QLabel *label_ordenamientoListado;
    QTableView *tableView;
    QLabel *label_ayudaBarraBus;
    QComboBox *comboBoxOrdAscDesc;
    QComboBox *comboBoxOrdenamiento;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_ordenamientoListado_2;
    QMenuBar *menubar;
    QMenu *menuOpciones;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *listado_de_alumnos)
    {
        if (listado_de_alumnos->objectName().isEmpty())
            listado_de_alumnos->setObjectName("listado_de_alumnos");
        listado_de_alumnos->resize(900, 600);
        actionCambiar_cuenta = new QAction(listado_de_alumnos);
        actionCambiar_cuenta->setObjectName("actionCambiar_cuenta");
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("x-office-address-book")));
        actionCambiar_cuenta->setIcon(icon);
        actionVolver = new QAction(listado_de_alumnos);
        actionVolver->setObjectName("actionVolver");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::EditUndo));
        actionVolver->setIcon(icon1);
        actionSalir = new QAction(listado_de_alumnos);
        actionSalir->setObjectName("actionSalir");
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        actionSalir->setIcon(icon2);
        centralwidget = new QWidget(listado_de_alumnos);
        centralwidget->setObjectName("centralwidget");
        lEdit_barraBusqueda = new QLineEdit(centralwidget);
        lEdit_barraBusqueda->setObjectName("lEdit_barraBusqueda");
        lEdit_barraBusqueda->setGeometry(QRect(400, 20, 441, 26));
        lEdit_barraBusqueda->setStyleSheet(QString::fromUtf8("color: rgb(6, 22, 40);"));
        lEdit_barraBusqueda->setFrame(true);
        label_tituloVentana = new QLabel(centralwidget);
        label_tituloVentana->setObjectName("label_tituloVentana");
        label_tituloVentana->setGeometry(QRect(220, 20, 241, 61));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        label_tituloVentana->setFont(font);
        label_tituloVentana->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        label_tituloVentana->setWordWrap(true);
        label_ordenamientoListado = new QLabel(centralwidget);
        label_ordenamientoListado->setObjectName("label_ordenamientoListado");
        label_ordenamientoListado->setGeometry(QRect(220, 110, 131, 31));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setItalic(true);
        label_ordenamientoListado->setFont(font1);
        label_ordenamientoListado->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(220, 160, 621, 381));
        label_ayudaBarraBus = new QLabel(centralwidget);
        label_ayudaBarraBus->setObjectName("label_ayudaBarraBus");
        label_ayudaBarraBus->setGeometry(QRect(400, 60, 221, 20));
        QFont font2;
        font2.setPointSize(12);
        font2.setItalic(true);
        label_ayudaBarraBus->setFont(font2);
        comboBoxOrdAscDesc = new QComboBox(centralwidget);
        comboBoxOrdAscDesc->setObjectName("comboBoxOrdAscDesc");
        comboBoxOrdAscDesc->setGeometry(QRect(660, 110, 181, 26));
        comboBoxOrdAscDesc->setStyleSheet(QString::fromUtf8("color: rgb(198, 70, 0);"));
        comboBoxOrdenamiento = new QComboBox(centralwidget);
        comboBoxOrdenamiento->setObjectName("comboBoxOrdenamiento");
        comboBoxOrdenamiento->setGeometry(QRect(370, 110, 181, 26));
        comboBoxOrdenamiento->setStyleSheet(QString::fromUtf8("color: rgb(198, 70, 0);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, -40, 16, 591));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 132, 228);"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(-5, -13, 61, 591));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 209, 122);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, -20, 31, 591));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 120, 0);"));
        label_ordenamientoListado_2 = new QLabel(centralwidget);
        label_ordenamientoListado_2->setObjectName("label_ordenamientoListado_2");
        label_ordenamientoListado_2->setGeometry(QRect(562, 110, 91, 31));
        label_ordenamientoListado_2->setFont(font1);
        label_ordenamientoListado_2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        listado_de_alumnos->setCentralWidget(centralwidget);
        menubar = new QMenuBar(listado_de_alumnos);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 900, 29));
        QFont font3;
        font3.setPointSize(15);
        font3.setWeight(QFont::Medium);
        menubar->setFont(font3);
        menubar->setStyleSheet(QString::fromUtf8("color: rgb(255, 120, 0);\n"
"alternate-background-color: rgb(255, 190, 111);\n"
"selection-background-color: rgb(255, 190, 111);"));
        menuOpciones = new QMenu(menubar);
        menuOpciones->setObjectName("menuOpciones");
        QFont font4;
        font4.setPointSize(13);
        menuOpciones->setFont(font4);
        menuOpciones->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(0, 0, 0);\n"
"selection-color: rgb(0, 0, 0);\n"
"color: rgb(0, 0, 0);"));
        listado_de_alumnos->setMenuBar(menubar);
        statusbar = new QStatusBar(listado_de_alumnos);
        statusbar->setObjectName("statusbar");
        listado_de_alumnos->setStatusBar(statusbar);

        menubar->addAction(menuOpciones->menuAction());
        menuOpciones->addAction(actionCambiar_cuenta);
        menuOpciones->addSeparator();
        menuOpciones->addAction(actionVolver);
        menuOpciones->addSeparator();
        menuOpciones->addAction(actionSalir);

        retranslateUi(listado_de_alumnos);

        QMetaObject::connectSlotsByName(listado_de_alumnos);
    } // setupUi

    void retranslateUi(QMainWindow *listado_de_alumnos)
    {
        listado_de_alumnos->setWindowTitle(QCoreApplication::translate("listado_de_alumnos", "MainWindow", nullptr));
        actionCambiar_cuenta->setText(QCoreApplication::translate("listado_de_alumnos", "   Cambiar cuenta", nullptr));
        actionVolver->setText(QCoreApplication::translate("listado_de_alumnos", "   Volver", nullptr));
        actionSalir->setText(QCoreApplication::translate("listado_de_alumnos", "   Salir", nullptr));
        label_tituloVentana->setText(QCoreApplication::translate("listado_de_alumnos", "<html><head/><body><p><span style=\" color:#061628;\">LISTADO DE ALUMNOS</span></p></body></html>", nullptr));
        label_ordenamientoListado->setText(QCoreApplication::translate("listado_de_alumnos", "<html><head/><body><p><span style=\" color:#c64600;\">Ordenar por...</span></p></body></html>", nullptr));
        label_ayudaBarraBus->setText(QCoreApplication::translate("listado_de_alumnos", "<html><head/><body><p><span style=\" color:#728ead;\">Barra de b\303\272squeda de alumnos</span></p></body></html>", nullptr));
        label_3->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
        label_ordenamientoListado_2->setText(QCoreApplication::translate("listado_de_alumnos", "<html><head/><body><p><span style=\" color:#c64600;\">Asc/Desc</span></p></body></html>", nullptr));
        menuOpciones->setTitle(QCoreApplication::translate("listado_de_alumnos", "Opciones", nullptr));
    } // retranslateUi

};

namespace Ui {
    class listado_de_alumnos: public Ui_listado_de_alumnos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTADO_DE_ALUMNOS_H
