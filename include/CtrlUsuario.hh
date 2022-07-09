#ifndef _CtrlUsuario_
#define _CtrlUsuario_

#include "DTUsuario.hh"
#include "DTResena.hh"
#include "DTHuesped.hh"
#include "ICtrlUsuario.hh"

class Empleado;
class Huesped;
class Usuario;

#include <set>
#include <string>
using std::set;
using std::string;

struct nuevoUsuario{
    string nombre;
    string password;
    string mail;
    bool esFinger;
    TipoCargo cargo;
    bool esEmpleado;
};

class CtrlUsuario : public ICtrlUsuario
{
private:
    static CtrlUsuario* instance;
    map<string, Huesped*> huespedes;
    map<string, Empleado*> empleados;
    map<string, Usuario*> usuarios;
    Usuario* usuarioSeleccionado; 
    nuevoUsuario * datonuevousuario;    

    CtrlUsuario();
public:
  

    static CtrlUsuario* getInstance();
    Empleado* encontrarEmpleado(const string& emailEmplado);
    bool ingresarDatosUsuario(const string& nombre, const string& mail, const string& password);
    bool actualizarMail(const string& nuevoMail);
    void cancelarAltaUsuario();
    void ingresarTipoDeCargo(TipoCargo tipo);
    void esFingerUsuario(bool es);
    void darDeAltaUsuario();
    Huesped* darHuesped(const string& email);
    void suscribirse(const string& email);
    set<DTUsuario*> darUsuarios();
    DTUsuario* consultarUsuario(const string& email);
    set<DTEmpleado> darEmpleados();
    //set<DTResena> darResenasSinResponder(const string& emailEmpleado);
    void comentarCalificacion(Empleado* empleado,const string& coment, const string& emailH, int codRes);
    void eliminarSuscripcion(string email);
    set<DTEmpleado> darEmpleadosSA();

    set<DTNotificacion> consultaNotificaciones(const string& emailEmpleado); 
    Empleado* buscarEmpleado(const string& email);
   
    // se agrego por caso de uso 5
    set<DTHuesped> darHuespedes();


   //destructor
    ~CtrlUsuario();


};
#include "Empleado.hh"
#include "Huesped.hh"
#include "Usuario.hh"


#endif
