#ifndef _Consumicion_
#define _Consumicion_

class TipoDeConsumo;

class Consumicion{
    private:
        int cantidad;
        TipoDeConsumo* tipo;
    public:
        //Constructores
        Consumicion(int cantidad, TipoDeConsumo* tipo);

        //Metodos
        int getCantidad();
        TipoDeConsumo* getTipo(); 
        float getPrecio();

        //Sobrecargas
        

        //Destructor
        ~Consumicion();
};

#include "TipoDeConsumo.hh"

#endif
