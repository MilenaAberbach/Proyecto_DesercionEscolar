#include "inicio_de_sesion.h" // Encabezado de la clase inicio_de_sesion
#include "ui_inicio_de_sesion.h" // Archivo generado automáticamente para gestionar la interfaz de usuario
#include "pantalla_inicio.h" // Encabezado de la clase pantalla_inicio
#include "olvide_mi_contrasena.h" // Encabezado de la clase olvide_mi_contrasena
#include "menu_herramientas.h" // Encabezado de la clase menu_herramientas
#include "sesionusuario.h" // Encabezado de la clase sesionusuario

// Librerías utilizadas
#include <QLineEdit>
#include <QMessageBox>
#include <QShowEvent>

// Constructor de la clase inicio_de_sesion
inicio_de_sesion::inicio_de_sesion(QWidget *parent)
    : QMainWindow(parent) // Llama al constructor base QMainWindow con el padre especificado
    , ui(new Ui::inicio_de_sesion) // Inicializa el puntero de la interfaz de usuario
    , olvideContra(nullptr) // Inicializa el puntero del apartado de olvidé mi contraseña a nullptr
    , menuHerramientas(nullptr) // Inicializa el puntero del apartado de menú de herramientas a nullptr
{
    ui -> setupUi(this); // Configuración de la interfaz de usuario
    setWindowTitle("Inicio de sesión - BackToLearn!"); // Establecer el título de la ventana
    conexionBdd();

    // Configurar el QLineEdit para ocultar la contraseña desde el inicio
    ui->lEdit_contrasena->setEchoMode(QLineEdit::Password);
}

// Destructor de la clase inicio_de_sesion
inicio_de_sesion::~inicio_de_sesion()
{
    delete ui;
}

// Establecer conexión con la base de datos
void inicio_de_sesion::conexionBdd()
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

// Función que se ejecuta si el usuario presiona el desplegable "Volver" (Menú desplegable "Opciones" -> Subopción "Volver")
void inicio_de_sesion::on_actionVolver_triggered()
{
    // Obtener el puntero de la pantalla de inicio desde el parent
    pantalla_inicio *pantallaInicio = qobject_cast<pantalla_inicio *>(parent());
    if (pantallaInicio) {
        pantallaInicio -> show(); // Mostrar la pantalla de inicio
        this -> close(); // Ocultar la ventana secundaria
        qDebug() << "\n---- EL USUARIO VOLVIO A LA PANTALLA DE INICIO"; // Muestra el mensaje por la consola
    }
}

// Función que se ejecuta si el usuario presiona el desplegable "Salir" (Menú desplegable "Opciones" -> Subopción "Salir")
void inicio_de_sesion::on_actionSalir_triggered()
{
    close(); // Cierra la ventana actual
    qDebug() << "\n---- EL USUARIO SALIO DEL PROGRAMA"; // Muestra el mensaje por la consola
}

// Evento que se ejecuta cuando la ventana es mostrada
void inicio_de_sesion::showEvent(QShowEvent *event) {
    QMainWindow::showEvent(event);
    ui->lEdit_mail->clear(); // Limpia el campo de email
    ui->lEdit_contrasena->clear(); // Limpia el campo de contraseña
}

