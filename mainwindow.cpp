#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
   setupUi(this);
   conections();
   argc = 3;
   snd = new SoundBackground;
   snd->start();
}

void MainWindow::sound(){
    label->setText("SoundStart");
    snd->player->play();
}

void MainWindow::killsnd(){
    label->setText("SoundKill");
    snd->player->stop();
}

void MainWindow::startGame(){
    gfx = new oglgfx();
    game = new snakegame(1);
    char *argv[] = {"GLUT_RGB", "-w", "GLUT_RGBA"};
    game->addrand();
    game->addrand();
    game->addrand();
    game->gfx = gfx;
    game->ctls[0] = (snakectl*) gfx;
    game->init();
    gfx->init(argc, argv);
}

void MainWindow::opt(){
    Options *dlg = new Options();
    dlg->show();
}

void MainWindow::stat(){
    Stat *stat = new Stat();
    stat->show();
}
void MainWindow::sometest(){
}
void MainWindow::conections(){
    connect(pushButton, SIGNAL(clicked()), this, SLOT(sound()));
    connect(pushButton_2, SIGNAL(clicked()), this, SLOT(opt()));
    connect(pushButton_4, SIGNAL(clicked()), this, SLOT(killsnd()));
    connect(pushButton_5, SIGNAL(clicked()), this, SLOT(startGame()));
    connect(pushButton_6, SIGNAL(clicked()), this, SLOT(stat()));
}
