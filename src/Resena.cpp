#include "../include/Resena.hh"

#include <stdexcept>
using std::invalid_argument;

Resena::Resena(const string& coment, int cal) :
    calificacion(cal), 
    comentario(coment),  
    fechaCal(DTFecha()),
    estadia(NULL),
    respuesta(NULL)
{}

int Resena::getCalificacion() const { return calificacion; }
string Resena::getComentario() const { return comentario; }
DTFecha Resena::getFechaCal() const { return fechaCal; }
Estadia* Resena::getEstadia() const { return estadia; }
Respuesta* Resena::getRespuesta() const { return respuesta; }

void Resena::setComentario(const string& comentario){
    this->comentario = comentario;
}

void Resena::setCalificacion(int calificacion){
    this->calificacion = calificacion;
}

void Resena::setFechaCal(const DTFecha& fechaCal){
    this->fechaCal = fechaCal;
}

void Resena::setEstadia(Estadia* estadia){
    this->estadia = estadia;
}

void Resena::setRespuesta(Respuesta* respuesta){
    this->respuesta = respuesta;
}

DTResena Resena::darDT(int codRes, const DTHuesped& dth) {
    return DTResena(calificacion, comentario, fechaCal, dth, codRes);
}

DTNotificacion Resena::darDTNotificacion() {
    return DTNotificacion(getEstadia()->getHuesped()->getNombre(), calificacion, comentario);
}

DTRespuesta Resena::infoRespuesta() {
    if (respuesta != NULL){
        return respuesta->darDT();
    }else 
        throw invalid_argument("No hay respuesta");
}

void Resena::comentarCalificacion(const string& comentario, Empleado* empleado){
    respuesta = new Respuesta(comentario, empleado);
}

bool Resena::sinResponder() {
    return respuesta == NULL;
}

void Resena::eliminarResena(){
    respuesta->~Respuesta();
    respuesta = NULL;
}

// sin hacer
Resena::~Resena(){

}
