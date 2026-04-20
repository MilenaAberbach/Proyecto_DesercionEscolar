#include "resumen_de_asis_y_faltas.h" // Encabezado de la clase resumen_de_asis_y_faltas
#include "ui_resumen_de_asis_y_faltas.h" // Archivo generado automáticamente para gestionar la interfaz de usuario
#include "menu_herramientas.h" // Encabezado de la clase menu_herramientas
#include "inicio_de_sesion.h" // Encabezado de la clase inicio_de_sesion
#include "sesionusuario.h" // Encabezado de la clase sesionusuario

// Librerías utilizadas
#include <QMessageBox>
#include <QComboBox>
#include <QShowEvent>
#include <QDate>

// Constructor de la clase resumen_de_asis_y_faltas
resumen_de_asis_y_faltas::resumen_de_asis_y_faltas(QWidget *parent)
    : QMainWindow(parent) // Llama al constructor base QMainWindow con el padre especificado
    , ui(new Ui::resumen_de_asis_y_faltas) // Inicializa el puntero de la interfaz de usuario
{
    ui->setupUi(this); // Configuración de la interfaz de usuario
    setWindowTitle("Resumen de asistencias e inasistencias (Alumnos) - BackToLearn!"); // Establecer el título de la ventana
    conexionBdd();
    cargarAlumnosConFaltas(); // Carga solo alumnos con faltas
    cargarMotivosDeFalta(); // Carga los motivos de falta
    cargarAlumnosParaResumen(); // Carga todos los alumnos para ver sus resumenes de asistencias y faltas

    // Conexiones: vincula las señales de los widgets con los slots correspondientes
    connect(ui->comboBoxAlumno, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &resumen_de_asis_y_faltas::on_comboBoxAlumno_currentIndexChanged);
    connect(ui->comboBox_motivoRes_Alu, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &resumen_de_asis_y_faltas::on_comboBox_motivoRes_Alu_currentIndexChanged);
    connect(ui->comboBox_motivoRes_Fecha, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &resumen_de_asis_y_faltas::on_comboBox_motivoRes_Fecha_currentIndexChanged);
    connect(ui->comboBoxMesFaltas, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &resumen_de_asis_y_faltas::mostrarFaltasPorMes);
    connect(ui->comboBox_motivoRes_Mes, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &resumen_de_asis_y_faltas::mostrarFaltasPorMes);
    connect(ui->comboBoxResumen, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &resumen_de_asis_y_faltas::mostrarResumenAlumno);
    connect(ui->comboBoxRangoTiempo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &resumen_de_asis_y_faltas::mostrarResumenAlumno);
    connect(ui->comboBoxMes, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &resumen_de_asis_y_faltas::mostrarResumenAlumno);
    connect(ui->btnGuardar, &QPushButton::clicked, this, &resumen_de_asis_y_faltas::mostrarResumenAlumno);
    connect(ui->btnGuardar, &QPushButton::clicked, this, &resumen_de_asis_y_faltas::mostrarFaltasPorMes);
}

// Destructor de la clase resumen_de_asis_y_faltas
resumen_de_asis_y_faltas::~resumen_de_asis_y_faltas()
{
    delete ui;
}

// Establecer conexión con la base de datos
void resumen_de_asis_y_faltas::conexionBdd()
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
void resumen_de_asis_y_faltas::on_actionCambiar_cuenta_triggered()
{
    qDebug() << "\n\tBotón 'Cambiar cuenta' presionado.";

    inicio_de_sesion *inicioSesion = new inicio_de_sesion();
    inicioSesion->show();

    qDebug() << "\n\tNueva instancia de inicio_de_sesion creada y mostrada.";

    this->close(); // Cierra completamente la ventana actual
}

// Función que se ejecuta si el usuario presiona el desplegable "Volver" (Menú desplegable "Opciones" -> Subopción "Volver")
void resumen_de_asis_y_faltas::on_actionVolver_triggered()
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
void resumen_de_asis_y_faltas::on_actionSalir_triggered()
{
    close(); // Cierra la ventana actual
    qDebug() << "\n---- EL USUARIO SALIO DEL PROGRAMA"; // Muestra el mensaje por la consola
}

