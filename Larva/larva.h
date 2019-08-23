#ifndef LARVA_H
#define LARVA_H

#include <QGraphicsRectItem>
#include <QObject>

class Larva: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Larva();
    ~Larva();
    QTimer * timer;
    void keyPressEvent(QKeyEvent * event);
    void restart();
    int getDeaths();

    int speed_ = 25;


public slots:
    void move();
    void points_spawn();
private:
    int direction_ = 0;
    int points_ = 0;
    int deaths_ = 0;
    const int step_ = 2;
    const int stepHard_ = 5;

};


#endif // LARVA_H
