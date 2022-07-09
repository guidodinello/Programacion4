#ifndef __DTRESENA_HH__
#define __DTRESENA_HH__

#include <string>
using std::string;

#include "DTHuesped.hh"
#include "DTFecha.hh"

class DTResena{
    private:
        int calificacion;
        string comentario;
        DTFecha fechaCal;
        DTHuesped huesped;
        int codReserva;
    public:
        DTResena(int,const string&,const DTFecha&, const DTHuesped&,int);
        
        //Getters
        int getCalificacion() const;
        string getComentario() const;
        DTFecha getFechaCal() const;
        DTHuesped getHuesped() const;
        int getCodReserva() const;
        
        //Destructor
        ~DTResena();
        
        bool operator<(DTResena const&) const;
};

#endif
