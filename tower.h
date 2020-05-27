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

    QImage deletetower;
    QImage up;

protected:
    int towerx;
    int towery;




};


class Tower1:public Tower
{
public:
    Tower1(int x=-1000,int y=-1000);
    void drawtower(QPainter painter);
    void t1up();
protected:

private:
    bool wetherup=false;
    friend class Map;
    QImage tower1body;
    QImage tower1up;
    friend class Map;





    void loadimages();
};


class Tower2:public Tower
{
public:
    Tower2(int x=-1000,int y=-1000);
    void drawtower(QPainter painter);
    void t2up();
protected:

private:
    bool wetherup=false;
    friend class Map;
    QImage tower2body;
    QImage tower2up;

    friend class Map;





    void loadimages();
};






#endif // TOWER_H

















