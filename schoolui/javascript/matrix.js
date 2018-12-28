
var Matrix = function(){}

Matrix.prototype.grado = {
    fieldTypes:{ciclo:"string", nivel:"string", ordinal:"string"},
    rows:[
        {ciclo:"I",nivel:"Inicial",ordinal:"2"},
        {ciclo:"I",nivel:"Inicial",ordinal:"3"},
        {ciclo:"II",nivel:"Inicial",ordinal:"4"},
        {ciclo:"II",nivel:"Inicial",ordinal:"5"},
        {ciclo:"III",nivel:"Primaria",ordinal:"1"},
        {ciclo:"III",nivel:"Primaria",ordinal:"2"},
        {ciclo:"IV",nivel:"Primaria",ordinal:"3"},
        {ciclo:"IV",nivel:"Primaria",ordinal:"4"},
        {ciclo:"V",nivel:"Primaria",ordinal:"5"},
        {ciclo:"V",nivel:"Primaria",ordinal:"6"},
        {ciclo:"VI",nivel:"Secundaria",ordinal:"1"},
        {ciclo:"VI",nivel:"Secundaria",ordinal:"2"},
        {ciclo:"VII",nivel:"Secundaria",ordinal:"3"},
        {ciclo:"VII",nivel:"Secundaria",ordinal:"4"},
        {ciclo:"VII",nivel:"Secundaria",ordinal:"5"}
    ]
};

Matrix.prototype.asignatura = {
    fieldTypes:{detalle:"string",descripcion:"string"},
    rows:[
        {detalle:"Área de Personal Social", descripcion:""},
        {detalle:"Educación Física", descripcion:""},
        {detalle:"Arte y Cultura", descripcion:""},
        {detalle:"Comunicación", descripcion:""},
        {detalle:"Castellano como segunda lengua", descripcion:""},
        {detalle:"Inglés como lengua extranjera", descripcion:""},
        {detalle:"Matemática", descripcion:""},
        {detalle:"Ciencia y Tecnología", descripcion:""},
        {detalle:"Educación Religiosa", descripcion:""},
        {detalle:"Desarrollo Personal, Ciudadanía y Cívica", descripcion:""},
        {detalle:"Ciencias sociales", descripcion:""},
        {detalle:"Educación para el Trabajo", descripcion:""}
    ]
};
