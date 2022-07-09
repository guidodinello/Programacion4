#include "../include/DTTipoDeConsumo.hh"

#include <string>
using namespace std;

DTTipoDeConsumo::DTTipoDeConsumo(int cod, string name, float pre){
  codigo = cod;
  nombre = name;
  precio = pre;
}
int DTTipoDeConsumo::getCodigo() const {
  return codigo;
}
float DTTipoDeConsumo::getPrecio() const {
  return precio;
}
string DTTipoDeConsumo::getNombre() const {
  return nombre;
} 

DTTipoDeConsumo::~DTTipoDeConsumo(){}

bool DTTipoDeConsumo::operator<(const DTTipoDeConsumo& other) const{
  return true;
}
