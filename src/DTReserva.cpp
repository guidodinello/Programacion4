#include "../include/DTReserva.hh"

/*DTReserva::DTReserva()
{}*/

/*DTReserva::DTReserva(DTFecha cIn, DTFecha cOut, int cod, EstadoReserva es, int nH, set<string> hues) :
	checkIn(cIn),
	checkOut(cOut),
	codigo(cod),
    estado(es),
	numeroHabitacion(nH),
	huespedes(hues)
{}*/

DTFecha DTReserva::getCheckIn() const { return checkIn; }

DTFecha DTReserva::getCheckOut() const { return checkOut; }

int DTReserva::getCodigo() const { return codigo; }

EstadoReserva DTReserva::getEstado() const { return estado; }

set<string> DTReserva::getHuespedes() const { return huespedes;}

int DTReserva::getNumeroHabitacion() const { return numeroHabitacion; }

DTReserva::~DTReserva() {}