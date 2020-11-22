#ifndef MQTTGRAPHICSSCENE_H
#define MQTTGRAPHICSSCENE_H

#include <QGraphicsScene>

class MqttGraphicsScene : public QGraphicsScene
{
    Q_OBJECT

public:
    MqttGraphicsScene(QObject* parent);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};
#endif // MQTTGRAPHICSSCENE_H
