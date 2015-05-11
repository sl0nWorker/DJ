#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QGraphicsRectItem>


class TextEdit:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    // constructors
    TextEdit(QString name, QGraphicsItem* parent=NULL);

private:
    QGraphicsTextItem* text;
};


#endif // TEXTEDIT_H
