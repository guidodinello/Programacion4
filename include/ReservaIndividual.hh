#ifndef _ReservaIndividual_
#define _ReservaIndividual_

#include "DTReserva.hh"
#include "DTReservaIndividual.hh"
#include "Reserva.hh"

class Resena;

class ReservaIndividual : public Reserva {
    private:
        
    public:
        //Constructores
        ReservaIndividual();
        //ReservaIndividual(DTFecha cI, DTFecha cO, int cod);
        ReservaIndividual(DTFecha CheckIn, DTFecha CheckOut, Habitacion* HabitacionRecordada, Huesped* HuespedRecordado, int cod);

        //Getters
        DTFecha getCheckIn() const;
        DTFecha getCheckOut() const;
        int getCodigo() const;
        EstadoReserva getEstado() const;
        Habitacion* getHabitacion() const;
        map<string, Huesped*> getHuespedes() const;
        set<Estadia*> getEstadias() const;
        float getCosto();
        
        //setters
        void setEstado(EstadoReserva es);

        //Operaciones
        DTReserva* darDT();
        bool estaDisponibleReserva(DTFecha CheckIn, DTFecha CheckOut);
        bool esHostal(string nombreH);
        bool esEstadiaReserva(int codReserva);
        void actualizarPromedioHostal(int calificacion);
        //set<DTResena> mostrarResena();
        set<DTResena> darResenas();
        set<DTResena> darResenasSinResponder();
        void eliminarReserva();
        int darIdH();
        string darNombreH();
        set<DTEstadiaC> darEstadias(string nombreH);

        //se agrego por darAltaEstadia de controlador Reserva
        void crearLinkEstadia(Estadia* e);
        

        //Destructor
        ~ReservaIndividual();
};

#include "Resena.hh"

#endif