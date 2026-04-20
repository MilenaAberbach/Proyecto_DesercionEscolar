#include "baja_de_alumnos.h"  // Encabezado de la clase baja_de_alumnos
#include "ui_baja_de_alumnos.h" // Archivo generado automáticamente para gestionar la interfaz de usuario
#include "menu_herramientas.h" // Encabezado de la clase menu_herramientas
#include "inicio_de_sesion.h" // Encabezado de la clase inicio_de_sesion
#include "sesionusuario.h" // Encabezado de la clase sesionusuario

// Librerías utilizadas
#include <QDebug>
#include <QMessageBox>
#include <QComboBox>
#include <QShowEvent>

// Constructor de la clase baja_de_alumnos
baja_de_alumnos::baja_de_alumnos(QWidget *parent) // Llama al constructor base QMainWindow con el padre especificado
    : QMainWindow(parent) // Inicializa el puntero de la interfaz de usuario
    , ui(new Ui::baja_de_alumnos)
{
    ui -> setupUi(this); // Configuración de la interfaz de usuario
    setWindowTitle("Baja de Alumnos - BackToLearn!"); // Establecer el título de la ventana
    conexionBdd();
    datosComboAlumno();

    // Obtenemos el idUsuario, nombre, cargo e idCurso de la cuenta actual (preceptor)
    int idUsuario = SesionUsuario::getInstance().getIdUsuario();
    QString nombre = SesionUsuario::getInstance().getNombreUsuario();
    QString cargo = SesionUsuario::getInstance().getCargoUsuario();
    int idCurso = SesionUsuario::getInstance().getIdCurso();

    ui->label_nombreUsuario->setText(nombre); // Agregamos texto
    ui->label_cargoUsuario->setText(cargo); // " "
    ui->label_idUsuario->setText(QString::number(idUsuario)); // " "
    ui->label_nombreUsuario->setStyleSheet("color: rgb(255, 190, 11);"); // Colorea el texto
    ui->label_cargoUsuario->setStyleSheet("color: rgb(255, 255, 255);"); // Colorea el texto
    ui->label_idUsuario->setStyleSheet("color: rgb(255, 190, 11);"); // Colorea el texto
    ui->label_idCurso->setText(QString::number(idCurso)); // " "
    ui->label_idCurso->setStyleSheet("color: rgb(255, 190, 11);");  // Colorea el texto
}

// Destructor de la clase alta_de_alumnos
baja_de_alumnos::~baja_de_alumnos()
{
    delete ui;
}

// Establecer conexión con la base de datos
void baja_de_alumnos::conexionBdd()
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
void baja_de_alumnos::on_actionCambiar_cuenta_triggered()
{
    qDebug() << "\n\tBotón 'Cambiar cuenta' presionado.";

    inicio_de_sesion *inicioSesion = new inicio_de_sesion();
    inicioSesion->show();

    qDebug() << "\n\tNueva instancia de inicio_de_sesion creada y mostrada.";

    this->close(); // Cierra completamente la ventana actual
}

// Función que se ejecuta si el usuario presiona el desplegable "Volver" (Menú desplegable "Opciones" -> Subopción "Volver")
void baja_de_alumnos::on_actionVolver_triggered()
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
void baja_de_alumnos::on_actionSalir_triggered()
{
    close(); // Cierra la ventana actual
    qDebug() << "\n---- EL USUARIO SALIO DEL PROGRAMA"; // Muestra el mensaje por la consola
}

// Evento que se ejecuta cuando la ventana es mostrada
void baja_de_alumnos::showEvent(QShowEvent *event) {
    QMainWindow::showEvent(event);
    datosComboAlumno(); // Recarga el comboBox cada vez que se muestra la ventana
}

