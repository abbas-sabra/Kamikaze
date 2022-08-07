#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <QImage>
#include <QMediaPlayer>

Game::Game(QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(QImage(":/images/C:/Users/Joe/Desktop/Sky.png"))); //path should be replaced with users path so graphics and sound work properly

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // create the player
    myPlane = new MyPlane();
    myPlane->setPos(400,500); // to always be in the middle bottom of screen

    // make the player focusable and set it to be the current focus
    myPlane->setFlag(QGraphicsItem::ItemIsFocusable);
    myPlane->setFocus();
    // add the player to the scene
    scene->addItem(myPlane);

    // create the score/health
    score = new Score();
    scene->addItem(score);// add to the scene in order to be visualized
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);// add to the scene in order to be visualized

    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),myPlane,SLOT(spawn()));
    timer->start(2000);

    // play background music
    QMediaPlayer * music = new QMediaPlayer();

    music->setMedia(QUrl("qrc:/sounds/C:/Users/Joe/Desktop/background.mp3")); //path should be replaced with users path so graphics and sound work properly

    music->play();

    show();
}
