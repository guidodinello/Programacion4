#ifndef _DTTipoDeConsumo_H_
#define _DTTipoDeConsumo_H_

#include <string>
using std::string;

class DTTipoDeConsumo {
    private:
        int codigo;
        string nombre;
        float precio;

    public:
        //Constructores
        DTTipoDeConsumo(int cod, string name, float pre);

        //Metodos
        int getCodigo() const;
        float getPrecio() const;
        string getNombre() const;
        
        bool operator<(DTTipoDeConsumo const&) const;

        //Destructor
        ~DTTipoDeConsumo();
};

#endif 
