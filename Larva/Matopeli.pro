QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Matopeli
TEMPLATE = app


SOURCES += main.cpp \
    score.cpp \
    game.cpp \
    health.cpp \
    enemy.cpp \
    point.cpp \
    larva.cpp

HEADERS  += \
    score.h \
    game.h \
    health.h \
    enemy.h \
    point.h \
    larva.h

RESOURCES +=
