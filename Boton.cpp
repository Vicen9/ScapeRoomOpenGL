#include "Boton.h"
#include "igvTextura.h"

Boton::Boton()
{
	seleccionado = false;
	rotacion = 0;

	color = new float[4];

	color[0] = 0;
	color[1] = 0;
	color[2] = 0;
	color[3] = 0;
}

void Boton::dibujaBotonCero(int tam, std::string ruta)
{
	float* col = new float[4];

	col[0] = 0.9;
	col[1] = 0.9;
	col[2] = 0.8;
	col[3] = 0.0;

	color[0] = col[0];
	color[1] = col[1];
	color[2] = col[2];
	color[3] = col[3];

	glMaterialfv(GL_FRONT, GL_EMISSION, col);
	glColor3fv(col);

	glPushMatrix();

	glTranslatef(35.73, 25, 199.5);
	glScalef(tam, tam, tam);
	glScalef(1.9, 0.5, 0.1);
	dibujaCubo(1, "./texturas/0.jpg");
	glPopMatrix();
}

void Boton::dibujaBotonCeroNT(int tam)
{
	glPushMatrix();

	glTranslatef(35.73, 25, 199.5);
	glScalef(tam, tam, tam);
	glScalef(1.9, 0.5, 0.1);
	glutSolidCube(1);

	glPopMatrix();
}

void Boton::dibujaBotonNumero(int tam, int numero, std::string ruta)
{
	char* texturaBoton;
	std::string str_bot(ruta);
	texturaBoton = &str_bot[0];

	GLfloat separacionX = 0.7;

	glPushMatrix();

	glTranslatef(33, 29.5, 200);
	glScalef(tam, tam, tam);

	if (numero == 9)
	{
		float* col = new float[4];

		col[0] = 0.8;
		col[1] = 0.9;
		col[2] = 0.8;
		col[3] = 0.0;

		color[0] = col[0];
		color[1] = col[1];
		color[2] = col[2];
		color[3] = col[3];

		glMaterialfv(GL_FRONT, GL_EMISSION, col);
		glColor3fv(col);

		glPushMatrix();
		glTranslatef(0 * separacionX, 0, -0.05);
		glScalef(0.5, 0.5, 0.1);
		dibujaCubo(1, "./texturas/9.jpg");
		glPopMatrix();
	}

	if (numero == 8)
	{
		float* col = new float[4];

		col[0] = 0.9;
		col[1] = 0.9;
		col[2] = 0.9;
		col[3] = 0.0;

		color[0] = col[0];
		color[1] = col[1];
		color[2] = col[2];
		color[3] = col[3];

		glMaterialfv(GL_FRONT, GL_EMISSION, col);
		glColor3fv(col);

		glPushMatrix();
		glTranslatef(1 * separacionX, 0, -0.05);
		glScalef(0.5, 0.5, 0.1);
		dibujaCubo(1, "./texturas/8.jpg");
		glPopMatrix();
	}

	if (numero == 7)
	{
		float* col = new float[4];

		col[0] = 0.8;
		col[1] = 0.8;
		col[2] = 0.8;
		col[3] = 0.0;

		color[0] = col[0];
		color[1] = col[1];
		color[2] = col[2];
		color[3] = col[3];

		glMaterialfv(GL_FRONT, GL_EMISSION, col);
		glColor3fv(col);

		glPushMatrix();
		glTranslatef(2 * separacionX, 0, -0.05);
		glScalef(0.5, 0.5, 0.1);
		dibujaCubo(1, "./texturas/7.jpg");
		glPopMatrix();
	}

	if (numero == 6)
	{
		float* col = new float[4];

		col[0] = 0.7;
		col[1] = 0.7;
		col[2] = 0.7;
		col[3] = 0.0;

		color[0] = col[0];
		color[1] = col[1];
		color[2] = col[2];
		color[3] = col[3];

		glMaterialfv(GL_FRONT, GL_EMISSION, col);
		glColor3fv(col);

		glPushMatrix();
		glTranslatef(0 * separacionX, 1, -0.05);
		glScalef(0.5, 0.5, 0.1);
		dibujaCubo(1, "./texturas/6.jpg");
		glPopMatrix();
	}

	if (numero == 5)
	{
		float* col = new float[4];

		col[0] = 0.6;
		col[1] = 0.6;
		col[2] = 0.6;
		col[3] = 0.0;

		color[0] = col[0];
		color[1] = col[1];
		color[2] = col[2];
		color[3] = col[3];

		glMaterialfv(GL_FRONT, GL_EMISSION, col);
		glColor3fv(col);

		glPushMatrix();
		glTranslatef(1 * separacionX, 1, -0.05);
		glScalef(0.5, 0.5, 0.1);
		dibujaCubo(1, "./texturas/5.jpg");
		glPopMatrix();
	}

	if (numero == 4)
	{
		float* col = new float[4];

		col[0] = 0.8;
		col[1] = 0.9;
		col[2] = 0.9;
		col[3] = 0.0;

		color[0] = col[0];
		color[1] = col[1];
		color[2] = col[2];
		color[3] = col[3];

		glMaterialfv(GL_FRONT, GL_EMISSION, col);
		glColor3fv(col);

		glPushMatrix();
		glTranslatef(2 * separacionX, 1, -0.05);
		glScalef(0.5, 0.5, 0.1);
		dibujaCubo(1, "./texturas/4.jpg");
		glPopMatrix();
	}

	if (numero == 3)
	{
		float* col = new float[4];

		col[0] = 0.9;
		col[1] = 0.8;
		col[2] = 0.9;
		col[3] = 0.0;

		color[0] = col[0];
		color[1] = col[1];
		color[2] = col[2];
		color[3] = col[3];

		glMaterialfv(GL_FRONT, GL_EMISSION, col);
		glColor3fv(col);

		glPushMatrix();
		glTranslatef(0 * separacionX, 2, -0.05);
		glScalef(0.5, 0.5, 0.1);
		dibujaCubo(1, "./texturas/3.jpg");
		glPopMatrix();
	}

	if (numero == 2)
	{
		float* col = new float[4];

		col[0] = 0.9;
		col[1] = 0.9;
		col[2] = 0.6;
		col[3] = 0.0;

		color[0] = col[0];
		color[1] = col[1];
		color[2] = col[2];
		color[3] = col[3];

		glMaterialfv(GL_FRONT, GL_EMISSION, col);
		glColor3fv(col);

		glPushMatrix();
		glTranslatef(1 * separacionX, 2, -0.05);
		glScalef(0.5, 0.5, 0.1);
		dibujaCubo(1, "./texturas/2.jpg");
		glPopMatrix();
	}

	if (numero == 1)
	{
		float* col = new float[4];

		col[0] = 0.9;
		col[1] = 0.9;
		col[2] = 0.7;
		col[3] = 0.0;

		color[0] = col[0];
		color[1] = col[1];
		color[2] = col[2];
		color[3] = col[3];

		glMaterialfv(GL_FRONT, GL_EMISSION, col);
		glColor3fv(col);

		glPushMatrix();
		glTranslatef(2 * separacionX, 2, -0.05);
		glScalef(0.5, 0.5, 0.1);
		dibujaCubo(1, "./texturas/1.jpg");
		glPopMatrix();
	}

	glPopMatrix();
}

