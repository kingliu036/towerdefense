#ifndef MAP_H
#define MAP_H

#include<QWidget>
#include<QMouseEvent>
#include<QPainter>
#include"tower.h"
#include<QImage>

class Towerpos
{
public:
    Towerpos(int x=-1000,int y=-1000){tx=x;ty=y;}
    void set(int x,int y){tx=x;ty=y;}

    int getX(){return tx;}
    int getY(){return ty;}
private:
    int tx;
    int ty;

};






class Map:public QWidget
{
public:
    Map(QWidget *parent=0);
protected:
    void paintEvent(QPaintEvent *);
    //void timerEvent(QTimerEvent *);
    void mousePressEvent(QMouseEvent *event);
    //void mouseMoveEvent(QMouseEvent *event) ;
    //void mouseReleaseEvent(QMouseEvent *event) ;

private:
    QPixmap map;
    QImage towerchoose;
    Towerpos loc[20];
    int towernum;


    bool inGame;
    bool towerpress;
    bool hastower[20]={false};
    bool clicktower=false;


    void loadImages();
    void initGame();
    void doDrawing();
    void gameOver(QPainter &);

};

#endif // MAP_H
