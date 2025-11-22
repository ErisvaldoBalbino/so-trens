QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG  += c++17

SOURCES += main.cpp \
    networkhandler.cpp \
    mainwindow.cpp \
    trem.cpp

HEADERS  += \
    networkhandler.h \
    mainwindow.h \
    trem.h

FORMS    += \
    mainwindow.ui

TARGET = server
TEMPLATE = app

LIBS += -pthread
