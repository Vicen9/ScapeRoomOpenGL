#include "Tractor.h"
#include "Modelo.h"


Tractor::Tractor() {

	seleccionado = false;
	rotacion = 0;

	color = new float[3];

	color[0] = 0;
	color[1] = 0;
	color[2] = 0;
}

void Tractor::recorrido_preorden(Nodo* raiz) {
	if (raiz)
	{
		aplicarMatrizTransformacion(raiz->getTipo());
		glPushMatrix();
		recorrido_preorden(raiz->getHijo1());
		glPopMatrix();
		glPushMatrix();
		recorrido_preorden(raiz->getHijo2());
		glPopMatrix();
	}
}

void Tractor::visualizar_arbol() {

	std::string s1 = "Cuerpo";
	std::string s2 = "BrazoPrimero";
	std::string s3 = "BrazoSegundo";
	std::string s4 = "Cazo";


	Nodo* cuerpo = new Nodo(s1);

	Nodo* brazoPrimero = new Nodo(s2);
	Nodo* brazoSegundo = new Nodo(s3);

	Nodo* cazo = new Nodo(s4);

	cuerpo->setHijo1(brazoPrimero);
	brazoPrimero->setHijo1(brazoSegundo);
	brazoSegundo->setHijo1(cazo);

	recorrido_preorden(cuerpo);

}

void Tractor::aplicarMatrizTransformacion(std::string tipo) {
	if (tipo == "Cuerpo")
	{
		glRotatef(rotCuerpo, 0, 1, 0);
		cuerpo();

	}
	else if (tipo == "BrazoPrimero")
	{

		glTranslatef(17, 0, 0);
		glRotatef(rotBrazo1, 0, 0, 1);
		glTranslatef(11, 0, 0);
		brazoPrimero();

	}
	else if (tipo == "BrazoSegundo")
	{

		glTranslatef(14, 0, 0);
		glRotatef(rotBrazo2, 0, 0, 1);
		glTranslatef(11, 0, 0);
		brazoSegundo();


	}
	else if (tipo == "Cazo")
	{
		glTranslatef(14, 0, 0);
		glRotatef(rotCazo, 0, 0, 1);
		cazo();

	}
	else
	{
		std::cout << "Se especifico un valor erroneo";
	}



}

