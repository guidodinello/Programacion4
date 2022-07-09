#include "../include/DTNotificacion.hh"

DTNotificacion::DTNotificacion(const string& autor, int calificacion, const string& comentario) : 
    autor(autor), 
    calificacion(calificacion), 
    comentario(comentario) 
{}

string DTNotificacion::getAutor() const{ return autor;}
int DTNotificacion::getCalificacion() const{ return calificacion;}
string DTNotificacion::getComentario() const{ return comentario;}

bool DTNotificacion::operator<(const DTNotificacion& other) const{
    return true;
}

DTNotificacion::~DTNotificacion() {}