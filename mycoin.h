#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include <QTimer>
class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    MyCoin(QString btnImg);

    void changeFlag();

    int pos_x;
    int pos_y;
    bool coinFlag;
    int min=1;
    int max=8;

    QTimer *timer;
    QTimer *timer2;



signals:

};

#endif // MYCOIN_H
