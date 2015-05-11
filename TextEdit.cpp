#include "TextEdit.h"
#include <QGraphicsTextItem>
#include <QBrush>


TextEdit::TextEdit(QString name, QGraphicsItem *parent)
{
    // draw the rect
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);

    // draw the text
    text = new QGraphicsTextItem(name,this);
    text->setDefaultTextColor(Qt::white);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    // allow responding to hover events
    setAcceptHoverEvents(true);
}
