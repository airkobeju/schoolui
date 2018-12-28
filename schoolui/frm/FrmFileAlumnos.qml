import QtQuick 2.9
import SchoolUI.Utils 1.0

Item {
    id: frmFileAlumnos

    FileIO {
        id: fileIO
        onError: console.log(msg)
    }

    DropArea {

        anchors.fill: parent


        onDropped: {
            fileIO.source = drop.text;
            var strjson = fileIO.read();
            var alumnosObj = JSON.parse( strjson );

            db.AlumnoModel.addFromObject(alumnosObj);

            console.info( alumnosObj.length );
        }

    }

}
