#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    MyPushButton(QString normalImg,QString pressImg="");
    void zoom(bool flag);

    QString normalImgPath;
    QString pressImgPath;



signals:

};

#endif // MYPUSHBUTTON_H
