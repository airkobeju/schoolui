
var AlumnoModel = function(db) {
    this.db = db;
};

AlumnoModel.prototype.add = function(arr) {
    var fnt = function(tx){
        tx.executeSql( "INSERT INTO alumno (apellido, nombre, dni, nacimiento)"+
                      " VALUES (?, ?, ?, ?);", arr);
        console.log("Alumno agregado correctamente.");
    };
    this.db.transaction(fnt);
};

AlumnoModel.prototype.addFromObject = function(obj) {
    var strSql ="";
    for(var i=0;i<obj.length;i++) {
        strSql = "INSERT INTO alumno (apellido, nombre, dni, nacimiento) ";
        var _apellido = obj[i].apellido === undefined? "null": obj[i].apellido;
        var _nombre = obj[i].nombre === undefined? "null": obj[i].nombre;
        var _dni = obj[i].dni === undefined? "null": obj[i].dni;
        var _nacimiento = obj[i].nacimiento === undefined? "null": obj[i].nacimiento;

        strSql += "VALUES (\""+_apellido+"\", \""+ _nombre+"\", \""+ _dni+"\","+ _nacimiento+");";

        this.db.transaction(function(tx){
            //TODO: arreglar UNIQUE para DNI
            tx.executeSql( strSql );
            console.log( strSql );
        });
    }
};

AlumnoModel.prototype.find = function(){
    var _rst;
    var strSql = "";
    if(arguments.length > 0) {
        var fields = arguments[0];
        var longPage = arguments[1];
        var currentPage = arguments[2];

        strSql += "SELECT ";
        strSql += fields[0];
        for(var i=1; i<fields.length;i++) {
            strSql += ", "+fields[i];
        }
        var star = longPage * currentPage;
        strSql += " FROM alumno LIMIT "+star+", "+longPage+";";
    }else{
        strSql = "SELECT * FROM alumno;";
    }
    var fnt = function(tx){
        _rst = tx.executeSql(strSql);
    };
    this.db.transaction(fnt);
    return _rst;
};

AlumnoModel.prototype.findById = function(id){
    var _rst;
    var fnt = function(tx){
        try{
            _rst = tx.executeSql("SELECT * FROM alumno WHERE id = "+id+";");
        }catch(err){
            console.error(err);
        }
        if(_rst.rows.length === 0) throw "No existe el elemento";
    };
    this.db.transaction(fnt);
    return _rst.rows.item(0);
};

AlumnoModel.prototype.findByDni = function(dni){
    var _rst;
    var fnt = function(tx){
        _rst = tx.executeSql("SELECT * FROM alumno WHERE dni = \""+dni+"\";");
        if(_rst.rows.length === 0) throw "No existe el elemento";
    };
    this.db.transaction(fnt);
    return _rst.rows.item(0);
};

AlumnoModel.prototype.updateById = function(id, obj){
    var _rst;
    var fnt = function(tx){
        var strSql ="UPDATE alumno SET ";
        Object.keys(obj).forEach(function(key) {
            strSql += key +" = \""+obj[key]+"\", ";
        });
        strSql = strSql.slice(0, strSql.length-2);
        strSql += " WHERE id = "+id+";";
        _rst = tx.executeSql( strSql );
    };
    this.db.transaction(fnt);
    return _rst;
};

AlumnoModel.prototype.length = function() {
    var _rst;
    var strSql = "SELECT count(*) as \"length\" FROM alumno;";

    var fnt = function(tx){
        _rst = tx.executeSql(strSql);
    };
    this.db.transaction(fnt);
    return _rst.rows[0]["length"];
}
