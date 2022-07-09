#include "include/DTFecha.hh"
#include "include/DTHuesped.hh"
#include "include/DTEmpleado.hh"
#include "include/DTEstadiaC.hh"
#include "include/DTEstadiaL.hh"
#include "include/DTHabitacion.hh"
#include "include/DTHostal.hh"
#include "include/DTReserva.hh"
#include "include/DTTipoDeConsumo.hh"
#include "include/DTUsuario.hh"
#include "include/DTNotificacion.hh"

#include "include/Huesped.hh"
#include "include/Empleado.hh"
#include "include/Habitacion.hh" // Hasta aca bien
#include "include/Hostal.hh"
#include "include/Reserva.hh"
#include "include/ReservaGrupal.hh"
#include "include/ReservaIndividual.hh"
#include "include/Respuesta.hh"
#include "include/Resena.hh"
#include "include/TipoDeConsumo.hh"
#include "include/Usuario.hh"
#include "include/Estadia.hh"
#include "include/Fabrica.hh"
#include "include/ICtrlHostal.hh"
#include "include/ICtrlReserva.hh"
#include "include/ICtrlUsuario.hh"
#include "include/IObserver.hh"
#include <iostream>
using namespace std;
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::string;

void Menu() {
    cout << "   Menu \n";
    cout << "0. Cargar Datos\n";
    cout << "1. Alta de Usuario\n";
    cout << "2. Alta de Hostal\n";
    cout << "3. Alta de Habitación\n";
    cout << "4. Asignar empleado a hostal\n";
    cout << "5. Realizar Reserva\n";
    cout << "6. Consultar top 3 de hostales\n";
    cout << "7. Registrar estadía\n";
    cout << "8. Finalizar Estadía\n";
    cout << "9. Calificar estadía\n";
    cout << "10. Comentar calificación\n";
    cout << "11. Consulta de Usuario\n";
    cout << "12. Consulta de Hostal\n";
    cout << "13. Consulta de Reserva\n";
    cout << "14. Consulta de Estadía\n";
    cout << "15. Baja de reserva\n";
    cout << "16. Modificar Fecha del Sistema\n";
    cout << "17. Eliminar suscripcion\n";
    cout << "18. Consulta de notificacion\n";
    cout << "19. Suscribirse a Notificaciones\n";
    cout << "20. Alta tipo de Consumo\n";
    cout << "21. Dar tipos de consumo\n";
    cout << "22. Salir\n";
}

#define MAX_int 99999999
template <typename T>
void validate(T &a, const string &nombre_tipo, const T &min, const T &max) {
    while (cin.fail()) {
        cin.clear();           // clear input buffer to restore cin to a usable state
        cin.ignore(100, '\n'); // ignore last input
        cout << "Error: Deberias ingresar un " << nombre_tipo << "." << endl;
        cout << "Ingrese el " << nombre_tipo << ": ";
        cin >> a;
    }
    while (a < min || a > max) {
        cout << "Error: Deberias ingresar un " << nombre_tipo << " entre " << min << " y " << max << "." << endl;
        cout << "Ingrese el " << nombre_tipo << ": ";
        cin >> a;
    }
    cin.ignore();
}

DTFecha pedirFecha() {
    int hora, dia, mes, anio;
    cout << "Ingrese hora: ";
    cin >> hora;
    cout << "Ingrese dia: ";
    cin >> dia;
    cout << "Ingrese mes: ";
    cin >> mes;
    cout << "Ingrese anio: ";
    cin >> anio;
    return DTFecha(hora, dia, mes, anio);
}

TipoCargo leerTipoDeCargo(int tc) {
    bool incorrecto = true;
    while (incorrecto) {
        cout << "Ingresar tipo de cargo \n0:Administracion\n1:Limpieza\n2:Recepcion\n3:Infraestructura\n" << endl;
        cin >> tc; // getline?
        if (tc > 4 || tc < 0) {
            cout << "Tipo de cargo invalido" << endl;
        }
        else {
            incorrecto = false;
        }
    }
    return (TipoCargo)tc;
}

ostream &operator<<(ostream &os, const DTNotificacion &n) {
    os << "###############  NOTIFICACION  ################" << endl;
    os << "Autor: " << n.getAutor() << endl;
    os << "Calificacion: " << n.getCalificacion() << endl;
    os << "Comentario: \n"
       << n.getComentario() << endl;
    os << "###############################################" << endl;
    return os;
}

ostream &operator<<(ostream &os, const DTHostal &h) {
    os << "###############  HOSTAL  ################" << endl;
    os << "Hostal: " << h.getNombre() << endl;
    os << "Direccion: " << h.getDireccion() << endl;
    ;
    os << "Telefono: " << h.getTelefono() << endl;
    os << "Promedio: " << h.getPromedio() << endl;
    os << "#########################################" << endl;
    return os;
}

ostream &operator<<(ostream &os, const DTTipoDeConsumo &t) {
    os << "Nombre: " << t.getNombre() << endl;
    os << "Codigo: " << t.getCodigo() << endl;
    os << "Precio: " << t.getPrecio() << endl;
    return os;
}

ostream &operator<<(ostream &os, const DTEmpleado &e) {
    os << "Nombre: " << e.getNombre() << endl;
    os << "Mail: " << e.getMail() << endl;
    os << "Cargo: ";
    switch (e.getCargo()) {
    case 0: {
        os << "Administracion" << endl;
        break;
    }
    case 1: {
        os << "Limpieza" << endl;
        break;
    }
    case 2: {
        os << "Recepcion" << endl;
        break;
    }
    case 3: {
        os << "Infraestructura" << endl;
        break;
    }
    case 4: {
        os << "Sin Cargo" << endl;
        break;
    }
    }
    return os;
}

ostream &operator<<(ostream &os, const DTHuesped &e) {
    os << "Nombre: " << e.getNombre() << endl;
    os << "Mail: " << e.getMail() << endl;
    os << "Es finger: ";
    if (e.getEsFinger()){
        os << "Si" << endl;
    }
    else{
        os << "No" << endl;
    }
    return os;
}

