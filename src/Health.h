#ifndef HEALTH_H
#define HEALTH_H


#include <QGraphicsTextItem>

// add Health class
class Health: public QGraphicsTextItem {

  public:
    Health(QGraphicsItem * parent=0);
    void decrease(); // this function will decrease the Health
    int getHealth(); // and this one will return the Health
private:
    int health; // show the current score


};




#endif // HEALTH_H
