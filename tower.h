#ifndef TOWER_H
#define TOWER_H

#include<QWidget>
#include<QMouseEvent>
#include<QPainter>
#include<QImage>

class Tower
{
public:
    Tower(int x=-1000,int y=-1000);
    void sett(int x,int y);



protected:
    int towerx;
    int towery;

};


class Tower1:public Tower
{
public:
    Tower1(int x=-1000,int y=-1000);
};


class Tower2:public Tower
{
public:
    Tower2(int x=-1000,int y=-1000);
};

#endif // TOWER_H
