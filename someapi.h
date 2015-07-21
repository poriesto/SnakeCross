#ifndef SOMEAPI_H
#define SOMEAPI_H
#include <QList>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QListWidget>
#include <QRunnable>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QThreadPool>
#include <QList>

typedef struct{
    QString name;
    int score;
}player;

player parsePlayer(QString str);
QList<QString>ReadFromFile(QString filename);
void PutToListWidget(QList<QString>list, QListWidget *widget);
void WriteToFile(QList<QString> list, QString filename);
#endif // SOMEAPI_H
