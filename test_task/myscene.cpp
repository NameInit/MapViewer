#include "myscene.h"

MyScene::MyScene(QObject *parent) : QGraphicsScene(parent) {}

void MyScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseMoveEvent(event);
    emit mouseMoved(event->scenePos());
}
