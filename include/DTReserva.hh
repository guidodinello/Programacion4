#ifndef __DTRESERVA_HH__
#define __DTRESERVA_HH__

enum EstadoReserva {
    Abierta, Cerrada, Cancelada
};

#include "DTFecha.hh"
#include "DTHuesped.hh"

#include <set>
#include <string>
#include <map>

using std::string;
using std::set;
using std::map;

class DTReserva {
protected:
    int codigo;
    DTFecha checkIn;
    DTFecha checkOut;
    EstadoReserva estado;
    int numeroHabitacion;
    set<string> huespedes;
public:
    //DTReserva();
    //DTReserva(DTFecha cIn, DTFecha cOut, int cod, EstadoReserva es, int nH, set<string> hues);

    //Getters 
    virtual DTFecha getCheckIn() const ;
    virtual DTFecha getCheckOut() const ;
    virtual int getCodigo() const ;
    virtual EstadoReserva getEstado() const ;
    virtual set<string> getHuespedes() const ;
    virtual int getNumeroHabitacion() const ;

    //Destructor
    virtual ~DTReserva();
};

#endif