ostream &operator<<(ostream &os, DTUsuario *usu) {
    os << "############## Usuario #################" << endl;
    DTHuesped *h = dynamic_cast<DTHuesped *>(usu);
    if (h != NULL) {
        os << *h;
    }
    else {
        DTEmpleado *e = dynamic_cast<DTEmpleado *>(usu);
        os << *e;
    }
    os << "########################################" << endl;
    return os;
}

ostream &operator<<(ostream &os, const set<DTHuesped> &e) {
    for (auto it = e.begin(); it != e.end(); ++it) {
        os << *it << endl;
    }
    return os;
}

ostream &operator<<(ostream &os, const DTFecha &e) {
    os << "  Hora: " << e.getHora() << endl;
    os << "  Dia: " << e.getDia() << endl;
    os << "  Mes: " << e.getMes() << endl;
    os << "  Anio: " << e.getAnio() << endl;
    return os;
}

ostream &operator<<(ostream &os, const DTEstadiaC &e) {
    os << "########### ESTADIA ###########" << endl;
    os << "Mail Huesped: " << e.getMail() << endl;
    os << "CheckIn: \n"
       << e.getCheckIn() << endl;
    if (e.getCheckIn() == e.getCheckOut()) {
        os << "Estado: Sin finalizar" << endl;
    }
    else {
        os << "CheckOut: \n"
           << e.getCheckOut() << endl;
    }
    os << "Codigo Reserva: " << e.getCodReserva() << endl;
    os << "###############################" << endl;
    return os;
}

ostream &operator<<(ostream &os, const DTEstadiaL &e) {
    os << "########### ESTADIA ###########" << endl;
    os << "Mail Huesped: " << e.getMailHuesped() << endl;
    os << "CheckIn: \n"
       << e.getCheckIn() << endl;
    os << "CheckOut: \n"
       << e.getCheckOut() << endl;
    os << "Codigo Reserva: " << e.getCodigoReserva() << endl;
    os << "Hostal: " << e.getNombreHostal() << endl;
    os << "Habitacion: " << e.getNumeroHab() << endl;
    // os << "Terminada: " << e.getTerminada() << endl;
    os << "Total consumido: " << e.getTotalConsumo() << endl;
    os << "###############################" << endl;
    return os;
}

ostream &operator<<(ostream &os, const DTResena &e) {
    os << "#################### RESENA ####################" << endl;
    os << "Calificacion: " << e.getCalificacion() << endl;
    os << "Comentario: " << e.getComentario() << endl;
    os << "Fecha: " << e.getFechaCal() << endl;
    os << "Huesped: " << e.getHuesped() << endl;
    os << "Codigo reserva: " << e.getCodReserva() << endl;
    os << "################################################" << endl;
    return os;
}

ostream &operator<<(ostream &os, const set<DTTipoDeConsumo> &t) {
    for (auto it = t.begin(); it != t.end(); ++it) {
        os << "Nombre: " << it->getNombre() << endl;
        os << "Codigo: " << it->getCodigo() << endl;
        os << "Precio: " << it->getPrecio() << endl;
    }
    return os;
}

ostream &operator<<(ostream &os, const DTHabitacion &e) {
    os << "########### Datos de Habitacion ###########" << endl;
    os << "Id: " << e.getId() << endl;
    os << "Precio: $" << e.getPrecio() << endl;
    os << "Capacidad: " << e.getCapacidad() << endl;
    os << "Tipos de consumo: " << e.getTipos() << endl;
    os << "############################################" << endl;
    return os;
}

ostream &operator<<(ostream &os, const DTRespuesta &e) {
    os << "########### RESPUESTA ###########" << endl;
    os << "Comentario: " << e.getComentario() << endl;
    os << "Empleado: " << e.getEmpleado() << endl;
    os << "Fecha: " << e.getFechaComentario() << endl;
    os << "#################################" << endl;
    return os;
}
ostream &operator<<(ostream &os, const map<string, Huesped *> &e) { // para el getHuespedes de la sobrecarga de DTReserva
    for (auto it = e.begin(); it != e.end(); ++it) {
        os << " Nombre: " << it->second->getNombre() << endl;
        os << " Mail: " << it->second->getMail() << endl;
        os << " Es finger: " << it->second->getEsFinger() << endl;
    }
    return os;
}

ostream &operator<<(ostream &os, const set<string> &e) {
    for (auto it = e.begin(); it != e.end(); ++it) {
        os << " " << *it << endl;
    }
    return os;
}

ostream &operator<<(ostream &os, const EstadoReserva &e) {
    switch (e) {
    case 0: {
        os << "Abierta";
        break;
    }
    case 1: {
        os << "Cerrada";
        break;
    }
    case 2: {
        os << "Cancelada";
        break;
    }
    default: {
        os << "Error";
    }
    }
    return os;
}

ostream &operator<<(ostream &os, const DTReserva &r) {
    os << "#################### RESERVA ####################" << endl;
    os << "Codigo: " << r.getCodigo() << endl;
    os << "Check In: \n"
       << r.getCheckIn() << endl;
    os << "Check Out: \n"
       << r.getCheckOut() << endl;
    os << "Estado: " << r.getEstado() << endl;
    os << "Huespedes: \n" << r.getHuespedes() << endl;
    os << "Numero de habitacion: " << r.getNumeroHabitacion() << endl;
    os << "##################################################" << endl;
    return os;
}

