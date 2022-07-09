#include "../include/Reserva.hh"
#include "../include/ReservaIndividual.hh"
#include "../include/DTReserva.hh"

ReservaIndividual::ReservaIndividual() {
}

/*ReservaIndividual::ReservaIndividual(DTFecha cI, DTFecha cO, int cod) {
	checkIn = cI;
	checkOut = cO;
	codigo = cod;
	estado = Abierta;
}*/

ReservaIndividual::ReservaIndividual(DTFecha CheckIn, DTFecha CheckOut, Habitacion* HabitacionRecordada, Huesped* HuespedRecordado, int cod) {
	checkIn = CheckIn;
	checkOut = CheckOut;
	habitacion = HabitacionRecordada;
	huespedes[HuespedRecordado->getMail()] = HuespedRecordado;
	codigo = cod;
	estado = Abierta;
}

DTFecha ReservaIndividual::getCheckIn() const {	return checkIn; }

DTFecha ReservaIndividual::getCheckOut() const { return checkOut; }

int ReservaIndividual::getCodigo() const { return codigo; }

EstadoReserva ReservaIndividual::getEstado() const { return estado; }

Habitacion* ReservaIndividual::getHabitacion() const { return habitacion; }

map<string, Huesped*> ReservaIndividual::getHuespedes() const { return huespedes; }

set<Estadia*> ReservaIndividual::getEstadias() const { return estadias; }

void ReservaIndividual::setEstado(EstadoReserva es) {
    estado = es;
}

float ReservaIndividual::getCosto() {
	int c = habitacion->getPrecio();
	
	int diasOut = getCheckOut().getDia() + getCheckOut().getMes() * 30 + getCheckOut().getAnio() * 365;
	int diasIn = getCheckIn().getDia() + getCheckIn().getMes() * 30 + getCheckIn().getAnio() * 365;
	int diferencia = diasOut - diasIn;

	return c * diferencia;
}

DTReserva* ReservaIndividual::darDT() {
	set<string> hues;
	for (auto it = huespedes.begin(); it != huespedes.end(); it++) {
		Huesped* h = it->second;
		string i = it->first;
		hues.insert(h->getNombre());
	}
	DTReservaIndividual* ri = new DTReservaIndividual(checkIn, checkOut, codigo, estado, habitacion->getId(), hues);
	DTReserva* dt = dynamic_cast<DTReserva*>(ri);
	return dt;
}

bool ReservaIndividual::estaDisponibleReserva(DTFecha CheckIn, DTFecha CheckOut) {
	return ((CheckIn > checkOut) || (CheckOut < checkIn));
}

bool ReservaIndividual::esHostal(string nombreH) {
	return (nombreH == habitacion->getHostal()->getNombre());
}

bool ReservaIndividual::esEstadiaReserva(int codReserva) {
	return (codigo == codReserva);
}

void ReservaIndividual::actualizarPromedioHostal(int calificacion) {
	habitacion->getHostal()->setPromedio(calificacion);
	
}

/*
set<DTResena> ReservaIndividual::mostrarResena() {
	set<DTResena> res;
	for (auto it = estadias.begin(); it != estadias.end(); it++) {
		Estadia* r = *it;
		res.insert(r->darResena(getCodigo()));
	}
	return res;
}
*/

set<DTResena> ReservaIndividual::darResenas() {
	set<DTResena> res;
	for (auto it = estadias.begin(); it != estadias.end(); it++) {
		Estadia* r = *it;
		//preguntar si tiene resena
		if (!r->noTieneResena()) {
			res.insert(r->darResena(getCodigo()));
		}
	}
	return res;
}

set<DTResena> ReservaIndividual::darResenasSinResponder() {
	set<DTResena> res;
	for (auto it = estadias.begin(); it != estadias.end(); it++) {
		Estadia* r = *it;
		//if (r->getResena()->sinResponder()) {
		if (!r->noTieneResena() && r->getResena()->getRespuesta()==NULL) {
			res.insert(r->darResenaSinResponder(getCodigo()));
		}
	}
	return res;
}

void ReservaIndividual::eliminarReserva() {
	habitacion->eliminarLinkReserva(this);

	for (auto it = huespedes.begin(); it != huespedes.end(); it++) {
		Huesped* h = it->second;
		h->eliminarLinkReserva(this);
	}

	for (auto it = estadias.begin(); it != estadias.end(); it++) {
		Estadia* r = *it;
		r->eliminarEstadia();
	}
}

int ReservaIndividual::darIdH() {
	return habitacion->getId();
}

string ReservaIndividual::darNombreH() {
	return habitacion->getHostal()->getNombre();
}

set<DTEstadiaC> ReservaIndividual::darEstadias(string nombreH) {
	set<DTEstadiaC> res;
	for (auto it = estadias.begin(); it != estadias.end(); it++) {
		Estadia* e = *it;
		res.insert(e->darDTC(e->getHuesped()->getMail(),habitacion->getHostal()->getNombre(),getCodigo()));
	}
	return res;
}

void ReservaIndividual::crearLinkEstadia(Estadia* e) {
	estadias.insert(e);
}

ReservaIndividual::~ReservaIndividual() {
}
