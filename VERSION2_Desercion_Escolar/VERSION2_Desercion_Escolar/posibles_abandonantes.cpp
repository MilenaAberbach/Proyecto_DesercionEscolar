#include "posibles_abandonantes.h" // Encabezado de la clase registro_de_asistencias
#include "ui_posibles_abandonantes.h" // Archivo generado automáticamente para gestionar la interfaz de usuario
#include "menu_herramientas.h" // Encabezado de la clase menu_herramientas
#include "inicio_de_sesion.h" // Encabezado de la clase inicio_de_sesion
#include "sesionusuario.h" // Encabezado de la clase sesionusuario

// Librerías utilizadas
#include <QMessageBox>
#include <QComboBox>
#include <QTableView>
#include <QShowEvent>

// Constructor de la clase posibles_abandonantes
posibles_abandonantes::posibles_abandonantes(QWidget *parent)
    : QMainWindow(parent) // Llama al constructor base QMainWindow con el padre especificado
    , ui(new Ui::posibles_abandonantes) // Inicializa el puntero de la interfaz de usuario
    , model(new QSqlQueryModel(this)) // Inicializa model
{
    ui->setupUi(this); // Configuración de la interfaz de usuario
    setWindowTitle("Posibles abandonantes - BackToLearn!"); // Establecer el título de la ventana
    conexionBdd();
    cargarAbandonantes();
}

// Destructor de la clase posibles_abandonantes
posibles_abandonantes::~posibles_abandonantes()
{
    delete ui;
}

// Establecer conexión con la base de datos
void posibles_abandonantes::conexionBdd()
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
void posibles_abandonantes::on_actionCambiar_cuenta_triggered()
{
    qDebug() << "\n\tBotón 'Cambiar cuenta' presionado.";

    inicio_de_sesion *inicioSesion = new inicio_de_sesion();
    inicioSesion->show();

    qDebug() << "\n\tNueva instancia de inicio_de_sesion creada y mostrada.";

    this->close(); // Cierra completamente la ventana actual
}

// Función que se ejecuta si el usuario presiona el desplegable "Volver" (Menú desplegable "Opciones" -> Subopción "Volver")
void posibles_abandonantes::on_actionVolver_triggered()
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
void posibles_abandonantes::on_actionSalir_triggered()
{
    close(); // Cierra la ventana actual
    qDebug() << "\n---- EL USUARIO SALIO DEL PROGRAMA"; // Muestra el mensaje por la consola
}

// Evento para recargar datos cada vez que se muestra la ventana
void posibles_abandonantes::showEvent(QShowEvent *event) {
    QMainWindow::showEvent(event);
    cargarAbandonantes();
}

void posibles_abandonantes::cargarAbandonantes() {

    QString cargo = SesionUsuario::getInstance().getCargoUsuario();
    int idCurso = SesionUsuario::getInstance().getIdCurso();

    qDebug() << "\n\t Cargando posibles abandonantes...";
    qDebug() << "\n\tUsuario con rol: " << cargo << "ID Curso:" << idCurso;

    QSqlQuery query;
    QString consultaSQL =
        "SELECT "
        "    a.idAlumno, "
        "    CONCAT(a.apellidoAlumno, ', ', a.nombreAlumno) AS nombreCompleto, "
        "    YEAR(f.fechaFaltaAlu) AS anio, "
        "    MONTH(f.fechaFaltaAlu) AS mes, "
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
        "WHERE f.idMotFalta IN (6, 7) ";

    // Si el usuario es PRECEPTOR, filtrar por su curso
    if (cargo == "Preceptor") {
        consultaSQL += " AND a.idCurso = :idCurso ";
    }

    consultaSQL +=
        "GROUP BY a.idAlumno, YEAR(f.fechaFaltaAlu), MONTH(f.fechaFaltaAlu) "
        "HAVING (totalFaltas > 15 AND maxFaltasConsecutivas >= 3) OR totalFaltas > 15 OR maxFaltasConsecutivas >= 3 "
        "ORDER BY a.apellidoAlumno, anio, mes;";

    query.prepare(consultaSQL);

    if (cargo == "Preceptor") {
        query.bindValue(":idCurso", idCurso);
    }

    if (!query.exec()) {
        qDebug() << "\n\tError en la consulta SQL (POSIBLES ABANDONANTES): " << query.lastError().text();
        QMessageBox::warning(this, "Error", "No se pudo cargar la lista de posibles abandonantes:\n" + query.lastError().text());
        return;
    }

    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, "ID Alumno");
    model->setHeaderData(1, Qt::Horizontal, "Nombre");
    model->setHeaderData(2, Qt::Horizontal, "Año");
    model->setHeaderData(3, Qt::Horizontal, "Mes");
    model->setHeaderData(4, Qt::Horizontal, "Total Faltas");
    model->setHeaderData(5, Qt::Horizontal, "Faltas Consecutivas");

    ui->tableView->setModel(model);
    // Configurar el modo de redimensionamiento de las columnas
    QHeaderView* header = ui->tableView->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Interactive); // Permitir ajuste dinámico

    // Asignar proporciones dinámicas para las columnas
    ui->tableView->setColumnWidth(0, 80); // "ID Alumno" más pequeño (80 píxeles aprox)
    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch); // "Nombre" ocupa más espacio
    for (int i = 2; i < model->columnCount(); ++i) {
        ui->tableView->horizontalHeader()->setSectionResizeMode(i, QHeaderView::ResizeToContents); // Otros normales
    }
}
