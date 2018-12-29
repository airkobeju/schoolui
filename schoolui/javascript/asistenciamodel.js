
var AsistenciaModel = function(db) {
    this.db = db;
};

AsistenciaModel.prototype.add = function(arr) {
    var fnt = function(tx){
        tx.executeSql( "INSERT INTO asistencia (sesion_id, alumno_id, is_present)"+
                      " VALUES (?, ?, ?);", arr);
        console.log("Asistencia agregado correctamente.");
    };
    this.db.transaction(fnt);
};

AsistenciaModel.prototype.find = function(){
    var _rst;
    var fnt = function(tx){
        _rst = tx.executeSql("SELECT * FROM asistencia;");
    };
    this.db.transaction(fnt);
    return _rst;
};

AsistenciaModel.prototype.findById = function(id){
    var _rst;
    var fnt = function(tx){
        try{
            _rst = tx.executeSql("SELECT * FROM asistencia WHERE id = "+id+";");
        }catch(err){
            console.error(err);
        }
        if(_rst.rows.length === 0) throw "No existe el elemento";
    };
    this.db.transaction(fnt);
    return _rst.rows.item(0);
};

AsistenciaModel.prototype.updateById = function(id, obj){
    var _rst;
    var fnt = function(tx){
        var strSql ="UPDATE asistencia SET ";
        Object.keys(obj).forEach(function(key) {
            if(typeof obj[key] === "string"){
                strSql += key +" = \""+obj[key]+"\", ";
            }else if(typeof obj[key] === "number" || typeof obj[key] === "boolean") {
                strSql += key +" = " + obj[key] + ", ";
            }
        });
        strSql = strSql.slice(0, strSql.length-2);
        strSql += " WHERE id = "+id+";";
        _rst = tx.executeSql( strSql );
    };
    this.db.transaction(fnt);
    return _rst;
};
