#include "alta_de_alumnos.h" // Encabezado de la clase alta_de_alumnos
#include "ui_alta_de_alumnos.h" // Archivo generado automáticamente para gestionar la interfaz de usuario
#include "menu_herramientas.h" // Encabezado de la clase menu_herramientas
#include "inicio_de_sesion.h" // Encabezado de la clase inicio_de_sesion
#include "sesionusuario.h" // Encabezado de la clase sesionusuario

// Librerías utilizadas
#include <QDebug>
#include <QMessageBox>
#include <QComboBox>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

// Constructor de la clase alta_de_alumnos
alta_de_alumnos::alta_de_alumnos(QWidget *parent)
    : QMainWindow(parent)  // Llama al constructor base QMainWindow con el padre especificado
    , ui(new Ui::alta_de_alumnos) // Inicializa el puntero de la interfaz de usuario
{
    ui->setupUi(this);
    setWindowTitle("Alta de Alumnos - BackToLearn!"); // Establecer el título de la ventana
    conexionBdd(); // Establecer conexión con la base de datos

    // Expresión regular para validar nombres y apellidos
    QRegularExpression regex("^[a-zA-ZáéíóúÁÉÍÓÚñÑ ]+$");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regex, this);
    // Aplica el validador a los campos de nombre y apellido
    ui -> lEdit_NombreAlu -> setValidator(validator);
    ui -> lEdit_ApellidoAlu -> setValidator(validator);

    // Obtenemos el idUsuario, nombre, cargo e idCurso de la cuenta actual (preceptor)
    int idUsuario = SesionUsuario::getInstance().getIdUsuario();
    QString nombre = SesionUsuario::getInstance().getNombreUsuario();
    QString cargo = SesionUsuario::getInstance().getCargoUsuario();
    int idCurso = SesionUsuario::getInstance().getIdCurso();

    ui->label_nombreUsuario->setText(nombre); // Agregamos texto
    ui->label_cargoUsuario->setText(cargo); // " "
    ui->label_idUsuario->setText(QString::number(idUsuario)); // " "
    ui->label_cargoUsuario->setStyleSheet("color: rgb(255, 255, 255);"); // Colorea el texto
    ui->label_idUsuario->setStyleSheet("color: rgb(153, 193, 241);"); // Colorea el texto
    ui->label_idCurso->setText(QString::number(idCurso)); // " "
    ui->label_idCurso->setStyleSheet("color: rgb(153, 193, 241);");  // Colorea el texto
}

// Destructor de la clase alta_de_alumnos
alta_de_alumnos::~alta_de_alumnos()
{
    delete ui;
}

// Establecer conexión con la base de datos
void alta_de_alumnos::conexionBdd()
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
void alta_de_alumnos::on_actionCambiar_cuenta_triggered()
{
    qDebug() << "\n\tBotón 'Cambiar cuenta' presionado.";

    inicio_de_sesion *inicioSesion = new inicio_de_sesion();
    inicioSesion->show();

    qDebug() << "\n\tNueva instancia de inicio_de_sesion creada y mostrada.";

    this->close(); // Cierra completamente la ventana actual
}

// Función que se ejecuta si el usuario presiona el desplegable "Volver" (Menú desplegable "Opciones" -> Subopción "Volver")
void alta_de_alumnos::on_actionVolver_triggered()
{
    // Obtener el puntero de la pantalla de menú de herramientas desde el parent
    menu_herramientas *menuHerramientas = qobject_cast<menu_herramientas *>(parent());
    if (menuHerramientas) {
        menuHerramientas -> show(); // Mostrar la pantalla de menú de herramientas
        this -> hide(); // Ocultar la ventana secundaria
        qDebug() << "\n---- EL USUARIO VOLVIO AL MENÚ DE HERRAMIENTAS"; // Muestra el mensaje por la consola
    }
}

// Función que se ejecuta si el usuario presiona el desplegable "Salir" (Menú desplegable "Opciones" -> Subopción "Salir")
void alta_de_alumnos::on_actionSalir_triggered()
{
    close(); // Cierra la ventana actual
    qDebug() << "\n---- EL USUARIO SALIO DEL PROGRAMA"; // Muestra el mensaje por la consola
}

// Acción que se ejecuta cuando el usuario confirma el alta de un alumno (botón confirmar)
void alta_de_alumnos::on_confirmarAltaAlumno_clicked()
{
    int idCurso = SesionUsuario::getInstance().getIdCurso();

    // Obtener los datos del formulario
    QString nombreAlumno = ui -> lEdit_NombreAlu -> text().trimmed();
    QString apellidoAlumno = ui -> lEdit_ApellidoAlu -> text().trimmed();
    int edadAlumno = ui -> sBox_EdadAlumno -> value();

    // Validar los datos del formulario
    if (nombreAlumno.isEmpty() && apellidoAlumno.isEmpty()) {
        qDebug() << "\n\tError: El nombre y el apellido del alumno no pueden estar vacíos.";
        QMessageBox::warning(this, "Error", "El nombre y el apellido del alumno no pueden estar vacíos.");
        return;
    } else if (nombreAlumno.isEmpty()) {
        qDebug() << "\n\tError: El nombre del alumno no puede estar vacío.";
        QMessageBox::warning(this, "Error", "El nombre del alumno no puede estar vacío.");
        ui -> lEdit_ApellidoAlu -> clear();
        return;
    } else if (apellidoAlumno.isEmpty()) {
        qDebug() << "\n\tError: El apellido del alumno no puede estar vacío.";
        QMessageBox::warning(this, "Error", "El apellido del alumno no puede estar vacío.");
        ui -> lEdit_NombreAlu -> clear();
        return;
    }

    // Preparar la consulta para insertar los datos del alumno en la base de datos
    QSqlQuery query;
    query.prepare("INSERT INTO Alumnos (nombreAlumno, apellidoAlumno, edadAlumno, idCurso) VALUES (:nombreAlumno, :apellidoAlumno, :edadAlumno, :idCurso)");
    query.bindValue(":nombreAlumno", nombreAlumno);
    query.bindValue(":apellidoAlumno", apellidoAlumno);
    query.bindValue(":edadAlumno", edadAlumno);
    query.bindValue(":idCurso", idCurso);

    // Verificar si la inserción fue exitosa
    if (!query.exec()) {
        qDebug() << "\n\tError al insertar el alumno: " << query.lastError().text();
        return;
    }

    // Obtener el ID auto-generado por la base de datos
    if (query.exec("SELECT LAST_INSERT_ID()") && query.next()) {
        int nuevoId = query.value(0).toInt();
        qDebug() << "\n\tNUEVO ALUMNO REGISTRADO CON ID: " << nuevoId;
        QMessageBox::information(this, "Éxito", "¡El alumno ha sido registrado correctamente!");
        ui -> lEdit_NombreAlu -> clear(); // Limpiar los campos del formulario
        ui -> lEdit_ApellidoAlu -> clear();
        ui -> sBox_EdadAlumno -> setValue(13);
    } else {
        qDebug() << "\n\tError al obtener el último ID generado.";
        QMessageBox::critical(this, "Ups...", "No se pudo registrar al alumno.\nError: " + query.lastError().text());
    }
}
