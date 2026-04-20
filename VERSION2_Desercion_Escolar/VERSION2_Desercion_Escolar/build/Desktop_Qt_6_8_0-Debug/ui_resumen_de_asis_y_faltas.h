/********************************************************************************
** Form generated from reading UI file 'resumen_de_asis_y_faltas.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESUMEN_DE_ASIS_Y_FALTAS_H
#define UI_RESUMEN_DE_ASIS_Y_FALTAS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_resumen_de_asis_y_faltas
{
public:
    QAction *actionCambiar_cuenta;
    QAction *actionVolver;
    QAction *actionSalir;
    QWidget *centralwidget;
    QLabel *label_IdAlumno;
    QLabel *labelAlumno;
    QLabel *labelMotivos;
    QLabel *label_4;
    QLabel *label;
    QLabel *labelTituloResumen;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelCantAsist;
    QLabel *labelCantInasist_SJ;
    QLabel *labelCantInasistJ;
    QComboBox *comboBoxMes;
    QLabel *labelDiaJustif;
    QComboBox *comboBoxMesFaltas;
    QFrame *line_3;
    QLabel *labelMeses;
    QComboBox *comboBoxFecha;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_2;
    QComboBox *comboBoxRangoTiempo;
    QComboBox *comboBoxResumen;
    QComboBox *comboBoxMotivoFalta;
    QPushButton *btnGuardar;
    QComboBox *comboBoxAlumno;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *Rpta_CantAsist;
    QLabel *Rpta_CantInasist_SJ;
    QLabel *Rpta_CantInasistJ;
    QLabel *label_6;
    QLabel *label_motivoRes_Alu;
    QComboBox *comboBox_motivoRes_Alu;
    QLabel *label_motivoRes_Fecha;
    QComboBox *comboBox_motivoRes_Fecha;
    QLabel *label_motivoRes;
    QLabel *label_motivoRes_Mot;
    QLabel *label_7;
    QComboBox *comboBox_motivoRes_Mes;
    QLabel *label_8;
    QLabel *label_IdAlu;
    QFrame *line;
    QMenuBar *menubar;
    QMenu *menuOpciones;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *resumen_de_asis_y_faltas)
    {
        if (resumen_de_asis_y_faltas->objectName().isEmpty())
            resumen_de_asis_y_faltas->setObjectName("resumen_de_asis_y_faltas");
        resumen_de_asis_y_faltas->resize(1000, 768);
        actionCambiar_cuenta = new QAction(resumen_de_asis_y_faltas);
        actionCambiar_cuenta->setObjectName("actionCambiar_cuenta");
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("x-office-address-book")));
        actionCambiar_cuenta->setIcon(icon);
        actionVolver = new QAction(resumen_de_asis_y_faltas);
        actionVolver->setObjectName("actionVolver");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::EditUndo));
        actionVolver->setIcon(icon1);
        actionSalir = new QAction(resumen_de_asis_y_faltas);
        actionSalir->setObjectName("actionSalir");
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        actionSalir->setIcon(icon2);
        centralwidget = new QWidget(resumen_de_asis_y_faltas);
        centralwidget->setObjectName("centralwidget");
        label_IdAlumno = new QLabel(centralwidget);
        label_IdAlumno->setObjectName("label_IdAlumno");
        label_IdAlumno->setGeometry(QRect(530, 40, 301, 51));
        QFont font;
        font.setPointSize(13);
        font.setWeight(QFont::DemiBold);
        label_IdAlumno->setFont(font);
        label_IdAlumno->setStyleSheet(QString::fromUtf8("padding-left: 10px;"));
        label_IdAlumno->setFrameShape(QFrame::Shape::Box);
        label_IdAlumno->setLineWidth(1);
        labelAlumno = new QLabel(centralwidget);
        labelAlumno->setObjectName("labelAlumno");
        labelAlumno->setGeometry(QRect(10, 40, 251, 41));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        labelAlumno->setFont(font1);
        labelAlumno->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 229, 243);\n"
"border: 2px;\n"
"border-radius: 25px;"));
        labelAlumno->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelMotivos = new QLabel(centralwidget);
        labelMotivos->setObjectName("labelMotivos");
        labelMotivos->setGeometry(QRect(10, 190, 321, 41));
        labelMotivos->setFont(font1);
        labelMotivos->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 229, 243);\n"
"border: 2px;\n"
"border-radius: 25px;"));
        labelMotivos->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(930, 380, 41, 18));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(670, 290, 291, 41));
        label->setWordWrap(true);
        labelTituloResumen = new QLabel(centralwidget);
        labelTituloResumen->setObjectName("labelTituloResumen");
        labelTituloResumen->setGeometry(QRect(10, 280, 681, 31));
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setUnderline(true);
        labelTituloResumen->setFont(font2);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 310, 241, 141));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labelCantAsist = new QLabel(verticalLayoutWidget);
        labelCantAsist->setObjectName("labelCantAsist");
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setItalic(true);
        labelCantAsist->setFont(font3);

        verticalLayout->addWidget(labelCantAsist);

        labelCantInasist_SJ = new QLabel(verticalLayoutWidget);
        labelCantInasist_SJ->setObjectName("labelCantInasist_SJ");
        labelCantInasist_SJ->setFont(font3);

        verticalLayout->addWidget(labelCantInasist_SJ);

        labelCantInasistJ = new QLabel(verticalLayoutWidget);
        labelCantInasistJ->setObjectName("labelCantInasistJ");
        labelCantInasistJ->setFont(font3);

        verticalLayout->addWidget(labelCantInasistJ);

        comboBoxMes = new QComboBox(centralwidget);
        comboBoxMes->addItem(QString());
        comboBoxMes->addItem(QString());
        comboBoxMes->addItem(QString());
        comboBoxMes->addItem(QString());
        comboBoxMes->addItem(QString());
        comboBoxMes->addItem(QString());
        comboBoxMes->addItem(QString());
        comboBoxMes->addItem(QString());
        comboBoxMes->addItem(QString());
        comboBoxMes->addItem(QString());
        comboBoxMes->setObjectName("comboBoxMes");
        comboBoxMes->setGeometry(QRect(930, 410, 51, 31));
        QFont font4;
        font4.setWeight(QFont::DemiBold);
        comboBoxMes->setFont(font4);
        comboBoxMes->setStyleSheet(QString::fromUtf8("color: rgb(6, 22, 40);\n"
"alternate-background-color: rgb(222, 229, 243);\n"
"selection-background-color: rgb(222, 229, 243);"));
        labelDiaJustif = new QLabel(centralwidget);
        labelDiaJustif->setObjectName("labelDiaJustif");
        labelDiaJustif->setGeometry(QRect(10, 120, 391, 41));
        labelDiaJustif->setFont(font1);
        labelDiaJustif->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 229, 243);\n"
"border: 2px;\n"
"border-radius: 25px;"));
        labelDiaJustif->setAlignment(Qt::AlignmentFlag::AlignCenter);
        comboBoxMesFaltas = new QComboBox(centralwidget);
        comboBoxMesFaltas->addItem(QString());
        comboBoxMesFaltas->addItem(QString());
        comboBoxMesFaltas->addItem(QString());
        comboBoxMesFaltas->addItem(QString());
        comboBoxMesFaltas->addItem(QString());
        comboBoxMesFaltas->addItem(QString());
        comboBoxMesFaltas->addItem(QString());
        comboBoxMesFaltas->addItem(QString());
        comboBoxMesFaltas->addItem(QString());
        comboBoxMesFaltas->addItem(QString());
        comboBoxMesFaltas->setObjectName("comboBoxMesFaltas");
        comboBoxMesFaltas->setGeometry(QRect(630, 130, 51, 31));
        comboBoxMesFaltas->setFont(font4);
        comboBoxMesFaltas->setStyleSheet(QString::fromUtf8("color: rgb(6, 22, 40);\n"
"alternate-background-color: rgb(222, 229, 243);\n"
"selection-background-color: rgb(222, 229, 243);"));
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(-23, 260, 1021, 16));
        line_3->setStyleSheet(QString::fromUtf8("color: rgb(210, 211, 213);"));
        line_3->setFrameShadow(QFrame::Shadow::Plain);
        line_3->setLineWidth(2);
        line_3->setFrameShape(QFrame::Shape::HLine);
        labelMeses = new QLabel(centralwidget);
        labelMeses->setObjectName("labelMeses");
        labelMeses->setGeometry(QRect(420, 320, 211, 111));
        QFont font5;
        font5.setPointSize(11);
        labelMeses->setFont(font5);
        labelMeses->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        labelMeses->setWordWrap(true);
        comboBoxFecha = new QComboBox(centralwidget);
        comboBoxFecha->setObjectName("comboBoxFecha");
        comboBoxFecha->setEnabled(true);
        comboBoxFecha->setGeometry(QRect(420, 120, 181, 41));
        comboBoxFecha->setFont(font);
        comboBoxFecha->setStyleSheet(QString::fromUtf8("color: rgb(6, 22, 40);\n"
"alternate-background-color: rgb(222, 229, 243);\n"
"selection-background-color: rgb(222, 229, 243);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(670, 380, 241, 18));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(630, 110, 41, 18));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(530, 10, 301, 31));
        QFont font6;
        font6.setPointSize(13);
        label_2->setFont(font6);
        label_2->setWordWrap(true);
        comboBoxRangoTiempo = new QComboBox(centralwidget);
        comboBoxRangoTiempo->addItem(QString());
        comboBoxRangoTiempo->addItem(QString());
        comboBoxRangoTiempo->setObjectName("comboBoxRangoTiempo");
        comboBoxRangoTiempo->setGeometry(QRect(670, 410, 231, 31));
        comboBoxRangoTiempo->setFont(font4);
        comboBoxRangoTiempo->setStyleSheet(QString::fromUtf8("color: rgb(6, 22, 40);\n"
"alternate-background-color: rgb(222, 229, 243);\n"
"selection-background-color: rgb(222, 229, 243);"));
        comboBoxResumen = new QComboBox(centralwidget);
        comboBoxResumen->setObjectName("comboBoxResumen");
        comboBoxResumen->setGeometry(QRect(670, 340, 291, 31));
        comboBoxResumen->setFont(font4);
        comboBoxResumen->setStyleSheet(QString::fromUtf8("color: rgb(6, 22, 40);\n"
"alternate-background-color: rgb(222, 229, 243);\n"
"selection-background-color: rgb(222, 229, 243);"));
        comboBoxMotivoFalta = new QComboBox(centralwidget);
        comboBoxMotivoFalta->setObjectName("comboBoxMotivoFalta");
        comboBoxMotivoFalta->setEnabled(true);
        comboBoxMotivoFalta->setGeometry(QRect(360, 190, 361, 41));
        comboBoxMotivoFalta->setFont(font);
        comboBoxMotivoFalta->setStyleSheet(QString::fromUtf8("color: rgb(6, 22, 40);\n"
"alternate-background-color: rgb(222, 229, 243);\n"
"selection-background-color: rgb(222, 229, 243);"));
        btnGuardar = new QPushButton(centralwidget);
        btnGuardar->setObjectName("btnGuardar");
        btnGuardar->setGeometry(QRect(760, 180, 191, 51));
        btnGuardar->setFont(font1);
        btnGuardar->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(222, 221, 218);\n"
"border-radius: 25px;"));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave));
        btnGuardar->setIcon(icon3);
        comboBoxAlumno = new QComboBox(centralwidget);
        comboBoxAlumno->setObjectName("comboBoxAlumno");
        comboBoxAlumno->setEnabled(true);
        comboBoxAlumno->setGeometry(QRect(290, 40, 181, 41));
        comboBoxAlumno->setFont(font);
        comboBoxAlumno->setStyleSheet(QString::fromUtf8("color: rgb(6, 22, 40);\n"
"alternate-background-color: rgb(222, 229, 243);\n"
"selection-background-color: rgb(222, 229, 243);"));
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(280, 310, 101, 141));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        Rpta_CantAsist = new QLabel(verticalLayoutWidget_2);
        Rpta_CantAsist->setObjectName("Rpta_CantAsist");
        QFont font7;
        font7.setPointSize(14);
        font7.setWeight(QFont::DemiBold);
        font7.setItalic(true);
        Rpta_CantAsist->setFont(font7);

        verticalLayout_2->addWidget(Rpta_CantAsist);

        Rpta_CantInasist_SJ = new QLabel(verticalLayoutWidget_2);
        Rpta_CantInasist_SJ->setObjectName("Rpta_CantInasist_SJ");
        Rpta_CantInasist_SJ->setFont(font7);

        verticalLayout_2->addWidget(Rpta_CantInasist_SJ);

        Rpta_CantInasistJ = new QLabel(verticalLayoutWidget_2);
        Rpta_CantInasistJ->setObjectName("Rpta_CantInasistJ");
        Rpta_CantInasistJ->setFont(font7);

        verticalLayout_2->addWidget(Rpta_CantInasistJ);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 490, 66, 18));
        label_motivoRes_Alu = new QLabel(centralwidget);
        label_motivoRes_Alu->setObjectName("label_motivoRes_Alu");
        label_motivoRes_Alu->setGeometry(QRect(10, 490, 61, 18));
        comboBox_motivoRes_Alu = new QComboBox(centralwidget);
        comboBox_motivoRes_Alu->setObjectName("comboBox_motivoRes_Alu");
        comboBox_motivoRes_Alu->setGeometry(QRect(90, 490, 221, 26));
        QFont font8;
        font8.setWeight(QFont::Medium);
        comboBox_motivoRes_Alu->setFont(font8);
        comboBox_motivoRes_Alu->setStyleSheet(QString::fromUtf8("color: rgb(17, 49, 88);"));
        label_motivoRes_Fecha = new QLabel(centralwidget);
        label_motivoRes_Fecha->setObjectName("label_motivoRes_Fecha");
        label_motivoRes_Fecha->setGeometry(QRect(10, 535, 51, 18));
        comboBox_motivoRes_Fecha = new QComboBox(centralwidget);
        comboBox_motivoRes_Fecha->setObjectName("comboBox_motivoRes_Fecha");
        comboBox_motivoRes_Fecha->setGeometry(QRect(90, 530, 221, 26));
        comboBox_motivoRes_Fecha->setFont(font8);
        comboBox_motivoRes_Fecha->setStyleSheet(QString::fromUtf8("color: rgb(17, 49, 88);"));
        label_motivoRes = new QLabel(centralwidget);
        label_motivoRes->setObjectName("label_motivoRes");
        label_motivoRes->setGeometry(QRect(640, 480, 261, 31));
        QFont font9;
        font9.setPointSize(20);
        font9.setBold(true);
        label_motivoRes->setFont(font9);
        label_motivoRes_Mot = new QLabel(centralwidget);
        label_motivoRes_Mot->setObjectName("label_motivoRes_Mot");
        label_motivoRes_Mot->setGeometry(QRect(640, 520, 341, 71));
        QFont font10;
        font10.setPointSize(17);
        font10.setBold(true);
        label_motivoRes_Mot->setFont(font10);
        label_motivoRes_Mot->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        label_motivoRes_Mot->setWordWrap(true);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 570, 41, 31));
        comboBox_motivoRes_Mes = new QComboBox(centralwidget);
        comboBox_motivoRes_Mes->addItem(QString());
        comboBox_motivoRes_Mes->addItem(QString());
        comboBox_motivoRes_Mes->addItem(QString());
        comboBox_motivoRes_Mes->addItem(QString());
        comboBox_motivoRes_Mes->addItem(QString());
        comboBox_motivoRes_Mes->addItem(QString());
        comboBox_motivoRes_Mes->addItem(QString());
        comboBox_motivoRes_Mes->addItem(QString());
        comboBox_motivoRes_Mes->addItem(QString());
        comboBox_motivoRes_Mes->addItem(QString());
        comboBox_motivoRes_Mes->setObjectName("comboBox_motivoRes_Mes");
        comboBox_motivoRes_Mes->setGeometry(QRect(90, 570, 61, 26));
        comboBox_motivoRes_Mes->setFont(font8);
        comboBox_motivoRes_Mes->setStyleSheet(QString::fromUtf8("color: rgb(17, 49, 88);"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(370, 480, 221, 41));
        label_8->setFont(font6);
        label_8->setWordWrap(true);
        label_IdAlu = new QLabel(centralwidget);
        label_IdAlu->setObjectName("label_IdAlu");
        label_IdAlu->setGeometry(QRect(370, 530, 201, 41));
        label_IdAlu->setFont(font);
        label_IdAlu->setStyleSheet(QString::fromUtf8("padding-left: 10px;\n"
"color: rgb(17, 49, 88);"));
        label_IdAlu->setFrameShape(QFrame::Shape::Box);
        label_IdAlu->setLineWidth(1);
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(-3, 460, 1001, 21));
        line->setStyleSheet(QString::fromUtf8("color: rgb(210, 211, 213);"));
        line->setFrameShadow(QFrame::Shadow::Plain);
        line->setLineWidth(2);
        line->setFrameShape(QFrame::Shape::HLine);
        resumen_de_asis_y_faltas->setCentralWidget(centralwidget);
        menubar = new QMenuBar(resumen_de_asis_y_faltas);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 29));
        QFont font11;
        font11.setPointSize(15);
        font11.setWeight(QFont::Medium);
        menubar->setFont(font11);
        menubar->setStyleSheet(QString::fromUtf8("color: rgb(255, 120, 0);\n"
"alternate-background-color: rgb(255, 190, 111);\n"
"selection-background-color: rgb(255, 190, 111);"));
        menuOpciones = new QMenu(menubar);
        menuOpciones->setObjectName("menuOpciones");
        QFont font12;
        font12.setPointSize(13);
        font12.setBold(false);
        menuOpciones->setFont(font12);
        menuOpciones->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(0, 0, 0);\n"
"selection-color: rgb(0, 0, 0);\n"
"color: rgb(0, 0, 0);"));
        resumen_de_asis_y_faltas->setMenuBar(menubar);
        statusbar = new QStatusBar(resumen_de_asis_y_faltas);
        statusbar->setObjectName("statusbar");
        resumen_de_asis_y_faltas->setStatusBar(statusbar);

        menubar->addAction(menuOpciones->menuAction());
        menuOpciones->addAction(actionCambiar_cuenta);
        menuOpciones->addSeparator();
        menuOpciones->addAction(actionVolver);
        menuOpciones->addSeparator();
        menuOpciones->addAction(actionSalir);

        retranslateUi(resumen_de_asis_y_faltas);

        QMetaObject::connectSlotsByName(resumen_de_asis_y_faltas);
    } // setupUi

    void retranslateUi(QMainWindow *resumen_de_asis_y_faltas)
    {
        resumen_de_asis_y_faltas->setWindowTitle(QCoreApplication::translate("resumen_de_asis_y_faltas", "MainWindow", nullptr));
        actionCambiar_cuenta->setText(QCoreApplication::translate("resumen_de_asis_y_faltas", "   Cambiar cuenta", nullptr));
        actionVolver->setText(QCoreApplication::translate("resumen_de_asis_y_faltas", "   Volver", nullptr));
        actionSalir->setText(QCoreApplication::translate("resumen_de_asis_y_faltas", "   Salir", nullptr));
        label_IdAlumno->setText(QCoreApplication::translate("resumen_de_asis_y_faltas", "...", nullptr));
        labelAlumno->setText(QCoreApplication::translate("resumen_de_asis_y_faltas", "<html><head/><body><p><span style=\" color:#061628;\">Seleccion\303\241 un alumno: </span></p></body></html>", nullptr));
        labelMotivos->setText(QCoreApplication::translate("resumen_de_asis_y_faltas", "<html><head/><body><p><span style=\" color:#061628;\">Seleccion\303\241 un motivo de falta:</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("resumen_de_asis_y_faltas", "<html><head/><body><p><span style=\" color:#000000;\">Mes:</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("resumen_de_asis_y_faltas", "<html><head/><body><p><span style=\" color:#000000;\">Mostrar resumen de asistencias / inasistencias del alumno seleccionado:</span></p></body></html>", nullptr));
        labelTituloResumen->setText(QCoreApplication::translate("resumen_de_asis_y_faltas", "<html><head/><body><p><span style=\" color:#091e35;\">RESUMEN ASISTENCIAS E INASISTENCIAS DEL ALUMNO</span></p></body></html>", nullptr));
        labelCantAsist->setText(QCoreApplication::translate("resumen_de_asis_y_faltas", "<html><head/><body><p><span style=\" color:#2a435f;\">Asistencias:</span></p></body></html>", nullptr));
        labelCantInasist_SJ->setText(QCoreApplication::translate("resumen_de_asis_y_faltas", "<html><head/><body><p><span style=\" color:#2a435f;\">Inasistencias sin justificar:</span></p></body></html>", nullptr));
        labelCantInasistJ->setText(QCoreApplication::translate("resumen_de_asis_y_faltas", "<html><head/><body><p><span style=\" color:#2a435f;\">Inasistencias justificadas:</span></p></body></html>", nullptr));
        comboBoxMes->setItemText(0, QCoreApplication::translate("resumen_de_asis_y_faltas", "03", nullptr));
        comboBoxMes->setItemText(1, QCoreApplication::translate("resumen_de_asis_y_faltas", "04", nullptr));
        comboBoxMes->setItemText(2, QCoreApplication::translate("resumen_de_asis_y_faltas", "05", nullptr));
        comboBoxMes->setItemText(3, QCoreApplication::translate("resumen_de_asis_y_faltas", "06", nullptr));
        comboBoxMes->setItemText(4, QCoreApplication::translate("resumen_de_asis_y_faltas", "07", nullptr));
        comboBoxMes->setItemText(5, QCoreApplication::translate("resumen_de_asis_y_faltas", "08", nullptr));
        comboBoxMes->setItemText(6, QCoreApplication::translate("resumen_de_asis_y_faltas", "09", nullptr));
        comboBoxMes->setItemText(7, QCoreApplication::translate("resumen_de_asis_y_faltas", "10", nullptr));
        comboBoxMes->setItemText(8, QCoreApplication::translate("resumen_de_asis_y_faltas", "11", nullptr));
        comboBoxMes->setItemText(9, QCoreApplication::translate("resumen_de_asis_y_faltas", "12", nullptr));

        labelDiaJustif->setText(QCoreApplication::translate("resumen_de_asis_y_faltas", "<html><head/><body><p><span style=\" color:#061628;\">Seleccion\303\241 d\303\255a para justificar asistencia:</span></p></body></html>", nullptr));
        comboBoxMesFaltas->setItemText(0, QCoreApplication::translate("resumen_de_asis_y_faltas", "03", nullptr));
        comboBoxMesFaltas->setItemText(1, QCoreApplication::translate("resumen_de_asis_y_faltas", "04", nullptr));
        comboBoxMesFaltas->setItemText(2, QCoreApplication::translate("resumen_de_asis_y_faltas", "05", nullptr));
        comboBoxMesFaltas->setItemText(3, QCoreApplication::translate("resumen_de_asis_y_faltas", "06", nullptr));
        comboBoxMesFaltas->setItemText(4, QCoreApplication::translate("resumen_de_asis_y_faltas", "07", nullptr));
        comboBoxMesFaltas->setItemText(5, QCoreApplication::translate("resumen_de_asis_y_faltas", "08", nullptr));
        comboBoxMesFaltas->setItemText(6, QCoreApplication::translate("resumen_de_asis_y_faltas", "09", nullptr));
        comboBoxMesFaltas->setItemText(7, QCoreApplication::translate("resumen_de_asis_y_faltas", "10", nullptr));
        comboBoxMesFaltas->setItemText(8, QCoreApplication::translate("resumen_de_asis_y_faltas", "11", nullptr));
        comboBoxMesFaltas->setItemText(9, QCoreApplication::translate("resumen_de_asis_y_faltas", "12", nullptr));

        labelMeses->setText(QCoreApplication::translate("resumen_de_asis_y_faltas", "<html><head/><body><p align=\"justify\"><span style=\" color:#000000;\">Marzo: 03 --- Abril: 04 --- Mayo: 05 --- Junio: 06</span></p><p align=\"justify\"><span style=\" color:#000000;\">Julio: 07 --- Agosto: 08 --- Septiembre: 09 -- Octubre: 10</span></p><p align=\"justify\"><span style=\" color:#000000;\">Noviembre: 11 --- Diciembre: 12</span></p><p align=\"justify\"><span style=\" color:#000000;\"><br/></span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("resumen_de_asis_y_faltas", "<html><head/><body><p><span style=\" color:#000000;\">Rango de tiempo para el resumen:</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("resumen_de_asis_y_faltas", "<html><head/><body><p><span style=\" color:#000000;\">Mes:</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("resumen_de_asis_y_faltas", "ID del alumno con faltas seleccionado:", nullptr));
        comboBoxRangoTiempo->setItemText(0, QCoreApplication::translate("resumen_de_asis_y_faltas", "Anual", nullptr));
        comboBoxRangoTiempo->setItemText(1, QCoreApplication::translate("resumen_de_asis_y_faltas", "Mensual", nullptr));

        btnGuardar->setText(QCoreApplication::translate("resumen_de_asis_y_faltas", "   GUARDAR", nullptr));
        Rpta_CantAsist->setText(QCoreApplication::translate("resumen_de_asis_y_faltas", "<html><head/><body><p><span style=\" color:#000000;\">...</span></p></body></html>", nullptr));
        Rpta_CantInasist_SJ->setText(QCoreApplication::translate("resumen_de_asis_y_faltas", "<html><head/><body><p><span style=\" color:#000000;\">...</span></p></body></html>", nullptr));
        Rpta_CantInasistJ->setText(QCoreApplication::translate("resumen_de_asis_y_faltas", "<html><head/><body><p><span style=\" color:#000000;\">...</span></p></body></html>", nullptr));
        label_6->setText(QString());
        label_motivoRes_Alu->setText(QCoreApplication::translate("resumen_de_asis_y_faltas", "<html><head/><body><p><span style=\" color:#113158;\">Alumno:</span></p></body></html>", nullptr));
        label_motivoRes_Fecha->setText(QCoreApplication::translate("resumen_de_asis_y_faltas", "<html><head/><body><p><span style=\" color:#113158;\">Fecha:</span></p></body></html>", nullptr));
        label_motivoRes->setText(QCoreApplication::translate("resumen_de_asis_y_faltas", "<html><head/><body><p><span style=\" color:#113158;\">MOTIVO DE FALTA:</span></p></body></html>", nullptr));
        label_motivoRes_Mot->setText(QCoreApplication::translate("resumen_de_asis_y_faltas", "<html><head/><body><p><span style=\" color:#99c1f1;\">MOTIVO DE FALTA AC\303\201AAA</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("resumen_de_asis_y_faltas", "<html><head/><body><p><span style=\" color:#113158;\">Mes:</span></p></body></html>", nullptr));
        comboBox_motivoRes_Mes->setItemText(0, QCoreApplication::translate("resumen_de_asis_y_faltas", "03", nullptr));
        comboBox_motivoRes_Mes->setItemText(1, QCoreApplication::translate("resumen_de_asis_y_faltas", "04", nullptr));
        comboBox_motivoRes_Mes->setItemText(2, QCoreApplication::translate("resumen_de_asis_y_faltas", "05", nullptr));
        comboBox_motivoRes_Mes->setItemText(3, QCoreApplication::translate("resumen_de_asis_y_faltas", "06", nullptr));
        comboBox_motivoRes_Mes->setItemText(4, QCoreApplication::translate("resumen_de_asis_y_faltas", "07", nullptr));
        comboBox_motivoRes_Mes->setItemText(5, QCoreApplication::translate("resumen_de_asis_y_faltas", "08", nullptr));
        comboBox_motivoRes_Mes->setItemText(6, QCoreApplication::translate("resumen_de_asis_y_faltas", "09", nullptr));
        comboBox_motivoRes_Mes->setItemText(7, QCoreApplication::translate("resumen_de_asis_y_faltas", "10", nullptr));
        comboBox_motivoRes_Mes->setItemText(8, QCoreApplication::translate("resumen_de_asis_y_faltas", "11", nullptr));
        comboBox_motivoRes_Mes->setItemText(9, QCoreApplication::translate("resumen_de_asis_y_faltas", "12", nullptr));

        label_8->setText(QCoreApplication::translate("resumen_de_asis_y_faltas", "<html><head/><body><p><span style=\" color:#113158;\">ID del alumno con faltas seleccionado:</span></p></body></html>", nullptr));
        label_IdAlu->setText(QCoreApplication::translate("resumen_de_asis_y_faltas", "...", nullptr));
        menuOpciones->setTitle(QCoreApplication::translate("resumen_de_asis_y_faltas", "Opciones", nullptr));
    } // retranslateUi

};

namespace Ui {
    class resumen_de_asis_y_faltas: public Ui_resumen_de_asis_y_faltas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESUMEN_DE_ASIS_Y_FALTAS_H
