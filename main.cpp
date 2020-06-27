#include "mainwindow.h"

#include <QApplication>
#include"map.h"
#include<QMediaPlayer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/hdl.mp3"));
    player->setVolume(30);
    player->play();
    MainWindow window;
    window.setWindowTitle("开始界面");
    window.show();
    return a.exec();
}
