#include "chooselevelscene.h"
#include <QMenuBar>
#include <QPainter>
Chooselevelscene::Chooselevelscene(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowTitle("关卡选择");
    this->setWindowIcon(QIcon(":/res/Coin001.png"));
    this->setFixedSize(320,588);

    QMenuBar *menubar = new QMenuBar(this);
    setMenuBar(menubar);
    QMenu *menu= menubar->addMenu("开始");
    QAction *quitAction =menu->addAction("退出");

    connect(quitAction,&QAction::triggered,[=](){
        this->close();
    });

}

void Chooselevelscene::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    pix.load(":/res/Title.png");
    pix=pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(10,30,pix);

}
