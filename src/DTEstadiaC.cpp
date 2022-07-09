#include "../include/DTEstadiaC.hh"

DTEstadiaC::DTEstadiaC(const string& mail, const string& nombreHostal, const DTFecha& checkIn, const DTFecha& checkOut, int codReserva) : 
    mailH(mail),
    nombreHostal(nombreHostal),
    checkIn(checkIn),
    checkOut(checkOut),
    codReserva(codReserva)
{}

string DTEstadiaC::getMail() const {
    return mailH;
}

string DTEstadiaC::getNombreHostal() const {
    return nombreHostal;
}

DTFecha DTEstadiaC::getCheckIn() const {
    return checkIn;
}

DTFecha DTEstadiaC::getCheckOut() const {
    return checkOut;
}

int DTEstadiaC::getCodReserva() const {
    return codReserva;
}

bool DTEstadiaC::operator<(const DTEstadiaC& other) const {
    return true;
}


DTEstadiaC::~DTEstadiaC(){
    
}
