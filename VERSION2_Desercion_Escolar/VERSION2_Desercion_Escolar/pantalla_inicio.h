#ifndef PANTALLA_INICIO_H
#define PANTALLA_INICIO_H

#include <QMainWindow>
#include <QDebug>
#include "inicio_de_sesion.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class pantalla_inicio;
}
QT_END_NAMESPACE

class pantalla_inicio : public QMainWindow
{
    Q_OBJECT

public:
    pantalla_inicio(QWidget *parent = nullptr);
    ~pantalla_inicio();

private slots:
    void on_btnContinuar_clicked();

    void on_btnSalir_clicked();

private:
    Ui::pantalla_inicio *ui;
    inicio_de_sesion *inicioSesion;
};
#endif // PANTALLA_INICIO_H
