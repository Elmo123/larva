#ifndef ENEMY_H
#define ENEMT_H

#include <QObject>
#include <QGraphicsRectItem>

class Enemy:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Enemy(int d);
    ~Enemy();
public slots:
    void move();

private:
    int direction_ = 0;
    int step_ = 2;
    int stepHard_ = 5;
};

#endif // ENEMY_H
