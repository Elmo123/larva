#include "Larva.h"
#include <QKeyEvent>
#include "enemy.h"
#include <QGraphicsScene>
#include "point.h"
#include "score.h"
#include "game.h"
#include "health.h"

#include <QTimer>
#include <iostream>

#include <QList>
#include <QApplication>

extern Game * game;

Larva::Larva()
{
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this, SLOT(move()));
    timer->start(speed_);
}

Larva::~Larva()
{   }


void Larva::keyPressEvent(QKeyEvent *event)
{

    //Direction keys
    if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W){
        if (game->option_ != -300 && game->option_ != -299){
            if (game->option_ > 0){
                game->option_--;
                game->drawMenu(0,0,150,1);
            }
            else if (game->option_ == 0){
                game->option_ = 3;
                game->drawMenu(0,0,150,1);
            }
            else {
                std::cout << "Error, returning default option_";
                game->option_ = 0;
            }
        }
        else
            direction_ = 0;
    }
    else if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S){
        if (game->option_ != -300 && game->option_ != -299){
            if (game->option_ < 3){
                game->option_++;
                game->drawMenu(0,0,150,1);
            }
            else if (game->option_ == 3){
                game->option_ = 0;
                game->drawMenu(0,0,150,1);
            }
            else {
                std::cout << "Error, returning default option_";
                game->option_ = 0;
            }
        }
        else
            direction_ = 2;
    }
    else if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A){
        if (game->option_ < 0){
            direction_ = 1;
        }
    }
    else if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D){
        if (game->option_ < 0){
            direction_ = 3;
        }
    }

    // Enter key and Escape Key
    else if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter){
        //starts the game
        if (game->option_ == 0){
            game->enter_ = true;
            // to stop changing option_ after game has started
            game->option_ = -300;

        }
        // sets difficulty
        else if(game->option_ == 1){
            game->difficult_++;
            if (game->difficult_ >= 4){
                game->difficult_ = 0;
            }
            game->difficulty(0,0,150,1);
            speed_ = game->speedo_;
        }
        // gets highscore
        else if(game->option_ == 2){
            int highscore = game->getHighScore();
            QGraphicsTextItem* txt = new QGraphicsTextItem("Highscore: " + QString::number(highscore));
            txt->setPos(0,120);
            scene()->addItem(txt);
        }
        //closes the game
        else if (game->option_ == 3){
            scene()->clear();
            game->close();
            QApplication::quit();
        }
        else if (game->option_ == -299){
            restart();
        }
        else
            std::cout << "Invalid option!" << std::endl << "Syntax Error" << std::endl;
    }
    else if (game->option_ != -300 && game->option_ != -299){
        // PASS
    }
    else if (event->key() == Qt::Key_Escape){
        restart();
    }
}


void Larva::move(){
    int step = step_;
    if (game->difficult_ >= 2){
        step = stepHard_;
    }
    if (direction_ == 0){
        setPos(x(),y()-step);
        if(y()<=-5){
            setPos(x(),y()+395);
        }
    }
    else if (direction_ == 1){
        setPos(x()-step,y());
        if(x()<=-5){
            setPos(x()+395,y());
        }
    }
    else if (direction_ == 2){
        setPos(x(),y()+step);
        if(y()>=395){
            setPos(x(),y()-400);
        }
    }
    else if (direction_ == 3){
        setPos(x()+step,y());
        if(x()>=395){
            setPos(x()-400,y());
        }
    }
    else {
        direction_ = 0;
    }

    QList<QGraphicsItem *> colliding_items = collidingItems();

    for(int i = 0, n = colliding_items.size(); i < n; ++i){
       if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            deaths_++;
            std::cout << "Crashed" << std::endl << "Total crashes: " << deaths_ << std::endl;
            delete colliding_items[i];
            game->health->decrease();
            if (game->health->getHealth() <= 0){
                game->gameOver(points_);
            }
            return;
            }
       if (typeid(*(colliding_items[i])) == typeid(Point)){
            points_++;
            std::cout << "Points: " << points_ << std::endl;
            delete colliding_items[i];
            Larva::points_spawn();
            game->score->increase();
            if (points_%3 == 0){
                game->health->increase();
            }
       }
    }
}

void Larva::points_spawn()
{
    // create point
    Point * point = new Point();
    point->setBrush(* new QBrush(Qt::green));
    scene()->addItem(point);

    // create enemy
    Enemy * enemy = new Enemy(direction_);
    enemy->setBrush(* new QBrush(Qt::gray));
    if (direction_ == 0){
        enemy->setPos(x()+1,y()+11);
    }
    else if (direction_ == 1){
        enemy->setPos(x()+11,y()+1);
    }
    else if (direction_ == 2){
        enemy->setPos(x()+1,y()-9);
    }
    else if (direction_ == 3){
        enemy->setPos(x()-9,y()+1);
    }
    scene()->addItem(enemy);

}

void Larva::restart(){
    timer->stop();
    game->close();
    delete game;
    game = new Game();
    game->show();
}

int Larva::getDeaths()
{
    return deaths_;
}
