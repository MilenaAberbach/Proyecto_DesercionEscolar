/********************************************************************************
** Form generated from reading UI file 'baja_de_alumnos.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BAJA_DE_ALUMNOS_H
#define UI_BAJA_DE_ALUMNOS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_baja_de_alumnos
{
public:
    QAction *actionCambiar_cuenta;
    QAction *actionVolver;
    QAction *actionSalir;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *camposAlumno;
    QLabel *label_NomAlu;
    QLabel *label_ApeAlu;
    QLabel *label_3;
    QPushButton *confirmarBajaAlumno;
    QLabel *labelFondo1;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *completarCamposAlumno;
    QComboBox *comboBoxAlumno;
    QLabel *label_nombreAlumno;
    QLabel *label_4;
    QLabel *label_nombreUsuario;
    QLabel *label_cargoUsuario;
    QLabel *label;
    QLabel *label_idUsuario;
    QLabel *label_2;
    QLabel *label_idCurso;
    QMenuBar *menubar;
    QMenu *menuOpciones;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *baja_de_alumnos)
    {
        if (baja_de_alumnos->objectName().isEmpty())
            baja_de_alumnos->setObjectName("baja_de_alumnos");
        baja_de_alumnos->resize(800, 391);
        actionCambiar_cuenta = new QAction(baja_de_alumnos);
        actionCambiar_cuenta->setObjectName("actionCambiar_cuenta");
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("x-office-address-book")));
        actionCambiar_cuenta->setIcon(icon);
        actionVolver = new QAction(baja_de_alumnos);
        actionVolver->setObjectName("actionVolver");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::EditUndo));
        actionVolver->setIcon(icon1);
        actionSalir = new QAction(baja_de_alumnos);
        actionSalir->setObjectName("actionSalir");
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        actionSalir->setIcon(icon2);
        centralwidget = new QWidget(baja_de_alumnos);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(200, 140, 241, 106));
        camposAlumno = new QVBoxLayout(verticalLayoutWidget);
        camposAlumno->setSpacing(20);
        camposAlumno->setObjectName("camposAlumno");
        camposAlumno->setContentsMargins(0, 0, 0, 0);
        label_NomAlu = new QLabel(verticalLayoutWidget);
        label_NomAlu->setObjectName("label_NomAlu");
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        label_NomAlu->setFont(font);
        label_NomAlu->setStyleSheet(QString::fromUtf8("color: rgb(98, 160, 234);"));

        camposAlumno->addWidget(label_NomAlu);

        label_ApeAlu = new QLabel(verticalLayoutWidget);
        label_ApeAlu->setObjectName("label_ApeAlu");
        label_ApeAlu->setFont(font);
        label_ApeAlu->setStyleSheet(QString::fromUtf8("color: rgb(98, 160, 234);"));

        camposAlumno->addWidget(label_ApeAlu);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(-10, 0, 841, 51));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 120, 0);"));
        confirmarBajaAlumno = new QPushButton(centralwidget);
        confirmarBajaAlumno->setObjectName("confirmarBajaAlumno");
        confirmarBajaAlumno->setGeometry(QRect(190, 280, 561, 41));
        QFont font1;
        font1.setBold(true);
        confirmarBajaAlumno->setFont(font1);
        confirmarBajaAlumno->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(222, 221, 218);\n"
"border-radius: 20px;"));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::DialogError));
        confirmarBajaAlumno->setIcon(icon3);
        labelFondo1 = new QLabel(centralwidget);
        labelFondo1->setObjectName("labelFondo1");
        labelFondo1->setGeometry(QRect(190, 130, 561, 121));
        labelFondo1->setStyleSheet(QString::fromUtf8("background-color: rgb(253, 229, 200);"));
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(450, 140, 291, 101));
        completarCamposAlumno = new QVBoxLayout(verticalLayoutWidget_2);
        completarCamposAlumno->setSpacing(30);
        completarCamposAlumno->setObjectName("completarCamposAlumno");
        completarCamposAlumno->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
        completarCamposAlumno->setContentsMargins(0, 0, 0, 0);
        comboBoxAlumno = new QComboBox(verticalLayoutWidget_2);
        comboBoxAlumno->setObjectName("comboBoxAlumno");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBoxAlumno->sizePolicy().hasHeightForWidth());
        comboBoxAlumno->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(15);
        comboBoxAlumno->setFont(font2);
        comboBoxAlumno->setStyleSheet(QString::fromUtf8("color: rgb(230, 97, 0);\n"
"alternate-background-color: rgb(255, 190, 111);\n"
"selection-background-color: rgb(255, 190, 111);"));

        completarCamposAlumno->addWidget(comboBoxAlumno);

        label_nombreAlumno = new QLabel(verticalLayoutWidget_2);
        label_nombreAlumno->setObjectName("label_nombreAlumno");
        label_nombreAlumno->setFont(font2);
        label_nombreAlumno->setStyleSheet(QString::fromUtf8("color: rgb(230, 97, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 15px;\n"
"padding-left: 10px;"));
        label_nombreAlumno->setFrameShape(QFrame::Shape::NoFrame);
        label_nombreAlumno->setFrameShadow(QFrame::Shadow::Plain);
        label_nombreAlumno->setLineWidth(1);
        label_nombreAlumno->setMidLineWidth(0);
        label_nombreAlumno->setWordWrap(false);

        completarCamposAlumno->addWidget(label_nombreAlumno);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(-10, 0, 841, 91));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 120, 0);"));
        label_nombreUsuario = new QLabel(centralwidget);
        label_nombreUsuario->setObjectName("label_nombreUsuario");
        label_nombreUsuario->setGeometry(QRect(200, 20, 301, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Ubuntu")});
        font3.setPointSize(20);
        font3.setBold(true);
        label_nombreUsuario->setFont(font3);
        label_nombreUsuario->setStyleSheet(QString::fromUtf8("color: rgb(53, 132, 228);"));
        label_cargoUsuario = new QLabel(centralwidget);
        label_cargoUsuario->setObjectName("label_cargoUsuario");
        label_cargoUsuario->setGeometry(QRect(550, 20, 211, 61));
        QFont font4;
        font4.setPointSize(20);
        font4.setBold(true);
        label_cargoUsuario->setFont(font4);
        label_cargoUsuario->setStyleSheet(QString::fromUtf8("color: rgb(53, 132, 228);"));
        label_cargoUsuario->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        label_cargoUsuario->setWordWrap(true);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(200, 50, 41, 31));
        label->setFont(font4);
        label->setStyleSheet(QString::fromUtf8("color: rgb(53, 132, 228);"));
        label->setWordWrap(true);
        label_idUsuario = new QLabel(centralwidget);
        label_idUsuario->setObjectName("label_idUsuario");
        label_idUsuario->setGeometry(QRect(240, 50, 31, 31));
        label_idUsuario->setFont(font4);
        label_idUsuario->setStyleSheet(QString::fromUtf8("color: rgb(53, 132, 228);"));
        label_idUsuario->setWordWrap(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(290, 50, 121, 31));
        label_2->setFont(font4);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(53, 132, 228);"));
        label_2->setWordWrap(true);
        label_idCurso = new QLabel(centralwidget);
        label_idCurso->setObjectName("label_idCurso");
        label_idCurso->setGeometry(QRect(410, 50, 31, 31));
        label_idCurso->setFont(font4);
        label_idCurso->setStyleSheet(QString::fromUtf8("color: rgb(53, 132, 228);"));
        label_idCurso->setWordWrap(true);
        baja_de_alumnos->setCentralWidget(centralwidget);
        labelFondo1->raise();
        verticalLayoutWidget->raise();
        label_3->raise();
        confirmarBajaAlumno->raise();
        verticalLayoutWidget_2->raise();
        label_4->raise();
        label_nombreUsuario->raise();
        label_cargoUsuario->raise();
        label->raise();
        label_idUsuario->raise();
        label_2->raise();
        label_idCurso->raise();
        menubar = new QMenuBar(baja_de_alumnos);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 29));
        QFont font5;
        font5.setPointSize(15);
        font5.setWeight(QFont::Medium);
        menubar->setFont(font5);
        menubar->setStyleSheet(QString::fromUtf8("color: rgb(255, 120, 0);\n"
"alternate-background-color: rgb(255, 190, 111);\n"
"selection-background-color: rgb(255, 190, 111);"));
        menuOpciones = new QMenu(menubar);
        menuOpciones->setObjectName("menuOpciones");
        QFont font6;
        font6.setPointSize(13);
        menuOpciones->setFont(font6);
        menuOpciones->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(0, 0, 0);\n"
"selection-color: rgb(0, 0, 0);\n"
"color: rgb(0, 0, 0);"));
        baja_de_alumnos->setMenuBar(menubar);
        statusbar = new QStatusBar(baja_de_alumnos);
        statusbar->setObjectName("statusbar");
        baja_de_alumnos->setStatusBar(statusbar);

        menubar->addAction(menuOpciones->menuAction());
        menuOpciones->addAction(actionCambiar_cuenta);
        menuOpciones->addSeparator();
        menuOpciones->addAction(actionVolver);
        menuOpciones->addSeparator();
        menuOpciones->addAction(actionSalir);

        retranslateUi(baja_de_alumnos);

        QMetaObject::connectSlotsByName(baja_de_alumnos);
    } // setupUi

    void retranslateUi(QMainWindow *baja_de_alumnos)
    {
        baja_de_alumnos->setWindowTitle(QCoreApplication::translate("baja_de_alumnos", "MainWindow", nullptr));
        actionCambiar_cuenta->setText(QCoreApplication::translate("baja_de_alumnos", "   Cambiar cuenta", nullptr));
        actionVolver->setText(QCoreApplication::translate("baja_de_alumnos", "   Volver", nullptr));
        actionSalir->setText(QCoreApplication::translate("baja_de_alumnos", "   Salir", nullptr));
        label_NomAlu->setText(QCoreApplication::translate("baja_de_alumnos", "<html><head/><body><p><span style=\" color:#ffa348;\">ID del alumno a eliminar: </span></p></body></html>", nullptr));
        label_ApeAlu->setText(QCoreApplication::translate("baja_de_alumnos", "<html><head/><body><p><span style=\" color:#ffa348;\">Nombre del alumno</span></p><p><span style=\" color:#ffa348;\">a eliminar: </span></p></body></html>", nullptr));
        label_3->setText(QString());
        confirmarBajaAlumno->setText(QCoreApplication::translate("baja_de_alumnos", "   CONFIRMAR", nullptr));
        labelFondo1->setText(QString());
        label_nombreAlumno->setText(QCoreApplication::translate("baja_de_alumnos", "...", nullptr));
        label_4->setText(QString());
        label_nombreUsuario->setText(QCoreApplication::translate("baja_de_alumnos", "<html><head/><body><p><span style=\" color:#ffbe6f;\">Nombre completo</span></p></body></html>", nullptr));
        label_cargoUsuario->setText(QCoreApplication::translate("baja_de_alumnos", "<html><head/><body><p><span style=\" color:#ffffff;\">Preceptor / DOE</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("baja_de_alumnos", "<html><head/><body><p><span style=\" color:#ffffff;\">ID:</span></p></body></html>", nullptr));
        label_idUsuario->setText(QCoreApplication::translate("baja_de_alumnos", "<html><head/><body><p><span style=\" color:#ffbe6f;\">0</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("baja_de_alumnos", "<html><head/><body><p><span style=\" color:#ffffff;\">ID Curso:</span></p></body></html>", nullptr));
        label_idCurso->setText(QCoreApplication::translate("baja_de_alumnos", "<html><head/><body><p><span style=\" color:#ffbe6f;\">0</span></p></body></html>", nullptr));
        menuOpciones->setTitle(QCoreApplication::translate("baja_de_alumnos", "Opciones", nullptr));
    } // retranslateUi

};

namespace Ui {
    class baja_de_alumnos: public Ui_baja_de_alumnos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BAJA_DE_ALUMNOS_H
