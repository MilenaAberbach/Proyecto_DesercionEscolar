#include "listado_de_alumnos.h" // Encabezado de la clase listado_de_alumnos
#include "ui_listado_de_alumnos.h" // Archivo generado automáticamente para gestionar la interfaz de usuario
#include "menu_herramientas.h" // Encabezado de la clase menu_herramientas
#include "inicio_de_sesion.h" // Encabezado de la clase inicio_de_sesion
#include "sesionusuario.h" // Encabezado de la clase sesionusuario

// Librerías utilizadas
#include <QDebug>
#include <QMessageBox>
#include <QComboBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QShowEvent>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

// Constructor de la clase listado_de_alumnoss
listado_de_alumnos::listado_de_alumnos(QWidget *parent)
    : QMainWindow(parent) // Llama al constructor base QMainWindow con el padre especificado
    , ui(new Ui::listado_de_alumnos) // Inicializa el puntero de la interfaz de usuario
{
    ui -> setupUi(this); // Configuración de la interfaz de usuario
    setWindowTitle("Listado de alumnos - BackToLearn!"); // Establecer el título de la ventana
    conexionBdd();

    // Configurar el combobox para ordenar por columnas
    ui -> comboBoxOrdenamiento -> addItem("idAlumno");       // index 0
    ui -> comboBoxOrdenamiento -> addItem("nombreAlumno");   // index 1
    ui -> comboBoxOrdenamiento -> addItem("apellidoAlumno"); // index 2
    ui -> comboBoxOrdenamiento -> addItem("edadAlumno"); // index 3
    ui -> comboBoxOrdenamiento -> addItem("idCurso"); // index 4

    // Configurar el combobox para tipo de orden (Ascendente o Descendente)
    ui -> comboBoxOrdAscDesc -> addItem("Ascendente"); // index 0
    ui -> comboBoxOrdAscDesc -> addItem("Descendente"); // index 1

    // Cargar datos iniciales
    cargarDatos("", "idAlumno", true);

    // Expresión regular para validar nombres y apellidos
    QRegularExpression regex("^[a-zA-ZáéíóúÁÉÍÓÚñÑ ]+$");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regex, this);
    // Aplicar el validador a la barra de búsqueda
    ui -> lEdit_barraBusqueda -> setValidator(validator);

    // Conectar la barra de búsqueda
    connect(ui -> lEdit_barraBusqueda, &QLineEdit::textChanged, this, &listado_de_alumnos::on_lEdit_barraBusqueda_textChanged);
    // Conectar el comboBox para ordenar por un campo específico
    connect(ui -> comboBoxOrdenamiento, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &listado_de_alumnos::on_comboBoxOrdenamiento_currentIndexChanged);
    // Conectar el comboBox para orden ascendente o descendiente
    connect(ui -> comboBoxOrdAscDesc, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &listado_de_alumnos::on_comboBoxOrdAscDesc_currentIndexChanged);
}

// Destructor de la clase listado_de_alumnos
listado_de_alumnos::~listado_de_alumnos()
{
    delete ui;
}

// Establecer conexión con la base de datos
void listado_de_alumnos::conexionBdd()
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
void listado_de_alumnos::on_actionCambiar_cuenta_triggered()
{
    qDebug() << "\n\tBotón 'Cambiar cuenta' presionado.";

    inicio_de_sesion *inicioSesion = new inicio_de_sesion();
    inicioSesion->show();

    qDebug() << "\n\tNueva instancia de inicio_de_sesion creada y mostrada.";

    this->close(); // Cierra completamente la ventana actual
}

// Función que se ejecuta si el usuario presiona el desplegable "Volver" (Menú desplegable "Opciones" -> Subopción "Volver")
void listado_de_alumnos::on_actionVolver_triggered()
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
void listado_de_alumnos::on_actionSalir_triggered()
{
    close(); // Cierra la ventana actual
    qDebug() << "\n---- EL USUARIO SALIO DEL PROGRAMA"; // Muestra el mensaje por la consola
}

// Evento que se ejecuta cuando la ventana es mostrada
void listado_de_alumnos::showEvent(QShowEvent *event)
{
    QMainWindow::showEvent(event);
    qDebug() << "\n\tDatos recargados al mostrar la ventana.";
    cargarDatos("", "idAlumno", true); // Recargar todos los datos al mostrar la ventana
}

