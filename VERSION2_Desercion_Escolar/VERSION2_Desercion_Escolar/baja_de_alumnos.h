#ifndef BAJA_DE_ALUMNOS_H
#define BAJA_DE_ALUMNOS_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class baja_de_alumnos;
}

class baja_de_alumnos : public QMainWindow
{
    Q_OBJECT

public:
    explicit baja_de_alumnos(QWidget *parent = nullptr);
    ~baja_de_alumnos();

protected:
    void showEvent(QShowEvent *event) override;

private slots:
    void on_actionCambiar_cuenta_triggered();

    void on_actionVolver_triggered();

    void on_actionSalir_triggered();

    void on_comboBoxAlumno_currentIndexChanged();

    void on_confirmarBajaAlumno_clicked();

private:
    Ui::baja_de_alumnos *ui;
    QSqlDatabase db;

    void conexionBdd();
    void datosComboAlumno();
};

#endif // BAJA_DE_ALUMNOS_H
