#include "Modelo.h"
#include "Boton.h"

Modelo::Modelo()
{
	seleccionado = false;
	rotacion = 0;
	
	color = new float[3];

	color[0] = 0;
	color[1] = 0;
	color[2] = 0;

	ABREPUERTA = false;
	rotacionPuerta = 0;
}

void Modelo::mesa(GLfloat tam){

	char* texturaMadera;
	std::string str_madera("./texturas/mesa.jpg");
	texturaMadera = &str_madera[0];


	char* texturaMesaAbajo;
	std::string str_mesaAbajo("./texturas/mesa_abajo.jpg");
	texturaMesaAbajo = &str_mesaAbajo[0];


	glPushMatrix();

	glTranslatef(0, 16, 0);
	glScalef(tam, tam, tam);

	//Pata 1
	glPushMatrix();

	glTranslatef(-2, -0.2, 0);
	glRotatef(-20, 0, 0, 1);
	glScalef(0.2, 1.2, 0.2);

	glPushMatrix();
	glTranslatef(0, 1, 0);
	glRotatef(90, 1, 0, 0);


	GLUquadric* pata1 = gluNewQuadric();
	igvTextura tex = igvTextura(texturaMadera);
	gluQuadricTexture(pata1, TRUE);
	gluQuadricNormals(pata1, GLU_SMOOTH);
	tex.aplicar();


	gluCylinder(pata1, 2, 2, 6, 60, 60);
	glPopMatrix();
	glPopMatrix();
	gluDeleteQuadric(pata1);



	//Pata 2
	glPushMatrix();

	glTranslatef(0, -0.2, 3);
	glRotatef(-20, 1, 0, 0);
	glScalef(0.2, 1.2, 0.2);

	glPushMatrix();
	glTranslatef(0, 1, 0);
	glRotatef(90, 1, 0, 0);

	GLUquadric* pata2 = gluNewQuadric();
	gluQuadricTexture(pata2, TRUE);
	gluQuadricNormals(pata2, GLU_SMOOTH);
	tex.aplicar();

	gluCylinder(pata2, 2, 2, 6, 60, 60);
	glPopMatrix();
	glPopMatrix();
	gluDeleteQuadric(pata2);



	//Pata 3
	glPushMatrix();

	glTranslatef(0, -0.2, -3);
	glRotatef(20, 1, 0, 0);
	glScalef(0.2, 1.2, 0.2);

	glPushMatrix();
	glTranslatef(0, 1, 0);
	glRotatef(90, 1, 0, 0);

	GLUquadric* pata3 = gluNewQuadric();
	gluQuadricTexture(pata3, TRUE);
	gluQuadricNormals(pata3, GLU_SMOOTH);
	tex.aplicar();

	gluCylinder(pata3, 2, 2, 6, 60, 60);
	glPopMatrix();
	glPopMatrix();
	gluDeleteQuadric(pata3);


	//Pata 4
	glPushMatrix();

	glTranslatef(2, -0.2, 0);
	glRotatef(20, 0, 0, 1);
	glScalef(0.2, 1.2, 0.2);

	glPushMatrix();
	glTranslatef(0, 1, 0);
	glRotatef(90, 1, 0, 0);

	GLUquadric* pata4 = gluNewQuadric();
	gluQuadricTexture(pata4, TRUE);
	gluQuadricNormals(pata4, GLU_SMOOTH);
	tex.aplicar();

	gluCylinder(pata4, 2, 2, 6, 60, 60);
	glPopMatrix();
	glPopMatrix();

	gluDeleteQuadric(pata4);



	//Mesa
	glPushMatrix();

	glPushMatrix();
	glTranslatef(0, 1.2, 0);
	glRotatef(90, 1, 0, 0);

	GLUquadric* tapa = gluNewQuadric();
	gluQuadricTexture(tapa, TRUE);
	gluQuadricNormals(tapa, GLU_SMOOTH);
	tex.aplicar();

	gluDisk(tapa, 0, 6, 60, 60);
	glPopMatrix();
	gluDeleteQuadric(tapa);


	glPushMatrix();
	glTranslatef(0, 0.2, 0);
	glRotatef(90, 1, 0, 0);


	GLUquadric* tapa2 = gluNewQuadric();
	igvTextura texTapa = igvTextura(texturaMesaAbajo);
	gluQuadricTexture(tapa2, TRUE);
	gluQuadricNormals(tapa2, GLU_SMOOTH);
	texTapa.aplicar();

	gluDisk(tapa2, 0, 6, 60, 60);
	glPopMatrix();
	gluDeleteQuadric(tapa2);


	glPushMatrix();
	glTranslatef(0, 1.2, 0);
	glRotatef(90, 1, 0, 0);

	GLUquadric* borde = gluNewQuadric();
	gluQuadricTexture(borde, TRUE);
	gluQuadricNormals(borde, GLU_SMOOTH);
	tex.aplicar();

	gluCylinder(borde, 6, 6, 1, 60, 60);
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
	gluDeleteQuadric(borde);
}

