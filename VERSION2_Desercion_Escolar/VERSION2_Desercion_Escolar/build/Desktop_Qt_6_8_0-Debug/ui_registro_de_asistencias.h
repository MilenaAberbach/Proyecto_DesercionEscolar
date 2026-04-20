/********************************************************************************
** Form generated from reading UI file 'registro_de_asistencias.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRO_DE_ASISTENCIAS_H
#define UI_REGISTRO_DE_ASISTENCIAS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registro_de_asistencias
{
public:
    QAction *actionCambiar_cuenta;
    QAction *actionVolver;
    QAction *actionSalir;
    QWidget *centralwidget;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label;
    QComboBox *comboSemana;
    QLabel *label_4;
    QLabel *label_2;
    QPushButton *btnGuardar;
    QTableWidget *tablaAsistencias;
    QMenuBar *menubar;
    QMenu *menuOpciones;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *registro_de_asistencias)
    {
        if (registro_de_asistencias->objectName().isEmpty())
            registro_de_asistencias->setObjectName("registro_de_asistencias");
        registro_de_asistencias->resize(950, 711);
        actionCambiar_cuenta = new QAction(registro_de_asistencias);
        actionCambiar_cuenta->setObjectName("actionCambiar_cuenta");
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("x-office-address-book")));
        actionCambiar_cuenta->setIcon(icon);
        actionVolver = new QAction(registro_de_asistencias);
        actionVolver->setObjectName("actionVolver");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::EditUndo));
        actionVolver->setIcon(icon1);
        actionSalir = new QAction(registro_de_asistencias);
        actionSalir->setObjectName("actionSalir");
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        actionSalir->setIcon(icon2);
        centralwidget = new QWidget(registro_de_asistencias);
        centralwidget->setObjectName("centralwidget");
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 130, 151, 21));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        label_5->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(-5, 41, 1111, 20));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 209, 122);"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(-5, 1, 1111, 20));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 120, 0);"));
        comboSemana = new QComboBox(centralwidget);
        comboSemana->setObjectName("comboSemana");
        comboSemana->setGeometry(QRect(200, 125, 291, 31));
        comboSemana->setStyleSheet(QString::fromUtf8("color: rgb(230, 97, 0);\n"
"alternate-background-color: rgb(222, 229, 243);\n"
"selection-background-color: rgb(222, 229, 243);"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(280, 10, 400, 41));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("border-radius: 20px;\n"
"background-color: rgb(222, 229, 243);"));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(-5, 21, 1131, 20));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 132, 228);"));
        btnGuardar = new QPushButton(centralwidget);
        btnGuardar->setObjectName("btnGuardar");
        btnGuardar->setGeometry(QRect(20, 610, 901, 41));
        btnGuardar->setFont(font);
        btnGuardar->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);\n"
"border-radius: 15px;"));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave));
        btnGuardar->setIcon(icon3);
        tablaAsistencias = new QTableWidget(centralwidget);
        tablaAsistencias->setObjectName("tablaAsistencias");
        tablaAsistencias->setGeometry(QRect(20, 180, 901, 411));
        registro_de_asistencias->setCentralWidget(centralwidget);
        comboSemana->raise();
        btnGuardar->raise();
        label_2->raise();
        label_5->raise();
        label_3->raise();
        label->raise();
        tablaAsistencias->raise();
        label_4->raise();
        menubar = new QMenuBar(registro_de_asistencias);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 950, 29));
        QFont font2;
        font2.setPointSize(15);
        font2.setWeight(QFont::Medium);
        menubar->setFont(font2);
        menubar->setStyleSheet(QString::fromUtf8("color: rgb(255, 120, 0);\n"
"alternate-background-color: rgb(255, 190, 111);\n"
"selection-background-color: rgb(255, 190, 111);"));
        menuOpciones = new QMenu(menubar);
        menuOpciones->setObjectName("menuOpciones");
        QFont font3;
        font3.setPointSize(13);
        menuOpciones->setFont(font3);
        menuOpciones->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(0, 0, 0);\n"
"selection-color: rgb(0, 0, 0);\n"
"color: rgb(0, 0, 0);"));
        registro_de_asistencias->setMenuBar(menubar);
        statusbar = new QStatusBar(registro_de_asistencias);
        statusbar->setObjectName("statusbar");
        registro_de_asistencias->setStatusBar(statusbar);

        menubar->addAction(menuOpciones->menuAction());
        menuOpciones->addAction(actionCambiar_cuenta);
        menuOpciones->addSeparator();
        menuOpciones->addAction(actionVolver);
        menuOpciones->addSeparator();
        menuOpciones->addAction(actionSalir);

        retranslateUi(registro_de_asistencias);

        QMetaObject::connectSlotsByName(registro_de_asistencias);
    } // setupUi

    void retranslateUi(QMainWindow *registro_de_asistencias)
    {
        registro_de_asistencias->setWindowTitle(QCoreApplication::translate("registro_de_asistencias", "MainWindow", nullptr));
        actionCambiar_cuenta->setText(QCoreApplication::translate("registro_de_asistencias", "   Cambiar cuenta", nullptr));
        actionVolver->setText(QCoreApplication::translate("registro_de_asistencias", "   Volver", nullptr));
        actionSalir->setText(QCoreApplication::translate("registro_de_asistencias", "   Salir", nullptr));
        label_5->setText(QCoreApplication::translate("registro_de_asistencias", "<html><head/><body><p><span style=\" color:#061628;\">N\302\260 DE SEMANA:</span></p></body></html>", nullptr));
        label_3->setText(QString());
        label->setText(QString());
        label_4->setText(QCoreApplication::translate("registro_de_asistencias", "REGISTRO DE ASISTENCIAS", nullptr));
        label_2->setText(QString());
        btnGuardar->setText(QCoreApplication::translate("registro_de_asistencias", "   GUARDAR", nullptr));
        menuOpciones->setTitle(QCoreApplication::translate("registro_de_asistencias", "Opciones", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registro_de_asistencias: public Ui_registro_de_asistencias {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRO_DE_ASISTENCIAS_H
