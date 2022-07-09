#ifndef __DTUSUARIO_HH__
#define __DTUSUARIO_HH__

#include <string>
using std::string;

class DTUsuario {
    protected:
        string nombre;
        string mail;
    public:
        //DTUsuario(const string&, const string&);
        
        //Getters
        virtual string getNombre() const = 0;
        virtual string getMail() const = 0;
        
        //Destructor
        virtual ~DTUsuario() = 0;
};

#endif