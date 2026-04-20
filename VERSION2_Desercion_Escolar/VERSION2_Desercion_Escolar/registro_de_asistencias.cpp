#include "registro_de_asistencias.h" // Encabezado de la clase registro_de_asistencias
#include "ui_registro_de_asistencias.h" // Archivo generado automáticamente para gestionar la interfaz de usuario
#include "menu_herramientas.h" // Encabezado de la clase menu_herramientas
#include "inicio_de_sesion.h" // Encabezado de la clase inicio_de_sesion
#include "sesionusuario.h" // Encabezado de la clase sesionusuario

// Librerías utilizadas
#include <QMessageBox>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QComboBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDate>
#include <QList>
#include <QShowEvent>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

// Constructor de la clase registro_de_asistencias
registro_de_asistencias::registro_de_asistencias(QWidget *parent)
    : QMainWindow(parent) // Llama al constructor base QMainWindow con el padre especificado
    , ui(new Ui::registro_de_asistencias) // Inicializa el puntero de la interfaz de usuario
{
    ui -> setupUi(this); // Configuración de la interfaz de usuario
    setWindowTitle("Registro de asistencias (Alumnos) - BackToLearn!"); // Establecer el título de la ventana
    conexionBdd();
    cargarSemanas();

    connect(ui->comboSemana, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &registro_de_asistencias::onSemanaSeleccionada);
    if (ui->comboSemana->count() > 0) {
        actualizarTablaAsistencias(ui->comboSemana->currentData().toInt());
    }
    connect(ui->btnGuardar, &QPushButton::clicked, this, &registro_de_asistencias::guardarAsistencias);
}

// Destructor de la clase alta_de_alumnos
registro_de_asistencias::~registro_de_asistencias()
{
    delete ui;
}

// Establecer conexión con la base de datos
void registro_de_asistencias::conexionBdd()
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
void registro_de_asistencias::on_actionCambiar_cuenta_triggered()
{
    qDebug() << "\n\tBotón 'Cambiar cuenta' presionado.";

    inicio_de_sesion *inicioSesion = new inicio_de_sesion();
    inicioSesion->show();

    qDebug() << "\n\tNueva instancia de inicio_de_sesion creada y mostrada.";

    this->close(); // Cierra completamente la ventana actual
}

// Función que se ejecuta si el usuario presiona el desplegable "Volver" (Menú desplegable "Opciones" -> Subopción "Volver")
void registro_de_asistencias::on_actionVolver_triggered()
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
void registro_de_asistencias::on_actionSalir_triggered()
{
    close(); // Cierra la ventana actual
    qDebug() << "\n---- EL USUARIO SALIO DEL PROGRAMA"; // Muestra el mensaje por la consola
}

// Evento para recargar datos cada vez que se muestra la ventana
void registro_de_asistencias::showEvent(QShowEvent *event) {
    QMainWindow::showEvent(event);
    actualizarTablaAsistencias(ui->comboSemana->currentData().toInt());  // Recarga el comboBox cada vez que se muestra la ventana
}

void registro_de_asistencias::cargarSemanas()
{
    ui -> comboSemana -> clear(); // Limpiar el ComboBox
    QDate inicioClases(2024, 3, 4); // Fecha de inicio de clases

    for (int semana = 1; semana <= 43; ++semana) {
        QDate fechaInicio = inicioClases.addDays((semana - 1) * 7); // Inicio de la semana
        QDate fechaFin = fechaInicio.addDays(4);                   // Fin de la semana

        QString textoSemana = QString("Semana %1 (%2 - %3)")
                                  .arg(semana)
                                  .arg(fechaInicio.toString("dd/MM/yyyy"))
                                  .arg(fechaFin.toString("dd/MM/yyyy"));
        ui -> comboSemana -> addItem(textoSemana, semana);
    }
}

