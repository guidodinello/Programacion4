#ifndef _Huesped_ 
#define _Huesped_ 

#include "DTHuesped.hh"
#include "DTEstadiaC.hh"
#include "DTEstadiaL.hh"
#include "DTReserva.hh"
#include "Usuario.hh"
#include <map>
#include <set>
#include <string>

using std::string;
using std::set;
using std::map;

class Reserva;
class Estadia;
class Empleado;

class Huesped : public Usuario {
    private:
        bool esFinger;
        map<int, Reserva*> reservas;
        set<Estadia*> estadias;
    public:
        //Constructores
        Huesped();
        Huesped(string nom, string email, string pas, bool EsFing);

        //Metodos
        string getNombre();
        string getPassword();
        string getMail();

        bool getEsFinger();
        
        // devuelve DTUsuario porque sino no compila
        DTUsuario* darDT();
        void setEsFinger(bool);

        //operaciones 
        DTEstadiaL seleccionarEstadia(int codReserva);
        Estadia* seleccionarEstadiaPuntero(int codReserva);
        void crearLinkR(Reserva *res);
        void eliminarLinkReserva(Reserva *res);
        void comentarCalificacion(Empleado* empleado, string coment,int codres);
        void eliminarLinkEstadia(Estadia *est);
        set<DTReserva*> darReservasNoCanceladas(string nombreH);
        set<DTEstadiaC> darEstadiasFinalizadasNoCalificadas(string nombreH);
        void crearLinkEstadia(Estadia* e);
        void finalizarEstadia(string NombreHos);

        
        //Destructor
        ~Huesped();
};

#include "Reserva.hh"
#include "Estadia.hh"
#include "Empleado.hh"

#endif
