/********************************************************************************
** Form generated from reading UI file 'olvide_mi_contrasena.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OLVIDE_MI_CONTRASENA_H
#define UI_OLVIDE_MI_CONTRASENA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
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

class Ui_olvide_mi_contrasena
{
public:
    QAction *actionVolver;
    QAction *actionSalir;
    QWidget *centralwidget;
    QPushButton *btnRecuperar;
    QLabel *label_3;
    QLabel *label_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_pregunta;
    QLineEdit *lEdit_respuesta;
    QLabel *label_respuesta;
    QLineEdit *lEdit_nuevaContrasena;
    QLineEdit *lEdit_mail;
    QLabel *label_respuesta_2;
    QMenuBar *menubar;
    QMenu *menuOpciones;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *olvide_mi_contrasena)
    {
        if (olvide_mi_contrasena->objectName().isEmpty())
            olvide_mi_contrasena->setObjectName("olvide_mi_contrasena");
        olvide_mi_contrasena->resize(800, 389);
        actionVolver = new QAction(olvide_mi_contrasena);
        actionVolver->setObjectName("actionVolver");
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::EditUndo));
        actionVolver->setIcon(icon);
        actionSalir = new QAction(olvide_mi_contrasena);
        actionSalir->setObjectName("actionSalir");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        actionSalir->setIcon(icon1);
        centralwidget = new QWidget(olvide_mi_contrasena);
        centralwidget->setObjectName("centralwidget");
        btnRecuperar = new QPushButton(centralwidget);
        btnRecuperar->setObjectName("btnRecuperar");
        btnRecuperar->setGeometry(QRect(310, 250, 361, 41));
        QFont font;
        font.setPointSize(13);
        font.setWeight(QFont::DemiBold);
        btnRecuperar->setFont(font);
        btnRecuperar->setStyleSheet(QString::fromUtf8("color: rgb(26, 95, 180);\n"
"background-color: rgb(153, 193, 241);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(310, 70, 361, 161));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(246, 245, 244);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(290, 50, 401, 261));
        label_2->setStyleSheet(QString::fromUtf8("border-radius: 20px;\n"
"background-color: rgb(222, 221, 218);"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(320, 70, 341, 151));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_pregunta = new QLabel(verticalLayoutWidget);
        label_pregunta->setObjectName("label_pregunta");
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        label_pregunta->setFont(font1);
        label_pregunta->setWordWrap(true);

        verticalLayout->addWidget(label_pregunta);

        lEdit_respuesta = new QLineEdit(verticalLayoutWidget);
        lEdit_respuesta->setObjectName("lEdit_respuesta");
        QFont font2;
        font2.setPointSize(13);
        lEdit_respuesta->setFont(font2);
        lEdit_respuesta->setStyleSheet(QString::fromUtf8("padding-left: 5px;"));
        lEdit_respuesta->setFrame(true);
        lEdit_respuesta->setCursorMoveStyle(Qt::CursorMoveStyle::VisualMoveStyle);
        lEdit_respuesta->setClearButtonEnabled(false);

        verticalLayout->addWidget(lEdit_respuesta);

        label_respuesta = new QLabel(verticalLayoutWidget);
        label_respuesta->setObjectName("label_respuesta");
        label_respuesta->setFont(font1);

        verticalLayout->addWidget(label_respuesta);

        lEdit_nuevaContrasena = new QLineEdit(verticalLayoutWidget);
        lEdit_nuevaContrasena->setObjectName("lEdit_nuevaContrasena");
        lEdit_nuevaContrasena->setFont(font2);
        lEdit_nuevaContrasena->setStyleSheet(QString::fromUtf8("padding-left: 5px;"));
        lEdit_nuevaContrasena->setFrame(true);
        lEdit_nuevaContrasena->setClearButtonEnabled(false);

        verticalLayout->addWidget(lEdit_nuevaContrasena);

        lEdit_nuevaContrasena->raise();
        label_respuesta->raise();
        label_pregunta->raise();
        lEdit_respuesta->raise();
        lEdit_mail = new QLineEdit(centralwidget);
        lEdit_mail->setObjectName("lEdit_mail");
        lEdit_mail->setGeometry(QRect(30, 130, 231, 26));
        QFont font3;
        font3.setPointSize(15);
        font3.setWeight(QFont::DemiBold);
        lEdit_mail->setFont(font3);
        lEdit_mail->setStyleSheet(QString::fromUtf8("color: rgb(29, 119, 69);"));
        label_respuesta_2 = new QLabel(centralwidget);
        label_respuesta_2->setObjectName("label_respuesta_2");
        label_respuesta_2->setGeometry(QRect(30, 80, 181, 39));
        QFont font4;
        font4.setPointSize(15);
        font4.setBold(true);
        label_respuesta_2->setFont(font4);
        olvide_mi_contrasena->setCentralWidget(centralwidget);
        label_2->raise();
        btnRecuperar->raise();
        label_3->raise();
        verticalLayoutWidget->raise();
        lEdit_mail->raise();
        label_respuesta_2->raise();
        menubar = new QMenuBar(olvide_mi_contrasena);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 29));
        QFont font5;
        font5.setPointSize(15);
        menubar->setFont(font5);
        menubar->setStyleSheet(QString::fromUtf8("color: rgb(255, 120, 0);\n"
"alternate-background-color: rgb(255, 190, 111);\n"
"selection-background-color: rgb(255, 190, 111);"));
        menuOpciones = new QMenu(menubar);
        menuOpciones->setObjectName("menuOpciones");
        menuOpciones->setFont(font2);
        menuOpciones->setStyleSheet(QString::fromUtf8("selection-color: rgb(0, 0, 0);\n"
"color: rgb(0, 0, 0);"));
        olvide_mi_contrasena->setMenuBar(menubar);
        statusbar = new QStatusBar(olvide_mi_contrasena);
        statusbar->setObjectName("statusbar");
        olvide_mi_contrasena->setStatusBar(statusbar);

        menubar->addAction(menuOpciones->menuAction());
        menuOpciones->addAction(actionVolver);
        menuOpciones->addSeparator();
        menuOpciones->addAction(actionSalir);

        retranslateUi(olvide_mi_contrasena);

        QMetaObject::connectSlotsByName(olvide_mi_contrasena);
    } // setupUi

    void retranslateUi(QMainWindow *olvide_mi_contrasena)
    {
        olvide_mi_contrasena->setWindowTitle(QCoreApplication::translate("olvide_mi_contrasena", "MainWindow", nullptr));
        actionVolver->setText(QCoreApplication::translate("olvide_mi_contrasena", "   Volver", nullptr));
        actionSalir->setText(QCoreApplication::translate("olvide_mi_contrasena", "   Salir", nullptr));
        btnRecuperar->setText(QCoreApplication::translate("olvide_mi_contrasena", "RECUPERAR CONTRASE\303\221A", nullptr));
        label_3->setText(QString());
        label_2->setText(QString());
        label_pregunta->setText(QCoreApplication::translate("olvide_mi_contrasena", "<html><head/><body><p><span style=\" color:#3d3846;\">Respuesta de la pregunta de seguridad:</span></p></body></html>", nullptr));
        lEdit_respuesta->setText(QString());
        lEdit_respuesta->setPlaceholderText(QCoreApplication::translate("olvide_mi_contrasena", "Si nunca registr\303\263 una, ponga lo que quiera", nullptr));
        label_respuesta->setText(QCoreApplication::translate("olvide_mi_contrasena", "<html><head/><body><p><span style=\" color:#3d3846;\">Nueva contrase\303\261a:</span></p></body></html>", nullptr));
        lEdit_nuevaContrasena->setText(QString());
        lEdit_nuevaContrasena->setPlaceholderText(QCoreApplication::translate("olvide_mi_contrasena", "Ingrese la nueva contrase\303\261a aqu\303\255", nullptr));
        lEdit_mail->setPlaceholderText(QCoreApplication::translate("olvide_mi_contrasena", "Ingrese su email aqu\303\255", nullptr));
        label_respuesta_2->setText(QCoreApplication::translate("olvide_mi_contrasena", "<html><head/><body><p><span style=\" color:#33d17a;\">Mail institucional:</span></p></body></html>", nullptr));
        menuOpciones->setTitle(QCoreApplication::translate("olvide_mi_contrasena", "Opciones", nullptr));
    } // retranslateUi

};

namespace Ui {
    class olvide_mi_contrasena: public Ui_olvide_mi_contrasena {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OLVIDE_MI_CONTRASENA_H
