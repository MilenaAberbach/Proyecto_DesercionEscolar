#ifndef INICIO_DE_SESION_H
#define INICIO_DE_SESION_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include "olvide_mi_contrasena.h"
#include "menu_herramientas.h"

namespace Ui {
class inicio_de_sesion;
}

class inicio_de_sesion : public QMainWindow
{
    Q_OBJECT

public:
    explicit inicio_de_sesion(QWidget *parent = nullptr);
    ~inicio_de_sesion();

protected:
    void showEvent(QShowEvent *event) override;

private slots:
    void on_actionVolver_triggered();

    void on_actionSalir_triggered();

    void on_btnIniciar_clicked();

    void on_btnOlvide_clicked();

private:
    Ui::inicio_de_sesion *ui;
    QSqlDatabase db;
    olvide_mi_contrasena *olvideContra;
    menu_herramientas *menuHerramientas;
    void conexionBdd();
};

#endif // INICIO_DE_SESION_H
