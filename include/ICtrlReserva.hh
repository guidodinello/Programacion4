#ifndef __ICTRL_RESERVA_HH__
#define __ICTRL_RESERVA_HH__

#include <string>
using std::string;

#include <set>
using std::set;

#include "DTResena.hh"
#include "DTReserva.hh"
#include "DTHuesped.hh"
#include "DTHabitacion.hh"
#include "DTEstadiaC.hh"
#include "DTEstadiaL.hh"
#include "DTRespuesta.hh"

class ICtrlReserva {
    public:
		
		virtual set<DTHostal> darHostalesRegistrados() = 0;
		virtual set<DTEstadiaC> darEstadias() = 0;
		virtual set<DTReserva*> darReservasNoCanceladas() = 0;
		virtual set<DTReserva*> darReservas() = 0;
		virtual set<DTHuesped> darHuespedes() = 0;
        virtual set<DTHabitacion> darHabDisponibles() = 0;
		virtual set<DTEstadiaC> darEstadiasFinalizadasNoCalificadas() = 0;
		virtual set<DTResena> darResenasSinResponder(string) = 0;
		        
		virtual DTHostal seleccionarHostal(string) = 0;
        virtual void seleccionarHabitacion(int id) = 0;
		virtual void seleccionarFecha(DTFecha, DTFecha) = 0;
        virtual void seleccionarHuesped(string) = 0;
		virtual void seleccionarEstadia(int) = 0;
		virtual DTEstadiaL seleccionarEstadiaL(int) = 0;
		virtual DTReserva* seleccionarReserva(int) = 0;
		
		virtual DTResena infoResena() = 0;
		virtual DTRespuesta infoRespuesta() = 0;

        virtual void asignarHuesped(string) = 0;
        
        virtual void darAltaReserva(bool) = 0;
		virtual void crearResena(string, int) = 0;
		virtual void darAltaEstadia() = 0;
		
		virtual void eliminarReserva() = 0;
	
		virtual void finalizarEstadia() = 0;
		virtual void comentarCalificacion(DTResena resena, string coment) = 0;
		virtual void finalizarConsultaEstadia() = 0;
		virtual void finalizarBajaReserva() = 0;
        virtual void cancelarReserva() = 0;
		virtual void cerrarReserva() = 0;
		
		virtual ~ICtrlReserva() {};
};

#endif