#ifndef LISTADO_DE_ALUMNOS_H
#define LISTADO_DE_ALUMNOS_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class listado_de_alumnos;
}

class listado_de_alumnos : public QMainWindow
{
    Q_OBJECT

public:
    explicit listado_de_alumnos(QWidget *parent = nullptr);
    ~listado_de_alumnos();

protected:
    void showEvent(QShowEvent *event) override;

private slots:
    void on_actionCambiar_cuenta_triggered();

    void on_actionVolver_triggered();

    void on_actionSalir_triggered();

    void on_lEdit_barraBusqueda_textChanged(const QString &arg1);

    void on_comboBoxOrdenamiento_currentIndexChanged(int columna);

    void on_comboBoxOrdAscDesc_currentIndexChanged(int index);

private:
    Ui::listado_de_alumnos *ui;
    QSqlDatabase db;

    void conexionBdd();
    void cargarDatos(const QString &filtro, const QString &columnaOrden, bool ascendente);
};

#endif // LISTADO_DE_ALUMNOS_H
