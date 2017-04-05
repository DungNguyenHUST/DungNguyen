#include "audiocontroller.h"
#include <QDebug>
#include <QString>




AudioController::AudioController()
{

}

AudioController::~AudioController()
{

}

QString AudioController::play()
{
    return "play";
}

QString AudioController::stop()
{
    return "stop";
}

QString AudioController::openFile()
{
    return "openFile";
}

QString AudioController::playFile()
{
    return "playFile";
}

QString AudioController::seekForward()
{
    return "seekForward";
}

QString AudioController::seekBackward()
{
    return "seekBackward";
}

QString AudioController::previous()
{
    return "previous";
}

QString AudioController::next()
{
    return "next";
}

QString AudioController::maxVolum()
{
    return "maxVolum";
}

QString AudioController::seekVolum()
{
    return "seekVolum";
}

QString AudioController::addFile()
{
    return "addFile";
}

QString AudioController::clearFile()
{
    return "clearFile";
}

QString AudioController::removeFile()
{
    return "removeFile";
}
