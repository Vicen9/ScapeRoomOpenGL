#include <cstdlib>

#include "igvInterfaz.h"

// Objetos globales
// objeto que contiene la configuraci�n y la interacci�n con la ventana de visualizaci�n
igvInterfaz interfaz;

int main (int argc, char** argv) {
	// inicializa la ventana de visualizaci�n
	interfaz.configura_entorno(argc, argv, 600, 500, 200, 100, "Escape room");

	// establece las funciones callbacks para la gestion de los eventos
	interfaz.inicializa_callbacks();

	// inicia el bucle de visualizacion de OpenGL
	interfaz.inicia_bucle_visualizacion();

	return(0);
}
