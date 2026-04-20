#include "menu_herramientas.h" // Encabezado de la clase menu_herramientas
#include "ui_menu_herramientas.h" // Archivo generado automáticamente para gestionar la interfaz de usuario
#include "inicio_de_sesion.h" // Encabezado de la clase inicio_de_sesion
#include "alta_de_alumnos.h" // Encabezado de la clase alta_de_alumnos
#include "baja_de_alumnos.h" // Encabezado de la clase baja_de_alumnos
#include "modificacion_de_alumnos.h" // Encabezado de la clase modifacion_de_alumnos
#include "listado_de_alumnos.h" // Encabezado de la clase listado_de_alumnos
#include "registro_de_asistencias.h" // Encabezado de la clase registro_de_asistencias
#include "resumen_de_asis_y_faltas.h" // Encabezado de la clase resumen_de_asis_y_faltas
#include "posibles_abandonantes.h" // Encabezado de la clase posibles_abandonantes
#include "reuniones.h" // Encabezado de la clase reuniones

// Librerías utilizadas
#include <QMessageBox>

// Constructor de la clase menu_herramientas
menu_herramientas::menu_herramientas(QWidget *parent)
    : QMainWindow(parent) // Llama al constructor base QMainWindow con el padre especificado
    , ui(new Ui::menu_herramientas)  // Inicializa el puntero de la interfaz de usuario
    , menuAlta(nullptr) // Inicializa el puntero del apartado de alta de alumnos a nullptr
    , menuBaja(nullptr) // Inicializa el puntero del apartado de baja de alumnos a nullptr
    , menuModificacion(nullptr) // Inicializa el puntero del apartado de modificación de alumnos a nullptr
    , menuListado(nullptr) // Inicializa el puntero del apartado de listado de alumnos a nullptr
    , menuRegAsistencia(nullptr) // Inicializa el puntero del apartado de registro de asistencias a nullptr
    , menuResumenAsisYFaltas(nullptr) // Inicializa el puntero del apartado de resumen de asistencias y faltas a nulltpr
    , menuAbandonantes(nullptr) // Inicializa el puntero del apartado posibles abandonantes a nullptr
    , menuReuniones (nullptr) // Inicializa el puntero del apartado reuniones a nullptr
{
    ui -> setupUi(this); // Configuración de la interfaz de usuario
    setWindowTitle("Menú de herramientas - BackToLearn!"); // Establecer el título de la ventana
    conexionBdd();
}

// Destructor de la clase menuHerramientas
menu_herramientas::~menu_herramientas()
{
    delete ui;
    if (menuAlta) {
        delete menuAlta;
    } else if (menuBaja) {
        delete menuBaja;
    } else if (menuModificacion) {
        delete menuModificacion;
    } else if (menuListado) {
        delete menuListado;
    } else if (menuRegAsistencia) {
        delete menuRegAsistencia;
    } else if (menuResumenAsisYFaltas) {
        delete menuResumenAsisYFaltas;
    } else if (menuAbandonantes) {
        delete menuAbandonantes;
    } else if (menuReuniones) {
        delete menuReuniones;
    }
}

// Establecer conexión con la base de datos
void menu_herramientas::conexionBdd()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost"); // Dirección del servidor
    db.setUserName("root"); // Usuario
    db.setPassword("MileBDD2024!"); // Contraseña
    db.setDatabaseName("ver2_Desercion_Escolar"); // Nombre de la base de datos

    // Verificar si la conexión fue exitosa
    if (!db.open()) {
        qDebug() << "\n---- ERROR AL CONECTARSE A LA BASE DE DATOS: " << db.lastError().text();
        QMessageBox::critical(this, "Error de conexión ", "No se pudo conectar a la base de datos.");
        return;
    } else {
        qDebug() << "\n\n------ CONEXION EXITOSA A LA BASE DE DATOS !!! ------\n\n";
        return;
    }
}

