#ifndef __DTEMPLEADO_HH__
#define __DTEMPLEADO_HH__

#include "DTUsuario.hh"
#include "DTHostal.hh"

#include <string>
using std::string;

enum TipoCargo {
    Administracion, Limpieza, Recepcion, Infraestructura, sinCargo
}; 

class DTEmpleado : public DTUsuario{
    private:
    TipoCargo cargo;
    DTHostal hostal;
    bool suscrito;

    public:
        //Constructores
        DTEmpleado(string, string, TipoCargo cargo,/* DTHostal hostal,*/bool suscrito);

        //Metodos
         TipoCargo getCargo() const;
       // DTHostal getHostal();
        bool getSuscrito() const;
        string getNombre() const;
        string getMail() const;

        bool operator<(DTEmpleado const&) const;

        //Destructor
        ~DTEmpleado();
};

#endif