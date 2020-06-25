#include "mybutton.h"
#include<QPixmap>
mybutton::mybutton(QString pix):QPushButton(0)
{
    QPixmap pixmap(pix);
    this->setFixedSize(400,200);
    this->setStyleSheet("QPushButton{border:Opx;}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(400,200));
}
