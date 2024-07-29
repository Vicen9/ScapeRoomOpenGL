#include <cstdlib>
#include <stdio.h>
#include <string>
#include <iostream>
#include <cmath>

#include "igvEscena3D.h"
#include "igvFuenteLuz.h"
#include "igvMaterial.h"
#include "igvTextura.h"
#include "Modelo.h"

// Metodos constructores 

igvEscena3D::igvEscena3D () {
	ejes = true;
	reset = false;
}

igvEscena3D::~igvEscena3D() {
}


// Metodos publicos 

void pintar_ejes(void) {
  GLfloat rojo[]={1,0,0,1.0};
  GLfloat verde[]={0,1,0,1.0};
  GLfloat azul[]={0,0,1,1.0};

  glMaterialfv(GL_FRONT,GL_EMISSION,rojo);
	glBegin(GL_LINES);
		glVertex3f(1000,0,0);
		glVertex3f(-1000,0,0);
	glEnd();

  glMaterialfv(GL_FRONT,GL_EMISSION,verde);
	glBegin(GL_LINES);
		glVertex3f(0,1000,0);
		glVertex3f(0,-1000,0);
	glEnd();

  glMaterialfv(GL_FRONT,GL_EMISSION,azul);
	glBegin(GL_LINES);
		glVertex3f(0,0,1000);
		glVertex3f(0,0,-1000);
	glEnd();
}


void pintar_quad(float div_x, float div_z) {
	float ini_x = 0.0;
	float ini_z = 0.0;
	float tam_x = 5.0;
	float tam_z = 5.0;

	double tamXquad = tam_x / div_x;
	double tamZquad = tam_z / div_z;

	double tamXtex = 0.1 / tam_x;
	double tamZtex = 0.1 / tam_z;

	float coordXQuad = ini_x;
	float coordZQuad = ini_z;

	float coordXTex = ini_x;
	float coordZTex = ini_z;

	glNormal3f(0,1,0);
	glBegin(GL_QUADS);

	for (int i = 0; i < div_z; i++)
	{
		for (int j = 0; j < div_x; j++)
		{
			glTexCoord2f(coordXTex, coordZTex);
			glVertex3f(coordXQuad, 0.0, coordZQuad);

			glTexCoord2f(coordXTex, coordZTex + tamZtex);
			glVertex3f(coordXQuad, 0.0, coordZQuad + tamZquad);

			glTexCoord2f(coordXTex + tamXtex, coordZTex + tamZtex);
			glVertex3f(coordXQuad + tamXquad, 0.0, coordZQuad + tamZquad);

			glTexCoord2f(coordXTex + tamXtex, coordZTex);
			glVertex3f(coordXQuad + tamXquad, 0.0, coordZQuad);

			coordXQuad = coordXQuad + tamXquad;
			coordXTex = coordXTex + tamXtex;
		}

		coordZQuad = coordZQuad + tamZquad;
		coordXQuad = ini_x;

		coordZTex = coordZTex + tamZtex;
		coordXTex = ini_x;
	}

	glEnd();
}


