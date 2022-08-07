#ifndef MYPLANE_H
#define MYPLANE_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class MyPlane:public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
 public:
    MyPlane(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event); // member Function (KeyPressEvent) will allows the Object (MyPlane) to respond when my Keyboard being pressed.
public slots:
    void spawn();
private:
    QMediaPlayer* bulletsound;

};



#endif // MYPLANE_H