void Modelo::cartonCereales()
{
	cartonCerealesLL();
	cartonCerealesFB();
	cartonCerealesTOP();
	cartonCerealesBOTTOM();
}

void Modelo::cartonCerealesNT()
{
	cartonCerealesLLNT();
	cartonCerealesFBNT();
	cartonCerealesTOPNT();
	cartonCerealesBOTTOMNT();
}

void Modelo::cartonCerealesLL()
{
	char* cerealLat;
	std::string str_la("./texturas/cereales_l.jpg");
	cerealLat = &str_la[0];

	igvTextura tex = igvTextura(cerealLat);
	tex.aplicar();

	glPushMatrix();
	glNormal3f(-1, 0, 0);
	glBegin(GL_QUADS);
	//Lateral Derecho
	glTexCoord2f(0, 0);
	glVertex3f(0, 10, 0);

	glTexCoord2f(1, 0);
	glVertex3f(0, 10, 2.5);

	glTexCoord2f(1, 1);
	glVertex3f(0, 0, 2.5);

	glTexCoord2f(0, 1);
	glVertex3f(0, 0, 0);

	glEnd();
	glPopMatrix();


	glPushMatrix();
	glNormal3f(1, 0, 0);
	glBegin(GL_QUADS);
	//Lateral Izquierdo
	glTexCoord2f(1, 0);
	glVertex3f(6, 10, 0);

	glTexCoord2f(0, 0);
	glVertex3f(6, 10, 2.5);

	glTexCoord2f(0, 1);
	glVertex3f(6, 0, 2.5);

	glTexCoord2f(1, 1);
	glVertex3f(6, 0, 0);
	glEnd();
	glPopMatrix();


}
void Modelo::cartonCerealesFB()
{
	char* cerealFront;
	std::string str_cf("./texturas/cereales_f.jpg");
	cerealFront = &str_cf[0];

	igvTextura tex = igvTextura(cerealFront);
	tex.aplicar();

	glPushMatrix();
	glNormal3f(0, 0, 1);
	glBegin(GL_QUADS);
	//Frontal
	glTexCoord2f(1, 0);
	glVertex3f(0, 10, 0);

	glTexCoord2f(0, 0);
	glVertex3f(6, 10, 0);

	glTexCoord2f(0, 1);
	glVertex3f(6, 0, 0);

	glTexCoord2f(1, 1);
	glVertex3f(0, 0, 0);


	glEnd();
	glPopMatrix();

	glPushMatrix();
	glNormal3f(0, 0, -1);
	glBegin(GL_QUADS);

	//Trasera
	glTexCoord2f(0, 0);
	glVertex3f(0, 10, 2.5);

	glTexCoord2f(1, 0);
	glVertex3f(6, 10, 2.5);

	glTexCoord2f(1, 1);
	glVertex3f(6, 0, 2.5);

	glTexCoord2f(0, 1);
	glVertex3f(0, 0, 2.5);

	glEnd();
	glPopMatrix();


}
void Modelo::cartonCerealesTOP()
{
	char* cerealTOP;
	std::string str_t("./texturas/cereales_arriba.jpg");
	cerealTOP = &str_t[0];

	igvTextura tex = igvTextura(cerealTOP);
	tex.aplicar();

	glPushMatrix();
	glNormal3f(0, 1, 0);
	glBegin(GL_QUADS);

	//Frontal
	glTexCoord2f(0, 1);
	glVertex3f(0, 10, 0);

	glTexCoord2f(0, 0);
	glVertex3f(6, 10, 0);

	glTexCoord2f(1, 0);
	glVertex3f(6, 10, 2.5);

	glTexCoord2f(1, 1);
	glVertex3f(0, 10, 2.5);

	glEnd();
	glPopMatrix();

}
void Modelo::cartonCerealesBOTTOM()
{
	char* cerealBOTTOM;
	std::string str_b("./texturas/cereales_abajo.jpg");
	cerealBOTTOM = &str_b[0];

	igvTextura tex = igvTextura(cerealBOTTOM);
	tex.aplicar();


	glPushMatrix();
	glNormal3f(0, -1, 0);
	glBegin(GL_QUADS);


	//Frontal
	glTexCoord2f(1, 1);
	glVertex3f(0, 0, 0);

	glTexCoord2f(1, 0);
	glVertex3f(6, 0, 0);

	glTexCoord2f(0, 0);
	glVertex3f(6, 0, 2.5);

	glTexCoord2f(0, 1);
	glVertex3f(0, 0, 2.5);

	glEnd();
	glPopMatrix();
}

