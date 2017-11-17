#-------------------------------------------------
#
# Project created by QtCreator 2017-11-11T00:38:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH+=C:/opencv/build/include/opencv \
                    C:/opencv/build/include/opencv2 \
                   C:/opencv/build/include
LIBS+=C:\opencv\build\x64\vc14\lib\opencv_world310.lib
LIBS+=C:\opencv\build\x64\vc14\lib\opencv_world310d.lib

QMAKE_LFLAGS += -static
