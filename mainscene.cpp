#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QMessageBox>
#include <QSound>
MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    //主场景
    setFixedSize(320,588);
    setWindowIcon(QIcon(":/res/Coin0008.png"));
    setWindowTitle("主场景");

    //菜单栏 关闭
    connect(ui->actionQuit,&QAction::triggered,[=](){
        this->close();
    });

    //菜单 关于
    connect(ui->actionInfo,&QAction::triggered,[=](){
        QMessageBox::information(this,"关于版本","CoinFlip_kira,Version:0x0001");
    });

    //添加音效
    QSound *startSound =new QSound(":/res/ConFlipSound.wav",this);

    //开始按钮
    MyPushButton *startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5 -startBtn->width()*0.5,this->height() * 0.7);

    //开始按钮动画
    connect(startBtn,&QPushButton::clicked,[=](){
        startBtn->zoom(true);
        startBtn->zoom(false);

        startSound->play();

        //进入关卡选择场景
        QTimer::singleShot(450,this,[=](){
            this->hide();
            chooseLevelScene->setGeometry(this->geometry());
            chooseLevelScene->show();
        });


    });

    chooseLevelScene = new ChooseLevelScene();

    //关卡选择场景返回至主场景
    connect(chooseLevelScene,&ChooseLevelScene::chooseSceneBack,[=](){
        QTimer::singleShot(300,this,[=](){
             chooseLevelScene->hide();
             this->setGeometry(chooseLevelScene->geometry());
             this->show();
        });
    });
}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::paintEvent(QPaintEvent *)
{
    //绘制主场景背景图
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/MenuSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}
