#include "reuniones.h" // Encabezado de la clase reuniones
#include "ui_reuniones.h" // Archivo generado automáticamente para gestionar la interfaz de usuario
#include "menu_herramientas.h" // Encabezado de la clase menu_herramientas
#include "inicio_de_sesion.h" // Encabezado de la clase inicio_de_sesion
#include "sesionusuario.h" // Encabezado de la clase sesionusuario

// Librerías utilizadas
#include <QMessageBox>
#include <QComboBox>
#include <QShowEvent>
#include <QLineEdit>
#include <QDate>

// Constructor de la clase reuniones
reuniones::reuniones(QWidget *parent)
    : QMainWindow(parent) // Llama al constructor base QMainWindow con el padre especificado
    , ui(new Ui::reuniones) // Inicializa el puntero de la interfaz de usuario
{
    ui->setupUi(this); // Configuración de la interfaz de usuario
    setWindowTitle("Reuniones - BackToLearn!"); // Establecer el título de la ventana
    conexionBdd();

    // Cargar alumnos del mes actual al inicio
    cargarAlumnosFaltas(ui->comboBox_alumno, ui->comboBox_mes->currentText());
    cargarFechas(ui->comboBox_fecha, ui->comboBox_mes->currentText());
    cargarAlumnosConReuniones();
    cargarReunionesAlumno();

    // Conectar la señal del comboBox de mes con la función de actualización
    connect(ui->comboBox_mes, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &reuniones::on_comboBox_mes_currentIndexChanged);
    connect(ui->comboBox_justif_Alumno, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &reuniones::on_comboBox_justif_Alumno_currentIndexChanged);
    connect(ui->comboBox_justif_Alumno, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &reuniones::actualizarIdAlumno);
    connect(ui->comboBox_cantReuniones, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &reuniones::actualizarCantidadReuniones);
    connect(ui->comboBox_cantReuniones2, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &reuniones::on_comboBox_cantReuniones2_currentIndexChanged);
}

// Destructor de la clase reuniones
reuniones::~reuniones()
{
    delete ui;
}

// Establecer conexión con la base de datos
void reuniones::conexionBdd()
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
void reuniones::on_actionCambiar_cuenta_triggered()
{
    qDebug() << "\n\tBotón 'Cambiar cuenta' presionado.";

    inicio_de_sesion *inicioSesion = new inicio_de_sesion();
    inicioSesion->show();

    qDebug() << "\n\tNueva instancia de inicio_de_sesion creada y mostrada.";

    this->close(); // Cierra completamente la ventana actual
}

// Función que se ejecuta si el usuario presiona el desplegable "Volver" (Menú desplegable "Opciones" -> Subopción "Volver")
void reuniones::on_actionVolver_triggered()
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
void reuniones::on_actionSalir_triggered()
{
    close(); // Cierra la ventana actual
    qDebug() << "\n---- EL USUARIO SALIO DEL PROGRAMA"; // Muestra el mensaje por la consola
}

// Evento para recargar datos cada vez que se muestra la ventana
void reuniones::showEvent(QShowEvent *event) {
    QMainWindow::showEvent(event);
    int index;
    // Limpiar los ComboBox
    ui->comboBox_alumno->clear();
    ui->comboBox_fecha->clear();
    ui->comboBox_justif_Alumno->clear();
    ui->comboBox_justif_Alumno->setCurrentIndex(0); // Vuelve al primer índice
    ui->comboBox_justifPadre->clear();
    ui->comboBox_justifPadre->setCurrentIndex(0); // Vuelve al primer índice
    ui->comboBox_cantReuniones->clear();
    ui->comboBox_cantReuniones->setCurrentIndex(0); // Vuelve al primer índice
    ui->label_cantReuniones->clear(); // Limpia el contenido del label
    ui->comboBox_cantReuniones2->clear();
    ui->comboBox_cantReuniones2->setCurrentIndex(0); // Vuelve al primer índice
    cargarAlumnosFaltas(ui->comboBox_alumno, ui->comboBox_mes->currentText());
    cargarFechas(ui->comboBox_fecha, ui->comboBox_mes->currentText());
    cargarAlumnosConReuniones();
    cargarReunionesAlumno();
}

