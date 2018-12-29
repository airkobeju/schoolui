
var SesionDesempenoModel = function(db) {
    this.db = db;
};

SesionDesempenoModel.prototype.add = function(arr) {
    var fnt = function(tx){
        tx.executeSql( "INSERT INTO sesion_desempeno (sesion_id, desempeno_id)"+
                      " VALUES (?, ?);", arr);
        console.log("Sesion-Desempeño agregado correctamente.");
    };
    this.db.transaction(fnt);
};

SesionDesempenoModel.prototype.find = function(){
    var _rst;
    var fnt = function(tx){
        _rst = tx.executeSql("SELECT * FROM sesion_desempeno;");
    };
    this.db.transaction(fnt);
    return _rst;
};

SesionDesempenoModel.prototype.findById = function(id){
    var _rst;
    var fnt = function(tx){
        try{
            _rst = tx.executeSql("SELECT * FROM sesion_desempeno WHERE id = "+id+";");
        }catch(err){
            console.error(err);
        }
        if(_rst.rows.length === 0) throw "No existe el elemento";
    };
    this.db.transaction(fnt);
    return _rst.rows.item(0);
};

SesionDesempenoModel.prototype.updateById = function(id, obj){
    var _rst;
    var fnt = function(tx){
        var strSql ="UPDATE sesion_desempeno SET ";
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
