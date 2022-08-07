#include <Health.h>
#include <qfont.h>


Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
 // initialize the Health to 4
    health = 4; // the Intial Health Value, This one will be decreased -1 when an Enemy escape
 // draw the text
    setPlainText(QString("Health: ")+ QString::number(health)); // Health:4
    setDefaultTextColor(Qt::red); // color
    setFont(QFont("times",16)); // time = name of the font , 16 = size

}

void Health::decrease(){

    health--;
     setPlainText(QString("Health: ")+ QString::number(health)); // set the new health
}

int Health::getHealth(){
    return  health;
}
