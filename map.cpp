#include "map.h"
#include<QPainter>
#include<QTime>
#include<QDebug>
#include<QtCore/qmath.h>
#include"tower.h"
#include"enemy.h"

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
    start.load(":/start.png");
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
        QRectF qstart(1400,0,230,200);
        qp.drawImage(qstart,start);

        for(int i=0;i<20;i++)
        {
            qp.drawRect(loc[i].getX(),loc[i].getY(),300,300);
        }
        if(clicktower==true)
        {
            QRectF towerchoose1(loc[towernum].getX()-150,loc[towernum].getY()-300,600,300);       //没有repaint（），所以显示不出来
            qp.drawImage(towerchoose1,towerchoose);

        }
        for(int i=0;i<20;i++)
        {
            if(hastower[i]==true)
            {
                   if(towertype[i]==1&&t1[i].wetherup==false)
                   {
                        QRectF r1(t1[i].towerx,t1[i].towery,300,300);
                        qp.drawImage(r1,t1[i].tower1body);
                   }
                   else if(towertype[i]==2&&t2[i].wetherup==false)
                   {
                       QRectF r2(t2[i].towerx,t2[i].towery,300,300);
                       qp.drawImage(r2,t2[i].tower2body);
                   }
            }
        }
        if(updown==true)
        {
            if(max[towernum]==false)
            {
                QRectF upp(loc[towernum].getX(),loc[towernum].getY()-300,300,300);
                qp.drawImage(upp,t1[towernum].up);
            }

            QRectF downn(loc[towernum].getX(),loc[towernum].getY()+300,300,300);
            qp.drawImage(downn,t1[towernum].deletetower);
        }
        for(int i=0;i<20;i++)
        {
            if(towerup[i]==true&&towertype[i]==1&&hastower[i]==true)
            {
                QRectF t1upp(loc[i].getX()+50,loc[i].getY()+50,200,200);
                qp.drawImage(t1upp,t1[towernum].tower1up);
            }
            else if(towerup[i]==true&&towertype[i]==2&&hastower[i]==true)
            {
                QRectF t2upp(loc[i].getX()+50,loc[i].getY()+50,200,200);
                qp.drawImage(t2upp,t2[towernum].tower2up);
            }
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
            if(hastower[i]==false)
            {
                towernum=i;
                clicktower=true;
                updown=false;
                hastower[towernum]=false;
                max[towernum]=false;
                towerup[towernum]=false;
            }
            else
            {
                towernum=i;
                updown=true;
            }
        }

    }
    if(clicktower==true&&mx>loc[towernum].getX()-150&&mx<loc[towernum].getX()+150
            &&my>loc[towernum].getY()-300&&my<loc[towernum].getY()&&hastower[towernum]==false)
    {
            hastower[towernum]=true;
            t1[towernum].sett(loc[towernum].getX(),loc[towernum].getY());
            towertype[towernum]=1;
            clicktower=false;
    }
    else if(clicktower==true&&mx>loc[towernum].getX()+150&&mx<loc[towernum].getX()+450
             &&my>loc[towernum].getY()-300&&my<loc[towernum].getY()&&hastower[towernum]==false)
    {
            hastower[towernum]=true;
            t2[towernum].sett(loc[towernum].getX(),loc[towernum].getY());
            towertype[towernum]=2;
            clicktower=false;
    }
    else if(clicktower==false&&updown==true&&(mx<loc[towernum].getX()+300)&&(mx>loc[towernum].getX())
            &&(my<loc[towernum].getY())&&(my>loc[towernum].getY()-300)&&hastower[towernum]==true)
    {
        updown=false;
        max[towernum]=true;
        if(towertype[towernum]==1)
        {
            towerup[towernum]=true;
        }
        else if(towertype[towernum]==2)
        {
            towerup[towernum]=true;
        }
    }
    else if(updown==true&&(mx<loc[towernum].getX()+300)&&(mx>loc[towernum].getX())
            &&(my<loc[towernum].getY()+600)&&(my>loc[towernum].getY()+300))
    {
        updown=false;
        hastower[towernum]=false;
        max[towernum]=false;


    }
    /*else if(towerup[towernum]==true&&mx>loc[towernum].getX()&&mx<loc[towernum].getX()+300
            &&my>loc[towernum].getY()&&my<loc[towernum].getY()+300&&hastower[towernum]==true
            )
    {
        updown=true;

    }*/
    else if((mx<loc[towernum].getX()+300)&&(mx>loc[towernum].getX())
            &&(my<loc[towernum].getY()+600)&&(my>loc[towernum].getY()+300)&&max[towernum]==true)
    {
        updown=false;
        hastower[towernum]=false;
        max[towernum]=false;
        towerup[towernum]=false;
    }
    QWidget::mousePressEvent(event);
}


void Map::mouseReleaseEvent(QMouseEvent *event)
{
    int mx=event->x();
    int my=event->y();
    if(mx>1400&&mx<1630&&my>0&&my<200&&startgame==false)
    {
        startgame=true;
    }
    else if(mx>1400&&mx<1630&&my>0&&my<200&&startgame==true)
    {
        startgame=false;
    }
}



void Map::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);
    repaint();
}








