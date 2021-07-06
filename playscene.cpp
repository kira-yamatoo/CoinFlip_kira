#include "playscene.h"
#include <QMenuBar>
#include "mypushbutton.h"
#include <QPainter>
#include <QLabel>
#include <QDebug>
#include "mycoin.h"
#include "dataconfig.h"

PlayScene::PlayScene(int levelNum)
{
    this->levelIndex = levelNum;
    this->setWindowTitle(QString("Level: %1").arg(levelIndex +1));
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
    QString levelStr =QString("Level:%1").arg(this->levelIndex +1);
    levelLabel->setText(levelStr);
    levelLabel->setGeometry(30,this->height()-50, 150,50);

    QFont levelFont;
    levelFont.setFamily("华文新魏");
    levelFont.setPointSize(20);
    levelLabel->setFont(levelFont);

    //初始化关卡二位数组
    DataConfig dataConfig;
    for(int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            gameArray[i][j]=dataConfig.mData[levelIndex][i][j];
        }
    }

    //绘制表格
    for(int i=0;i<4; i++)
    {
        for(int j=0; j<4;j++)
        {
            //绘制金币背景
            QPixmap pixmap= QPixmap(":/res/BoardNode.png");
            QLabel *label= new QLabel(this);
            label->setGeometry(0,0, pixmap.width(),pixmap.height());
            label->setPixmap(pixmap);
            label->move(60+ i*50 , 200+j*50);

            //绘制金币  1金币 0银币
            QString imgPath= ":/res/Coin0001.png";
            if(gameArray[i][j]==0)
            {
                imgPath= ":/res/Coin0008.png";
            }
            MyCoin *coin =new MyCoin(imgPath);
            coin->setParent(this);
            coin->move(2+ 60+ i*50 , 2+ 200+j*50);
            coin->pos_x= i;
            coin->pos_y= j;
            coin->coinFlag=gameArray[i][j];

            connect(coin,&MyCoin::clicked,[=](){
                coin->changeFlag();
//                gameArray[i][j]=!gameArray[i][j];

            });

        }
    }

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
