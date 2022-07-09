#ifndef _Hostal_H_
#define _Hostal_H_

#include "DTHabitacion.hh"
#include "DTReserva.hh"
#include "DTHostal.hh"
#include "Habitacion.hh"
#include "DTResena.hh"
#include "DTEstadiaC.hh"

#include <string>
#include <set>
#include <map>

using std::set;
using std::string;
using std::map;

class Hostal{
    private:
        string nombre;
        string direccion;
        string telefono;
        float totalCalif;
        int cantCalif;

        map<int, Habitacion*> habitaciones;
    public:
        //Constructores
        Hostal();
        Hostal(string nom, string dir, string tel, float prom, int canCal);

        //Getters
        string getNombre() const;
        string getDireccion() const;
        string getTelefono() const;
        float getTotalCalif() const;
        int getCantCalif() const;
        set<DTHabitacion> getHabitaciones() const;

        //setters
        void setNombre(const string& nom);
        void setDireccion(string dir);
        void setTelefono(string tel);
        void setPromedio(int calificacion);
        void setCantCalif(int cantCal);

        //Metodos
        DTHostal darDT();
        float darTotalCalif();
        void crearLinkHab(Habitacion* hab);
        Habitacion* darHabitacion(int id);
        bool esHostal(string nombreH);
        void actualizarPromedio(int);
        //set<DTResena> mostrarResena(string nombreH);
        set<DTResena> darResenas();
        set<DTHabitacion> darHabitaciones();
        set<DTResena> darResenasSinResponder();
        set<DTReserva*> darReservas();
        set<DTEstadiaC> darEstadias();
        set<DTHabitacion> darHabitacionesDispH(DTFecha CheckIn,DTFecha CheckOut);

        //void crearLinkEstadia(Estadia* e);

        //Sobrecargas
        

        //Destructor
        ~Hostal();
};


#endif
