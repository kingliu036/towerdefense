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
    void move(bool start);
    void setX1(int a){x=-1000*a;}
    void setX2(int a){x=-1000*a-500;}

    int underattack(int a);
    int getX(){return x;}
    int getY(){return y;}
    int blood;
    bool alive=true;
protected:
    void loadimages();
    void initenemy();                          //初始化敌人
    int x;
    int y;
    int period=0;

    bool rightDirection=false;
    bool leftDirection=false;
    bool upDirection=false;
    bool downDirection=false;
};

class enemy1:public enemy
{
public:
    enemy1();
    int blood0;
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



#endif // ENEMY_H
