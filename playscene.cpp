#include "playscene.h"
#include <QMenuBar>
#include "mypushbutton.h"
#include <QPainter>
#include <QLabel>
#include <QDebug>
#include "mycoin.h"
#include "dataconfig.h"
#include <QPropertyAnimation>
#include <QSound>

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

    //返回音效
    QSound *backSound= new QSound(":/res/BackButtonSound.wav",this);

    //返回按钮
    MyPushButton *backBtn =new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move((this->width()-backBtn->width()),(this->height()-backBtn->height()));

    connect(backBtn,&QPushButton::clicked,[=](){
        emit this->playSceneBack();
        backSound->play();
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

    //过关图片
    QLabel* winLabel = new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/res/LevelCompletedDialogBg.png");
    winLabel->setGeometry(0,0,tmpPix.width(),tmpPix.height());
    winLabel->setPixmap(tmpPix);
    winLabel->setParent(this);
    winLabel->move( (this->width() - tmpPix.width())*0.5 , -tmpPix.height());

    //过关音效
    QSound *winSound= new QSound(":/res/LevelWinSound.wav",this);

    //翻转金币音效
    QSound *flidSound = new QSound(":/res/ConFlipSound.wav", this);

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
            coinBtn[i][j]=coin;

            connect(coin,&MyCoin::clicked,[=](){
                coin->changeFlag();
                gameArray[i][j]=!gameArray[i][j];

                flidSound->play();

                //延时后 翻转四周金币
                QTimer::singleShot(300,this,[=](){
                    if(coin->pos_x+1< 4)
                    {
                        coinBtn[coin->pos_x+1][coin->pos_y]->changeFlag();
                        gameArray[coin->pos_x+1][coin->pos_y] =!gameArray[coin->pos_x+1][coin->pos_y];
                    }
                    if(coin->pos_x-1>= 0)
                    {
                        coinBtn[coin->pos_x-1][coin->pos_y]->changeFlag();
                        gameArray[coin->pos_x-1][coin->pos_y] =!gameArray[coin->pos_x-1][coin->pos_y];
                    }
                    if(coin->pos_y+1< 4)
                    {
                        coinBtn[coin->pos_x][coin->pos_y+1]->changeFlag();
                        gameArray[coin->pos_x][coin->pos_y+1] =!gameArray[coin->pos_x][coin->pos_y+1];
                    }
                    if(coin->pos_y-1>= 0)
                    {
                        coinBtn[coin->pos_x][coin->pos_y-1]->changeFlag();
                        gameArray[coin->pos_x][coin->pos_y-1] =!gameArray[coin->pos_x][coin->pos_y-1];
                    }

                    isWin=true;
                    for(int i= 0;i<4; i++)
                    {
                        for(int j=0; j<4; j++)
                        {
                            if(coinBtn[i][j]->coinFlag== 0)
                            {
                                isWin=false;
                                break;
                            }
                        }
                    }
                    if(isWin)
                    {
                        winSound->play();

                        QPropertyAnimation * animation1 =  new QPropertyAnimation(winLabel,"geometry");
                        animation1->setDuration(1000);
                        animation1->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));
                        animation1->setEndValue(QRect(winLabel->x(),winLabel->y()+ 150,winLabel->width(),winLabel->height()));
                        animation1->setEasingCurve(QEasingCurve::OutBounce);
                        animation1->start();

                        for(int i= 0;i<4; i++)
                        {
                            for(int j=0; j<4; j++)
                            {
                                coinBtn[i][j]->isWin=true;
                            }
                        }

                    }

                });

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
