#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Button.h"
#include <QTimer>


const int Npf = 10;

Game::Game(QWidget *parent){

    //create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(scene);

    //create the player
    player = new Player();
    //create the Score
   // score = new Score();
   // startGame();
    show();
}

void Game::displayMainMenu(){

    // create the title text
      QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Doodle Jump"));
      QFont titleFont("comic sans",50);
      titleText->setFont(titleFont);
      int txPos = this->width()/2 - titleText->boundingRect().width()/2;
      int tyPos = 150;
      titleText->setPos(txPos,tyPos);
      scene->addItem(titleText);

      // create the play button
      Button* playButton = new Button(QString("Play"));
      int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
      int byPos = 275;
      playButton->setPos(bxPos,byPos);
      connect(playButton,SIGNAL(clicked()),this,SLOT(startGame()));
      scene->addItem(playButton);

      // create the quit button
      Button* quitButton = new Button(QString("Quit"));
      int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
      int qyPos = 350;
      quitButton->setPos(qxPos,qyPos);
      connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
      scene->addItem(quitButton);

}

void Game::startGame(){

    scene->clear();
    //add the Score
    // scene->addItem(score);
    //add item to scene
    scene->addItem(player);
    //make the player focusable
    player->setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    player->setFocus();
    // player pos
    player->setPos(400,300);

     //создание и добавление платформ
     createPlatforms();

     QTimer* t = new QTimer(this);
     connect(t, SIGNAL(timeout()), SLOT(update()));
     t->start(5);


}

void Game::update()
{
   player->setPos(player->x(),player->y()-1);
}

void Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity){
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}

void Game::createPlatforms(){
    pf = new Platforms *[Npf];
    for (int j = 0; j< Npf ;j++)
    {
         Platforms *p = new Platforms();
         pf[j] = p;
         scene->addItem(pf[j]);
    }

}


