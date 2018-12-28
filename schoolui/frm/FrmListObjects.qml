import QtQuick 2.9
import QtQuick.Controls 2.4
import "../components" as Cmp

Item {
    id: frmListObjects

    property string tableName
    property var fields:[]
    property int longPage: 10
    property int currentPage: 0
    property int countPage
    property alias list: listView
    property var model
    property string format

    Component.onCompleted: {
        var tableLength = model.length();
        countPage = Math.ceil( tableLength/longPage );
        console.info("Table length: " + tableLength);
        lblTotalPage.text = " / " + countPage;
    }

    function loadData() {
        objectList.clear();
        var result_objects = model.find(fields, longPage, currentPage);
        var lng = result_objects.rows.length;
        for (var i = 0; i < lng; i++) {
            var pasador = format;
            var _row = result_objects.rows[i];
            Object.keys(_row).forEach(function(prop){
                pasador = pasador.replace("$"+prop, _row[prop], "gi");
            });
            objectList.append( {label: pasador} );
        }
    }

//    width: parent.width
//    height: 350


    ListView {
        id: listView
        clip: true
        anchors.fill: parent
        anchors.bottomMargin: 50

        highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
        focus: true

        model: ListModel { id: objectList }

        delegate: Cmp.ItemListObjects{}

        ScrollIndicator.vertical: ScrollIndicator { }
    }

    Item {
        id: _top_frmListObjects
        x: 0; y: parent.height-_top_frmListObjects.height
        width: parent.width
        height: 50


        TextInput {
            id: textInput
            x: 320
            y: 5
            width: 40
            height: 30
            text: qsTr( (1+currentPage).toString() )
            renderType: Text.NativeRendering
            antialiasing: true
            horizontalAlignment: Text.AlignRight
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 12
            anchors.horizontalCenterOffset: -20
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Text {
            id: lblTotalPage
            x: 320
            y: 5
            width: 40
            height: 30
            text: qsTr("/NN")
            anchors.horizontalCenterOffset: 20
            anchors.horizontalCenter: parent.horizontalCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 12
        }

        Button {
            id: btnPrePage
            x: 260
            y: 5
            width: 40
            text: qsTr("<<")
            anchors.horizontalCenterOffset: -60
            anchors.horizontalCenter: parent.horizontalCenter

            onClicked: {
                if( currentPage > 0 ) {
                    currentPage -= 1;
                    loadData();
                }
            }
        }

        Button {
            id: btnPosPage
            x: 260
            y: 5
            width: 40
            text: qsTr(">>")
            anchors.horizontalCenterOffset: 60
            anchors.horizontalCenter: parent.horizontalCenter

            onClicked: {
                if( currentPage < countPage-1 ) {
                    currentPage += 1;
                    loadData();
                }
            }
        }

        Button {
            id: btnReload
            y: 5
            width: 40
            display: AbstractButton.IconOnly
            anchors.right: parent.right
            anchors.rightMargin: 5
            icon.source: "../img/reload.png"
            icon.color: "transparent"
            icon.height: 32; icon.width: 32

            onClicked: {
                loadData();
            }
        }

    }

}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
