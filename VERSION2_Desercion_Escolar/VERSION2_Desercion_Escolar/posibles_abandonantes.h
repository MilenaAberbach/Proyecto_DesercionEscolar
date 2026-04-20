#ifndef POSIBLES_ABANDONANTES_H
#define POSIBLES_ABANDONANTES_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class posibles_abandonantes;
}

class posibles_abandonantes : public QMainWindow
{
    Q_OBJECT

public:
    explicit posibles_abandonantes(QWidget *parent = nullptr);
    ~posibles_abandonantes();

protected:
    void showEvent(QShowEvent *event) override;

private slots:
    void on_actionCambiar_cuenta_triggered();

    void on_actionVolver_triggered();

    void on_actionSalir_triggered();

private:
    Ui::posibles_abandonantes *ui;
    QSqlDatabase db;
    QSqlQueryModel *model; // Modelo de datos para manejar resultados de consultas.

    void conexionBdd();
    void cargarAbandonantes(); // Carga los posibles alumnos abandonantes desde la base de datos.
};

#endif // POSIBLES_ABANDONANTES_H
