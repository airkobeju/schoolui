
Qt.include("alumnomodel.js");
Qt.include("gradomodel.js");
Qt.include("asignaturamodel.js");
Qt.include("yearlectivomodel.js");
Qt.include("matriculamodel.js");
Qt.include("cursomodel.js");
Qt.include("sesionmodel.js");
Qt.include("asistenciamodel.js");
Qt.include("competenciamodel.js");
Qt.include("capacidadmodel.js");
Qt.include("desempenomodel.js");
Qt.include("sesiondesempenomodel.js");

Qt.include("matrix.js");

var Database = function() {
    this.db = LocalStorage.openDatabaseSync("school", "1.0", "school database", 1073741824);
    this.AlumnoModel = new AlumnoModel(this.db);
    this.GradoModel = new GradoModel(this.db);
    this.AsignaturaModel = new AsignaturaModel(this.db);
    this.YearlectivoModel = new YearlectivoModel(this.db);
    this.MatriculaModel = new MatriculaModel(this.db);
    this.CursoModel = new CursoModel(this.db);
    this.SesionModel = new SesionModel(this.db);
    this.AsistenciaModel = new AsistenciaModel(this.db);
    this.CompetenciaModel = new CompetenciaModel(this.db);
    this.CapacidadModel = new CapacidadModel(this.db);
    this.DesempenoModel =new DesempenoModel(this.db);
    this.SesionDesempenoModel = new SesionDesempenoModel(this.db);
}

Database.prototype.createStructure=function(){
    var tblAlumno = this.tablesArr["alumno"];
    var tblGrado = this.tablesArr["grado"];
    var tblAsignatura = this.tablesArr["asignatura"];
    var tblYearlectivo = this.tablesArr["year_lectivo"];
    var tblMatricula = this.tablesArr["matricula"];
    var tblCurso = this.tablesArr["curso"];
    var tblSesion = this.tablesArr["sesion"];
    var tblAsistencia = this.tablesArr["asistencia"];
    var tblCompetencia = this.tablesArr["competencia"];
    var tblCapacidad = this.tablesArr["capacidad"];
    var tblDesempeno = this.tablesArr["desempeno"];
    var tblSesionDesempeno = this.tablesArr["sesion_desempeno"];

    this.db.transaction(
             function(tx) {
                 tx.executeSql( "PRAGMA foreign_keys = off;" );
                 tx.executeSql( dropTable("alumno") );
                 tx.executeSql( tblAlumno );
                 tx.executeSql( dropTable("grado") );
                 tx.executeSql( tblGrado );
                 tx.executeSql( dropTable("asignatura") );
                 tx.executeSql( tblAsignatura );
                 tx.executeSql( dropTable("year_lectivo") );
                 tx.executeSql( tblYearlectivo );
                 tx.executeSql( dropTable("matricula") );
                 tx.executeSql( tblMatricula );
                 tx.executeSql( dropTable("curso") );
                 tx.executeSql( tblCurso );
                 tx.executeSql( dropTable("sesion") );
                 tx.executeSql( tblSesion );
                 tx.executeSql( dropTable("asistencia") );
                 tx.executeSql( tblAsistencia );
                 tx.executeSql( dropTable("competencia") );
                 tx.executeSql( tblCompetencia );
                 tx.executeSql( dropTable("capacidad") );
                 tx.executeSql( tblCapacidad );
                 tx.executeSql( dropTable("desempeno") );
                 tx.executeSql( tblDesempeno );
                 tx.executeSql( dropTable("sesion_desempeno") );
                 tx.executeSql( tblSesionDesempeno );
                 tx.executeSql( "PRAGMA foreign_keys = on;" );

                 console.info("Tabla creada correctamente.");
             }
             );
}

Database.prototype.populateMatrix=function() {
    var insertArr = [];
    var matrix = new Matrix();

    //grado
    matrix.grado.rows.forEach(function(o){
        insertArr.push(makeInsert(o, matrix.grado.fieldTypes, "grado"));
    });
    //asignatura
    matrix.asignatura.rows.forEach(function(o){
        insertArr.push(makeInsert(o, matrix.asignatura.fieldTypes, "asignatura"));
    });

    this.db.transaction(
             function(tx){
                 insertArr.forEach(function(o){
                     console.info(o);
                     tx.executeSql( o );
                 });
             });
};