void cargarDatos(Fabrica *f) {

    ICtrlUsuario *cu = f->getICtrlUsuario();
    ICtrlHostal *ch = f->getICtrlHostal();
    ICtrlReserva *cr = f->getICtrlReserva();

    // Empleados
    cu->ingresarDatosUsuario("Emilia", "emilia@mail.com", "123");
    cu->ingresarTipoDeCargo(Recepcion);
    cu->darDeAltaUsuario();

    cu->ingresarDatosUsuario("Leonardo", "leo@mail.com", "123");
    cu->ingresarTipoDeCargo(Recepcion);
    cu->darDeAltaUsuario();

    cu->ingresarDatosUsuario("Alina", "alina@mail.com", "123");
    cu->ingresarTipoDeCargo(Recepcion);
    cu->darDeAltaUsuario();

    cu->ingresarDatosUsuario("Barliman", "barli@mail.com", "123");
    cu->ingresarTipoDeCargo(Recepcion);
    cu->darDeAltaUsuario();

    // Huespedes
    cu->ingresarDatosUsuario("Sofia", "sofia@mail.com", "123");
    cu->esFingerUsuario(true);
    cu->darDeAltaUsuario();

    cu->ingresarDatosUsuario("Frodo", "frodo@mail.com", "123");
    cu->esFingerUsuario(true);
    cu->darDeAltaUsuario();

    cu->ingresarDatosUsuario("Sam", "sam@mail.com", "123");
    cu->esFingerUsuario(true);
    cu->darDeAltaUsuario();

    cu->ingresarDatosUsuario("Merry", "merry@mail.com", "123");
    cu->esFingerUsuario(true);
    cu->darDeAltaUsuario();

    cu->ingresarDatosUsuario("Pippin", "pippin@mail.com", "123");
    cu->esFingerUsuario(true);
    cu->darDeAltaUsuario();

    cu->ingresarDatosUsuario("Seba", "seba@mail.com", "123");
    cu->esFingerUsuario(true);
    cu->darDeAltaUsuario();

    // para probar consulta notificaciones
    // cu->suscribirse("barli@mail.com");

    // Hostales
    ch->darAltaNuevoHostal("La posada del finger", "Av de la playa 123, Maldonado", "099111111");

    ch->darAltaNuevoHostal("Mochileros", "Rambla Costanera 333, Rocha ", "42579512");

    ch->darAltaNuevoHostal("El Pony Pisador", "Bree (preguntar por Gandalf)", "000");

    ch->darAltaNuevoHostal("Altos de Fing", "Av del Toro 1424", "099892992");

    ch->darAltaNuevoHostal("Caverna Lujosa", "Amaya 2515", "233233235");

    // Habitaciones
    ch->seleccionarHostal("La posada del finger");
    ch->ingresarDatosNuevaHabitacion(1, 40, 2);
    ch->confirmarAltaDeHabitacion();

    ch->seleccionarHostal("La posada del finger");
    ch->ingresarDatosNuevaHabitacion(2, 10, 7);
    ch->confirmarAltaDeHabitacion();

    ch->seleccionarHostal("La posada del finger");
    ch->ingresarDatosNuevaHabitacion(3, 30, 3);
    ch->confirmarAltaDeHabitacion();

    ch->seleccionarHostal("La posada del finger");
    ch->ingresarDatosNuevaHabitacion(4, 5, 12);
    ch->confirmarAltaDeHabitacion();

    ch->seleccionarHostal("Caverna Lujosa");
    ch->ingresarDatosNuevaHabitacion(1, 3, 2);
    ch->confirmarAltaDeHabitacion();

    ch->seleccionarHostal("El Pony Pisador");
    ch->ingresarDatosNuevaHabitacion(1, 9, 5);
    ch->confirmarAltaDeHabitacion();

    // Asignar Tipo de Cargo
    ch->seleccionarHostal("La posada del finger");
    ch->seleccionarEmpleadoYCargo("emilia@mail.com", Recepcion);
    ch->confirmarAsignacionDeCargo();

    ch->seleccionarHostal("Mochileros");
    ch->seleccionarEmpleadoYCargo("leo@mail.com", Recepcion);
    ch->confirmarAsignacionDeCargo();

    ch->seleccionarHostal("Mochileros");
    ch->seleccionarEmpleadoYCargo("alina@mail.com", Administracion);
    ch->confirmarAsignacionDeCargo();

    ch->seleccionarHostal("El Pony Pisador");
    ch->seleccionarEmpleadoYCargo("barli@mail.com", Recepcion);
    ch->confirmarAsignacionDeCargo();

    // Crear reservas
    cr->seleccionarHostal("La posada del finger");
    cr->seleccionarHabitacion(1);
    cr->seleccionarFecha(DTFecha(14, 01, 05, 22), DTFecha(10, 10, 05, 22));
    cr->seleccionarHuesped("sofia@mail.com");
    cr->darAltaReserva(0);

    cr->seleccionarHostal("El Pony Pisador");
    cr->seleccionarHabitacion(1);
    cr->seleccionarFecha(DTFecha(20, 04, 01, 01), DTFecha(02, 05, 01, 01));
    cr->seleccionarHuesped("frodo@mail.com");
    cr->asignarHuesped("sam@mail.com");
    cr->asignarHuesped("merry@mail.com");
    cr->asignarHuesped("pippin@mail.com");
    cr->darAltaReserva(1);

    cr->seleccionarHostal("La posada del finger");
    cr->seleccionarHabitacion(3);
    cr->seleccionarFecha(DTFecha(14, 07, 06, 22), DTFecha(11, 30, 06, 22));
    cr->seleccionarHuesped("sofia@mail.com");
    cr->darAltaReserva(0);

    cr->seleccionarHostal("Caverna Lujosa");
    cr->seleccionarHabitacion(1);
    cr->seleccionarFecha(DTFecha(14, 10, 06, 22), DTFecha(11, 30, 06, 22));
    cr->seleccionarHuesped("seba@mail.com");
    cr->darAltaReserva(0);

    // Crear estadia //pasarle check in con datos de prueba y no con fecha del sistema
    cr->seleccionarReserva(0);
    cr->seleccionarHuesped("sofia@mail.com");
    DTFecha::modificarHoraSistema(18, 1, 5, 22);

    cr->cerrarReserva();
    cr->darAltaEstadia();

    cr->seleccionarReserva(1);
    cr->seleccionarHuesped("frodo@mail.com");
    DTFecha::modificarHoraSistema(21, 4, 1, 1);
    cr->cerrarReserva();
    cr->darAltaEstadia();

    cr->seleccionarReserva(1);
    cr->seleccionarHuesped("sam@mail.com");
    DTFecha::modificarHoraSistema(21, 4, 1, 1);
    cr->cerrarReserva();
    cr->darAltaEstadia();

    cr->seleccionarReserva(1);
    cr->seleccionarHuesped("merry@mail.com");
    DTFecha::modificarHoraSistema(21, 4, 1, 1);
    cr->cerrarReserva();
    cr->darAltaEstadia();

    cr->seleccionarReserva(1);
    cr->seleccionarHuesped("pippin@mail.com");
    DTFecha::modificarHoraSistema(21, 4, 1, 1);
    cr->cerrarReserva();
    cr->darAltaEstadia();

    cr->seleccionarReserva(3);
    cr->seleccionarHuesped("seba@mail.com");
    DTFecha::modificarHoraSistema(18, 7, 6, 22);
    cr->cerrarReserva();
    cr->darAltaEstadia();

    // Finalizar estadia
    cr->seleccionarHostal("La posada del finger");
    cr->seleccionarHuesped("sofia@mail.com");
    cr->finalizarEstadia();

    cr->seleccionarHostal("El Pony Pisador");
    cr->seleccionarHuesped("frodo@mail.com");
    cr->finalizarEstadia();

    cr->seleccionarHostal("Caverna Lujosa");
    cr->seleccionarHuesped("seba@mail.com");
    cr->finalizarEstadia();

    // Calificar estadia
    cr->seleccionarHostal("La posada del finger");
    cr->seleccionarHuesped("sofia@mail.com");
    cr->seleccionarEstadia(0);
    DTFecha::modificarHoraSistema(9, 10, 5, 22);
    cr->crearResena("Un poco caro para lo que ofrecen. El famoso gimnasio era una caminadora (que hacia tremendo ruido) y 2 pesas, la piscina parecia el lago del Parque Rodo y el desayuno eran 2 tostadas con mermelada. Internet se pasaba cayendo. No vuelvo.", 3);

    cr->seleccionarHostal("El Pony Pisador");
    cr->seleccionarHuesped("frodo@mail.com");
    cr->seleccionarEstadia(1);
    DTFecha::modificarHoraSistema(2, 5, 1, 1);
    cr->crearResena("Se pone peligroso de noche, no recomiendo. Además no hay caja fuerte para guardar anillos.", 2);

    cr->seleccionarHostal("Caverna Lujosa");
    cr->seleccionarHuesped("seba@mail.com");
    cr->seleccionarEstadia(3);
    DTFecha::modificarHoraSistema(22, 15, 6, 22);
    cr->crearResena("Había pulgas en la habitación. Que lugar más mamarracho!!", 1);

    // FALTA HACER
    // Comentar calificacion
    cr->seleccionarHostal("El Pony Pisador");
    cr->darResenasSinResponder("barli@mail.com");
    cr->seleccionarHuesped("frodo@mail.com");
    cr->seleccionarEstadia(1);
    DTResena resena(0, "", DTFecha(), DTHuesped("", "frodo@mail.com", 1), 1);
    // no se como conseguir la resena de la estadia para pasarla a comentarcalif
    DTFecha Fecha = DTFecha(15, 06, 01, 01); // esta es la fecha que necesita
    cr->comentarCalificacion(resena, "Desapareció y se fue sin pagar.");

    // /*PRUEBA*/
    //   cr->seleccionarHostal("La posada del finger");
    //   set<DTEstadiaC> estadias = cr->darEstadias();
    //   for (auto it = estadias.begin(); it!= estadias.end(); ++it){
    //     cout<< *it << endl;
    //   }
    //   cr->seleccionarHuesped("sofia@mail.com");
    //   DTEstadiaL estadiaS = cr->seleccionarEstadiaL(0);
    //   cout<< estadiaS << endl;

    //   DTResena resena = cr->infoResena();
    //   cout<< resena << endl;

    DTFecha::set0();
    cout << "Datos Cargados" << endl;
}

