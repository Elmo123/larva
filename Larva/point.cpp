#include "point.h"
#include <stdlib.h>  //rand
#include <QPainter>
#include <iostream>


Point::Point()
{
    int random_x = rand() % 350;
    int random_y = rand() % 350;
    random_x = random_x + 10;
    random_y = random_y + 10;
    setPos(random_x, random_y);
    setRect(0,0,10,10);
}

Point::~Point()
{   }

