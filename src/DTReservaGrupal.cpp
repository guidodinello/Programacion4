#include "../include/DTReservaGrupal.hh"

DTReservaGrupal::DTReservaGrupal()
{}

DTReservaGrupal::DTReservaGrupal(DTFecha cIn, DTFecha cOut, int cod, EstadoReserva es, int hab, set<string> hues) {
	checkIn = cIn;
	checkOut = cOut;
	codigo = cod;
	estado = es;
	numeroHabitacion = hab;
	huespedes = hues;
}

// DTFecha DTReservaGrupal::getCheckIn() const { return checkIn; }

// DTFecha DTReservaGrupal::getCheckOut() const { return checkOut; }

// int DTReservaGrupal::getCodigo() const { return codigo; }

// EstadoReserva DTReservaGrupal::getEstado() const { return estado; }

// set<string> DTReservaGrupal::getHuespedes() const { return huespedes; }

// int DTReservaGrupal::getNumeroHabitacion() const { return numeroHabitacion; }

DTReservaGrupal::~DTReservaGrupal() {}
