#include "playscene.h"
#include <QMenuBar>
#include "mypushbutton.h"
#include <QPainter>
#include <QLabel>
#include <QDebug>

PlayScene::PlayScene(int levelNum)
{
    this->levelIndex = levelNum;
    this->setWindowTitle(QString("Level: %1").arg(levelIndex));
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
        emit this->playSceneBack();
    });

    //关卡标签
    QLabel *levelLabel= new QLabel();
    levelLabel->setParent(this);
    QString levelStr =QString("Level:%1").arg(this->levelIndex);
    levelLabel->setText(levelStr);
    levelLabel->setGeometry(30,this->height()-50, 150,50);

    QFont levelFont;
    levelFont.setFamily("华文新魏");
    levelFont.setPointSize(20);
    levelLabel->setFont(levelFont);

}

void PlayScene::paintEvent(QPaintEvent*)
{
    //绘制背景 以及logo
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width()-pix.width())*0.5,30,pix.width(),pix.height(),pix);

}
