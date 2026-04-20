#ifndef RESUMEN_DE_ASIS_Y_FALTAS_H
#define RESUMEN_DE_ASIS_Y_FALTAS_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class resumen_de_asis_y_faltas;
}

class resumen_de_asis_y_faltas : public QMainWindow
{
    Q_OBJECT

public:
    explicit resumen_de_asis_y_faltas(QWidget *parent = nullptr);
    ~resumen_de_asis_y_faltas();

protected:
    void showEvent(QShowEvent *event) override;

private slots:
    void on_actionCambiar_cuenta_triggered();

    void on_actionVolver_triggered();

    void on_actionSalir_triggered();

    void mostrarResumenAlumno();

    void on_btnGuardar_clicked();

    void on_comboBoxAlumno_currentIndexChanged(int index);

    void mostrarFaltasPorMes();

    void on_comboBox_motivoRes_Alu_currentIndexChanged(int index);

    void on_comboBox_motivoRes_Fecha_currentIndexChanged(int index);

private:
    Ui::resumen_de_asis_y_faltas *ui;
    QSqlDatabase db;

    void conexionBdd();
    void cargarAlumnosConFaltas();
    void cargarMotivosDeFalta();
    void cargarAlumnosParaResumen();
};

#endif // RESUMEN_DE_ASIS_Y_FALTAS_H