void Modelo::cartonCerealesLLNT()
{
	glNormal3f(0, 1, 0);
	glBegin(GL_QUADS);

	glPushMatrix();

	//Lateral Derecho
	glTexCoord2f(0, 0);
	glVertex3f(0, 10, 0);

	glTexCoord2f(1, 0);
	glVertex3f(0, 10, 2.5);

	glTexCoord2f(1, 1);
	glVertex3f(0, 0, 2.5);

	glTexCoord2f(0, 1);
	glVertex3f(0, 0, 0);

	//Lateral Izquierdo
	glTexCoord2f(1, 0);
	glVertex3f(6, 10, 0);

	glTexCoord2f(0, 0);
	glVertex3f(6, 10, 2.5);

	glTexCoord2f(0, 1);
	glVertex3f(6, 0, 2.5);

	glTexCoord2f(1, 1);
	glVertex3f(6, 0, 0);

	glPopMatrix();

	glEnd();
}
void Modelo::cartonCerealesFBNT()
{

	glNormal3f(0, 1, 0);
	glBegin(GL_QUADS);

	glPushMatrix();

	//Frontal
	glTexCoord2f(1, 0);
	glVertex3f(0, 10, 0);

	glTexCoord2f(0, 0);
	glVertex3f(6, 10, 0);

	glTexCoord2f(0, 1);
	glVertex3f(6, 0, 0);

	glTexCoord2f(1, 1);
	glVertex3f(0, 0, 0);

	//Trasera
	glTexCoord2f(0, 0);
	glVertex3f(0, 10, 2.5);

	glTexCoord2f(1, 0);
	glVertex3f(6, 10, 2.5);

	glTexCoord2f(1, 1);
	glVertex3f(6, 0, 2.5);

	glTexCoord2f(0, 1);
	glVertex3f(0, 0, 2.5);

	glPopMatrix();

	glEnd();
}
void Modelo::cartonCerealesTOPNT()
{

	glNormal3f(0, 1, 0);
	glBegin(GL_QUADS);

	glPushMatrix();

	//Frontal
	glTexCoord2f(0, 1);
	glVertex3f(0, 10, 0);

	glTexCoord2f(0, 0);
	glVertex3f(6, 10, 0);

	glTexCoord2f(1, 0);
	glVertex3f(6, 10, 2.5);

	glTexCoord2f(1, 1);
	glVertex3f(0, 10, 2.5);

	glPopMatrix();

	glEnd();
}

void Modelo::cartonCerealesBOTTOMNT()
{

	glNormal3f(0, 1, 0);
	glBegin(GL_QUADS);

	glPushMatrix();

	//Frontal
	glTexCoord2f(1, 1);
	glVertex3f(0, 0, 0);

	glTexCoord2f(1, 0);
	glVertex3f(6, 0, 0);

	glTexCoord2f(0, 0);
	glVertex3f(6, 0, 2.5);

	glTexCoord2f(0, 1);
	glVertex3f(0, 0, 2.5);

	glPopMatrix();

	glEnd();
}

