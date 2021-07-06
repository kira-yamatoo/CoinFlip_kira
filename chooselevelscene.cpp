#include "chooselevelscene.h"
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QLabel>
#include <QDebug>
#include "playscene.h"
ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowTitle("关卡选择");
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
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
        emit this->chooseSceneBack();
    });

    //绘制关卡选择按钮
    for(int i=0; i<20; i++)
    {
        MyPushButton *levelBtn =new MyPushButton(":/res/LevelIcon.png");
        levelBtn->setParent(this);
        levelBtn->move(25 + i%4 *70, 130 + i/4*70);

        connect(levelBtn,&QPushButton::clicked,[=](){
            playScene =new PlayScene(i);
            playScene->show();
            this->hide();

            //关卡选择场景返回至主场景
            connect(playScene,&PlayScene::playSceneBack,[=](){
                QTimer::singleShot(300,this,[=](){
                    this->show();
                    delete playScene;
                    playScene =NULL;
                });
            });
        });

        //绘制标签
        QLabel *label = new QLabel();
        label->setParent(this);
        label->setFixedSize(levelBtn->width(),levelBtn->height());
        label->setText(QString::number(i +1));
        label->move(25 + i%4 *70, 130 + i/4*70);
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        //设置穿透鼠标事件
        label->setAttribute(Qt::WA_TransparentForMouseEvents);

    }

}

void ChooseLevelScene::paintEvent(QPaintEvent*)
{
    //绘制背景 以及logo
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width()-pix.width())*0.5,30,pix.width(),pix.height(),pix);

}
