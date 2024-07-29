#ifndef __BOTON
#define __BOTON

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#endif

#include <string>

class Boton {

public:

	float* color;

	bool seleccionado;
	double rotacion;
	double rotacionY;

public:
	// Constructores por defecto y destructor
	Boton();

	void dibujaBotonCero(int tam, std::string ruta);
	void dibujaBotonCeroNT(int tam);
	void dibujaBotonNumero(int tam, int numero, std::string ruta);
	void dibujaBotonNumeroNT(int tam, int numero);
	void dibujaCubo(GLfloat tam, std::string rutaTextura);

	GLubyte* getColorByte();
};

#endif