void resumen_de_asis_y_faltas::showEvent(QShowEvent *event) {
    QMainWindow::showEvent(event);
    // Limpiar los ComboBox
    ui->comboBoxAlumno->clear();
    ui->label_IdAlumno->clear();
    ui->comboBoxFecha->clear();
    ui->comboBoxMotivoFalta->clear();
    ui->Rpta_CantAsist->clear();
    ui->Rpta_CantInasist_SJ->clear();
    ui->Rpta_CantInasistJ->clear();
    ui->comboBoxResumen->clear();
    ui->comboBoxRangoTiempo->setCurrentIndex(0); // Selecciona "Anual" como valor predeterminado
    ui->comboBoxMes->hide();
    ui->label_4->hide();
    ui->labelMeses->hide();
    ui->comboBoxMes->setCurrentIndex(0); // Selecciona "03" como valor predeterminado
    ui->comboBox_motivoRes_Alu->clear();
    ui->comboBox_motivoRes_Fecha->clear();

    // Recargar datos en los combobox
    cargarAlumnosConFaltas(); // Cargar solo alumnos con faltas
    mostrarFaltasPorMes(); // Cargar las faltas del mes seleccionado
    cargarMotivosDeFalta();   // Cargar los motivos de falta
    cargarAlumnosParaResumen(); // Cargar TODOS los alumnos
    mostrarResumenAlumno(); // Actualizar el resumen automáticamente
}

void resumen_de_asis_y_faltas::cargarAlumnosConFaltas() {
    ui->comboBoxAlumno->clear(); // Limpia el combobox de alumno
    ui->comboBox_motivoRes_Alu->clear(); // Limpia el combobox de alumno del que se quiere ver motivos de faltas

    QSqlQuery query;
    int idCurso = SesionUsuario::getInstance().getIdCurso();
    QString cargoUsuario = SesionUsuario::getInstance().getCargoUsuario(); // Obtener tipo de usuario

    if (cargoUsuario == "Preceptor") {
        // Solo alumnos del curso asignado al preceptor
        query.prepare("SELECT DISTINCT a.idAlumno, CONCAT(a.apellidoAlumno, ', ', a.nombreAlumno) "
                      "FROM Alumnos AS a "
                      "INNER JOIN FaltasAlumno AS f ON a.idAlumno = f.idAlumno "
                      "WHERE a.idCurso = :idCurso");
        query.bindValue(":idCurso", idCurso);
    } else {
        // Miembros del DOE pueden ver todos los alumnos
        query.prepare("SELECT DISTINCT a.idAlumno, CONCAT(a.apellidoAlumno, ', ', a.nombreAlumno) "
                      "FROM Alumnos AS a "
                      "INNER JOIN FaltasAlumno AS f ON a.idAlumno = f.idAlumno");
    }

    if (!query.exec()) {
        QMessageBox::warning(this, "Error", "No se pudieron cargar los alumnos con faltas: " + query.lastError().text());
        return;
    }

    while (query.next()) {
        QString idAlumno = query.value(0).toString();
        QString nombreCompleto = query.value(1).toString();
        ui->comboBoxAlumno->addItem(nombreCompleto, idAlumno);
        ui->comboBox_motivoRes_Alu->addItem(nombreCompleto, idAlumno);
    }

    if (ui->comboBoxAlumno->count() == 0) {
        ui->comboBoxAlumno->addItem("No hay alumnos con faltas registradas");
        ui->comboBox_motivoRes_Alu->addItem("No hay alumnos con faltas registradas");
        ui->comboBoxAlumno->setEnabled(false);
        ui->comboBox_motivoRes_Alu->setEnabled(false);
    } else {
        ui->comboBoxAlumno->setEnabled(true);
        ui->comboBox_motivoRes_Alu->setEnabled(true);
    }
}

void resumen_de_asis_y_faltas::cargarMotivosDeFalta() {
    QSqlQuery query("SELECT idMotFalta, descripMotFalta FROM motivoFalta");

    ui->comboBoxMotivoFalta->clear();  // Limpia el combobox antes de cargar nuevos datos

    while (query.next()) {
        QString idMotFalta = query.value(0).toString();
        QString descripcion = query.value(1).toString();

        qDebug() << "\n\tCargando motivo de falta: " << descripcion << "ID: " << idMotFalta;

        ui->comboBoxMotivoFalta->addItem(descripcion, idMotFalta);
    }
}

