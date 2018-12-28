import QtQuick 2.9
import QtQuick.Controls 2.4

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




}
