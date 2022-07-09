#include "../include/Hostal.hh"
#include <string>
#include <iterator>
#include <set>
#include <map>

Hostal::Hostal() {
}

Hostal::Hostal(string nom, string dir, string tel, float prom, int cantCal) :
	nombre(nom), direccion(dir), telefono(tel), totalCalif(prom), cantCalif(cantCal)
{}

string Hostal::getNombre() const { return nombre; }

string Hostal::getDireccion() const { return direccion; }

string Hostal::getTelefono() const { return telefono; }

float Hostal::getTotalCalif() const { return totalCalif; }

int Hostal::getCantCalif() const { return cantCalif; }

set<DTHabitacion> Hostal::getHabitaciones() const { 
	set<DTHabitacion> res;
	for( auto& it : habitaciones ) {
		DTHabitacion h = it.second->darDT();
		res.insert(h);
	}
	return res; 
}

void Hostal::setNombre(const string& nom) {
	nombre = nom;
}

void Hostal::setDireccion(string dir) {
	direccion = dir;
}

void Hostal::setTelefono(string tel) {
	telefono = tel;
}

void Hostal::setPromedio(int calificacion) {
	totalCalif += calificacion;
	cantCalif++;
}

void Hostal::setCantCalif(int cantCal) {
	cantCalif = cantCal;
}

DTHostal Hostal::darDT() {
	DTHostal dt = DTHostal(nombre, direccion, telefono, totalCalif, cantCalif);
	return dt;
}

float Hostal::darTotalCalif() {
	return totalCalif;
}

void Hostal::crearLinkHab(Habitacion* hab) {
	habitaciones[hab->getId()] = hab;
}

Habitacion* Hostal::darHabitacion(int id) {
	auto it = habitaciones.find(id);
	if (it != habitaciones.end()) {
		return it->second;
	} else {
		throw invalid_argument("No hay habitaciones con ese id en el Hostal seleccionado");
	}
}

bool Hostal::esHostal(string nombreHostal) {
	return (nombreHostal == getNombre());
}

void Hostal::actualizarPromedio(int calificacion) {
	totalCalif = calificacion + totalCalif;
}

// set<DTResena> Hostal::mostrarResena(string nombreH) {
// 	set<DTResena> res;
// 	for (auto it = habitaciones.begin(); it != habitaciones.end(); it++) {
// 		Habitacion* h = it->second;
// 		res.insert(h->mostrarResena()); // no puede insertar un set
// 	}
// 	return res;
// }

set<DTResena> Hostal::darResenas() {
	set<DTResena> res;
	for (auto it = habitaciones.begin(); it != habitaciones.end(); it++) {
		Habitacion* h = it->second;
		set<DTResena> resenas = h->darResenas();
		for (auto& it2 : resenas)
			res.insert(it2);
	}
	return res;
}

set<DTHabitacion> Hostal::darHabitaciones(){
	return getHabitaciones();
}

set<DTResena> Hostal::darResenasSinResponder() {
	set<DTResena> res;
	for (auto it = habitaciones.begin(); it != habitaciones.end(); ++it) {
		Habitacion* h = it->second;
		for (auto& it2 : h->darResenasSinResponder()) {
				res.insert(it2);
		}
	}
	return res;
}
 
set<DTReserva*> Hostal::darReservas() {
	set<DTReserva*> res;
	for (auto it = habitaciones.begin(); it != habitaciones.end(); it++) {
		Habitacion* h = it->second;
		map<int, Reserva*> resh = h->getReservas();
		for (auto it2 = resh.begin(); it2 != resh.end(); it2++) {
			DTReserva* r = it2->second->darDT();
			res.insert(r);
		}
	}
	return res;
}

set<DTEstadiaC> Hostal::darEstadias() {
	set<DTEstadiaC> res;
	for (auto it = habitaciones.begin(); it != habitaciones.end(); it++) {
		Habitacion* h = it->second;
		set<DTEstadiaC> est = h->darEstadias(nombre);
		for (auto& it2 : est)
			res.insert(it2);
	}
	return res;
}

set<DTHabitacion> Hostal::darHabitacionesDispH(DTFecha CheckIn,DTFecha CheckOut){
	set<DTHabitacion> salida;
	for (auto it = habitaciones.begin(); it != habitaciones.end(); ++it){
		if (it->second->estaDisponible(CheckIn, CheckOut)) {
			salida.insert(it->second->darDT()); 
		}
	}
	if (salida.empty()) throw invalid_argument("No hay habitaciones disponibles");
	return salida;
}

//void Hostal::crearLinkEstadia(Estadia* e) {
//	//falta
//}

Hostal::~Hostal() {
	for (auto it = habitaciones.begin(); it != habitaciones.end(); ++it) {
		delete it->second;
	}
	habitaciones.clear();
}
