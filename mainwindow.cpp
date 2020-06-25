#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include<QPixmap>
#include<QPaintEvent>
#include<QPushButton>
#include<QDebug>
#include"mybutton.h"
#include"map.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setFixedSize(3000,2000);
    ui->setupUi(this);
    mybutton * but=new mybutton(":/button.png");
    but->setParent(this);
    but->move(1400,1400);
    connect(but,&QPushButton::clicked,this,&MainWindow::close);
    Map * window =new Map;
    connect(but,&QPushButton::clicked,this,[=](){
        this->close();
        window->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    QPixmap pixmap(":/load.jpg");
    painter.drawPixmap(0,0,3000,2000,pixmap);

}
