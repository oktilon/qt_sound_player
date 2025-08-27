#include <unistd.h>

#include "snd_player.h"

SndPlayer::SndPlayer(QApplication *app, QString *path) {
    a = app;
    snd = new QSound(*path);
}

SndPlayer::~SndPlayer() {
    delete snd;
}

void SndPlayer::play() {
    snd->play();
    while (!snd->isFinished()) {
        usleep(10000);
    }
    Q_EMIT done();
    a->exit(0);
}