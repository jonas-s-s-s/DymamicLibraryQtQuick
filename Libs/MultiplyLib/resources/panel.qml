import QtQuick
Item {
    anchors.fill: parent

    // POINTER TO C++ OBJECT CONTAINING SIGNALS (initialized on construction)
    property var multiplyLib
    Connections {
        target: multiplyLib
        // CONNECT TO C++ SIGNALS HERE
        function onDataUpdated(data) {resultDisplay.text = data}
    }

    Column {
        spacing: 10
        Text {
            id: resultDisplay
            color: "red"
            text: "No input data."
        }

        Image {
            width: 30
            height: 30
            source: "qrc:///MultiplyLib/resources/picture.svg"
        }
    }

}
