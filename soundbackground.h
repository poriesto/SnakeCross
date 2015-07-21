#ifndef SOUNDBACKGROUND_H
#define SOUNDBACKGROUND_H
#include <QtCore>
#include "someapi.h"
class SoundBackground:public QThread
{
private:
    QList<QString>list;
    QMediaPlaylist *mplaylist;
public:
    QMediaPlayer *player;
    void run();
};

#endif // SOUNDBACKGROUND_H
