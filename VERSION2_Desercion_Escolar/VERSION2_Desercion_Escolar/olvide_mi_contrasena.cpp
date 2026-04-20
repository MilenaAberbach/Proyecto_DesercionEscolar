#include "olvide_mi_contrasena.h"
#include "ui_olvide_mi_contrasena.h"
#include "inicio_de_sesion.h" // Encabezado de la clase inicio_de_sesion

// Librerías utilizadas
#include <QLineEdit>
#include <QMessageBox>
#include <QComboBox>
#include <QVariant>
#include <QInputDialog>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

// Constructor de la clase olvide_mi_contrasena
olvide_mi_contrasena::olvide_mi_contrasena(QWidget *parent)
    : QMainWindow(parent) // Llama al constructor base QMainWindow con el padre especificado
    , ui(new Ui::olvide_mi_contrasena) // Inicializa el puntero de la interfaz de usuario
{
    ui -> setupUi(this); // Configuración de la interfaz de usuario
    setWindowTitle("Olvidé mi contraseña - BackToLearn!"); // Establecer el título de la ventana
    conexionBdd();

    // Expresión regular para validar nombres y apellidos con letras, números y símbolos simples, excluyendo el carácter `, espacios, eñes y tildes
    QRegularExpression regex("^[a-zA-Z0-9@#$%&¡!*()'-_+=:;.¿?]+$");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(QRegularExpression("^[a-zA-Z0-9@#$%&¡!*(),'-_+=:;.¿?]+[^`´|°¬ñ]"), this);

    // Aplicar el validador a los campos
    ui -> lEdit_nuevaContrasena -> setValidator(validator);

    // Configurar el QLineEdit para ocultar la contraseña desde el inicio
    ui->lEdit_nuevaContrasena->setEchoMode(QLineEdit::Password);
}

// Destructor de la clase olvide_mi_contrasena
olvide_mi_contrasena::~olvide_mi_contrasena()
{
    delete ui;
}

// Establecer conexión con la base de datos
void olvide_mi_contrasena::conexionBdd()
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
void olvide_mi_contrasena::on_actionVolver_triggered()
{
    // Obtener el puntero del apartado de inicio de sesion desde el parent
    inicio_de_sesion *inicioSesion = qobject_cast<inicio_de_sesion *>(parent());
    if (inicioSesion) {
        inicioSesion -> show(); // Mostrar la pantalla de inicio de sesion
        this -> hide(); // Ocultar la ventana secundaria
        qDebug() << "\n---- EL USUARIO VOLVIO AL APARTADO DE INICIO DE SESION"; // Muestra el mensaje por la consola
    }
}

// Función que se ejecuta si el usuario presiona el desplegable "Salir" (Menú desplegable "Opciones" -> Subopción "Salir")
void olvide_mi_contrasena::on_actionSalir_triggered()
{
    close(); // Cierra la ventana actual
    qDebug() << "\n---- EL USUARIO SALIO DEL PROGRAMA"; // Muestra el mensaje por la consola
}