void reuniones::on_comboBox_mes_currentIndexChanged(int index)
{
    QString mesSeleccionado = ui->comboBox_mes->currentText();
    cargarAlumnosFaltas(ui->comboBox_alumno, mesSeleccionado);
    cargarFechas(ui->comboBox_fecha, mesSeleccionado);
}

void reuniones::cargarAlumnosFaltas(QComboBox *comboBox_alumno, QString mesSeleccionado) {
    ui->comboBox_alumno->clear(); // Limpiar antes de cargar nuevos datos
    QString cargo = SesionUsuario::getInstance().getCargoUsuario();
    int idCurso = SesionUsuario::getInstance().getIdCurso();

    int faltasConsecutivas = (cargo == "Preceptor") ? 3 : 4;
    int faltasAcumuladas = 15; // Mismo criterio para ambos roles

    QSqlQuery query;
    QString consultaSQL =
        "SELECT "
        "    a.idAlumno, "
        "    CONCAT(a.apellidoAlumno, ', ', a.nombreAlumno) AS nombreCompleto, "
        "    COUNT(*) AS totalFaltas, "
        "    MAX(r.consecutivas) AS maxFaltasConsecutivas "
        "FROM Alumnos AS a "
        "INNER JOIN FaltasAlumno AS f ON a.idAlumno = f.idAlumno "
        "INNER JOIN ( "
        "    SELECT "
        "        idAlumno, "
        "        fechaFaltaAlu, "
        "        COUNT(*) OVER (PARTITION BY idAlumno, YEAR(fechaFaltaAlu), MONTH(fechaFaltaAlu), grp) AS consecutivas "
        "    FROM ( "
        "        SELECT "
        "            idAlumno, "
        "            fechaFaltaAlu, "
        "            idMotFalta, "
        "            DATE_SUB(fechaFaltaAlu, INTERVAL ROW_NUMBER() OVER ( "
        "                PARTITION BY idAlumno, YEAR(fechaFaltaAlu), MONTH(fechaFaltaAlu) "
        "                ORDER BY fechaFaltaAlu "
        "            ) DAY) AS grp "
        "        FROM FaltasAlumno "
        "        WHERE idMotFalta NOT IN (1, 2, 3, 4, 5) "
        "    ) AS sub "
        ") AS r ON f.idAlumno = r.idAlumno AND f.fechaFaltaAlu = r.fechaFaltaAlu "
        "WHERE YEAR(f.fechaFaltaAlu) = 2024 "
        "AND LPAD(MONTH(f.fechaFaltaAlu), 2, '0') = :mesSeleccionado "
        "AND f.idMotFalta IN (6, 7) ";

    // Filtrar por curso si el usuario es Preceptor
    if (cargo == "Preceptor") {
        consultaSQL += " AND a.idCurso = :idCurso ";
    }

    // Aplicar los criterios de faltas
    consultaSQL +=
        "GROUP BY a.idAlumno "
        "HAVING (totalFaltas > :faltasAcumuladas OR maxFaltasConsecutivas >= :faltasConsecutivas) "
        "ORDER BY a.apellidoAlumno;";

    query.prepare(consultaSQL);
    query.bindValue(":mesSeleccionado", mesSeleccionado);
    query.bindValue(":faltasAcumuladas", faltasAcumuladas);
    query.bindValue(":faltasConsecutivas", faltasConsecutivas);
    if (cargo == "Preceptor") {
        query.bindValue(":idCurso", idCurso);
    }

    if (!query.exec()) {
        qDebug() << "Error en consulta SQL:" << query.lastError().text();
        QMessageBox::warning(nullptr, "Error ", "No se pudieron cargar los alumnos: \n" + query.lastError().text());
        return;
    }

    bool hayAlumnos = false;

    while (query.next()) {
        int idAlumno = query.value("idAlumno").toInt();
        QString nombreCompleto = query.value("nombreCompleto").toString();
        ui->comboBox_alumno->addItem(nombreCompleto, idAlumno); // Añadir al ComboBox
        hayAlumnos = true;
    }

    // Si no se encontraron alumnos, mostrar mensaje y resetear el comboBox_mes
    if (!hayAlumnos) {
        QMessageBox::information(this, "Información", "No hay alumnos que cumplan con los criterios establecidos para ser considerados posibles abandonantes.");
        ui->comboBox_mes->setCurrentIndex(0); // Volver al primer mes
    }
}

