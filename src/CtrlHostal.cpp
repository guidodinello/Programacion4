#include "../include/CtrlHostal.hh"
#include "../include/CtrlUsuario.hh"
#include "../include/CtrlReserva.hh"

#include <string>
#include <iterator>
#include <set>
#include <map>
#include <vector>
using std::string;
using std::vector;

#include <stdexcept>
using std::invalid_argument;

CtrlHostal::CtrlHostal(){

}


CtrlHostal* CtrlHostal::instance = NULL;

CtrlHostal* CtrlHostal::getInstance(){
    if(instance == NULL){
        instance = new CtrlHostal();
    }
    return instance;
}



void CtrlHostal::darAltaNuevoHostal(string nombre, string dire, string tel){
    Hostal *nuevo = new Hostal(nombre, dire, tel, 0, 0); //verificar cómo implementan los parámetros del constructor (la firma)
    hostales[nombre] = nuevo;
}

set<DTHostal> CtrlHostal::darHostalesRegistrados(){
  set<DTHostal> salida;
  for (map<string, Hostal*>::iterator it = hostales.begin(); it != hostales.end(); ++it){
    const DTHostal h = it->second->darDT();
    salida.insert(h);
  }
  if (salida.empty()) {
    throw invalid_argument{"No hay hostales registrados"};
  }
  return salida;
}

DTHostal CtrlHostal::seleccionarHostal(string nombre){
  auto it = hostales.find(nombre);
  if (it == hostales.end()) {throw invalid_argument("No existe Hostal con el nombre "+nombre); }
  Hostal *hostalS = hostales.find(nombre)->second;
  hostalSeleccionado = hostalS;
  DTHostal dtHostalS = hostalS->darDT();
  return dtHostalS;
}

void CtrlHostal::ingresarDatosNuevaHabitacion(int numero, float precio, int capacidad){
  nuevaHabitacion* nueva = new nuevaHabitacion;
  nueva->num = numero;
  nueva->precio = precio;
  nueva->capacidad = capacidad;
  
  nuevaHab = nueva;
}

/*  No se por que lo hice */
set<DTTipoDeConsumo> CtrlHostal::getTiposDeConsumo() {
  set<DTTipoDeConsumo> tipos;
  for (auto it = tiposDeConsumo.begin(); it != tiposDeConsumo.end(); it++) {
		DTTipoDeConsumo* t = it->second->darDT();
    DTTipoDeConsumo dt = *t;
		tipos.insert(dt);
    delete t;
	}
  return tipos;
}

void CtrlHostal::setTiposDeConsumo(TipoDeConsumo* tipo){//supongo que lo precisaremos para probar las cosas
  tiposDeConsumo[tipo->getCodigo()] = tipo; 
}

void CtrlHostal::agregarTipoDeConsumoPH(int codigo){
  auto it = tiposDeConsumo.find(codigo);
  if (it == tiposDeConsumo.end()) {throw invalid_argument("No existe Tipo de Consumo"); }
  TipoDeConsumo *t = tiposDeConsumo.find(codigo)->second;
  tiposDeConsumo[codigo] = t;
}

void CtrlHostal::confirmarAltaDeHabitacion(){
  if (nuevaHab == NULL) {throw invalid_argument("No hay datos para la habitacion"); }
  Habitacion* nueva = new Habitacion(nuevaHab->num, nuevaHab->precio, nuevaHab->capacidad);

  nueva->crearLinkTDC(tdcParaNuevaHab);
  if(hostalSeleccionado == NULL) {throw invalid_argument("No hay hostal seleccionado"); }
  hostalSeleccionado->crearLinkHab(nueva);

  // faltaba crear link de habitacion hacia hostal
  nueva->setHostal(hostalSeleccionado);

  hostalSeleccionado = NULL;
  delete nuevaHab;
  nuevaHab = NULL; //por las dudas
}

void CtrlHostal::cancelarAltaDeHabitacion(){
  hostalSeleccionado = NULL;
  nuevaHab = NULL;
  tdcParaNuevaHab.erase(tdcParaNuevaHab.begin(), tdcParaNuevaHab.end()); //no tiene que borrar las instancias de TDC ya que son las que quedan asociadas a la habitacion
}

set<DTEmpleado> CtrlHostal::empleadosSinAsignar(){
  CtrlUsuario * ctrlU = CtrlUsuario::getInstance();
  return ctrlU->darEmpleadosSA();
  //return empleadosSA;
}

