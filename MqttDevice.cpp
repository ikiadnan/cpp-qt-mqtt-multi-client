#include "MqttDevice.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QtWidgets>
#include <QtDebug>
#include <QtMqtt/QMqttClient>
#include <QRandomGenerator>

MqttDevice::MqttDevice(QObject* parent)
{
    qInfo( "%s %s %d", __FILE__, __FUNCTION__, __LINE__ );
    this->parent = parent;
    init();
    setCursor(Qt::PointingHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
}
MqttDevice::MqttDevice(QObject* parent, int positionX, int positionY, QString hostAddress, quint16 port, QString userName, QString password, QString topicPrefix) :
    mPositionX(positionX),
    mPositionY(positionY),
    mHostAddress(hostAddress),
    mPort(port),
    mUserName(userName),
    mPassword(password),
    mTopicPrefix(topicPrefix)
{
    qInfo( "%s %s %d x: %d y: %d", __FILE__, __FUNCTION__, __LINE__, mPositionX, mPositionY );
    this->parent = parent;
    setCursor(Qt::PointingHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
    init();
}


MqttDevice::~MqttDevice()
{
    qInfo( "%s %s %d", __FILE__, __FUNCTION__, __LINE__ );
    if(mClient->state() == QMqttClient::Connected)
    {
        mClient->disconnectFromHost();
    }
}
void MqttDevice::init()
{
    qInfo( "%s %s %d", __FILE__, __FUNCTION__, __LINE__ );
    mLocation.latitude = -7.823900;
    mLocation.longitude = 110.370500;
    QString suffix = QString::number(QRandomGenerator::global()->bounded(5555));
    mImei += suffix;
    mPublishTopic = mTopicPrefix + mImei;
    mClient = new QMqttClient(parent);
    mClient->setHostname(mHostAddress);
    mClient->setPort(mPort);
    mClient->setUsername(mUserName);
    mClient->setPassword(mPassword);
    connect(mClient, &QMqttClient::stateChanged, this, &MqttDevice::updateState);
    connect(mClient, &QMqttClient::disconnected, this, &MqttDevice::updateState);
    connect(mClient, &QMqttClient::pingResponseReceived, this, [this]() {
        const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(" PingResponse")
                    + QLatin1Char('\n');
    });

    connect(mClient, &QMqttClient::messageReceived, this, [this](const QByteArray &message, const QMqttTopicName &topic)
    {
        qInfo( "%s %s %d messageReceived", __FILE__, __FUNCTION__, __LINE__ );
        const QString content = "Sub:"
                    + QDateTime::currentDateTime().time().toString()
                    + " "
                    + message;
        this->mLastSubscribeMessage = content;
    });
    connectToBroker();
}

void MqttDevice::connectToBroker()
{
    qInfo( "%s %s %d", __FILE__, __FUNCTION__, __LINE__ );
    mClient->connectToHost();
    if(timer == nullptr)
    {
        qInfo( "%s %s %d init timer", __FILE__, __FUNCTION__, __LINE__ );
        timer = new QTimer(parent);
        connect(timer, SIGNAL(timeout()),this,SLOT(publishPosition()));
        timer->start(1000);
    }
}

void MqttDevice::disconnectFromBroker()
{
    if (mClient->state() == QMqttClient::Connected) {
        mClient->disconnectFromHost();
        isSubscribedtoImeiCmd = false;
    }
}
void MqttDevice::updateState()
{
    QString status = "";
    switch(mClient->state())
    {
    case QMqttClient::ClientState::Disconnected:
        status = "Disconnected";
        break;
    case QMqttClient::ClientState::Connecting:
        status = "Connecting...";
        break;
    case QMqttClient::ClientState::Connected:
        status = "Connected";
        if(!isSubscribedtoImeiCmd)
        {
            QString topic = "/+/+/" + mImei + "_cmd";
            auto subscription = mClient->subscribe(topic);
            if (!subscription)
            {
                mLastSubscribeMessage = "Sub: Not subscribed!";
            }
            else
            {
                mLastSubscribeMessage = "Sub: " + topic;
                isSubscribedtoImeiCmd = true;
            }
        }
        break;
    default:
        break;

    }

    const QString content = QLatin1String("Status : ") + status;
    mState = content;
}
void MqttDevice::updateLastPublishMessage(QString publishMessage)
{
    mLastPublishMessage = "Last publish message: " + publishMessage;
}
void brokerDisconnected()
{

}

void MqttDevice::publishPosition()
{
    //qInfo( "%s %s %d", __FILE__, __FUNCTION__, __LINE__ );
    char buffer[30];
    //update dummy position
    int posToUpdate = QRandomGenerator::global()->bounded(4);
    double updateLength = static_cast<double>(QRandomGenerator::global()->bounded(10))/100000;
    switch(posToUpdate)
    {
        case 0:
            mLocation.latitude += updateLength;
            break;
        case 1:
            mLocation.longitude += updateLength;
            break;
        case 2:
            mLocation.latitude -= updateLength;
            break;
        case 3:
            mLocation.longitude -= updateLength;
            break;
        default:
            break;
    }

    sprintf(buffer,"%0.7f,%0.7f",mLocation.latitude,mLocation.longitude);
    if(mClient->state() == QMqttClient::ClientState::Connected)
    {
        QElapsedTimer timer;
        timer.start();
        mClient->publish(mPublishTopic, buffer, 2);
        qint64 elapsedTime = timer.nsecsElapsed();
        qInfo( "%s %s %d", __FILE__, __FUNCTION__, __LINE__);
        QString message = buffer;
        int size = sizeof(qint8) //header
                  + mPublishTopic.size() //topic
                  + sizeof(qint16)  //identifier
                  + message.size(); //message
        mSpeed = (1000000  * static_cast<qreal>(size)) / static_cast<qreal>(elapsedTime);
        if(mSpeed > 1000)
        {
            mSpeed /= 1000;
            mSpeedUnit = "MB/s";
        }
        else
        {
            mSpeedUnit = "KB/s";
        }
        mLastPublishMessage = "Pub:"+ QDateTime::currentDateTime().time().toString() + " " + QString(buffer);
    }
    timer->start();


}

QRectF MqttDevice::boundingRect() const
{
    return QRectF(mPositionX - width/2, mPositionY - width/2,(qreal) width, (qreal)height);
    //return QRectF(0, 0,(qreal) width, (qreal)height);
}
QPainterPath MqttDevice::shape() const
{
    QPainterPath path;
    path.addRect(mPositionX - width/2, mPositionY - width/2,(qreal) width, (qreal)height);
    return path;
}
void MqttDevice::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    painter->drawRect(boundingRect());
    painter->drawText(mPositionX - width/2 + margin, mPositionY - width/2 + margin, mClient->clientId());
    painter->drawText(mPositionX - width/2 + margin, mPositionY - width/2 + 2 * margin, mState);
    painter->drawText(mPositionX - width/2 + margin, mPositionY - width/2 + 3 * margin, mLastPublishMessage);
    painter->drawText(mPositionX - width/2 + margin, mPositionY - width/2 + 4 * margin, mLastSubscribeMessage);
    painter->drawText(mPositionX - width/2 + margin, mPositionY - width/2 + 5 * margin, "IMEI: " + mImei);
    painter->drawText(mPositionX - width/2 + margin, mPositionY - width/2 + 6 * margin, "Speed: " + QString::number(mSpeed) + " " + mSpeedUnit);
}

void MqttDevice::advance(int step)
{

}

void MqttDevice::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    qInfo( "%s %s %d", __FILE__, __FUNCTION__, __LINE__ );
    setCursor(Qt::ClosedHandCursor);
    isPressed = true;
}