void Boton::dibujaBotonNumeroNT(int tam, int numero)
{
	GLfloat separacionX = 0.7;

	glPushMatrix();

	glTranslatef(33, 29.5, 200);
	glScalef(tam, tam, tam);

	if (numero == 9)
	{
		float* col = new float[4];

		col[0] = 0.8;
		col[1] = 0.9;
		col[2] = 0.8;
		col[3] = 0.0;

		color[0] = col[0];
		color[1] = col[1];
		color[2] = col[2];
		color[3] = col[3];

		glMaterialfv(GL_FRONT, GL_EMISSION, col);
		glColor3fv(col);

		glPushMatrix();
		glTranslatef(0 * separacionX, 0, -0.05);
		glScalef(0.5, 0.5, 0.1);
		glutSolidCube(1);
		glPopMatrix();
	}

	if (numero == 8)
	{
		float* col = new float[4];

		col[0] = 0.9;
		col[1] = 0.9;
		col[2] = 0.9;
		col[3] = 0.0;

		color[0] = col[0];
		color[1] = col[1];
		color[2] = col[2];
		color[3] = col[3];

		glMaterialfv(GL_FRONT, GL_EMISSION, col);
		glColor3fv(col);

		glPushMatrix();
		glTranslatef(1 * separacionX, 0, -0.05);
		glScalef(0.5, 0.5, 0.1);
		glutSolidCube(1);
		glPopMatrix();
	}

	if (numero == 7)
	{
		float* col = new float[4];

		col[0] = 0.8;
		col[1] = 0.8;
		col[2] = 0.8;
		col[3] = 0.0;

		color[0] = col[0];
		color[1] = col[1];
		color[2] = col[2];
		color[3] = col[3];

		glMaterialfv(GL_FRONT, GL_EMISSION, col);
		glColor3fv(col);

		glPushMatrix();
		glTranslatef(2 * separacionX, 0, -0.05);
		glScalef(0.5, 0.5, 0.1);
		glutSolidCube(1);
		glPopMatrix();
	}

	if (numero == 6)
	{
		float* col = new float[4];

		col[0] = 0.7;
		col[1] = 0.7;
		col[2] = 0.7;
		col[3] = 0.0;

		color[0] = col[0];
		color[1] = col[1];
		color[2] = col[2];
		color[3] = col[3];

		glMaterialfv(GL_FRONT, GL_EMISSION, col);
		glColor3fv(col);

		glPushMatrix();
		glTranslatef(0 * separacionX, 1, -0.05);
		glScalef(0.5, 0.5, 0.1);
		glutSolidCube(1);
		glPopMatrix();
	}

	if (numero == 5)
	{
		float* col = new float[4];

		col[0] = 0.6;
		col[1] = 0.6;
		col[2] = 0.6;
		col[3] = 0.0;

		color[0] = col[0];
		color[1] = col[1];
		color[2] = col[2];
		color[3] = col[3];

		glMaterialfv(GL_FRONT, GL_EMISSION, col);
		glColor3fv(col);

		glPushMatrix();
		glTranslatef(1 * separacionX, 1, -0.05);
		glScalef(0.5, 0.5, 0.1);
		glutSolidCube(1);
		glPopMatrix();
	}

	if (numero == 4)
	{
		float* col = new float[4];

		col[0] = 0.8;
		col[1] = 0.9;
		col[2] = 0.9;
		col[3] = 0.0;

		color[0] = col[0];
		color[1] = col[1];
		color[2] = col[2];
		color[3] = col[3];

		glMaterialfv(GL_FRONT, GL_EMISSION, col);
		glColor3fv(col);

		glPushMatrix();
		glTranslatef(2 * separacionX, 1, -0.05);
		glScalef(0.5, 0.5, 0.1);
		glutSolidCube(1);
		glPopMatrix();
	}

	if (numero == 3)
	{
		float* col = new float[4];

		col[0] = 0.9;
		col[1] = 0.8;
		col[2] = 0.9;
		col[3] = 0.0;

		color[0] = col[0];
		color[1] = col[1];
		color[2] = col[2];
		color[3] = col[3];

		glMaterialfv(GL_FRONT, GL_EMISSION, col);
		glColor3fv(col);

		glPushMatrix();
		glTranslatef(0 * separacionX, 2, -0.05);
		glScalef(0.5, 0.5, 0.1);
		glutSolidCube(1);
		glPopMatrix();
	}

	if (numero == 2)
	{
		float* col = new float[4];

		col[0] = 0.9;
		col[1] = 0.9;
		col[2] = 0.6;
		col[3] = 0.0;

		color[0] = col[0];
		color[1] = col[1];
		color[2] = col[2];
		color[3] = col[3];

		glMaterialfv(GL_FRONT, GL_EMISSION, col);
		glColor3fv(col);

		glPushMatrix();
		glTranslatef(1 * separacionX, 2, -0.05);
		glScalef(0.5, 0.5, 0.1);
		glutSolidCube(1);
		glPopMatrix();
	}

	if (numero == 1)
	{
		float* col = new float[4];

		col[0] = 0.9;
		col[1] = 0.9;
		col[2] = 0.7;
		col[3] = 0.0;

		color[0] = col[0];
		color[1] = col[1];
		color[2] = col[2];
		color[3] = col[3];

		glMaterialfv(GL_FRONT, GL_EMISSION, col);
		glColor3fv(col);

		glPushMatrix();
		glTranslatef(2 * separacionX, 2, -0.05);
		glScalef(0.5, 0.5, 0.1);
		glutSolidCube(1);
		glPopMatrix();
	}

	glPopMatrix();
}

