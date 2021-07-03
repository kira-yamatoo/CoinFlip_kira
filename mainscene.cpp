#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
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
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    pix.load(":/res/Title.png");
    pix=pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(10,30,pix);
}
