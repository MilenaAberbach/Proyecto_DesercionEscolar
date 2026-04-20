#ifndef REGISTRO_DE_ASISTENCIAS_H
#define REGISTRO_DE_ASISTENCIAS_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class registro_de_asistencias;
}

class registro_de_asistencias : public QMainWindow
{
    Q_OBJECT

public:
    explicit registro_de_asistencias(QWidget *parent = nullptr);
    ~registro_de_asistencias();

protected:
    void showEvent(QShowEvent *event) override;

private slots:
    void on_actionCambiar_cuenta_triggered();

    void on_actionVolver_triggered();

    void on_actionSalir_triggered();

    void onSemanaSeleccionada();

    void guardarAsistencias();

private:
    Ui::registro_de_asistencias *ui;
    QSqlDatabase db;

    void conexionBdd();
    void cargarSemanas();
    QList<QDate> obtenerFechasDeSemana(int semana);
    void actualizarTablaAsistencias(int semana);
};

#endif // REGISTRO_DE_ASISTENCIAS_H
