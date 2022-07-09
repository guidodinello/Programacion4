#include "../include/DTEmpleado.hh"

DTEmpleado::DTEmpleado(string nombre,  string mail, TipoCargo cargo,/* DTHostal hostal,*/bool suscrito) {
    this->nombre = nombre;
    this->mail = mail;
    this->cargo = cargo;
    this->suscrito = suscrito;
    //hostal ver 
}

TipoCargo DTEmpleado::getCargo() const {
    return cargo;
}
     /*   DTHostal DTEmpleado::getHostal(){
            return hostal;
        }*/
bool DTEmpleado::getSuscrito() const {
    return suscrito;
}

string DTEmpleado::getNombre() const { return nombre; }
string DTEmpleado::getMail() const { return mail; }

bool DTEmpleado::operator<(const DTEmpleado& other) const{
    return true;
}

//#include <iostream>
DTEmpleado::~DTEmpleado(){
    //std::cout << "destruyendo DTEmpleado" << std::endl;
}