// Función que se ejecuta si el usuario presiona el desplegable "Cambiar cuenta" (Menú desplegable "Opciones" -> Subopción "Cambiar cuenta")
void menu_herramientas::on_actionCambiarCuenta_triggered()
{
    // Obtener el puntero de la pantalla de inicio de sesión desde el parent
    inicio_de_sesion *inicioSesion = qobject_cast<inicio_de_sesion *>(parent());
    if (inicioSesion) {
        inicioSesion -> show(); // Mostrar la pantalla de inicio de sesión
        this -> close(); // Ocultar la ventana secundaria
        qDebug() << "\n---- EL USUARIO VOLVIO A LA PANTALLA DE INICIO DE SESIÓN"; // Muestra el mensaje por la consola
    }
}

// Función que se ejecuta si el usuario presiona el desplegable "Salir" (Menú desplegable "Opciones" -> Subopción "Salir")
void menu_herramientas::on_actionSalir_triggered()
{
    close(); // Cierra la ventana actual
    qDebug() << "\n---- EL USUARIO SALIO DEL PROGRAMA"; // Muestra el mensaje por la consola
}

void menu_herramientas::setDatosUsuario(const QString &nombre, const QString &cargo)
{
    ui->label_nombreUsuario->setText(nombre);
    ui->label_nombreUsuario->setStyleSheet("color: rgb(255, 120, 0);");
    ui->label_cargoUsuario->setText(cargo);
    ui->label_cargoUsuario->setStyleSheet("color: rgb(53, 132, 228);");
    this->cargoUsuario = cargo; // Guardamos el cargo del usuario
}

// Función que se ejecuta si el usuario presiona el desplegable "Alta" (Menú desplegable "ABML" -> Subopción "Alta")
void menu_herramientas::on_actionAlta_triggered()
{
    if (cargoUsuario == "Miembro del DOE") {
        QMessageBox::warning(this, "Acceso denegado", "Los usuarios del DOE no tienen permiso para acceder al módulo de Alta de Alumnos.");
        return;
    }

    // Verifica si la ventana alta_de_alumnos no ha sido creada aún
    if (!menuAlta) {
        menuAlta = new alta_de_alumnos(this);
    }

    menuAlta->show(); // Muestra la ventana de alta_de_alumnos
    this->hide(); // Oculta la ventana actual
    qDebug() << "\n---- EL USUARIO SE FUE AL APARTADO DE ALTA DE ALUMNOS";
}

// Función que se ejecuta si el usuario presiona el desplegable "Baja" (Menú desplegable "ABML" -> Subopción "Baja")
void menu_herramientas::on_actionBaja_triggered()
{
    if (cargoUsuario == "Miembro del DOE") {
        QMessageBox::warning(this, "Acceso denegado", "Los usuarios del DOE no tienen permiso para acceder al módulo de Baja de Alumnos.");
        return;
    }

    // Verifica si la ventana baja_de_alumnos no ha sido creada aún
    if (!menuBaja) {
        menuBaja = new baja_de_alumnos(this);
    }

    menuBaja->show(); // Muestra la ventana de baja_de_alumnos
    this->hide(); // Oculta la ventana actual
    qDebug() << "\n---- EL USUARIO SE FUE AL APARTADO DE BAJA DE ALUMNOS";
}

// Función que se ejecuta si el usuario presiona el desplegable "Modificación" (Menú desplegable "ABML" -> Subopción "Modificación")
void menu_herramientas::on_actionModificacion_triggered()
{
    if (cargoUsuario == "Miembro del DOE") {
        QMessageBox::warning(this, "Acceso denegado", "Los usuarios del DOE no tienen permiso para acceder al módulo de Modificación de Alumnos.");
        return;
    }

    // Verifica si la ventana modificacion_de_alumnos no ha sido creada aún
    if (!menuModificacion) {
        menuModificacion = new modificacion_de_alumnos(this);
    }

    menuModificacion->show(); // Muestra la ventana de modificacion_de_alumnos
    this->hide(); // Oculta la ventana actual
    qDebug() << "\n---- EL USUARIO SE FUE AL APARTADO DE MODIFICACIÓN DE ALUMNOS (DATOS)";
}

