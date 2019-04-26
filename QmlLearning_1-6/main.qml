import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column
    {
        spacing: 20

        Text {
            id: texttitle
            text: Movie.title
        }

        Row
        {
            TextEdit
            {
                id:textedittitle
                width: 200
            }

            Button{
                text: "push"
                onClicked:
                {
                    Movie.title = textedittitle.text
                }
            }
        }
    }
}
