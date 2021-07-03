#include "chooselevelscene.h"
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
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


    //返回按钮
    MyPushButton *backBtn =new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move((this->width()-backBtn->width()),(this->height()-backBtn->height()));

    connect(backBtn,&QPushButton::clicked,[=](){
        QTimer::singleShot(300,this,[=](){
            this->hide();

        });

    });

}

void Chooselevelscene::paintEvent(QPaintEvent*)
{
    //绘制背景 以及logo
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width()-pix.width())*0.5,30,pix.width(),pix.height(),pix);

}
