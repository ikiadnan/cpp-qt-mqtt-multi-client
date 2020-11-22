#ifndef MQTTDEVICE_H
#define MQTTDEVICE_H

#include <QtMqtt/QMqttClient>
#include <QGraphicsItem>
#include <QTimer>

struct GPSLocation
{
    double latitude;
    double longitude;
};

class MqttDevice : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    MqttDevice(QObject* parent);
    MqttDevice(QObject* parent, int positionX, int positionY);
    MqttDevice(QObject* parent, int positionX, int positionY, QString hostAddress, quint16 port, QString userName, QString password, QString topicPrefix);
    ~MqttDevice() override;
    void init();
    void connectToBroker();
    void disconnectFromBroker();

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

public slots:
    void publishPosition();

protected:
    void advance(int step) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    void updateState();
    void updateLastPublishMessage(QString publishMessage);
    QObject* parent;
    QMqttClient* mClient;
    QString mHostAddress = "broker.hivemq.com";
    QString mUserName = "";
    QString mPassword = "";
    quint16 mPort = 1883;
    QString mImei = "12233344445";
    QString mState = "State:";
    QString mLastPublishMessage = "Last publish message:";
    QString mLastSubscribeMessage = "Last subscribe message:";
    QString mReceivedString = "";
    QString mPublishTopic;
    QString mSubscribeTopic;
    QString mTopicPrefix = "indgtl/imeitest/";
    GPSLocation mLocation;
    bool isSubscribedtoImeiCmd = false;
    qreal mSpeed = 0;
    QString mSpeedUnit = "KB/s";


    QTimer* timer = nullptr;
    int mPositionX = 0;
    int mPositionY = 0;
    const int height = 100;
    const int width = 220;
    const int margin = 15;
    bool isPressed = false;
};

#endif // MQTTDEVICE_H
