#include "Enemy.h"
#include <QTimer>
#include <stdlib.h>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "Game.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    // set random position
    int random_number = rand()%700;
    setPos(random_number, 0);
    // set Bullet size

    setPixmap(QPixmap(":/images/C:/Users/Joe/Desktop/Enemy.png"));  //path should be replaced with users path so graphics and sound work properly
    setTransformOriginPoint(50,50);



    // create signal to connect to move function
    // move bullet when timer  times out
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));
    // start the Time
    timer-> start(45);

}

// function definition
void Enemy::move()
{
    // move enemy down
    setPos(x(),y()+5);
    // destroy Enemey when it goes out of the screen
    if (pos().y()>600){

    // deacrease the health
      game->health->decrease();
      scene()->removeItem(this);
                delete this;

    }


}

