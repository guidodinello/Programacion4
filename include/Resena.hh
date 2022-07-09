#ifndef _Resena_
#define _Resena_

#include <string>
using std::string;

#include "DTFecha.hh"
#include "DTResena.hh"
#include "DTRespuesta.hh"
#include "DTNotificacion.hh"

class Empleado;
class Estadia;
class Respuesta;

class Resena {
    private:
        int calificacion;
        string comentario;
        DTFecha fechaCal;

        Estadia* estadia;
        Respuesta* respuesta;
    public:
        //Constructores
        Resena(const string&, int);

        //Getters
        int getCalificacion() const;
        string getComentario() const;
        DTFecha getFechaCal() const;
        Estadia* getEstadia() const;
        Respuesta* getRespuesta() const;

        //setters
        void setComentario(const string&);
        void setCalificacion(int);
        void setFechaCal(const DTFecha&);
        void setEstadia(Estadia*);
        void setRespuesta(Respuesta*);

        //Metodos
        DTResena darDT(int, const DTHuesped&);
        DTRespuesta infoRespuesta();
        DTNotificacion darDTNotificacion(); // implementar
        void comentarCalificacion(const string&, Empleado*);
        bool sinResponder();
        void eliminarResena();

        //CU
        //6 DTResena darDT();


        //Destructor
        ~Resena();
};

#include "Empleado.hh"
#include "Estadia.hh"
#include "Respuesta.hh"

#endif
