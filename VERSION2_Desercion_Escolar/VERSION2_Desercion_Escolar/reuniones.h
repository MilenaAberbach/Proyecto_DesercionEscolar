#ifndef REUNIONES_H
#define REUNIONES_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QComboBox>

namespace Ui {
class reuniones;
}

class reuniones : public QMainWindow
{
    Q_OBJECT

public:
    explicit reuniones(QWidget *parent = nullptr);
    ~reuniones();

protected:
    void showEvent(QShowEvent *event) override;

private slots:
    void on_actionCambiar_cuenta_triggered();

    void on_actionVolver_triggered();

    void on_actionSalir_triggered();

    void on_comboBox_mes_currentIndexChanged(int index);

    void on_btnCrearReunion_clicked();

    void on_comboBox_justif_Alumno_currentIndexChanged(int index);

    void on_btnConfirmarJustif_clicked();

    void actualizarCantidadReuniones();

    void actualizarIdAlumno(int index);

    void on_comboBox_cantReuniones_currentIndexChanged(int index);

    void on_comboBox_cantReuniones2_currentIndexChanged(int index);

private:
    Ui::reuniones *ui;
    QSqlDatabase db;
    QString mesSeleccionado; // Almacena el mes seleccionado

    void conexionBdd();
    void cargarAlumnosFaltas(QComboBox *comboBox_alumno, QString mesSeleccionado);
    void cargarFechas(QComboBox *comboBox_fecha, QString mesSeleccionado);
    void cargarAlumnosConReuniones();
    void cargarReunionesAlumno();
};

#endif // REUNIONES_H
