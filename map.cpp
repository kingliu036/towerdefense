#include "map.h"
#include<QPainter>
#include<QTime>
#include<QDebug>
#include<QtCore/qmath.h>
#include"tower.h"
#include"enemy.h"
#include"playerstatus.h"


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
    cast.load(":/castle.png");
}

void Map::initGame()
{
    castleblood=3;
    loc[0].set(750,950);
    loc[1].set(1070,950);
    loc[2].set(1500,1400);
    loc[3].set(1820,1400);
    loc[4].set(1800,650);
    timerId = startTimer(10);
    timerId2 = startTimer(4000);
    timerId3=startTimer(300);
    timerId4=startTimer(2500);


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
        qp.drawPixmap(0,100,3000,1900,map);                         //通过各种bool型变量控制塔的升级，拆除的画出
        qp.setPen(QPen(Qt::yellow,5,Qt::DashLine) );
        QRectF qstart(1400,0,230,200);
        qp.drawImage(qstart,start);

        for(int i=0;i<20;i++)
        {
            qp.drawRect(loc[i].getX(),loc[i].getY(),300,300);
        }
        if(clicktower==true)
        {
            QRectF towerchoose1(loc[towernum].getX()-150,loc[towernum].getY()-300,600,300);
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
        for(int i=0;i<500;i++)                                       //利用坐标画出敌人
        {
            if(e1[i].alive==true)
            {
                QRectF r1(e1[i].getX(),e1[i].getY(),190,190);
                qp.drawImage(r1,e1[i].enemywalk);
                qp.drawRect(e1[i].getX()+20,e1[i].getY()-50,120,30);
                QBrush brush1;                                                  //利用blood与blood0画出血条
                brush1.setColor(Qt::green);
                brush1.setStyle(Qt::SolidPattern);
                qp.setBrush(brush1);
                qp.drawRect(e1[i].getX()+20,e1[i].getY()-50,120*e1[i].blood/e1[i].blood0,30);
            }
            if(e2[i].alive==true)
            {
                QRectF r2(e2[i].getX(),e2[i].getY(),210,210);
                qp.drawImage(r2,e2[0].enemy22);
                qp.drawRect(e2[i].getX()+20,e2[i].getY()-20,120,30);
                QBrush brush2;                                                  //利用blood与blood0画出血条
                brush2.setColor(Qt::green);
                brush2.setStyle(Qt::SolidPattern);
                qp.setBrush(brush2);
                qp.drawRect(e2[i].getX()+20,e2[i].getY()-20,120*e2[i].blood/e2[i].blood0,30);
            }
            if(e3[i].alive==true)
            {
                QRectF r3(e3[i].getX(),e3[i].getY(),210,210);
                qp.drawImage(r3,e3[0].crazy);
            }


        }

        for(int i=0;i<20;i++)
        {
            if(hastower[i]==true&&t1[i].attack==true)                       //通过translate，rotate和角度画出一塔子弹
            {
                if(t1[i].checkenemy(e1,e2)==true)
                {

                        t1[i].draw(&qp,e1);


                }
            }
            /*else if(hastower[i]==true&&towertype[i]==2)
            {
                QRectF rr(t2[i].sendX(e1),t2[i].sendY(e1),50,50);
                qp.drawImage(rr,t2[i].bt2.bulletImg2);
            }*/
        }
        /*qp.translate(loc[0].getX()+100,loc[0].getY());
        qp.rotate(-45);
        qp.translate(-loc[0].getX()-100,-loc[0].getY());
        QRectF q1(loc[0].getX()+100,loc[0].getY(),300,200);
        qp.drawImage(q1,t1[0].bt[0].bulletImg);*/
        QFont font1("宋体",15,QFont::Bold,true);
        qp.setFont(font1);
        qp.setPen(Qt::black);
        QString ab=QString::number(p1.money);
        QString cd=QString::number(wave);
        qp.drawText(80,50,"MONEY:");
        qp.drawText(200,50,ab);
        qp.drawText(400,50,"WAVE:");
        qp.drawText(500,50,cd);

        t2[0].draw(&qp);
        t2[1].draw(&qp);
        t2[2].draw(&qp);
        t2[3].draw(&qp);
        t2[4].draw(&qp);

        QRectF cas(2500,400,600,600);
        qp.drawImage(cas,cast);


    }
    else                                                            //游戏结束，显示gameover以及撑过的波数；
    {
        QFont font2("宋体",60,QFont::Bold,true);
        qp.setFont(font2);
        qp.setPen(Qt::black);
        qp.drawText(1100,900,"GAME OVER!");
        QFont font3("宋体",20,QFont::Bold,true);
        qp.setFont(font3);
        qp.setPen(Qt::red);
        qp.drawText(1000,1200,"恭喜你成功抵挡了攻击波数：");
        QString ef=QString::number(wave);
        qp.drawText(1800,1200,ef);
    }

}


