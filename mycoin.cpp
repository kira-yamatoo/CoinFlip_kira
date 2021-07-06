#include "mycoin.h"
#include <QDebug>

MyCoin::MyCoin(QString btnImg)
{
    QPixmap pixmap;
    bool flag =pixmap.load(btnImg);
    if(!flag)
    {
        QString str =QString("btnImg load false");
        qDebug()<<str;

        return;
    }

    this->setFixedSize(pixmap.width(),pixmap.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(),pixmap.height()) );

    //绘制翻转金币
    timer =new QTimer(this);
    timer2 =new QTimer(this);
    connect(timer,&QTimer::timeout,[=](){
        QPixmap pixmap;
        QString str;

        str=QString(":/res/Coin000%1.png").arg(this->min++);

        pixmap.load(str);
        this->setFixedSize(pixmap.width(),pixmap.height() );
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(),pixmap.height()));

        if(this->min > this->max)
        {
            this->min=1;
            this->max=8;
            timer->stop();
        }

    });

    connect(timer2,&QTimer::timeout,[=](){
        QPixmap pixmap;
        QString str;

        str=QString(":/res/Coin000%1.png").arg(this->max--);

        pixmap.load(str);
        this->setFixedSize(pixmap.width(),pixmap.height() );
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(),pixmap.height()));

        if(this->min > this->max)
        {
            this->min=1;
            this->max=8;
            timer2->stop();
        }

    });


}

void MyCoin::changeFlag()
{
    if(coinFlag)
    {
        timer->start(30);
    }
    else
    {
        timer2->start(30);
    }
    coinFlag=!coinFlag;

}