#ifndef _ReservaGrupal_
#define _ReservaGrupal_

#include "DTReserva.hh"
#include "DTReservaGrupal.hh"
#include "Reserva.hh"

class Resena;

class ReservaGrupal : public Reserva{
    private:

    public:
        //Constructores
        ReservaGrupal();
        //ReservaGrupal(DTFecha cI, DTFecha cO, int cod);
        ReservaGrupal(DTFecha CheckIn, DTFecha CheckOut, Habitacion* HabitacionRecordada, map<string, Huesped*>& HuespedesReservaRecordado, int cod);

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
        ~ReservaGrupal();
};

#include "Resena.hh"

#endif