// Función que se ejecuta si el usuario presiona el botón de recuperar contraseña
void olvide_mi_contrasena::on_btnRecuperar_clicked()
{
    QString mail = ui->lEdit_mail->text();
    QString respuestaIngresada = ui->lEdit_respuesta->text();
    QString nuevaContrasena = ui->lEdit_nuevaContrasena->text();

    if (mail.isEmpty() || nuevaContrasena.isEmpty()) {
        QMessageBox::warning(this, "Error", "Todos los campos son obligatorios.             ");
        return;
    }

    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    query.prepare("SELECT idUsuario FROM Usuario WHERE mailUsuario = :mail");
    query.bindValue(":mail", mail);

    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "Error", "El mail ingresado no fue encontrado.             ");
        return;
    }

    int idUsuario = query.value(0).toInt();

    query.prepare("SELECT idPregunta, respuesta FROM respuestas_seguridad WHERE idUsuario = :idUsuario");
    query.bindValue(":idUsuario", idUsuario);

    if (!query.exec()) {
        qDebug() << "\n\tError al verificar la pregunta de seguridad (OLVIDÉ MI CONTRASEÑA): " << query.lastError().text();
        QMessageBox::critical(this, "Error", "No se pudo verificar la pregunta de seguridad.");
        return;
    }

    if (query.next()) {
        QString respuestaCorrecta = query.value(1).toString();

        if (respuestaIngresada.isEmpty()) {
            QMessageBox::warning(this, "Error", "Debe ingresar la respuesta a la pregunta de seguridad.");
            return;
        }

        if (respuestaIngresada == respuestaCorrecta) {
            query.prepare("UPDATE Usuario SET contraUsuario = :nuevaContrasena WHERE idUsuario = :idUsuario");
            query.bindValue(":nuevaContrasena", nuevaContrasena);
            query.bindValue(":idUsuario", idUsuario);

            if (!query.exec()) {
                qDebug() << "\n\tError al actualizar contraseña (OLVIDÉ MI CONTRASEÑA): " << query.lastError().text();
                QMessageBox::critical(this, "Error", "No se pudo actualizar la contraseña.             ");
            } else {
                QMessageBox::information(this, "Éxito", "Contraseña restablecida correctamente.             ");
            }
        } else {
            QMessageBox::warning(this, "Error", "Su respuesta a la pregunta de seguridad es incorrecta.");
        }
    } else {
        QSqlQuery preguntasQuery(db);
        preguntasQuery.prepare("SELECT idPregunta, tituloPregunta FROM Preguntas_Seguridad");
        if (!preguntasQuery.exec()) {
            qDebug() << "\n\tError al obtener preguntas de seguridad (OLVIDÉ MI CONTRASEÑA): " << preguntasQuery.lastError().text();
            QMessageBox::critical(this, "Error", "No se pudieron cargar las preguntas de seguridad.");
            return;
        }

        QStringList preguntas;
        QMap<QString, int> mapaPreguntas;
        while (preguntasQuery.next()) {
            int idPregunta = preguntasQuery.value(0).toInt();
            QString titulo = preguntasQuery.value(1).toString();
            preguntas.append(titulo);
            mapaPreguntas[titulo] = idPregunta;
        }

        QString preguntaSeleccionada = QInputDialog::getItem(this, "Seleccione una pregunta", "Pregunta de seguridad:             ", preguntas, 0, false);
        if (preguntaSeleccionada.isEmpty()) {
            QMessageBox::warning(this, "Error", "Debe seleccionar una pregunta de seguridad.");
            return;
        }

        QString nuevaRespuesta = QInputDialog::getText(this, "Ingrese la respuesta", "Respuesta a la pregunta de seguridad:             ", QLineEdit::Normal);
        if (nuevaRespuesta.isEmpty()) {
            QMessageBox::warning(this, "Error", "Debe ingresar una respuesta a la pregunta de seguridad.");
            return;
        }

        query.prepare("INSERT INTO respuestas_seguridad (idUsuario, idPregunta, respuesta) VALUES (:idUsuario, :idPregunta, :respuesta)");
        query.bindValue(":idUsuario", idUsuario);
        query.bindValue(":idPregunta", mapaPreguntas[preguntaSeleccionada]);
        query.bindValue(":respuesta", nuevaRespuesta);

        if (!query.exec()) {
            qDebug() << "Error al guardar pregunta y respuesta secreta: " << query.lastError().text();
            QMessageBox::critical(this, "Error", "No se pudo guardar la pregunta de seguridad.");
            return;
        }
        QMessageBox::information(this, "Éxito", "Pregunta de seguridad guardada correctamente. Intente cambiar la contraseña nuevamente.");
    }
    ui->lEdit_mail->clear();
    ui->lEdit_respuesta->clear();
    ui->lEdit_nuevaContrasena->clear();
}