void MqttDevice::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    qInfo( "%s %s %d", __FILE__, __FUNCTION__, __LINE__ );
    setCursor(Qt::PointingHandCursor);
}

void MqttDevice::mouseReleaseEvent(QGraphicsSceneMouseEvent *)
{
    qInfo( "%s %s %d", __FILE__, __FUNCTION__, __LINE__ );
    setCursor(Qt::PointingHandCursor);
    if(isPressed)
    {
        QMessageBox msgBox;
        msgBox.setTextInteractionFlags(Qt::TextInteractionFlag::TextSelectableByMouse);
        QString txt = "Client ID\t: " + mClient->clientId() + QLatin1Char('\n')
                    + "Host Name\t: " + mClient->hostname() + QLatin1Char('\n')
                    + "Port\t: " + QString::number(mClient->port()) + QLatin1Char('\n')
                    + "User Name\t: " + mClient->username() + QLatin1Char('\n')
                    + "Password\t: " + mClient->password() + QLatin1Char('\n')
                    + "IMEI\t: " + mImei + QLatin1Char('\n')
                    + QLatin1Char('\n') + mState;

        msgBox.setText(txt);
        QAbstractButton* pBtnCopy = msgBox.addButton(tr("Copy IMEI"), QMessageBox::NoRole);
        msgBox.addButton(tr("Ok"), QMessageBox::YesRole);
        QAbstractButton* pBtnConnect = msgBox.addButton(tr( mClient->state() == QMqttClient::ClientState::Connected ? "Disconnect" : "Connect"), QMessageBox::NoRole);
        msgBox.exec();
        if (msgBox.clickedButton() == pBtnCopy) {
            QClipboard *clipboard = QApplication::clipboard();
            clipboard->setText(mImei);
        }
        else if(msgBox.clickedButton() == pBtnConnect)
        {
            mClient->state() == QMqttClient::ClientState::Connected ? disconnectFromBroker() : connectToBroker();
        }
    }
    isPressed = false;
}
