import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Row
    {
        Rectangle
        {
            id:redrect
            width: 100
            height: 100
            color: "red"

            MouseArea
            {
                id:redrectmouseArea
                anchors.fill: parent
                onClicked:
                {
                    console.log("mousearea clicked")
                }
            }
        }

        Rectangle
        {
            id:bluerect
            width: 100
            height: 100
            color:"blue"

            Connections
            {
                target: redrectmouseArea

                onClicked:
                {
                    console.log("bluerect responding")
                }
            }
        }

        Rectangle
        {
            id:greenrect
            width: 100
            height: 100
            color: "green"

            Connections
            {
                target: redrectmouseArea

                onClicked:
                {
                    console.log("bluerect responding")
                }
            }
        }
    }
}
