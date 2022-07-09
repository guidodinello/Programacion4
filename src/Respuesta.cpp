#include "../include/Respuesta.hh"

using std::string;

Respuesta::Respuesta(const string& coment, Empleado* emp) :
    comentario(coment), 
    fechaCom(DTFecha()), 
    empleado(emp)
{}

DTRespuesta Respuesta::darDT() const {
    DTEmpleado* ptr_dte = dynamic_cast<DTEmpleado*>(empleado->darDT());
    DTEmpleado dte = *ptr_dte;
    DTRespuesta dt(comentario, dte, fechaCom);
    return dt;
}

//Destructor
Respuesta::~Respuesta(){
    
}