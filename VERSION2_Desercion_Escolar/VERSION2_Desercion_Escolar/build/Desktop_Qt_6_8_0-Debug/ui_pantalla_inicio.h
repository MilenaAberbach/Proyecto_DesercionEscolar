/********************************************************************************
** Form generated from reading UI file 'pantalla_inicio.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANTALLA_INICIO_H
#define UI_PANTALLA_INICIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pantalla_inicio
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *titulo_software;
    QLabel *azul_degrade;
    QLabel *logo_producto;
    QLabel *texto_software;
    QLabel *logo_equipo;
    QLabel *label_7;
    QLabel *fondo_transparente;
    QLabel *fondo_naranja;
    QLabel *descrip_software;
    QLabel *pregunta_inicio;
    QPushButton *btnContinuar;
    QPushButton *btnSalir;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *pantalla_inicio)
    {
        if (pantalla_inicio->objectName().isEmpty())
            pantalla_inicio->setObjectName("pantalla_inicio");
        pantalla_inicio->resize(800, 400);
        centralwidget = new QWidget(pantalla_inicio);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 800, 41));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(153, 193, 241);"));
        titulo_software = new QLabel(centralwidget);
        titulo_software->setObjectName("titulo_software");
        titulo_software->setGeometry(QRect(10, 60, 261, 51));
        QFont font;
        font.setPointSize(30);
        font.setWeight(QFont::DemiBold);
        titulo_software->setFont(font);
        titulo_software->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        azul_degrade = new QLabel(centralwidget);
        azul_degrade->setObjectName("azul_degrade");
        azul_degrade->setGeometry(QRect(0, 0, 800, 41));
        azul_degrade->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.455, y2:0.199, stop:0 rgba(8, 26, 128, 126), stop:0.995 rgba(255, 255, 255, 0));"));
        logo_producto = new QLabel(centralwidget);
        logo_producto->setObjectName("logo_producto");
        logo_producto->setGeometry(QRect(290, 60, 81, 71));
        logo_producto->setPixmap(QPixmap(QString::fromUtf8(":/logos/IMAGENES/logoProducto.png")));
        logo_producto->setScaledContents(true);
        texto_software = new QLabel(centralwidget);
        texto_software->setObjectName("texto_software");
        texto_software->setGeometry(QRect(470, 70, 151, 51));
        QFont font1;
        font1.setPointSize(14);
        font1.setWeight(QFont::DemiBold);
        font1.setItalic(true);
        font1.setKerning(false);
        texto_software->setFont(font1);
        texto_software->setWordWrap(true);
        logo_equipo = new QLabel(centralwidget);
        logo_equipo->setObjectName("logo_equipo");
        logo_equipo->setGeometry(QRect(670, 60, 71, 71));
        logo_equipo->setPixmap(QPixmap(QString::fromUtf8(":/logos/IMAGENES/logoEquipo.png")));
        logo_equipo->setScaledContents(true);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(-30, 199, 891, 581));
        label_7->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0.46, y1:0.0857274, x2:0.48, y2:1, stop:0 rgba(255, 255, 255, 123), stop:1 rgba(255, 255, 255, 105));"));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/logos/IMAGENES/fondito_faltas.jpeg")));
        label_7->setScaledContents(true);
        fondo_transparente = new QLabel(centralwidget);
        fondo_transparente->setObjectName("fondo_transparente");
        fondo_transparente->setGeometry(QRect(-10, 190, 821, 521));
        fondo_transparente->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0.46, y1:0.0857274, x2:0.48, y2:1, stop:0 rgba(255, 255, 255, 172), stop:1 rgba(255, 255, 255, 173));"));
        fondo_naranja = new QLabel(centralwidget);
        fondo_naranja->setObjectName("fondo_naranja");
        fondo_naranja->setGeometry(QRect(460, 60, 291, 71));
        fondo_naranja->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0.506, x2:0.64, y2:0.522727, stop:0 rgba(255, 190, 111, 255), stop:1 rgba(255, 255, 255, 255));"));
        descrip_software = new QLabel(centralwidget);
        descrip_software->setObjectName("descrip_software");
        descrip_software->setGeometry(QRect(10, 120, 241, 51));
        QFont font2;
        font2.setWeight(QFont::Medium);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setStrikeOut(false);
        font2.setKerning(true);
        descrip_software->setFont(font2);
        descrip_software->setAlignment(Qt::AlignmentFlag::AlignJustify|Qt::AlignmentFlag::AlignVCenter);
        descrip_software->setWordWrap(true);
        pregunta_inicio = new QLabel(centralwidget);
        pregunta_inicio->setObjectName("pregunta_inicio");
        pregunta_inicio->setGeometry(QRect(40, 210, 651, 61));
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        pregunta_inicio->setFont(font3);
        pregunta_inicio->setStyleSheet(QString::fromUtf8("color: rgb(36, 31, 49);"));
        btnContinuar = new QPushButton(centralwidget);
        btnContinuar->setObjectName("btnContinuar");
        btnContinuar->setGeometry(QRect(40, 280, 301, 41));
        QFont font4;
        font4.setPointSize(15);
        font4.setBold(true);
        btnContinuar->setFont(font4);
        btnContinuar->setStyleSheet(QString::fromUtf8("border-radius: 20px;\n"
"color: rgb(38, 162, 105);\n"
"background-color: rgb(143, 240, 164);"));
        btnSalir = new QPushButton(centralwidget);
        btnSalir->setObjectName("btnSalir");
        btnSalir->setGeometry(QRect(380, 280, 301, 41));
        btnSalir->setFont(font4);
        btnSalir->setStyleSheet(QString::fromUtf8("border-radius: 20px;\n"
"color: rgb(165, 29, 45);\n"
"background-color: rgb(246, 97, 81);"));
        pantalla_inicio->setCentralWidget(centralwidget);
        fondo_naranja->raise();
        label_7->raise();
        fondo_transparente->raise();
        label->raise();
        azul_degrade->raise();
        titulo_software->raise();
        logo_producto->raise();
        texto_software->raise();
        logo_equipo->raise();
        descrip_software->raise();
        pregunta_inicio->raise();
        btnContinuar->raise();
        btnSalir->raise();
        statusbar = new QStatusBar(pantalla_inicio);
        statusbar->setObjectName("statusbar");
        pantalla_inicio->setStatusBar(statusbar);

        retranslateUi(pantalla_inicio);

        QMetaObject::connectSlotsByName(pantalla_inicio);
    } // setupUi

    void retranslateUi(QMainWindow *pantalla_inicio)
    {
        pantalla_inicio->setWindowTitle(QCoreApplication::translate("pantalla_inicio", "pantalla_inicio", nullptr));
        label->setText(QString());
        titulo_software->setText(QCoreApplication::translate("pantalla_inicio", "<html><head/><body><p><span style=\" text-decoration: underline; color:#2fa56f;\">BackToLearn!</span></p></body></html>", nullptr));
        azul_degrade->setText(QString());
        logo_producto->setText(QString());
        texto_software->setText(QCoreApplication::translate("pantalla_inicio", "<html><head/><body><p><span style=\" color:#e66100;\">Software creado por A &amp; F</span></p></body></html>", nullptr));
        logo_equipo->setText(QString());
        label_7->setText(QString());
        fondo_transparente->setText(QString());
        fondo_naranja->setText(QCoreApplication::translate("pantalla_inicio", "<html><head/><body><p><br/></p></body></html>", nullptr));
        descrip_software->setText(QCoreApplication::translate("pantalla_inicio", "<html><head/><body><p><span style=\" color:#1a5fb4;\">El objetivo principal de este programa es combatir la deserci\303\263n escolar</span></p></body></html>", nullptr));
        pregunta_inicio->setText(QCoreApplication::translate("pantalla_inicio", "\302\277DIRIGIRSE A LA PANTALLA DE INICIO DE SESI\303\223N?", nullptr));
        btnContinuar->setText(QCoreApplication::translate("pantalla_inicio", "CONTINUAR", nullptr));
        btnSalir->setText(QCoreApplication::translate("pantalla_inicio", "SALIR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pantalla_inicio: public Ui_pantalla_inicio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANTALLA_INICIO_H
