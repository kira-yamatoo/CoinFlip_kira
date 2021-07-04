#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>

class Chooselevelscene : public QMainWindow
{
    Q_OBJECT
public:
    explicit Chooselevelscene(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);

signals:
    void chooseSceneBack();

};

#endif // CHOOSELEVELSCENE_H
