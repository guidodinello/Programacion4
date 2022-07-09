#ifndef __DTNotificacion_H__
#define __DTNotificacion_H__

#include <string>
using std::string;

class DTNotificacion{
    private:
        string autor;
        int calificacion;
        string comentario;
    public:
        //Constructores
        DTNotificacion(const string&, int, const string&);

        //Getters
        string getAutor() const;
        int getCalificacion() const;
        string getComentario() const;

        bool operator<(DTNotificacion const&) const;

        //Destructor
        ~DTNotificacion();
};

#endif