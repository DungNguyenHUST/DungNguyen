#ifndef SENDTOSERVICE_H
#define SENDTOSERVICE_H

#include <QObject>
#include <qsharedmemory.h>


class SendToService:public QObject
{
    Q_OBJECT

public:
    //  Initialize shared memory
   // void InitialSharedMemory();
     // Write to shared memory
    void writeToShareMemory(QString event);

private:
    // create shaed memory
    QSharedMemory sharedMemory;

};

#endif // SENDTOSERVICE_H
