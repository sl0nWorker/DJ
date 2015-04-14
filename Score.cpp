#include <QFont>
#include "Score.h"

Score::Score(QGraphicsItem *parent):QGraphicsTextItem (parent){

    score = 0;
    // draw the text
    setPlainText(QString("Score: ")+QString::number(score)); //Score 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase()
{
    score = score + 1;
    setPlainText(QString("Score: ")+QString::number(score)); //Score 0

}

int Score::getScore()
{
    return score;

}
