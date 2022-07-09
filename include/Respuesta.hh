#ifndef _Respuesta_
#define _Respuesta_

#include <string>
using std::string;

#include "DTFecha.hh"
#include "DTRespuesta.hh"

class Empleado;

class Respuesta {
    private:
        string comentario;
        DTFecha fechaCom;
        Empleado* empleado;
    public:
        //Constructores
        Respuesta(const string&, Empleado*);

        DTRespuesta darDT() const;

        //Destructor
        ~Respuesta();
};

#include "Empleado.hh"

#endif