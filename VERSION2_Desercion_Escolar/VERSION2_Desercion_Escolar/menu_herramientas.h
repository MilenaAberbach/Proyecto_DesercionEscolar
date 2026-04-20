#ifndef MENU_HERRAMIENTAS_H
#define MENU_HERRAMIENTAS_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include "alta_de_alumnos.h"
#include "baja_de_alumnos.h"
#include "modificacion_de_alumnos.h"
#include "listado_de_alumnos.h"
#include "registro_de_asistencias.h"
#include "resumen_de_asis_y_faltas.h"
#include "posibles_abandonantes.h"
#include "reuniones.h"

namespace Ui {
class menu_herramientas;
}

class menu_herramientas : public QMainWindow
{
    Q_OBJECT

public:
    void setDatosUsuario(const QString &nombre, const QString &cargo);
    explicit menu_herramientas(QWidget *parent = nullptr);
    ~menu_herramientas();

private slots:

    void on_actionCambiarCuenta_triggered();

    void on_actionSalir_triggered();

    void on_actionAlta_triggered();

    void on_actionBaja_triggered();

    void on_actionModificacion_triggered();

    void on_actionListado_triggered();

    void on_actionRegistro_de_asistencias_triggered();

    void on_actionResumen_asistencias_faltas_triggered();

    void on_actionPosibles_abandonantes_triggered();

    void on_actionReuniones_triggered();

private:
    Ui::menu_herramientas *ui;
    QSqlDatabase db;
    QString cargoUsuario; // Almacena el cargo del usuario

    void conexionBdd();
    alta_de_alumnos *menuAlta; // Puntero al menú de alta de alumnos.
    baja_de_alumnos *menuBaja; // Puntero al menú de baja de alumnos.
    modificacion_de_alumnos *menuModificacion; // Puntero al menú de modificación de alumnos.
    listado_de_alumnos *menuListado; // Puntero al menú de listado de alumnos.
    registro_de_asistencias *menuRegAsistencia; // Puntero al menú de registro de asistencia.
    resumen_de_asis_y_faltas *menuResumenAsisYFaltas; // Puntero al menú de resumen de asistencias e inasistencias.
    posibles_abandonantes *menuAbandonantes; // Puntero al menú de posibles abandonantes.
    reuniones *menuReuniones; // Puntero al menú de reuniones.
};

#endif // MENU_HERRAMIENTAS_H
