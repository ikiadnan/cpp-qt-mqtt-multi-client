#include "MqttGraphicsScene.h"
#include <QtDebug>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>

MqttGraphicsScene::MqttGraphicsScene(QObject* parent)
    : QGraphicsScene(parent)
{

}
void MqttGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qInfo( "%s %s %d", __FILE__, __FUNCTION__, __LINE__ );
    QGraphicsScene::mousePressEvent(event);
}

void MqttGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseMoveEvent(event);

}

void MqttGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qInfo( "%s %s %d", __FILE__, __FUNCTION__, __LINE__ );
    QGraphicsScene::mouseReleaseEvent(event);
}
