import QtQuick 2.2
import QtQuick.Window 2.1
//import "bootstrap.worker" as Bootstrap

Window {
    id: test
    visible: true
    //visibility: "FullScreen"
    width: 500
    height: 500
    //Component.onCompleted: Bootstrap.startup();

    WorkerScript {
            id: bootstrapWorker
            source: "bootstrap.worker.js"
            onMessage: myText.text = messageObject.reply
    }
    Connections {
        target: receiver
        onSendToQml: {
            console.log("Received in QML from C++: " + count)
        }
    }

    MouseArea {
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.rightMargin: 0
        anchors.bottomMargin: 234
        anchors.fill: parent
        onClicked: {
            receiver.runbackgroundcmd();
            //bootstrapWorker.sendMessage({ 'x': mouse.x, 'y': mouse.y })
            //console.log("QML: Clicked Button")
        }
    }

    Text {
        text: qsTr("test.height is curently " + test.height)
        anchors.verticalCenterOffset: -116
        anchors.horizontalCenterOffset: -79
        anchors.centerIn: parent
    }


    Rectangle {
        id:img
        width: 50
        height: 50
        color: "#ff2929"
        anchors.horizontalCenter: parent.horizontalCenter
        SequentialAnimation on y{
        id:anim
        running:true;loops:Animation.Infinite
        NumberAnimation{
            to:test.height - img.height;duration:2000; easing.type:Easing.OutBounce
        }
        PauseAnimation{duration:1000}
        NumberAnimation{
            to:0;duration:1000; easing.type:Easing.OutQuad
        }
        }
    }

    Text {
        id: myText
        x: 18
        y: 297
        width: 134
        height: 14
        text: "Test"
        font.pixelSize: 12
    }
}
