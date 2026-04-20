#include "pantalla_inicio.h" // Encabezado de la clase pantalla_inicio
#include "ui_pantalla_inicio.h" // Archivo generado automáticamente para gestionar la interfaz de usuario
#include "inicio_de_sesion.h" // Encabezado de la clase inicio_de_sesion

// Constructor de la clase pantalla_inicio
pantalla_inicio::pantalla_inicio(QWidget *parent)
    : QMainWindow(parent) // Llama al constructor base QMainWindow con el padre especificado
    , ui(new Ui::pantalla_inicio) // Inicializa el puntero de la interfaz de usuario
    , inicioSesion(nullptr) // Inicializa el puntero del apartado de inicio de sesión a nullptr
{
    ui->setupUi(this); // Configura la interfaz de usuario definida en el archivo .ui
    setWindowTitle("Inicio - BackToLearn!"); // Establece el título de la ventana
}

// Destructor de la clase pantalla_inicio
pantalla_inicio::~pantalla_inicio()
{
    delete ui; // Libera la memoria de la interfaz de usuario
    if (inicioSesion) { // Comprueba si inicioSesion está asignado
        delete inicioSesion; // Libera la memoria de la ventana de inicio de sesión.
    }
}

// Función que se ejecuta si el botón para continuar es presionado
void pantalla_inicio::on_btnContinuar_clicked()
{
    // Verifica si la ventana inicio_de_sesion no ha sido creada aún
    if (!inicioSesion) {
        inicioSesion = new inicio_de_sesion(this); // Crea una nueva instancia de inicio_de_sesion como hija de esta ventana
    }

    inicioSesion->show(); // Muestra la ventana de inicio_de_sesion
    this->hide(); // Oculta la ventana actual
    qDebug() << "\n---- EL USUARIO SE FUE AL APARTADO DE INICIO DE SESION"; // Imprime un mensaje en la consola para depuración
}

// Función que se ejecuta si el botón para salir es presionado
void pantalla_inicio::on_btnSalir_clicked()
{
    close(); // Cierra la ventana actual
    qDebug() << "\n---- EL USUARIO SALIO DEL PROGRAMA"; // Imprime un mensaje en la consola para depuración
}

