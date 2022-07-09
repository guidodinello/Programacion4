#include "../include/Reserva.hh"

DTFecha Reserva::getCheckIn() const { return checkIn; }

DTFecha Reserva::getCheckOut() const { return checkOut; }

int Reserva::getCodigo() const { return codigo; }

EstadoReserva Reserva::getEstado() const { return estado; }

map<string, Huesped*> Reserva::getHuespedes() const { return huespedes; }

Habitacion* Reserva::getHabitacion() const { return habitacion; }

set<Estadia*> Reserva::getEstadias() const { return estadias; }


Reserva::~Reserva() {}