void Tractor::cuerpo() {
	Modelo model;

	char* texturaTractor;
	std::string str_t("./texturas/tractor.jpg");
	texturaTractor = &str_t[0];

	char* texturaCristal;
	std::string str_tc("./texturas/cristal.jpg");
	texturaCristal = &str_tc[0];

	char* texturaRueda;
	std::string str_rueda("./texturas/rueda.jpg");
	texturaRueda = &str_rueda[0];

	char* texturaTapaRueda;
	std::string str_Taparueda("./texturas/rueda2.jpg");
	texturaTapaRueda = &str_Taparueda[0];



	igvTextura tex = igvTextura(texturaTractor);
	igvTextura texC = igvTextura(texturaCristal);
	igvTextura texRueda = igvTextura(texturaRueda);
	igvTextura texTapa = igvTextura(texturaTapaRueda);


	glPushMatrix();//General

		//Tapa de arriba
	glPushMatrix();
	glTranslatef(-5, 20, 0);
	glScalef(1.7, 1.7, 1.7);
	glRotatef(45, 0, 1, 0);
	glRotatef(90, 1, 0, 0);
	GLUquadric* tapaCuerpo = gluNewQuadric();
	gluQuadricNormals(tapaCuerpo, GLU_SMOOTH);
	gluQuadricTexture(tapaCuerpo, true);
	tex.aplicar();
	gluDisk(tapaCuerpo, 0, 4, 4, 60);
	gluDeleteQuadric(tapaCuerpo);
	glPopMatrix();

	//Parte de arriba

	glPushMatrix();

	glTranslatef(-5, 20, 0);
	glScalef(1.7, 1.7, 1.7);
	glRotatef(45, 0, 1, 0);
	glRotatef(90, 1, 0, 0);
	GLUquadric* cuerpoArriba = gluNewQuadric();
	gluQuadricNormals(cuerpoArriba, GLU_SMOOTH);
	gluQuadricTexture(cuerpoArriba, true);
	texC.aplicar();
	gluCylinder(cuerpoArriba, 4, 6, 7, 4, 4);
	gluDeleteQuadric(cuerpoArriba);
	glPopMatrix();

	//Rueda 1 tapa
	glPushMatrix();
	glTranslatef(-9, -7, -14);
	GLUquadric* tapa1 = gluNewQuadric();
	gluQuadricNormals(tapa1, GLU_SMOOTH);
	gluQuadricTexture(tapa1, true);
	texTapa.aplicar();
	gluDisk(tapa1, 0, 7, 40, 60);
	gluDeleteQuadric(tapa1);
	glPopMatrix();

	//Rueda 1
	glPushMatrix();
	glTranslatef(-9, -7, -14);
	GLUquadric* rueda1 = gluNewQuadric();
	gluQuadricNormals(rueda1, GLU_SMOOTH);
	gluQuadricTexture(rueda1, true);
	texRueda.aplicar();
	gluCylinder(rueda1, 7, 7, 5, 40, 60);
	gluDeleteQuadric(rueda1);
	glPopMatrix();


	//rueda 2 tapa
	glPushMatrix();
	glTranslatef(-9, -7, 14);
	GLUquadric* tapa2 = gluNewQuadric();
	gluQuadricNormals(tapa2, GLU_SMOOTH);
	gluQuadricTexture(tapa2, true);
	texTapa.aplicar();
	gluDisk(tapa2, 0, 7, 40, 60);
	gluDeleteQuadric(tapa2);
	glPopMatrix();

	//Rueda 2
	glPushMatrix();
	glTranslatef(-9, -7, 9);
	GLUquadric* rueda2 = gluNewQuadric();
	gluQuadricNormals(rueda2, GLU_SMOOTH);
	gluQuadricTexture(rueda2, true);
	texRueda.aplicar();
	gluCylinder(rueda2, 7, 7, 5, 40, 60);
	gluDeleteQuadric(rueda2);
	glPopMatrix();

	//Rueda 3 tapa
	glPushMatrix();
	glTranslatef(12, -7, 14);
	GLUquadric* tapa3 = gluNewQuadric();
	gluQuadricNormals(tapa3, GLU_SMOOTH);
	gluQuadricTexture(tapa3, true);
	texTapa.aplicar();
	gluDisk(tapa3, 0, 4, 40, 60);
	gluDeleteQuadric(tapa3);
	glPopMatrix();

	//Rueda 3
	glPushMatrix();
	glTranslatef(12, -7, 9);
	GLUquadric* rueda3 = gluNewQuadric();
	gluQuadricNormals(rueda3, GLU_SMOOTH);
	gluQuadricTexture(rueda3, true);
	texRueda.aplicar();
	gluCylinder(rueda3, 4, 4, 5, 40, 60);
	gluDeleteQuadric(rueda3);
	glPopMatrix();

	//Rueda 4 tapa
	glPushMatrix();
	glTranslatef(12, -7, -14);
	GLUquadric* tapa4 = gluNewQuadric();
	gluQuadricNormals(tapa4, GLU_SMOOTH);
	gluQuadricTexture(tapa4, true);
	texTapa.aplicar();
	gluDisk(tapa4, 0, 4, 40, 60);
	gluDeleteQuadric(tapa4);
	glPopMatrix();

	//Rueda 4
	glPushMatrix();
	glTranslatef(12, -7, -14);
	GLUquadric* rueda4 = gluNewQuadric();
	gluQuadricNormals(rueda4, GLU_SMOOTH);
	gluQuadricTexture(rueda4, true);
	texRueda.aplicar();
	gluCylinder(rueda4, 4, 4, 5, 40, 60);
	gluDeleteQuadric(rueda4);
	glPopMatrix();

	//Cuerpo
	glPushMatrix();
	glScalef(5, 3, 3);
	model.dibujaCubo(6, "./texturas/tractor.jpg");
	glPopMatrix();

	glPopMatrix();//General


}

