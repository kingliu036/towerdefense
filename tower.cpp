#include "tower.h"

Tower::Tower(int x,int y)
{
    towerx=x;
    towery=y;
}

void Tower::sett(int x, int y)
{
    towerx=x;
    towery=y;
}



Tower1::Tower1(int x,int y)
{
    towerx=x;
    towery=y;
    loadimages();
}

void Tower1::loadimages()
{
    tower1body.load(":/tower1body.png");
    up.load(":/up.png");
    deletetower.load(":/deletetower.png");
    tower1up.load(":/up1.png");
}

void Tower1::drawtower(QPainter painter)
{
    QRectF r1(towerx,towery,300,300);
    painter.drawImage(r1,tower1body);
}

void Tower1::t1up()
{
    wetherup=true;
}

Tower2::Tower2(int x,int y)
{
    towerx=x;
    towery=y;
    loadimages();
}


void Tower2::loadimages()
{
    tower2body.load(":/tower2body.png");
    up.load(":/up.png");
    deletetower.load(":/deletetower.png");
    tower2up.load(":/up2.png");
}

void Tower2::drawtower(QPainter painter)
{
    QRectF r2(towerx,towery,300,300);
    painter.drawImage(r2,tower2body);
}

void Tower2::t2up()
{
    wetherup=true;
}
















