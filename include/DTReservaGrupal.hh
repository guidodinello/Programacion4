#ifndef _DTReservaGrupal_
#define _DTReservaGrupal_

#include "DTFecha.hh"
#include "DTReserva.hh"

#include <string>
#include <set>

using std::string;
using std::set;

class DTReservaGrupal : public DTReserva {
//private:
//     int codigo;
//    DTFecha checkIn;
//    DTFecha checkOut;
//    EstadoReserva estado;
//    int numeroHabitacion;
//    set<string> huespedes;
public:
    DTReservaGrupal();
    DTReservaGrupal(DTFecha cIn, DTFecha cOut, int cod, EstadoReserva es, int hab, set<string> hues);

    //Getters
    // DTFecha getCheckIn() const;
    // DTFecha getCheckOut() const;
    // int getCodigo() const;
    // EstadoReserva getEstado() const;
    // set<string> getHuespedes() const;
    // int getNumeroHabitacion() const;

    //Destructor
    ~DTReservaGrupal();
};

#endif