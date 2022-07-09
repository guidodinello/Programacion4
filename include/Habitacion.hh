#ifndef _Habitacion_H_
#define _Habitacion_H_



#include "DTTipoDeConsumo.hh"
#include "DTHabitacion.hh"
#include "DTReserva.hh"
#include "DTResena.hh"
#include "DTEstadiaC.hh"


#include <string>
#include <set>
#include <map>

using std::map;
using std::set;
using std::string;

class Hostal;
class Reserva;
class TipoDeConsumo;

class Habitacion{
    private:
        int id;
        float precio;
        int capacidad;

        Hostal* hostal;
        map<int, TipoDeConsumo*> tipos; //TipoDeConsumo* tipos[10]; 
        map<int, Reserva*> reservas;
    public:
        //Constructores
        Habitacion();
        Habitacion(int id1, float precio1, int cap);

        //Getters
        int getId() const;
        float getPrecio() const;
        int getCapacidad() const;
        Hostal* getHostal() const;
        map<int, TipoDeConsumo*> getTipos() const;
        map<int, Reserva*> getReservas() const;

        //setters
        void setId(int id1);
        void setPrecio(float precio1);
        void setCapacidad(int cap);
        void setHostal(Hostal* h);
        void setTipos(TipoDeConsumo* tc);
    
        //Operaciones
        DTHabitacion darDT();
        void crearLinkR(Reserva *res);
        void crearLinkTDC(map<int, TipoDeConsumo*> tc);
        bool estaDisponible(DTFecha CheckIn, DTFecha CheckOut);
        bool esHostal(string nombreHostal);
        //set<DTResena> mostrarResena();
        void actualizarPromedioHostal(int calificacion);
        set<DTResena> darResenas();
        map<int, DTReserva*> darReservasHab();
        set<DTResena> darResenasSinResponder();
        set<DTEstadiaC> darEstadias(string nombreHostal);
        string darNombreH();
        void eliminarLinkReserva(Reserva* res);

        //Sobrecargas
        

        //Destructor
        ~Habitacion();
};

#include "TipoDeConsumo.hh"
#include "Hostal.hh"
#include "Reserva.hh"

#endif