//###############################################################################
//
// Notas:
//  Fijarse que se armen bien los links. En CtrlHostal::confirmarAltaDeHabitacion() creaba el
// link hostal->habitacion pero no creaba el link habitacion->hostal, debe pasar lo mismo en otros lados.
//###############################################################################

int main() {

    Fabrica *f = Fabrica::getInstance();
    int op;

    do {
        try {
            Menu();
            cin >> op;
            validate(op, "numero entero", 0, 22);
            switch (op) {
            case 0: {
                cargarDatos(f);
                break;
            }
            case 1: { // Alta usuario
                string nombre, email, password;
                cout << "Ingresar nombre: " << endl;
                getline(cin, nombre);
                cout << "Ingresar email: " << endl;
                getline(cin, email);
                cout << "Ingresar constrasena: " << endl;
                getline(cin, password);

                ICtrlUsuario *u = f->getICtrlUsuario();
                bool existe = u->ingresarDatosUsuario(nombre, email, password);

                bool cancelar = false;
                while ((existe) && (!cancelar)) {
                    cout << "El mail ya existe, ingrese 0 para intentar con otro o ingrese 1 para cancelar" << endl;
                    cin >> cancelar;
                    validate(cancelar, "numero entero", false, true);
                    if (!cancelar) {
                        cout << "Ingresar email: \n";
                        getline(cin, email);
                        existe = u->actualizarMail(email);
                    }
                    else {
                        u->cancelarAltaUsuario();
                    }
                }

                if (!cancelar) {
                    bool empleado;
                    cout << "Ingresar 1 si es empleado o 0 si es huesped: " << endl;
                    cin >> empleado;
                    validate(empleado, "numero entero", false, true);

                    if (empleado) {
                        // Todos los empleados ingresan sin cargo.
                        u->ingresarTipoDeCargo(sinCargo);
                    }
                    else {
                        cout << "Ingresar 1 si es finger o 0 si no es: " << endl;
                        bool es;
                        cin >> es;
                        validate(es, "numero entero", false, true);
                        u->esFingerUsuario(es);
                    }

                    cout << "Ingrese 1 si quiere confirmar o 0 si quiere cancelar: " << endl;
                    bool c;
                    cin >> c;
                    validate(c, "numero entero", false, true);
                    if (c) {
                        u->darDeAltaUsuario();
                    }
                    else {
                        u->cancelarAltaUsuario();
                    }
                }
                break;
            }
            case 2: { // Alta hostal
                string nombre, dire;
                string telefono;
                cout << "Ingresar nombre: \n";
                getline(cin, nombre);
                cout << "Ingresar direccion: \n";
                getline(cin, dire);
                cout << "Ingresar telefono: \n";
                getline(cin, telefono);

                ICtrlHostal *h = f->getICtrlHostal();
                h->darAltaNuevoHostal(nombre, dire, telefono);

                break;
            }
            case 3: { // Alta habitacion
                ICtrlHostal *h = f->getICtrlHostal();
                set<DTHostal> hostales = h->darHostalesRegistrados();
                for (auto it = hostales.begin(); it != hostales.end(); ++it) {
                    cout << *it << endl;
                }

                string nombre;
                cout << "Ingresar nombre del hostal seleccionado: " << endl;
                getline(cin, nombre);
                DTHostal dth = h->seleccionarHostal(nombre);
                // cout << dth << endl;

                int numero, capacidad;
                float precio;
                cout << "Ingresar datos de la nueva habitacion: " << endl;
                cout << "Ingresar numero: " << endl;
                cin >> numero;
                validate(numero, "numero entero", 0, MAX_int);
                cout << "Ingresar precio: " << endl;
                cin >> precio;
                cout << "Ingresar capacidad: " << endl;
                cin >> capacidad;
                validate(capacidad, "numero entero", 0, MAX_int);

                h->ingresarDatosNuevaHabitacion(numero, precio, capacidad);

                set<DTTipoDeConsumo> TDCs = h->getTiposDeConsumo();
                for (auto it = TDCs.begin(); it != TDCs.end(); ++it) {
                    cout << *it << endl;
                }

                if (TDCs.empty()) {
                    cout << "No hay tipos de consumo en el Sistema" << endl;
                    // cout << "Ingresar tipos de consumo habilitados: " << endl;
                    // bool quiereAgregar=true; //PUEDE AGREGAR 0?
                    // int codigo;
                    // while (quiereAgregar){
                    // cout << "Ingresar codigo: " << endl;
                    // cin >> codigo;
                    // h->agregarTipoDeConsumoPH(codigo); // si no existe el codigo tira error
                    // cout << "Quiere seguir agregando? true\false: " << endl;
                    // cin >> quiereAgregar;
                }

                cout << "Ingrese 1 si quiere confirmar o 0 si quiere cancelar: \n";
                bool c;
                cin >> c;
                validate(c, "numero entero", false, true);
                if (c) {
                    h->confirmarAltaDeHabitacion();
                }
                else {
                    h->cancelarAltaDeHabitacion();
                }

                break;
            }
            case 4: { // Asignar empleado a Hostal
                ICtrlHostal *h = f->getICtrlHostal();
                set<DTHostal> HostalesR = h->darHostalesRegistrados();
                for (auto it = HostalesR.begin(); it != HostalesR.end(); ++it) {
                    cout << *it << endl;
                }
                cout << "Seleccione un Hostal \n";
                string NombreHS;
                getline(cin, NombreHS);
                DTHostal hostalSelec = h->seleccionarHostal(NombreHS);
                bool quiereSA = true;
                while (quiereSA) {
                    cout << "Empleados registrados " << endl;
                    set<DTEmpleado> empleadosSA = h->empleadosSinAsignar();
                    for (auto it = empleadosSA.begin(); it != empleadosSA.end(); ++it) {
                        cout << *it << endl;
                    }

                    cout << "Seleccione un Empleado (mail)" << endl;
                    string emailE;
                    getline(cin, emailE);
                    // selecciona tipo cargo
                    int tc = 0;
                    TipoCargo cargo = leerTipoDeCargo(tc);
                    h->seleccionarEmpleadoYCargo(emailE, cargo);
                    cout << "Ingrese 1 si quiere confirmar o 0 si quiere cancelar: \n";
                    bool c;
                    cin >> c;
                    validate(c, "numero entero", false, true);
                    if (c) {
                        h->confirmarAsignacionDeCargo();
                    }
                    else {
                        h->cancelarAsignacionDeCargo();
                    }
                    cout << "Ingrese 1 si quiere seguir asignando empleados o 0 si quiere cancelar: \n";
                    cin >> quiereSA;
                    validate(quiereSA, "numero entero", false, true);
                }
                h->finalizarAsignacionDeCargo();
                break;
            }
            case 5: { // Realizar Reserva
                ICtrlReserva *r = f->getICtrlReserva();
                set<DTHostal> hostales = r->darHostalesRegistrados();
                for (auto it = hostales.begin(); it != hostales.end(); ++it) {
                    cout << *it;
                }
                string nombreH;
                cout << "Seleccione un Hostal (nombre)\n";
                getline(cin, nombreH);
                DTHostal hostal = r->seleccionarHostal(nombreH);

                DTFecha in, out;
                cout << "Ingrese fecha de checkIn\n";
                in = pedirFecha();
                cout << "Ingrese fecha de checkOut\n";
                out = pedirFecha();
                while (out < in) {
                    cout << "La fecha de checkOut debe ser mayor a la de checkIn\n";
                    cout << "Ingrese fecha de checkIn\n";
                    in = pedirFecha();
                    cout << "Ingrese fecha de checkOut\n";
                    out = pedirFecha();
                }
                r->seleccionarFecha(in, out);

                set<DTHabitacion> habitacionesD = r->darHabDisponibles();
                DTHabitacion habitacion;
                for (auto it = habitacionesD.begin(); it != habitacionesD.end(); ++it) {
                    cout << *it;
                }

                cout << "Seleccione una habitacion (id)\n";
                int id;
                cin >> id;
                validate(id, "numero entero", 0, MAX_int);
                r->seleccionarHabitacion(id);

                set<DTHuesped> huespedes = r->darHuespedes();

                cout << "Seleccione un huesped (email)\n";
                string mail;
                getline(cin, mail);
                r->seleccionarHuesped(mail);

                cout << "¿Es una reserva grupal? (true=1/false=0)\n";
                bool grupal;
                cin >> grupal;
                validate(grupal, "numero entero", false, true);
                if (grupal) {
                    bool quiereSeguir = true;
                    while (quiereSeguir) {
                        cout << "Seleccione un huesped (email)\n";
                        getline(cin, mail);
                        r->asignarHuesped(mail);
                        cout << "Quiere seguir agregando? (true=1/false=0): \n";
                        cin >> quiereSeguir;
                        validate(quiereSeguir, "numero entero", false, true);
                    }
                }
                cout << "Ingrese 1 si quiere confirmar o 0 si quiere cancelar: \n";
                bool c;
                cin >> c;
                validate(c, "numero entero", false, true);
                if (c) {
                    r->darAltaReserva(grupal);
                }
                else {
                    r->cancelarReserva();
                }
                break;
            }
            case 6: { // Consultar top 3 de hostales
                ICtrlHostal *h = f->getICtrlHostal();
                vector<string> topHostales = h->darTopHostales();

                for (auto it = topHostales.begin(); it != topHostales.end(); ++it) {
                    cout << *it << endl;
                }

                cout << "Ingrese 1 si quiere ver detalles de algún hostal, 0 sino. " << endl;
                bool ver;
                cin >> ver;
                validate(ver, "numero entero", false, true);
                while (ver) {
                    // cout << "Ingrese nombre del hostal. " << endl;
                    // string nombre;
                    // cin >> nombre;

                    string nombreH;
                    cout << "Ingresar nombre del hostal seleccionado: " << endl;
                    getline(cin, nombreH);
                    DTHostal dth = h->seleccionarHostal(nombreH);

                    set<DTResena> resenas = h->darResenas();
                    if (resenas.empty()) {
                        cout << "No hay reseñas para este hostal. " << endl;
                    }
                    for (auto it = resenas.begin(); it != resenas.end(); ++it) {
                        cout << *it << endl;
                    }

                    cout << "Ingrese 1 si quiere ver detalles de algún hostal, 0 sino. " << endl;
                    cin >> ver;
                    validate(ver, "numero entero", false, true);
                }
                break;
            }
            case 7: { // Registrar estadía
                ICtrlReserva *r = f->getICtrlReserva();
                set<DTHostal> hostales = r->darHostalesRegistrados();
                DTHostal hostal;
                for (auto it = hostales.begin(); it != hostales.end(); ++it) {
                    cout << *it << endl;
                }

                string nombre;
                cout << "Ingresar nombre del hostal seleccionado: " << endl;
                getline(cin, nombre);
                DTHostal dth = r->seleccionarHostal(nombre);

                string huespedEmail;
                cout << "Ingresar email del huesped que quiere seleccionar: " << endl;
                getline(cin, huespedEmail);
                r->seleccionarHuesped(huespedEmail);

                set<DTReserva *> reservasNC = r->darReservasNoCanceladas();
                if (reservasNC.empty()) { cout << "No hat resevas no canceladas para dicho huesped en ese hostal" << endl;}
                for (auto it = reservasNC.begin(); it != reservasNC.end(); ++it) {
                    cout << **it << endl; //** porque it es un puntero a DTReserva*
                    delete *it;
                }

                cout << "Ingresar el codigo de la reserva que quiere seleccionar: " << endl;
                int codigo;
                cin >> codigo;
                validate(codigo, "numero entero", 0, MAX_int);
                r->seleccionarReserva(codigo);

                r->cerrarReserva();
                r->darAltaEstadia();

                cout << "Estadia registrada con exito" << endl;
                break;
            }
            case 8: { // Finalizar Estadía
                ICtrlReserva *r = f->getICtrlReserva();
                set<DTHostal> hostales = r->darHostalesRegistrados();
                DTHostal hostal;
                for (auto it = hostales.begin(); it != hostales.end(); ++it) {
                    cout << *it << endl;
                }

                string nombre;
                cout << "Ingresar nombre del hostal seleccionado: " << endl;
                getline(cin, nombre);
                DTHostal dth = r->seleccionarHostal(nombre);
                cout << dth << endl;

                string huespedEmail;
                cout << "Ingresar email del huesped que quiere seleccionar: " << endl;
                getline(cin, huespedEmail);
                r->seleccionarHuesped(huespedEmail);

                r->finalizarEstadia();
                cout << "Estadia finalizada. " << endl;

                break;
            }
            case 9: { // Calificar estadía
                ICtrlReserva *r = f->getICtrlReserva();
                set<DTHostal> hostales = r->darHostalesRegistrados();
                for (auto it = hostales.begin(); it != hostales.end(); ++it) {
                    cout << *it << endl;
                }

                string nombre;
                cout << "Ingresar nombre del hostal seleccionado: " << endl;
                getline(cin, nombre);
                DTHostal dth = r->seleccionarHostal(nombre);
                //cout << dth << endl; // por qué lo imprime?

                string huespedEmail;
                cout << "Ingresar email del huesped que quiere seleccionar: " << endl;
                getline(cin, huespedEmail);
                r->seleccionarHuesped(huespedEmail);

                set<DTEstadiaC> estadias = r->darEstadiasFinalizadasNoCalificadas();
                // DTEstadiaC estadia; // donde se usa?
                if (estadias.empty()) {
                    cout << "No hay estadias finalizadas sin calificar para dicho huesped en ese hostal" << endl;
                }
                for (auto it = estadias.begin(); it != estadias.end(); ++it) {
                    cout << *it << endl;
                }

                int codRes;
                cout << "Seleccione una estadia (con el código de la reserva): " << endl;
                cin >> codRes;
                validate(codRes, "numero entero", 0, MAX_int);
                r->seleccionarEstadia(codRes);

                string comentario;
                cout << "Ingresar un comentario para la resena: " << endl;
                getline(cin, comentario);
                int calificacion;
                cout << "Ingresar una calificacion (1-5) para la resena: " << endl;
                cin >> calificacion;
                validate(calificacion, "numero entero", 1, 5);
                r->crearResena(comentario, calificacion);

                cout << "Resena creada. " << endl;
                break;
            }
            case 10: { // Comentar calificación
                ICtrlReserva *r = f->getICtrlReserva();
                string empleadoEmail;
                cout << "Ingresar email del empleado: " << endl;
                getline(cin, empleadoEmail);
                set<DTResena> resenas = r->darResenasSinResponder(empleadoEmail);
                if (resenas.empty()) {
                    throw invalid_argument("No hay reseñas sin responder");
                }
                for (auto it = resenas.begin(); it != resenas.end(); ++it) {
                    cout << *it << endl;
                }

                string huespedEmail;
                int codRes;
                bool encontro = false;
                auto it = resenas.begin();
                while (!encontro) {
                    cout << "Seleccione una resena ingresando: " << endl;
                    cout << "Mail del huesped: " << endl;
                    getline(cin, huespedEmail);
                    cout << "Código de la reserva: " << endl;
                    cin >> codRes;
                    validate(codRes, "numero entero", 0, MAX_int);
                    while (!encontro && (it != resenas.end())) {
                        string hEmail = it->getHuesped().getMail();
                        int cRes = it->getCodReserva();
                        encontro = ((hEmail == huespedEmail) && (cRes == codRes));
                        if (!encontro) {
                            ++it;
                        }
                    }
                    if (!encontro) {
                        cout << "Resena no encontrada. Mail del huesped o codigo de la reserva inválidos" << endl;
                        cout << "¿Desea ingresar una resena nuevamente (SI=0/NO=1)?" << endl;
                        cin >> encontro;
                        validate(encontro, "numero entero", false, true);
                    }
                    else {
                        string comentario;
                        cout << "Ingrese un comentario: " << endl;
                        getline(cin, comentario);
                        r->comentarCalificacion(*it, comentario);
                    }
                }

                cout << "Resena comentada. " << endl;
                break;
            }
            case 11: { // Consulta de Usuario
                ICtrlUsuario *u = f->getICtrlUsuario();
                set<DTUsuario *> usuarios = u->darUsuarios();

                for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {
                    cout << *it << endl;
                    // ver lo del delete
                }
                string email;
                cout << "Seleccione un Usuario (email):" << endl;
                getline(cin, email);
                DTUsuario *usu = u->consultarUsuario(email);
                cout << usu << endl;
                // ver lo del delete
                break;
            }
            case 12: { // Consulta de Hostal
                ICtrlHostal *h = f->getICtrlHostal();
                set<DTHostal> hostales = h->darHostalesRegistrados();
                DTHostal hostal;
                for (auto it = hostales.begin(); it != hostales.end(); ++it) {
                    cout << *it << endl;
                }

                string nombre;
                cout << "Ingresar nombre del hostal seleccionado: " << endl;
                getline(cin, nombre);
                DTHostal dth = h->seleccionarHostal(nombre);

                set<DTResena> resenas = h->darResenas();
                if (resenas.empty()) {
                    cout << "No hay resenas para este hostal" << endl;
                }
                for (auto it = resenas.begin(); it != resenas.end(); ++it) {
                    cout << *it << endl;
                }

                set<DTHabitacion> habitaciones = h->darHabitaciones();
                if (habitaciones.empty()) {
                    cout << "No hay habitaciones para este hostal" << endl;
                }
                for (auto it = habitaciones.begin(); it != habitaciones.end(); ++it) {
                    cout << *it << endl;
                }

                set<DTReserva *> reservas = h->darReservas();
                if (reservas.empty()) {
                    cout << "No hay reservas para este hostal" << endl;
                }
                for (auto it = reservas.begin(); it != reservas.end(); ++it) {
                    cout << **it << endl; //** porque it es un puntero a DTReserva*
                    delete *it;
                }

                h->finalizarConsultaHostal();

                break;
            }
            case 13: { // Consulta de Reserva
                ICtrlHostal *h = f->getICtrlHostal();
                set<DTHostal> hostales = h->darHostalesRegistrados();
                DTHostal hostal;
                for (auto it = hostales.begin(); it != hostales.end(); ++it) {
                    cout << *it << endl;
                }

                string nombre;
                cout << "Ingresar nombre del hostal seleccionado: " << endl;
                getline(cin, nombre);
                DTHostal dth = h->seleccionarHostal(nombre);

                set<DTReserva *> reservas = h->darReservas();
                if (reservas.empty()) {
                    cout << "No hay reservas para este hostal" << endl;
                }
                for (auto it = reservas.begin(); it != reservas.end(); ++it) {
                    cout << **it << endl; //** porque it es un puntero a DTReserva*
                    delete *it;
                }

                break;
            }
            case 14: { // Consulta de Estadía
                ICtrlReserva *r = f->getICtrlReserva();
                set<DTHostal> hostales = r->darHostalesRegistrados();
                for (auto it = hostales.begin(); it != hostales.end(); ++it) {
                    cout << *it << endl;
                }

                string nombre;
                cout << "Ingresar nombre del hostal seleccionado: " << endl;
                getline(cin, nombre);
                DTHostal dth = r->seleccionarHostal(nombre);

                set<DTEstadiaC> estadias = r->darEstadias();
                if (estadias.empty()) {
                    cout << "No hay estadias para este hostal" << endl;
                    break;
                }
                for (auto it = estadias.begin(); it != estadias.end(); ++it) {
                    cout << *it << endl;
                }

                string nombreH;
                cout << "Ingresar el email del huesped a seleccionar: " << endl;
                getline(cin, nombreH);
                r->seleccionarHuesped(nombreH);

                int codRes;
                cout << "Ingresar el código de la reserva a seleccionar: " << endl;
                cin >> codRes;
                validate(codRes, "numero entero", 0, MAX_int);
                DTEstadiaL estadiaS = r->seleccionarEstadiaL(codRes);
                cout << estadiaS << endl;

                cout << "¿Desea solicitar informacion sobre la resena y la respuesta? (SI=1/NO=0)" << endl;
                bool quiere;
                cin >> quiere;
                validate(quiere, "numero entero", false, true);
                if (quiere) {
                    DTResena resena = r->infoResena();
                    cout << resena << endl;

                    DTRespuesta respuesta = r->infoRespuesta();
                    cout << respuesta << endl;
                }

                cout << "¿Desea solicitar informacion sobre la reserva? (SI=1/NO=0)" << endl;
                cin >> quiere;
                validate(quiere, "numero entero", false, true);
                if (quiere) {
                    cout << "Ingrese el código de la reserva: " << endl;
                    cin >> codRes;
                    validate(codRes, "numero entero", 0, MAX_int);
                    DTReserva *reserva = r->seleccionarReserva(codRes);
                    cout << *reserva << endl;
                }

                r->finalizarConsultaEstadia();

                break;
            }
            case 15: { // Baja de Reserva
                ICtrlReserva *r = f->getICtrlReserva();
                set<DTHostal> hostales = r->darHostalesRegistrados();
                for (auto it = hostales.begin(); it != hostales.end(); ++it) {
                    cout << *it << endl;
                }

                string nombre;
                cout << "Ingresar nombre del hostal seleccionado: " << endl;
                getline(cin, nombre);
                r->seleccionarHostal(nombre); // No es necesario imprimirlo

                set<DTReserva *> reservas = r->darReservas();
                for (auto it = reservas.begin(); it != reservas.end(); ++it) {
                    cout << **it << endl;
                    delete *it;
                }

                int codigo;
                cout << "Ingresar codigo del la reserva seleccionada: " << endl;
                cin >> codigo;
                r->seleccionarReserva(codigo); // No es necesario imprimirlo

                cout << "Ingrese 1 si quiere confirmar o 0 si quiere cancelar: \n";
                bool c;
                cin >> c;
                validate(c, "numero entero", false, true);
                if (c) {
                    r->eliminarReserva();
                }
                r->finalizarBajaReserva();
                
                cout << "Reserva eliminada" << endl;
                break;
            }

            case 16: { // Modificar Fecha del Sistema
                int anio;
                int mes;
                int dia;
                int hora;
                cout << "Ingrese anio, mes, dia y hora que quiere que sean: " << endl;
                cin >> anio;
                cin >> mes;
                cin >> dia;
                cin >> hora;

                DTFecha::modificarHoraSistema(hora, dia, mes, anio);

                cout << "Fecha del sistema modificada" << endl;
                break;
            }
            case 17: { // Eliminar suscripcion
                ICtrlUsuario *u = f->getICtrlUsuario();
                set<DTEmpleado> empleados = u->darEmpleados();
                for (auto it = empleados.begin(); it != empleados.end(); ++it) {
                    cout << *it << endl;

                }

                cout << "Ingrese email del Empleado seleccionado: \n";
                string email;
                getline(cin, email);
                u->eliminarSuscripcion(email);

                cout << "Suscripcion eliminada" << endl;
                break;
            }
            case 18: { // Consulta de notificacion
                ICtrlUsuario *u = f->getICtrlUsuario();
                set<DTEmpleado> empleados = u->darEmpleados();
                for (auto it = empleados.begin(); it != empleados.end(); ++it) {
                    cout << *it << endl;
                }

                cout << "Ingrese email del Empleado seleccionado: \n";
                string email;
                getline(cin, email);
                set<DTNotificacion> notificaciones = u->consultaNotificaciones(email);
                if (notificaciones.empty()) {
                    cout << "No hay notificaciones para este empleado" << endl;
                }
                for (auto it = notificaciones.begin(); it != notificaciones.end(); ++it) {
                    cout << *it << endl; // SOBRECARGAR OPERADOR. No deberiamos devolver directamente DTResena?
                }
                cout << "Empleado eliminado del suscripto" << endl;
                break;
            }
            case 19: { // Suscribirse a Notificaciones
                ICtrlUsuario *u = f->getICtrlUsuario();
                set<DTEmpleado> empleados = u->darEmpleados();
                for (auto it = empleados.begin(); it != empleados.end(); ++it) {
                    cout << *it << endl;
                }

                cout << "Ingrese email del Empleado seleccionado: " << endl;
                string email;
                getline(cin, email);
                u->suscribirse(email);

                cout << "Empleado suscripto" << endl;

                break;
            }

            case 20: { // Alta Tipo de consumo
                ICtrlHostal *h = f->getICtrlHostal();
                bool quiereSeguir = true;
                int codigo;
                string nombre;
                float precio;
                while (quiereSeguir) {
                    cout << "Ingrese el código del tipo de consumo: " << endl;
                    cin >> codigo;
                    validate(codigo, "numero entero", 0, MAX_int);
                    cout << "Ingrese el nombre del tipo de consumo: " << endl;
                    getline(cin, nombre);
                    cout << "Ingrese el precio del tipo de consumo: " << endl;
                    cin >> precio;
                    validate(precio, "numero entero", (float)0.0, (float)MAX_int);
                    h->agregarConsumo(codigo, nombre, precio); // Se asume que no se ingresan dos tipos con el mismo código.
                    cout << "¿Quiere seguir agregando? (SI=1/NO=0) " << endl;
                    cin >> quiereSeguir;
                    validate(quiereSeguir, "numero entero", false, true);
                }

                break;
            }
            case 21: { // Dar tipos de consumo
                ICtrlHostal *h = f->getICtrlHostal();
                set<DTTipoDeConsumo> consumos = h->getTiposDeConsumo();
                for (auto it = consumos.begin(); it != consumos.end(); ++it) {
                    cout << *it << endl;
                }
            }
            }
        }
        catch (const invalid_argument &e) {
            cerr << e.what() << '\n';
        }
    } while (op != 22);
    delete f->getICtrlHostal();
    delete f->getICtrlUsuario();
    delete f->getICtrlReserva();
    delete f;
}
