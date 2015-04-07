
#include <QKeyEvent>
#include "Player.h"
#include "constants.h"
#include <QGraphicsView>
//#include "score.h"
#include "Game.h"
#include <QDebug>


Player::Player(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    vMove = 0;
    jof = 1;
    setPixmap(QPixmap(":/images/birdR.png"));
}


void Player::keyPressEvent(QKeyEvent *event){

   if (event->key() == Qt::Key_Right) {
   if (pos().x() + ImgW < 800-20)  // right edge 10px - scroll bar
           changeVmove(0.7);

    setPixmap(QPixmap(":/images/birdR.png"));
   }
   else if (event->key() == Qt::Key_Left){
       if (pos().x() > 0)  //  left edge
            changeVmove(-0.7);
     setPixmap(QPixmap(":/images/birdL.png"));
   }


}



void Player::changeVmove(float v)
{
    vMove = v;
}

void Player::fall(){
    jof = 1;
}
void Player::jump(){
    jof = -1;
}

