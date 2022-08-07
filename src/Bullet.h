#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

// create Bullet Class
// inheret from QObject and QGraphicsRectItem
class Bullet: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet(QGraphicsItem*parent=0);
public slots:
    // creat slot function to connect to signal
    void move();
};





#endif // BULLET_H
