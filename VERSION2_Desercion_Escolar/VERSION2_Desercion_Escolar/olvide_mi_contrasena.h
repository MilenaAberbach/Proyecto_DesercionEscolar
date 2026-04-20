#ifndef OLVIDE_MI_CONTRASENA_H
#define OLVIDE_MI_CONTRASENA_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class olvide_mi_contrasena;
}

class olvide_mi_contrasena : public QMainWindow
{
    Q_OBJECT

public:
    explicit olvide_mi_contrasena(QWidget *parent = nullptr);
    ~olvide_mi_contrasena();

private slots:
    void on_actionVolver_triggered();

    void on_actionSalir_triggered();

    void on_btnRecuperar_clicked();

private:
    Ui::olvide_mi_contrasena *ui;
    QSqlDatabase db;
    void conexionBdd();
};
#endif // OLVIDE_MI_CONTRASENA_H
