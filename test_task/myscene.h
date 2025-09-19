#ifndef MYSCENE_H
#define MYSCENE_H


#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QDebug>

class MyScene : public QGraphicsScene
{
    Q_OBJECT
public:
    MyScene(QObject *parent = nullptr);

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

signals:
    void mouseMoved(const QPointF &scenePos);
};

#endif // MYSCENE_H
