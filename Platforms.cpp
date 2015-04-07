#include "Platforms.h"
#include <stdlib.h>
#include "constants.h"
#include <time.h>

Platforms::Platforms(): QObject(), QGraphicsRectItem()
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
    setRect(0,0,Wpf,Hpf);

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

