#include "Platforms.h"
#include <stdlib.h>
#include "constants.h"
#include <time.h>
#include <QBrush>

Platforms::Platforms(): QObject(), QGraphicsPixmapItem()
{

    int rndx;
    int rndy;

    QlevelW = rand()%3;

    if (QlevelW == 3 || qlw == 3){
        rndx = rand() % Wpf + QlevelW*Wzon;
        rndy = rand() % Hpf + (WinH - (2*QlevelH*Hpf));
        QlevelH=QlevelH+2; // next level
        qRnd = false;
    }
    else{
        if (!qRnd){
            qRnd = true;
            rndx = rand() % Wpf + QlevelW*Wzon;
            rndy = rand() % Hpf + (WinH - (2*QlevelH*Hpf));
            qlw = QlevelW;

        }
        else {
            if (qlw>=QlevelW){
                QlevelW=qlw+1;
                rndx = rand() % Wpf + QlevelW*Wzon;
                rndy = rand() % Hpf + (WinH - (2*QlevelH*Hpf));
                qlw = QlevelW;
                if (QlevelW==3){
                     QlevelH=QlevelH+2; // next level
                    qRnd = false;
                }
            }
            else {

                rndx = rand() % Wpf + QlevelW*Wzon;
                rndy = rand() % Hpf + (WinH - (2*QlevelH*Hpf));
                qlw = QlevelW;
            }

        }


   }
  //  setBackgroundBrush(QBrush(QImage(":/images/pbg.png")));
       setPixmap(QPixmap(":/images/pbg.png"));
    //setRect(0,0,Wpf,Hpf);

    setPos(rndx,rndy);

}

void Platforms::change()
{
    int rndx;
    int rndy;

    QlevelW = rand()%3;

    if (QlevelW == 3 || qlw == 3){
        rndx = rand() % Wpf + QlevelW*Wzon;
        rndy = rand() % Hpf + (WinH - (2*QlevelH*Hpf));
        QlevelH=QlevelH+2; // next level
        qRnd = false;
    }
    else{
        if (!qRnd){
            qRnd = true;
            rndx = rand() % Wpf + QlevelW*Wzon;
            rndy = rand() % Hpf + (WinH - (2*QlevelH*Hpf));
            qlw = QlevelW;

        }
        else {
            if (qlw>=QlevelW){
                QlevelW=qlw+1;
                rndx = rand() % Wpf + QlevelW*Wzon;
                rndy = rand() % Hpf + (WinH - (2*QlevelH*Hpf));
                qlw = QlevelW;
                if (QlevelW==3){
                     QlevelH=QlevelH+2; // next level
                    qRnd = false;
                }
            }
            else {

                rndx = rand() % Wpf + QlevelW*Wzon;
                rndy = rand() % Hpf + (WinH - (2*QlevelH*Hpf));
                qlw = QlevelW;
            }

        }


   }
     setPos(rndx,rndy);

}

void Platforms::restart()
{
     QlevelW = 0;
     QlevelH = 1;
}

