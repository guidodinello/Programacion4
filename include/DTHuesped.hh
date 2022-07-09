#ifndef __DTHUESPED_HH__
#define __DTHUESPED_HH__



#include "DTUsuario.hh"
#include "iostream"
using std::string;

class DTHuesped : public DTUsuario {
    private:
        bool esFinger;

    public:
        DTHuesped(const string, const string, bool);
        
        //Getters
        bool getEsFinger() const;
        string getNombre() const;
        string getMail() const;

        bool operator<(DTHuesped const&) const;
        
        //Destructor
        ~DTHuesped();
};

#endif