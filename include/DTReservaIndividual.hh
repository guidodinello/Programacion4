#ifndef _DTReservaIndividual_
#define _DTReservaIndividual_

#include "DTFecha.hh"
#include "DTReserva.hh"

#include <string>
#include <set>

using std::string;
using std::set;

class DTReservaIndividual : public DTReserva {
//private:
//    DTFecha checkIn;
//    DTFecha checkOut;
//    int codigo;
//    EstadoReserva estado;
//    int numeroHabitacion;
//    set<string> huespedes;
public:
    DTReservaIndividual();
    DTReservaIndividual(DTFecha cIn, DTFecha cOut, int cod, EstadoReserva es, int hab, set<string> hues);

    //Getters
    // DTFecha getCheckIn() const;
    // DTFecha getCheckOut() const;
    // int getCodigo() const;
    // EstadoReserva getEstado() const;
    // set<string> getHuespedes() const;
    // int getNumeroHabitacion() const;
   
    //Destructor
    ~DTReservaIndividual();
};

#endif