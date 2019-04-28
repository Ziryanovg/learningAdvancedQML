import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Extras 1.4 as QQE

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ListView {
        width: 200; height: 250

        model: MainModel
        delegate: Text { text: name }
    }

    QQE.StatusIndicator {
        id: statusIndicator
        x: 0
        y: 263
        color:"green"
        on:false
    }


}
