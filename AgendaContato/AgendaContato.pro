#-------------------------------------------------
#
# Project created by QtCreator 2015-05-18T20:52:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AgendaContato
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Contato.cpp \
    ContatoPersistencia.cpp \
    CRUD.cpp \
    TransformarDados.cpp \
    janela2.cpp \
    Endereco.cpp \
    Telefone.cpp \
    OrdenadorTemplateMethod.cpp \
    OrdenarPorNome.cpp \
    OrdenarPorEndereco.cpp \
    OrdenarPorCepENome.cpp

HEADERS  += mainwindow.h \
    Contato.h \
    ContatoPersistencia.h \
    CRUD.h \
    TransformarDados.h \
    janela2.h \
    Endereco.h \
    Telefone.h \
    OrdenadorTemplateMethod.h \
    OrdenarPorNome.h \
    OrdenarPorEndereco.h \
    OrdenarPorCepENome.h

FORMS    += mainwindow.ui \
    janela2.ui
