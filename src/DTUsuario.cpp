#include "../include/DTUsuario.hh"

/*
DTUsuario::DTUsuario(const string& nombre, const string& mail) : 
    nombre(nombre),
    mail(mail)
{}
*/

string DTUsuario::getNombre() const {
    return nombre;
}

string DTUsuario::getMail() const {
    return mail;
}

DTUsuario::~DTUsuario() {}
