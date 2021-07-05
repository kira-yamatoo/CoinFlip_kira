#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    PlayScene(int levelNum);
    void paintEvent(QPaintEvent*);

    int levelIndex;

signals:
    void playSceneBack();

};

#endif // PLAYSCENE_H
