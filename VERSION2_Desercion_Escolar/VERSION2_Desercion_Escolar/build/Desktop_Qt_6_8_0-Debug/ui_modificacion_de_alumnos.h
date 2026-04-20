/********************************************************************************
** Form generated from reading UI file 'modificacion_de_alumnos.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFICACION_DE_ALUMNOS_H
#define UI_MODIFICACION_DE_ALUMNOS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
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

class Ui_modificacion_de_alumnos
{
public:
    QAction *actionCambiar_cuenta;
    QAction *actionVolver;
    QAction *actionSalir;
    QWidget *centralwidget;
    QLabel *label_3;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *lEdit_nombreAlu;
    QLineEdit *lEdit_apellidoAlu;
    QSpinBox *sBox_EdadAlumno;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *camposAlumno;
    QLabel *label_NomAlu;
    QLabel *label_ApeAlu;
    QCheckBox *checkBoxNombre;
    QCheckBox *checkBoxApellido;
    QCheckBox *checkBoxEdad;
    QPushButton *confirmarModificacionAlumno;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *completarCamposAlumno;
    QComboBox *comboBoxAlumno;
    QLabel *label_nombreAlumno;
    QLabel *labelFondo1;
    QLabel *label_4;
    QLabel *label_cargoUsuario;
    QLabel *label_idCurso;
    QLabel *label_2;
    QLabel *label_idUsuario;
    QLabel *label_nombreUsuario;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menuOpciones;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *modificacion_de_alumnos)
    {
        if (modificacion_de_alumnos->objectName().isEmpty())
            modificacion_de_alumnos->setObjectName("modificacion_de_alumnos");
        modificacion_de_alumnos->resize(800, 540);
        actionCambiar_cuenta = new QAction(modificacion_de_alumnos);
        actionCambiar_cuenta->setObjectName("actionCambiar_cuenta");
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("x-office-address-book")));
        actionCambiar_cuenta->setIcon(icon);
        actionVolver = new QAction(modificacion_de_alumnos);
        actionVolver->setObjectName("actionVolver");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::EditUndo));
        actionVolver->setIcon(icon1);
        actionSalir = new QAction(modificacion_de_alumnos);
        actionSalir->setObjectName("actionSalir");
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        actionSalir->setIcon(icon2);
        centralwidget = new QWidget(modificacion_de_alumnos);
        centralwidget->setObjectName("centralwidget");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 0, 800, 101));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 194, 126);"));
        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(290, 270, 321, 138));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lEdit_nombreAlu = new QLineEdit(verticalLayoutWidget_3);
        lEdit_nombreAlu->setObjectName("lEdit_nombreAlu");
        QFont font;
        font.setPointSize(15);
        lEdit_nombreAlu->setFont(font);

        verticalLayout->addWidget(lEdit_nombreAlu);

        lEdit_apellidoAlu = new QLineEdit(verticalLayoutWidget_3);
        lEdit_apellidoAlu->setObjectName("lEdit_apellidoAlu");
        lEdit_apellidoAlu->setFont(font);

        verticalLayout->addWidget(lEdit_apellidoAlu);

        sBox_EdadAlumno = new QSpinBox(verticalLayoutWidget_3);
        sBox_EdadAlumno->setObjectName("sBox_EdadAlumno");
        sBox_EdadAlumno->setEnabled(true);
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
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

        verticalLayout->addWidget(sBox_EdadAlumno);

        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(91, 141, 251, 261));
        camposAlumno = new QVBoxLayout(verticalLayoutWidget);
        camposAlumno->setSpacing(20);
        camposAlumno->setObjectName("camposAlumno");
        camposAlumno->setContentsMargins(0, 0, 0, 0);
        label_NomAlu = new QLabel(verticalLayoutWidget);
        label_NomAlu->setObjectName("label_NomAlu");
        label_NomAlu->setFont(font1);
        label_NomAlu->setStyleSheet(QString::fromUtf8("color: rgb(46, 194, 126);"));

        camposAlumno->addWidget(label_NomAlu);

        label_ApeAlu = new QLabel(verticalLayoutWidget);
        label_ApeAlu->setObjectName("label_ApeAlu");
        label_ApeAlu->setFont(font1);
        label_ApeAlu->setStyleSheet(QString::fromUtf8("color: rgb(98, 160, 234);"));

        camposAlumno->addWidget(label_ApeAlu);

        checkBoxNombre = new QCheckBox(verticalLayoutWidget);
        checkBoxNombre->setObjectName("checkBoxNombre");
        checkBoxNombre->setFont(font1);
        checkBoxNombre->setStyleSheet(QString::fromUtf8("color: rgb(46, 194, 126);"));

        camposAlumno->addWidget(checkBoxNombre);

        checkBoxApellido = new QCheckBox(verticalLayoutWidget);
        checkBoxApellido->setObjectName("checkBoxApellido");
        checkBoxApellido->setFont(font1);
        checkBoxApellido->setStyleSheet(QString::fromUtf8("color: rgb(46, 194, 126);"));

        camposAlumno->addWidget(checkBoxApellido);

        checkBoxEdad = new QCheckBox(verticalLayoutWidget);
        checkBoxEdad->setObjectName("checkBoxEdad");
        checkBoxEdad->setFont(font1);
        checkBoxEdad->setStyleSheet(QString::fromUtf8("color: rgb(46, 194, 126);"));

        camposAlumno->addWidget(checkBoxEdad);

        confirmarModificacionAlumno = new QPushButton(centralwidget);
        confirmarModificacionAlumno->setObjectName("confirmarModificacionAlumno");
        confirmarModificacionAlumno->setGeometry(QRect(71, 440, 571, 41));
        QFont font2;
        font2.setBold(true);
        confirmarModificacionAlumno->setFont(font2);
        confirmarModificacionAlumno->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(222, 221, 218);\n"
"border-radius: 20px;"));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::ToolsCheckSpelling));
        confirmarModificacionAlumno->setIcon(icon3);
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(341, 141, 271, 101));
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
        comboBoxAlumno->setFont(font);
        comboBoxAlumno->setStyleSheet(QString::fromUtf8("color: rgb(38, 162, 105);\n"
"alternate-background-color: rgb(143, 240, 164);\n"
"selection-background-color: rgb(143, 240, 164);"));

        completarCamposAlumno->addWidget(comboBoxAlumno);

        label_nombreAlumno = new QLabel(verticalLayoutWidget_2);
        label_nombreAlumno->setObjectName("label_nombreAlumno");
        label_nombreAlumno->setFont(font);
        label_nombreAlumno->setStyleSheet(QString::fromUtf8("color: rgb(38, 162, 105);\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 15px;\n"
"padding-left: 10px;"));
        label_nombreAlumno->setFrameShape(QFrame::Shape::NoFrame);
        label_nombreAlumno->setFrameShadow(QFrame::Shadow::Plain);
        label_nombreAlumno->setLineWidth(1);
        label_nombreAlumno->setMidLineWidth(0);
        label_nombreAlumno->setWordWrap(false);

        completarCamposAlumno->addWidget(label_nombreAlumno);

        labelFondo1 = new QLabel(centralwidget);
        labelFondo1->setObjectName("labelFondo1");
        labelFondo1->setGeometry(QRect(71, 121, 566, 301));
        labelFondo1->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 247, 226);"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(-10, 0, 841, 91));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 113, 216);"));
        label_cargoUsuario = new QLabel(centralwidget);
        label_cargoUsuario->setObjectName("label_cargoUsuario");
        label_cargoUsuario->setGeometry(QRect(540, 20, 211, 61));
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        label_cargoUsuario->setFont(font3);
        label_cargoUsuario->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_cargoUsuario->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        label_cargoUsuario->setWordWrap(true);
        label_idCurso = new QLabel(centralwidget);
        label_idCurso->setObjectName("label_idCurso");
        label_idCurso->setGeometry(QRect(410, 50, 31, 31));
        label_idCurso->setFont(font3);
        label_idCurso->setStyleSheet(QString::fromUtf8("color: rgb(38, 162, 105);"));
        label_idCurso->setWordWrap(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(290, 50, 121, 31));
        label_2->setFont(font3);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(53, 132, 228);"));
        label_2->setWordWrap(true);
        label_idUsuario = new QLabel(centralwidget);
        label_idUsuario->setObjectName("label_idUsuario");
        label_idUsuario->setGeometry(QRect(240, 50, 31, 31));
        label_idUsuario->setFont(font3);
        label_idUsuario->setStyleSheet(QString::fromUtf8("color: rgb(38, 162, 105);"));
        label_idUsuario->setWordWrap(true);
        label_nombreUsuario = new QLabel(centralwidget);
        label_nombreUsuario->setObjectName("label_nombreUsuario");
        label_nombreUsuario->setGeometry(QRect(200, 20, 281, 31));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Ubuntu")});
        font4.setPointSize(20);
        font4.setBold(true);
        label_nombreUsuario->setFont(font4);
        label_nombreUsuario->setStyleSheet(QString::fromUtf8("color: rgb(38, 162, 105);"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(200, 50, 41, 31));
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8("color: rgb(53, 132, 228);"));
        label->setWordWrap(true);
        modificacion_de_alumnos->setCentralWidget(centralwidget);
        label_4->raise();
        labelFondo1->raise();
        label_3->raise();
        verticalLayoutWidget_3->raise();
        verticalLayoutWidget->raise();
        confirmarModificacionAlumno->raise();
        verticalLayoutWidget_2->raise();
        label_cargoUsuario->raise();
        label_idCurso->raise();
        label_2->raise();
        label_idUsuario->raise();
        label_nombreUsuario->raise();
        label->raise();
        menubar = new QMenuBar(modificacion_de_alumnos);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 29));
        QFont font5;
        font5.setPointSize(15);
        font5.setWeight(QFont::Medium);
        menubar->setFont(font5);
        menubar->setStyleSheet(QString::fromUtf8("color: rgb(255, 120, 0);\n"
"alternate-background-color: rgb(255, 190, 111);\n"
"selection-background-color: rgb(255, 190, 111);\n"
""));
        menuOpciones = new QMenu(menubar);
        menuOpciones->setObjectName("menuOpciones");
        QFont font6;
        font6.setPointSize(13);
        menuOpciones->setFont(font6);
        menuOpciones->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(0, 0, 0);\n"
"selection-color: rgb(0, 0, 0);\n"
"color: rgb(0, 0, 0);"));
        modificacion_de_alumnos->setMenuBar(menubar);
        statusbar = new QStatusBar(modificacion_de_alumnos);
        statusbar->setObjectName("statusbar");
        modificacion_de_alumnos->setStatusBar(statusbar);

        menubar->addAction(menuOpciones->menuAction());
        menuOpciones->addAction(actionCambiar_cuenta);
        menuOpciones->addSeparator();
        menuOpciones->addAction(actionVolver);
        menuOpciones->addSeparator();
        menuOpciones->addAction(actionSalir);

        retranslateUi(modificacion_de_alumnos);

        QMetaObject::connectSlotsByName(modificacion_de_alumnos);
    } // setupUi

    void retranslateUi(QMainWindow *modificacion_de_alumnos)
    {
        modificacion_de_alumnos->setWindowTitle(QCoreApplication::translate("modificacion_de_alumnos", "MainWindow", nullptr));
        actionCambiar_cuenta->setText(QCoreApplication::translate("modificacion_de_alumnos", "   Cambiar cuenta", nullptr));
        actionVolver->setText(QCoreApplication::translate("modificacion_de_alumnos", "   Volver", nullptr));
        actionSalir->setText(QCoreApplication::translate("modificacion_de_alumnos", "   Salir", nullptr));
        label_3->setText(QString());
        sBox_EdadAlumno->setSuffix(QString());
        label_NomAlu->setText(QCoreApplication::translate("modificacion_de_alumnos", "<html><head/><body><p><span style=\" color:#2ec27e;\">ID del alumno a modificar:</span></p></body></html>", nullptr));
        label_ApeAlu->setText(QCoreApplication::translate("modificacion_de_alumnos", "<html><head/><body><p><span style=\" color:#2ec27e;\">Nombre del alumno</span></p><p><span style=\" color:#2ec27e;\">a modificar sus datos:</span></p></body></html>", nullptr));
        checkBoxNombre->setText(QCoreApplication::translate("modificacion_de_alumnos", "    Nuevo nombre: ", nullptr));
        checkBoxApellido->setText(QCoreApplication::translate("modificacion_de_alumnos", "    Nuevo apellido: ", nullptr));
        checkBoxEdad->setText(QCoreApplication::translate("modificacion_de_alumnos", "    Nueva edad:", nullptr));
        confirmarModificacionAlumno->setText(QCoreApplication::translate("modificacion_de_alumnos", "     CONFIRMAR", nullptr));
        label_nombreAlumno->setText(QCoreApplication::translate("modificacion_de_alumnos", "...", nullptr));
        labelFondo1->setText(QString());
        label_4->setText(QString());
        label_cargoUsuario->setText(QCoreApplication::translate("modificacion_de_alumnos", "<html><head/><body><p><span style=\" color:#ffffff;\">Preceptor / DOE</span></p></body></html>", nullptr));
        label_idCurso->setText(QCoreApplication::translate("modificacion_de_alumnos", "<html><head/><body><p><span style=\" color:#26a269;\">0</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("modificacion_de_alumnos", "<html><head/><body><p><span style=\" color:#ffffff;\">ID Curso:</span></p></body></html>", nullptr));
        label_idUsuario->setText(QCoreApplication::translate("modificacion_de_alumnos", "<html><head/><body><p><span style=\" color:#26a269;\">0</span></p></body></html>", nullptr));
        label_nombreUsuario->setText(QCoreApplication::translate("modificacion_de_alumnos", "<html><head/><body><p><span style=\" color:#26a269;\">Nombre completo</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("modificacion_de_alumnos", "<html><head/><body><p><span style=\" color:#ffffff;\">ID:</span></p></body></html>", nullptr));
        menuOpciones->setTitle(QCoreApplication::translate("modificacion_de_alumnos", "Opciones", nullptr));
    } // retranslateUi

};

namespace Ui {
    class modificacion_de_alumnos: public Ui_modificacion_de_alumnos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFICACION_DE_ALUMNOS_H