void Modelo::puerta(GLfloat tam) {

	glPushMatrix();
		
	glTranslatef(0, 25, 200);

	glScalef(tam,tam,tam);

	glPushMatrix();

		if (ABREPUERTA)
		{
			glTranslatef(traslacionX, 0, traslacionZ);
			glRotatef(rotacionPuerta, 0, 1, 0);
		}
		//Pomo
		glPushMatrix();

			glTranslatef(-0.8, 0.6,-0.3);
			glScalef(0.4, 0.25, 0.25);
			dibujaCubo(1, "./texturas/pomo.jpg");

		glPopMatrix();

		//Puerta
		glPushMatrix();

			glTranslatef(0, 0.08, 0);
			glScalef(2.5, 4.4, 0.5);
			dibujaCubo(1, "./texturas/puerta.jpg");

		glPopMatrix();

	glPopMatrix();

		//Marco arriba

		glPushMatrix();

			glTranslatef(0,2.5, 0);
			glRotatef(90, 0, 0, 1);
			glScalef(0.5, 3.5, 0.5);
			dibujaCubo(1, "./texturas/marco.jpg");

		glPopMatrix();

		//Marco derecha
		glPushMatrix();

			glTranslatef(-1.5, 0, 0);
			glScalef(0.5, 4.5, 0.5);
			dibujaCubo(1, "./texturas/marco.jpg");

		glPopMatrix();

		//Marco izquierda
		glPushMatrix();

			glTranslatef(1.5, 0, 0);
			glScalef(0.5, 4.5, 0.5);
			dibujaCubo(1, "./texturas/marco.jpg");

		glPopMatrix();

	glPopMatrix();

}
void Modelo::teclado(GLfloat tam) {

	glPushMatrix();//General

	glTranslatef(33, 29, 200);
	glScalef(tam, tam, tam);

		glPushMatrix();
		glTranslatef(0.7, 0.7, 0.0);
		glScalef(2.5, 4.5, 0.1);
		dibujaCubo(1, "./texturas/metal.jpg");
		glPopMatrix();

	glPopMatrix();//General
}

void Modelo::tecladoNT(GLfloat tam) {

	glPushMatrix();//General

	glTranslatef(33, 29, 200);
	glScalef(tam, tam, tam);

	glPushMatrix();
	glTranslatef(0.7, 0.7, 0.0);
	glScalef(2.5, 4.5, 0.1);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();//General
}

