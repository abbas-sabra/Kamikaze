#include <Score.h>
#include <QFont>


Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
 // initialize the score to 0
    score =0;
 // draw the text
    setPlainText(QString("Score: ")+ QString::number(score)); // score:0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16)); // time = name of the font , 16 = size

}

void Score::increase(){

    score++;
     setPlainText(QString("Score: ")+ QString::number(score)); // set the new score, update the text
}

int Score::getScore(){
    return  score;
}

