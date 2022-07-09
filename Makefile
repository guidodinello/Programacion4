
# Objetivo predeterminado (no se necesita especificarlo al invocar `make`).
all: main

# Objetivos que no son archivos.
.PHONY: all clean_bin clean_test clean testing
#.phony es una palabra reservada del makefile, no se bien que hace creo 
#que evita errores si tenes carpetas con el mismo nombre que un objetivo
#tipo una carpeta con nombre all

# directorios
HDIR    = include
CPPDIR  = src
ODIR    = obj
TESTDIR = test

MODULOS = DTEmpleado DTEstadiaC DTEstadiaL DTFecha DTHabitacion DTHostal DTHuesped DTNotificacion DTResena DTReserva DTReservaGrupal DTReservaIndividual DTRespuesta DTTipoDeConsumo DTUsuario Consumicion CtrlHostal CtrlReserva CtrlUsuario Empleado Estadia Fabrica Habitacion Hostal Huesped Resena Reserva ReservaGrupal ReservaIndividual Respuesta TipoDeConsumo Usuario
#aca van los nombres de las clases y datatypes
#tenemos que ver si las subclases de reserva las ponemos en el mismo archivo
#que reserva, sino hay que agregarlas

HS   = $(MODULOS:%=$(HDIR)/%.hh)
CPPS = $(MODULOS:%=$(CPPDIR)/%.cpp)
OS   = $(MODULOS:%=$(ODIR)/%.o)
#Usando la cadena de strings de la lista MODULOS va a setear las listas
#HS = include/Reserva.hh ... include/etc.hh
#CPPS = src/Reserva.cpp ... src/etc.cpp
#OS = obj/Reserva.o ... obj/etc.o

PRINCIPAL=main
EJECUTABLE=main
#variables

# compilador
CC = g++
# opciones de compilación
CCFLAGS = -Wall -I$(HDIR) -g
#ni idea, no encontre info sobre -Wall -Werror -I
#son flags del compilador pero no se que hacen


$(ODIR)/$(PRINCIPAL).o: $(PRINCIPAL).cpp
	$(CC) $(CCFLAGS) -c $< -o $@
#obj/main.o : (depende de) main.cpp
#se ejecuta, g++ -Wall -Werror -Iinclude -c main.cpp -o obj/main.o


# cada .o depende de su .cpp
# $@ se expande para tranformarse en el objetivo
# $< se expande para tranformarse en la primera dependencia
$(ODIR)/%.o: $(CPPDIR)/%.cpp $(HDIR)/%.hh
	$(CC) $(CCFLAGS) -c $< -o $@
#se ejecuta algo asi
#g++ -Wall -Werror -Iinclude -g -c src/Reserva.cpp -o obj/Reserva.o
#...
#g++ -Wall -Werror -Iinclude -g -c src/etc.cpp -o obj/etc.o
#$@ es una variable que contiene el objetivo, osea, $(ODIR)/(lo_que_haya_en_la_carpeta_ODIR=obj).o
#$< es una variable que contiene la primera dependencia, osea, $(CPPDIR)/(lo_que_haya_en_la_carpeta_CPPDIR=src).cpp



# $^ se expande para tranformarse en todas las dependencias
$(EJECUTABLE): $(ODIR)/$(PRINCIPAL).o $(OS)
	$(CC) $(CCFLAGS) $^ -o $@
#^$ es la lista de los objetivos
#$^ es la lista de las dependencias
#osea, $^ = obj/main.o obj/Reserva.o obj/etc.o
#se ejecuta, g++ -Wall -Werror -Iinclude -g obj/main.o obj/Reserva.o ... obj/etc.o -o main






#========PARA LOS TEST=========#
# lista de casos de prueba
CASOS = 00

# lista de archivos, con directorio y extensión
INS=$(CASOS:%=$(TESTDIR)/%.in)
OUTS=$(CASOS:%=$(TESTDIR)/%.out)
SALS=$(CASOS:%=$(TESTDIR)/%.sal)
DIFFS=$(CASOS:%=$(TESTDIR)/%.diff)

$(SALS): $(EJECUTABLE)
#$(TESTDIR)/%.sal:$(TESTDIR)/%.in
#	./$(EJECUTABLE) < $< > $@
# el guión antes del comando es para que si hay error no se detenga la
# ejecución de los otros casos
$(TESTDIR)/%.sal: $(TESTDIR)/%.in
#	-timeout 6 NO SE USA  
	valgrind -q --leak-check=full ./$(EJECUTABLE) < $< > $@ 2>&1
	@if [ $$(stat -L -c %s $@) -ge 10000 ]; then \
		echo "tamaño excedido" > $@;\
	fi

# cada .diff depende de su .out y de su .sal
%.diff: %.out %.sal
	@diff $^ > $@;                                            \
 	if [ $$? -ne 0 ];                                         \
 	then                                                      \
 		echo ---- ERROR en caso $@ ----;                  \
 	fi
# Con $$? se obtiene el estado de salida del comando anterior.
# En el caso de `diff`, si los dos archivos comparados no son iguales,
# el estado de la salida no es 0 y en ese caso se imprime el mensaje.

#==============================#

#===========COMANDOS===========#

FOLDER_NAME=
compressed:
	@echo Compressing Project Directory...
	@mkdir compressed
	tar -zcvf compressed/$(FOLDER_NAME).tar.gz --exclude=compressed ../$(FOLDER_NAME) 

# Test general. Las dependencias son los .diff.
testing:$(DIFFS)
	@LST_ERR=$$(find $(TESTDIR) -name *.diff -size +0c -print);             \
	if [ -n "$${LST_ERR}" ];                                                \
	then                                                                    \
		echo -- CASOS CON ERRORES --;                                   \
		echo "$${LST_ERR}" | sed -e 's/$(TESTDIR)\///g' -e 's/.diff//g' | sort;\
	fi

# borra binarios
clean_bin:
	rm -f $(EJECUTABLE) $(ODIR)/$(PRINCIPAL).o $(OS)

# borra resultados de ejecución y comparación
clean_test:
	@rm -f $(TESTDIR)/*.sal $(TESTDIR)/*.diff

# borra binarios, resultados de ejecución y comparación, y copias de respaldo
clean:clean_test clean_bin
	@rm -f *~ $(HDIR)/*~ $(CPPDIR)/*~ $(TESTDIR)/*~ 
