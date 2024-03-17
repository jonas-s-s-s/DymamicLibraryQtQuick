import QtQuick
Item {
    property var multiplyLib

    anchors.fill: parent

    Column {
        spacing: 10
        Text {

            Component.onCompleted: {
                multiplyLib.dataUpdated.connect(function(data) {resultDisplay.text = data})
            }

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
