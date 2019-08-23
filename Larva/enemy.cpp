#include "enemy.h"
#include <QTimer>
#include <iostream>
#include "game.h"

extern Game * game;

Enemy::Enemy(int d)
{
    setRect(0,0,8,8);
    direction_ = d;

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this, SLOT(move()));
    timer->start(game->larva->speed_);

}

Enemy::~Enemy()
{   }

void Enemy::move(){
    int step;
    if (game->difficult_ >= 2){
        step = stepHard_;
    }
    else {
        step = step_;
    }
    int dir = direction_;

    if (dir == 2){
        setPos(x(),y()-step);
        if(y()<=0){
            setPos(x(),y()+400);
        }
    }
    else if (dir == 3){
        setPos(x()-step,y());
        if(x()<=0){
            setPos(x()+400,y());
        }
    }
    else if (dir == 0){
        setPos(x(),y()+step);
        if(y()>=400){
            setPos(x(),y()-400);
        }
    }
    else if (dir == 1){
        setPos(x()+step,y());
        if(x()>=400){
            setPos(x()-400,y());
        }
    }
}
