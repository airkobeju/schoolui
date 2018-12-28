import QtQuick 2.9
import QtQuick.Controls 2.4

Item {
    id: databaseController

    Button {
        id: btnResetDB
        x: 8
        y: 8
        text: qsTr("Reiniciar DataBase")
    }

    Button {
        id: btnLoadMatrix
        x: 135
        y: 8
        text: qsTr("Cargar Matrices")

        onClicked: {
            db.populateMatrix();
        }
    }

    TextField {
        id: txtYearLectivo
        x: 8
        y: 54
        width: 120
        height: 40
        text: qsTr("")
        placeholderText: qsTr("Año Lectivo")
        renderType: Text.NativeRendering
    }

    Button {
        id: btnSaveYearLectivo
        x: 135
        y: 54
        width: 80
        height: 40
        text: qsTr("Guardar")

        onClicked: {
            db.YearlectivoModel.add([Number(txtYearLectivo.text)]);
        }
    }

}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
