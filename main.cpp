#include "mainwindow.h"

#include <QApplication>
#include"map.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    window.setWindowTitle("开始界面");
    window.show();
    return a.exec();
}
