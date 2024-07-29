#ifndef __NODO
#define __NODO

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#endif

#include <string>
#include <iostream>

class Nodo {
private:

	Nodo* hijo1;
	Nodo* hijo2;

	std::string _tipo;

public:
	// Constructores por defecto y destructor
	Nodo();
	~Nodo();
	Nodo(std::string s);

	Nodo* getHijo1();
	Nodo* getHijo2();


	void setHijo1(Nodo* n);
	void setHijo2(Nodo* n);


	std::string getTipo();
	void setTipo(std::string s);
};

#endif
