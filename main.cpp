#include "mainwindow.h"

#include <QApplication>
#include"map.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Map window;
    window.setWindowTitle("Level 1");
    window.show();
    return a.exec();
}