void Tractor::brazoPrimero() {
	Modelo model;
	char* texturaTractor;
	std::string str_t("./texturas/tractor.jpg");
	texturaTractor = &str_t[0];
	igvTextura tex = igvTextura(texturaTractor);

	glPushMatrix();

	glTranslatef(-11, 0, -4);
	GLUquadric* brazoPrimero = gluNewQuadric();
	gluQuadricNormals(brazoPrimero, GLU_SMOOTH);
	gluQuadricTexture(brazoPrimero, true);
	tex.aplicar();
	gluCylinder(brazoPrimero, 2.5, 2.5, 7, 40, 60);
	glPopMatrix();


	glPushMatrix();
	glScalef(8, 1.5, 1.5);
	model.dibujaCubo(3, "./texturas/tractor.jpg");

	glPopMatrix();


	gluDeleteQuadric(brazoPrimero);

}

void Tractor::brazoSegundo() {
	Modelo model;
	char* texturaTractor;
	std::string str_t("./texturas/tractor.jpg");
	texturaTractor = &str_t[0];
	igvTextura tex = igvTextura(texturaTractor);


	glPushMatrix();

	glTranslatef(-11, 0, -4);
	GLUquadric* brazoSegundo = gluNewQuadric();
	gluQuadricNormals(brazoSegundo, GLU_SMOOTH);
	gluQuadricTexture(brazoSegundo, true);
	tex.aplicar();
	gluCylinder(brazoSegundo, 2.5, 2.5, 7, 40, 60);

	glPopMatrix();


	glPushMatrix();
	glScalef(8, 1.5, 1.5);
	model.dibujaCubo(3, "./texturas/tractor.jpg");
	glPopMatrix();

	gluDeleteQuadric(brazoSegundo);
}

void Tractor::cazo() {
	Modelo model;
	char* texturaTractor;
	std::string str_t("./texturas/tractor.jpg");
	texturaTractor = &str_t[0];
	igvTextura tex = igvTextura(texturaTractor);


	glPushMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -8);
	GLUquadric* cazoQua = gluNewQuadric();
	gluQuadricNormals(cazoQua, GLU_SMOOTH);
	gluQuadricTexture(cazoQua, true);
	tex.aplicar();
	gluCylinder(cazoQua, 2.5, 2.5, 16, 40, 60);

	gluDeleteQuadric(cazoQua);
	glPopMatrix();




	glPushMatrix();
	glTranslatef(6, 5.5, 8);
	glScalef(2.5, 2.5, 0.2);
	model.dibujaCubo(5, "./texturas/tractor.jpg");

	glPopMatrix();

	glPushMatrix();
	glTranslatef(6, 5.5, -8);
	glScalef(2.5, 2.5, 0.2);
	model.dibujaCubo(5, "./texturas/tractor.jpg");
	glPopMatrix();


	glPushMatrix();
	glTranslatef(7, 0, 0);
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glScalef(3, 3, 0.2);
	model.dibujaCuboSecreto(5, "./texturas/tractor.jpg", "./texturas/tractor_secret.jpg");
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0, 8, 0);
	glRotatef(90, 0, 1, 0);
	glScalef(3, 3, 0.2);
	model.dibujaCubo(5, "./texturas/tractor.jpg");
	glPopMatrix();


	glPopMatrix();

}

void Tractor::dibujaTractor(GLfloat tam)
{
	glPushMatrix();
	glScalef(tam, tam, tam);
	visualizar_arbol();
	glPopMatrix();
}

// Version NT (No texture)

