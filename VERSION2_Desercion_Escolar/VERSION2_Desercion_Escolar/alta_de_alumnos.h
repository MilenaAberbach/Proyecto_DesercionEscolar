#ifndef ALTA_DE_ALUMNOS_H
#define ALTA_DE_ALUMNOS_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class alta_de_alumnos;
}

class alta_de_alumnos : public QMainWindow
{
    Q_OBJECT

public:
    explicit alta_de_alumnos(QWidget *parent = nullptr);
    ~alta_de_alumnos();

private slots:
    void on_actionCambiar_cuenta_triggered();

    void on_actionVolver_triggered();

    void on_actionSalir_triggered();

    void on_confirmarAltaAlumno_clicked();

private:
    Ui::alta_de_alumnos *ui;
    QSqlDatabase db;

    void conexionBdd();
};

#endif // ALTA_DE_ALUMNOS_H
