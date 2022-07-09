#include "../include/DTHuesped.hh"

DTHuesped::DTHuesped(const string nom, const string ma, bool esF) {
    nombre = nom;
    mail = ma; 
    esFinger = esF;
}

bool DTHuesped::getEsFinger() const {
    return esFinger;
}

string DTHuesped::getNombre() const { return nombre; }
string DTHuesped::getMail() const { return mail; }

bool DTHuesped::operator<(const DTHuesped& other) const{
    return true;
}

DTHuesped::~DTHuesped(){
    
}