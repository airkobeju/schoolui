import QtQuick 2.9

Component {
    id: itemGrid
    Item {
        width: 100; height: 100
        MouseArea {
            anchors.fill: parent
            anchors.margins: 5
            Column {
                anchors.fill: parent
                anchors.margins: 5
                Image { width:60; height: 60; sourceSize.height: 60; sourceSize.width: 60
                    source: icon; anchors.horizontalCenter: parent.horizontalCenter }
                Text { color: "#000000"; text: subjet; font.family: "Arial"; anchors.horizontalCenter: parent.horizontalCenter }
            }
            onClicked: {
                parent.GridView.view.currentIndex = index;
                console.info("Subject: "+subjet);
            }
        }
    }
}