void Boton::dibujaCubo(GLfloat tam, std::string rutaTextura) {

	tam = tam / 2;

	char* textura;
	std::string str_obj(rutaTextura);
	textura = &str_obj[0];

	igvTextura tex = igvTextura(textura);
	tex.aplicar();

	glNormal3f(0, 1, 0);
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

	/* Ceiling */
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-tam, tam, -tam);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(tam, tam, -tam);

	glTexCoord2f(0.0, 0.0);
	glVertex3f(tam, tam, tam);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(-tam, tam, tam);

	/* Walls */
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-tam, -tam, tam);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(tam, -tam, tam);

	glTexCoord2f(0.0, 0.0);
	glVertex3f(tam, tam, tam);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(-tam, tam, tam);

	//Pared
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-tam, -tam, -tam);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(tam, -tam, -tam);

	glTexCoord2f(0.0, 0.0);
	glVertex3f(tam, tam, -tam);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(-tam, tam, -tam);

	//Pared
	glTexCoord2f(0.0, 0.0);
	glVertex3f(tam, tam, tam);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(tam, -tam, tam);

	glTexCoord2f(1.0, 1.0);
	glVertex3f(tam, -tam, -tam);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(tam, tam, -tam);

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
}

GLubyte* Boton::getColorByte() {

	GLubyte colorubyte[4];
	colorubyte[0] = (GLubyte)(color[0] * 255);
	colorubyte[1] = (GLubyte)(color[1] * 255);
	colorubyte[2] = (GLubyte)(color[2] * 255);
	colorubyte[3] = (GLubyte)(color[3] * 255);

	return colorubyte;
}