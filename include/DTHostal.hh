#ifndef __DTHOSTAL_HH__
#define __DTHOSTAL_HH__

#include <string>
using std::string;

class DTHostal{
    private:
        string nombre;
        string direccion;
        string telefono;
        float promedio;
        int cantCalif;
    public:
        //Constructores
        DTHostal();
        DTHostal(string nom, string dir, string tel, float prom, int canCal);

        //Getters
        string getNombre() const;
        string getDireccion() const;
        string getTelefono() const;
        float getPromedio() const;
        int getCantCalif() const;

        bool operator<(DTHostal const&) const;
};
#endif