// Cargar datos en la tabla de alumnos con filtros y orden
void listado_de_alumnos::cargarDatos(const QString &filtro, const QString &columnaOrden, bool ascendente)
{
    QSqlQuery query;
    QString consulta = "SELECT * FROM Alumnos";

    // Obtenemos el idUsuario, cargo e idCurso de la cuenta actual (preceptor)
    QString cargo = SesionUsuario::getInstance().getCargoUsuario();
    int idCurso = SesionUsuario::getInstance().getIdCurso();

    // Aplicar filtro de curso si el usuario es Preceptor
    if (cargo == "Preceptor") {
        consulta += QString(" WHERE idCurso = %1").arg(idCurso);

        // Si además hay un filtro de búsqueda, se añade con AND
        if (!filtro.isEmpty()) {
            consulta += " AND (nombreAlumno LIKE :filtro OR apellidoAlumno LIKE :filtro)";
        }
    }
    else if (!filtro.isEmpty()) {
        consulta += " WHERE nombreAlumno LIKE :filtro OR apellidoAlumno LIKE :filtro";
    }

    // Agregar ordenamiento
    if (!columnaOrden.isEmpty()) {
        consulta += QString(" ORDER BY %1 %2")
        .arg(columnaOrden)
            .arg(ascendente ? "ASC" : "DESC");
    }

    query.prepare(consulta);

    // Asignar valor al filtro en la consulta
    if (!filtro.isEmpty()) {
        query.bindValue(":filtro", "%" + filtro + "%");
    }

    // Ejecutar consulta y verificar si fue exitosa
    if (!query.exec()) {
        qDebug() << "\n\tError al ejecutar consulta: " << query.lastError().text();
        return;
    }

    // Crear un modelo para la tabla
    QSqlQueryModel *modelo = new QSqlQueryModel(this);
    modelo -> setQuery(query);

    // Configurar el modelo a la vista de tabla
    ui -> tableView -> setModel(modelo);
    ui -> tableView -> resizeColumnsToContents();
    qDebug() << "\n\tDatos cargados exitosamente con filtro: " << filtro << ", orden: " << columnaOrden;
}

// Acción que se ejecuta cuando cambia el texto de la barra de búsqueda
void listado_de_alumnos::on_lEdit_barraBusqueda_textChanged(const QString &arg1)
{
    qDebug() << "\n\tTexto de búsqueda cambiado: " << arg1;
    // Validar el texto de entrada para eliminar caracteres especiales
    QString textoFiltrado = arg1;
    textoFiltrado.remove(QRegularExpression("[^a-zA-ZáéíóúÁÉÍÓÚñÑ ]"));
    cargarDatos(textoFiltrado, ui -> comboBoxOrdenamiento -> currentText(), true);
}

// Acción que se ejecuta cuando cambia el índice del ComboBox de ordenamiento
void listado_de_alumnos::on_comboBoxOrdenamiento_currentIndexChanged(int columna)
{
    // Obtener el texto del combobox y determinar si es un orden válido
    QString columnaOrden;

    switch (columna) {
    case 0: // ID
        columnaOrden = "idAlumno";
        break;
    case 1: // Nombre
        columnaOrden = "nombreAlumno";
        break;
    case 2: // Apellido
        columnaOrden = "apellidoAlumno";
        break;
    case 3: // Edad
        columnaOrden = "edadAlumno";
        break;
    default:
        columnaOrden = "";
        break;
    }
    cargarDatos(ui -> lEdit_barraBusqueda -> text(), columnaOrden, true);
}

// Acción que se ejecuta cuando cambia el índice del combobox de tipo de orden
void listado_de_alumnos::on_comboBoxOrdAscDesc_currentIndexChanged(int index)
{
    // Llamar a cargarDatos con el nuevo orden (ascendente o descendente)
    bool ascendente = (index == 0); // Ascendente si index es 0, Descendente si es 1
    cargarDatos(ui -> lEdit_barraBusqueda -> text(), ui -> comboBoxOrdenamiento -> currentText(), ascendente);
}
