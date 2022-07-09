#include "../include/Huesped.hh"

 Huesped::Huesped(){}

Huesped::Huesped(string nom, string email, string pas, bool EsFing) {
    nombre = nom;
    mail = email;
    password = pas;
    esFinger = EsFing;
}

//Metodos
string Huesped:: getNombre() { return nombre; }
string Huesped::getPassword() { return password;}
string Huesped::getMail() { return mail; }
bool Huesped:: getEsFinger() { return esFinger; }

DTUsuario* Huesped::darDT(){
       DTHuesped* dtHue = new DTHuesped(nombre,mail,esFinger);
       return dynamic_cast<DTUsuario*> (dtHue);
}

void Huesped::setEsFinger(bool esFing){
       esFinger = esFing;
}

//Operaciones 
DTEstadiaL Huesped::seleccionarEstadia(int codReserva){
      auto it = estadias.begin();
      Estadia * ej = *it;
      while ( it != estadias.end() && ej->esReservaEstadia(codReserva) == false){
        it++;
        ej = *it;
      }
      return ej->darDTL(nombre,codReserva);
} //hacer dtestadiaL

Estadia* Huesped::seleccionarEstadiaPuntero(int codReserva) {
  auto it = estadias.begin();
  Estadia * ej = *it;
      while ( it != estadias.end() && ej->esReservaEstadia(codReserva) == false){
        it++;
        ej = *it;
      }
      if (it == estadias.end()) {
        throw invalid_argument("No existe estadia con ese codigo");
      }
      return ej;
}

void Huesped::crearLinkR(Reserva *res){
       reservas[res->getCodigo()] = res;
}

void Huesped::eliminarLinkReserva(Reserva * res){
       reservas.erase(res->getCodigo());
}
void Huesped::comentarCalificacion(Empleado *empleado, string coment,int codRes){
      auto it = estadias.begin();
      Estadia * ej = *it;
      while ( it != estadias.end() && ej->esReservaEstadia(codRes) == false){
              it++;
              ej = *it;
      }
      if (it == estadias.end()){
             throw invalid_argument("No existe reserva con ese codigo asociada al Huesped");
      }
      ej->comentarCalificacion(coment,empleado);
}

void Huesped::eliminarLinkEstadia(Estadia* est){
       auto it = estadias.find(est);
      estadias.erase(it);
}

set<DTReserva*> Huesped::darReservasNoCanceladas(string nombreH){
  set<DTReserva*> salida;
  for (auto it = reservas.begin(); it != reservas.end(); ++it){
    if ((it->second->getEstado() != Cancelada) && (it->second->esHostal(nombreH))) {
      DTReserva* res = it->second->darDT();
      salida.insert(res);
    }
  }
  return salida;
}

set<DTEstadiaC> Huesped::darEstadiasFinalizadasNoCalificadas(string nombreH){
  set<DTEstadiaC> salida;
  for (auto it = estadias.begin(); it != estadias.end(); ++it)  {
    Estadia * est = *it;
    if((est->getTerminada()) && (est->noTieneResena()) && (est->esHostal(nombreH))){
      salida.insert(est->darDTC(est->getHuesped()->getMail(), nombreH, est->darCodReserva()));
    }
  }
  return salida;
}

void Huesped::crearLinkEstadia(Estadia* e) {
  estadias.insert(e);
}

void Huesped::finalizarEstadia(string NombreHos){
  for (auto it = estadias.begin(); it != estadias.end(); ++it){
    Estadia * est = *it;
    if(est->esHostal(NombreHos)) { 
      est->finalizarEstadia(); 
    }
  }
}
        
//Destructor
Huesped::~Huesped(){}
