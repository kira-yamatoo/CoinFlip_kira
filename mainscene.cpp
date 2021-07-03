#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QMessageBox>
MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    //主场景
    setFixedSize(320,588);
    setWindowIcon(QIcon(":/res/Coin0008.png"));
    setWindowTitle("主场景");

    connect(ui->actionQuit,&QAction::triggered,[=](){
        this->close();
    });

    connect(ui->actionInfo,&QAction::triggered,[=](){
        QMessageBox::information(this,"关于版本","CoinFlip_kira,Version:0x0001");
    });

    MyPushButton *startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5 -startBtn->width()*0.5,this->height() * 0.7);

    chooselevelscene = new Chooselevelscene();
    connect(startBtn,&QPushButton::clicked,[=](){
        startBtn->zoom(true);
        startBtn->zoom(false);

        QTimer::singleShot(450,this,[=](){
            this->hide();
            chooselevelscene->show();
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

//    pix.load(":/res/Title.png");
//    pix=pix.scaled(pix.width()*0.5,pix.height()*0.5);
//    painter.drawPixmap(10,30,pix);
}
