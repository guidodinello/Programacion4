#ifndef _CtrlReserva__
#define _CtrlReserva__

#include "DTHostal.hh"
#include "DTHuesped.hh"
#include "DTEmpleado.hh"
#include "DTResena.hh"
#include "DTUsuario.hh"
#include "DTEstadiaL.hh"
#include "DTEstadiaC.hh"
#include "DTFecha.hh"
#include "ICtrlReserva.hh"

class Hostal;
class Huesped;
class Habitacion;
class Empleado;
class Usuario;
class Estadia;
class Reserva;
class ReservaGrupal;
class ReservaIndividual;

#include <string>
#include <iterator>
#include <map>
using std::string;
using std::map;

class CtrlReserva : public ICtrlReserva {
    private:
		static CtrlReserva* InstContR;
        map < int, Reserva*> Reservas;
        
        Hostal* HostalRecordado;
        Huesped* HuespedRecordado;
        Empleado* EmpleadoRecordado;
        Habitacion* HabitacionRecordada;
        map<string, Huesped*> HuespedesReservaRecordado;
		Estadia* EstadiaRecordada;
		Reserva* ReservaRecordada;
		DTFecha CheckIn, CheckOut;
		
		CtrlReserva();

    public:
        //
		static CtrlReserva * getInstance();
		
		set<DTHostal> darHostalesRegistrados();
		set<DTEstadiaC> darEstadias();
		set<DTReserva*> darReservasNoCanceladas();
		set<DTReserva*> darReservas();
		set<DTHuesped> darHuespedes();
    set<DTHabitacion> darHabDisponibles();
		set<DTEstadiaC> darEstadiasFinalizadasNoCalificadas();
		set<DTResena> darResenasSinResponder(string emailEmpleado);
		        
		DTHostal seleccionarHostal(string Nombre);
    void seleccionarHabitacion(int id);
		void seleccionarFecha(DTFecha ChechIn, DTFecha CheckOut);
    void seleccionarHuesped(string emailHues);
		void seleccionarEstadia(int codRes);
		DTEstadiaL seleccionarEstadiaL(int codReserva);
		DTReserva* seleccionarReserva(int codigo);
		void comentarCalificacion(DTResena resena, string coment);
		
		DTResena infoResena();
		DTRespuesta infoRespuesta();

    void asignarHuesped(string email);
        
    void darAltaReserva(bool Grupal);
		void crearResena(string msj, int calificacion);
		void darAltaEstadia();
		
		void eliminarReserva();
	
		void finalizarEstadia();
		///void comentarCalificacion()
		void finalizarConsultaEstadia();
		void finalizarBajaReserva();
        void cancelarReserva();
		void cerrarReserva();

		void suscribir(Empleado*);
		void desuscribir(Empleado* e);
		
        //Destructor
        ~CtrlReserva();
};

#include "Hostal.hh"
#include "Huesped.hh"
#include "Empleado.hh"
#include "Usuario.hh"
#include "Estadia.hh"
#include "Reserva.hh"
#include "ReservaGrupal.hh"
#include "ReservaIndividual.hh"
#include "Habitacion.hh"

#endif
