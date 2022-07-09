#include "../include/Empleado.hh"
#include "../include/Usuario.hh"


Empleado::Empleado(){

}
//string unnombre,string unpassword,string unmail,
Empleado::Empleado(string nom,string email, string pas, TipoCargo carg){
  nombre = nom;
  mail = email;
  password = pas;
  cargo = carg;
  suscripto = false;
  trabajaEn = NULL;
}

string Empleado::getNombre() {return nombre;}
string Empleado::getPassword(){return password;}
string Empleado::getMail() {return mail;}

TipoCargo Empleado::getTipoCargo() {return cargo;}
bool Empleado::getSuscripto(){return suscripto;}

DTUsuario* Empleado::darDT(){
    // DTEmpleado::DTEmpleado(const string nombre, const string mail,
    //  TipoCargo cargo, DTHostal hostal,bool suscrito)
    DTEmpleado* dte = new DTEmpleado(nombre,mail,cargo,/*trabajaEn->darDT()*/ suscripto);
    return dynamic_cast<DTUsuario*> (dte);
}

void Empleado::setTipoCargo(TipoCargo carg){
    cargo = carg;
}
void Empleado::setSuscripto(bool susc){
    suscripto = susc;
}
bool Empleado::sinAsignar(){return trabajaEn == NULL;
}

void Empleado::crearLinkH(Hostal *h){
    trabajaEn = h ;
}
        
set<DTResena> Empleado::darResenasSinResponder(){
    return trabajaEn->darResenasSinResponder();
} // chequear
        
set<DTNotificacion> Empleado::consultaNotificaciones(string email){
  set<DTNotificacion> salida;
  for (auto it = notificaciones.begin(); it != notificaciones.end(); ++it){
    Resena * ej = *it;
    salida.insert(ej->darDTNotificacion());
  }
  notificaciones.clear(); //CHEQUEAR QUE NO BORRE LAS INSTANCIAS
  return salida;
}


void Empleado::notificar(Resena * res) {
  notificaciones.insert(res);
}
//observer

void Empleado::desuscribir(){
  suscripto = false;
  notificaciones.clear();
}

Empleado::~Empleado(){
}
