import QtQuick
import QtQuick.Controls
import DymamicLibraryQtQuick


Window {

    Component.onCompleted: {
        Controller.qmlLoaded.connect(function(item) {
            contentContainer.children = [item];
        })
    }

    width: 640
    height: 480
    visible: true
    title: qsTr("Dll example")

    Rectangle {
        id: topRect
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.right: parent.right
        height: parent.height/2
        width: parent.width
        color: "gray"

        Column {
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.topMargin: 10

            spacing: 5
            Button {
                height: 50
                width: 200
                text: "Load multiply by two DLL"
                onClicked: {
                    Controller.showLibraryQml(0);
                }
            }

            Button {
                height: 50
                width: 200
                text: "Load divide by two DLL"
                onClicked: {
                    Controller.showLibraryQml(1);
                }
            }

            Button {
                height: 50
                width: 200
                text: "Perform calculation"
                onClicked: {
                    Controller.clickUpdate(parseInt(numTf.text));
                }
            }
            TextField {
                id: numTf
                width: 200
                inputMethodHints: Qt.ImhDigitsOnly
                validator: RegularExpressionValidator {regularExpression: /[0-9]*/ }
            }
        }
    }
    Rectangle {
        anchors.left: parent.left
        anchors.top: topRect.bottom
        anchors.right: parent.right

        height: parent.height/2
        width: parent.width
        color: "lightblue"

        Item {
            id: contentContainer
            anchors.fill: parent
            anchors.leftMargin: 10
            anchors.topMargin: 10
        }

    }




}
