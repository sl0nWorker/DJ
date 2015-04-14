#ifndef PLATFORMS_H
#define PLATFORMS_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Platforms:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:

    Platforms();
    void change ();
    void restart();

};


#endif // PLATFORMS_H
