#include "map.h"
#include<QPainter>
#include<QTime>
#include<QDebug>
#include<QtCore/qmath.h>
#include"tower.h"


Map::Map(QWidget * parent):QWidget(parent)
{
    inGame=true;


    resize(3000,2000);
    loadImages();
    initGame();
}



void Map::loadImages()
{
    map.load(":/timg[7].png");
    towerchoose.load(":/choosetower.png");
}

void Map::initGame()
{
    loc[0].set(750,950);
    loc[1].set(1070,950);
    loc[2].set(1500,1400);
    loc[3].set(1820,1400);
    loc[4].set(1800,650);
    timerId = startTimer(10);
}

void Map::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    doDrawing();
}

void Map::doDrawing()
{
    QPainter qp(this);
    if(inGame)
    {
        qp.drawPixmap(0,100,3000,1900,map);
        qp.setPen(QPen(Qt::yellow,5,Qt::DashLine) );

        for(int i=0;i<20;i++)
        {
            qp.drawRect(loc[i].getX(),loc[i].getY(),300,300);
        }
        if(clicktower==true)
        {
            QRectF towerchoose1(loc[towernum].getX()-150,loc[towernum].getY()-300,600,300);       //没有repaint（），所以显示不出来
            qp.drawImage(towerchoose1,towerchoose);
        }




    }

}


void Map::mousePressEvent(QMouseEvent *event)
{
    int mx = event->x();                            //获取鼠标点击的位置
    int my = event->y();
    for(int i=0;i<20;i++)
    {

        if((mx>loc[i].getX())&&(mx<loc[i].getX()+300)&&(my>loc[i].getY())&&(my<loc[i].getY()+300))
        {
            towernum=i;
            clicktower=true;
        }

    }
    if(clicktower==true&&mx>loc[towernum].getX()-150&&mx<loc[towernum].getX()+150
            &&my>loc[towernum].getY()-300&&my<loc[towernum].getY())
    {

           t1.sett(loc[towernum].getX(),loc[towernum].getY());
    }
    else if(clicktower==true&&mx>loc[towernum].getX()+150&&mx<loc[towernum].getX()+450
             &&my>loc[towernum].getY()-300&&my<loc[towernum].getY())
    {
            t2.sett(loc[towernum].getX(),loc[towernum].getY());
    }

    QWidget::mousePressEvent(event);
}


void Map::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);
    repaint();
}








