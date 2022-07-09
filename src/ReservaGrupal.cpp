#include "../include/Reserva.hh"
#include "../include/ReservaGrupal.hh"
#include "../include/DTReserva.hh"

ReservaGrupal::ReservaGrupal() {}

/*ReservaGrupal::ReservaGrupal(DTFecha cI, DTFecha cO, int cod) {
	checkIn = cI;
	checkOut = cO;
	codigo = cod;
	estado = Abierta;
}*/

ReservaGrupal::ReservaGrupal(DTFecha CheckIn, DTFecha CheckOut, Habitacion* HabitacionRecordada, map<string, Huesped*>& HuespedesReservaRecordado, int cod) {
	checkIn = CheckIn;
	checkOut = CheckOut;
	habitacion = HabitacionRecordada;
	for (auto it = HuespedesReservaRecordado.begin(); it != HuespedesReservaRecordado.end(); it++) {
		Huesped* h = it->second;
		huespedes[h->getMail()] = h;
	}
	codigo = cod;
	estado = Abierta;
}

DTFecha ReservaGrupal::getCheckIn() const {	return checkIn; }

DTFecha ReservaGrupal::getCheckOut() const { return checkOut; }

int ReservaGrupal::getCodigo() const { return codigo; }

EstadoReserva ReservaGrupal::getEstado() const { return estado; }

Habitacion* ReservaGrupal::getHabitacion() const { return habitacion; }

map<string, Huesped*> ReservaGrupal::getHuespedes() const { return huespedes; }

set<Estadia*> ReservaGrupal::getEstadias() const { return estadias; }

void ReservaGrupal::setEstado(EstadoReserva es) {
    estado = es;
}

// devuelve true si en huespedes hay al menos 2 fingers
bool fingers(map<string, Huesped*> h) {
	int count = 0;
	auto it = h.begin();
	while ((count < 2) && (it != h.end())) {
		Huesped *h = it->second; //???
		if (h->getEsFinger()) {
			count++;
		}
		it++; 
	}
	return (count >= 2);
}

float ReservaGrupal::getCosto() { 
	int c = habitacion->getPrecio();
	
	if (fingers(huespedes)) {
		c = c * (0.70);
	}

	int diasOut = getCheckOut().getDia() + getCheckOut().getMes() * 30 + getCheckOut().getAnio() * 365;
	int diasIn = getCheckIn().getDia() + getCheckIn().getMes() * 30 + getCheckIn().getAnio() * 365;
	int diferencia = diasOut - diasIn;

	return c * diferencia;
}

DTReserva* ReservaGrupal::darDT() {
	set<string> hues;
	for (auto it = huespedes.begin(); it != huespedes.end(); it++) {
		Huesped* h = it->second;
		string i = it->first;
		hues.insert(h->getNombre());
	}
	DTReservaGrupal* rg = new DTReservaGrupal(checkIn, checkOut, codigo, estado, habitacion->getId(), hues);
	DTReserva* dt = dynamic_cast<DTReserva*>(rg);
	return dt;
}

bool ReservaGrupal::estaDisponibleReserva(DTFecha CheckIn, DTFecha CheckOut) {
	return ((CheckIn > checkOut) || (CheckOut < checkIn));
}

bool ReservaGrupal::esHostal(string nombreH) {
	return (nombreH == habitacion->getHostal()->getNombre());
}

bool ReservaGrupal::esEstadiaReserva(int codReserva) {
	return (codigo == codReserva);
}

void ReservaGrupal::actualizarPromedioHostal(int calificacion) {
	habitacion->getHostal()->setPromedio(calificacion); 
}

/*
set<DTResena> ReservaGrupal::mostrarResena() {
	set<DTResena> res;
	for (auto it = estadias.begin(); it != estadias.end(); it++) {
		Estadia* r = *it;
		res.insert(r->darResena(getCodigo()));
	}
	return res;
}
*/

set<DTResena> ReservaGrupal::darResenas() {
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

set<DTResena> ReservaGrupal::darResenasSinResponder() {
	set<DTResena> res;
	for (auto it = estadias.begin(); it != estadias.end(); it++) {
		Estadia* r = *it;
		if (!r->noTieneResena() && r->getResena()->getRespuesta()==NULL) {
			res.insert(r->darResenaSinResponder(getCodigo()));
		}
	}
	return res;
}

void ReservaGrupal::eliminarReserva() {
	habitacion->eliminarLinkReserva(this);

	for (auto it = huespedes.begin(); it != huespedes.end(); it++) { // deberia ser solo 1
		Huesped* h = it->second; // ???
		h->eliminarLinkReserva(this);
	}

	for (auto it = estadias.begin(); it != estadias.end(); it++) {
		Estadia* r = *it;
		r->eliminarEstadia();
	}
}

int ReservaGrupal::darIdH() {
	return habitacion->getId();
}

string ReservaGrupal::darNombreH() {
	return habitacion->getHostal()->getNombre();
}

set<DTEstadiaC> ReservaGrupal::darEstadias(string nombreH) {
	set<DTEstadiaC> res;
	for (auto it = estadias.begin(); it != estadias.end(); it++) {
		Estadia* e = *it;
		res.insert(e->darDTC(e->getHuesped()->getMail(), habitacion->getHostal()->getNombre(),getCodigo()));
	}
	return res;
}

void ReservaGrupal::crearLinkEstadia(Estadia* e) {
	estadias.insert(e);
}

ReservaGrupal::~ReservaGrupal() {
}
