import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Layouts 1.0
import QtQuick.Controls 1.0
import QtQuick.Dialogs 1.0
import QtMultimedia 5.0



Rectangle
{
    id: item
    width: 640
    height: 480
    visible: true



    Image {
        id: img
        width: item.width
        height: item.height
        source: "qrc:/imagebackgroud/background.png"
    }
    ColumnLayout
    {
        id: column
        anchors.margins: 9
        anchors.fill: parent

        Label
        {
            id: infoLabel

            elide: Qt.ElideLeft
            verticalAlignment: Qt.AlignCenter
            Layout.minimumHeight: infoLabel.implicitHeight
            Layout.fillWidth: true
            Layout.fillHeight: true

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
                //
                Connections
                {
                    target: receiver
                    onPlayState: {
                        console.log("Received in QML from C++: " + mgs)
                    }
                }
                MouseArea
                {
                    id: mouseArea
                    anchors.fill: parent
                    onClicked:
                    {

                        audioController.play();
                        console.log("played music")                        
                    }
                }


            }
            ToolButton
            {
                id: stopButton
                Layout.preferredWidth: stopButton.implicitHeight
                iconSource: "qrc:/imageaudio/media-stop-16.png"
                onClicked:
                {
                    audioController.stop()
                    console.log("Stop")
                }
            }
            ToolButton
            {
                tooltip: qsTr("Rewind")
                iconSource: "qrc:/imageaudio/media-seek-backward-16.png"
                onClicked:
                {

                    audioController.seekBackward()
                    console.log("seekBackward")
                }
            }
            ToolButton
            {
                tooltip: qsTr("Forward")
                iconSource: "qrc:/imageaudio/media-seek-forward-16.png"
                onClicked:
                {

                    audioController.seekForward()
                    console.log("seekForward")
                }
            }
            ToolButton
            {
                tooltip: qsTr("previous")
                iconSource: "qrc:/imageaudio/previous-16.png"
                onClicked:
                {
                    audioController.previous()
                    console.log("previous")
                }
            }
            ToolButton
            {
                tooltip: qsTr("Next")
                iconSource: "qrc:/imageaudio/next-16.png"
                onClicked:
                {
                    audioController.next()
                    console.log("next")
                }
            }
            Slider
            {
                id: positionSlider
                Layout.minimumWidth: 75
                Layout.fillWidth: true
                //maximumValue: audioController.maxVolum()



            }

            Label
            {
                id: positionLabel


            }
            Slider
            {
                id: volumeSlide
                minimumValue: 0.0
                maximumValue: 1.0
                value: 1.0
                stepSize: 0.01
                implicitWidth: 50


                onValueChanged:
                {
//                    if(!sync)
//                    {
//                        // do some thing
//                    }
                }
            }
        }
        ColumnLayout
        {
            id: playlist

            ScrollView
            {
                Layout.fillWidth: true
                Layout.fillHeight: true
                flickableItem.interactive: true

                ListView
                {
                    id: playlistView
                    anchors.fill: parent
                }
            }


            RowLayout
            {
                ToolButton
                {
                    text: qsTr("ADd music file")
                    iconSource: "qrc:/imageaudio/plus-16.png"
                    onClicked:
                    {

                        audioController.addFile()
                        console.log("addFile")
                    }

                }
                ToolButton
                {
                    text: "Remove file from playlist"
                    iconSource: "qrc:/imageaudio/minus-16.png"
                    onClicked:
                    {

                        audioController.removeFile()
                        console.log("removeFile")
                    }
                }

                ToolButton
                {
                    text: qsTr("Clear playlist")
                    iconSource: "qrc:/imageaudio/cross-16.png"
                    onClicked:
                    {

                        audioController.clearFile()
                        console.log("clearFile")
                    }

                }
            }
        }

    }




}
