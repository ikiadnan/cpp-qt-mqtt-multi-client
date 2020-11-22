/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEditHost;
    QLabel *label_2;
    QSpinBox *spinBoxPort;
    QLabel *label_5;
    QLineEdit *lineEditUserName;
    QLabel *label_6;
    QLineEdit *lineEditPassword;
    QLabel *label_3;
    QLineEdit *lineEditTopic;
    QPushButton *buttonAddDevice;
    QLabel *label_4;
    QLabel *labelDeviceCount;
    QSpinBox *spinBoxDeviceCount;
    QGraphicsView *graphicsViewDevices;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonQuit;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1024, 768);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEditHost = new QLineEdit(centralWidget);
        lineEditHost->setObjectName(QString::fromUtf8("lineEditHost"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditHost);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        spinBoxPort = new QSpinBox(centralWidget);
        spinBoxPort->setObjectName(QString::fromUtf8("spinBoxPort"));
        spinBoxPort->setMaximum(99999);
        spinBoxPort->setValue(11062);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBoxPort);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        lineEditUserName = new QLineEdit(centralWidget);
        lineEditUserName->setObjectName(QString::fromUtf8("lineEditUserName"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEditUserName);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_6);

        lineEditPassword = new QLineEdit(centralWidget);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEditPassword);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_3);

        lineEditTopic = new QLineEdit(centralWidget);
        lineEditTopic->setObjectName(QString::fromUtf8("lineEditTopic"));

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEditTopic);

        buttonAddDevice = new QPushButton(centralWidget);
        buttonAddDevice->setObjectName(QString::fromUtf8("buttonAddDevice"));

        formLayout->setWidget(7, QFormLayout::LabelRole, buttonAddDevice);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_4);

        labelDeviceCount = new QLabel(centralWidget);
        labelDeviceCount->setObjectName(QString::fromUtf8("labelDeviceCount"));
        QFont font;
        font.setPointSize(12);
        labelDeviceCount->setFont(font);

        formLayout->setWidget(7, QFormLayout::FieldRole, labelDeviceCount);

        spinBoxDeviceCount = new QSpinBox(centralWidget);
        spinBoxDeviceCount->setObjectName(QString::fromUtf8("spinBoxDeviceCount"));
        spinBoxDeviceCount->setMinimum(1);
        spinBoxDeviceCount->setMaximum(999);

        formLayout->setWidget(6, QFormLayout::FieldRole, spinBoxDeviceCount);


        horizontalLayout->addLayout(formLayout);


        verticalLayout->addLayout(horizontalLayout);

        graphicsViewDevices = new QGraphicsView(centralWidget);
        graphicsViewDevices->setObjectName(QString::fromUtf8("graphicsViewDevices"));
        graphicsViewDevices->setMaximumSize(QSize(16777215, 16777213));
        graphicsViewDevices->setFrameShape(QFrame::StyledPanel);

        verticalLayout->addWidget(graphicsViewDevices);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        buttonQuit = new QPushButton(centralWidget);
        buttonQuit->setObjectName(QString::fromUtf8("buttonQuit"));
        buttonQuit->setFlat(false);

        horizontalLayout_3->addWidget(buttonQuit);


        verticalLayout->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Host:", nullptr));
        lineEditHost->setText(QCoreApplication::translate("MainWindow", "soldier.cloudmqtt.com", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Port:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "User Name", nullptr));
        lineEditUserName->setText(QCoreApplication::translate("MainWindow", "bnadyuxw", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        lineEditPassword->setInputMask(QString());
        lineEditPassword->setText(QCoreApplication::translate("MainWindow", "p8pKMzQSmkjo", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Topic:", nullptr));
        lineEditTopic->setText(QCoreApplication::translate("MainWindow", "/group/regu/", nullptr));
        buttonAddDevice->setText(QCoreApplication::translate("MainWindow", "Add New\n"
"Device", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Device:", nullptr));
        labelDeviceCount->setText(QCoreApplication::translate("MainWindow", "0 device(s) added", nullptr));
        buttonQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
