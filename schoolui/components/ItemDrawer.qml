import QtQuick 2.0

Component {
    id: itemDrawer
    Item {
        width: 230
        height: 40

        Text {
            id: text1
            text: qsTr(label)
            anchors.rightMargin: 5
            anchors.leftMargin: 15
            anchors.bottomMargin: 5
            anchors.topMargin: 5
            elide: Text.ElideRight
            clip: true
            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 12
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent

            onClicked: {
                console.info("ItemDrawer lable: "+label);
                try {
                    fnt();
                } catch(err) {
                    console.info("No fnt definido en la lista.");
                }
                parent.ListView.view.currentIndex = index;
            }

        }

    }
}
/*##^## Designer {
    D{i:1;anchors_x:8;anchors_y:15}D{i:2;anchors_height:100;anchors_width:100;anchors_x:36;anchors_y:5}
}
 ##^##*/