void Modelo::securityCamara(GLfloat tam) {

	char* texturaMetal;
	std::string str_metal("./texturas/metal.jpg");
	texturaMetal = &str_metal[0];

	char* texturaMetalLente;
	std::string str_metalLente("./texturas/metal.jpg");
	texturaMetalLente = &str_metalLente[0];

	glPushMatrix();

	glScalef(tam, tam, tam);

	//Base pared
	glPushMatrix();
	glTranslatef(0, -1.2, -1.5);

	GLUquadric* basePared = gluNewQuadric();
	igvTextura tex = igvTextura(texturaMetal);
	gluQuadricTexture(basePared, TRUE);
	gluQuadricNormals(basePared, GLU_SMOOTH);
	tex.aplicar();

	gluCylinder(basePared, 0.7, 0.2, 0.1, 40, 60);
	glPopMatrix();
	gluDeleteQuadric(basePared);

	//Base lateral
	glPushMatrix();
	glTranslatef(0, -1.2, -1.4);

	GLUquadric* baseLateral = gluNewQuadric();
	gluQuadricTexture(baseLateral, TRUE);
	gluQuadricNormals(baseLateral, GLU_SMOOTH);
	tex.aplicar();

	gluCylinder(baseLateral, 0.2, 0.2, 1, 40, 60);
	glPopMatrix();
	gluDeleteQuadric(baseLateral);

	//Base Cubo
	glPushMatrix();
	glTranslatef(0, -0.5, -0.5);
	glRotatef(90, 1, 0, 0);

	GLUquadric* baseCubo = gluNewQuadric();
	gluQuadricTexture(baseCubo, TRUE);
	gluQuadricNormals(baseCubo, GLU_SMOOTH);
	tex.aplicar();

	gluCylinder(baseCubo, 0.2, 0.2, 0.8, 40, 60);
	glPopMatrix();
	gluDeleteQuadric(baseCubo);

	glPushMatrix();

	glRotatef(25, 1, 0, 0);
	glRotatef(25, 0, 1, 0);

	//Pelota
	glPushMatrix();
	glTranslatef(0.3, 0.3, 0.95);
	glutSolidSphere(0.1, 40, 60);
	glPopMatrix();

	//Tapa objetivo
	glPushMatrix();
	glTranslatef(0, 0, 1.5);

	GLUquadric* tapaObjetivo = gluNewQuadric();
	igvTextura texObv = igvTextura(texturaMetalLente);
	gluQuadricTexture(tapaObjetivo, TRUE);
	gluQuadricNormals(tapaObjetivo, GLU_SMOOTH);
	texObv.aplicar();
	gluDisk(tapaObjetivo, 0, 0.3, 40, 60);
	glPopMatrix();
	gluDeleteQuadric(tapaObjetivo);


	//Objetivo
	glPushMatrix();
	glTranslatef(0, 0, 1);

	GLUquadric* objetivo = gluNewQuadric();
	gluQuadricTexture(objetivo, TRUE);
	gluQuadricNormals(objetivo, GLU_SMOOTH);
	tex.aplicar();
	gluCylinder(objetivo, 0.3, 0.3, 0.5, 40, 60);
	glPopMatrix();
	gluDeleteQuadric(objetivo);

	//Cuerpo
	glPushMatrix();
	glScalef(1, 1, 2);
	dibujaCubo(1, "./texturas/metal.jpg");
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
}
void Modelo::securityCamara2(GLfloat tam) {

	char* texturaMetal;
	std::string str_metal("./texturas/metal.jpg");
	texturaMetal = &str_metal[0];

	char* texturaMetalLente;
	std::string str_metalLente("./texturas/metal.jpg");
	texturaMetalLente = &str_metalLente[0];

	glPushMatrix();

	glRotatef(180, 0, 1, 0);
	glScalef(tam, tam, tam);

	//Base pared
	glPushMatrix();
	glTranslatef(0, -1.2, -1.5);

	GLUquadric* basePared = gluNewQuadric();
	igvTextura tex = igvTextura(texturaMetal);
	gluQuadricTexture(basePared, TRUE);
	gluQuadricNormals(basePared, GLU_SMOOTH);
	tex.aplicar();

	gluCylinder(basePared, 0.7, 0.2, 0.1, 40, 60);
	glPopMatrix();
	gluDeleteQuadric(basePared);


	//Base lateral
	glPushMatrix();
	glTranslatef(0, -1.2, -1.4);

	GLUquadric* baseLateral = gluNewQuadric();
	gluQuadricTexture(baseLateral, TRUE);
	gluQuadricNormals(baseLateral, GLU_SMOOTH);
	tex.aplicar();

	gluCylinder(baseLateral, 0.2, 0.2, 1, 40, 60);
	glPopMatrix();
	gluDeleteQuadric(baseLateral);

	//Base Cubo
	glPushMatrix();
	glTranslatef(0, -0.5, -0.5);
	glRotatef(90, 1, 0, 0);

	GLUquadric* baseCubo = gluNewQuadric();
	gluQuadricTexture(baseCubo, TRUE);
	gluQuadricNormals(baseCubo, GLU_SMOOTH);
	tex.aplicar();

	gluCylinder(baseCubo, 0.2, 0.2, 0.8, 40, 60);
	glPopMatrix();
	gluDeleteQuadric(baseCubo);

	glPushMatrix();

	glRotatef(25, 1, 0, 0);
	glRotatef(25, 0, 1, 0);

	//Pelota
	glPushMatrix();
	glTranslatef(0.3, 0.3, 0.95);
	glutSolidSphere(0.1, 40, 60);
	glPopMatrix();

	//Tapa objetivo
	glPushMatrix();
	glTranslatef(0, 0, 1.5);

	GLUquadric* tapaObjetivo = gluNewQuadric();
	igvTextura texObv = igvTextura(texturaMetalLente);
	gluQuadricTexture(tapaObjetivo, TRUE);
	gluQuadricNormals(tapaObjetivo, GLU_SMOOTH);
	texObv.aplicar();
	gluDisk(tapaObjetivo, 0, 0.3, 40, 60);
	glPopMatrix();
	gluDeleteQuadric(tapaObjetivo);


	//Objetivo
	glPushMatrix();
	glTranslatef(0, 0, 1);

	GLUquadric* objetivo = gluNewQuadric();
	gluQuadricTexture(objetivo, TRUE);
	gluQuadricNormals(objetivo, GLU_SMOOTH);
	tex.aplicar();
	gluCylinder(objetivo, 0.3, 0.3, 0.5, 40, 60);
	glPopMatrix();
	gluDeleteQuadric(objetivo);

	//Cuerpo
	glPushMatrix();
	glScalef(1, 1, 2);
	dibujaCubo(1, "./texturas/metal.jpg");
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
}
void Modelo::dibujaCubo(GLfloat tam, std::string rutaTextura) {

	tam = tam / 2;

	char* textura;
	std::string str_obj(rutaTextura);
	textura = &str_obj[0];

	igvTextura tex = igvTextura(textura);

	tex.aplicar();

	glPushMatrix();

	glNormal3f(0, -1, 0);
	glBegin(GL_QUADS);
	/* Floor */
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-tam, -tam, -tam);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(tam, -tam, -tam);

	glTexCoord2f(0.0, 0.0);
	glVertex3f(tam, -tam, tam);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(-tam, -tam, tam);
	glEnd();


	tex.aplicar();
	glNormal3f(0, 1, 0);
	glBegin(GL_QUADS);
	/* Ceiling */
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-tam, tam, -tam);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(tam, tam, -tam);

	glTexCoord2f(0.0, 0.0);
	glVertex3f(tam, tam, tam);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(-tam, tam, tam);


	glEnd();

	tex.aplicar();
	glNormal3f(0, 0, 1);
	glBegin(GL_QUADS);

	/* Walls */
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-tam, -tam, tam);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(tam, -tam, tam);

	glTexCoord2f(0.0, 0.0);
	glVertex3f(tam, tam, tam);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(-tam, tam, tam);


	glEnd();


	tex.aplicar();
	glNormal3f(0, 0, -1);
	glBegin(GL_QUADS);

	//Pared
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-tam, -tam, -tam);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(tam, -tam, -tam);

	glTexCoord2f(0.0, 0.0);
	glVertex3f(tam, tam, -tam);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(-tam, tam, -tam);

	glEnd();

	tex.aplicar();
	glNormal3f(1, 0, 0);
	glBegin(GL_QUADS);
	//Pared
	glTexCoord2f(0.0, 0.0);
	glVertex3f(tam, tam, tam);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(tam, -tam, tam);

	glTexCoord2f(1.0, 1.0);
	glVertex3f(tam, -tam, -tam);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(tam, tam, -tam);
	glEnd();

	tex.aplicar();
	glNormal3f(-1, 0, 0);
	glBegin(GL_QUADS);

	glTexCoord2f(0.0, 0.0);
	glVertex3f(-tam, tam, tam);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(-tam, -tam, tam);

	glTexCoord2f(1.0, 1.0);
	glVertex3f(-tam, -tam, -tam);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(-tam, tam, -tam);


	glEnd();
	glPopMatrix();
}

