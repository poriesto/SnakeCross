#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QApplication>
#include <GL/glut.h>
#include <QWidget>
#include "ui_mainwindow.h"
#include "options.h"
#include "soundbackground.h"
#include "stat.h"
#include "SnakeGameSource/congfx.h"
#include "SnakeGameSource/kbdctl.h"
#include "SnakeGameSource/snake.h"
#include "SnakeGameSource/oglgfx.h"

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
private:
    int argc;
    SoundBackground *snd;
    oglgfx *gfx;
    snakegame* game;
    void conections();
private slots:
    void sound();
    void killsnd();
    void startGame();
    void stat();
    void opt();
    void sometest();
};

#endif // MAINWINDOW_H
