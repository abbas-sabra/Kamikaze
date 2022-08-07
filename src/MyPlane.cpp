#include "MyPlane.h"
#include<QKeyEvent>
#include <QGraphicsScene>
#include "Bullet.h"
#include "Enemy.h"




MyPlane::MyPlane(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    // set bullet sound
     bulletsound = new QMediaPlayer();

     bulletsound->setMedia(QUrl("qrc:/sounds/C:/Users/Joe/Desktop/bullet.wav")); //path should be replaced with users path so graphics and sound work properly


    setPixmap(QPixmap(":/images/C:/Users/Joe/Desktop/Plane.png")); //path should be replaced with users path so graphics and sound work properly


}
// Moving the Plane with the Arrow Keys
void MyPlane::keyPressEvent(QKeyEvent *event)
{

    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
                setPos(x()-10,y());
       }
       else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
               setPos(x()+10,y());
       }

    // add Bullet keybind to Spacebar
    else if (event->key() == Qt::Key_Space) {
             Bullet * bullet = new Bullet();
             bullet->setPos(x(),y());
             scene()->addItem(bullet); //add the Bullet to the scene

        // play bulletsound
       if (bulletsound->state() == QMediaPlayer::PlayingState){
       bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
                         bulletsound->play();
       }

    }
}

void MyPlane::spawn()
{
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);

}

