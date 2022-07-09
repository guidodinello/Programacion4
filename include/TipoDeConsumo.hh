#ifndef _TipoDeConsumo_
#define _TipoDeConsumo_

#include <string>
using namespace std;
#include "DTTipoDeConsumo.hh"

class TipoDeConsumo{
    private:
        int codigo;
        string nombre;
        float precio;

    public:
        //Constructores
        TipoDeConsumo();
        TipoDeConsumo(int, string, float); // hay que crear un constructor si se quiere usar en habitacion

        //Getters y setters
        int getCodigo();
        float getPrecio();
        string getNombre();
        void setCodigo(int cod);
        void setPrecio(float pre);
        void setNombre(string name);

        DTTipoDeConsumo* darDT();

        //Destructor
        ~TipoDeConsumo();
};

#endif