Database.prototype.tablesArr = {
    "alumno" : "CREATE TABLE alumno ( id         INTEGER      PRIMARY KEY AUTOINCREMENT,  apellido   STRING (100) NOT NULL,   nombre     STRING (100) NOT NULL,  dni        STRING (10)  UNIQUE,  nacimiento DATE);",
    "grado" : "CREATE TABLE grado ( id      INTEGER     PRIMARY KEY AUTOINCREMENT, ciclo   STRING (30) NOT NULL, nivel   STRING (30) NOT NULL, ordinal STRING (30) NOT NULL);",
    "asignatura" : "CREATE TABLE asignatura ( id          INTEGER      PRIMARY KEY AUTOINCREMENT,    detalle     STRING (100) NOT NULL,  descripcion TEXT);",
    "year_lectivo" : "CREATE TABLE year_lectivo ( id   INTEGER PRIMARY KEY AUTOINCREMENT,  year INTEGER NOT NULL );",
    "matricula" : "CREATE TABLE matricula (  id    INTEGER     PRIMARY KEY AUTOINCREMENT, codigo   STRING (20),  alumno_id      INTEGER     REFERENCES alumno (id),  grado_id       INTEGER   REFERENCES grado (id),  yearlectivo_id INTEGER     REFERENCES year_lectivo (id) );",
    "curso" : "CREATE TABLE curso ( id  INTEGER PRIMARY KEY AUTOINCREMENT, asignatura_id INTEGER REFERENCES asignatura (id), grado_id INTEGER REFERENCES grado (id), detalle  TEXT);",
    "sesion" : "CREATE TABLE sesion ( id INTEGER      PRIMARY KEY AUTOINCREMENT, titulo  STRING (100) NOT NULL, recurso_metodologico STRING (100), fecha   DATE         NOT NULL, secuencia_didactica  TEXT, curso_id  INTEGER      REFERENCES curso (id)  );",
    "asistencia" : "CREATE TABLE asistencia ( id INTEGER PRIMARY KEY AUTOINCREMENT, sesion_id  INTEGER REFERENCES sesion (id), alumno_id  INTEGER REFERENCES alumno (id), is_present BOOLEAN DEFAULT (false)  );",
    "competencia" : "CREATE TABLE competencia ( id INTEGER PRIMARY KEY AUTOINCREMENT, descripcion TEXT, detalle TEXT, yearlectivo_id INTEGER REFERENCES year_lectivo (id)  );",
    "capacidad" : "CREATE TABLE capacidad (id INTEGER PRIMARY KEY AUTOINCREMENT, descripcion TEXT, detalle TEXT, competencia_id INTEGER REFERENCES competencia (id) );",
    "desempeno" : "CREATE TABLE desempeno (id INTEGER PRIMARY KEY AUTOINCREMENT, descripcion  TEXT, detalle TEXT, capacidad_id INTEGER REFERENCES capacidad (id) );",
    "sesion_desempeno" : " CREATE TABLE sesion_desempeno (id INTEGER PRIMARY KEY AUTOINCREMENT, sesion_id    INTEGER REFERENCES sesion (id), desempeno_id INTEGER REFERENCES desempeno (id) );"
}

function dropTable(name){
    return "DROP TABLE IF EXISTS "+name+";";
}

function ExceptionDb(msj){
    this.message = msj;
}

function makeInsert(obj_data, obj_fieldtype, table_name){
    var keys = Object.keys(obj_fieldtype);
    var strSql = "INSERT INTO " + table_name + " (";

    strSql += keys[0];
    for(var i=1; i<keys.length;i++){
        strSql += ", "+keys[i];
    }
    strSql += ") VALUES (";
    for(var x = 0; x < keys.length; x++){
        if(obj_fieldtype[keys[x]] === "string") {
            strSql += "\""+ obj_data[keys[x]] +"\",";
        }else if(obj_fieldtype[keys] === "number") {
            strSql += obj_data[keys[x]] +",";
        }
    }
    strSql = strSql.slice(0, -1);
    strSql += ");";
    return strSql;
}
