#ifndef __DTHABITACION_HH__
#define __DTHABITACION_HH__

#include "DTHostal.hh"
#include "DTTipoDeConsumo.hh"
#include "DTReserva.hh"

#include <set>
#include <map>

using std::set;
using std::map;

class DTTipoDeConsumo;

class DTHabitacion{
    private:
        int id;
        float precio;
        int capacidad;
        set<DTTipoDeConsumo> tipos;
    public:
        DTHabitacion();
        DTHabitacion(int i, float p, int c, set<DTTipoDeConsumo> t);

        //Getters
        int getId() const;
        float getPrecio() const;
        int getCapacidad() const;
        set<DTTipoDeConsumo> getTipos() const;
        
        bool operator<(DTHabitacion const&) const;

};

#endif
