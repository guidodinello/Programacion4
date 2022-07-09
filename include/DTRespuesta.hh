#ifndef __DTRESPUESTA_HH__
#define __DTRESPUESTA_HH__

#include "DTEmpleado.hh"
#include "DTFecha.hh"

#include <string>
using std::string;

class DTRespuesta{
    private:
        string comentario;
        DTEmpleado empleado;
        DTFecha fechaComentario;
    public:
        DTRespuesta(const string&, const DTEmpleado&, const DTFecha&);
        
        //Getters
        string getComentario() const;
        DTEmpleado getEmpleado() const;
        DTFecha getFechaComentario() const;
        
        //Destructor
        ~DTRespuesta();
};

#endif