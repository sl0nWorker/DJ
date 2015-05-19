#ifndef PLAYER_H
#define PLAYER_H


#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>


class Player: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT

public:

    float vMove;
    int jof; // jump or fall

    Player( QGraphicsItem * parent = 0);
    void keyPressEvent(QKeyEvent * event);


    void changeVmove(float v);
    void jump();
    void fall();


};


#endif // PLAYER_H
