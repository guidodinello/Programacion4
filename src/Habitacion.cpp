#include "../include/Habitacion.hh"
#include "../include/DTHabitacion.hh"
#include "../include/DTTipoDeConsumo.hh"

#include <iterator>
#include <map>
#include <set>
using std::map;
using std::set;

Habitacion::Habitacion() {
}

Habitacion::Habitacion(int id1, float precio1, int cap) :
	id(id1), precio(precio1), capacidad(cap)
{}

int Habitacion::getId() const { return id;}

float Habitacion::getPrecio() const { return precio; }

int Habitacion::getCapacidad() const { return capacidad; }

Hostal* Habitacion::getHostal() const { return hostal; }

map<int, TipoDeConsumo*> Habitacion::getTipos() const { return tipos; }

map<int, Reserva*> Habitacion::getReservas() const { return reservas; }

void Habitacion::setId(int id1) { id = id1; }

void Habitacion::setPrecio(float precio1) {	precio = precio1; }

void Habitacion::setCapacidad(int cap) { capacidad = cap; }

void Habitacion::setHostal(Hostal* h) {	hostal = h; }

void Habitacion::setTipos(TipoDeConsumo* tc) {
	if (tipos.size() == 10) throw invalid_argument{"No se pueden aregar mas de 10 tipos por habitacion"};
	else tipos.insert(std::pair<int,TipoDeConsumo*>(tc->getCodigo(),tc));
	}

DTHabitacion Habitacion::darDT() {
	set<DTTipoDeConsumo> tdc;
	for (auto it = tipos.begin(); it != tipos.end(); it++) {
		DTTipoDeConsumo* tipo = it->second->darDT();
		tdc.insert(*tipo);
	}
	DTHabitacion dt = DTHabitacion(id, precio, capacidad, tdc);
	return dt;
}

void Habitacion::crearLinkR(Reserva *res) {
	reservas[res->getCodigo()] = res;
}

void Habitacion::crearLinkTDC(map<int, TipoDeConsumo*> tc) {
	tipos = tc;
}

bool Habitacion::estaDisponible(DTFecha CheckIn, DTFecha CheckOut) {
	// tiene que preguntarle a su conjunto de reservas si cada una retorna estaDisponibleReserva true
	bool res = true;
	auto it = reservas.begin();
	while ((it != reservas.end()) && (res == true)) {
		Reserva* r = it->second;
		if (!r->estaDisponibleReserva(CheckIn, CheckOut)) res = false;
		++it;
	}
	return res;
}

bool Habitacion::esHostal(string nombreHostal) {
	return (nombreHostal == hostal->getNombre());
}

/*
set<DTResena> Habitacion::mostrarResena() {
	set<DTResena> res;
	for (auto it = reservas.begin(); it != reservas.end(); it++) {
		Reserva* r = it->second;
		res.insert(r->mostrarResena()); // no puede insertar un set
	}
	return res;
}
*/

void Habitacion::actualizarPromedioHostal(int calificacion) {
	hostal->actualizarPromedio(calificacion);
}

set<DTResena> Habitacion::darResenas() {
	set<DTResena> res;
	for (auto it = reservas.begin(); it != reservas.end(); it++) {
		set<DTResena> r = it->second->darResenas();
		for (auto it2 = r.begin(); it2 != r.end(); it2++)  {
			DTResena a = *it2;
			res.insert(a);
		}
	}
	return res;
}

map<int, DTReserva*> Habitacion::darReservasHab() {
	map<int, DTReserva*> res;
	for (auto it = reservas.begin(); it != reservas.end(); it++) {
		DTReserva* r = it->second->darDT();
		res[r->getCodigo()] = r;
	}
	return res;
}

set<DTResena> Habitacion::darResenasSinResponder() {
	set<DTResena> res;
	for (auto it = reservas.begin(); it != reservas.end(); it++) {
		set<DTResena> r = it->second->darResenasSinResponder();
		for (auto it2 = r.begin(); it2 != r.end(); it2++)  {
			DTResena a = *it2;
			res.insert(a);
		}
	}
	return res;
}

set<DTEstadiaC> Habitacion::darEstadias(string nombreHostal) {
	set<DTEstadiaC> res;
	for (auto it = reservas.begin(); it != reservas.end(); it++) {
		set<DTEstadiaC> e = it->second->darEstadias(nombreHostal);
		for (auto it2 = e.begin(); it2 != e.end(); it2++)  {
			DTEstadiaC a = *it2;
			res.insert(a);
		}	
	}
	return res;
}

string Habitacion::darNombreH() {
	return (hostal->getNombre());
}

void Habitacion::eliminarLinkReserva(Reserva *res) {
	reservas.erase(res->getCodigo());
}

Habitacion::~Habitacion() {
}