void Tractor::recorrido_preordenNT(Nodo* raiz) {
	if (raiz)
	{
		aplicarMatrizTransformacionNT(raiz->getTipo());
		glPushMatrix();
		recorrido_preordenNT(raiz->getHijo1());
		glPopMatrix();
		glPushMatrix();
		recorrido_preordenNT(raiz->getHijo2());
		glPopMatrix();
	}
}

void Tractor::visualizar_arbolNT() {

	std::string s1 = "Cuerpo";
	std::string s2 = "BrazoPrimero";
	std::string s3 = "BrazoSegundo";
	std::string s4 = "Cazo";


	Nodo* cuerpo = new Nodo(s1);

	Nodo* brazoPrimero = new Nodo(s2);
	Nodo* brazoSegundo = new Nodo(s3);

	Nodo* cazo = new Nodo(s4);

	cuerpo->setHijo1(brazoPrimero);
	brazoPrimero->setHijo1(brazoSegundo);
	brazoSegundo->setHijo1(cazo);

	recorrido_preordenNT(cuerpo);

}

void Tractor::aplicarMatrizTransformacionNT(std::string tipo) {
	if (tipo == "Cuerpo")
	{
		glRotatef(rotCuerpo, 0, 1, 0);
		cuerpoNT();

	}
	else if (tipo == "BrazoPrimero")
	{

		glTranslatef(17, 0, 0);
		glRotatef(rotBrazo1, 0, 0, 1);
		glTranslatef(11, 0, 0);
		brazoPrimeroNT();

	}
	else if (tipo == "BrazoSegundo")
	{

		glTranslatef(14, 0, 0);
		glRotatef(rotBrazo2, 0, 0, 1);
		glTranslatef(11, 0, 0);
		brazoSegundoNT();


	}
	else if (tipo == "Cazo")
	{
		glTranslatef(14, 0, 0);
		glRotatef(rotCazo, 0, 0, 1);
		cazoNT();

	}
	else
	{
		std::cout << "Se especifico un valor erroneo";
	}



}

void Tractor::cuerpoNT() {
	glPushMatrix();//General

		//Tapa de arriba
	glPushMatrix();
	glTranslatef(-5, 20, 0);
	glScalef(1.7, 1.7, 1.7);
	glRotatef(45, 0, 1, 0);
	glRotatef(90, 1, 0, 0);
	GLUquadric* tapaCuerpo = gluNewQuadric();
	gluDisk(tapaCuerpo, 0, 4, 4, 60);
	gluDeleteQuadric(tapaCuerpo);
	glPopMatrix();

	//Parte de arriba

	glPushMatrix();

	glTranslatef(-5, 20, 0);
	glScalef(1.7, 1.7, 1.7);
	glRotatef(45, 0, 1, 0);
	glRotatef(90, 1, 0, 0);
	GLUquadric* cuerpoArriba = gluNewQuadric();
	gluCylinder(cuerpoArriba, 4, 6, 7, 4, 4);
	gluDeleteQuadric(cuerpoArriba);
	glPopMatrix();

	//Rueda 1 tapa
	glPushMatrix();
	glTranslatef(-9, -7, -14);
	GLUquadric* tapa1 = gluNewQuadric();
	gluDisk(tapa1, 0, 7, 40, 60);
	gluDeleteQuadric(tapa1);
	glPopMatrix();

	//Rueda 1
	glPushMatrix();
	glTranslatef(-9, -7, -14);
	GLUquadric* rueda1 = gluNewQuadric();
	gluCylinder(rueda1, 7, 7, 5, 40, 60);
	gluDeleteQuadric(rueda1);
	glPopMatrix();


	//rueda 2 tapa
	glPushMatrix();
	glTranslatef(-9, -7, 14);
	GLUquadric* tapa2 = gluNewQuadric();
	gluDisk(tapa2, 0, 7, 40, 60);
	gluDeleteQuadric(tapa2);
	glPopMatrix();

	//Rueda 2
	glPushMatrix();
	glTranslatef(-9, -7, 9);
	GLUquadric* rueda2 = gluNewQuadric();
	gluCylinder(rueda2, 7, 7, 5, 40, 60);
	gluDeleteQuadric(rueda2);
	glPopMatrix();

	//Rueda 3 tapa
	glPushMatrix();
	glTranslatef(12, -7, 14);
	GLUquadric* tapa3 = gluNewQuadric();
	gluDisk(tapa3, 0, 4, 40, 60);
	gluDeleteQuadric(tapa3);
	glPopMatrix();

	//Rueda 3
	glPushMatrix();
	glTranslatef(12, -7, 9);
	GLUquadric* rueda3 = gluNewQuadric();
	gluCylinder(rueda3, 4, 4, 5, 40, 60);
	gluDeleteQuadric(rueda3);
	glPopMatrix();

	//Rueda 4 tapa
	glPushMatrix();
	glTranslatef(12, -7, -14);
	GLUquadric* tapa4 = gluNewQuadric();
	gluDisk(tapa4, 0, 4, 40, 60);
	gluDeleteQuadric(tapa4);
	glPopMatrix();

	//Rueda 4
	glPushMatrix();
	glTranslatef(12, -7, -14);
	GLUquadric* rueda4 = gluNewQuadric();
	gluCylinder(rueda4, 4, 4, 5, 40, 60);
	gluDeleteQuadric(rueda4);
	glPopMatrix();

	//Cuerpo
	glPushMatrix();
	glScalef(5, 3, 3);
	glutSolidCube(6);
	glPopMatrix();

	glPopMatrix();//General


}