void igvEscena3D::visualizar(void) {

	// crear el modelo
	glPushMatrix(); // guarda la matriz de modelado

		// se pintan los ejes
	  if (ejes) pintar_ejes();

	  igvPunto3D posicion = igvPunto3D(0.0, 20.0, 0.0);
	  igvColor colorAmbiental = igvColor(0.7, 0.7, 0.7, 1.0);
	  igvColor colorDifuso = igvColor(0.0, 0.0, 0.0, 0.0);
	  igvColor colorEspecular = igvColor(0.0, 0.0, 0.0, 0.0);
	  double a0 = 1.0;
	  double a1 = 0.0;
	  double a2 = 0.0;

	  igvFuenteLuz luzPuntual = igvFuenteLuz(GL_LIGHT0,
		  posicion,
		  colorAmbiental, colorDifuso, colorEspecular,
		  a0, a1, a2);

	  luzPuntual.aplicar();

	  // APARTADO E: Define y aplica la luz tipo foco especificada en el guión de prácticas

	  igvPunto3D posicion2 = igvPunto3D(0.0, 50, -20.0);

	  igvPunto3D direccionFoco = igvPunto3D(0.0, 0.0, -1.0);

	  double anguloFoco = 40.0;
	  double exponenteFoco = 4.0;

	  igvFuenteLuz luzFocal = igvFuenteLuz(GL_LIGHT1,
		  posicion2,
		  colorAmbiental, colorDifuso, colorEspecular,
		  a0, a1, a2,
		  direccionFoco, anguloFoco, exponenteFoco);

	  luzFocal.aplicar();


	  //Lampara
	  igvPunto3D posicion3 = igvPunto3D(80, 20, 190);

	  igvPunto3D direccionFoco3 = igvPunto3D(0.0, 1.0, 0.0);

	  double anguloFoco3 = 40.0;
	  double exponenteFoco3 = 3.0;

	  igvFuenteLuz luzFocal3 = igvFuenteLuz(GL_LIGHT2,
		  posicion3,
		  colorAmbiental, colorDifuso, colorEspecular,
		  a0, a1, a2,
		  direccionFoco3, anguloFoco3, exponenteFoco3);

	  luzFocal3.aplicar();

	  //Lampara
	  igvPunto3D posicion4 = igvPunto3D(0, 2, 75);

	  igvPunto3D direccionFoco4 = igvPunto3D(0.0, 1.0, 0.0);

	  double anguloFoco4 = 40.0;
	  double exponenteFoco4 = 2.0;

	  igvFuenteLuz luzFocal4 = igvFuenteLuz(GL_LIGHT3,
		  posicion4,
		  colorAmbiental, colorDifuso, colorEspecular,
		  a0, a1, a2,
		  direccionFoco4, anguloFoco4, exponenteFoco4);

	  luzFocal4.aplicar();



	  igvColor coeficienteAmbiental = igvColor(0.4, 0.4, 0.4);
	  igvColor coeficienteDifuso = igvColor(0, 0, 0);
	  igvColor coeficienteEspecular = igvColor(0, 0, 0);
	  double expPhong = exponentePhong;

	  igvMaterial material = igvMaterial(coeficienteAmbiental, coeficienteDifuso, coeficienteEspecular, expPhong);

	  material.aplicar();

		/* Apartado F: Añade aquí la creación del objeto textura y su aplicación */

	  // HABITACION
	  habitacion();

	  // MESA (CIRCULAR)
	  glPushMatrix();
	  glTranslatef(0, 0, 75);
	  m.mesa(3);
	  glPopMatrix();

	  // CAMARA DE SEGURIDAD 1
	  glPushMatrix();
	  glTranslatef(-84, 85, -94);
	  m.securityCamara(4);
	  glPopMatrix();

	  // CAMARA DE SEGURIDAD 2
	  glPushMatrix();
	  glTranslatef(84, 85, 194);
	  m.securityCamara2(4);
	  glPopMatrix();

	  // PUERTA
	  m.puerta(13);

	  // TECLADO NUMERICO
	  m.teclado(4);

	  // BOTONES

	  m.b0.dibujaBotonCero(4, "./texturas/0.jpg");
	  m.b9.dibujaBotonNumero(4, 9, "./texturas/9.jpg");
	  m.b8.dibujaBotonNumero(4, 8, "./texturas/8.jpg");
	  m.b7.dibujaBotonNumero(4, 7, "./texturas/7.jpg");
	  m.b6.dibujaBotonNumero(4, 6, "./texturas/6.jpg");
	  m.b5.dibujaBotonNumero(4, 5, "./texturas/5.jpg");
	  m.b4.dibujaBotonNumero(4, 4, "./texturas/4.jpg");
	  m.b3.dibujaBotonNumero(4, 3, "./texturas/3.jpg");
	  m.b2.dibujaBotonNumero(4, 2, "./texturas/2.jpg");
	  m.b1.dibujaBotonNumero(4, 1, "./texturas/1.jpg");

	  // TAZAS
	  m.dibujaTaza(0.5, -60, 21, 185);
	  m.dibujaTaza(0.5, -69, 21, 177, 30);
	  m.dibujaTaza(0.5, -77, 21, 193, 115);

	  // TETERA
	  glPushMatrix();
	  glTranslatef(-44, 25, 185);
	  glRotatef(180, 0, 1, 0);
	  m.dibujaTetera(4);
	  glPopMatrix();

	  // MESA (RECTANGULAR)
	  glPushMatrix();
	  glTranslatef(-60, 19, 185);
	  m.mesaRectangular(1.5);
	  glPopMatrix();

	  // CAJA DE CEREALES
	  glPushMatrix();

	  float* color = new float[3];

	  color[0] = 0.0;
	  color[1] = 0.0;
	  color[2] = 1.0;

	  glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	  glColor3fv(color); //Importante, es necesario para que lo reconozca el buffer de color a la hora de la selección.

	  if (caja.seleccionado)
	  {
		  glTranslatef(0, 35, 75);
		  glRotatef(caja.rotacionY, 0, 1, 0);
		  glRotatef(caja.rotacion, 1, 0, 0);
		  glScalef(1.5, 1.5, 1.5);
		  glTranslatef(-3, -5, -1.25);
	  }
	  else
	  {
		  glTranslatef(-7, 25, 75);
		  glRotatef(caja.rotacion, 0, 1, 0);
		  glTranslatef(-3, -5, -1.25);
	  }

	  caja.cartonCereales();
	  
	  caja.color[0] = color[0];
	  caja.color[1] = color[1];
	  caja.color[2] = color[2];

	  color[0] = 0.0;
	  color[1] = 0.0;
	  color[2] = 0.0;
	  glMaterialfv(GL_FRONT, GL_DIFFUSE, color);

	  glPopMatrix();

	  // TRACTOR
	  glPushMatrix();

	  float* colorT = new float[3];

	  colorT[0] = 0.0;
	  colorT[1] = 1.0;
	  colorT[2] = 0.0;

	  glMaterialfv(GL_FRONT, GL_DIFFUSE, colorT);
	  glColor3fv(colorT); //Importante, es necesario para que lo reconozca el buffer de color a la hora de la selección.

	  glTranslatef(10, 23, 75);
	  tractor.dibujaTractor(0.25);

	  tractor.color[0] = colorT[0];
	  tractor.color[1] = colorT[1];
	  tractor.color[2] = colorT[2];

	  colorT[0] = 0.0;
	  colorT[1] = 0.0;
	  colorT[2] = 0.0;
	  glMaterialfv(GL_FRONT, GL_DIFFUSE, colorT);

	  glPopMatrix();

	  // Pizarra
	  glPushMatrix();
	  glTranslatef(0, 48, -100);
	  m.panel(3, "./texturas/panel.jpg", "./texturas/marco_panel.jpg");
	  glPopMatrix();

	  // Pizarra
	  glPushMatrix();
	  glTranslatef(-90, 45, 45);
	  glRotatef(90, 0, 1, 0);
	  m.panel(3, "./texturas/panelCorcho.jpg", "./texturas/madera.png");
	  glPopMatrix();

	  // Lámparas
	  glPushMatrix();
	  m.dibujaLampara(1.25, 80, 0, 190);
	  m.dibujaLampara(1.25, -80, 0, -90);
	  glPopMatrix();

	  // MODO VISUALIZACION

	  glPushMatrix();

	  glTranslatef(0, 210, 35);

	  char* nombre;

	  std::string str_obj("./texturas/ms.jpg");
	  nombre = &str_obj[0];

	  igvTextura tex = igvTextura(nombre);
	  tex.aplicar();

	  glNormal3f(0, 1, 0);
	  glBegin(GL_QUADS);

	  glPushMatrix();

	  glTexCoord2f(1, 1);
	  glVertex3f(-10, 0, 0);

	  glTexCoord2f(0, 1);
	  glVertex3f(10, 0, 0);

	  glTexCoord2f(0, 0);
	  glVertex3f(10, 10, 0);

	  glTexCoord2f(1, 0);
	  glVertex3f(-10, 10, 0);

	  glPopMatrix();

	  glEnd();

	glPopMatrix (); // restaura la matriz de modelado

	// MODO REC

	glPushMatrix();

	glTranslatef(0, 250, 35);

	char* nombre2;

	std::string str_obj2("./texturas/rec.jpg");
	nombre2 = &str_obj2[0];

	igvTextura tex2 = igvTextura(nombre2);
	tex2.aplicar();

	glNormal3f(0, 1, 0);
	glBegin(GL_QUADS);

	glPushMatrix();

	glTexCoord2f(1, 1);
	glVertex3f(-10, 0, 0);

	glTexCoord2f(0, 1);
	glVertex3f(10, 0, 0);

	glTexCoord2f(0, 0);
	glVertex3f(10, 10, 0);

	glTexCoord2f(1, 0);
	glVertex3f(-10, 10, 0);

	glPopMatrix();

	glEnd();

	glPopMatrix(); // restaura la matriz de modelado

	// PANEL MAPA UJA

	glPushMatrix();

	glTranslatef(89, 18, 35);
	glScalef(7, 6, 7);
	glRotatef(90, 0, 1, 0);

	char* nombre3;

	std::string str_obj3("./texturas/planouja.png");
	nombre3 = &str_obj3[0];

	igvTextura tex3 = igvTextura(nombre3);
	tex3.aplicar();

	glNormal3f(0, 1, 0);
	glBegin(GL_QUADS);

	glPushMatrix();
	glTexCoord2f(1, 1);
	glVertex3f(-10, 0, 0);

	glTexCoord2f(0, 1);
	glVertex3f(10, 0, 0);

	glTexCoord2f(0, 0);
	glVertex3f(10, 10, 0);

	glTexCoord2f(1, 0);
	glVertex3f(-10, 10, 0);

	glPopMatrix();

	glEnd();

	glPopMatrix(); // restaura la matriz de modelado
}

