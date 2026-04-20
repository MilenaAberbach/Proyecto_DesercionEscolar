#include "modificacion_de_alumnos.h" // Encabezado de la clase modificacion_de_alumnos
#include "ui_modificacion_de_alumnos.h" // Archivo generado automáticamente para gestionar la interfaz de usuario
#include "menu_herramientas.h" // Encabezado de la clase menu_herramientas
#include "inicio_de_sesion.h" // Encabezado de la clase inicio_de_sesion
#include "sesionusuario.h" // Encabezado de la clase sesionusuario

// Librerías utilizadas
#include <QDebug> // Depuración en consola.
#include <QMessageBox> // Mensajes para alertar o informar al usuario.
#include <QComboBox> // Manejo de menús desplegables.
#include <QCheckBox>
#include <QShowEvent> // Evento que se dispara al mostrar la ventana.
#include <QRegularExpression> // Expresiones regulares.
#include <QRegularExpressionValidator> // Validadores basados en expresiones regulares.

// Constructor de la clase modificacion_de_alumno
modificacion_de_alumnos::modificacion_de_alumnos(QWidget *parent)
    : QMainWindow(parent) // Llama al constructor base QMainWindow con el padre especificado
    , ui(new Ui::modificacion_de_alumnos) // Inicializa el puntero de la interfaz de usuario
{
    ui -> setupUi(this); // Configura la interfaz gráfica
    setWindowTitle("Modificacion de Alumnos - BackToLearn!"); // Título de la ventana
    conexionBdd(); // Establece la conexión a la base de datos
    datosComboAlumno(); // Carga los datos de alumnos en el combobox

    // Conecta los checkboxes a métodos que habilitan/deshabilitan campos de entrada
    connect(ui -> checkBoxNombre, &QCheckBox::stateChanged, this, &modificacion_de_alumnos::on_checkBoxNombre);
    connect(ui -> checkBoxApellido, &QCheckBox::stateChanged, this, &modificacion_de_alumnos::on_checkBoxApellido);
    connect(ui -> checkBoxEdad, &QCheckBox::stateChanged, this, &modificacion_de_alumnos::on_checkBoxEdad);

    // Inicializa los campos de entrada como deshabilitados (solo visualización)
    ui -> lEdit_nombreAlu -> setEnabled(false);
    ui -> lEdit_apellidoAlu -> setEnabled(false);
    ui -> sBox_EdadAlumno -> setEnabled(false);

    // Expresión regular para validar nombres y apellidos
    QRegularExpression regex("^[a-zA-ZáéíóúÁÉÍÓÚñÑ ]+$");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regex, this);
    // Aplica el validador a los campos de nombre y apellido
    ui -> lEdit_nombreAlu -> setValidator(validator);
    ui -> lEdit_apellidoAlu -> setValidator(validator);

    // Obtenemos el idUsuario, nombre, cargo e idCurso de la cuenta actual (preceptor)
    int idUsuario = SesionUsuario::getInstance().getIdUsuario();
    QString nombre = SesionUsuario::getInstance().getNombreUsuario();
    QString cargo = SesionUsuario::getInstance().getCargoUsuario();
    int idCurso = SesionUsuario::getInstance().getIdCurso();

    ui->label_nombreUsuario->setText(nombre); // Agregamos texto
    ui->label_cargoUsuario->setText(cargo); // " "
    ui->label_idUsuario->setText(QString::number(idUsuario)); // " "
    ui->label_cargoUsuario->setStyleSheet("color: rgb(38, 162, 105);"); // Colorea el texto
    ui->label_idUsuario->setStyleSheet("color: rgb(38, 162, 105);"); // Colorea el texto
    ui->label_idCurso->setText(QString::number(idCurso)); // " "
    ui->label_idCurso->setStyleSheet("color: rgb(38, 162, 105);");  // Colorea el texto
}

// Destructor de la clase alta_de_alumnos
modificacion_de_alumnos::~modificacion_de_alumnos()
{
    delete ui;
}

// Establecer conexión con la base de datos
void modificacion_de_alumnos::conexionBdd()
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
void modificacion_de_alumnos::on_actionCambiar_cuenta_triggered()
{
    qDebug() << "\n\tBotón 'Cambiar cuenta' presionado.";

    inicio_de_sesion *inicioSesion = new inicio_de_sesion();
    inicioSesion->show();

    qDebug() << "\n\tNueva instancia de inicio_de_sesion creada y mostrada.";

    this->close(); // Cierra completamente la ventana actual
}

// Función que se ejecuta si el usuario presiona el desplegable "Volver" (Menú desplegable "Opciones" -> Subopción "Volver")
void modificacion_de_alumnos::on_actionVolver_triggered()
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
void modificacion_de_alumnos::on_actionSalir_triggered()
{
    close(); // Cierra la ventana actual
    qDebug() << "\n---- EL USUARIO SALIO DEL PROGRAMA"; // Muestra el mensaje por la consola
}

