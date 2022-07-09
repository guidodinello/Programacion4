#ifndef _Reserva_
#define _Reserva_

#include "DTReserva.hh"
#include "DTFecha.hh"
#include "DTResena.hh"
#include "DTEstadiaC.hh"

#include <string>
#include <iterator>
#include <set>
#include <map>

using std::string;
using std::set;
using std::map;

class Huesped;
class Estadia;
class Habitacion;

class Reserva {
    protected:
        DTFecha checkIn;
        DTFecha checkOut;

        int codigo;
        EstadoReserva estado;

        Habitacion* habitacion;
        map<string, Huesped*> huespedes;
        set<Estadia*> estadias;
    public:
        //Constructores
        // No tiene 

        //Getters
        virtual DTFecha getCheckIn() const;
        virtual DTFecha getCheckOut() const;
        virtual int getCodigo() const;
        virtual EstadoReserva getEstado() const;
        virtual void setEstado(EstadoReserva es) = 0;
        virtual map<string, Huesped*> getHuespedes() const;
        virtual Habitacion* getHabitacion() const;
        virtual set<Estadia*> getEstadias() const;

        //Operaciones
        virtual DTReserva* darDT() = 0;
        virtual bool estaDisponibleReserva(DTFecha CheckIn, DTFecha CheckOut) = 0;
        virtual bool esHostal(string nombreH) = 0;
        virtual bool esEstadiaReserva(int codReserva) = 0;
        virtual void actualizarPromedioHostal(int calificacion) = 0;
        //virtual set<DTResena> mostrarResena() = 0; igual a darResenas
        virtual set<DTResena> darResenas() = 0;
        virtual set<DTResena> darResenasSinResponder() = 0;
        virtual void eliminarReserva() = 0;
        virtual int darIdH() = 0;
        virtual string darNombreH() = 0;
        virtual set<DTEstadiaC> darEstadias(string nombreH) = 0;

        //se agrego por darAltaEstadia de controlador Reserva
        virtual void crearLinkEstadia(Estadia* e) = 0;

        //Destructor
        virtual ~Reserva();
};

#include "Huesped.hh"
#include "Estadia.hh"
#include "Habitacion.hh"

#endif
