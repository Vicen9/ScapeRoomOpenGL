#include <cstdlib>

#include "igvInterfaz.h"

// Objetos globales
// objeto que contiene la configuración y la interacción con la ventana de visualización
igvInterfaz interfaz;

int main (int argc, char** argv) {
	// inicializa la ventana de visualización
	interfaz.configura_entorno(argc, argv, 600, 500, 200, 100, "Escape room");

	// establece las funciones callbacks para la gestion de los eventos
	interfaz.inicializa_callbacks();

	// inicia el bucle de visualizacion de OpenGL
	interfaz.inicia_bucle_visualizacion();

	return(0);
}
