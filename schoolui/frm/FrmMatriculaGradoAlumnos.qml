import QtQuick 2.9
import QtQuick.Controls 2.4
import "../components" as Cmp

Item {
    id: frmMatriculaGradoAlumnos

    ComboBox {
        id: cmbYearLectivo
    }

    ComboBox {
        id: cmbGrado
    }

    Row {
        Label {
            id: lblAlumnosLoad
            text: qsTr("Alumnos")
        }

        Button {
            id: btnAddAlumnos
            text: qsTr("+")
        }
    }

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


}
