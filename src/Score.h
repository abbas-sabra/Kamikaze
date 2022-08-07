#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsSimpleTextItem>

// add score class
class Score: public QGraphicsTextItem {

  public:
    Score(QGraphicsItem * parent=0);
    void increase(); // this function will increase the score
    int getScore(); // and this one will return the score
private:
    int score; // show the current score


};






#endif // SCORE_H
