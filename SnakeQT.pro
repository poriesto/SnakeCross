#-------------------------------------------------
#
# Project created by QtCreator 2014-03-06T14:41:20
#
#-------------------------------------------------

QT       += core gui opengl multimedia
LIBS += -lglut -lGLU
#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SnakeQT
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    options.cpp \
    soundbackground.cpp \
    someapi.cpp \
    stat.cpp \
    SnakeGameSource/snakepln.cpp \
    SnakeGameSource/snakegfx.cpp \
    SnakeGameSource/snakegam.cpp \
    SnakeGameSource/snakectl.cpp \
    SnakeGameSource/snakecls.cpp \
    SnakeGameSource/snakecel.cpp \
    SnakeGameSource/oglgfx.cpp \
    SnakeGameSource/kbdctl.cpp \
    SnakeGameSource/congfx.cpp \
    SnakeGameSource/conio.cpp

HEADERS  += mainwindow.h \
    options.h \
    soundbackground.h \
    someapi.h \
    stat.h \
    SnakeGameSource/snake.h \
    SnakeGameSource/oglgfx.h \
    SnakeGameSource/kbdctl.h \
    SnakeGameSource/congfx.h \
    SnakeGameSource/conio.h

FORMS    += mainwindow.ui \
    options.ui \
    stat.ui

RESOURCES +=