// Cargar datos en el combobox de alumnos
void baja_de_alumnos::datosComboAlumno()
{
    int idCurso = SesionUsuario::getInstance().getIdCurso(); // Obtener el curso del preceptor

    QSqlQuery query;
    query.prepare("SELECT idAlumno, apellidoAlumno, nombreAlumno FROM Alumnos WHERE idCurso = :idCurso");
    query.bindValue(":idCurso", idCurso);
    ui -> comboBoxAlumno -> clear(); // Limpia el contenido del combobox

    // Verificar si la consulta fue exitosa
    if (!query.exec()) {
        qDebug() << "\n\tHubo un error al cargar los alumnos: " << query.lastError().text();
        return;
    }

    // Agregar los nombres de los alumnos al combobox
    while (query.next()) {
        QString idAlumno = query.value(0).toString(); // Obtiene el ID del alumno
        QString nombreCompleto = query.value(1).toString() + ", " + query.value(2).toString(); // Construye el nombre completo
        ui -> comboBoxAlumno -> addItem(idAlumno, nombreCompleto); // Agrega los nombres de los alumnos al combobox
        qDebug() << "\n----Fue agregado el alumno <" << nombreCompleto << "> con ID: " << idAlumno;
    }
}

// Acción que se ejecuta cuando cambia el índice seleccionado en el combobox
void baja_de_alumnos::on_comboBoxAlumno_currentIndexChanged()
{
    QString idAlumno = ui -> comboBoxAlumno -> currentText();

    // Consultar el nombre y apellido del alumno basado en el ID
    QSqlQuery query;
    query.prepare("SELECT nombreAlumno, apellidoAlumno FROM Alumnos WHERE idAlumno = :idAlumno");
    query.bindValue(":idAlumno", idAlumno);

    // Verificar si la consulta fue exitosa y actualizar el label con el nombre completo del alumno
    if (query.exec() && query.next()) {
        QString nombreCompleto = query.value(1).toString() + ", " + query.value(0).toString();
        ui -> label_nombreAlumno -> setText(nombreCompleto);
    } else {
        ui -> label_nombreAlumno -> setText("Nombre desconocido");
    }
}

// Acción que se ejecuta cuando el usuario confirma la baja de un alumno (botón confirmar)
void baja_de_alumnos::on_confirmarBajaAlumno_clicked()
{
    QString idAlumno = ui -> comboBoxAlumno -> currentText();
    QString nombreCompleto = ui -> label_nombreAlumno -> text();

    // Verificar que el ID del alumno y el nombre completo sean válidos
    if (idAlumno.isEmpty() || nombreCompleto == "Nombre desconocido") {
        QMessageBox::warning(this, "Error", "Por favor seleccione un ID válido.");
        return;
    }

    // Confirmar con el usuario
    QMessageBox::StandardButton confirmacion = QMessageBox::question(
        this,
        "Confirmar eliminación de alumno",
        QString("¿Está seguro de que desea eliminar al alumno '%1' con ID '%2'? \n(Yes: Sí)").arg(nombreCompleto).arg(idAlumno),
        QMessageBox::No | QMessageBox::Yes
        );

    if (confirmacion == QMessageBox::Yes) {
        // Eliminar el alumno de la base de datos
        QSqlQuery query;
        query.prepare("DELETE FROM Alumnos WHERE idAlumno = :idAlumno");
        query.bindValue(":idAlumno", idAlumno);

        // Verificar si la eliminación fue exitosa
        if (query.exec()) {
            qDebug() << "\n\tEl alumno de nombre " << nombreCompleto << " con ID " << idAlumno << " fue eliminado con éxito.";
            QMessageBox::information(this, "Exito", "¡El alumno ha sido eliminado correctamente!");
            ui -> comboBoxAlumno -> clear(); // Limpiar el combo box
            ui -> label_nombreAlumno -> clear(); // Limpiar el label
            datosComboAlumno(); // Recargar los alumnos en el combo box
        } else {
            QMessageBox::critical(this, "Error", "No se pudo eliminar al alumno: ");
            qDebug() << "\n\tError: No se pudo eliminar al alumno: " << query.lastError().text();
        }
    }
}
