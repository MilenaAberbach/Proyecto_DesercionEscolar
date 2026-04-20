/********************************************************************************
** Form generated from reading UI file 'posibles_abandonantes.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSIBLES_ABANDONANTES_H
#define UI_POSIBLES_ABANDONANTES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_posibles_abandonantes
{
public:
    QAction *actionCambiar_cuenta;
    QAction *actionVolver;
    QAction *actionSalir;
    QWidget *centralwidget;
    QLabel *label;
    QTableView *tableView;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QMenu *menuOpciones;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *posibles_abandonantes)
    {
        if (posibles_abandonantes->objectName().isEmpty())
            posibles_abandonantes->setObjectName("posibles_abandonantes");
        posibles_abandonantes->resize(1100, 680);
        actionCambiar_cuenta = new QAction(posibles_abandonantes);
        actionCambiar_cuenta->setObjectName("actionCambiar_cuenta");
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("x-office-address-book")));
        actionCambiar_cuenta->setIcon(icon);
        actionVolver = new QAction(posibles_abandonantes);
        actionVolver->setObjectName("actionVolver");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::EditUndo));
        actionVolver->setIcon(icon1);
        actionSalir = new QAction(posibles_abandonantes);
        actionSalir->setObjectName("actionSalir");
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        actionSalir->setIcon(icon2);
        centralwidget = new QWidget(posibles_abandonantes);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(260, 50, 500, 31));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(55, 120, 991, 441));
        tableView->setStyleSheet(QString::fromUtf8("color: rgb(17, 49, 88);\n"
"background-color: rgb(224, 232, 242);\n"
"border-color: rgb(17, 49, 88);"));
        tableView->setFrameShape(QFrame::Shape::Panel);
        tableView->setFrameShadow(QFrame::Shadow::Plain);
        tableView->setLineWidth(2);
        tableView->setShowGrid(true);
        tableView->setGridStyle(Qt::PenStyle::SolidLine);
        tableView->setCornerButtonEnabled(false);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(800, 10, 281, 101));
        QFont font1;
        font1.setPointSize(13);
        label_2->setFont(font1);
        label_2->setWordWrap(true);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(-20, 0, 1131, 680));
        label_3->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0.49, y1:1, x2:0.48, y2:0.648, stop:0 rgba(20, 44, 79, 153), stop:1 rgba(255, 255, 255, 0));"));
        posibles_abandonantes->setCentralWidget(centralwidget);
        menubar = new QMenuBar(posibles_abandonantes);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1100, 29));
        QFont font2;
        font2.setPointSize(15);
        menubar->setFont(font2);
        menubar->setStyleSheet(QString::fromUtf8("color: rgb(255, 120, 0);\n"
"alternate-background-color: rgb(255, 190, 111);\n"
"selection-background-color: rgb(255, 190, 111);"));
        menuOpciones = new QMenu(menubar);
        menuOpciones->setObjectName("menuOpciones");
        menuOpciones->setFont(font1);
        menuOpciones->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(0, 0, 0);\n"
"selection-color: rgb(0, 0, 0);\n"
"color: rgb(0, 0, 0);"));
        posibles_abandonantes->setMenuBar(menubar);
        statusbar = new QStatusBar(posibles_abandonantes);
        statusbar->setObjectName("statusbar");
        posibles_abandonantes->setStatusBar(statusbar);

        menubar->addAction(menuOpciones->menuAction());
        menuOpciones->addAction(actionCambiar_cuenta);
        menuOpciones->addSeparator();
        menuOpciones->addAction(actionVolver);
        menuOpciones->addSeparator();
        menuOpciones->addAction(actionSalir);

        retranslateUi(posibles_abandonantes);

        QMetaObject::connectSlotsByName(posibles_abandonantes);
    } // setupUi

    void retranslateUi(QMainWindow *posibles_abandonantes)
    {
        posibles_abandonantes->setWindowTitle(QCoreApplication::translate("posibles_abandonantes", "MainWindow", nullptr));
        actionCambiar_cuenta->setText(QCoreApplication::translate("posibles_abandonantes", "   Cambiar cuenta", nullptr));
        actionVolver->setText(QCoreApplication::translate("posibles_abandonantes", "   Volver", nullptr));
        actionSalir->setText(QCoreApplication::translate("posibles_abandonantes", "   Salir", nullptr));
        label->setText(QCoreApplication::translate("posibles_abandonantes", "<html><head/><body><p><span style=\" color:#113158;\">TABLA DE POSIBLES ABANDONANTES</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("posibles_abandonantes", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700; color:#3d3846;\">Criterios del an\303\241lisis:</span></p><p><span style=\" font-size:14pt; font-style:italic; color:#3d3846;\">- 3 faltas consecutivas por mes</span></p><p><span style=\" font-size:14pt; font-style:italic; color:#3d3846;\">- M\303\241s de 15 faltas acumuladas por mes</span></p></body></html>", nullptr));
        label_3->setText(QString());
        menuOpciones->setTitle(QCoreApplication::translate("posibles_abandonantes", "Opciones", nullptr));
    } // retranslateUi

};

namespace Ui {
    class posibles_abandonantes: public Ui_posibles_abandonantes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSIBLES_ABANDONANTES_H
