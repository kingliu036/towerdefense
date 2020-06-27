#ifndef ENEMY_H
#define ENEMY_H

#include<QWidget>
#include<QMouseEvent>
#include<QPainter>
#include<QImage>
class enemy
{
public:
    enemy();
    int turnx[8];                               //地图中转折点的x,y坐标；
    int turny[8];
    void move(bool start);                      //敌人移动函数；

    void setX(int a){x=a;}

    int underattack(int a);                     //敌人受击函数；
    int getX(){return x;}
    int getY(){return y;}
    int blood;                                  //敌人血量；
    bool alive=true;                            //敌人是否被消灭
    int speed=2;                                //敌人移动速度；
protected:
    void loadimages();
    void initenemy();                          //初始化敌人
    int x;
    int y;
    int period=0;                               //敌人移动阶段，与转向有关

    bool rightDirection=false;
    bool leftDirection=false;
    bool upDirection=false;
    bool downDirection=false;
};

class enemy1:public enemy
{
public:
    enemy1();
    int blood0;                         //总血量
    QImage enemywalk;
private:

    void loadimages();
    void initenemy();

};

class enemy2:public enemy
{
public:
    enemy2();
    int blood0;
    QImage enemy22;
private:
    void loadimages();
    void initenemy();

};

class enemy3:public enemy
{
public:
    enemy3();
    int blood0;
    QImage crazy;
private:
    void loadimages();
    void initenemy();
};

#endif // ENEMY_H
