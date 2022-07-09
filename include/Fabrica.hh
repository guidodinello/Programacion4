#ifndef _Fabrica_
#define _Fabrica_

class ICtrlHostal;
class ICtrlReserva;
class ICtrlUsuario;

class Fabrica{
    private:
        static Fabrica * instance;
        Fabrica();
    public:
      static Fabrica* getInstance();

      ICtrlHostal* getICtrlHostal();
      ICtrlReserva* getICtrlReserva();
      ICtrlUsuario* getICtrlUsuario();

      ~Fabrica();
};

#include "ICtrlHostal.hh"
#include "ICtrlReserva.hh"
#include "ICtrlUsuario.hh"

#endif