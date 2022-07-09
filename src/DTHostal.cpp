#include "../include/DTHostal.hh"

#include <string>
using std::string;

DTHostal::DTHostal() {}

DTHostal::DTHostal(string nom, string dir, string tel, float prom, int cantCal) :
	// porque recibe cantCalif?
	nombre(nom), direccion(dir), telefono(tel), promedio(prom), cantCalif(cantCal)
{}

string DTHostal::getNombre() const { return nombre; }

string DTHostal::getDireccion() const { return direccion; }

string DTHostal::getTelefono() const { return telefono; }

float DTHostal::getPromedio() const { return promedio; }

int DTHostal::getCantCalif() const { return cantCalif; }

bool DTHostal::operator<(const DTHostal& other) const{
	return true;
}