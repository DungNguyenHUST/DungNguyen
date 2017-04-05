import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Layouts 1.0
import QtQuick.Controls 1.0
import QtQuick.Dialogs 1.0
import QtMultimedia 5.0
import QtWinExtras 1.0 as Win



Rectangle
{
    id: item
    width: 640
    height: 480
    visible: true
    color : "green"
    Image {
        id: img
        width: item.width
        height: item.height
        source: "qrc:/imagebackgroud/background.png"
    }

    RowLayout
    {
        id: row

        ToolButton
        {
            id: playPauseButton
            iconSource: "qrc:/imageaudio/media-play-16.png"
            // enable audio
            Layout.preferredWidth: playPauseButton.implicitHeight

            onClicked:
            {
                 console.log(audioController.play())
            }
            Connections {
                target: receiver
                onSendToQml: {
                    console.log("Received in QML from C++: " + count)
                }
            }

        }
     }


}