QList<QDate> registro_de_asistencias::obtenerFechasDeSemana(int semana)
{
    QDate inicioClases(2024, 3, 4); // Inicio de clases
    QDate inicioSemana = inicioClases.addDays((semana - 1) * 7); // Calcular el inicio de la semana

    QList<QDate> fechas;
    for (int i = 0; i < 5; ++i) { // De lunes a viernes
        fechas.append(inicioSemana.addDays(i));
    }

    return fechas;
}

void registro_de_asistencias::onSemanaSeleccionada()
{
    // Número de semana del ComboBox
    int semana = ui->comboSemana->currentData().toInt();
    actualizarTablaAsistencias(semana);
}

void registro_de_asistencias::actualizarTablaAsistencias(int semana)
{
    int idCurso = SesionUsuario::getInstance().getIdCurso();

    // Obtener las fechas correspondientes a la semana seleccionada
    QList<QDate> fechasSemana = obtenerFechasDeSemana(semana);

    // Configurar el número de columnas (1 para "Alumno" + 5 días)
    ui->tablaAsistencias->setColumnCount(6);
    QStringList cabeceras;
    cabeceras << "Alumno";

    // Añadir las fechas como cabeceras de las columnas
    for (const QDate &fecha : fechasSemana) {
        cabeceras << fecha.toString("dd/MM/yyyy");
    }
    ui->tablaAsistencias->setHorizontalHeaderLabels(cabeceras);

    // Configurar el comportamiento del encabezado
    QHeaderView *header = ui->tablaAsistencias->horizontalHeader();
    header->setStretchLastSection(false); // Permite configurar el tamaño proporcional de todas las columnas

    // Configurar las proporciones
    header->setSectionResizeMode(0, QHeaderView::Stretch); // "Alumno" se adapta proporcionalmente
    for (int i = 1; i <= 5; ++i) {
        header->setSectionResizeMode(i, QHeaderView::Stretch);
    }

    // Cargar los alumnos desde la base de datos
    QSqlQuery query;
    query.prepare("SELECT CONCAT(nombreAlumno, ' ', apellidoAlumno) AS nombre_completo FROM Alumnos WHERE idCurso = :idCurso");
    query.bindValue(":idCurso", idCurso);
    if (!query.exec()) {
        qDebug() << "\n\tError al obtener alumnos (REGISTRO DE ASISTENCIAS): " << query.lastError().text();
        return;
    }

    // Crear una lista con los nombres completos de los alumnos
    QStringList alumnos;
    while (query.next()) {
        alumnos << query.value("nombre_completo").toString();
    }

    // Configurar las filas del QTableWidget
    ui->tablaAsistencias->setRowCount(alumnos.size());

    for (int i = 0; i < alumnos.size(); ++i) {
        // Primera columna: Alumno
        QTableWidgetItem *itemAlumno = new QTableWidgetItem(alumnos[i]);
        ui->tablaAsistencias->setItem(i, 0, itemAlumno);

        // Crear un QWidget con dos QCheckBox para cada día
        for (int j = 1; j <= 5; ++j) {
            QWidget *widgetAsistencia = new QWidget();
            QCheckBox *checkPresente = new QCheckBox("P", widgetAsistencia);
            QCheckBox *checkAusente = new QCheckBox("A", widgetAsistencia);
            QCheckBox *checkNoCorresponde = new QCheckBox("NC", widgetAsistencia);
            checkPresente->setObjectName("P"); // Asigna el nombre "P"
            checkAusente->setObjectName("A"); // Asigna el nombre "A"
            checkNoCorresponde->setObjectName("NC"); // Asigna el nombre "NC"

            // Ajustar la disposición
            QHBoxLayout *layout = new QHBoxLayout(widgetAsistencia);
            layout->addWidget(checkPresente);
            layout->addWidget(checkAusente);
            layout->addWidget(checkNoCorresponde);
            layout->setContentsMargins(0, 0, 0, 0);
            layout->setAlignment(Qt::AlignCenter);
            widgetAsistencia->setLayout(layout);

            // Agregar el widget a la celda de la tabla
            ui->tablaAsistencias->setCellWidget(i, j, widgetAsistencia);

            // Conectar los checkboxes para que solo uno pueda estar marcado a la vez
            connect(checkPresente, &QCheckBox::clicked, this, [checkPresente, checkAusente]() {
                if (checkPresente->isChecked()) {
                    checkAusente->setChecked(false);
                }
            });
            connect(checkAusente, &QCheckBox::clicked, this, [checkPresente, checkAusente]() {
                if (checkAusente->isChecked()) {
                    checkPresente->setChecked(false);
                }
            });
            connect(checkNoCorresponde, &QCheckBox::clicked, this, [checkPresente, checkAusente, checkNoCorresponde]() {
                if (checkNoCorresponde->isChecked()) {
                    checkPresente->setChecked(false);
                    checkAusente->setChecked(false);
                }
            });
        }
    }
    ui->tablaAsistencias->setColumnWidth(0, ui->tablaAsistencias->width() * 0.2);
}

