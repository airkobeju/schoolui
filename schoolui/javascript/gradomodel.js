
var GradoModel = function(db){
    this.db = db;

    this.id = 0;
    this.ciclo="";
    this.nivel="";
    this.ordinal="";
};

GradoModel.prototype.find=function(){
    var _rst;
    var fnt = function(tx){
        _rst = tx.executeSql("SELECT * FROM grado;");
    };
    this.db.transaction(fnt);
    return _rst;
};

GradoModel.prototype.findById=function(id){
    var _rst;
    var fnt = function(tx){
        try{
            _rst = tx.executeSql("SELECT * FROM grado WHERE id = "+id+";");
        }catch(err){
            console.error(err);
        }
        if(_rst.rows.length === 0) throw "No existe el elemento";
    };
    this.db.transaction(fnt);
    return _rst.rows.item(0);
};

GradoModel.prototype.add=function(arr){
    var fnt = function(tx){
        tx.executeSql( "INSERT INTO grado (ciclo, nivel, ordinal)"+
                      " VALUES (?, ?, ?);", arr);
        console.log("Grado agregado correctamente.");
    };
    this.db.transaction(fnt);
};

GradoModel.prototype.updateById=function(id, obj){
    var _rst;
    var fnt = function(tx){
        var strSql ="UPDATE grado SET ";
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
