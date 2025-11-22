QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    main.cpp \
    controlwindow.cpp

HEADERS += \
    controlwindow.h

FORMS += \
    controlwindow.ui

TARGET = client
TEMPLATE = app
