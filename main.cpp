
#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QWindow>
#include <QQmlContext>
#include <QStandardPaths>
#include <QDir>
#include <QDebug>
#include <QQuickItem>
#include <QObject>
#include <QQmlContext>
#include <QQuickView>

#include "audiocontroller.h"
#include "receiver.h"
#include "sendtoservice.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // SetContextProperty AudioController
//    QQuickView view;

//    AudioController data;
//    view.rootContext()->setContextProperty("audioController", &data);
//    view.setSource (QUrl("qrc:/audio.qml"));
//    view.show();


    //Set ContextProperty Receiver




    QQuickView view;
    Receiver receiverdata;
    AudioController data;
    SendToService loadData;
   // loadData.InitialSharedMemory();
    loadData.writeToShareMemory("stop");

    view.rootContext()->setContextProperty("receiver",&receiverdata);
    view.rootContext()->setContextProperty("audioController", &data);
    view.setSource(QUrl("qrc:/audio.qml"));
    view.show();


    return app.exec();
}
