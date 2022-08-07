#include "Bullet.h"
#include <QTimer>
#include "Enemy.h"
#include <QList>
#include <QGraphicsScene>
#include "Game.h"


extern Game * game; // there is an external global object called game

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // set Bullet size
    setPixmap(QPixmap(":/images/C:/Users/Joe/Desktop/Bullet.png")); //path should be replaced with users path so graphics and sound work properly

    // create signal to connect with move function
    // move bullet when timer times out
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));

    timer-> start(45);

}

// function definition
void Bullet::move()
{
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem*> colliding_items = collidingItems();
    // if bullet collides with enemy, destroyed both the bullet and the enemy
    for (int i=0, n =colliding_items.size(); i < n; ++i){

        if (typeid(*(colliding_items[i])) == typeid(Enemy)){

        // increase the score
            game->score->increase();

        // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them both
            delete colliding_items[i];
            delete this;

            return;
        }


    }


    // move bullet up
    setPos(x(),y()-10);
    // if the bullet is off the screen, destroy it
       if (pos().y() < 0){
           scene()->removeItem(this);
           delete this;
}
}
