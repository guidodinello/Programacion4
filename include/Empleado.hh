#ifndef __Empleado_HH__ 
#define __Empleado_HH__ 

#include "Usuario.hh"
#include "IObserver.hh"
#include "DTEmpleado.hh"
#include "DTNotificacion.hh"
#include <set>
#include <string>

using std::string;
using std::set;

class Hostal;
class Resena;

class Empleado : public Usuario, public IObserver {
    private:  
    TipoCargo cargo;    
        bool suscripto;  

        Hostal* trabajaEn;
        set<Resena*> notificaciones;
       
    public:
        //Constructores
        Empleado();
        Empleado(string nom,string email, string pas,TipoCargo carg);

         string getNombre() ;
         string getPassword() ;
         string getMail() ;
         bool getSuscripto();

         /*Hostal getTrabajaEn();
         void setTrabajaEn(Hostal *);
        */

        //Metodos
        TipoCargo getTipoCargo();
        // devuelve DTUsuario porque sino no compila
        DTUsuario* darDT();
        void setTipoCargo(TipoCargo carg);
        void setSuscripto(bool susc);

        //operaciones
        bool sinAsignar();
        void crearLinkH(Hostal *h);
        set<DTResena> darResenasSinResponder();
        void notificar(Resena * res);
        set<DTNotificacion> consultaNotificaciones(string emailEmpleado);
        void desuscribir();
        
        //Destructor
        ~Empleado();
};

#include "Hostal.hh"
#include "Resena.hh"

#endif
