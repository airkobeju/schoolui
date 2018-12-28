import QtQuick 2.9
import QtQuick.Controls 2.4

Item {
    id: item1

    TextField {
        id: txtId
        height: 40
        selectByMouse: true
        text: qsTr("")
        clip: true
        anchors.rightMargin: 50
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        placeholderText: qsTr("Id")
    }

    Button {
        id: btnLoadById
        width: 40
        height: 40
        text: qsTr("...")
        anchors.top: txtId.top
        anchors.topMargin: 0
        anchors.left: txtId.right
        anchors.leftMargin: 5

        onClicked: {
            try {
                var result = db.AlumnoModel.findById( txtId.text );
            }catch(err){
                console.error(err);
                return;
            }
            txtApellido.text = result.apellido;
            txtNombre.text = result.nombre;
            txtDni.text = result.dni;
            txtNacimiento.text = result.nacimiento;
        }
    }

    TextField {
        id: txtApellido
        height: 40
        text: qsTr("")
        clip: true
        anchors.right: parent.right
        anchors.rightMargin: 5
        anchors.left: txtId.left
        anchors.leftMargin: 0
        anchors.top: txtId.bottom
        anchors.topMargin: 5
        placeholderText: "Apellido"
        selectByMouse: true
    }

    TextField {
        id: txtNombre
        height: 40
        clip: true
        anchors.right: parent.right
        anchors.rightMargin: 5
        anchors.left: txtApellido.left
        anchors.leftMargin: 0
        anchors.top: txtApellido.bottom
        anchors.topMargin: 5
        selectByMouse: true
        placeholderText: "Nombre"
    }

    TextField {
        id: txtDni
        height: 43
        anchors.right: parent.right
        anchors.rightMargin: 50
        anchors.left: txtNombre.left
        anchors.leftMargin: 0
        anchors.top: txtNombre.bottom
        anchors.topMargin: 5
        selectByMouse: true
        placeholderText: "Dni"
    }

    Button {
        id: btnLoadByDni
        width: 40
        text: qsTr("...")
        anchors.top: txtDni.top
        anchors.topMargin: 0
        anchors.left: txtDni.right
        anchors.leftMargin: 6

        onClicked: {

            var result = db.AlumnoModel.findByDni( txtDni.text );
            if(result === undefined) return;

            txtId.text = result.id;
            txtApellido.text = result.apellido;
            txtNombre.text = result.nombre;
            txtDni.text = result.dni;
            txtNacimiento.text = result.nacimiento;
        }
    }

    TextField {
        id: txtNacimiento
        height: 40
        anchors.right: parent.right
        anchors.rightMargin: 5
        anchors.left: txtDni.left
        anchors.leftMargin: 0
        anchors.top: txtDni.bottom
        anchors.topMargin: 5
        placeholderText: "YYYY-mm-dd"
        selectByMouse: true
    }

    Button {
        id: btnGuardar
        x: 8
        y: 234
        text: qsTr("Guardar")

        onClicked: {
            if(txtId.text === ""){
                //Nuevo alumno
                db.AlumnoModel.add([txtApellido.text, txtNombre.text, txtDni.text, txtNacimiento.text]);

            }else{
                //Guardar actualización updateById = function(id, obj)
                db.AlumnoModel.updateById(txtId.text, {
                                              "apellido" : txtApellido.text,
                                              "nombre" : txtNombre.text,
                                              "dni" : txtDni.text,
                                              "nacimiento" : txtNacimiento.text
                                          });
            }
            txtId.text = "";
            txtApellido.text = "";
            txtNombre.text = "";
            txtDni.text = "";
            txtNacimiento.text = "";
        }
    }

}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