double igvEscena3D::getRD()
{
	return rojoDifuso;
}

void igvEscena3D::setRD(double rojoD)
{
	rojoDifuso = rojoD;
}

double igvEscena3D::getRE()
{
	return rojoEspecular;
}

void igvEscena3D::setRE(double rojoE)
{
	rojoEspecular = rojoE;
}

double igvEscena3D::getEP()
{
	return exponentePhong;
}
void igvEscena3D::setEP(double ePhong)
{
	exponentePhong = ePhong;
}

double igvEscena3D::getxFoco()
{
	return xFoco;
}

void igvEscena3D::setxFoco(double x)
{
	xFoco = x;
}

double igvEscena3D::getyFoco()
{
	return yFoco;
}

void igvEscena3D::setyFoco(double y)
{
	yFoco = y;
}

void igvEscena3D::suelo() {

	char* nombre;
	std::string str_obj("./texturas/suelo.jpg");
	nombre = &str_obj[0];

	igvTextura tex = igvTextura(nombre);
	tex.aplicar();


	//Nuevo
	float ini_x = -90.0;
	float ini_z = -100.0;
	float tam_x = 180.0;
	float tam_z = 300.0;

	GLfloat div_x = 50;
	GLfloat div_z = 50;

	double tamXquad = tam_x / div_x;
	double tamZquad = tam_z / div_z;

	double tamXtex = 10 / tam_x;
	double tamZtex = 14 / tam_z;

	float coordXQuad = ini_x;
	float coordZQuad = ini_z;

	float coordXTex = ini_x;
	float coordZTex = ini_z;


	glNormal3f(0, 1, 0);
	glBegin(GL_QUADS);

	for (int i = 0; i < div_z; i++)
	{
		for (int j = 0; j < div_x; j++)
		{
			glTexCoord2f(coordXTex, coordZTex);
			glVertex3f(coordXQuad, 0.0, coordZQuad);

			glTexCoord2f(coordXTex, coordZTex + tamZtex);
			glVertex3f(coordXQuad, 0.0, coordZQuad + tamZquad);

			glTexCoord2f(coordXTex + tamXtex, coordZTex + tamZtex);
			glVertex3f(coordXQuad + tamXquad, 0.0, coordZQuad + tamZquad);

			glTexCoord2f(coordXTex + tamXtex, coordZTex);
			glVertex3f(coordXQuad + tamXquad, 0.0, coordZQuad);

			coordXQuad = coordXQuad + tamXquad;
			coordXTex = coordXTex + tamXtex;
		}

		coordZQuad = coordZQuad + tamZquad;
		coordXQuad = ini_x;

		coordZTex = coordZTex + tamZtex;
		coordXTex = ini_x;
	}

	glEnd();


}

