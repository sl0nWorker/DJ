#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "Player.h"
//#include "Score.h"
#include "Platforms.h"

class Game: public QGraphicsView{
Q_OBJECT
public:

    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
    //Score * score;
    Platforms **pf;


    void displayMainMenu();
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    void createPlatforms();
public slots:

    void startGame();
    void update();
    // void restartGame();


};

#endif // GAME_H
