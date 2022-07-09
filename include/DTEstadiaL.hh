#ifndef __DTESTADIAL_HH__
#define __DTESTADIAL_HH__

#include "DTFecha.hh"

#include <string>
using std::string;


class DTEstadiaL{
    private:
        DTFecha checkIn;
        DTFecha checkOut;
        string mailHuesped;
        string nombreHostal;
        int numeroHab;
        bool terminada;
        float totalConsumo;
        int codigoReserva;
    public:
        DTEstadiaL(const DTFecha& cI, const DTFecha& cO, const string& mailHuesped, const string& nombreHostal, int numeroHab, bool terminada, float totalConsumo, int codigoReserva);
        
        DTFecha getCheckIn() const;
        DTFecha getCheckOut() const;
        string getMailHuesped() const;
        string getNombreHostal() const;
        int getNumeroHab() const;
        bool getTerminada() const;
        float getTotalConsumo() const;
        int getCodigoReserva() const;

        bool operator<(DTEstadiaL const&) const;

        ~DTEstadiaL();
};

#endif