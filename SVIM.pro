QT += core widgets
QT -= gui

CONFIG += c++11

TARGET = SVIM
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    imagen.cpp \
    pixel.cpp \
    archivo.cpp \
    archivomif.cpp \
    interfazconsola.cpp \
    sistema.cpp \
    graficador.cpp \
    procesamiento.cpp \
    filtrocolor.cpp \
    structdet.cpp \
    metadatos.cpp \
    pixelado.cpp \
    archivoppm.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    imagen.h \
    pixel.h \
    archivo.h \
    archivomif.h \
    interfazconsola.h \
    sistema.h \
    graficador.h \
    procesamiento.h \
    filtrocolor.h \
    structdet.h \
    metadatos.h \
    pixelado.h \
    archivoppm.h
