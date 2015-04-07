
#include <QKeyEvent>
#include "Player.h"
#include "constants.h"
#include <QGraphicsView>
//#include "score.h"
#include "Game.h"
#include <QDebug>


Player::Player(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/birdR.png"));
}


void Player::keyPressEvent(QKeyEvent *event){

   if (event->key() == Qt::Key_Right) {
   if (pos().x() + ImgW < 800-20)  // right edge 10px - scroll bar
            right();

    setPixmap(QPixmap(":/images/birdR.png"));
   }
   else if (event->key() == Qt::Key_Left){
       if (pos().x() > 0)  //  left edge
            left();
     setPixmap(QPixmap(":/images/birdL.png"));
   }


}

void Player::jump(){
    setPos(x(),y()-1);
}
void Player::left(){
    setPos(x()-1,y());
}
void Player::right(){
    setPos(x()+1,y());
}
void Player::fall(){
    setPos(x(),y()+1);
}