void resumen_de_asis_y_faltas::on_btnGuardar_clicked() {
    QString idAlumno = ui->comboBoxAlumno->currentData().toString();
    QString fecha = ui->comboBoxFecha->currentText();
    QString idMotivo = ui->comboBoxMotivoFalta->currentData().toString();

    int idCursoUsuario = SesionUsuario::getInstance().getIdCurso();
    QString cargoUsuario = SesionUsuario::getInstance().getCargoUsuario();

    // Verificar si el usuario es preceptor y si el alumno pertenece a su curso
    if (cargoUsuario == "Preceptor") {
        QSqlQuery queryCurso;
        queryCurso.prepare("SELECT idCurso FROM Alumnos WHERE idAlumno = :idAlumno");
        queryCurso.bindValue(":idAlumno", idAlumno);
        if (queryCurso.exec() && queryCurso.next()) {
            int idCursoAlumno = queryCurso.value(0).toInt();
            if (idCursoAlumno != idCursoUsuario) {
                QMessageBox::warning(this, "Acceso denegado", "No puede modificar faltas de alumnos fuera de su curso.");
                return;
            }
        } else {
            QMessageBox::warning(this, "Error", "No se pudo verificar el curso del alumno.");
            return;
        }
    }

    // Consulta para actualizar el motivo de la falta
    QSqlQuery query;
    query.prepare("UPDATE FaltasAlumno SET idMotFalta = :idMotivo WHERE idAlumno = :idAlumno AND fechaFaltaAlu = :fecha");
    query.bindValue(":idMotivo", idMotivo);
    query.bindValue(":idAlumno", idAlumno);
    query.bindValue(":fecha", fecha);

    if (query.exec()) {
        QMessageBox::information(this, "Éxito", "¡Motivo de falta actualizado correctamente!");
    } else {
        QMessageBox::warning(this, "Error", "No se pudo actualizar el motivo de la falta: " + query.lastError().text());
    }
}

void resumen_de_asis_y_faltas::mostrarResumenAlumno() {
    QString idAlumno = ui->comboBoxResumen->currentData().toString();
    QString rangoSeleccionado = ui->comboBoxRangoTiempo->currentText();
    QString filtroTiempo1;
    QString filtroTiempo2;
    QString mesSeleccionado = ui->comboBoxMes->currentText(); // Obtener el mes actual del comboBox

    // Definir el filtro según el rango de tiempo seleccionado
    if (rangoSeleccionado == "Anual") {
        ui->comboBoxMes->hide();
        ui->labelMeses->hide();
        filtroTiempo1 = "YEAR(fechaFaltaAlu) = :anio";
        filtroTiempo2 = "YEAR(fechaAsistencia) = :anio";
    } else if (rangoSeleccionado == "Mensual") {
        ui->comboBoxMes->show();
        ui->labelMeses->show();
        ui->label_5->show();
        filtroTiempo1 = "YEAR(fechaFaltaAlu) = :anio AND MONTH(fechaFaltaAlu) = :mes";
        filtroTiempo2 = "YEAR(fechaAsistencia) = :anio AND MONTH(fechaAsistencia) = :mes";
    } else {
        QMessageBox::warning(this, "Error", "Rango de tiempo no reconocido.");
        return;
    }

    // Consulta SQL con parámetros
    QSqlQuery query;
    query.prepare(
        "SELECT "
        "(SELECT COUNT(*) FROM AsistenciasAlumno WHERE idAlumno = :idAlumno AND " + filtroTiempo2 + ") AS asistencias, "
                          "(SELECT COUNT(*) FROM FaltasAlumno WHERE idAlumno = :idAlumno AND idMotFalta IN (6, 7) AND " + filtroTiempo1 + ") AS inasistencias, "
                          "(SELECT COUNT(*) FROM FaltasAlumno WHERE idAlumno = :idAlumno AND idMotFalta IN (1, 2, 3, 4, 5) AND " + filtroTiempo1 + ") AS inasistencias_justificadas"
        );

    // Vincular los valores de los parámetros
    if (rangoSeleccionado == "Anual") {
        query.bindValue(":idAlumno", idAlumno);
        query.bindValue(":anio", 2024);
    } else if (rangoSeleccionado == "Mensual") {
        query.bindValue(":idAlumno", idAlumno);
        query.bindValue(":anio", 2024);
        query.bindValue(":mes", mesSeleccionado);
    }

    // Ejecutar la consulta y manejar los resultados
    if (query.exec() && query.next()) {
        ui->Rpta_CantAsist->setText(query.value("asistencias").toString());
        ui->Rpta_CantInasist_SJ->setText(query.value("inasistencias").toString());
        ui->Rpta_CantInasistJ->setText(query.value("inasistencias_justificadas").toString());
    } else {
        QMessageBox::warning(this, "Error", "No se pudo obtener el resumen: " + query.lastError().text());
    }
}

