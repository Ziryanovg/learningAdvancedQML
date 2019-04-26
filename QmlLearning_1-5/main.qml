import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Connections
    {
        target: Sender
        onCallToQml:
        {
            textfield.text = param
        }

        onSendToQmlCount:
        {
            counttext.text = value
        }
    }

    Column
    {
        Rectangle
        {
            width: 200
            height: 200
            color: "red"
            radius: 20

            Text {
                id: counttext
                anchors.centerIn: parent
                text: qsTr("text")
                color:"white"
                font.pointSize: 30
            }
        }

        Button
        {
            width: 100
            height: 50
            text:"press"
            onClicked:
            {
                Sender.cppSlot();
            }
        }

        Text {
            id: textfield
            text: qsTr("Default")
        }
    }
}
