#ifndef POINT_H
#define POINT_H
#include <QObject>
#include <QGraphicsRectItem>

class Point: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Point();
    ~Point();
};

#endif // POINT_H
