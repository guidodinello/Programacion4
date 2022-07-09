#ifndef _H_Usuario_ 
#define _H_Usuario_ 


#include <iostream>
#include "DTUsuario.hh"

using std::string;

class Usuario {
    protected:
        string nombre;
        string mail;
        string password;
    public:
       
        virtual string getNombre() = 0;
        virtual string getMail() = 0;
        virtual string getPassword() = 0;
        // comentado para compilar
        virtual DTUsuario* darDT() = 0;
        //Destructor
        virtual ~Usuario() = 0;
};

#endif