void Modelo::panel(GLfloat tam, std::string ruta, std::string ruta2) {

	glPushMatrix();
	glScalef(tam, tam, tam);
	//Marco izquierda
	glPushMatrix();
	glTranslatef(-17, 0, 0);
	glRotatef(90, 0, 0, 1);
	glScalef(6, 0.7, 0.7);
	dibujaCubo(3, ruta2);
	glPopMatrix();

	//Marco izquierda
	glPushMatrix();
	glTranslatef(17, 0, 0);
	glRotatef(90, 0, 0, 1);
	glScalef(6, 0.7, 0.7);
	dibujaCubo(3, ruta2);
	glPopMatrix();

	//Marco abajo
	glPushMatrix();
	glTranslatef(0, -10, 0);
	glScalef(12, 0.7, 0.7);
	dibujaCubo(3, ruta2);
	glPopMatrix();

	//Marco Arriba
	glPushMatrix();
	glTranslatef(0, 10, 0);
	glScalef(12, 0.7, 0.7);
	dibujaCubo(3, ruta2);
	glPopMatrix();

	//Panel
	glPushMatrix();
	glScalef(11, 7, 0.4);
	dibujaCubo(3, ruta);
	glPopMatrix();
	glPopMatrix();
}

void Modelo::dibujaTetera(GLfloat tam) {
	char* texturaMetal;
	std::string str_metal("./texturas/taza.jpg");
	texturaMetal = &str_metal[0];
	glScalef(tam, tam, tam);
	glPushMatrix();
	igvTextura tex = igvTextura(texturaMetal);
	glutSolidTeapot(1);
	tex.aplicar();

	glPopMatrix();

}