void reuniones::cargarFechas(QComboBox *comboBox_fecha, QString mesSeleccionado) {
    comboBox_fecha->clear(); // Limpiar el comboBox antes de cargar nuevas fechas

    int mes = mesSeleccionado.toInt(); // Convertir el QString del combobox a entero
    int anio = 2024; // Año fijo
    QDate fechaInicio = (mes == 3) ? QDate(anio, mes, 4) : QDate(anio, mes, 1);
    QDate fechaFin(anio, mes, fechaInicio.daysInMonth());

    // Obtener lista de feriados desde la base de datos
    QSet<QDate> feriados;
    QSqlQuery query("SELECT fecha FROM Feriados WHERE YEAR(fecha) = 2024");
    while (query.next()) {
        feriados.insert(query.value(0).toDate());
    }

    // Recorrer todas las fechas del mes
    for (QDate fecha = fechaInicio; fecha <= fechaFin; fecha = fecha.addDays(1)) {
        if (fecha.dayOfWeek() == 6 || fecha.dayOfWeek() == 7) {
            continue; // Saltar sábados (6) y domingos (7)
        }
        if (feriados.contains(fecha)) {
            continue; // Saltar feriados registrados
        }

        comboBox_fecha->addItem(fecha.toString("yyyy/MM/dd"), fecha);
    }
}

void reuniones::on_btnCrearReunion_clicked()
{
    // Obtener datos seleccionados
    int idAlumno = ui->comboBox_alumno->currentData().toInt();
    QString fechaReunion = ui->comboBox_fecha->currentText();
    int idUsuario = SesionUsuario::getInstance().getIdUsuario();
    QString motivo = ui->lineEdit_motivo->text();

    // Validar que todos los datos estén completos
    if (motivo.isEmpty()) {
        QMessageBox::warning(this, "Error", "Debe completar todos los campos antes de registrar la reunión.");
        return;
    }

    // Insertar en la base de datos
    QSqlQuery query;
    query.prepare("INSERT INTO Reuniones (idAlumno, fechaReunion, idUsuario, motivoReunion) "
                  "VALUES (:idAlumno, :fechaReunion, :idUsuario, :motivo)");

    query.bindValue(":idAlumno", idAlumno);
    query.bindValue(":fechaReunion", fechaReunion);
    query.bindValue(":idUsuario", idUsuario);
    query.bindValue(":motivo", motivo);

    if (!query.exec()) {
        qDebug() << "\n\tError al registrar reunión (REUNIONES): " << query.lastError().text();
        QMessageBox::warning(this, "Error", "No se pudo registrar la reunión.");
        return;
    } else {
        QMessageBox::information(this, "Éxito", "Reunión registrada correctamente.");
        cargarAlumnosConReuniones();
        cargarReunionesAlumno();
        actualizarCantidadReuniones();
        int index;
        on_comboBox_cantReuniones2_currentIndexChanged(index);
        return;
    }
}

void reuniones::cargarAlumnosConReuniones() {
    ui->comboBox_justif_Alumno->clear(); // Limpiar antes de cargar nuevos datos
    ui->comboBox_cantReuniones->clear();

    int idUsuario = SesionUsuario::getInstance().getIdUsuario();

    QSqlQuery query;
    query.prepare(
        "SELECT DISTINCT a.idAlumno, CONCAT(a.apellidoAlumno, ', ', a.nombreAlumno) AS nombreCompleto "
        "FROM Reuniones AS r "
        "INNER JOIN Alumnos AS a ON r.idAlumno = a.idAlumno "
        "WHERE r.idUsuario = :idUsuario "
        );
    query.bindValue(":idUsuario", idUsuario);

    QSqlQuery query2;
    query2.prepare(
        "SELECT DISTINCT a.idAlumno, CONCAT(a.apellidoAlumno, ', ', a.nombreAlumno) AS nombreCompleto "
        "FROM Reuniones AS r "
        "INNER JOIN Alumnos AS a ON r.idAlumno = a.idAlumno "
        "WHERE r.idUsuario = :idUsuario "
        );
    query2.bindValue(":idUsuario", idUsuario);

    if (!query.exec()) {
        qDebug() << "\n\tError al cargar alumnos con reuniones: " << query.lastError().text();
        QMessageBox::warning(nullptr, "Error", "No se pudieron cargar los alumnos con reuniones.");
        return;
    }
    if (!query2.exec()) {
        qDebug() << "\n\tError al cargar alumnos con reuniones: " << query2.lastError().text();
        QMessageBox::warning(nullptr, "Error", "No se pudieron cargar los alumnos con reuniones.");
        return;
    }

    while (query.next()) {
        int idAlumno = query.value(0).toInt();
        QString nombreCompleto = query.value(1).toString();
        ui->comboBox_justif_Alumno->addItem(nombreCompleto, idAlumno);
    }

    while (query2.next()) {
        int idAlumno2 = query2.value(0).toInt();
        QString nombreCompleto2 = query2.value(1).toString();
        ui->comboBox_cantReuniones->addItem(nombreCompleto2, idAlumno2);
    }
}

