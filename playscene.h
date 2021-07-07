#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include "mycoin.h"

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    PlayScene(int levelNum);
    void paintEvent(QPaintEvent*);

    int levelIndex;
    int gameArray[4][4];
    MyCoin *coinBtn[4][4];


signals:
    void playSceneBack();

};

#endif // PLAYSCENE_H
