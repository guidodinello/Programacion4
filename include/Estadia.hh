#ifndef _Estadia_
#define _Estadia_

#include "DTFecha.hh"
#include "DTEstadiaC.hh"
#include "DTEstadiaL.hh"
#include "DTResena.hh"
#include "DTRespuesta.hh"
#include "IObserver.hh"

#include <set>
#include <map>
using std::set;
using std::map;

class Huesped;
class Reserva;
class Empleado;
class Resena;
class Consumicion;

class Estadia {
    private:
        static map<string, IObserver*> suscriptos;

        DTFecha checkIn;
        DTFecha checkOut;

        bool terminada;

        Resena* resena;
        Huesped* huesped;
        Reserva* reserva;
        set<Consumicion*> consumiciones;
    public:
        //Constructores
        Estadia(const DTFecha& cI, const DTFecha& cO, bool terminada, Reserva* r, Huesped* h);

        // hacer set de checkout

        //Getters
        DTFecha getCheckIn() const;
        DTFecha getCheckOut() const;
        bool getTerminada() const;
        Resena* getResena() const;
        Huesped* getHuesped() const;
        Reserva* getReserva() const;

        //Operaciones
        DTEstadiaC darDTC(const string& mailH, const string& nombreHostal, int codigoReserva);
        DTEstadiaL darDTL(const string& mailH, int codigoReserva);
        //DTResena mostrarResena();
        bool esHostal(const string& nombreHostal);
        void finalizarEstadia();
        bool noTieneResena();
        int darCodReserva();
        void crearResena(const string& comentario, int calificacion);
        DTResena darResenaSinResponder(int);
        bool esReservaEstadia(int codigoReserva);
        void comentarCalificacion(const string& comentario, Empleado* empleado);
        DTResena infoComentario();
        DTRespuesta infoRespuesta();
        void eliminarEstadia();
        DTResena darResena(int codigoReserva);
        static void suscribir(Empleado *e);
        static void desuscribir(Empleado *e);
        string darHuesped();

        //CU
        //12 DTResena darResenas()
        //      no tiene sentido, devuelve un DT y pide
        //      resenaS, ademas Estadia solo se asocia
        //      a una reserva, entonces es el getReserva()
        //   Sol: Se agrego darResena, y se pregunta previamente
        //   con noTieneResena() en el caso de uso.
        //14 DTEstadia darEstaida(codRes, mailHuesped);
        //      no existe DTEstadia, y para que recibe esos
        //      parametros
        //   Sol: Se agrego darEstadia, devuelve un DTEstadiaL

        //Destructor
        ~Estadia();
};

#include "Empleado.hh"
#include "Huesped.hh"
#include "Reserva.hh"
#include "Resena.hh"
#include "Consumicion.hh"

#endif
