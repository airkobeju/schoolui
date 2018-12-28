import QtQuick 2.9

Component {
    id: itemListObjects

    Item {
        width: parent.width
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
                console.info("ItemListObjects lable: "+label);
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
