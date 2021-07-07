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
    void mousePressEvent(QMouseEvent *e);

    int pos_x;
    int pos_y;
    bool coinFlag;
    bool isAnimation= false;
    int min=1;
    int max=8;
    bool isWin=false;

    QTimer *timer;
    QTimer *timer2;


signals:

};

#endif // MYCOIN_H
