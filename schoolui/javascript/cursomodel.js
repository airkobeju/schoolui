
var CursoModel = function(db) {
    this.db = db;
};

CursoModel.prototype.add = function(arr) {
    var fnt = function(tx){
        tx.executeSql( "INSERT INTO curso (asignatura_id, grado_id, detalle)"+
                      " VALUES ( ?, ?, ?);", arr);
        console.log("Curso agregado correctamente.");
    };
    this.db.transaction(fnt);
};

CursoModel.prototype.find = function(){
    var _rst;
    var fnt = function(tx){
        _rst = tx.executeSql("SELECT * FROM curso;");
    };
    this.db.transaction(fnt);
    return _rst;
};

CursoModel.prototype.findById = function(id){
    var _rst;
    var fnt = function(tx){
        try{
            _rst = tx.executeSql("SELECT * FROM curso WHERE id = "+id+";");
        }catch(err){
            console.error(err);
        }
        if(_rst.rows.length === 0) throw "No existe el elemento";
    };
    this.db.transaction(fnt);
    return _rst.rows.item(0);
};

CursoModel.prototype.updateById = function(id, obj){
    var _rst;
    var fnt = function(tx){
        var strSql ="UPDATE curso SET ";
        Object.keys(obj).forEach(function(key) {
            if(typeof obj[key] === "string"){
                strSql += key +" = \""+obj[key]+"\", ";
            }else if(typeof obj[key] === "number") {
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
