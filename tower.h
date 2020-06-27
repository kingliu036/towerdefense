#ifndef TOWER_H
#define TOWER_H

#include<QWidget>
#include<QMouseEvent>
#include<QPainter>
#include<QImage>
#include"enemy.h"
#include"bullet3.h"
#include<QList>
class Bullet
{
public:
   Bullet(int x=-100,int y=-100);


   int x=0,y=0;
   double direction;
   QImage bulletImg;
   QImage bulletImg2;
   int getX(){return x;}
   int getY(){return y;}
   void setX(int a){x=a;}
   void setY(int b){y=b;}

};

class Bullet2:public Bullet
{
public:
    void move(double direct);
};




class Tower
{
public:
    Tower(int x=-1000,int y=-1000);
    void sett(int x,int y);
    virtual void upgrade()=0;
    QImage deletetower;
    QImage up;
    int power=300;
    bool checkenemy(enemy1 ee[500],enemy2 ee2[500]);                     //检查攻击范围内是否有敌人
    double getdirection(enemy1 ee[500]);                  //获得敌人的位置
    bool attack=false;
    bool beginattack=false;
    int nowenemy=-1;
    int att(enemy1 ee[500],enemy2 ee2[500]);
    bool slowdown=false;
protected:
    int towerx;
    int towery;
    bool systemup=false;



};


class Tower1:public Tower
{
public:
    Tower1(int x=-1000,int y=-1000);
    void drawtower(QPainter painter);
    void t1up();
    Bullet bt[10];
    void draw(QPainter * painter,enemy1 e1[50]);
    void upgrade();
    int power;
protected:

private:
    bool wetherup=false;
    friend class Map;
    QImage tower1body;
    QImage tower1up;
    friend class Map;





    void loadimages();
};


class Tower2:public Tower,public QWidget
{
public:
    Tower2(int x=-1000,int y=-1000);
    void drawtower(QPainter painter);
    void upgrade();
    void t2up();
    Bullet2 bt2;
    int sendX(enemy1 ee[50]);
    int sendY(enemy1 ee[50]);
    int att(enemy1 ee[50],enemy2 ee2[50]);
    void draw(QPainter * painter);
    void addbullet();
    int power;
protected:

private:
    bool wetherup=false;
    friend class Map;
    QImage tower2body;
    QImage tower2up;

    friend class Map;


    QList<bullet3*>bullet_list;


    void loadimages();
};






#endif // TOWER_H

