// Función que se ejecuta si el usuario presiona el desplegable "Listado" (Menú desplegable "ABML" -> Subopción "Listado")
void menu_herramientas::on_actionListado_triggered()
{
    // Verifica si la ventana listado_de_alumnos no ha sido creada aún
    if (!menuListado) {
        menuListado = new listado_de_alumnos(this);
    }

    menuListado->show(); // Muestra la ventana de listado_de_alumnos
    this->hide(); // Oculta la ventana actual
    qDebug() << "\n---- EL USUARIO SE FUE AL APARTADO DE LISTADO DE ALUMNOS";
}

// Función que se ejecuta si el usuario presiona el desplegable "Registro de asistencias" (Menú desplegable "Asistencias" -> Subopción "Registro de asistencias")
void menu_herramientas::on_actionRegistro_de_asistencias_triggered()
{
    if (cargoUsuario == "Miembro del DOE") {
        QMessageBox::warning(this, "Acceso denegado", "Los usuarios del DOE no tienen permiso para acceder al módulo de Registro de Asistencias.");
        return;
    }

    // Verifica si la ventana registro_de_asistencias no ha sido creada aún
    if (!menuRegAsistencia) {
        menuRegAsistencia = new registro_de_asistencias(this);
    }

    menuRegAsistencia->show(); // Muestra la ventana de registro_de_asistencias
    this->hide(); // Oculta la ventana actual
    qDebug() << "\n---- EL USUARIO SE FUE AL APARTADO DE REGISTRO DE ASISTENCIAS";
}

// Función que se ejecuta si el usuario presiona el desplegable "Resumen de asistencias y faltas" (Menú desplegable "Asistencias" -> Subopción "Resumen de asistencias y faltas")
void menu_herramientas::on_actionResumen_asistencias_faltas_triggered()
{
    // Verifica si la ventana resumen_de_asis_y_faltas no ha sido creada aún
    if (!menuResumenAsisYFaltas) {
        menuResumenAsisYFaltas = new resumen_de_asis_y_faltas(this);
    }

    menuResumenAsisYFaltas->show(); // Muestra la ventana de resumen_de_asis_y_faltas
    this->hide(); // Oculta la ventana actual
    qDebug() << "\n---- EL USUARIO SE FUE AL APARTADO DE RESUMEN DE ASISTENCIAS Y FALTAS";
}

// Función que se ejecuta si el usuario presiona el desplegable "Posibles abandonantes" (Menú desplegable "Asistencias" -> Subopción "Posibles abandonantes")
void menu_herramientas::on_actionPosibles_abandonantes_triggered()
{
    // Verifica si la ventana resumen_de_asis_y_faltas no ha sido creada aún
    if (!menuAbandonantes) {
        menuAbandonantes = new posibles_abandonantes(this);
    }

    menuAbandonantes->show(); // Muestra la ventana de posibles_abandonantes
    this->hide(); // Oculta la ventana actual
    qDebug() << "\n---- EL USUARIO SE FUE AL APARTADO DE POSIBLES ABANDONANTES";
}

// Función que se ejecuta si el usuario presiona el desplegable "Reuniones" (Menú desplegable "Asistencias" -> Subopción "Reuniones")
void menu_herramientas::on_actionReuniones_triggered()
{
    // Verifica si la ventana resumen_de_asis_y_faltas no ha sido creada aún
    if (!menuReuniones) {
        menuReuniones = new reuniones(this);
    }

    menuReuniones->show(); // Muestra la ventana de reuniones
    this->hide(); // Oculta la ventana actual
    qDebug() << "\n---- EL USUARIO SE FUE AL APARTADO DE REUNIONES";
}
