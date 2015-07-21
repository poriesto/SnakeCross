#include "soundbackground.h"
#include <qglobal.h>

void SoundBackground::run()Q_DECL_OVERRIDE {
    list = ReadFromFile("pl.txt");
    mplaylist = new QMediaPlaylist;
    player = new QMediaPlayer;
    foreach (QString value, list) mplaylist->addMedia( (QUrl::fromLocalFile("/home/poriesto/Music/"+value)) );
    mplaylist->setCurrentIndex(1);
    player->setPlaylist(mplaylist);
    player->setVolume(100);
    player->play();
}