void Map::mousePressEvent(QMouseEvent *event)
{
    int mx = event->x();                            //获取鼠标点击的位置
    int my = event->y();

    for(int i=0;i<20;i++)                               //通过鼠标点击改变各种bool变量
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
    if(clicktower==true&&mx>loc[towernum].getX()-150&&mx<loc[towernum].getX()+150                       //建造一塔；
            &&my>loc[towernum].getY()-300&&my<loc[towernum].getY()&&hastower[towernum]==false)
    {
        if(p1.money>=300)
        {
            hastower[towernum]=true;
            t1[towernum].sett(loc[towernum].getX(),loc[towernum].getY());
            towertype[towernum]=1;
            clicktower=false;
            p1.money-=300;
        }


    }
    else if(clicktower==true&&mx>loc[towernum].getX()+150&&mx<loc[towernum].getX()+450
             &&my>loc[towernum].getY()-300&&my<loc[towernum].getY()&&hastower[towernum]==false)          //建造二塔；
    {
        if(p1.money>=250)
        {
            hastower[towernum]=true;
            t2[towernum].sett(loc[towernum].getX(),loc[towernum].getY());
            towertype[towernum]=2;
            clicktower=false;
            p1.money-=250;
        }

    }
    else if(clicktower==false&&updown==true&&(mx<loc[towernum].getX()+300)&&(mx>loc[towernum].getX())       //升级已有塔；
            &&(my<loc[towernum].getY())&&(my>loc[towernum].getY()-300)&&hastower[towernum]==true)
    {
        updown=false;
        max[towernum]=true;
        if(towertype[towernum]==1)
        {
            towerup[towernum]=true;
            p1.money-=270;
            t1[towernum].upgrade();
        }
        else if(towertype[towernum]==2)
        {
            towerup[towernum]=true;
            p1.money-=270;
            t2[towernum].upgrade();
        }
    }
    else if(updown==true&&(mx<loc[towernum].getX()+300)&&(mx>loc[towernum].getX())                  //拆塔；
            &&(my<loc[towernum].getY()+600)&&(my>loc[towernum].getY()+300))
    {
        updown=false;
        hastower[towernum]=false;
        max[towernum]=false;
        p1.money+=125;

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
        p1.money+=125;
    }
    QWidget::mousePressEvent(event);
}


void Map::mouseReleaseEvent(QMouseEvent *event)                     //控制的是start按钮
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
    int id = e->timerId();
    if(id==timerId)
    {
        if(castleblood==0)
        {
            inGame=false;
        }
        for(int i=0;i<500;i++)
        {
            e1[i].move(startgame);              //隔较短时间更新敌人移动数据
            e2[i].move(startgame);
            e3[i].move(startgame);
        }
        hurt();
    }

    else if(id==timerId3)                   //一塔子弹显示暂留控制
    {
        for(int i=0;i<20;i++)
        {
            t1[i].attack=false;
        }
    }
    else if(id==timerId2)                       //一塔子弹冷却结束，发射
    {
        for(int i=0;i<20;i++)
        {
            if(hastower[i]==true&&towertype[i]==1)
            {
                t1[i].attack=true;
                p1.money+=t1[i].att(e1,e2);
            }
        }
    }
    else if(id==timerId4)
    {
        for(int i=0;i<20;i++)
        {
            if(hastower[i]==true&&towertype[i]==2)
            {
                p1.money+=t2[i].att(e1,e2,e3);
            }
        }
        setWave();
    }
    repaint();
}

void Map::hurt()
{
    for(int i=0;i<500;i++)
    {
        if(e1[i].alive==true&&e1[i].getX()>=2300&&e1[i].getY()<780)
        {
            castleblood-=1;
            e1[i].alive=false;
        }
        if(e2[i].alive==true&&e2[i].getX()>=2300&&e2[i].getY()<780)
        {
            castleblood-=1;
            e2[i].alive=false;
        }
        if(e3[i].alive==true&&e3[i].getX()>=2300&&e3[i].getY()<780)
        {
            castleblood-=1;
            e3[i].alive=false;
        }
    }
}

void Map::setWave()
{
    QTime t;
    t=QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);
    int n=qrand();
    if(n%2==1)
    {
        totalenemy++;
        current1++;
        e1[current1].setX(0);
        e1[current1].blood0=e1[current1].blood+=wave*80;
    }
    else if(n%2==0)
    {
        totalenemy++;
        current2++;
        e2[current2].setX(0);
        e2[current2].blood0=e2[current2].blood+=wave*80;
    }
    if(n%5==1)
    {
        totalenemy++;
        current3++;
        e3[current3].setX(0);

    }
    if(totalenemy==wave*10+10)
    {
        wave++;
    }
}



