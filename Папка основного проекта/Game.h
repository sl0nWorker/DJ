#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QSettings>
#include "Player.h"
#include "Score.h"
#include "Platforms.h"
#include <QLineEdit>


class Game: public QGraphicsView{
Q_OBJECT
public:


    int heightJump;
    int scroll;
    int sdf;
    QTimer * t;
    QTime *timer;
    Game(QWidget * parent=0);

    QSettings *settings;
    QList<int> Lscore;
    QStringList name;
    QString  nowName;


    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Platforms **pf;

     QLineEdit* line;


    void topName(int bestScore, QString bestScoreName);
    void displayMainMenu();
    void displayGameOverMenu(int s);
    void displayTextMenu();

    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    void createPlatforms();
    int top10(int bestScore, QString bestScoreName);

public slots:
    void displayTop10();
    void startGame();
    void update();
    void changeGodName();


};

#endif // GAME_H
