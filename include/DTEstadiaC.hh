#ifndef __DTESTADIAC_HH__
#define __DTESTADIAC_HH__

#include <string>
using std::string;

#include "DTFecha.hh"

class DTEstadiaC{
    private:
        string mailH;
        string nombreHostal;
        DTFecha checkIn;
        DTFecha checkOut;
        int codReserva;
    public:
        DTEstadiaC(const string&, const string&, const DTFecha&, const DTFecha&,int);
        
        //Getters
        string getMail() const;
        string getNombreHostal() const;
        DTFecha getCheckIn() const;
        DTFecha getCheckOut() const;
        int getCodReserva() const;

        bool operator<(DTEstadiaC const&) const;
        
        //Destructor
        ~DTEstadiaC();
};

#endif