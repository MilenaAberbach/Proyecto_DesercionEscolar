/********************************************************************************
** Form generated from reading UI file 'reuniones.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REUNIONES_H
#define UI_REUNIONES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reuniones
{
public:
    QAction *actionCambiar_cuenta;
    QAction *actionVolver;
    QAction *actionSalir;
    QWidget *centralwidget;
    QLabel *label_alumno;
    QComboBox *comboBox_alumno;
    QLabel *label_fecha;
    QLabel *label_motivo;
    QLabel *label_mes;
    QLineEdit *lineEdit_motivo;
    QComboBox *comboBox_mes;
    QComboBox *comboBox_fecha;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox_justifPadre;
    QLineEdit *lineEdit_justifPadre;
    QLabel *label_3;
    QPushButton *btnConfirmarJustif;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *comboBox_cantReuniones;
    QLabel *label_6;
    QLabel *label_cantReuniones;
    QPushButton *btnCrearReunion;
    QLabel *label_8;
    QComboBox *comboBox_justif_Alumno;
    QLabel *label_9;
    QLabel *label_7;
    QLabel *label_10;
    QLabel *label_motivoReunion;
    QLabel *label_11;
    QComboBox *comboBox_cantReuniones2;
    QMenuBar *menubar;
    QMenu *menuOpciones;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *reuniones)
    {
        if (reuniones->objectName().isEmpty())
            reuniones->setObjectName("reuniones");
        reuniones->resize(1200, 700);
        actionCambiar_cuenta = new QAction(reuniones);
        actionCambiar_cuenta->setObjectName("actionCambiar_cuenta");
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("x-office-address-book")));
        actionCambiar_cuenta->setIcon(icon);
        actionVolver = new QAction(reuniones);
        actionVolver->setObjectName("actionVolver");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::EditUndo));
        actionVolver->setIcon(icon1);
        actionSalir = new QAction(reuniones);
        actionSalir->setObjectName("actionSalir");
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        actionSalir->setIcon(icon2);
        centralwidget = new QWidget(reuniones);
        centralwidget->setObjectName("centralwidget");
        label_alumno = new QLabel(centralwidget);
        label_alumno->setObjectName("label_alumno");
        label_alumno->setGeometry(QRect(20, 250, 181, 101));
        QFont font;
        font.setPointSize(18);
        font.setWeight(QFont::Medium);
        label_alumno->setFont(font);
        label_alumno->setWordWrap(true);
        comboBox_alumno = new QComboBox(centralwidget);
        comboBox_alumno->setObjectName("comboBox_alumno");
        comboBox_alumno->setGeometry(QRect(230, 260, 301, 71));
        QFont font1;
        font1.setPointSize(13);
        comboBox_alumno->setFont(font1);
        comboBox_alumno->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(224, 232, 242);\n"
"selection-background-color: rgb(241, 243, 246);\n"
"alternate-background-color: rgb(241, 243, 246);\n"
"color: rgb(9, 30, 53);"));
        label_fecha = new QLabel(centralwidget);
        label_fecha->setObjectName("label_fecha");
        label_fecha->setGeometry(QRect(20, 170, 131, 61));
        label_fecha->setFont(font);
        label_fecha->setWordWrap(true);
        label_motivo = new QLabel(centralwidget);
        label_motivo->setObjectName("label_motivo");
        label_motivo->setGeometry(QRect(20, 390, 171, 71));
        label_motivo->setFont(font);
        label_motivo->setStyleSheet(QString::fromUtf8("background-color: rgb(17, 49, 88);\n"
"border-radius: 25px;"));
        label_motivo->setWordWrap(true);
        label_mes = new QLabel(centralwidget);
        label_mes->setObjectName("label_mes");
        label_mes->setGeometry(QRect(20, 110, 171, 31));
        label_mes->setFont(font);
        lineEdit_motivo = new QLineEdit(centralwidget);
        lineEdit_motivo->setObjectName("lineEdit_motivo");
        lineEdit_motivo->setGeometry(QRect(230, 390, 301, 51));
        lineEdit_motivo->setFont(font1);
        lineEdit_motivo->setStyleSheet(QString::fromUtf8("padding-left: 20px;\n"
"color: rgb(17, 49, 88);\n"
"background-color: rgb(241, 243, 246);\n"
"border-radius: 25px;\n"
""));
        lineEdit_motivo->setFrame(true);
        comboBox_mes = new QComboBox(centralwidget);
        comboBox_mes->addItem(QString());
        comboBox_mes->addItem(QString());
        comboBox_mes->addItem(QString());
        comboBox_mes->addItem(QString());
        comboBox_mes->addItem(QString());
        comboBox_mes->addItem(QString());
        comboBox_mes->addItem(QString());
        comboBox_mes->addItem(QString());
        comboBox_mes->addItem(QString());
        comboBox_mes->addItem(QString());
        comboBox_mes->setObjectName("comboBox_mes");
        comboBox_mes->setGeometry(QRect(230, 110, 301, 31));
        comboBox_mes->setFont(font1);
        comboBox_mes->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(224, 232, 242);\n"
"selection-background-color: rgb(241, 243, 246);\n"
"alternate-background-color: rgb(241, 243, 246);\n"
"color: rgb(9, 30, 53);"));
        comboBox_fecha = new QComboBox(centralwidget);
        comboBox_fecha->setObjectName("comboBox_fecha");
        comboBox_fecha->setGeometry(QRect(230, 180, 301, 41));
        comboBox_fecha->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(224, 232, 242);\n"
"selection-background-color: rgb(241, 243, 246);\n"
"alternate-background-color: rgb(241, 243, 246);\n"
"color: rgb(9, 30, 53);"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(580, 0, 621, 361));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(241, 243, 246);\n"
"color: rgb(17, 49, 88);"));
        label->setFrameShape(QFrame::Shape::Box);
        label->setLineWidth(2);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(620, 100, 251, 41));
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(true);
        label_2->setFont(font2);
        comboBox_justifPadre = new QComboBox(centralwidget);
        comboBox_justifPadre->addItem(QString());
        comboBox_justifPadre->setObjectName("comboBox_justifPadre");
        comboBox_justifPadre->setGeometry(QRect(620, 140, 281, 31));
        QFont font3;
        font3.setPointSize(13);
        font3.setWeight(QFont::Medium);
        comboBox_justifPadre->setFont(font3);
        comboBox_justifPadre->setStyleSheet(QString::fromUtf8("color: rgb(9, 30, 53);"));
        lineEdit_justifPadre = new QLineEdit(centralwidget);
        lineEdit_justifPadre->setObjectName("lineEdit_justifPadre");
        lineEdit_justifPadre->setGeometry(QRect(620, 220, 421, 51));
        lineEdit_justifPadre->setFont(font1);
        lineEdit_justifPadre->setStyleSheet(QString::fromUtf8("padding-top: 10px;\n"
"padding-left: 10px;\n"
"color: rgb(17, 49, 88);\n"
"background-color: rgb(224, 232, 242);\n"
"border-radius: 25px;"));
        lineEdit_justifPadre->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(620, 190, 321, 20));
        label_3->setFont(font2);
        btnConfirmarJustif = new QPushButton(centralwidget);
        btnConfirmarJustif->setObjectName("btnConfirmarJustif");
        btnConfirmarJustif->setGeometry(QRect(620, 290, 541, 51));
        QFont font4;
        font4.setPointSize(13);
        font4.setWeight(QFont::DemiBold);
        btnConfirmarJustif->setFont(font4);
        btnConfirmarJustif->setStyleSheet(QString::fromUtf8("background-color: rgb(9, 30, 53);\n"
"color: rgb(241, 243, 246);"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(580, 390, 621, 251));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 54, 82);\n"
"color: rgb(17, 49, 88);"));
        label_4->setFrameShape(QFrame::Shape::Box);
        label_4->setLineWidth(2);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(630, 420, 291, 41));
        label_5->setFont(font2);
        comboBox_cantReuniones = new QComboBox(centralwidget);
        comboBox_cantReuniones->addItem(QString());
        comboBox_cantReuniones->setObjectName("comboBox_cantReuniones");
        comboBox_cantReuniones->setGeometry(QRect(630, 470, 281, 41));
        comboBox_cantReuniones->setFont(font3);
        comboBox_cantReuniones->setStyleSheet(QString::fromUtf8("color: rgb(9, 30, 53);"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(930, 400, 251, 61));
        label_6->setFont(font2);
        label_6->setWordWrap(true);
        label_cantReuniones = new QLabel(centralwidget);
        label_cantReuniones->setObjectName("label_cantReuniones");
        label_cantReuniones->setGeometry(QRect(930, 470, 281, 31));
        label_cantReuniones->setFont(font2);
        btnCrearReunion = new QPushButton(centralwidget);
        btnCrearReunion->setObjectName("btnCrearReunion");
        btnCrearReunion->setGeometry(QRect(20, 490, 521, 51));
        btnCrearReunion->setFont(font4);
        btnCrearReunion->setStyleSheet(QString::fromUtf8("color: rgb(17, 49, 88);\n"
"border-radius: 20px;\n"
"background-color: rgb(153, 193, 241);"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(620, 10, 251, 41));
        label_8->setFont(font2);
        comboBox_justif_Alumno = new QComboBox(centralwidget);
        comboBox_justif_Alumno->addItem(QString());
        comboBox_justif_Alumno->setObjectName("comboBox_justif_Alumno");
        comboBox_justif_Alumno->setGeometry(QRect(620, 50, 281, 31));
        comboBox_justif_Alumno->setFont(font3);
        comboBox_justif_Alumno->setStyleSheet(QString::fromUtf8("color: rgb(9, 30, 53);"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(940, 10, 251, 61));
        label_9->setFont(font2);
        label_9->setWordWrap(true);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(940, 90, 241, 31));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(930, 510, 311, 31));
        label_10->setFont(font2);
        label_motivoReunion = new QLabel(centralwidget);
        label_motivoReunion->setObjectName("label_motivoReunion");
        label_motivoReunion->setGeometry(QRect(930, 550, 241, 71));
        label_motivoReunion->setFont(font2);
        label_motivoReunion->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        label_motivoReunion->setWordWrap(true);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(630, 530, 281, 41));
        label_11->setFont(font2);
        comboBox_cantReuniones2 = new QComboBox(centralwidget);
        comboBox_cantReuniones2->addItem(QString());
        comboBox_cantReuniones2->setObjectName("comboBox_cantReuniones2");
        comboBox_cantReuniones2->setGeometry(QRect(630, 570, 281, 41));
        comboBox_cantReuniones2->setFont(font3);
        comboBox_cantReuniones2->setStyleSheet(QString::fromUtf8("color: rgb(9, 30, 53);"));
        reuniones->setCentralWidget(centralwidget);
        menubar = new QMenuBar(reuniones);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 29));
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
        font6.setBold(false);
        menuOpciones->setFont(font6);
        menuOpciones->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(0, 0, 0);\n"
"selection-color: rgb(0, 0, 0);\n"
"color: rgb(0, 0, 0);"));
        reuniones->setMenuBar(menubar);
        statusbar = new QStatusBar(reuniones);
        statusbar->setObjectName("statusbar");
        reuniones->setStatusBar(statusbar);

        menubar->addAction(menuOpciones->menuAction());
        menuOpciones->addAction(actionCambiar_cuenta);
        menuOpciones->addSeparator();
        menuOpciones->addAction(actionVolver);
        menuOpciones->addSeparator();
        menuOpciones->addAction(actionSalir);

        retranslateUi(reuniones);

        QMetaObject::connectSlotsByName(reuniones);
    } // setupUi

    void retranslateUi(QMainWindow *reuniones)
    {
        reuniones->setWindowTitle(QCoreApplication::translate("reuniones", "MainWindow", nullptr));
        actionCambiar_cuenta->setText(QCoreApplication::translate("reuniones", "   Cambiar cuenta", nullptr));
        actionVolver->setText(QCoreApplication::translate("reuniones", "   Volver", nullptr));
        actionSalir->setText(QCoreApplication::translate("reuniones", "   Salir", nullptr));
        label_alumno->setText(QCoreApplication::translate("reuniones", "<html><head/><body><p align=\"justify\"><span style=\" color:#113158;\">Alumno (posible abandonante de la escuela):</span></p></body></html>", nullptr));
        label_fecha->setText(QCoreApplication::translate("reuniones", "<html><head/><body><p><span style=\" color:#113158;\">Fecha de la reuni\303\263n:</span></p></body></html>", nullptr));
        label_motivo->setText(QCoreApplication::translate("reuniones", "<html><head/><body><p align=\"center\"><span style=\" color:#99c1f1;\">Motivo de la reuni\303\263n:</span></p></body></html>", nullptr));
        label_mes->setText(QCoreApplication::translate("reuniones", "<html><head/><body><p><span style=\" color:#113158;\">Mes a analizar:</span></p></body></html>", nullptr));
        lineEdit_motivo->setText(QString());
        comboBox_mes->setItemText(0, QCoreApplication::translate("reuniones", "03", nullptr));
        comboBox_mes->setItemText(1, QCoreApplication::translate("reuniones", "04", nullptr));
        comboBox_mes->setItemText(2, QCoreApplication::translate("reuniones", "05", nullptr));
        comboBox_mes->setItemText(3, QCoreApplication::translate("reuniones", "06", nullptr));
        comboBox_mes->setItemText(4, QCoreApplication::translate("reuniones", "07", nullptr));
        comboBox_mes->setItemText(5, QCoreApplication::translate("reuniones", "08", nullptr));
        comboBox_mes->setItemText(6, QCoreApplication::translate("reuniones", "09", nullptr));
        comboBox_mes->setItemText(7, QCoreApplication::translate("reuniones", "10", nullptr));
        comboBox_mes->setItemText(8, QCoreApplication::translate("reuniones", "11", nullptr));
        comboBox_mes->setItemText(9, QCoreApplication::translate("reuniones", "12", nullptr));

        label->setText(QString());
        label_2->setText(QCoreApplication::translate("reuniones", "<html><head/><body><p><span style=\" font-size:16pt; color:#091e35;\">SELECCIONAR REUNI\303\223N:</span></p></body></html>", nullptr));
        comboBox_justifPadre->setItemText(0, QCoreApplication::translate("reuniones", "PRUEBA", nullptr));

        lineEdit_justifPadre->setText(QString());
        label_3->setText(QCoreApplication::translate("reuniones", "<html><head/><body><p><span style=\" font-size:16pt; color:#091e35;\">JUSTIFICACI\303\223N DEL PADRE:</span></p></body></html>", nullptr));
        btnConfirmarJustif->setText(QCoreApplication::translate("reuniones", "MODIFICAR", nullptr));
        label_4->setText(QString());
        label_5->setText(QCoreApplication::translate("reuniones", "<html><head/><body><p><span style=\" color:#e0e8f2;\">ALUMNO:</span></p></body></html>", nullptr));
        comboBox_cantReuniones->setItemText(0, QCoreApplication::translate("reuniones", "PRUEBA", nullptr));

        label_6->setText(QCoreApplication::translate("reuniones", "<html><head/><body><p><span style=\" color:#e0e8f2;\">CANTIDAD DE REUNIONES:</span></p></body></html>", nullptr));
        label_cantReuniones->setText(QCoreApplication::translate("reuniones", "<html><head/><body><p><span style=\" color:#99c1f1;\">19</span></p></body></html>", nullptr));
        btnCrearReunion->setText(QCoreApplication::translate("reuniones", "CREAR REUNI\303\223N", nullptr));
        label_8->setText(QCoreApplication::translate("reuniones", "<html><head/><body><p><span style=\" font-size:16pt; color:#091e35;\">SELECCIONAR ALUMNO:</span></p></body></html>", nullptr));
        comboBox_justif_Alumno->setItemText(0, QCoreApplication::translate("reuniones", "PRUEBA", nullptr));

        label_9->setText(QCoreApplication::translate("reuniones", "<html><head/><body><p>ALUMNO SELECCIONADO:</p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("reuniones", "<html><head/><body><p><span style=\" font-size:16pt; color:#3d3846;\">...</span></p></body></html>", nullptr));
        label_10->setText(QCoreApplication::translate("reuniones", "<html><head/><body><p><span style=\" color:#e0e8f2;\">MOTIVO:</span></p></body></html>", nullptr));
        label_motivoReunion->setText(QCoreApplication::translate("reuniones", "<html><head/><body><p><span style=\" font-size:16pt; color:#99c1f1;\">Motivo aca</span></p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("reuniones", "<html><head/><body><p><span style=\" color:#e0e8f2;\">REUNI\303\223N:</span></p></body></html>", nullptr));
        comboBox_cantReuniones2->setItemText(0, QCoreApplication::translate("reuniones", "PRUEBA", nullptr));

        menuOpciones->setTitle(QCoreApplication::translate("reuniones", "Opciones", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reuniones: public Ui_reuniones {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REUNIONES_H
