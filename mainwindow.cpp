#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore/QDateTime>
#include <QtMqtt/QMqttClient>
#include <QtWidgets/QMessageBox>
#include <QtDebug>
#include <QCloseEvent>

#include "MqttDevice.h"
#include "MqttGraphicsScene.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qInfo( "%s %s %d", __FILE__, __FUNCTION__, __LINE__ );
    ui->setupUi(this);
    ui->graphicsViewDevices->setAlignment(Qt::AlignTop|Qt::AlignLeft);
    //scene = new QGraphicsScene(this);
    scene = new MqttGraphicsScene(this);
    //scene->setSceneRect(-300, -300, 600, 600);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    ui->graphicsViewDevices->setScene(scene);
    if(timer == nullptr)
    {
        qInfo( "%s %s %d init timer", __FILE__, __FUNCTION__, __LINE__ );
        timer = new QTimer(parent);
        connect(timer, SIGNAL(timeout()),this,SLOT(refreshScene()));
        timer->start(700);
    }
}

MainWindow::~MainWindow()
{
    qInfo( "%s %s %d", __FILE__, __FUNCTION__, __LINE__ );
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    qInfo( "%s %s %d", __FILE__, __FUNCTION__, __LINE__ );
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "MQTTTTT",
                                                                tr("Are you sure?\n"),
                                                                QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        for(auto it : devices)
        {
            it->disconnectFromBroker();
        }
        event->accept();
    }
}

void MainWindow::on_buttonQuit_clicked()
{
    qInfo( "%s %s %d", __FILE__, __FUNCTION__, __LINE__ );
    QApplication::quit();
}

void MainWindow::brokerDisconnected()
{
    qInfo( "%s %s %d", __FILE__, __FUNCTION__, __LINE__ );
    ui->lineEditHost->setEnabled(true);
    ui->spinBoxPort->setEnabled(true);
}

void MainWindow::setClientPort(int p)
{
    m_client->setPort(p);
}

void MainWindow::on_buttonAddDevice_clicked()
{
    qInfo( "%s %s %d", __FILE__, __FUNCTION__, __LINE__ );
    int deviceCount = ui->spinBoxDeviceCount->value();
    for(int i=0; i < deviceCount; i++)
    {
        MqttDevice* device = new MqttDevice(this, devicesXPos, devicesYPos
                                            ,ui->lineEditHost->text()
                                            ,ui->spinBoxPort->value()
                                            ,ui->lineEditUserName->text()
                                            ,ui->lineEditPassword->text()
                                            ,ui->lineEditTopic->text()
                                            );
        scene->addItem(device);
        devices.push_back(device);
        devicesXPos += 220;
        if(devices.size() % 5 == 0)
        {
            qInfo( "%s %s %d Added new device below", __FILE__, __FUNCTION__, __LINE__ );
            devicesYPos += 100;
            devicesXPos = 0;
        }

        ui->labelDeviceCount->setText(QString::number(devices.size()) + " device(s) added");
        ui->graphicsViewDevices->update();
        ui->graphicsViewDevices->scene()->update();
    }
}

void MainWindow::refreshScene()
{
    ui->graphicsViewDevices->update();
    ui->graphicsViewDevices->scene()->update();
    timer->start(700);
}
