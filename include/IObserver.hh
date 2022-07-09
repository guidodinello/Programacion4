#ifndef _IObserver_H_
#define _IObserver_H_

//#include "Resena.hh"
class Resena;

class IObserver {
    public:
        virtual void notificar(Resena * res) = 0;

};

#include "Resena.hh"

#endif
