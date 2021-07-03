#include "mypushbutton.h"
#include <QDebug>
#include <QPropertyAnimation>
MyPushButton::MyPushButton(QString normalImg,QString pressImg)
{
    this->normalImgPath= normalImg;
    this->pressImgPath= pressImg;

    QPixmap pixmap;

    bool flag= pixmap.load(normalImg);

    if(!flag)
    {
        qDebug()<< "MyPushButton:image load fall";
        return;
    }
    this->setFixedSize(pixmap.width(),pixmap.height());
    this->setStyleSheet("QPushButton{Border:0px}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));

}

void MyPushButton::zoom(bool flag)
{
    int tmp=10;

    QPropertyAnimation * animation= new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);
    if(flag)
    {
        tmp=!tmp;
        animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
        animation->setEndValue(QRect(this->x(),this->y()+tmp,this->width(),this->height()));
    }
    else
    {
        animation->setStartValue(QRect(this->x(),this->y()+tmp,this->width(),this->height()));
        animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    }
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();

}
