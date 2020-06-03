#include "tower.h"
#include<QtCore/qmath.h>

Bullet::Bullet(int x,int y)
{
    this->x=x;
    this->y=y;
    bulletImg.load(":/bullet.png");
    bulletImg2.load(":/bullet2.png");                   //加载图片
}

void Bullet2::move(double direct)
{
    x+= (int) (qCos(direct)*2);
    y+= (int) (qSin(direct)*2);
}




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

bool Tower::checkenemy(enemy1 ee[50])
{
    bool a=false;
    for(int i=0;i<50;i++)
    {
        if(ee[i].getX()<towerx+500&&ee[i].getX()>towerx-500&&ee[i].getY()<towery+500&&ee[i].getY()>towery-500)
        {
            a=true;
            break;
        }

    }
    return a;
}
double Tower::getdirection(enemy1 ee[50])                   //计算得到敌人与塔之间的角度
{

    int num=100;
    for(int i=0;i<50;i++)
    {
        if(ee[i].getX()<towerx&&ee[i].getX()>towerx-500&&ee[i].getY()<towery+500&&ee[i].getY()>towery-500)
        {

            num=i;
            if(num==nowenemy)
            {
                beginattack=false;
            }
            else
            {
                beginattack=true;
                nowenemy=num;
            }
            break;
        }
    }
    double direct;
    direct=qAtan((double)(ee[num].getY()+90-towery)/(ee[num].getX()+90-towerx));
    return  direct;
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


int Tower2::sendX(enemy1 ee[50])
{
    if(beginattack==true)
    {
        bt2.setX(towerx);
    }
    else
    {
        bt2.setX(bt2.getX()+(int) (qCos(getdirection(ee)) * 2));
    }
    if(bt2.getX()>ee[nowenemy].getX()&&bt2.getX()<ee[nowenemy].getX()+190)
    {
        bt2.setX(towerx);
    }
    return bt2.getX();
}


int Tower2::sendY(enemy1 *ee)
{
    if(beginattack==true)
    {
        bt2.setY(towery);
    }
    else
    {
        bt2.setY(bt2.getX()+(int)(qSin(getdirection(ee))*2));
    }
    if(bt2.getY()>ee[nowenemy].getY()&&bt2.getY()<ee[nowenemy].getY()+190)
    {
        bt2.setY(towery);
    }
    return  bt2.getY();
}










