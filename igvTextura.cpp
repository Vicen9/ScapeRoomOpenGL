#include "igvTextura.h"

// Metodos constructores y destructor

igvTextura::igvTextura(char *fichero) {

	SDL_Surface* imagen = NULL;

	glEnable(GL_TEXTURE_2D);
	if (!glIsTexture(idTextura)) {

		imagen = IMG_Load(fichero);
		if (!imagen)
		{
			/* Fallo de carga de la imagen */
			/*printf("Error al cargar la imagen: %s\n", IMG_GetError()); */
			return;

		}
		/* Muestra alguna información sobre la imagen */
		/*printf("Cargando %s: %dx%d %dbpp\n", fichero, */
			/*imagen->w, imagen->h, imagen->format->BitsPerPixel); */

		ancho = imagen->w;
		alto = imagen->h;

		glGenTextures(1, &idTextura);
		glBindTexture(GL_TEXTURE_2D, idTextura);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, ancho, alto, 0, GL_RGB, GL_UNSIGNED_BYTE, imagen->pixels);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		// Apartado F: Añadir aquí el código para cargar como textura OpenGL la imagen */
	    //	- Generar el identificador de textura y asignarlo al atributo idTextura (glGenTextures)
		//	- Enlazar el identificador creado a GL_TEXTURE_2D (glBindTexture)
		//  - Especificar la textura, asignádole como textura el array imagen (glTexImage2D)
		//  - Modo de aplicación de la textura (glTexEnvf)
		//	- Parámetros de la textura: repetición y filtros (glTexParameteri)
		
		SDL_FreeSurface(imagen);
	}
}

void igvTextura::aplicar(void) {
  glBindTexture(GL_TEXTURE_2D, idTextura);
}

igvTextura::~igvTextura() {
  glDeleteTextures(1, &idTextura); 
}
