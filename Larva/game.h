#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "larva.h"
#include "score.h"
#include "health.h"
#include <QTimer>

#include <QObject>

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget * parent=0);
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    void drawMenu(int x, int y, int width, double opacity);
    void options();
    void gameOver(int score_);
    void createLarva();
    int getHighScore();
    void writeHighScore(int score);
    void difficulty(int x, int y, int width, double opacity);

    ~Game();

    QGraphicsScene * scene;
    Larva * larva;
    Score * score;
    Health * health;

    bool enter_ = false;
    int option_ = 0;
    int difficult_ = 2;
    int speedo_ = 10;

public slots:
    void timerA();

private:
    QTimer * timer_;
    QGraphicsRectItem * panel_;
    int highscore_ = 0;
};

#endif // GAME_H
