#include "Game.h"
#include <QGraphicsTextItem>
#include <QFont>
#include "Button.h"
#include "constants.h"
#include <time.h>

Game::Game(QWidget *parent){

    t = new QTimer(this);
    scroll = 0;
    //create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(scene);
    scene->setBackgroundBrush(Qt::gray);
    show();
}

void Game::displayMainMenu(){

    // create the title text
      QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Doodle Jump"));
      QFont titleFont("comic sans",50);
      titleText->setFont(titleFont);
      int txPos = this->width()/2 - titleText->boundingRect().width()/2;
      int tyPos = sceneRect().y()+150;
      titleText->setPos(txPos,tyPos);
      scene->addItem(titleText);

      // create the play button
      Button* playButton = new Button(QString("Play"));
      int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
      int byPos = sceneRect().y()+275;
      playButton->setPos(bxPos,byPos);
      connect(playButton,SIGNAL(clicked()),this,SLOT(startGame()));
      scene->addItem(playButton);

      // create the quit button
      Button* quitButton = new Button(QString("Quit"));
      int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
      int qyPos = sceneRect().y()+350;
      quitButton->setPos(qxPos,qyPos);
      connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
      scene->addItem(quitButton);

}

void Game::displayGameOverMenu(int s)
{


    // create the title text
      QString is = QString::number(s);
      QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Your Score is "+is));
      QFont titleFont("comic sans",50);
      titleText->setFont(titleFont);
      int txPos = this->width()/2 - titleText->boundingRect().width()/2;
      int tyPos = sceneRect().y()+150;
      titleText->setPos(txPos,tyPos);
      scene->addItem(titleText);

      // create the play button
      Button* playButton = new Button(QString("Play again"));
      int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
      int byPos = sceneRect().y()+275;
      playButton->setPos(bxPos,byPos);
      connect(playButton,SIGNAL(clicked()),this,SLOT(startGame()));
      scene->addItem(playButton);

      // create the quit button
      Button* quitButton = new Button(QString("Quit"));
      int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
      int qyPos = sceneRect().y()+350;
      quitButton->setPos(qxPos,qyPos);
      connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
      scene->addItem(quitButton);
}

void Game::startGame(){


   scene->setBackgroundBrush(QBrush(QImage(":/images/bg.png")));
    srand(time(NULL));
   // scroll = 0;
    heightJump = 0;

     //create the player
     player = new Player();
     //create the Score
     score = new Score();
     score->setPos(sceneRect().x(),sceneRect().y());

    scene->clear();
    //add the Score
     scene->addItem(score);
    //add item to scene
    scene->addItem(player);
    //make the player focusable


    player->setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    player->setFocus();
    // player pos
    player->setPos(sceneRect().x()+400,sceneRect().y()+101);

     //создание и добавление платформ
     createPlatforms();


     connect(t, SIGNAL(timeout()),this, SLOT(update()));
     t->start(3);


}

void Game::update()
{
   if (sceneRect().y() > player->pos().y()-100) { // прокрутка сцены
       scroll = scroll - 5;
       setSceneRect(0,scroll,800,600);

       score->increase();
       score->setPos(sceneRect().x(),sceneRect().y());

   }


   if (player->jof == -1)
        heightJump++;

   if (heightJump == 250) { // высота прыжка
        heightJump = 0;
        player->fall();
   }

  player->setPos(player->x()+player->vMove,player->y()+player->jof); // перемещение игрока

    if (player->pos().x() + ImgW > 800-20 || player->pos().x()<0 )
        player->vMove = 0;


  if (player->jof == 1) { // если игрок падает, то проверяем наличие платформ под ногами, если есть то прыгаем
       for (int j = 0; j<Npf;j++)
       {
           if ( (player->pos().x()+ImgW/2> pf[j]->pos().x()) && (player->pos().x()<pf[j]->pos().x()+Wpf-ImgW/2)&& (player->pos().y() == pf[j]->pos().y()-Hpf)) {
              player->jump();
           }

       }
  }
// цикл для бесконечно генерации платформ, платформы уходящии за экран заново генерируюца сверху.
  for (int j = 0; j< Npf ;j++)
  {
       if (pf[j]->pos().y()>sceneRect().y()+600)
       {
          pf[j]->change();
       }
  }

//displayGameOverMenu(int s)
  if( player->pos().y()> sceneRect().y()+600)
  {
     t->stop();
     disconnect(t, SIGNAL(timeout()),this,SLOT(update()));
     pf[0]->restart();
     scene->clear();
    // scene->setSceneRect(0,0,800,600);
     QGraphicsView::viewport()->update();

     displayGameOverMenu(score->getScore());
  }


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


