#ifndef SESIONUSUARIO_H
#define SESIONUSUARIO_H

#include <QString>

class SesionUsuario {
public:
    static SesionUsuario& getInstance() {
        static SesionUsuario instance;
        return instance;
    }

    void setUsuario(int id, const QString &nombre, const QString &cargo, int curso) {
        idUsuario = id;
        nombreUsuario = nombre;
        cargoUsuario = cargo;
        idCurso = curso;
    }

    int getIdUsuario() const { return idUsuario; }
    QString getNombreUsuario() const { return nombreUsuario; }
    QString getCargoUsuario() const { return cargoUsuario; }
    int getIdCurso() const { return idCurso; }

private:
    int idUsuario;
    QString nombreUsuario;
    QString cargoUsuario;
    int idCurso;  // Nuevo atributo para almacenar el curso asignado

    // Constructor privado para que no pueda ser instanciada fuera
    SesionUsuario() : idUsuario(-1), nombreUsuario(""), cargoUsuario(""), idCurso(-1) {}

    // Evitar copia de la clase
    SesionUsuario(const SesionUsuario&) = delete;
    void operator=(const SesionUsuario&) = delete;
};


#endif // SESIONUSUARIO_H
