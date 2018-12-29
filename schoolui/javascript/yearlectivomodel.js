
var YearlectivoModel = function(db) {
    this.db = db;
};

YearlectivoModel.prototype.add = function(arr) {
    var fnt = function(tx){
        tx.executeSql( "INSERT INTO year_lectivo (year)"+
                      " VALUES (?);", arr);
        console.log("Yearlectivo agregado correctamente.");
    };
    this.db.transaction(fnt);
};

YearlectivoModel.prototype.find = function(){
    var _rst;
    var fnt = function(tx){
        _rst = tx.executeSql("SELECT * FROM year_lectivo;");
    };
    this.db.transaction(fnt);
    return _rst;
};

YearlectivoModel.prototype.findById = function(id){
    var _rst;
    var fnt = function(tx){
        try{
            _rst = tx.executeSql("SELECT * FROM year_lectivo WHERE id = "+id+";");
        }catch(err){
            console.error(err);
        }
        if(_rst.rows.length === 0) throw "No existe el elemento";
    };
    this.db.transaction(fnt);
    return _rst.rows.item(0);
};

YearlectivoModel.prototype.updateById = function(id, obj){
    var _rst;
    var fnt = function(tx){
        var strSql ="UPDATE year_lectivo SET ";
        Object.keys(obj).forEach(function(key) {
            strSql += key +" = "+obj[key]+", ";
        });
        strSql = strSql.slice(0, strSql.length-2);
        strSql += " WHERE id = "+id+";";
        _rst = tx.executeSql( strSql );
    };
    this.db.transaction(fnt);
    return _rst;
};
