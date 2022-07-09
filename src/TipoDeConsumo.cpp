#include "../include/TipoDeConsumo.hh"
#include "../include/DTTipoDeConsumo.hh"

#include <string>
using namespace std;

int TipoDeConsumo::getCodigo() {
  return codigo;
}

float TipoDeConsumo::getPrecio() {
  return precio;
}

string TipoDeConsumo::getNombre() {
  return nombre;
} 

void TipoDeConsumo::setCodigo(int cod) {
  codigo = cod;
}

void TipoDeConsumo::setNombre(string name){
  nombre = name;
}

void TipoDeConsumo::setPrecio(float pre) {
  precio = pre;
}

DTTipoDeConsumo* TipoDeConsumo::darDT(){
  DTTipoDeConsumo* tipoNuevo = new DTTipoDeConsumo(codigo, nombre, precio);
  return tipoNuevo;
}

TipoDeConsumo::TipoDeConsumo(int a, string b, float c){
  codigo = a;
  nombre = b;
  precio = c;
}

TipoDeConsumo::~TipoDeConsumo(){

}