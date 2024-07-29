#pragma once

#include"Nodo.h"
#include "igvColor.h"

class Modelo;
class Tractor
{
private:

	igvColor colorTodo = {0.6,0.6,0.0};
	igvColor colorVentana = {0.0,0.4,0.4};
	igvColor colorNada = { 0.0,0.0,0.0 };
	igvColor negro = { 0.1,0.1,0.1 };
	igvColor gris = {0.3,0.3,0.3};

public:

	float* color;

	bool seleccionado;
	double rotacion;
	double rotacionY;

	GLfloat rotCuerpo = 45;
	GLfloat rotBrazo1 = 50;
	GLfloat rotBrazo2 = -60;
	GLfloat rotCazo = -45;

	Tractor();
	void recorrido_preorden(Nodo* raiz);
	void visualizar_arbol();
	void aplicarMatrizTransformacion(std::string tipo);


	void cuerpo();
	void brazoPrimero();
	void brazoSegundo();
	void cazo();

	void dibujaTractor(GLfloat tam);

	//Version NT (No Texture)

	void recorrido_preordenNT(Nodo* raiz);
	void visualizar_arbolNT();
	void aplicarMatrizTransformacionNT(std::string tipo);


	void cuerpoNT();
	void brazoPrimeroNT();
	void brazoSegundoNT();
	void cazoNT();
	void dibujaTractorNT(GLfloat tam);

	float* getColor();
	void setColor(float* c);
	GLubyte* getColorByte(); //Para comparar con el pixel obtenido en la selección
};

