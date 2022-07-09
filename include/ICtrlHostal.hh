#ifndef _ICtrlHostal_
#define _ICtrlHostal_

#include "DTHostal.hh"
#include "DTEmpleado.hh"
#include "DTResena.hh" 
#include "DTHabitacion.hh"
#include "DTReserva.hh"
#include <set>
#include <string>
#include <vector>
using std::vector;
using std::string;

class Hostal;

class ICtrlHostal{
public:
  virtual void darAltaNuevoHostal(string nombre, string dire, string tel) = 0;
  virtual set<DTHostal> darHostalesRegistrados() = 0;
  virtual DTHostal seleccionarHostal(string nombre) = 0;
  virtual void ingresarDatosNuevaHabitacion(int numero, float precio, int capacidad) = 0;
  virtual void agregarTipoDeConsumoPH(int codigo) = 0;
  virtual void confirmarAltaDeHabitacion() = 0;
  virtual void cancelarAltaDeHabitacion() = 0;
  virtual set<DTEmpleado> empleadosSinAsignar() = 0;
  virtual void seleccionarEmpleadoYCargo(string email, TipoCargo cargo) = 0;
  virtual void confirmarAsignacionDeCargo() = 0;
  virtual void cancelarAsignacionDeCargo() = 0;
  virtual void finalizarAsignacionDeCargo() = 0;
  virtual vector<string> darTopHostales() = 0;
  //virtual set<DTResena> mostrarResena(string nombre) = 0;
  virtual set<DTResena> darResenas() = 0;
  virtual set<DTHabitacion> darHabitaciones()= 0;
  virtual set<DTReserva*> darReservas()= 0;
  virtual void finalizarConsultaHostal()= 0;
  virtual void finalizarConsultaReserva()= 0;
  virtual Hostal* darHostal(string nombre)= 0;
  
  virtual set<DTTipoDeConsumo> getTiposDeConsumo()=0;  
  virtual void agregarConsumo(int codigo, string nombre, float precio) = 0;

  virtual ~ICtrlHostal() {};
};



#include "Hostal.hh"

#endif
