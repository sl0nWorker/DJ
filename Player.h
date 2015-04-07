#ifndef PLAYER_H
#define PLAYER_H


#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>


class Player: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Player( QGraphicsItem * parent = 0);
    void keyPressEvent(QKeyEvent * event);

    void jump();
    void left();
    void right();
    void fall();


};


#endif // PLAYER_H