void CtrlHostal::seleccionarEmpleadoYCargo(string email, TipoCargo cargo){
  CtrlUsuario * ctrlU;
  ctrlU = CtrlUsuario::getInstance();
  empleadoSeleccionado = ctrlU->buscarEmpleado(email);
  tipoSeleccionado = cargo;
}



void CtrlHostal::confirmarAsignacionDeCargo(){
  if (empleadoSeleccionado == NULL) {throw invalid_argument("No hay ningun empleado seleccionado"); }
  Empleado * e = empleadoSeleccionado;
  if (tipoSeleccionado == sinCargo) {throw invalid_argument("No hay ningun tipo seleccionado"); }
  e->setTipoCargo(tipoSeleccionado);
  if (hostalSeleccionado == NULL) {throw invalid_argument("No hay ningun Hostal seleccionado"); }
  e->crearLinkH(hostalSeleccionado);
  empleadoSeleccionado = NULL;
  tipoSeleccionado = sinCargo;
}

void CtrlHostal::cancelarAsignacionDeCargo(){
  empleadoSeleccionado = NULL;
  tipoSeleccionado = sinCargo;
}

void CtrlHostal::finalizarAsignacionDeCargo(){
  hostalSeleccionado = NULL;
}

// bool esMayor(Hostal *a, Hostal *b){
//   if (b==NULL) {return true;} //es el primer caso, el arreglo está vacío
//   else if ((a->darTotalCalif()/a->getCantCalif()) > (b->darTotalCalif()/b->getCantCalif())) {return true; }
//   else {return false;}
// }

vector<string> CtrlHostal::darTopHostales(){
  if (hostales.size() < 3) {throw invalid_argument("Hay menos de 3 Hostales en el sistema"); }
  Hostal *top[3] = {NULL, NULL, NULL};
  Hostal *h;
  int prom0 = 0;
  int prom1 = 0;
  int prom2 = 0;
  int prom;
  for (auto it = hostales.begin(); it!= hostales.end(); ++it){
    h=it->second; 
    if (h->getCantCalif() == 0) {prom = 0;}
    else {prom = h->darTotalCalif()/h->getCantCalif();}
    if (prom >= prom0) {
      prom2 = prom1;
      prom1 = prom0;
      prom0 = prom;
      top[2] = top[1];
      top[1] = top[0];
      top[0]= h;
    }
    else if (prom >= prom1) {
      prom2 = prom1;
      prom1 = prom;
      top[2] = top[1];
      top[1]= h;
      }
    else if (prom >= prom2) {
      prom2 = prom;
      top[2]=h; 
    }
  }
  vector<string> salida = {top[0]->getNombre(), top[1]->getNombre(), top[2]->getNombre()};
  return salida;
}

set<DTResena> CtrlHostal::darResenas(){
  if (hostalSeleccionado == NULL) {throw invalid_argument("No hay Hostal seleccionado"); }
  return hostalSeleccionado->darResenas();
}

set<DTHabitacion> CtrlHostal::darHabitaciones(){
  if (hostalSeleccionado == NULL) {throw invalid_argument("No hay Hostal seleccionado"); }
  return hostalSeleccionado->darHabitaciones();
}

set<DTReserva*> CtrlHostal::darReservas(){
  if (hostalSeleccionado == NULL) {throw invalid_argument("No hay Hostal seleccionado"); }
  return hostalSeleccionado->darReservas();
}

void CtrlHostal::finalizarConsultaHostal(){
  hostalSeleccionado = NULL;
}

void CtrlHostal::finalizarConsultaReserva(){
  hostalSeleccionado = NULL;
}

Hostal* CtrlHostal::darHostal(string nombre) {
  auto salida = hostales.find(nombre);
  if (salida == hostales.end()) {throw invalid_argument("No existe Hostal con el nombre "+nombre); }
  return salida->second;
}

void CtrlHostal::agregarConsumo(int codigo, string nombre, float precio){
  TipoDeConsumo* nuevo = new TipoDeConsumo(codigo, nombre, precio);
  tiposDeConsumo[codigo] = nuevo;
}

CtrlHostal::~CtrlHostal(){
  for (auto it = hostales.begin(); it!= hostales.end(); ++it){
    delete it->second;
  }
  for (auto it = tiposDeConsumo.begin(); it!= tiposDeConsumo.end(); ++it){
    delete it->second;
  }
  hostales.clear();
  tiposDeConsumo.clear();
}