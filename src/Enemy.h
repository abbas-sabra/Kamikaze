#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>






// create Bullet Class
// inheret from QObject and QGraphicsRectItem
class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent=0);
public slots:
    // creat slot function to connect to signal
    void move();
};




#endif // ENEMY_H
