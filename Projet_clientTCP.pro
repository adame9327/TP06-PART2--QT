QT += core network
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app
TARGET = Projet_ClientTCP

SOURCES += main.cpp \
           client.cpp

HEADERS += client.h
