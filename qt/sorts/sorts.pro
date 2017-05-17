QT += core
QT -= gui

CONFIG += c++11

TARGET = sorts
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    sortclass.cpp \
    mergesort.cpp \
    quicksort.cpp \
    pyramidalsort.cpp

HEADERS += \
    sortclass.h \
    mergesort.h \
    quicksort.h \
    pyramidalsort.h
