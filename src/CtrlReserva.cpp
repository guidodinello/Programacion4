#include "../include/CtrlReserva.hh"
#include "../include/CtrlHostal.hh"
#include "../include/CtrlUsuario.hh"

CtrlReserva* CtrlReserva::InstContR = NULL;

CtrlReserva* CtrlReserva::getInstance(){
    if(InstContR == NULL){
        InstContR = new CtrlReserva();
    }
    return InstContR;
}

CtrlReserva::CtrlReserva(){

}

//Dar listas
set<DTHostal> CtrlReserva::darHostalesRegistrados(){
	CtrlHostal* ctrlHost = CtrlHostal::getInstance();
	return ctrlHost->darHostalesRegistrados();
}

set<DTEstadiaC> CtrlReserva::darEstadias(){
	return HostalRecordado->darEstadias();
}

set<DTReserva*> CtrlReserva::darReservas(){
	return HostalRecordado->darReservas();
}

set<DTReserva*> CtrlReserva::darReservasNoCanceladas(){
	string nombreH=HostalRecordado->getNombre();
	return HuespedRecordado->darReservasNoCanceladas(nombreH);
}

set<DTHuesped> CtrlReserva::darHuespedes(){
	CtrlUsuario* ctrlUsr = CtrlUsuario::getInstance();
	return ctrlUsr->darHuespedes();
}

set<DTHabitacion> CtrlReserva::darHabDisponibles(){
	return HostalRecordado->darHabitacionesDispH(CheckIn, CheckOut);
}

set<DTEstadiaC> CtrlReserva::darEstadiasFinalizadasNoCalificadas(){
	string nombreH=HostalRecordado->getNombre();
	return HuespedRecordado->darEstadiasFinalizadasNoCalificadas(nombreH);
}

set<DTResena> CtrlReserva::darResenasSinResponder(string emailEmpleado){
	CtrlUsuario* ctrlUsu = CtrlUsuario::getInstance();
	EmpleadoRecordado = ctrlUsu->encontrarEmpleado(emailEmpleado);
	return EmpleadoRecordado->darResenasSinResponder();
}

		        
//Seleccionar
DTHostal CtrlReserva::seleccionarHostal(string Nombre){
	CtrlHostal* ctrlH = CtrlHostal::getInstance();
	HostalRecordado=ctrlH->darHostal(Nombre);
	return HostalRecordado->darDT();
}
	
void CtrlReserva::seleccionarHabitacion(int id){
	HabitacionRecordada = HostalRecordado->darHabitacion(id);
}

void CtrlReserva::seleccionarFecha(DTFecha CheckIn, DTFecha CheckOut){
	this->CheckIn=CheckIn;
	this->CheckOut=CheckOut;
}

void CtrlReserva::seleccionarHuesped(string emailHues){
	CtrlUsuario* ctrlUs = CtrlUsuario::getInstance();
	HuespedRecordado = ctrlUs->darHuesped(emailHues);
	HuespedesReservaRecordado[emailHues] = HuespedRecordado;
}

void CtrlReserva::seleccionarEstadia(int codRes){
	EstadiaRecordada = HuespedRecordado->seleccionarEstadiaPuntero(codRes);
}

// o selecciona o devuelve el DT
DTEstadiaL CtrlReserva::seleccionarEstadiaL(int codReserva){
	EstadiaRecordada = HuespedRecordado->seleccionarEstadiaPuntero(codReserva);
	return EstadiaRecordada->darDTL(HuespedRecordado->getMail(), codReserva);
}

DTReserva* CtrlReserva::seleccionarReserva(int codigo){
	auto it = Reservas.find(codigo);
	if (it == Reservas.end()) {throw invalid_argument("No existe reserva con ese codigo"); } 
	ReservaRecordada = it->second;
	return ReservaRecordada->darDT();
}
		
		
//PEDIR INFORMACION
DTResena CtrlReserva::infoResena(){
	if (EstadiaRecordada->getResena()==NULL) {throw invalid_argument("No hay resena para esa estadia"); }
	return EstadiaRecordada->infoComentario();
}

