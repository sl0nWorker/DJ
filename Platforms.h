#ifndef PLATFORMS_H
#define PLATFORMS_H

#include <QGraphicsRectItem>
#include <QObject>

class Platforms:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:

    Platforms();
    void change ();

};


#endif // PLATFORMS_H
