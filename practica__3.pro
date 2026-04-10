TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Encriptacion_y_desencriptacion.cpp \
        LZ78.cpp \
        RLE.cpp \
        main.cpp

HEADERS += \
    librerias.h
