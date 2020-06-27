#ifndef BULLET3_H
#define BULLET3_H

#include <QObject>
#include <QPropertyAnimation>
#include <QPoint>
#include <QPixmap>
#include <QPainter>


class bullet3 : public QObject                                                  //用于实现二塔的动画
{
    Q_OBJECT
    Q_PROPERTY(QPoint currentPos READ getCurrentPos WRITE setCurrentPos)
public:
   bullet3(QPoint startPos,QPoint targetPos,QString fileName);
   void draw(QPainter * painter);
   void move();
   QPoint getCurrentPos();
   void setCurrentPos(QPoint pos);
private:
   QPoint startPos;
   QPoint targetPos;
   QPoint currentPos;
   QPixmap pixmap;

signals:

};

#endif // BULLET3_H
