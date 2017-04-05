#ifndef AUDIOCONTROLLER_H
#define AUDIOCONTROLLER_H

#include <QObject>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QWidgetList>



class AudioController : public QObject
{
    Q_OBJECT
public:
  //  explicit AudioController(QObject *parent = 0);
    AudioController();
    ~AudioController();

    Q_INVOKABLE QString play();
    Q_INVOKABLE QString stop();
    Q_INVOKABLE QString openFile();
    Q_INVOKABLE QString playFile();
    Q_INVOKABLE QString seekForward();
    Q_INVOKABLE QString seekBackward();
    Q_INVOKABLE QString previous();
    Q_INVOKABLE QString next();
    Q_INVOKABLE QString maxVolum();
    Q_INVOKABLE QString seekVolum();
    Q_INVOKABLE QString addFile();
    Q_INVOKABLE QString clearFile();
    Q_INVOKABLE QString removeFile();

signals:

public slots:
};

#endif // AUDIOCONTROLLER_H