void Modelo::dibujaTaza(GLfloat tam, const GLfloat x, const GLfloat y, const GLfloat z, const GLfloat rot) {
	char* texturaTaza;
	std::string str_taza("./texturas/taza.jpg");
	texturaTaza = &str_taza[0];
	igvTextura tex = igvTextura(texturaTaza);

	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(rot, 0, 1, 0);
	glScalef(tam, tam, tam);

	glPushMatrix();
	glTranslatef(-3, 4, 0);
	glutSolidTorus(0.5, 2.5, 30, 40);
	glPopMatrix();

	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	GLUquadric* base = gluNewQuadric();
	gluQuadricTexture(base, TRUE);
	gluQuadricNormals(base, GLU_SMOOTH);
	tex.aplicar();
	gluDisk(base, 0, 3, 20, 40);
	glPopMatrix();
	gluDeleteQuadric(base);

	glPushMatrix();
	glTranslatef(0.0, 7.0, 0.0);
	glRotatef(-90, 1, 0, 0);
	GLUquadric* tapa = gluNewQuadric();
	gluQuadricTexture(tapa, TRUE);
	gluQuadricNormals(tapa, GLU_SMOOTH);
	tex.aplicar();
	gluDisk(tapa, 0, 3, 20, 40);
	glPopMatrix();
	gluDeleteQuadric(tapa);


	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	GLUquadric* taza = gluNewQuadric();
	gluQuadricTexture(taza, TRUE);
	gluQuadricNormals(taza, GLU_SMOOTH);
	tex.aplicar();
	gluCylinder(taza, 3, 3, 8, 40, 1);
	glPopMatrix();
	gluDeleteQuadric(taza);

	glPopMatrix();
}

void Modelo::mesaRectangular(GLfloat tam) {

	char* texturaMesa;
	std::string str_mesa("./texturas/mesa.jpg");
	texturaMesa = &str_mesa[0];
	igvTextura tex = igvTextura(texturaMesa);

	glPushMatrix();

	glScalef(tam, tam, tam);

	glPushMatrix();
	glTranslatef(13, 0, 6);
	glRotatef(90, 1, 0, 0);
	GLUquadric* pata4 = gluNewQuadric();
	gluQuadricTexture(pata4, TRUE);
	gluQuadricNormals(pata4, GLU_SMOOTH);
	tex.aplicar();
	gluCylinder(pata4, 1, 1, 18, 40, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-13, 0, 6);
	glRotatef(90, 1, 0, 0);
	GLUquadric* pata3 = gluNewQuadric();
	gluQuadricTexture(pata3, TRUE);
	gluQuadricNormals(pata3, GLU_SMOOTH);
	tex.aplicar();
	gluCylinder(pata3, 1, 1, 18, 40, 1);
	glPopMatrix();



	glPushMatrix();
	glTranslatef(-13, 0, -6);
	glRotatef(90, 1, 0, 0);
	GLUquadric* pata2 = gluNewQuadric();
	gluQuadricTexture(pata2, TRUE);
	gluQuadricNormals(pata2, GLU_SMOOTH);
	tex.aplicar();
	gluCylinder(pata2, 1, 1, 18, 40, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(13, 0, -6);
	glRotatef(90, 1, 0, 0);
	GLUquadric* pata1 = gluNewQuadric();
	gluQuadricTexture(pata1, TRUE);
	gluQuadricNormals(pata1, GLU_SMOOTH);
	tex.aplicar();
	gluCylinder(pata1, 1, 1, 18, 40, 1);
	glPopMatrix();


	glPushMatrix();
	glScalef(13, 1, 7);
	dibujaCubo(3, "./texturas/mesa.jpg");
	glPopMatrix();

	glPopMatrix();

}

void Modelo::dibujaCuboSecreto(GLfloat tam, std::string rutaTextura, std::string rutaTexturaSecret) {
	tam = tam / 2;

	char* textura;
	std::string str_obj(rutaTextura);
	textura = &str_obj[0];

	char* texturaSecreto;
	std::string str_secret(rutaTexturaSecret);
	texturaSecreto = &str_secret[0];
	igvTextura tex = igvTextura(textura);

	igvTextura texSecret = igvTextura(texturaSecreto);

	texSecret.aplicar();
	glPushMatrix();
	glNormal3f(0, 0, -1);
	glBegin(GL_QUADS);

	glTexCoord2f(1.0, 1.0);
	glVertex3f(-tam, -tam, -tam);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(tam, -tam, -tam);

	glTexCoord2f(0.0, 0.0);
	glVertex3f(tam, tam, -tam);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(-tam, tam, -tam);
	glEnd();


	texSecret.aplicar();
	glNormal3f(0, -1, 0);
	glBegin(GL_QUADS);

	/* Floor */
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-tam, -tam, -tam);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(tam, -tam, -tam);

	glTexCoord2f(0.0, 0.0);
	glVertex3f(tam, -tam, tam);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(-tam, -tam, tam);
	glEnd();


	tex.aplicar();
	glNormal3f(0, 1, 0);
	glBegin(GL_QUADS);
	/* Ceiling */
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-tam, tam, -tam);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(tam, tam, -tam);

	glTexCoord2f(0.0, 0.0);
	glVertex3f(tam, tam, tam);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(-tam, tam, tam);

	glEnd();

	glNormal3f(0, 0, 1);
	glBegin(GL_QUADS);
	/* Walls */
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-tam, -tam, tam);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(tam, -tam, tam);

	glTexCoord2f(0.0, 0.0);
	glVertex3f(tam, tam, tam);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(-tam, tam, tam);

	glEnd();

	glNormal3f(1, 0, 0);
	glBegin(GL_QUADS);
	//Pared
	glTexCoord2f(0.0, 0.0);
	glVertex3f(tam, tam, tam);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(tam, -tam, tam);

	glTexCoord2f(1.0, 1.0);
	glVertex3f(tam, -tam, -tam);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(tam, tam, -tam);

	glEnd();


	glNormal3f(-1, 0, 0);
	glBegin(GL_QUADS);
	//Pared
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-tam, tam, tam);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(-tam, -tam, tam);

	glTexCoord2f(1.0, 1.0);
	glVertex3f(-tam, -tam, -tam);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(-tam, tam, -tam);
	glEnd();
	glPopMatrix();
}

