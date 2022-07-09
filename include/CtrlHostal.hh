#ifndef _CtrlHostal_
#define _CtrlHostal_

#include <set>
#include <map>
#include <vector>

#include "DTHabitacion.hh"
#include "ICtrlHostal.hh"

class Hostal;
class TipoDeConsumo;
class Habitacion;
class Empleado;
class Huesped;

using namespace std;

struct nuevaHabitacion{
    int num;
    float precio;
    int capacidad;
};


class CtrlHostal : public ICtrlHostal {
    private:
        static CtrlHostal* instance;
        map<string, Hostal*> hostales;
        map<int, TipoDeConsumo*> tiposDeConsumo;

        nuevaHabitacion* nuevaHab;                //usados en 
        map<int, TipoDeConsumo*> tdcParaNuevaHab; //Alta de Habitación

        Hostal* hostalSeleccionado;         //Usado en varis CU (todos los que seleccionan un hostal)
        
        Empleado* empleadoSeleccionado; //usados en 
        TipoCargo tipoSeleccionado;     //Asignar empleado a hostal


        //Constructores
        CtrlHostal(); //setear en null todo y en sinCargo
    public:
        //Metodos
        static CtrlHostal * getInstance(); 

        set<DTTipoDeConsumo> getTiposDeConsumo();
        void setTiposDeConsumo(TipoDeConsumo* tipo);
        
        void darAltaNuevoHostal(string nombre, string dire, string tel);
        set<DTHostal> darHostalesRegistrados();
        DTHostal seleccionarHostal(string nombre);
        void ingresarDatosNuevaHabitacion(int numero, float precio, int capacidad);
        void agregarTipoDeConsumoPH(int codigo);
        void confirmarAltaDeHabitacion();
        void cancelarAltaDeHabitacion();
        set<DTEmpleado> empleadosSinAsignar();
        void seleccionarEmpleadoYCargo(string email, TipoCargo cargo);
        void confirmarAsignacionDeCargo();
        void cancelarAsignacionDeCargo();
        void finalizarAsignacionDeCargo();
        vector<string> darTopHostales();
        //set<DTResena> mostrarResena(string nombre);
        set<DTResena> darResenas();
        set<DTHabitacion> darHabitaciones();
        set<DTReserva*> darReservas();
        void finalizarConsultaHostal();
        void finalizarConsultaReserva();
        Hostal* darHostal(string nombre);

        void agregarConsumo(int codigo, string nombre, float precio);

        //Destructor
        ~CtrlHostal();
        
};

#include "Hostal.hh"
#include "TipoDeConsumo.hh"
#include "Habitacion.hh"
#include "Empleado.hh"
#include "Huesped.hh"

#endif
