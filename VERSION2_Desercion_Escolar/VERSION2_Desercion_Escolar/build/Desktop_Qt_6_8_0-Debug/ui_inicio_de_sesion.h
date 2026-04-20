/********************************************************************************
** Form generated from reading UI file 'inicio_de_sesion.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INICIO_DE_SESION_H
#define UI_INICIO_DE_SESION_H

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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inicio_de_sesion
{
public:
    QAction *actionVolver;
    QAction *actionSalir;
    QWidget *centralwidget;
    QLabel *label_completardatos;
    QLabel *fondo_grisoscuro;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_mail;
    QLineEdit *lEdit_mail;
    QLabel *label_contrasena;
    QLineEdit *lEdit_contrasena;
    QPushButton *btnIniciar;
    QPushButton *btnOlvide;
    QLabel *fondo_grisclaro;
    QLabel *label_4;
    QLabel *label_degrade;
    QLabel *label_degrade_2;
    QLabel *label_degrade_3;
    QLabel *FONDO_TOTAL;
    QMenuBar *menubar;
    QMenu *menuOpciones;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *inicio_de_sesion)
    {
        if (inicio_de_sesion->objectName().isEmpty())
            inicio_de_sesion->setObjectName("inicio_de_sesion");
        inicio_de_sesion->resize(558, 450);
        inicio_de_sesion->setStyleSheet(QString::fromUtf8(""));
        actionVolver = new QAction(inicio_de_sesion);
        actionVolver->setObjectName("actionVolver");
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::EditUndo));
        actionVolver->setIcon(icon);
        actionSalir = new QAction(inicio_de_sesion);
        actionSalir->setObjectName("actionSalir");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        actionSalir->setIcon(icon1);
        centralwidget = new QWidget(inicio_de_sesion);
        centralwidget->setObjectName("centralwidget");
        label_completardatos = new QLabel(centralwidget);
        label_completardatos->setObjectName("label_completardatos");
        label_completardatos->setGeometry(QRect(250, 30, 231, 18));
        QFont font;
        font.setPointSize(13);
        label_completardatos->setFont(font);
        fondo_grisoscuro = new QLabel(centralwidget);
        fondo_grisoscuro->setObjectName("fondo_grisoscuro");
        fondo_grisoscuro->setGeometry(QRect(240, 60, 271, 311));
        fondo_grisoscuro->setStyleSheet(QString::fromUtf8("border-radius: 20px;\n"
"background-color: rgb(222, 221, 218);"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(270, 80, 211, 151));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_mail = new QLabel(verticalLayoutWidget);
        label_mail->setObjectName("label_mail");
        QFont font1;
        font1.setBold(true);
        label_mail->setFont(font1);

        verticalLayout->addWidget(label_mail);

        lEdit_mail = new QLineEdit(verticalLayoutWidget);
        lEdit_mail->setObjectName("lEdit_mail");

        verticalLayout->addWidget(lEdit_mail);

        label_contrasena = new QLabel(verticalLayoutWidget);
        label_contrasena->setObjectName("label_contrasena");
        label_contrasena->setFont(font1);

        verticalLayout->addWidget(label_contrasena);

        lEdit_contrasena = new QLineEdit(verticalLayoutWidget);
        lEdit_contrasena->setObjectName("lEdit_contrasena");
        lEdit_contrasena->setStyleSheet(QString::fromUtf8("padding-left: 5px;"));

        verticalLayout->addWidget(lEdit_contrasena);

        label_contrasena->raise();
        lEdit_mail->raise();
        label_mail->raise();
        lEdit_contrasena->raise();
        btnIniciar = new QPushButton(centralwidget);
        btnIniciar->setObjectName("btnIniciar");
        btnIniciar->setGeometry(QRect(260, 265, 231, 41));
        QFont font2;
        font2.setWeight(QFont::Medium);
        btnIniciar->setFont(font2);
        btnIniciar->setStyleSheet(QString::fromUtf8("color: rgb(47, 165, 111);\n"
"background-color: rgb(193, 241, 204);"));
        btnOlvide = new QPushButton(centralwidget);
        btnOlvide->setObjectName("btnOlvide");
        btnOlvide->setGeometry(QRect(260, 330, 191, 26));
        QFont font3;
        font3.setWeight(QFont::Medium);
        font3.setItalic(true);
        font3.setUnderline(true);
        btnOlvide->setFont(font3);
        btnOlvide->setStyleSheet(QString::fromUtf8("border: 1px;\n"
"color: rgb(53, 132, 228);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 0), stop:1 rgba(255, 255, 255, 0));\n"
""));
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::HelpFaq));
        btnOlvide->setIcon(icon2);
        fondo_grisclaro = new QLabel(centralwidget);
        fondo_grisclaro->setObjectName("fondo_grisclaro");
        fondo_grisclaro->setGeometry(QRect(260, 80, 231, 165));
        fondo_grisclaro->setStyleSheet(QString::fromUtf8("background-color: rgb(246, 245, 244);"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(-80, 0, 391, 451));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/logos/IMAGENES/green_pattern.png")));
        label_4->setScaledContents(true);
        label_degrade = new QLabel(centralwidget);
        label_degrade->setObjectName("label_degrade");
        label_degrade->setGeometry(QRect(-10, -50, 341, 471));
        label_degrade->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0.511364, x2:0.775, y2:0.545455, stop:0 rgba(0, 0, 0, 0), stop:1 rgba(240, 243, 247, 255));"));
        label_degrade_2 = new QLabel(centralwidget);
        label_degrade_2->setObjectName("label_degrade_2");
        label_degrade_2->setGeometry(QRect(0, -10, 291, 141));
        label_degrade_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0.465, y1:0.131, x2:0.495, y2:1, stop:0 rgba(240, 243, 247, 255), stop:1 rgba(255, 255, 255, 0));"));
        label_degrade_3 = new QLabel(centralwidget);
        label_degrade_3->setObjectName("label_degrade_3");
        label_degrade_3->setGeometry(QRect(-10, 0, 291, 411));
        label_degrade_3->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0.43, y1:0, x2:0.51, y2:1, stop:0 rgba(28, 113, 216, 109), stop:1 rgba(53, 132, 228, 107));"));
        FONDO_TOTAL = new QLabel(centralwidget);
        FONDO_TOTAL->setObjectName("FONDO_TOTAL");
        FONDO_TOTAL->setGeometry(QRect(-105, 0, 791, 431));
        FONDO_TOTAL->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 243, 247);"));
        inicio_de_sesion->setCentralWidget(centralwidget);
        FONDO_TOTAL->raise();
        label_degrade_2->raise();
        label_4->raise();
        label_degrade_3->raise();
        label_degrade->raise();
        fondo_grisoscuro->raise();
        fondo_grisclaro->raise();
        verticalLayoutWidget->raise();
        label_completardatos->raise();
        btnIniciar->raise();
        btnOlvide->raise();
        menubar = new QMenuBar(inicio_de_sesion);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 558, 29));
        QFont font4;
        font4.setPointSize(15);
        font4.setWeight(QFont::Medium);
        menubar->setFont(font4);
        menubar->setAutoFillBackground(true);
        menubar->setStyleSheet(QString::fromUtf8("color: rgb(255, 120, 0);\n"
"alternate-background-color: rgb(255, 190, 111);\n"
"selection-background-color: rgb(255, 190, 111);\n"
""));
        menuOpciones = new QMenu(menubar);
        menuOpciones->setObjectName("menuOpciones");
        menuOpciones->setGeometry(QRect(315, 157, 170, 114));
        menuOpciones->setFont(font);
        menuOpciones->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(0, 0, 0);\n"
"selection-color: rgb(0, 0, 0);\n"
"color: rgb(0, 0, 0);"));
        inicio_de_sesion->setMenuBar(menubar);
        statusbar = new QStatusBar(inicio_de_sesion);
        statusbar->setObjectName("statusbar");
        inicio_de_sesion->setStatusBar(statusbar);

        menubar->addAction(menuOpciones->menuAction());
        menuOpciones->addAction(actionVolver);
        menuOpciones->addSeparator();
        menuOpciones->addAction(actionSalir);

        retranslateUi(inicio_de_sesion);

        QMetaObject::connectSlotsByName(inicio_de_sesion);
    } // setupUi

    void retranslateUi(QMainWindow *inicio_de_sesion)
    {
        inicio_de_sesion->setWindowTitle(QCoreApplication::translate("inicio_de_sesion", "MainWindow", nullptr));
        actionVolver->setText(QCoreApplication::translate("inicio_de_sesion", "   Volver", nullptr));
        actionSalir->setText(QCoreApplication::translate("inicio_de_sesion", "   Salir", nullptr));
        label_completardatos->setText(QCoreApplication::translate("inicio_de_sesion", "<html><head/><body><p><span style=\" color:#3d3846;\">Complet\303\241 los siguientes datos:</span></p></body></html>", nullptr));
        fondo_grisoscuro->setText(QString());
        label_mail->setText(QCoreApplication::translate("inicio_de_sesion", "<html><head/><body><p><span style=\" color:#3d3846;\">Mail institucional:</span></p></body></html>", nullptr));
        lEdit_mail->setPlaceholderText(QCoreApplication::translate("inicio_de_sesion", "Ingrese su email ac\303\241", nullptr));
        label_contrasena->setText(QCoreApplication::translate("inicio_de_sesion", "<html><head/><body><p><span style=\" color:#3d3846;\">Contrase\303\261a:</span></p></body></html>", nullptr));
        lEdit_contrasena->setText(QString());
        lEdit_contrasena->setPlaceholderText(QCoreApplication::translate("inicio_de_sesion", "Ingrese su contrase\303\261a ac\303\241", nullptr));
        btnIniciar->setText(QCoreApplication::translate("inicio_de_sesion", "INICIAR SESI\303\223N", nullptr));
        btnOlvide->setText(QCoreApplication::translate("inicio_de_sesion", "  Olvid\303\251 mi contrase\303\261a", nullptr));
        fondo_grisclaro->setText(QString());
        label_4->setText(QString());
        label_degrade->setText(QString());
        label_degrade_2->setText(QString());
        label_degrade_3->setText(QString());
        FONDO_TOTAL->setText(QCoreApplication::translate("inicio_de_sesion", "TextLabel", nullptr));
        menuOpciones->setTitle(QCoreApplication::translate("inicio_de_sesion", "Opciones", nullptr));
    } // retranslateUi

};

namespace Ui {
    class inicio_de_sesion: public Ui_inicio_de_sesion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICIO_DE_SESION_H
