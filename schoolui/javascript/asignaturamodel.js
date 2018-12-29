
var AsignaturaModel = function(db) {
    this.db = db;
};

AsignaturaModel.prototype.add = function(arr) {
    var fnt = function(tx){
        tx.executeSql( "INSERT INTO asignatura (detalle, descripcion)"+
                      " VALUES (?, ?);", arr);
        console.log("Asignatura agregado correctamente.");
    };
    this.db.transaction(fnt);
};

AsignaturaModel.prototype.find = function(){
    var _rst;
    var fnt = function(tx){
        _rst = tx.executeSql("SELECT * FROM asignatura;");
    };
    this.db.transaction(fnt);
    return _rst;
};

AsignaturaModel.prototype.findById = function(id){
    var _rst;
    var fnt = function(tx){
        try{
            _rst = tx.executeSql("SELECT * FROM asignatura WHERE id = "+id+";");
        }catch(err){
            console.error(err);
        }
        if(_rst.rows.length === 0) throw "No existe el elemento";
    };
    this.db.transaction(fnt);
    return _rst.rows.item(0);
};

AsignaturaModel.prototype.updateById = function(id, obj){
    var _rst;
    var fnt = function(tx){
        var strSql ="UPDATE asignatura SET ";
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
