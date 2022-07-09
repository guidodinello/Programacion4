#include "../include/Fabrica.hh"
#include "../include/CtrlHostal.hh"
#include "../include/CtrlReserva.hh"
#include "../include/CtrlUsuario.hh"

Fabrica* Fabrica::instance = NULL;
Fabrica::Fabrica(){}

Fabrica* Fabrica::getInstance() {
	if (Fabrica::instance == NULL) {
		Fabrica::instance = new Fabrica();
	}
	return Fabrica::instance;
}

ICtrlHostal* Fabrica::getICtrlHostal(){
  return CtrlHostal::getInstance();
}

ICtrlReserva* Fabrica::getICtrlReserva(){
  return CtrlReserva::getInstance();
}

ICtrlUsuario* Fabrica::getICtrlUsuario(){
  return CtrlUsuario::getInstance();
}

Fabrica::~Fabrica(){}