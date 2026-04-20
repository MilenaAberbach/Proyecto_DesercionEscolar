#ifndef MODIFICACION_DE_ALUMNOS_H
#define MODIFICACION_DE_ALUMNOS_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class modificacion_de_alumnos;
}

class modificacion_de_alumnos : public QMainWindow
{
    Q_OBJECT

public:
    explicit modificacion_de_alumnos(QWidget *parent = nullptr);
    ~modificacion_de_alumnos();

protected:
    void showEvent(QShowEvent *event) override;

private slots:
    void on_actionCambiar_cuenta_triggered();

    void on_actionVolver_triggered();

    void on_actionSalir_triggered();

    void on_comboBoxAlumno_currentIndexChanged();

    void on_checkBoxNombre(int estado);

    void on_checkBoxApellido(int estado);

    void on_checkBoxEdad(int estado);

    void on_confirmarModificacionAlumno_clicked();

private:
    Ui::modificacion_de_alumnos *ui;
    QSqlDatabase db;

    void conexionBdd();
    void datosComboAlumno();
};

#endif // MODIFICACION_DE_ALUMNOS_H
