#include "enemy.h"
#include<QTime>

 enemy::enemy()
{
    x=0;
    y=0;
}
enemy1::enemy1():enemy()
{
    initenemy();
    loadimages();
}
void enemy::move(bool start)                                //控制敌人移动
{
    if(start==true)                                     //start按钮开始后，敌人方可移动
    {
        if(rightDirection==true)                            //以向右移动为例，到达转折点后，改变移动方向，进入下一阶段
        {
            if(x<turnx[period])
            {
                x+=1;
            }
            else if(x>=turnx[period]&&period!=2)
            {
                rightDirection=false;
                upDirection=true;
                period+=1;
            }
            else if(x>=turnx[period]&&period==2)
            {
                rightDirection=false;
                downDirection=true;
                period+=1;
            }
        }
        else if(upDirection==true)
        {
            if(y>=turny[period])
            {
                y-=1;
            }
            else if(y<turny[period])
            {
                upDirection=false;
                rightDirection=true;
                period+=1;
            }
        }
        else if(downDirection==true)
        {
            if(y<turny[period])
            {
                y+=1;
            }
            else if(y>=turny[period])
            {
                downDirection=false;
                rightDirection=true;
            }
        }
        if(period==7)
        {
            upDirection=false;
            rightDirection=true;
        }
    }
}

void enemy::underattack(int a)
{
    if(a==1)
    {
        blood-=200;
    }
    else if(a==2)
    {
        blood-=300;
    }
    if(blood<=0)
    {
        alive=false;
    }
}


void enemy1::loadimages()
{
    enemywalk.load(":/enemy1.gif");
}
void enemy1::initenemy()
{
    x=0;
    y=1100;
    blood=1000;
    blood0=1000;
    rightDirection=true;            //初始方向向右；
    turnx[0]=490;                   //初始化地图中拐点坐标；
    turny[0]=1100;
    turnx[1]=550;
    turny[1]=660;
    turnx[2]=1500;
    turny[2]=700;
    turnx[3]=1500;
    turny[3]=1100;
    turnx[4]=2350;
    turny[4]=1100;
    turnx[5]=2350;
    turny[5]=750;
    turnx[6]=3000;
    turny[6]=750;
}
