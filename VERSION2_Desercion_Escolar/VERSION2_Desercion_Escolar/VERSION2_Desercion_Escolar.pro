QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    alta_de_alumnos.cpp \
    baja_de_alumnos.cpp \
    inicio_de_sesion.cpp \
    listado_de_alumnos.cpp \
    main.cpp \
    menu_herramientas.cpp \
    modificacion_de_alumnos.cpp \
    olvide_mi_contrasena.cpp \
    pantalla_inicio.cpp \
    posibles_abandonantes.cpp \
    registro_de_asistencias.cpp \
    resumen_de_asis_y_faltas.cpp \
    reuniones.cpp

HEADERS += \
    alta_de_alumnos.h \
    baja_de_alumnos.h \
    inicio_de_sesion.h \
    listado_de_alumnos.h \
    menu_herramientas.h \
    modificacion_de_alumnos.h \
    olvide_mi_contrasena.h \
    pantalla_inicio.h \
    posibles_abandonantes.h \
    registro_de_asistencias.h \
    resumen_de_asis_y_faltas.h \
    reuniones.h \
    sesionusuario.h

FORMS += \
    alta_de_alumnos.ui \
    baja_de_alumnos.ui \
    inicio_de_sesion.ui \
    listado_de_alumnos.ui \
    menu_herramientas.ui \
    modificacion_de_alumnos.ui \
    olvide_mi_contrasena.ui \
    pantalla_inicio.ui \
    posibles_abandonantes.ui \
    registro_de_asistencias.ui \
    resumen_de_asis_y_faltas.ui \
    reuniones.ui

TRANSLATIONS += \
    VERSION2_Desercion_Escolar_es_AR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    IMAGENES.qrc