void registro_de_asistencias::guardarAsistencias()
{
    int idCurso = SesionUsuario::getInstance().getIdCurso();

    int semana = ui->comboSemana->currentData().toInt(); // Obtener la semana seleccionada
    QList<QDate> fechasSemana = obtenerFechasDeSemana(semana); // Fechas de la semana

    // Recorrer las filas (alumnos)
    for (int i = 0; i < ui->tablaAsistencias->rowCount(); ++i) {
        // Obtener el ID del alumno desde la base de datos
        QString nombreCompleto = ui->tablaAsistencias->item(i, 0)->text();
        QSqlQuery queryIdAlumno;
        queryIdAlumno.prepare("SELECT idAlumno FROM Alumnos WHERE CONCAT(nombreAlumno, ' ', apellidoAlumno) = :nombreCompleto AND idCurso = :idCurso");
        queryIdAlumno.bindValue(":nombreCompleto", nombreCompleto);
        queryIdAlumno.bindValue(":idCurso", idCurso);
        if (!queryIdAlumno.exec() || !queryIdAlumno.next()) {
            qDebug() << "\n\tError al obtener idAlumno o no se encontró: " << queryIdAlumno.lastError().text();
            continue;
        }
        int idAlumno = queryIdAlumno.value(0).toInt();
        qDebug() << "\n\tidAlumno encontrado: " << idAlumno;

        // Recorrer las columnas (días de la semana)
        for (int j = 1; j <= 5; ++j) {
            QWidget *widgetAsistencia = ui->tablaAsistencias->cellWidget(i, j);
            if (!widgetAsistencia) continue;

            QCheckBox *checkPresente = widgetAsistencia->findChild<QCheckBox *>("P");
            QCheckBox *checkAusente = widgetAsistencia->findChild<QCheckBox *>("A");
            QCheckBox *checkNoCorresponde = widgetAsistencia->findChild<QCheckBox *>("NC");

            QDate fecha = fechasSemana[j - 1]; // Fecha del día correspondiente

            if (checkPresente && checkPresente->isChecked()) {
                // INGRESO TARDÍO DE MENOS DE 15min = NO SE CUENTA FALTA!!!
                qDebug() << "\n\tIntentando guardar asistencia para idAlumno: " << idAlumno << " con fecha: " << fecha << " y semana: " << semana;

                // Verificar si ya existe una falta para este alumno y fecha
                QSqlQuery queryVerificarFalta;
                queryVerificarFalta.prepare("SELECT idFalta FROM FaltasAlumno WHERE idAlumno = :idAlumno AND fechaFaltaAlu = :fechaFaltaAlu");
                queryVerificarFalta.bindValue(":idAlumno", idAlumno);
                queryVerificarFalta.bindValue(":fechaFaltaAlu", fecha);

                if (queryVerificarFalta.exec() && queryVerificarFalta.next()) {
                    // Si existe una falta, eliminarla
                    int idFalta = queryVerificarFalta.value(0).toInt();
                    QSqlQuery queryEliminarFalta;
                    queryEliminarFalta.prepare("DELETE FROM FaltasAlumno WHERE idFalta = :idFalta");
                    queryEliminarFalta.bindValue(":idFalta", idFalta);

                    if (!queryEliminarFalta.exec()) {
                        qDebug() << "\n\tError al eliminar falta existente: " << queryEliminarFalta.lastError().text();
                        continue;
                    } else {
                        qDebug() << "\n\tFalta eliminada correctamente para idAlumno: " << idAlumno << " con fecha: " << fecha << " y semana: " << semana;
                    }
                }

                // Guardar la asistencia
                QSqlQuery queryAsistencia;
                queryAsistencia.prepare("INSERT INTO AsistenciasAlumno (idAlumno, fechaAsistencia, semana) "
                                        "VALUES (:idAlumno, :fechaAsistencia, :semana) "
                                        "ON DUPLICATE KEY UPDATE semana = VALUES(semana)");
                queryAsistencia.bindValue(":idAlumno", idAlumno);
                queryAsistencia.bindValue(":fechaAsistencia", fecha);
                queryAsistencia.bindValue(":semana", semana);

                if (!queryAsistencia.exec()) {
                    qDebug() << "\n\tError al guardar asistencias: " << queryAsistencia.lastError().text();
                } else {
                    qDebug() << "\n\t¡Las asistencias fueron guardadas correctamente!";
                }

            } else if (checkAusente && checkAusente->isChecked()) {
                // INGRESO TARDÍO DE MÁS DE 15min = SE CUENTA FALTA!!!
                qDebug() << "\n\tIntentando guardar falta para idAlumno: " << idAlumno << " con fecha: " << fecha << " y semana: " << semana;

                // Verificar si ya existe una asistencia para este alumno y fecha
                QSqlQuery queryVerificarAsistencia;
                queryVerificarAsistencia.prepare("SELECT idAsistencia FROM AsistenciasAlumno WHERE idAlumno = :idAlumno AND fechaAsistencia = :fechaAsistencia");
                queryVerificarAsistencia.bindValue(":idAlumno", idAlumno);
                queryVerificarAsistencia.bindValue(":fechaAsistencia", fecha);

                if (queryVerificarAsistencia.exec() && queryVerificarAsistencia.next()) {
                    // Si existe una falta, eliminarla
                    int idAsistencia = queryVerificarAsistencia.value(0).toInt();
                    QSqlQuery queryEliminarAsistencia;
                    queryEliminarAsistencia.prepare("DELETE FROM AsistenciasAlumno WHERE idAsistencia = :idAsistencia");
                    queryEliminarAsistencia.bindValue(":idAsistencia", idAsistencia);

                    if (!queryEliminarAsistencia.exec()) {
                        qDebug() << "\n\tError al eliminar falta existente: " << queryEliminarAsistencia.lastError().text();
                        continue;
                    } else {
                        qDebug() << "\n\tAsistencia eliminada correctamente para idAlumno: " << idAlumno << " con fecha: " << fecha << " y semana: " << semana;
                    }
                }

                // Guardar la falta
                QSqlQuery queryFalta;
                queryFalta.prepare("INSERT INTO FaltasAlumno (idAlumno, fechaFaltaAlu, idMotFalta, semana) "
                                   "VALUES (:idAlumno, :fechaFaltaAlu, :idMotFalta, :semana) "
                                   "ON DUPLICATE KEY UPDATE idMotFalta = VALUES(idMotFalta)");
                queryFalta.bindValue(":idAlumno", idAlumno);
                queryFalta.bindValue(":fechaFaltaAlu", fecha);
                queryFalta.bindValue(":idMotFalta", 7); // MOTIVO POR DEFECTO, LUEGO SE PUEDE CAMBIAR EN EL APARTADO DE RESUMEN DE FALTAS
                queryFalta.bindValue(":semana", semana);

                if (!queryFalta.exec()) {
                    qDebug() << "\n\tError al guardar faltas: " << queryFalta.lastError().text();
                } else {
                    qDebug() << "\n\t¡Las faltas fueron guardadas correctamente!";
                }
            } else if (checkNoCorresponde && checkNoCorresponde->isChecked()) {
                // Día marcado como "No corresponde", no guardar nada en la base de datos (Feriado o razones de fuerza mayor)
                qDebug() << "\n\tDía marcado como 'NC (Feriado / Razones de fuerza mayor)' para idAlumno: " << idAlumno << " fecha: " << fecha << " y semana: " << semana;

                // Verificar si ya existe una falta para este alumno y fecha
                QSqlQuery queryVerificarNc1;
                queryVerificarNc1.prepare("SELECT idFalta FROM FaltasAlumno WHERE idAlumno = :idAlumno AND fechaFaltaAlu = :fechaFaltaAlu");
                queryVerificarNc1.bindValue(":idAlumno", idAlumno);
                queryVerificarNc1.bindValue(":fechaFaltaAlu", fecha);

                if (queryVerificarNc1.exec() && queryVerificarNc1.next()) {
                    // Si existe una falta, eliminarla
                    int idFalta = queryVerificarNc1.value(0).toInt();
                    QSqlQuery queryEliminarFalta;
                    queryEliminarFalta.prepare("DELETE FROM FaltasAlumno WHERE idFalta = :idFalta");
                    queryEliminarFalta.bindValue(":idFalta", idFalta);

                    if (!queryEliminarFalta.exec()) {
                        qDebug() << "\n\tError al eliminar falta existente: " << queryEliminarFalta.lastError().text();
                        continue;
                    } else {
                        qDebug() << "\n\tFalta eliminada correctamente para idAlumno: " << idAlumno << " con fecha: " << fecha << " y semana: " << semana;
                    }
                }

                QSqlQuery queryVerificarNc2;
                queryVerificarNc2.prepare("SELECT idAsistencia FROM AsistenciasAlumno WHERE idAlumno = :idAlumno AND fechaAsistencia = :fechaAsistencia");
                queryVerificarNc2.bindValue(":idAlumno", idAlumno);
                queryVerificarNc2.bindValue(":fechaAsistencia", fecha);

                if (queryVerificarNc2.exec() && queryVerificarNc2.next()) {
                    // Si existe una falta, eliminarla
                    int idAsistencia = queryVerificarNc2.value(0).toInt();
                    QSqlQuery queryEliminarAsistencia;
                    queryEliminarAsistencia.prepare("DELETE FROM AsistenciasAlumno WHERE idAsistencia = :idAsistencia");
                    queryEliminarAsistencia.bindValue(":idAsistencia", idAsistencia);

                    if (!queryEliminarAsistencia.exec()) {
                        qDebug() << "\n\tError al eliminar falta existente: " << queryEliminarAsistencia.lastError().text();
                        continue;
                    } else {
                        qDebug() << "\n\tAsistencia eliminada correctamente para idAlumno: " << idAlumno << ", fecha: " << fecha;
                    }
                }
            }
        }
    }
    QMessageBox::information(this, "Éxito", "¡Las asistencias/faltas fueron guardadas correctamente!");
    // Limpiar la tabla
    ui->tablaAsistencias->clearContents();
    ui->tablaAsistencias->setRowCount(0);

    // Restablecer el combo de semanas
    ui->comboSemana->setCurrentIndex(0);

    // Cargar nuevamente los datos para la semana inicial
    if (ui->comboSemana->count() > 0) {
        int semanaInicial = ui->comboSemana->currentData().toInt();
        actualizarTablaAsistencias(semanaInicial);
    }
}

