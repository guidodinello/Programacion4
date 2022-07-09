#include "../include/DTResena.hh"

#include <string>
using std::string;

DTResena::DTResena(int calificacion, const string& comentario, const DTFecha& fechaCal, const DTHuesped& dthuesped, int codReserva) : 
    calificacion(calificacion),
    comentario(comentario),
    fechaCal(fechaCal),
    huesped(dthuesped),
    codReserva(codReserva)
{}

int DTResena::getCalificacion() const {
    return calificacion;
}

string DTResena::getComentario() const {
    return comentario;
}

DTFecha DTResena::getFechaCal() const {
    return fechaCal;
}

DTHuesped DTResena::getHuesped() const {
    return huesped;
}

int DTResena::getCodReserva() const {
    return codReserva;
}

DTResena::~DTResena(){
    
}

bool DTResena::operator<(const DTResena& other) const{
  return true;
}
