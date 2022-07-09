#include "../include/Consumicion.hh"


Consumicion::Consumicion(int cant, TipoDeConsumo* ti){
	cantidad=cant;
	tipo=ti;
}

int Consumicion::getCantidad(){ return cantidad;}

TipoDeConsumo* Consumicion::getTipo() {return tipo;}

float Consumicion::getPrecio() {
	 return tipo->getPrecio()*cantidad;
}


Consumicion::~Consumicion(){}