void resumen_de_asis_y_faltas::cargarAlumnosParaResumen() {
    ui->comboBoxResumen->clear(); // Limpiar combobox

    QSqlQuery query;
    int idCurso = SesionUsuario::getInstance().getIdCurso();
    QString cargoUsuario = SesionUsuario::getInstance().getCargoUsuario();

    if (cargoUsuario == "Preceptor") {
        query.prepare("SELECT idAlumno, CONCAT(apellidoAlumno, ', ', nombreAlumno) "
                      "FROM Alumnos WHERE idCurso = :idCurso");
        query.bindValue(":idCurso", idCurso);
    } else {
        query.prepare("SELECT idAlumno, CONCAT(apellidoAlumno, ', ', nombreAlumno) FROM Alumnos");
    }

    if (!query.exec()) {
        QMessageBox::warning(this, "Error", "No se pudieron cargar los alumnos para el resumen: " + query.lastError().text());
        return;
    }

    while (query.next()) {
        QString idAlumno = query.value(0).toString();
        QString nombreCompleto = query.value(1).toString();
        ui->comboBoxResumen->addItem(nombreCompleto, idAlumno);
    }
}

void resumen_de_asis_y_faltas::on_comboBoxAlumno_currentIndexChanged(int index)
{
    // Obtiene el idAlumno del elemento seleccionado en el primer QComboBox
    QString idAlumno = ui->comboBoxAlumno->itemData(index).toString();

    // Limpia el segundo comboBox antes de llenarlo
    ui->comboBoxFecha->clear();

    QSqlQuery query;
    query.prepare("SELECT fechaFaltaAlu FROM FaltasAlumno WHERE idAlumno = :idAlumno");
    query.bindValue(":idAlumno", idAlumno);

    if (!query.exec()) {
        QMessageBox::warning(this, "Error", "No se pudieron cargar las fechas de faltas: " + query.lastError().text());
        return;
    }

    while (query.next()) {
        QString fechaFalta = query.value(0).toDate().toString("yyyy-MM-dd");
        ui->comboBoxFecha->addItem(fechaFalta);
    }

    // Consultar el nombre y apellido del alumno basado en el ID
    QSqlQuery query2;
    query2.prepare("SELECT idAlumno FROM Alumnos WHERE idAlumno = :idAlumno");
    query2.bindValue(":idAlumno", idAlumno);

    if (query2.exec() && query2.next()) {
        ui -> label_IdAlumno -> setText(idAlumno);
    } else {
        ui -> label_IdAlumno -> setText("ID desconocido");
    }
}