void reuniones::cargarReunionesAlumno() {
    ui->comboBox_justifPadre->clear(); // Limpiar antes de cargar nuevos datos
    ui->comboBox_cantReuniones2->clear();
    int idAlumno = ui->comboBox_justif_Alumno->currentData().toInt();
    int idAlumno2 = ui->comboBox_cantReuniones->currentData().toInt();

    QSqlQuery query;
    query.prepare("SELECT idReunion, fechaReunion FROM Reuniones WHERE idAlumno = :idAlumno");
    query.bindValue(":idAlumno", idAlumno);

    QSqlQuery query2;
    query2.prepare("SELECT idReunion, fechaReunion FROM Reuniones WHERE idAlumno = :idAlumno");
    query2.bindValue(":idAlumno", idAlumno2);

    if (!query.exec()) {
        qDebug() << "\n\t1. Error al cargar reuniones del alumno: " << query.lastError().text();
        QMessageBox::warning(this, "Error", "No se pudieron cargar las reuniones.");
        return;
    }
    if (!query2.exec()) {
        qDebug() << "\n\t2. Error al cargar reuniones del alumno: " << query2.lastError().text();
        QMessageBox::warning(this, "Error", "No se pudieron cargar las reuniones.");
        return;
    }

    bool hayReuniones = false;
    bool hayReuniones2 = false;
    while (query.next()) {
        int idReunion = query.value(0).toInt();
        QString fechaReunion = query.value(1).toString();
        ui->comboBox_justifPadre->addItem(fechaReunion, idReunion);
        hayReuniones = true;
    }
    while (query2.next()) {
        int idReunion2 = query2.value(0).toInt();
        QString fechaReunion2 = query2.value(1).toString();
        ui->comboBox_cantReuniones2->addItem(fechaReunion2, idReunion2);
        hayReuniones2 = true;
    }

    if (!hayReuniones) {
        QMessageBox::information(this, "Información", "El alumno seleccionado no tiene reuniones registradas.");
        ui->label_motivoReunion->clear();
        return;
    }
    if (!hayReuniones2) {
        QMessageBox::information(this, "Información", "El alumno seleccionado no tiene reuniones registradas.");
        return;
        ui->label_motivoReunion->clear();
    }
}

void reuniones::on_comboBox_justif_Alumno_currentIndexChanged(int index)
{
    // Obtener el ID del alumno desde el comboBox
    QString idAlumno = ui->comboBox_justif_Alumno->currentData().toString();


    // Limpiar la lista de reuniones previas
    ui->comboBox_justifPadre->clear();

    // Verificar que el ID no esté vacío
    if (idAlumno.isEmpty()) {
        return;
    }

    // Obtener reuniones del nuevo alumno
    QSqlQuery query;
    query.prepare("SELECT idReunion, fechaReunion FROM Reuniones WHERE idAlumno = :idAlumno");
    query.bindValue(":idAlumno", idAlumno);

    if (query.exec()) {
        while (query.next()) {
            QString idReunion = query.value(0).toString();
            QString fecha = query.value(1).toString();
            ui->comboBox_justifPadre->addItem(fecha, idReunion);
        }
    } else {
        qDebug() << "\n\tError al cargar reuniones: " << query.lastError().text();
    }
}

