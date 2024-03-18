import QtQuick
Item {
    property var divideLib

    anchors.fill: parent

    Connections {
        target: divideLib
        function onDataUpdated(data) {resultDisplay.text = data}
    }

    Column {
        spacing: 10
        Text {
            id: resultDisplay
            color: "blue"
            text: "No input data."
        }

        Image {
            width: 30
            height: 30
            source: "qrc:///DivideLib/resources/picture.svg"
        }
    }

}
