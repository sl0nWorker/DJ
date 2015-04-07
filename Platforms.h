#ifndef PLATFORMS_H
#define PLATFORMS_H

#include <QGraphicsRectItem>
#include <QObject>

class Platforms:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:

    Platforms();
    void change ();
    void restart();

};


#endif // PLATFORMS_H