float* Modelo::getColor() {

	return color;
}

void Modelo::setColor(float* c)
{
	color = c;
}

GLubyte* Modelo::getColorByte() {

	GLubyte colorubyte[3];
	colorubyte[0] = (GLubyte)(color[0] * 255);
	colorubyte[1] = (GLubyte)(color[1] * 255);
	colorubyte[2] = (GLubyte)(color[2] * 255);

	return colorubyte;
}

void Modelo::dibujaLampara(GLfloat tam, const GLfloat x, const GLfloat y, const GLfloat z) {
	
	char* texturaLampara;
	std::string str_lamp("./texturas/lamparaCabeza.jpg");
	texturaLampara = &str_lamp[0];

	char* texturaLamparaSuelo;
	std::string str_lampS("./texturas/metal.jpg");
	texturaLamparaSuelo = &str_lampS[0];

	char* texturaLamparaPalo;
	std::string str_lampP("./texturas/metal.jpg");
	texturaLamparaPalo = &str_lampP[0];

	igvTextura texLamp = igvTextura(texturaLampara);
	igvTextura texLampS = igvTextura(texturaLamparaSuelo);
	igvTextura texLampP = igvTextura(texturaLamparaPalo);

	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(tam, tam, tam);

	glPushMatrix();
	glTranslatef(0, 38, 0);
	glRotatef(-90, 1, 0, 0);
	GLUquadric* tope = gluNewQuadric();
	gluQuadricTexture(tope, TRUE);
	gluQuadricNormals(tope, GLU_SMOOTH);
	texLamp.aplicar();
	gluCylinder(tope, 7, 2, 8, 40, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 41, 0);
	glutSolidSphere(2, 30, 30);
	glPopMatrix();


	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	GLUquadric* palo = gluNewQuadric();
	gluQuadricTexture(palo, TRUE);
	gluQuadricNormals(palo, GLU_SMOOTH);
	texLampP.aplicar();
	gluCylinder(palo, 1, 1, 40, 40, 1);
	glPopMatrix();


	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	GLUquadric* base = gluNewQuadric();
	gluQuadricTexture(base, TRUE);
	gluQuadricNormals(base, GLU_SMOOTH);
	texLampS.aplicar();
	gluCylinder(base, 7, 1, 3, 40, 1);
	glPopMatrix();

	glPopMatrix();

}