void reuniones::on_btnConfirmarJustif_clicked() {
    int idReunion = ui->comboBox_justifPadre->currentData().toInt();
    QString justificacionPadre = ui->lineEdit_justifPadre->text();

    if (idReunion == 0 || justificacionPadre.isEmpty()) {
        QMessageBox::warning(this, "Error", "Debe seleccionar una reunión y escribir una justificación.");
        return;
    }

    QSqlQuery query;
    query.prepare("UPDATE Reuniones SET justificPadre = :justificacion WHERE idReunion = :idReunion");
    query.bindValue(":justificacion", justificacionPadre);
    query.bindValue(":idReunion", idReunion);

    if (!query.exec()) {
        qDebug() << "\n\tError al actualizar la justificación: " << query.lastError().text();
        QMessageBox::warning(this, "Error", "No se pudo actualizar la justificación.");
        return;
    }

    QMessageBox::information(this, "Éxito", "Justificación actualizada correctamente.");
}

void reuniones::actualizarCantidadReuniones() {
    int idAlumno = ui->comboBox_cantReuniones->currentData().toInt();

    if (idAlumno == 0) {
        ui->label_cantReuniones->setText("0");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM Reuniones WHERE idAlumno = :idAlumno");
    query.bindValue(":idAlumno", idAlumno);

    if (!query.exec()) {
        qDebug() << "\n\tError al contar reuniones: " << query.lastError().text();
        QMessageBox::warning(this, "Error", "No se pudo contar la cantidad de reuniones.");
        return;
    }

    if (query.next()) {
        int cantidadReuniones = query.value(0).toInt();
        ui->label_cantReuniones->setText(QString::number(cantidadReuniones));
    } else {
        ui->label_cantReuniones->setText("0");
    }
}

void reuniones::actualizarIdAlumno(int index)
{
    if (index < 0) return; // Evita errores si no hay selección

    // Obtener el ID del alumno seleccionado
    QString idAlumno = ui->comboBox_justif_Alumno->currentData().toString();

    // Consultar la base de datos para obtener el ID
    QSqlQuery query;
    query.prepare("SELECT idAlumno FROM Alumnos WHERE idAlumno = :id");
    query.bindValue(":id", idAlumno);

    if (query.exec() && query.next()) {
        QString nombreCompleto = query.value(0).toString();
        ui->label_7->setText(nombreCompleto);
    } else {
        ui->label_7->setText("ID no encontrado");
    }
}

void reuniones::on_comboBox_cantReuniones_currentIndexChanged(int index)
{
    // Obtener el ID del alumno desde el comboBox
    QString idAlumno = ui->comboBox_cantReuniones->currentData().toString();


    // Limpiar la lista de reuniones previas
    ui->comboBox_cantReuniones2->clear();

    // Verificar que el ID no esté vacío
    if (idAlumno.isEmpty()) {
        return;
    }

    // Obtener reuniones del nuevo alumno
    QSqlQuery query;
    query.prepare("SELECT idReunion, fechaReunion FROM Reuniones WHERE idAlumno = :idAlumno");
    query.bindValue(":idAlumno", idAlumno);

    if (query.exec()) {
        while (query.next()) {
            QString idReunion = query.value(0).toString();
            QString fecha = query.value(1).toString();
            ui->comboBox_cantReuniones2->addItem(fecha, idReunion);
        }
    } else {
        qDebug() << "\n\tError al cargar reuniones: " << query.lastError().text();
    }
}

void reuniones::on_comboBox_cantReuniones2_currentIndexChanged(int index)
{
    if (index < 0) return; // Evita errores si no hay selección

    int idReunion = ui->comboBox_cantReuniones2->currentData().toInt();

    if (idReunion == 0) {
        ui->label_motivoReunion->setText("...");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT motivoReunion FROM Reuniones WHERE idReunion = :idReunion");
    query.bindValue(":idReunion", idReunion);

    if (!query.exec()) {
        qDebug() << "\n\tError al encontrar motivo de reunion: " << query.lastError().text();
        QMessageBox::warning(this, "Error", "No se pudo encontrar el motivo de reunión.");
        return;
    }

    if (query.next()) {
        QString motivo = query.value(0).toString();
        ui->label_motivoReunion->setText(motivo);
    } else {
        ui->label_motivoReunion->setText("...");
    }
}

