#include "../include/Estadia.hh"

#include <stdexcept>
using std::invalid_argument;

map<string, IObserver*> Estadia::suscriptos = {};

Estadia::Estadia(const DTFecha& cI, const DTFecha& cO, bool ter, Reserva* r, Huesped* h) : 
    checkIn(cI),
    checkOut(cO), 
    terminada(ter), 
    resena(NULL), 
    huesped(h), 
    reserva(r)
{} 

DTFecha Estadia::getCheckIn() const { return checkIn; };
DTFecha Estadia::getCheckOut() const { return checkOut; };
bool Estadia::getTerminada() const { return terminada; };
Resena* Estadia::getResena() const { return resena; };
Huesped* Estadia::getHuesped() const { return huesped; };
Reserva* Estadia::getReserva() const { return reserva; };

DTEstadiaC Estadia::darDTC(const string& mailH, const string& nombreHostal, int codigoReserva){
    return DTEstadiaC(mailH, nombreHostal, checkIn, checkOut, codigoReserva);
}

/*
DTResena Estadia::mostrarResena(){
    if (resena != NULL){
        DTUsuario* us = huesped->darDT();
        DTHuesped* h = dynamic_cast<DTHuesped*>(us);
        return resena->darDT(reserva->getCodigo(), *h);
    }
    else
        throw invalid_argument("No hay resena para esta estadia");
}
*/

bool Estadia::esHostal(const string& nombreHostal) {
    Habitacion * hab = reserva->getHabitacion();
    Hostal* host = hab->getHostal();
    string n =  host->getNombre();
    return (nombreHostal == n);
}

void Estadia::finalizarEstadia(){
    terminada = true;
    checkOut = DTFecha();
}

bool Estadia::noTieneResena() { return resena == NULL; };
int Estadia::darCodReserva() { return reserva->getCodigo(); };

void Estadia::crearResena(const string& comentario, int calificacion) { 
    
    resena = new Resena(comentario, calificacion);
    resena->setFechaCal(DTFecha());
    resena->setEstadia(this);
    if (reserva == NULL) {throw invalid_argument("Estadia no tiene reserva asociada");}
    reserva->actualizarPromedioHostal(calificacion);
    for (auto it = Estadia::suscriptos.begin(); it != Estadia::suscriptos.end(); ++it){ //suscriptos no le sirve
        it->second->notificar(resena);
    }
};

DTResena Estadia::darResenaSinResponder(int codRes){
    DTUsuario* us = huesped->darDT();
    DTHuesped* h = dynamic_cast<DTHuesped*>(us);
    return resena->darDT(codRes, *h);
}

bool Estadia::esReservaEstadia(int codigoReserva) {
    return reserva->getCodigo() == codigoReserva;
}

void Estadia::comentarCalificacion(const string& comentario, Empleado* empleado) {
    if (resena == NULL) {throw invalid_argument("No hay resena para esta estadia");}
    resena->comentarCalificacion(comentario, empleado);
}

DTResena Estadia::infoComentario() {
    DTUsuario* us = huesped->darDT();
    DTHuesped* h = dynamic_cast<DTHuesped*>(us);
    int cod = reserva->getCodigo();
    return resena->darDT(cod, *h);
}

DTRespuesta Estadia::infoRespuesta(){
    return resena->infoRespuesta();
}

void Estadia::eliminarEstadia(){
    huesped->eliminarLinkEstadia(this);
    if (resena != NULL){
        resena->eliminarResena();
        delete resena;
        resena = NULL;
    }
    for (auto it = consumiciones.begin(); it != consumiciones.end(); ++it){
        consumiciones.erase(it);
        delete *it;
    }
    consumiciones.clear();
}

DTResena Estadia::darResena(int codReserva){
    if (resena != NULL) {
        DTUsuario* us = huesped->darDT();
        DTHuesped* h = dynamic_cast<DTHuesped*>(us);
        return resena->darDT(codReserva, *h);
    }
    else
        throw invalid_argument("No hay resena para esta estadia");
}

DTEstadiaL Estadia::darDTL(const string& mailH, int codigoReserva){
    int idHabitacion = reserva->getHabitacion()->getId();
    string nombreHostal = reserva->getHabitacion()->getHostal()->getNombre();
    int totalConsumo = 0;
    for (auto& consumicion : consumiciones){
        totalConsumo += consumicion->getPrecio();
    }
    return DTEstadiaL(checkIn, checkOut, huesped->getMail(), nombreHostal, idHabitacion, terminada, totalConsumo, codigoReserva);
}

// chequear si se usa
string Estadia::darHuesped(){
    return huesped->getNombre();
}

void Estadia::suscribir(Empleado* empleado){
    Estadia::suscriptos[empleado->getMail()] = empleado;
    empleado->setSuscripto(true);
}

void Estadia::desuscribir(Empleado* empleado){
    Estadia::suscriptos.erase(empleado->getMail());
}

// sin hacer
Estadia::~Estadia() {
    
}