// Función que se ejecuta si el usuario presiona el botón "INICIAR SESIÓN" (color verde)
void inicio_de_sesion::on_btnIniciar_clicked()
{
    QString email = ui->lEdit_mail->text().trimmed();
    QString contrasena = ui->lEdit_contrasena->text().trimmed();

    // 1. Verificar si los campos están vacíos
    if (email.isEmpty() && contrasena.isEmpty()) {
        qDebug() << "\n\tError (INICIO DE SESIÓN): Los campos de email y contraseña no pueden estar vacíos.";
        QMessageBox::warning(this, "Error ", "Los campos de email y contraseña no pueden estar vacíos.");
        return;
    } else if (email.isEmpty()) {
        qDebug() << "\n\tError (INICIO DE SESIÓN): El campo del email no puede estar vacío.";
        QMessageBox::warning(this, "Error ", "El campo de email no puede estar vacío.");
        return;
    } else if (contrasena.isEmpty()) {
        qDebug() << "\n\tError (INICIO DE SESIÓN): El campo de contraseña no puede estar vacío.";
        QMessageBox::warning(this, "Error ", "El campo de contraseña no puede estar vacío.");
        return;
    }

    // 2. Consultar si el correo está registrado
    QSqlQuery query;
    query.prepare("SELECT contraUsuario FROM Usuario WHERE mailUsuario = :email");
    query.bindValue(":email", email);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error ", "Error al ejecutar la consulta: " + query.lastError().text());
        return;
    }
    if (!query.next()) {
        QMessageBox::warning(this, "Error ", "El correo ingresado no está registrado.");
        return;
    }

    // 3. Verificar si la contraseña es correcta
    QString contrasena_correcta = query.value(0).toString();
    if (contrasena != contrasena_correcta) {
        QMessageBox::warning(this, "Error ", "La contraseña que fue ingresada es incorrecta.");
        return;
    }

    // 4. Si todo está bien, iniciar sesión correctamente
    QMessageBox::information(this, "Éxito", "Inicio de sesión exitoso.             ");
    qDebug() << "---- EL USUARIO HA PODIDO INICIAR SESIÓN DE MANERA EXITOSA. REDIRIGIÉNDOLO AL MENÚ DE HERRAMIENTAS!!!";

    query.prepare(R"(
        SELECT U.idUsuario, P.idCurso,
               COALESCE(CONCAT(P.nombrePrece, ' ', P.apellidoPrece), CONCAT(D.nombre_MDOE, ' ', D.apellido_MDOE)) AS nombreCompleto,
               CASE
                   WHEN P.idPrece IS NOT NULL THEN 'Preceptor'
                   WHEN D.id_DOE IS NOT NULL THEN 'Miembro del DOE'
                   ELSE 'Desconocido'
               END AS cargo
        FROM Usuario U
        LEFT JOIN Preceptores P ON U.idUsuario = P.idCuentaPrece
        LEFT JOIN MiembrosDOE D ON U.idUsuario = D.idCuenta_MDOE
        WHERE U.mailUsuario = :email
    )");
    query.bindValue(":email", email);

    if (query.exec()) {
        if (query.next()) {
            int idUsuario = query.value("idUsuario").toInt();
            QString nombreCompleto = query.value("nombreCompleto").toString();
            QString cargo = query.value("cargo").toString();
            int idCurso = query.value("idCurso").toInt();

            // Guardar los datos en el Singleton
           SesionUsuario::getInstance().setUsuario(idUsuario, nombreCompleto, cargo, idCurso);

            qDebug() << "\n\tInicio de sesión exitoso. ID USUARIO: " << idUsuario;
            qDebug() << "\n\tNOMBRE COMPLETO: " << nombreCompleto;
            qDebug() << "\n\tCARGO: " << cargo;
            qDebug() << "\n\tCURSO QUE TIENE A CARGO: " << idCurso;

            // Mostrar la ventana del menú de herramientas y pasar los datos
            if (!menuHerramientas) {
                menuHerramientas = new menu_herramientas(this);
            }
            menuHerramientas->setDatosUsuario(nombreCompleto, cargo);
            menuHerramientas->show();
            this->hide();
        }
    } else {
        qDebug() << "\n\tError en la consulta: " << query.lastError().text();
    }
}

void inicio_de_sesion::on_btnOlvide_clicked()
{
    // Verifica si la ventana olvide_mi_contrasena no ha sido creada aún
    if (!olvideContra) {
        olvideContra = new olvide_mi_contrasena(this);
    }

    olvideContra->show(); // Muestra la ventana de olvide_mi_contrasena
    this->hide(); // Oculta la ventana actual
    qDebug() << "\n---- EL USUARIO SE FUE AL APARTADO DE OLVIDÉ MI CONTRASEÑA";
}
