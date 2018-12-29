import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.LocalStorage 2.0
import QtQuick.Controls 2.4
import QtQuick.Controls.Material 2.3

import "qrc:/javascript/database.js" as Dbase
import "../components" as Cmp
import "../frm" as Form
import "qrc:/../img"

ApplicationWindow {
    id: window

    property var db: new Dbase.Database();

    Component.onCompleted: {
        //frmListObjects.loadData();
        frmListAlumno.loadData();
    }

    Material.theme: Material.Dark
    visible: true
    width: 854
    height: 480
    title: qsTr("Hello World")

    Drawer {
        id: drawer
        y: 0
        width: 240
        height: window.height
        dragMargin: 20

        modal: true
        interactive: true
        visible: false

        ListView {
            id: listView
            anchors.fill: parent

            highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
            focus: true

            headerPositioning: ListView.OverlayHeader

            header: Pane {
                id: header
                z: 2
                width: parent.width

                contentHeight: logo.height

                Image {
                    id: logo
                    width: parent.width - 120
                    anchors.horizontalCenter: parent.horizontalCenter
                    source: "../img/school.png"
                    fillMode: implicitWidth > width ? Image.PreserveAspectFit : Image.Pad
                }

                MenuSeparator {
                    parent: header
                    width: parent.width
                    anchors.verticalCenter: parent.bottom
                    visible: !listView.atYBeginning
                }
            }

            footer: ItemDelegate {
                id: footer
                text: qsTr("Footer")
                width: parent.width

                MenuSeparator {
                    parent: footer
                    width: parent.width
                    anchors.verticalCenter: parent.top
                }
            }

            model: ListModel {
                ListElement{
                    label: "Cursos"
                    fnt: function(){
                        _swipeViewMain.setCurrentIndex(0);
                    }
                }
                ListElement{
                    label: "Alumnos Formulario"
                    fnt: function(){
                        _swipeViewMain.setCurrentIndex(1);
                    }
                }
                ListElement{
                    label: "Configuración Base de Datos"
                    fnt: function(){
                        _swipeViewMain.setCurrentIndex(2);
                    }
                }
                ListElement{
                    label: "Cargar Archivo de Alumnos"
                    fnt: function(){
                        _swipeViewMain.setCurrentIndex(3);
                    }
                }
                ListElement{
                    label: "Item 5"
                    fnt: function(){
                        _swipeViewMain.setCurrentIndex(4);
                    }
                }
                ListElement{
                    label: "Item 6"
                    fnt: function(){
                        _swipeViewMain.setCurrentIndex(5);
                    }
                }
                ListElement{
                    label: "Item 7"
                    fnt: function(){
                        _swipeViewMain.setCurrentIndex(6);
                    }
                }
                ListElement{
                    label: "Item 8"
                    fnt: function(){
                        _swipeViewMain.setCurrentIndex(7);
                    }
                }
                ListElement{
                    label: "Item 9"
                    fnt: function(){
                        _swipeViewMain.setCurrentIndex(8);
                    }
                }
                ListElement{
                    label: "Item 10"
                    fnt: function(){
                        _swipeViewMain.setCurrentIndex(9);
                    }
                }
                ListElement{
                    label: "Item 11"
                    fnt: function(){
                        _swipeViewMain.setCurrentIndex(10);
                    }
                }
            }

            delegate: Cmp.ItemDrawer {}

            ScrollIndicator.vertical: ScrollIndicator { }
        }
    }

    SwipeView {
        id: _swipeViewMain
        anchors.fill: parent
        orientation: Qt.Vertical

        Item {
            GridView {
                id: _grid
                anchors.fill: parent
                anchors.margins: 20
                cellWidth: 100; cellHeight: 100
                //TODO: Cargar con los datos de los cursos reales.
                model: ListModel {

                    ListElement {
                        subjet: "Comunicación"
                        icon: "qrc:/img/comunicacion_icon.png"
                    }
                    ListElement {
                        subjet: "Computación"
                        icon: "qrc:/img/computacion_icon.png"
                    }
                    ListElement {
                        subjet: "Ed. Física"
                        icon: "qrc:/img/icon_sports.png"
                    }
                    ListElement {
                        subjet: "Matemática"
                        icon: "qrc:/img/math_icon.png"
                    }
                }
                delegate: Cmp.ItemGrid {}
                highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
                focus: true
            }

        }

        Item {
            id: pnlAlumno

            Cmp.SwipeCheckButton {
                id: swipeCheckButton
                currentIndex: swipeAlumno.currentIndex
            }

            SwipeView {
                id: swipeAlumno
                x: 0
                y: 50
                currentIndex: swipeCheckButton.currentIndex
                orientation: Qt.Horizontal
                anchors.fill: parent
                anchors.topMargin: 50

                Form.FrmSaveAlumno {
                    id: frmSaveAlumno
                }

                Form.FrmListObjects {
                    id: frmListAlumno
                    tableName: "alumno"
                    fields: ["id", "apellido", "nombre"]
                    longPage: 10
                    model: db.AlumnoModel
                    format: "[$id] - $apellido, $nombre" //Ej: Ticona Verdeguer, Mia Mauren
                }

            }

        }

//        Form.FrmListObjects {
//            id: frmListObjects
//        }

        Cmp.DatabaseController {
            id: databaseController
        }

        Form.FrmFileAlumnos {
            id: frmFileAlumnos
        }

        onCurrentIndexChanged: {
            listView.currentIndex = _swipeViewMain.currentIndex;
        }

    }

//    Button {
//        id: button
//        x: 8
//        y: 25
//        width: 205
//        height: 76
//        text: qsTr("Create DB")

//        onClicked: {
//            db.createStructure();
//        }

//    }





}