DTRespuesta CtrlReserva::infoRespuesta(){
	return EstadiaRecordada->infoRespuesta();
}


//OTROS
void CtrlReserva::asignarHuesped(string email){
	CtrlUsuario* ctrlUs = CtrlUsuario::getInstance();
	Huesped* hues = ctrlUs->darHuesped(email); 
	HuespedesReservaRecordado[email] = hues;
}

// ver si  esta bien lo de codigo
static int codigo = 0;    
void CtrlReserva::darAltaReserva(bool Grupal){
	Reserva* r;
	if (Grupal)
		r = new ReservaGrupal(CheckIn, CheckOut, HabitacionRecordada, HuespedesReservaRecordado, codigo);
	else {
		r = new ReservaIndividual(CheckIn, CheckOut, HabitacionRecordada, HuespedRecordado, codigo);
	}
	Reservas[codigo] = r; 
	codigo++;
	HabitacionRecordada->crearLinkR(r);
	for (auto it = HuespedesReservaRecordado.begin(); it != HuespedesReservaRecordado.end(); ++it){
		it->second->crearLinkR(r);
	}

	HabitacionRecordada = NULL;
	HuespedRecordado = NULL;
	HostalRecordado = NULL;
	HuespedesReservaRecordado.clear();

	for (auto it = HuespedesReservaRecordado.begin(); it != HuespedesReservaRecordado.end(); ++it){
		cout << it->first << endl;
	}
}

void CtrlReserva::crearResena(string msj, int calificacion){
	EstadiaRecordada->crearResena(msj, calificacion);
}

void CtrlReserva::darAltaEstadia(){ //Pongo check in es check out porque la data en CheckOut es ivalida.
	Estadia* e = new Estadia(CheckIn, CheckIn, false, ReservaRecordada, HuespedRecordado );
	ReservaRecordada->crearLinkEstadia(e);
	HuespedRecordado->crearLinkEstadia(e);
}

void CtrlReserva::comentarCalificacion(DTResena resena, string coment){
	DTHuesped hues=resena.getHuesped();
	string emailH=hues.getMail();
	int codReserva=resena.getCodReserva();
	
	CtrlUsuario* ctrlUs = CtrlUsuario::getInstance();
	ctrlUs->comentarCalificacion(EmpleadoRecordado, coment, emailH, codReserva);
}
		
void CtrlReserva::eliminarReserva(){
	ReservaRecordada->eliminarReserva();
	int codigo= ReservaRecordada->getCodigo();
	Reservas.erase(codigo);//SACAR A RESERVA DE LA LISTA DE RESERVAS DEL CTRL
	delete ReservaRecordada;
}

void CtrlReserva::finalizarEstadia(){
	string nombre=HostalRecordado->getNombre();
	HuespedRecordado->finalizarEstadia(nombre);
}

void CtrlReserva::cerrarReserva(){
	ReservaRecordada->setEstado(Cerrada);
}

//Finalizar y cancelar
void CtrlReserva::finalizarConsultaEstadia(){
	HostalRecordado= NULL;
	HuespedRecordado= NULL;
	EstadiaRecordada = NULL;
	ReservaRecordada= NULL;
}


void CtrlReserva::finalizarBajaReserva(){
		HostalRecordado=NULL;
		ReservaRecordada=NULL;
}
	
void CtrlReserva::cancelarReserva(){
	HostalRecordado = NULL;
	HabitacionRecordada=NULL;
	HuespedRecordado=NULL;
	HuespedesReservaRecordado.clear();
	// delete CheckIn;
	// delete CheckOut;
}

void CtrlReserva::suscribir(Empleado* e){
	Estadia::suscribir(e);
}
void CtrlReserva::desuscribir(Empleado* e){
	Estadia::desuscribir(e);
}


//Destructor
CtrlReserva::~CtrlReserva() {
	for (auto it = Reservas.begin(); it != Reservas.end(); ++it){
		delete it->second;
	}
	Reservas.clear();
	// huespedes se libera al liberar los de CtrlUsuario
};
