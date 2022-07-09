#ifndef __ICTRL_USUARIO_HH__
#define __ICTRL_USUARIO_HH__

#include <string>
using std::string;

#include <set>
using std::set;

#include "DTResena.hh"
#include "DTUsuario.hh"
#include "DTEmpleado.hh" 
#include "DTHuesped.hh"
#include "DTNotificacion.hh" 

class Huesped;
class Empleado;

class ICtrlUsuario{
    public:
        virtual Empleado* encontrarEmpleado(const string&) = 0;
        virtual bool ingresarDatosUsuario(const string&, const string&, const string&) = 0;
        virtual bool actualizarMail(const string&) = 0;
        virtual void cancelarAltaUsuario() = 0;
        virtual void ingresarTipoDeCargo(TipoCargo) = 0;
        virtual void esFingerUsuario(bool) = 0;
        virtual void darDeAltaUsuario() = 0;
        virtual Huesped* darHuesped(const string&) = 0;
        virtual set<DTHuesped> darHuespedes() = 0;
        virtual set<DTUsuario *> darUsuarios() = 0;
        virtual DTUsuario* consultarUsuario(const string&) = 0;
        virtual set<DTEmpleado> darEmpleados() = 0;
        //virtual set<DTResena> darResenasSinResponder(const string&) = 0;
        virtual void comentarCalificacion(Empleado*,const string&, const string&, int) = 0;

        virtual set<DTNotificacion> consultaNotificaciones(const string& emailEmpleado) = 0; 
		virtual void eliminarSuscripcion(string email) = 0;	
        virtual void suscribirse(const string&) = 0;

        virtual ~ICtrlUsuario() {};
};

#include "Huesped.hh"
#include "Empleado.hh"

#endif
