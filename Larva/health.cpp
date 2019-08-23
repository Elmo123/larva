#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    health = 1;

    // draw the text
    setPlainText(QString("HP: ") + QString::number(health));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",10,QFont::Bold));
}

Health::~Health()
{   }

void Health::decrease(){
    health--;
    setPlainText(QString("HP: ") + QString::number(health));
}
void Health::increase(){
    health++;
    setPlainText(QString("HP: ") + QString::number(health));
}

int Health::getHealth(){
    return health;
}
