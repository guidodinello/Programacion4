#include "../include/DTHabitacion.hh"

DTHabitacion::DTHabitacion() {}

DTHabitacion::DTHabitacion(int i, float p, int c, set<DTTipoDeConsumo> t) :
    id(i),
    precio(p),
    capacidad(c),
    tipos(t)
{}

int DTHabitacion::getId() const { return id; }
        
float DTHabitacion::getPrecio() const { return precio; }
        
int DTHabitacion::getCapacidad() const { return capacidad; }

set<DTTipoDeConsumo> DTHabitacion::getTipos() const { return tipos; }

bool DTHabitacion::operator<(const DTHabitacion& other) const{
  return true;
}
