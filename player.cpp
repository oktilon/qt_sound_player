#include <QApplication>
#include <QDateTime>
#include <QSound>
#include <QObject>
#include <QFile>
#include <QFileInfo>
#include <QThread>

#include <unistd.h>

#include "snd_player.h"

//================================================================================================================================================================================
/**
 * @brief Main function, entry point of the application
 * @param argc An integer argument count of the command line arguments
 * @param argv A list of the command line arguments
 * @return an integer exit status of application
 */
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Sound path is required argument!\n");
        return 1;
    }
    QString path(argv[1]);
    QFile f(path);
    if (!QFileInfo::exists(path)) {
        printf("Can't access file: %s\n", path.toStdString().c_str());
        return 1;
    }
    printf("Play %s\n", argv[1]);
    QApplication app(argc, argv);

    SndPlayer *p = new SndPlayer(&app, &path);
    QThread *th = new QThread();
    p->moveToThread(th);

    QObject::connect(th, SIGNAL(started()), p, SLOT(play()));
    QObject::connect(p, SIGNAL(done()), th, SLOT(quit()));

    th->start();
    return app.exec();
}
//================================================================================================================================================================================