void igvEscena3D::paredFondo() {

	char* nombre;
	std::string str_obj("./texturas/pared.jpg");
	nombre = &str_obj[0];

	igvTextura tex = igvTextura(nombre);
	tex.aplicar();

	glNormal3f(0, 0, -1);
	glBegin(GL_QUADS);

	/* Pared Fondo */


	// Tramo Derecho
	glTexCoord2f(0, 1);
	glVertex3f(-22, -90, 200);

	glTexCoord2f(1, 1);
	glVertex3f(-22, 90, 200);

	glTexCoord2f(1, 0);
	glVertex3f(-90, 90, 200);

	glTexCoord2f(0, 0);
	glVertex3f(-90, -90, 200);

	//Tramo Izquierdo
	glTexCoord2f(0, 1);
	glVertex3f(22, -90, 200);

	glTexCoord2f(1, 1);
	glVertex3f(22, 90, 200);

	glTexCoord2f(1, 0);
	glVertex3f(90, 90, 200);

	glTexCoord2f(0, 0);
	glVertex3f(90, -90, 200);

	//Tramo Arriba

	glTexCoord2f(0, 1);
	glVertex3f(23, 61, 200);

	glTexCoord2f(1, 1);
	glVertex3f(23, 90, 200);

	glTexCoord2f(1, 0);
	glVertex3f(-23, 90, 200);

	glTexCoord2f(0, 0);
	glVertex3f(-23, 61, 200);

	glEnd();

}

