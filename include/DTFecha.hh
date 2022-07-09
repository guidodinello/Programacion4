#ifndef __DTFECHA_HH__
#define __DTFECHA_HH__

class DTFecha{
    private:
        static int desfHora;
        static int desfDia;
        static int desfMes;
        static int desfAnio;
        
        
        int hora;
        int dia;
        int mes;
        int anio;
    public:
        DTFecha();
        DTFecha(int,int,int,int);
        bool operator == (const DTFecha&);
        bool operator < (const DTFecha&);
        bool operator > (const DTFecha&);
        
        static void modificarHoraSistema(int hora, int dia, int mes, int anio);
        static void set0();

        //Getters
        int getHora() const;
        int getDia() const;
        int getMes() const;
        int getAnio() const;
        
        //Destructor
//        ~DTFecha() = default;
        ~DTFecha();
        
};

#endif
