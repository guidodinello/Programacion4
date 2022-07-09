#include "../include/DTEstadiaL.hh"

DTEstadiaL::DTEstadiaL(const DTFecha& cI, const DTFecha& cO, const string& mailHuesped, const string& nombreHostal, int numeroHab, bool terminada, float totalConsumo, int codigoReserva){
    this->checkIn = cI;
    this->checkOut = cO;
    this->mailHuesped = mailHuesped;
    this->nombreHostal = nombreHostal;
    this->numeroHab = numeroHab;
    this->terminada = terminada;
    this->totalConsumo = totalConsumo;
    this->codigoReserva = codigoReserva;
}

DTFecha DTEstadiaL::getCheckIn() const {return checkIn; }
DTFecha DTEstadiaL::getCheckOut() const {return checkOut; }
string DTEstadiaL::getMailHuesped() const {return mailHuesped; }
string DTEstadiaL::getNombreHostal() const {return nombreHostal; }
int DTEstadiaL::getNumeroHab() const {return numeroHab; }
bool DTEstadiaL::getTerminada() const {return terminada; }
float DTEstadiaL::getTotalConsumo() const {return totalConsumo; }
int DTEstadiaL::getCodigoReserva() const {return codigoReserva; }

bool DTEstadiaL::operator<(const DTEstadiaL& other) const{
    return true;
}

DTEstadiaL::~DTEstadiaL(){}