void igvEscena3D::paredDerecha() {

	char* nombre;
	std::string str_obj("./texturas/pared.jpg");
	nombre = &str_obj[0];

	igvTextura tex = igvTextura(nombre);
	tex.aplicar();


	//Nuevo
	float ini_y = 0.0;
	float ini_z = -100.0;
	float tam_y = 90.0;
	float tam_z = 300.0;

	GLfloat div_y = 40;
	GLfloat div_z = 40;

	double tamYquad = tam_y / div_y;
	double tamZquad = tam_z / div_z;

	double tamYtex = 10 / tam_y;
	double tamZtex = 14 / tam_z;

	float coordYQuad = ini_y;
	float coordZQuad = ini_z;

	float coordYTex = ini_y;
	float coordZTex = ini_z;

	glNormal3f(-1, 0, 0);
	glBegin(GL_QUADS);

	for (int i = 0; i < div_z; i++)
	{
		for (int j = 0; j < div_y; j++)
		{
			glTexCoord2f(coordYTex, coordZTex);
			glVertex3f(90, coordYQuad, coordZQuad);

			glTexCoord2f(coordYTex, coordZTex + tamZtex);
			glVertex3f(90, coordYQuad, coordZQuad + tamZquad);

			glTexCoord2f(coordYTex + tamYtex, coordZTex + tamZtex);
			glVertex3f(90, coordYQuad + tamYquad, coordZQuad + tamZquad);

			glTexCoord2f(coordYTex + tamYtex, coordZTex);
			glVertex3f(90, coordYQuad + tamYquad, coordZQuad);

			coordYQuad = coordYQuad + tamYquad;
			coordYTex = coordYTex + tamYtex;
		}

		coordZQuad = coordZQuad + tamZquad;
		coordYQuad = ini_y;

		coordZTex = coordZTex + tamZtex;
		coordYTex = ini_y;
	}

	glEnd();

}

void igvEscena3D::paredIzquierda() {

	char* nombre;
	std::string str_obj("./texturas/pared.jpg");
	nombre = &str_obj[0];

	igvTextura tex = igvTextura(nombre);
	tex.aplicar();

	//Nuevo
	float ini_y = 0.0;
	float ini_z = -100.0;
	float tam_y = 90.0;
	float tam_z = 300.0;

	GLfloat div_y = 40;
	GLfloat div_z = 40;

	double tamYquad = tam_y / div_y;
	double tamZquad = tam_z / div_z;

	double tamYtex = 10 / tam_y;
	double tamZtex = 14 / tam_z;

	float coordYQuad = ini_y;
	float coordZQuad = ini_z;

	float coordYTex = ini_y;
	float coordZTex = ini_z;

	glNormal3f(1, 0, 0);
	glBegin(GL_QUADS);

	for (int i = 0; i < div_z; i++)
	{
		for (int j = 0; j < div_y; j++)
		{
			glTexCoord2f(coordYTex, coordZTex);
			glVertex3f(-90, coordYQuad, coordZQuad);

			glTexCoord2f(coordYTex, coordZTex + tamZtex);
			glVertex3f(-90, coordYQuad, coordZQuad + tamZquad);

			glTexCoord2f(coordYTex + tamYtex, coordZTex + tamZtex);
			glVertex3f(-90, coordYQuad + tamYquad, coordZQuad + tamZquad);

			glTexCoord2f(coordYTex + tamYtex, coordZTex);
			glVertex3f(-90, coordYQuad + tamYquad, coordZQuad);

			coordYQuad = coordYQuad + tamYquad;
			coordYTex = coordYTex + tamYtex;
		}

		coordZQuad = coordZQuad + tamZquad;
		coordYQuad = ini_y;

		coordZTex = coordZTex + tamZtex;
		coordYTex = ini_y;
	}

	glEnd();

}

