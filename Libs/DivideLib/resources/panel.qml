import QtQuick
Item {
    property var divideLib

    anchors.fill: parent

    Column {
        spacing: 10
        Text {

            Component.onCompleted: {
                divideLib.dataUpdated.connect(function(data) {resultDisplay.text = data})
            }

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