// Evento para recargar datos cada vez que se muestra la ventana
void modificacion_de_alumnos::showEvent(QShowEvent *event) {
    QMainWindow::showEvent(event);
    datosComboAlumno();  // Recarga los datos de alumnos en el combobox
}

// Carga los alumnos en el combobox desde la base de datos
void modificacion_de_alumnos::datosComboAlumno()
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
void modificacion_de_alumnos::on_comboBoxAlumno_currentIndexChanged()
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

// Habilita o deshabilita el campo de nombre según el estado del checkbox
void modificacion_de_alumnos::on_checkBoxNombre(int estado)
{
    ui -> lEdit_nombreAlu -> setEnabled(estado == Qt::Checked);
}

// Habilita o deshabilita el campo de nombre según el estado del checkbox
void modificacion_de_alumnos::on_checkBoxApellido(int estado)
{
    ui -> lEdit_apellidoAlu -> setEnabled(estado == Qt::Checked);
}

// Habilita o deshabilita el campo de nombre según el estado del checkbox
void modificacion_de_alumnos::on_checkBoxEdad(int estado)
{
    ui -> sBox_EdadAlumno -> setEnabled(estado == Qt::Checked);
}

// Aplica los cambios al alumno seleccionado
void modificacion_de_alumnos::on_confirmarModificacionAlumno_clicked()
{
    QString idAlumno = ui -> comboBoxAlumno -> currentText(); // ID del alumno seleccionado
    QSqlQuery query;
    QString consulta = "UPDATE Alumnos SET "; // Consulta base para la actualización
    QStringList camposActualizados;

    // Verifica qué campos están habilitados para actualizar y los añade a la consulta
    if (ui->checkBoxNombre->isChecked() && ui->checkBoxApellido->isChecked()) {
        QString nuevoNombre = ui -> lEdit_nombreAlu -> text().trimmed();
        QString nuevoApellido = ui -> lEdit_apellidoAlu -> text().trimmed();
        if (nuevoNombre.isEmpty() && nuevoApellido.isEmpty()) {
            QMessageBox::warning(this, "Advertencia", "Los campos 'Nombre' y 'Apellido' no pueden estar vacíos.");
            return;
        }
        camposActualizados.append(QString("nombreAlumno = '%1'").arg(nuevoNombre));
        camposActualizados.append(QString("apellidoAlumno = '%1'").arg(nuevoApellido));
    }
    if (ui -> checkBoxNombre -> isChecked()) {
        QString nuevoNombre = ui -> lEdit_nombreAlu -> text().trimmed();
        if (nuevoNombre.isEmpty()) {
            QMessageBox::warning(this, "Advertencia", "El campo 'Nombre' no puede estar vacío.");
            return;
        }
        camposActualizados.append(QString("nombreAlumno = '%1'").arg(nuevoNombre));
    }
    if (ui -> checkBoxApellido -> isChecked()) {
        QString nuevoApellido = ui -> lEdit_apellidoAlu -> text().trimmed();
        if (nuevoApellido.isEmpty()) {
            QMessageBox::warning(this, "Advertencia", "El campo 'Apellido' no puede estar vacío.");
            return;
        }
        camposActualizados.append(QString("apellidoAlumno = '%1'").arg(nuevoApellido));
    }

    if (ui -> checkBoxEdad -> isChecked()) {
        int nuevaEdad = ui -> sBox_EdadAlumno -> value();
        camposActualizados.append(QString("edadAlumno = %1").arg(nuevaEdad));
    }

    // Si no hay campos seleccionados, muestra una advertencia
    if (camposActualizados.isEmpty()) {
        qDebug() << "\n\tNo se seleccionaron campos para modificar.";
        QMessageBox::warning(this, "Advertencia", "Debe seleccionar al menos un campo para modificar.");
        return;
    }

    // Construye la consulta final con los campos seleccionados
    consulta += camposActualizados.join(", ");
    consulta += QString(" WHERE idAlumno = %1").arg(idAlumno);

    // Ejecuta la consulta y verifica el resultado
    if (!query.exec(consulta)) {
        qDebug() << "\n\tError al modificar el alumno: " << query.lastError().text();
        QMessageBox::critical(this, "Error", "No se pudo modificar el alumno. Revise los datos e intente nuevamente.");
    } else {
        qDebug() << "\n\tEl alumno fue modificado correctamente.";
        QMessageBox::information(this, "Éxito", "¡Los datos del alumno fueron modificados correctamente!");

        // Limpia y resetea todos los campos de la interfaz
        ui -> comboBoxAlumno -> clear();
        ui -> label_nombreAlumno -> clear();
        ui -> lEdit_nombreAlu -> clear();
        ui -> lEdit_apellidoAlu -> clear();
        ui -> sBox_EdadAlumno -> setValue(11);

        // Desmarca los checkboxes
        ui -> checkBoxNombre -> setChecked(false);
        ui -> checkBoxApellido -> setChecked(false);
        ui -> checkBoxEdad -> setChecked(false);

        // Recarga los datos
        datosComboAlumno();
    }
}
