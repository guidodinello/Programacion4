#include "../include/DTFecha.hh"
#include <time.h>

int DTFecha::desfAnio=0;
int DTFecha::desfDia=0;
int DTFecha::desfHora=0;
int DTFecha::desfMes=0;


// Devuelve fecha y hora actual del sistema
DTFecha::DTFecha() {
    time_t ahora;
    time(&ahora);
    struct tm *fecha = localtime(&ahora);
    hora = fecha->tm_hour + DTFecha::desfHora;
    dia = fecha->tm_mday + DTFecha::desfDia;
    mes = fecha->tm_mon+1 + DTFecha::desfMes;
    anio = fecha->tm_year+1900 + DTFecha::desfAnio;
}


DTFecha::DTFecha(int h, int d, int m, int a) { 
    hora = h;
    dia = d;
    mes = m;
    anio = a;
}

void DTFecha::modificarHoraSistema(int hora, int dia, int mes, int anio){
  time_t ahora;
  time(&ahora);
  struct tm *fecha = localtime(&ahora);       
  DTFecha::desfAnio = anio -(fecha->tm_year+1900);
  DTFecha::desfDia = dia-fecha->tm_mday;
  DTFecha::desfHora = hora-fecha->tm_hour;
  DTFecha::desfMes = mes-(fecha->tm_mon+1);
}

void DTFecha::set0(){
  DTFecha::desfAnio = 0;
  DTFecha::desfDia = 0;
  DTFecha::desfHora = 0;
  DTFecha::desfMes = 0;
}

bool DTFecha::operator == (const DTFecha& other){
  return hora == other.hora && dia == other.dia && mes == other.mes && anio == other.anio; 
}

bool DTFecha::operator < (const DTFecha& other){
  if (anio < other.anio) {return true;}
  else if (mes < other.mes) {return true;}
  else if (dia < other.dia) {return true;}
  else if (hora < other.hora) {return true;}
  else return false;
}

bool DTFecha::operator > (const DTFecha& other){
  if (anio > other.anio) {return true;}
  else if (mes > other.mes) {return true;}
  else if (dia > other.dia) {return true;}
  else if (hora > other.hora) {return true;}
  else return false;
}



int DTFecha::getHora() const {
    return hora;
}

int DTFecha::getDia() const {
    return dia;
}

int DTFecha::getMes() const {
    return mes;
}

int DTFecha::getAnio() const {
    return anio;
}

DTFecha::~DTFecha() {};
