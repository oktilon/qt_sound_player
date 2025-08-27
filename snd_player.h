#ifndef SND_PLAYER_H
#define SND_PLAYER_H

#include <QApplication>
#include <QSound>
#include <QObject>
#include <QString>

class SndPlayer : public QObject
{
    Q_OBJECT

public:
    SndPlayer(QApplication *app, QString *path);
    ~SndPlayer();

public Q_SLOTS:
    void play();

Q_SIGNALS:
    void done();

private:
    QApplication *a;
    QSound *snd;
};

#endif // SND_PLAYER_H