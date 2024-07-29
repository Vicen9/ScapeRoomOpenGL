#pragma once
#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#endif

#include<iostream>
#include <stdexcept>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "igvTextura.h"
#include "Tractor.h"
#include "Boton.h"

class Modelo{

public:

	float* color;

	bool seleccionado;
	double rotacion;
	double rotacionY;

	bool ABREPUERTA;
	int rotacionPuerta;
	double traslacionX;
	double traslacionZ;

	Boton b0;
	Boton b1;
	Boton b2;
	Boton b3;
	Boton b4;
	Boton b5;
	Boton b6;
	Boton b7;
	Boton b8;
	Boton b9;

	Modelo();

	void mesa(GLfloat tam);
	void puerta(GLfloat tam);
	void teclado(GLfloat tam);
	void tecladoNT(GLfloat tam);
	void securityCamara(GLfloat tam);
	void securityCamara2(GLfloat tam);
	void dibujaCubo(GLfloat tam, std::string rutaTextura);
	void dibujaCuboSecreto(GLfloat tam, std::string rutaTextura, std::string rutaTexturaSecret);
	
	void cartonCereales();

	void cartonCerealesFB();
	void cartonCerealesLL();
	void cartonCerealesTOP();
	void cartonCerealesBOTTOM();

	void cartonCerealesNT();

	void cartonCerealesFBNT();
	void cartonCerealesLLNT();
	void cartonCerealesTOPNT();
	void cartonCerealesBOTTOMNT();

	void panel(GLfloat tam, std::string ruta, std::string ruta2);

	void dibujaTetera(GLfloat tam);
	void dibujaTaza(GLfloat tam, const GLfloat x = 0, const GLfloat y = 0, const GLfloat z = 0, const GLfloat rot = 0);
	void mesaRectangular(GLfloat tam);

	void dibujaLampara(GLfloat tam, const GLfloat x = 0, const GLfloat y = 0, const GLfloat z = 0);

	float* getColor();
	void setColor(float* c);
	GLubyte* getColorByte(); //Para comparar con el pixel obtenido en la selección
};