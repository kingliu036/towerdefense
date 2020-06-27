#include "bullet3.h"

bullet3::bullet3(QPoint startPos,QPoint targetPos,QString fileName):QObject(0),pixmap(fileName)
{
    this->currentPos=startPos;
    this->startPos=startPos;
    this->targetPos=targetPos;

}

void bullet3::draw(QPainter *painter)
{
    if(currentPos!=targetPos)
    painter->drawPixmap(currentPos,pixmap);
}

void bullet3::move()
{
    QPropertyAnimation * animation =new QPropertyAnimation(this,"currentPos");
    animation->setDuration(300);
    animation->setStartValue(startPos);
    animation->setEndValue(targetPos);
    animation->start();
}

QPoint bullet3::getCurrentPos()
{
    return currentPos;
}

void bullet3::setCurrentPos(QPoint pos)
{
    currentPos=pos;
}
