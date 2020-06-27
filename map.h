#ifndef MAP_H
#define MAP_H

#include<QWidget>
#include<QMouseEvent>
#include<QPainter>
#include"tower.h"
#include"enemy.h"
#include<QImage>
#include"playerstatus.h"
#include"bullet3.h"

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
    void addbullet3();
    void setWave();


protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void mousePressEvent(QMouseEvent *event);
    //void mouseMoveEvent(QMouseEvent *event) ;
    void mouseReleaseEvent(QMouseEvent *event) ;
    void hurt();


private:
    QPixmap map;
    QImage towerchoose;
    QImage start;
    QImage cast;
    Towerpos loc[20];
    int towernum;

    Tower1 t1[10];
    Tower2 t2[10];
    int towertype[20]={0};
    int wave=0;
    int castleblood;
    enemy1 e1[500];
    enemy2 e2[500];
    playerstatus p1;
    int totalenemy=0;
    int current1=0;
    int current2=0;


    int timerId;
    int timerId2;
    int timerId3;
    int timerId4;

    bool inGame;
    bool towerpress;
    bool hastower[20]={false};
    bool clicktower=false;
    bool updown=false;
    bool towerup[20]={false};
    bool max[20]={false};
    bool startgame=false;





    void loadImages();
    void initGame();
    void doDrawing();
    void gameOver(QPainter &);

};

#endif // MAP_H
