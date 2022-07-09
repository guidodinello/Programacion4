#include "../include/DTRespuesta.hh"

DTRespuesta::DTRespuesta(const string& comentario, const DTEmpleado& empleado, const DTFecha& fechaCom) : 
    comentario(comentario),
    empleado(empleado),
    fechaComentario(fechaCom)
{}

string DTRespuesta::getComentario() const {
    return comentario;
}

DTEmpleado DTRespuesta::getEmpleado() const {
    return empleado;
}

DTFecha DTRespuesta::getFechaComentario() const {
    return fechaComentario;
}

DTRespuesta::~DTRespuesta(){
    
}