void Tractor::brazoPrimeroNT() {
	glPushMatrix();

	glTranslatef(-11, 0, -4);
	GLUquadric* brazoPrimero = gluNewQuadric();
	gluCylinder(brazoPrimero, 2.5, 2.5, 7, 40, 60);
	glPopMatrix();


	glPushMatrix();
	glScalef(8, 1.5, 1.5);
	glutSolidCube(3);
	glPopMatrix();


	gluDeleteQuadric(brazoPrimero);

}

void Tractor::brazoSegundoNT() {
	Modelo model;
	glPushMatrix();

	glTranslatef(-11, 0, -4);
	GLUquadric* brazoSegundo = gluNewQuadric();
	gluCylinder(brazoSegundo, 2.5, 2.5, 7, 40, 60);

	glPopMatrix();


	glPushMatrix();
	glScalef(8, 1.5, 1.5);
	glutSolidCube(3);
	glPopMatrix();

	gluDeleteQuadric(brazoSegundo);
}

void Tractor::cazoNT() {

	glPushMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -8);
	GLUquadric* cazoQua = gluNewQuadric();
	gluCylinder(cazoQua, 2.5, 2.5, 16, 40, 60);
	gluDeleteQuadric(cazoQua);
	glPopMatrix();



	glPushMatrix();
	glTranslatef(6, 5.5, 8);
	glScalef(2.5, 2.5, 0.2);
	glutSolidCube(5);

	glPopMatrix();

	glPushMatrix();
	glTranslatef(6, 5.5, -8);
	glScalef(2.5, 2.5, 0.2);
	glutSolidCube(5);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(7, 0, 0);
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	glScalef(3, 3, 0.2);
	glutSolidCube(5);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0, 8, 0);
	glRotatef(90, 0, 1, 0);
	glScalef(3, 3, 0.2);
	glutSolidCube(5);
	glPopMatrix();

	glPopMatrix();

}

void Tractor::dibujaTractorNT(GLfloat tam)
{
	glPushMatrix();
	glScalef(tam, tam, tam);
	visualizar_arbolNT();
	glPopMatrix();
}

float* Tractor::getColor() {

	return color;
}

void Tractor::setColor(float* c)
{
	color = c;
}

GLubyte* Tractor::getColorByte() {

	GLubyte colorubyte[3];
	colorubyte[0] = (GLubyte)(color[0] * 255);
	colorubyte[1] = (GLubyte)(color[1] * 255);
	colorubyte[2] = (GLubyte)(color[2] * 255);

	return colorubyte;
}