void igvEscena3D::paredFrontal() {

	char* nombre;

	std::string str_obj("./texturas/pared.jpg");
	nombre = &str_obj[0];

	igvTextura tex = igvTextura(nombre);
	tex.aplicar();

	//Nuevo
	float ini_x = -90.0;
	float ini_y = 0.0;
	float tam_x = 180.0;
	float tam_y = 90.0;

	GLfloat div_x = 40;
	GLfloat div_y = 40;

	double tamXquad = tam_x / div_x;
	double tamYquad = tam_y / div_y;

	double tamXtex = 10 / tam_x;
	double tamYtex = 14 / tam_y;

	float coordXQuad = ini_x;
	float coordYQuad = ini_y;

	float coordXTex = ini_x;
	float coordYTex = ini_y;

	glNormal3f(0, 0, 1);
	glBegin(GL_QUADS);

	for (int i = 0; i < div_y; i++)
	{
		for (int j = 0; j < div_x; j++)
		{
			glTexCoord2f(coordXTex, coordYTex);
			glVertex3f(coordXQuad, coordYQuad, -100);

			glTexCoord2f(coordXTex, coordYTex + tamYtex);
			glVertex3f(coordXQuad, coordYQuad + tamYquad, -100);

			glTexCoord2f(coordXTex + tamXtex, coordYTex + tamYtex);
			glVertex3f(coordXQuad + tamXquad, coordYQuad + tamYquad, -100);

			glTexCoord2f(coordXTex + tamXtex, coordYTex);
			glVertex3f(coordXQuad + tamXquad, coordYQuad, -100);

			coordXQuad = coordXQuad + tamXquad;
			coordXTex = coordXTex + tamXtex;
		}

		coordYQuad = coordYQuad + tamYquad;
		coordXQuad = ini_x;

		coordYTex = coordYTex + tamYtex;
		coordXTex = ini_x;
	}

	glEnd();

}

void igvEscena3D::techo() {

	char* nombre;
	std::string str_obj("./texturas/techo.jpg");
	nombre = &str_obj[0];

	igvTextura tex = igvTextura(nombre);
	tex.aplicar();

	//Nuevo
	float ini_x = -90.0;
	float ini_z = -100.0;
	float tam_x = 180.0;
	float tam_z = 300.0;

	GLfloat div_x = 40;
	GLfloat div_z = 40;

	double tamXquad = tam_x / div_x;
	double tamZquad = tam_z / div_z;

	double tamXtex = 10 / tam_x;
	double tamZtex = 14 / tam_z;

	float coordXQuad = ini_x;
	float coordZQuad = ini_z;

	float coordXTex = ini_x;
	float coordZTex = ini_z;


	glNormal3f(0, -1, 0);
	glBegin(GL_QUADS);

	for (int i = 0; i < div_z; i++)
	{
		for (int j = 0; j < div_x; j++)
		{
			glTexCoord2f(coordXTex, coordZTex);
			glVertex3f(coordXQuad, 90.0, coordZQuad);

			glTexCoord2f(coordXTex, coordZTex + tamZtex);
			glVertex3f(coordXQuad, 90.0, coordZQuad + tamZquad);

			glTexCoord2f(coordXTex + tamXtex, coordZTex + tamZtex);
			glVertex3f(coordXQuad + tamXquad, 90.0, coordZQuad + tamZquad);

			glTexCoord2f(coordXTex + tamXtex, coordZTex);
			glVertex3f(coordXQuad + tamXquad, 90.0, coordZQuad);

			coordXQuad = coordXQuad + tamXquad;
			coordXTex = coordXTex + tamXtex;
		}

		coordZQuad = coordZQuad + tamZquad;
		coordXQuad = ini_x;

		coordZTex = coordZTex + tamZtex;
		coordXTex = ini_x;
	}

	glEnd();

}

void igvEscena3D::habitacion() {

	suelo();

	paredFondo();
	paredDerecha();
	paredIzquierda();
	paredFrontal();

	techo();

}