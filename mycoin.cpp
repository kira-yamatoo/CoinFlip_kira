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
}
