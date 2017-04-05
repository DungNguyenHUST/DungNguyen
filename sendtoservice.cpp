#include "sendtoservice.h"
#include <QBuffer>
#include <QtCore/QDebug>
#include <QSharedMemory>
#include<QDataStream>


//void SendToService::InitialSharedMemory()
//{
//    qDebug() << "Creating new shared memory...";
//    sharedMemory.setKey("globalAudioBufferSharedMemory");
//    // khoi tao bo nho chia se
//    int sizeOfSharedData = 60 * 8000 * 2; // 60 Seconds x 8 KHz * 2 Bytes ( signed short )
//    if ( !sharedMemory.create( sizeOfSharedData ) )
//       {
//           qDebug() << "ERROR: Failed to Allocate Shared Memory of size"
//                    << sizeOfSharedData << "ERROR: " << sharedMemory.errorString();
//       }
//}
void SendToService::writeToShareMemory(QString event)
{
 sharedMemory.setKey("server1234");
 if (sharedMemory.isAttached())
       {
       sharedMemory.detach();
       }

    QBuffer buffer;
    buffer.open( QBuffer::ReadWrite );
    QDataStream out( &buffer );
    out << event;
    int size = buffer.size();

    // Write into the shared memory

     sharedMemory.lock();
    qDebug() << "Writing data to buffer: " << event;
    char *to = (char*)sharedMemory.data();
    const char *from = buffer.data().data();
    qDebug() << "Pointer In Shared Memory is: " << &to;
    memcpy( to, from, qMin( sharedMemory.size(), size ) );
    sharedMemory.unlock();
}