void resumen_de_asis_y_faltas::mostrarFaltasPorMes() {
    QString idAlumno = ui->comboBoxAlumno->currentData().toString();
    QString idAlumno2 = ui->comboBox_motivoRes_Alu->currentData().toString();

    if (idAlumno.isEmpty() || ui->comboBoxAlumno->currentText() == "No hay alumnos con faltas registradas") {
        QMessageBox::information(this, "Advertencia", "Selecciona un alumno válido primero.");
        return;
    } else if (idAlumno2.isEmpty() || ui->comboBox_motivoRes_Alu->currentText() == "No hay alumnos con faltas registradas") {
        QMessageBox::information(this, "Advertencia", "Selecciona un alumno válido primero.");
        return;
    }

    // Resto de la lógica para mostrar faltas por mes
    ui->comboBoxFecha->clear();
    ui->comboBox_motivoRes_Fecha->clear();
    QString mesSeleccionado1 = ui->comboBoxMesFaltas->currentText();
    QString mesSeleccionado2 = ui->comboBox_motivoRes_Mes->currentText();

    QSqlQuery query1;
    query1.prepare(
        "SELECT fechaFaltaAlu "
        "FROM FaltasAlumno "
        "WHERE idAlumno = :idAlumno AND YEAR(fechaFaltaAlu) = 2024 AND MONTH(fechaFaltaAlu) = :mes"
        );
    query1.bindValue(":idAlumno", idAlumno);
    query1.bindValue(":mes", mesSeleccionado1);

    QSqlQuery query2;
    query2.prepare(
        "SELECT fechaFaltaAlu "
        "FROM FaltasAlumno "
        "WHERE idAlumno = :idAlumno AND YEAR(fechaFaltaAlu) = 2024 AND MONTH(fechaFaltaAlu) = :mes"
        );
    query2.bindValue(":idAlumno", idAlumno2);
    query2.bindValue(":mes", mesSeleccionado2);

    // primer combo de fecha con faltas
    if (!query1.exec()) {
        QMessageBox::warning(this, "Error", "No se pudieron cargar las fechas de faltas: " + query1.lastError().text());
        return;
    }
    while (query1.next()) {
        QString fecha = query1.value(0).toDate().toString("yyyy-MM-dd");
        ui->comboBoxFecha->addItem(fecha);
    }

    // segundo combo de fecha con faltas
    if (!query2.exec()) {
        QMessageBox::warning(this, "Error", "No se pudieron cargar las fechas de faltas: " + query2.lastError().text());
        return;
    }
    while (query2.next()) {
        QString fecha = query2.value(0).toDate().toString("yyyy-MM-dd");
        ui->comboBox_motivoRes_Fecha->addItem(fecha);
    }

    if (ui->comboBoxFecha->count() == 0) {
        QMessageBox::information(this, "Información", "El alumno seleccionado no tiene faltas registradas en el mes seleccionado.");
        ui->comboBoxMesFaltas->setCurrentIndex(0);
    } else if (ui->comboBox_motivoRes_Fecha->count() == 0) {
        QMessageBox::information(this, "Información", "El alumno seleccionado no tiene faltas registradas en el mes seleccionado.");
        ui->comboBox_motivoRes_Mes->setCurrentIndex(0);
    }
}

void resumen_de_asis_y_faltas::on_comboBox_motivoRes_Alu_currentIndexChanged(int index)
{
    // Obtiene el idAlumno del elemento seleccionado en el primer QComboBox
    QString idAlumno = ui->comboBox_motivoRes_Alu->itemData(index).toString();

    // Limpia el segundo comboBox antes de llenarlo
    ui->comboBox_motivoRes_Fecha->clear();

    QSqlQuery query;
    query.prepare("SELECT fechaFaltaAlu FROM FaltasAlumno WHERE idAlumno = :idAlumno");
    query.bindValue(":idAlumno", idAlumno);

    if (!query.exec()) {
        QMessageBox::warning(this, "Error", "No se pudieron cargar las fechas de faltas: " + query.lastError().text());
        return;
    }

    while (query.next()) {
        QString fechaFalta = query.value(0).toDate().toString("yyyy-MM-dd");
        ui->comboBox_motivoRes_Fecha->addItem(fechaFalta);
    }

    // Consultar el nombre y apellido del alumno basado en el ID
    QSqlQuery query2;
    query2.prepare("SELECT idAlumno FROM Alumnos WHERE idAlumno = :idAlumno");
    query2.bindValue(":idAlumno", idAlumno);

    if (query2.exec() && query2.next()) {
        ui -> label_IdAlu -> setText(idAlumno);
    } else {
        ui -> label_IdAlu -> setText("ID desconocido");
    }
}

void resumen_de_asis_y_faltas::on_comboBox_motivoRes_Fecha_currentIndexChanged(int index)
{
    if (index == -1) return; // Evitar ejecución si el índice no es válido

    QString fechaSeleccionada = ui->comboBox_motivoRes_Fecha->currentText();
    QString idAlumno = ui->comboBox_motivoRes_Alu->currentData().toString();

    if (fechaSeleccionada.isEmpty() || idAlumno.isEmpty()) {
        ui->label_motivoRes_Mot->setText("No hay datos");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT mf.descripMotFalta "
                  "FROM FaltasAlumno fa "
                  "JOIN motivoFalta mf ON fa.idMotFalta = mf.idMotFalta "
                  "WHERE fa.idAlumno = :idAlumno AND fa.fechaFaltaAlu = :fecha");
    query.bindValue(":idAlumno", idAlumno);
    query.bindValue(":fecha", fechaSeleccionada);

    if (query.exec() && query.next()) {
        QString descripcionMotivo = query.value(0).toString();
        ui->label_motivoRes_Mot->setText(descripcionMotivo);
    } else {
        ui->label_motivoRes_Mot->setText("Sin motivo registrado");
    }
}

