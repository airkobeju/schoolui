import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

RowLayout {
    id: swipeCheckButton

    property alias currentIndex: barra.currentIndex

    width: 600
    anchors {
        top: parent.top
        right: parent.right
        left: parent.left
    }
    height: 50
    clip: true

    TabBar {
        id: barra
        Layout.alignment: Qt.AlignVCenter|Qt.AlignCenter

        TabButton {
            id: button
            width: 120
            height: 40
            text: qsTr("Formulario")
            checkable: true
        }

        TabButton {
            id: button1
            width: 120
            height: 40
            text: qsTr("Lista")
            checkable: true
        }

    }


}
