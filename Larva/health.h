#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem{
public:
    Health(QGraphicsItem * parent=0);
    ~Health();
    void decrease();
    void increase();
    int getHealth();
private:
    int health;
};

#endif // HEALTH_H
