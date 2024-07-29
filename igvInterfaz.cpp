#include <cstdlib>
#include <stdio.h>
#include <iostream>

#include "igvInterfaz.h"
#include "Boton.h"
#include "Math.h"

# define M_PI           3.14159265358979323846

extern igvInterfaz interfaz; // los callbacks deben ser estaticos y se requiere este objeto para acceder desde
                             // ellos a las variables de la clase

// Metodos constructores -----------------------------------

igvInterfaz::igvInterfaz () {

	angulo = 0;
	NORTE = true;
	SUR = false;
	ESTE = false;
	OESTE = false;
	velocidad = 7;
	modo = IGV_VISUALIZAR;
	objeto_seleccionado = -1;
	boton_retenido = false;
	interfaz.escena.CAMDEMON = &interfaz.camara;
	interfaz.escena.ANGULOO = &interfaz.angulo;
	interfaz.escena.VELOC = &interfaz.velocidad;

	interfaz.codCorrecto[0] = 3;
	interfaz.codCorrecto[1] = 7;
	interfaz.codCorrecto[2] = 1;
	interfaz.codCorrecto[3] = 9;

	interfaz.ACCEPTED = true;
}

igvInterfaz::~igvInterfaz () {}


// Metodos publicos ----------------------------------------

void igvInterfaz::crear_mundo(void) {
	
	creacionCamaras();

}

void igvInterfaz::configura_entorno(int argc, char** argv,
			                              int _ancho_ventana, int _alto_ventana,
			                              int _pos_X, int _pos_Y,
													          string _titulo){
	// inicialización de las variables de la interfaz																	
	ancho_ventana = _ancho_ventana;
	alto_ventana = _alto_ventana;

	// inicialización de la ventana de visualización
	glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(_ancho_ventana,_alto_ventana);
  glutInitWindowPosition(_pos_X,_pos_Y);
	glutCreateWindow(_titulo.c_str());

	glEnable(GL_DEPTH_TEST); // activa el ocultamiento de superficies por z-buffer
  glClearColor(1.0,1.0,1.0,0.0); // establece el color de fondo de la ventana

	glEnable(GL_LIGHTING); // activa la iluminacion de la escena
  glEnable(GL_NORMALIZE); // normaliza los vectores normales para calculo iluminacion

	glEnable(GL_TEXTURE_2D); // activa el uso de texturas

	crear_mundo(); // crea el mundo a visualizar en la ventana
}

void igvInterfaz::inicia_bucle_visualizacion() {
	glutMainLoop(); // inicia el bucle de visualizacion de OpenGL
}

void igvInterfaz::set_glutSpecialFunc(int key, int x, int y) {
	
	double xN;
	double yN;
	double zN;

	double xrefN;
	double yrefN;
	double zrefN;

	igvPunto3D nuevoPunto(0, 0, 0);
	igvPunto3D nuevoPuntoRef(0, 0, 0);

	double xTot;
	double yTot;
	double zTot;

	double radio;
	double alfa;

	double xx;
	double yy;
	double zz;

	switch (key)
	{
	case GLUT_KEY_UP:

		if (!interfaz.escena.caja.seleccionado && !interfaz.escena.tractor.seleccionado)
		{
			if (interfaz.cam == interfaz.CP)
			{
				interfaz.mirarArriba();
			}
		}

		break;
	case GLUT_KEY_DOWN:

		if (!interfaz.escena.caja.seleccionado && !interfaz.escena.tractor.seleccionado)
		{
			if (interfaz.cam == interfaz.CP)
			{
				interfaz.mirarAbajo();
			}
		}

		break;
	case GLUT_KEY_LEFT:

		if (!interfaz.escena.caja.seleccionado && !interfaz.escena.tractor.seleccionado)
		{
			if (interfaz.cam == interfaz.CP)
			{
				interfaz.rotacionIzquierda();
			}

			if (interfaz.cam == interfaz.CS1)
			{
				interfaz.rotacionIzquierdaCS1();
			}

			if (interfaz.cam == interfaz.CS2)
			{
				interfaz.rotacionIzquierdaCS2();
			}
		}

		break;
	case GLUT_KEY_RIGHT:

		if (!interfaz.escena.caja.seleccionado && !interfaz.escena.tractor.seleccionado)
		{
			if (interfaz.cam == interfaz.CP)
			{
				interfaz.rotacionDerecha();
			}

			if (interfaz.cam == interfaz.CS1)
			{
				interfaz.rotacionDerechaCS1();
			}

			if (interfaz.cam == interfaz.CS2)
			{
				interfaz.rotacionDerechaCS2();
			}
		}

		break;
	}

	glutPostRedisplay(); // renueva el contenido de la ventana de vision y redibuja la escena
}

void igvInterfaz::set_glutKeyboardFunc(unsigned char key, int x, int y) {
	
	double difX;
	double difY;
	double difZ;

	double radio;

	switch (key) {
	case 'w': // Mueve el personaje hacia delante
		
		if (!interfaz.escena.caja.seleccionado && !interfaz.escena.tractor.seleccionado)
		{
			if (interfaz.cam == interfaz.CP)
			{
				interfaz.movimientoAdelante();
			}
		}

		break;
	case 's': // Movimiento del personaje hacia atrás.
		
		if (!interfaz.escena.caja.seleccionado && !interfaz.escena.tractor.seleccionado)
		{
			if (interfaz.cam == interfaz.CP)
			{
				interfaz.movimientoAtras();
			}
		}

		break;
	case 'd': // Movimiento del personaje hacia la derecha.

		if (!interfaz.escena.caja.seleccionado && !interfaz.escena.tractor.seleccionado)
		{
			if (interfaz.cam == interfaz.CP)
			{
				interfaz.movimientoDerecha();
			}
		}

		break;
	case 'a': // Movimiento del personaje hacia la izquierda.

		if (!interfaz.escena.caja.seleccionado && !interfaz.escena.tractor.seleccionado)
		{
			if (interfaz.cam == interfaz.CP)
			{
				interfaz.movimientoIzquierda();
			}
		}

		break;
	case 'b': // Rotacion del tractor
		if (interfaz.escena.tractor.seleccionado)
		{
			interfaz.escena.tractor.rotCuerpo = interfaz.escena.tractor.rotCuerpo - 10;
		}
		break;
	case 'n': // Rotacion del tractor
		if (interfaz.escena.tractor.seleccionado)
		{
			interfaz.escena.tractor.rotCuerpo = interfaz.escena.tractor.rotCuerpo + 10;
		}
		break;
	case 'h': // Rotacion del brazo largo del tractor
		if (interfaz.escena.tractor.seleccionado)
		{
			if (interfaz.escena.tractor.rotBrazo1 < 100)
			{
				interfaz.escena.tractor.rotBrazo1 = interfaz.escena.tractor.rotBrazo1 + 10;
			}
		}
		break;
	case 'j': // Rotacion del brazo largo del tractor
		if (interfaz.escena.tractor.seleccionado)
		{
			if (interfaz.escena.tractor.rotBrazo1 > 0)
			{
				interfaz.escena.tractor.rotBrazo1 = interfaz.escena.tractor.rotBrazo1 - 10;
			}
		}
		break;
	case 'y': // Rotacion del brazo largo del tractor
		if (interfaz.escena.tractor.seleccionado)
		{
			if (interfaz.escena.tractor.rotBrazo2 < 30)
			{
				interfaz.escena.tractor.rotBrazo2 = interfaz.escena.tractor.rotBrazo2 + 10;
			}
		}
		break;
	case 'u': // Rotacion del brazo largo del tractor
		if (interfaz.escena.tractor.seleccionado)
		{
			if (interfaz.escena.tractor.rotBrazo2 > -110)
			{
				interfaz.escena.tractor.rotBrazo2 = interfaz.escena.tractor.rotBrazo2 - 10;
			}
		}
		break;
	case 'i': // Rotacion del brazo largo del tractor
		if (interfaz.escena.tractor.seleccionado)
		{
			if (interfaz.escena.tractor.rotCazo < 30)
			{
				interfaz.escena.tractor.rotCazo = interfaz.escena.tractor.rotCazo + 10;
			}
		}
		break;
	case 'o': // Rotacion del brazo largo del tractor
		if (interfaz.escena.tractor.seleccionado)
		{
			if (interfaz.escena.tractor.rotCazo > -110)
			{
				interfaz.escena.tractor.rotCazo = interfaz.escena.tractor.rotCazo - 10;
			}
		}
		break;
	case '1': // Cambio a cámara 1º Persona
		interfaz.cam = interfaz.CP;
		break;
	case '2': // Cambio a cámara Seguridad1
		interfaz.cam = interfaz.CS1;
		break;
	case '3': // Cambio a cámara Seguridad2
		interfaz.cam = interfaz.CS2;
		break;
	case '4': // Cambio a cámara Seguridad2
		interfaz.cam = interfaz.ORB;
		break;
	case '8': // Cambio a cámara Suelo
		interfaz.cam = interfaz.CSu;
		break;
	case '9': // Cambio a cámara Techo
		interfaz.cam = interfaz.CT;
		break;
	case 'm': // Cambio a Multicámara
		interfaz.cam = interfaz.MC;
		break;
	case 'g': // Orbita IZQ

		difX = interfaz.camaraOrbita.P0.c[0] - interfaz.camaraOrbita.r.c[0];
		difY = interfaz.camaraOrbita.P0.c[1] - interfaz.camaraOrbita.r.c[1];
		difZ = interfaz.camaraOrbita.P0.c[2] - interfaz.camaraOrbita.r.c[2];

		radio = sqrt(pow(difX, 2) + pow(difY, 2) + pow(difZ, 2));

		interfaz.camaraOrbita.P0.c[0] = interfaz.camaraOrbita.r.c[0] + ((sin(interfaz.anguloORB * (M_PI / 180))) * radio);
		interfaz.camaraOrbita.P0.c[1] = interfaz.camaraOrbita.r.c[1] + 3;
		interfaz.camaraOrbita.P0.c[2] = interfaz.camaraOrbita.r.c[2] + ((cos(interfaz.anguloORB * (M_PI / 180))) * radio);

		interfaz.anguloORB = interfaz.anguloORB + 20;

		break;
	case 'f': // Orbita DER

		difX = interfaz.camaraOrbita.P0.c[0] - interfaz.camaraOrbita.r.c[0];
		difY = interfaz.camaraOrbita.P0.c[1] - interfaz.camaraOrbita.r.c[1];
		difZ = interfaz.camaraOrbita.P0.c[2] - interfaz.camaraOrbita.r.c[2];

		radio = sqrt(pow(difX, 2) + pow(difY, 2) + pow(difZ, 2));

		interfaz.camaraOrbita.P0.c[0] = interfaz.camaraOrbita.r.c[0] - ((sin(interfaz.anguloORB * (M_PI / 180))) * radio);
		interfaz.camaraOrbita.P0.c[1] = interfaz.camaraOrbita.r.c[1] + 3;
		interfaz.camaraOrbita.P0.c[2] = interfaz.camaraOrbita.r.c[2] - ((cos(interfaz.anguloORB * (M_PI / 180))) * radio);

		interfaz.anguloORB = interfaz.anguloORB - 20;


		break;
	case '+': // Aumenta el zoom de la cámara.
		interfaz.camara.zoom(1.25);
		interfaz.camara.aplicar();
		interfaz.camaraSeguridad1.zoom(1.25);
		interfaz.camaraSeguridad1.aplicar();
		interfaz.camaraSeguridad2.zoom(1.25);
		interfaz.camaraSeguridad2.aplicar();
		break;
	case '-': // Disminuye el zoom de la cámara
		interfaz.camara.zoom(-1.25);
		interfaz.camara.aplicar();
		interfaz.camaraSeguridad1.zoom(-1.25);
		interfaz.camaraSeguridad1.aplicar();
		interfaz.camaraSeguridad2.zoom(-1.25);
		interfaz.camaraSeguridad2.aplicar();
		break;
	case 'v': // Aumenta la velocidad de movimiento.
		interfaz.velocidad = interfaz.velocidad + 1;
		break;
	case 'V': // Disminuye la velocidad de movimiento.
		interfaz.velocidad = interfaz.velocidad - 1;
		break;
	case 'e': // activa/desactiva la visualizacion de los ejes
		interfaz.escena.set_ejes(interfaz.escena.get_ejes() ? false : true);
		break;
	case 27: // tecla de escape para SALIR
		exit(1);
		break;
	}
	glutPostRedisplay(); // renueva el contenido de la ventana de vision y redibuja la escena
}

void igvInterfaz::set_glutReshapeFunc(int w, int h) {
  // dimensiona el viewport al nuevo ancho y alto de la ventana
  // guardamos valores nuevos de la ventana de visualizacion
  interfaz.set_ancho_ventana(w);
  interfaz.set_alto_ventana(h);

	// establece los parámetros de la cámara y de la proyección
	interfaz.camara.aplicar();
}

void igvInterfaz::set_glutDisplayFunc() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // borra la ventana y el z-buffer

	interfaz.creacionViewports();

	// Apartado A: antes de aplicar las transformaciones de cámara y proyección hay que comprobar el modo para sólo visualizar o seleccionar:
	if (interfaz.modo == IGV_SELECCIONAR) {
		// Apartado A: Para que funcione habrá que dibujar la escena sin efectos, sin iluminación, sin texturas ...
		glDisable(GL_LIGHTING); // desactiva la iluminacion de la escena
		glDisable(GL_DITHER);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_CULL_FACE);

		// Apartado A: Reestablece los colores como no seleccionado

		if (interfaz.escena.reset)
		{
			interfaz.objeto_seleccionado = -1;
			interfaz.escena.reset = false;
		}

		if (interfaz.objeto_seleccionado != -1)
		{
			interfaz.escena.caja.seleccionado = false;
			interfaz.escena.tractor.seleccionado = false;
			interfaz.objeto_seleccionado = -1;
		}

		// BOTON CERO
		glPushMatrix();

		float* color0 = new float[4];

		color0[0] = 0.9;
		color0[1] = 0.9;
		color0[2] = 0.8;
		color0[3] = 0.0;

		glMaterialfv(GL_FRONT, GL_EMISSION, color0);
		glColor3fv(color0); //Importante, es necesario para que lo reconozca el buffer de color a la hora de la selección.

		interfaz.escena.m.b0.dibujaBotonCeroNT(4);

		glPopMatrix();

		// BOTON UNO
		glPushMatrix();

		float* color1 = new float[4];

		color1[0] = 0.9;
		color1[1] = 0.9;
		color1[2] = 0.7;
		color1[2] = 0.0;

		glMaterialfv(GL_FRONT, GL_EMISSION, color1);
		glColor3fv(color1); //Importante, es necesario para que lo reconozca el buffer de color a la hora de la selección.

		interfaz.escena.m.b1.dibujaBotonNumeroNT(4, 1);

		glPopMatrix();

		// BOTON DOS
		glPushMatrix();

		float* color2 = new float[4];

		color2[0] = 0.9;
		color2[1] = 0.9;
		color2[2] = 0.6;
		color2[3] = 0.0;

		glMaterialfv(GL_FRONT, GL_EMISSION, color2);
		glColor3fv(color2); //Importante, es necesario para que lo reconozca el buffer de color a la hora de la selección.

		interfaz.escena.m.b2.dibujaBotonNumeroNT(4, 2);

		glPopMatrix();

		// BOTON TRES
		glPushMatrix();

		float* color3 = new float[4];

		color3[0] = 0.9;
		color3[1] = 0.8;
		color3[2] = 0.9;
		color3[3] = 0.0;

		glMaterialfv(GL_FRONT, GL_EMISSION, color3);
		glColor3fv(color3); //Importante, es necesario para que lo reconozca el buffer de color a la hora de la selección.

		interfaz.escena.m.b3.dibujaBotonNumeroNT(4, 3);

		glPopMatrix();

		// BOTON CUATRO
		glPushMatrix();

		float* color4 = new float[4];

		color4[0] = 0.8;
		color4[1] = 0.9;
		color4[2] = 0.9;
		color4[3] = 0.0;

		glMaterialfv(GL_FRONT, GL_EMISSION, color4);
		glColor3fv(color4); //Importante, es necesario para que lo reconozca el buffer de color a la hora de la selección.

		interfaz.escena.m.b4.dibujaBotonNumeroNT(4, 4);

		glPopMatrix();

		// BOTON CINCO
		glPushMatrix();

		float* color5 = new float[4];

		color5[0] = 0.6;
		color5[1] = 0.6;
		color5[2] = 0.6;
		color5[3] = 0.0;

		glMaterialfv(GL_FRONT, GL_EMISSION, color5);
		glColor3fv(color5); //Importante, es necesario para que lo reconozca el buffer de color a la hora de la selección.

		interfaz.escena.m.b5.dibujaBotonNumeroNT(4, 5);

		glPopMatrix();

		// BOTON SEIS
		glPushMatrix();

		float* color6 = new float[4];

		color6[0] = 0.7;
		color6[1] = 0.7;
		color6[2] = 0.7;
		color6[3] = 0.0;

		glMaterialfv(GL_FRONT, GL_EMISSION, color6);
		glColor3fv(color6); //Importante, es necesario para que lo reconozca el buffer de color a la hora de la selección.

		interfaz.escena.m.b6.dibujaBotonNumeroNT(4, 6);

		glPopMatrix();

		// BOTON SIETE
		glPushMatrix();

		float* color7 = new float[4];

		color7[0] = 0.8;
		color7[1] = 0.8;
		color7[2] = 0.8;
		color7[3] = 0.0;

		glMaterialfv(GL_FRONT, GL_EMISSION, color7);
		glColor3fv(color7); //Importante, es necesario para que lo reconozca el buffer de color a la hora de la selección.

		interfaz.escena.m.b7.dibujaBotonNumeroNT(4, 7);

		glPopMatrix();

		// BOTON OCHO
		glPushMatrix();

		float* color8 = new float[4];

		color8[0] = 0.9;
		color8[1] = 0.9;
		color8[2] = 0.9;
		color8[3] = 0.0;

		glMaterialfv(GL_FRONT, GL_EMISSION, color8);
		glColor3fv(color8); //Importante, es necesario para que lo reconozca el buffer de color a la hora de la selección.

		interfaz.escena.m.b8.dibujaBotonNumeroNT(4, 8);

		glPopMatrix();

		// BOTON NUEVE
		glPushMatrix();

		float* color9 = new float[4];

		color9[0] = 0.8;
		color9[1] = 0.9;
		color9[2] = 0.8;
		color9[3] = 0.0;

		glMaterialfv(GL_FRONT, GL_EMISSION, color9);
		glColor3fv(color9); //Importante, es necesario para que lo reconozca el buffer de color a la hora de la selección.

		interfaz.escena.m.b9.dibujaBotonNumeroNT(4, 9);

		glPopMatrix();

		// CAJA CEREALES
		glPushMatrix();

		float* color = new float[3];

		color[0] = 0.0;
		color[1] = 0.0;
		color[2] = 1.0;

		glMaterialfv(GL_FRONT, GL_EMISSION, color);
		glColor3fv(color); //Importante, es necesario para que lo reconozca el buffer de color a la hora de la selección.

		if (interfaz.escena.caja.seleccionado)
		{
			glTranslatef(0, 35, 75);
			glRotatef(interfaz.escena.caja.rotacionY, 0, 1, 0);
			glRotatef(interfaz.escena.caja.rotacion, 1, 0, 0);
			glScalef(1.5, 1.5, 1.5);
			glTranslatef(-3, -5, -1.25);
		}
		else
		{
			glTranslatef(-7, 25, 75);
			glRotatef(interfaz.escena.caja.rotacion, 0, 1, 0);
			glTranslatef(-3, -5, -1.25);
		}

		interfaz.escena.caja.cartonCerealesNT();

		interfaz.escena.caja.color[0] = color[0];
		interfaz.escena.caja.color[1] = color[1];
		interfaz.escena.caja.color[2] = color[2];

		color[0] = 0.0;
		color[1] = 0.0;
		color[2] = 0.0;
		glMaterialfv(GL_FRONT, GL_EMISSION, color);

		glPopMatrix();

		// TRACTOR
		glPushMatrix();

		float* colorT = new float[3];

		colorT[0] = 0.0;
		colorT[1] = 1.0;
		colorT[2] = 0.0;

		glMaterialfv(GL_FRONT, GL_EMISSION, colorT);
		glColor3fv(colorT); //Importante, es necesario para que lo reconozca el buffer de color a la hora de la selección.

		glTranslatef(10, 23, 75);
		interfaz.escena.tractor.dibujaTractorNT(0.25);

		interfaz.escena.tractor.color[0] = colorT[0];
		interfaz.escena.tractor.color[1] = colorT[1];
		interfaz.escena.tractor.color[2] = colorT[2];

		colorT[0] = 0.0;
		colorT[1] = 0.0;
		colorT[2] = 0.0;
		glMaterialfv(GL_FRONT, GL_DIFFUSE, colorT);

		glPopMatrix();

		// Apartado A: Obtener el color del pixel seleccionado

		GLubyte pixel[3];

		glReadPixels(interfaz.cursorX, interfaz.alto_ventana - interfaz.cursorY, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &pixel);

		GLubyte pixelT[3];

		glReadPixels(interfaz.cursorX, interfaz.alto_ventana - interfaz.cursorY, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &pixelT);

		GLubyte pixelnum[4];

		glReadPixels(interfaz.cursorX, interfaz.alto_ventana - interfaz.cursorY, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &pixelnum);

		cout << "El color del pixel BOTON NUMERICO es: " << (GLfloat)pixelnum[0] << ", " << (GLfloat)pixelnum[1] << ", " << (GLfloat)pixelnum[2] << ".";
		cout << "El color del pixelT es: " << (GLfloat)pixelT[0] << ", " << (GLfloat)pixelT[1] << ", " << (GLfloat)pixelT[2] << ".";
		cout << "El color del pixel GUARDADO es: " << (GLfloat)interfaz.escena.caja.getColorByte()[0] << ", " << (GLfloat)interfaz.escena.caja.getColorByte()[1] << ", " << (GLfloat)interfaz.escena.caja.getColorByte()[2] << ".";
		cout << "El color del pixel TRACTOR GUARDADO es: " << (GLfloat)interfaz.escena.tractor.getColorByte()[0] << ", " << (GLfloat)interfaz.escena.tractor.getColorByte()[1] << ", " << (GLfloat)interfaz.escena.tractor.getColorByte()[2] << ".";
		cout << "El color del pixel CERO GUARDADO es: " << (GLfloat)interfaz.escena.m.b0.color[0] << ", " << (GLfloat)interfaz.escena.m.b0.color[1] << ", " << (GLfloat)interfaz.escena.m.b0.color[2] << ".";
		cout << "El color del pixel UNO GUARDADO es: " << (GLfloat)interfaz.escena.m.b1.color[0] << ", " << (GLfloat)interfaz.escena.m.b1.color[1] << ", " << (GLfloat)interfaz.escena.m.b1.color[2] << ".";
		// Apartado A: Comprobar el color del objeto que hay en el cursor mirando en la tabla de colores y asigna otro color al objeto seleccionado

		if (interfaz.escena.caja.getColorByte()[0] == pixel[0] &&
			interfaz.escena.caja.getColorByte()[1] == pixel[1] &&
			interfaz.escena.caja.getColorByte()[2] == pixel[2])
		{
			interfaz.escena.caja.seleccionado = true;
			interfaz.objeto_seleccionado = 1;
		}

		if (interfaz.escena.tractor.getColorByte()[0] == pixelT[0] &&
			interfaz.escena.tractor.getColorByte()[1] == pixelT[1] &&
			interfaz.escena.tractor.getColorByte()[2] == pixelT[2])
		{
			interfaz.escena.tractor.seleccionado = true;
			interfaz.objeto_seleccionado = 2;
		}

		if (interfaz.escena.m.b0.getColorByte()[0] == pixelnum[0] &&
			interfaz.escena.m.b0.getColorByte()[1] == pixelnum[1] &&
			interfaz.escena.m.b0.getColorByte()[2] == pixelnum[2])
		{
			interfaz.escena.m.b0.seleccionado = true;
			interfaz.objeto_seleccionado = 3;
			cout << "CARACTER INTRODUCIDO -> CERO\n";

			if (interfaz.codigo.size() < 4)
			{
				interfaz.codigo.push_back(0);
			}
			else
			{
				interfaz.codigo.clear();
				interfaz.codigo.push_back(0);
			}
		}

		if (interfaz.escena.m.b1.getColorByte()[0] == pixelnum[0] &&
			interfaz.escena.m.b1.getColorByte()[1] == pixelnum[1] &&
			interfaz.escena.m.b1.getColorByte()[2] == pixelnum[2] )
		{
			interfaz.escena.m.b1.seleccionado = true;
			interfaz.objeto_seleccionado = 4;
			cout << "CARACTER INTRODUCIDO -> UNO\n";

			if (interfaz.codigo.size() < 4)
			{
				interfaz.codigo.push_back(1);
			}
			else
			{
				interfaz.codigo.clear();
				interfaz.codigo.push_back(1);
			}
		}

		if (interfaz.escena.m.b2.getColorByte()[0] == pixelnum[0] &&
			interfaz.escena.m.b2.getColorByte()[1] == pixelnum[1] &&
			interfaz.escena.m.b2.getColorByte()[2] == pixelnum[2])
		{
			interfaz.escena.m.b2.seleccionado = true;
			interfaz.objeto_seleccionado = 5;
			cout << "CARACTER INTRODUCIDO -> DOS\n";

			if (interfaz.codigo.size() < 4)
			{
				interfaz.codigo.push_back(2);
			}
			else
			{
				interfaz.codigo.clear();
				interfaz.codigo.push_back(2);
			}
		}

		if (interfaz.escena.m.b3.getColorByte()[0] == pixelnum[0] &&
			interfaz.escena.m.b3.getColorByte()[1] == pixelnum[1] &&
			interfaz.escena.m.b3.getColorByte()[2] == pixelnum[2])
		{
			interfaz.escena.m.b3.seleccionado = true;
			interfaz.objeto_seleccionado = 6;
			cout << "CARACTER INTRODUCIDO -> TRES\n";

			if (interfaz.codigo.size() < 4)
			{
				interfaz.codigo.push_back(3);
			}
			else
			{
				interfaz.codigo.clear();
				interfaz.codigo.push_back(3);
			}
		}

		if (interfaz.escena.m.b4.getColorByte()[0] == pixelnum[0] &&
			interfaz.escena.m.b4.getColorByte()[1] == pixelnum[1] &&
			interfaz.escena.m.b4.getColorByte()[2] == pixelnum[2])
		{
			interfaz.escena.m.b4.seleccionado = true;
			interfaz.objeto_seleccionado = 7;
			cout << "CARACTER INTRODUCIDO -> CUATRO\n";

			if (interfaz.codigo.size() < 4)
			{
				interfaz.codigo.push_back(4);
			}
			else
			{
				interfaz.codigo.clear();
				interfaz.codigo.push_back(4);
			}
		}

		if (interfaz.escena.m.b5.getColorByte()[0] == pixelnum[0] &&
			interfaz.escena.m.b5.getColorByte()[1] == pixelnum[1] &&
			interfaz.escena.m.b5.getColorByte()[2] == pixelnum[2] )
		{
			interfaz.escena.m.b5.seleccionado = true;
			interfaz.objeto_seleccionado = 8;
			cout << "CARACTER INTRODUCIDO -> CINCO\n";

			if (interfaz.codigo.size() < 4)
			{
				interfaz.codigo.push_back(5);
			}
			else
			{
				interfaz.codigo.clear();
				interfaz.codigo.push_back(5);
			}
		}

		if (interfaz.escena.m.b6.getColorByte()[0] == pixelnum[0] &&
			interfaz.escena.m.b6.getColorByte()[1] == pixelnum[1] &&
			interfaz.escena.m.b6.getColorByte()[2] == pixelnum[2])
		{
			interfaz.escena.m.b6.seleccionado = true;
			interfaz.objeto_seleccionado = 9;
			cout << "CARACTER INTRODUCIDO -> SEIS\n";

			if (interfaz.codigo.size() < 4)
			{
				interfaz.codigo.push_back(6);
			}
			else
			{
				interfaz.codigo.clear();
				interfaz.codigo.push_back(6);
			}
		}

		if (interfaz.escena.m.b7.getColorByte()[0] == pixelnum[0] &&
			interfaz.escena.m.b7.getColorByte()[1] == pixelnum[1] &&
			interfaz.escena.m.b7.getColorByte()[2] == pixelnum[2])
		{
			interfaz.escena.m.b7.seleccionado = true;
			interfaz.objeto_seleccionado = 9;
			cout << "CARACTER INTRODUCIDO -> SIETE\n";

			if (interfaz.codigo.size() < 4)
			{
				interfaz.codigo.push_back(7);
			}
			else
			{
				interfaz.codigo.clear();
				interfaz.codigo.push_back(7);
			}
		}

		if (interfaz.escena.m.b8.getColorByte()[0] == pixelnum[0] &&
			interfaz.escena.m.b8.getColorByte()[1] == pixelnum[1] &&
			interfaz.escena.m.b8.getColorByte()[2] == pixelnum[2] )
		{
			interfaz.escena.m.b8.seleccionado = true;
			interfaz.objeto_seleccionado = 10;
			cout << "CARACTER INTRODUCIDO -> OCHO\n";

			if (interfaz.codigo.size() < 4)
			{
				interfaz.codigo.push_back(8);
			}
			else
			{
				interfaz.codigo.clear();
				interfaz.codigo.push_back(8);
			}
		}

		if (interfaz.escena.m.b9.getColorByte()[0] == pixelnum[0] &&
			interfaz.escena.m.b9.getColorByte()[1] == pixelnum[1] &&
			interfaz.escena.m.b9.getColorByte()[2] == pixelnum[2])
		{
			interfaz.escena.m.b9.seleccionado = true;
			interfaz.objeto_seleccionado = 11;
			cout << "CARACTER INTRODUCIDO -> NUEVE\n";

			if (interfaz.codigo.size() < 4)
			{
				interfaz.codigo.push_back(9);
			}
			else
			{
				interfaz.codigo.clear();
				interfaz.codigo.push_back(9);
			}
		}

		std::list<int>::iterator it = interfaz.codigo.begin();

		int i = 0;
		while (it != interfaz.codigo.end())
		{
			if (interfaz.codCorrecto[i] != *it)
			{
				interfaz.ACCEPTED = false;
			}

			std::cout << *it << ", ";
			it++;
			i++;
		}

		i = 0;

		if (interfaz.ACCEPTED && interfaz.codigo.size() == 4)
		{
			interfaz.escena.m.ABREPUERTA = true;
		}

		interfaz.ACCEPTED = true;

		// Apartado A: Cambiar a modo de visualización de la escena

		interfaz.modo = IGV_VISUALIZAR;

		// Apartado A: Habilitar de nuevo la iluminación
		glEnable(GL_LIGHTING);
	}
	else {
		// aplica las transformaciones en función de los parámetros de la cámara

		if (interfaz.cam == interfaz.CP)
		{
			interfaz.camara.aplicar();
		}

		if (interfaz.cam == interfaz.CS1)
		{
			interfaz.camaraSeguridad1.aplicar();
		}

		if (interfaz.cam == interfaz.CT)
		{
			interfaz.camaraTecho.aplicar();
		}

		if (interfaz.cam == interfaz.CSu)
		{
			interfaz.camaraSuelo.aplicar();
		}

		if (interfaz.cam == interfaz.CS2)
		{
			interfaz.camaraSeguridad2.aplicar();
		}

		if (interfaz.cam == interfaz.MC)
		{
			interfaz.camaraSeguridad1.aplicar();
			interfaz.camaraSeguridad2.aplicar();
			interfaz.camaraTecho.aplicar();
			interfaz.camaraSuelo.aplicar();
		}

		// visualiza la escena
		interfaz.escena.visualizar();

		// refresca la ventana
		glutSwapBuffers();
	}
}

void igvInterfaz::inicializa_callbacks() {
	glutKeyboardFunc(set_glutKeyboardFunc);
	glutReshapeFunc(set_glutReshapeFunc);
	glutDisplayFunc(set_glutDisplayFunc);
	glutSpecialFunc(set_glutSpecialFunc);

	glutMouseFunc(set_glutMouseFunc);
	glutMotionFunc(set_glutMotionFunc);
	glutIdleFunc(set_glutIdleFunc);
}

void igvInterfaz::movimientoDerecha()
{
	double xN;
	double yN;
	double zN;

	double xrefN;
	double yrefN;
	double zrefN;

	igvPunto3D nuevoPunto(0, 0, 0);
	igvPunto3D nuevoPuntoRef(0, 0, 0);

	xN = interfaz.p0.c[0];
	yN = interfaz.p0.c[1];
	zN = interfaz.p0.c[2];

	xrefN = interfaz.r.c[0];
	yrefN = interfaz.r.c[1];
	zrefN = interfaz.r.c[2];

	if (interfaz.angulo == 0 || interfaz.angulo == 360)
	{
		xN = interfaz.p0.c[0] - interfaz.velocidad;
		yN = interfaz.p0.c[1];
		zN = interfaz.p0.c[2];

		xrefN = interfaz.r.c[0] - interfaz.velocidad;
		yrefN = interfaz.r.c[1];
		zrefN = interfaz.r.c[2];
	}

	if (interfaz.angulo > 270 && interfaz.angulo < 360 || interfaz.angulo < 0 && interfaz.angulo > -90)
	{
		xN = xN - 1;
		yN = interfaz.p0.c[1];
		zN = zN - 1;

		xrefN = xrefN - 1;
		yrefN = interfaz.r.c[1];
		zrefN = zrefN - 1;
	}

	if (interfaz.angulo == -90 || interfaz.angulo == 270)
	{
		xN = interfaz.p0.c[0];
		yN = interfaz.p0.c[1];
		zN = interfaz.p0.c[2] - interfaz.velocidad;

		xrefN = interfaz.r.c[0];
		yrefN = interfaz.r.c[1];
		zrefN = interfaz.r.c[2] - interfaz.velocidad;
	}

	if (interfaz.angulo > 180 && interfaz.angulo < 270 || interfaz.angulo < -90 && interfaz.angulo > -180)
	{
		xN = xN + 1;
		yN = interfaz.p0.c[1];
		zN = zN - 1;

		xrefN = xrefN + 1;
		yrefN = interfaz.r.c[1];
		zrefN = zrefN - 1;
	}

	if (interfaz.angulo == -180 || interfaz.angulo == 180)
	{
		xN = interfaz.p0.c[0] + interfaz.velocidad;
		yN = interfaz.p0.c[1];
		zN = interfaz.p0.c[2];

		xrefN = interfaz.r.c[0] + interfaz.velocidad;
		yrefN = interfaz.r.c[1];
		zrefN = interfaz.r.c[2];
	}

	if (interfaz.angulo > 90 && interfaz.angulo < 180 || interfaz.angulo < -180 && interfaz.angulo > -270)
	{
		xN = xN + 1;
		yN = interfaz.p0.c[1];
		zN = zN + 1;

		xrefN = xrefN + 1;
		yrefN = interfaz.r.c[1];
		zrefN = zrefN + 1;
	}

	if (interfaz.angulo == -270 || interfaz.angulo == 90)
	{
		xN = interfaz.p0.c[0];
		yN = interfaz.p0.c[1];
		zN = interfaz.p0.c[2] + interfaz.velocidad;

		xrefN = interfaz.r.c[0];
		yrefN = interfaz.r.c[1];
		zrefN = interfaz.r.c[2] + interfaz.velocidad;
	}

	if (interfaz.angulo > 0 && interfaz.angulo < 90 || interfaz.angulo < -270 && interfaz.angulo > -360)
	{
		xN = xN - 1;
		yN = interfaz.p0.c[1];
		zN = zN + 1;

		xrefN = xrefN - 1;
		yrefN = interfaz.r.c[1];
		zrefN = zrefN + 1;
	}

	if ((xN < XMAXIMA - interfaz.velocidad && xN > XMINIMA + interfaz.velocidad) &&
		(zN < ZMAXIMA - interfaz.velocidad && zN > ZMINIMA + interfaz.velocidad))
	{
		nuevoPunto.c[0] = xN;
		nuevoPunto.c[1] = yN;
		nuevoPunto.c[2] = zN;

		nuevoPuntoRef.c[0] = xrefN;
		nuevoPuntoRef.c[1] = yrefN;
		nuevoPuntoRef.c[2] = zrefN;

		interfaz.p0 = nuevoPunto;
		interfaz.r = nuevoPuntoRef;

		interfaz.camara.P0 = nuevoPunto;
		interfaz.camara.r = nuevoPuntoRef;

		interfaz.camara.aplicar();
	}
}
void igvInterfaz::movimientoIzquierda()
{
	double xN;
	double yN;
	double zN;

	double xrefN;
	double yrefN;
	double zrefN;

	igvPunto3D nuevoPunto(0, 0, 0);
	igvPunto3D nuevoPuntoRef(0, 0, 0);

	xN = interfaz.p0.c[0];
	yN = interfaz.p0.c[1];
	zN = interfaz.p0.c[2];

	xrefN = interfaz.r.c[0];
	yrefN = interfaz.r.c[1];
	zrefN = interfaz.r.c[2];

	if (interfaz.angulo == 0 || interfaz.angulo == 360)
	{
		xN = interfaz.p0.c[0] + interfaz.velocidad;
		yN = interfaz.p0.c[1];
		zN = interfaz.p0.c[2];

		xrefN = interfaz.r.c[0] + interfaz.velocidad;
		yrefN = interfaz.r.c[1];
		zrefN = interfaz.r.c[2];
	}

	if (interfaz.angulo > 270 && interfaz.angulo < 360 || interfaz.angulo < 0 && interfaz.angulo > -90)
	{
		xN = xN + 1;
		yN = interfaz.p0.c[1];
		zN = zN + 1;

		xrefN = xrefN + 1;
		yrefN = interfaz.r.c[1];
		zrefN = zrefN + 1;
	}

	if (interfaz.angulo == -90 || interfaz.angulo == 270)
	{
		xN = interfaz.p0.c[0];
		yN = interfaz.p0.c[1];
		zN = interfaz.p0.c[2] + interfaz.velocidad;

		xrefN = interfaz.r.c[0];
		yrefN = interfaz.r.c[1];
		zrefN = interfaz.r.c[2] + interfaz.velocidad;
	}

	if (interfaz.angulo > 180 && interfaz.angulo < 270 || interfaz.angulo < -90 && interfaz.angulo > -180)
	{
		xN = xN - 1;
		yN = interfaz.p0.c[1];
		zN = zN + 1;

		xrefN = xrefN - 1;
		yrefN = interfaz.r.c[1];
		zrefN = zrefN + 1;
	}

	if (interfaz.angulo == -180 || interfaz.angulo == 180)
	{
		xN = interfaz.p0.c[0] - interfaz.velocidad;
		yN = interfaz.p0.c[1];
		zN = interfaz.p0.c[2];

		xrefN = interfaz.r.c[0] - interfaz.velocidad;
		yrefN = interfaz.r.c[1];
		zrefN = interfaz.r.c[2];
	}

	if (interfaz.angulo > 90 && interfaz.angulo < 180 || interfaz.angulo < -180 && interfaz.angulo > -270)
	{
		xN = xN - 1;
		yN = interfaz.p0.c[1];
		zN = zN - 1;

		xrefN = xrefN - 1;
		yrefN = interfaz.r.c[1];
		zrefN = zrefN - 1;
	}

	if (interfaz.angulo == -270 || interfaz.angulo == 90)
	{
		xN = interfaz.p0.c[0];
		yN = interfaz.p0.c[1];
		zN = interfaz.p0.c[2] - interfaz.velocidad;

		xrefN = interfaz.r.c[0];
		yrefN = interfaz.r.c[1];
		zrefN = interfaz.r.c[2] - interfaz.velocidad;
	}

	if (interfaz.angulo > 0 && interfaz.angulo < 90 || interfaz.angulo < -270 && interfaz.angulo > -360)
	{
		xN = xN + 1;
		yN = interfaz.p0.c[1];
		zN = zN - 1;

		xrefN = xrefN + 1;
		yrefN = interfaz.r.c[1];
		zrefN = zrefN - 1;
	}

	if ((xN < XMAXIMA - interfaz.velocidad && xN > XMINIMA + interfaz.velocidad) &&
		(zN < ZMAXIMA - interfaz.velocidad && zN > ZMINIMA + interfaz.velocidad))
	{

		nuevoPunto.c[0] = xN;
		nuevoPunto.c[1] = yN;
		nuevoPunto.c[2] = zN;

		nuevoPuntoRef.c[0] = xrefN;
		nuevoPuntoRef.c[1] = yrefN;
		nuevoPuntoRef.c[2] = zrefN;


		interfaz.p0 = nuevoPunto;
		interfaz.r = nuevoPuntoRef;

		interfaz.camara.P0 = nuevoPunto;
		interfaz.camara.r = nuevoPuntoRef;

		interfaz.camara.aplicar();
	}
}
void igvInterfaz::movimientoAdelante()
{
	double xN;
	double yN;
	double zN;

	double xrefN;
	double yrefN;
	double zrefN;

	igvPunto3D nuevoPunto(0, 0, 0);
	igvPunto3D nuevoPuntoRef(0, 0, 0);

	xN = interfaz.p0.c[0];
	yN = interfaz.p0.c[1];
	zN = interfaz.p0.c[2];

	xrefN = interfaz.r.c[0];
	yrefN = interfaz.r.c[1];
	zrefN = interfaz.r.c[2];

	xN = xN + (sin(interfaz.angulo * (M_PI / 180))) * interfaz.velocidad;
	zN = zN + (cos(interfaz.angulo * (M_PI / 180))) * interfaz.velocidad;

	xrefN = xrefN + (sin(interfaz.angulo * (M_PI / 180))) * interfaz.velocidad;
	zrefN = zrefN + (cos(interfaz.angulo * (M_PI / 180))) * interfaz.velocidad;

	if ( (xN < XMAXIMA - interfaz.velocidad && xN > XMINIMA + interfaz.velocidad) &&
		 (zN < ZMAXIMA - interfaz.velocidad && zN > ZMINIMA + interfaz.velocidad) )
	{
		nuevoPunto.c[0] = xN;
		nuevoPunto.c[1] = yN;
		nuevoPunto.c[2] = zN;

		nuevoPuntoRef.c[0] = xrefN;
		nuevoPuntoRef.c[1] = yrefN;
		nuevoPuntoRef.c[2] = zrefN;

		interfaz.p0 = nuevoPunto;
		interfaz.r = nuevoPuntoRef;

		interfaz.camara.P0 = nuevoPunto;
		interfaz.camara.r = nuevoPuntoRef;

		interfaz.camara.aplicar();
	}
}
void igvInterfaz::movimientoAtras()
{
	double xN;
	double yN;
	double zN;

	double xrefN;
	double yrefN;
	double zrefN;

	igvPunto3D nuevoPunto(0, 0, 0);
	igvPunto3D nuevoPuntoRef(0, 0, 0);

	xN = interfaz.p0.c[0];
	yN = interfaz.p0.c[1];
	zN = interfaz.p0.c[2];

	xrefN = interfaz.r.c[0];
	yrefN = interfaz.r.c[1];
	zrefN = interfaz.r.c[2];

	xN = xN - (sin(interfaz.angulo * (M_PI / 180))) * interfaz.velocidad;
	zN = zN - (cos(interfaz.angulo * (M_PI / 180))) * interfaz.velocidad;

	xrefN = xrefN - (sin(interfaz.angulo * (M_PI / 180))) * interfaz.velocidad;
	zrefN = zrefN - (cos(interfaz.angulo * (M_PI / 180))) * interfaz.velocidad;

	if ((xN < XMAXIMA - interfaz.velocidad && xN > XMINIMA + interfaz.velocidad) &&
		(zN < ZMAXIMA - interfaz.velocidad && zN > ZMINIMA + interfaz.velocidad))
	{
		nuevoPunto.c[0] = xN;
		nuevoPunto.c[1] = yN;
		nuevoPunto.c[2] = zN;

		nuevoPuntoRef.c[0] = xrefN;
		nuevoPuntoRef.c[1] = yrefN;
		nuevoPuntoRef.c[2] = zrefN;

		interfaz.p0 = nuevoPunto;
		interfaz.r = nuevoPuntoRef;

		interfaz.camara.P0 = nuevoPunto;
		interfaz.camara.r = nuevoPuntoRef;

		interfaz.camara.aplicar();
	}
}

void igvInterfaz::rotacionIzquierda()
{
	double xN;
	double yN;
	double zN;

	double xrefN;
	double yrefN;
	double zrefN;

	igvPunto3D nuevoPunto(0, 0, 0);
	igvPunto3D nuevoPuntoRef(0, 0, 0);

	double xTot;
	double yTot;
	double zTot;

	double radio;
	double alfa;

	double xx;
	double yy;
	double zz;

	xN = interfaz.p0.c[0]; // Guarda el punto de visión actual
	yN = interfaz.p0.c[1];
	zN = interfaz.p0.c[2];

	xrefN = interfaz.r.c[0]; // Guarda el punto de referencia actual
	yrefN = interfaz.r.c[1];
	zrefN = interfaz.r.c[2];

	xTot = xrefN - xN; // Vector entre el punto de visión actual y el de referencia actual
	yTot = yrefN - yN;
	zTot = zrefN - zN;

	alfa = 15; // Grado de giro

	if (interfaz.angulo < 0) // transformacion de angulo
	{
		int partes = 360 / alfa;
		int corte = -1 * (interfaz.angulo / alfa);

		interfaz.angulo = ((partes - corte) * alfa); // Si el angulo viene positivo, invierte el angulo a negativo
	}

	radio = sqrt(pow(xTot, 2) + pow(yTot, 2) + pow(zTot, 2));

	interfaz.angulo = interfaz.angulo + alfa;

	if (interfaz.angulo == 360 || interfaz.angulo == -360)
	{
		interfaz.angulo = 0;
	}

	if ((interfaz.angulo >= 0 && interfaz.angulo < 45) || (interfaz.angulo >= 315 && interfaz.angulo < 359))
	{
		interfaz.NORTE = true;
		interfaz.SUR = false;
		interfaz.ESTE = false;
		interfaz.OESTE = false;
	}
	else if ((interfaz.angulo >= 45 && interfaz.angulo < 135))
	{
		interfaz.NORTE = false;
		interfaz.SUR = false;
		interfaz.ESTE = false;
		interfaz.OESTE = true;
	}
	else if ((interfaz.angulo >= 135 && interfaz.angulo < 225))
	{
		interfaz.NORTE = false;
		interfaz.SUR = true;
		interfaz.ESTE = false;
		interfaz.OESTE = false;
	}
	else if ((interfaz.angulo >= 225 && interfaz.angulo < 315))
	{
		interfaz.NORTE = false;
		interfaz.SUR = false;
		interfaz.ESTE = true;
		interfaz.OESTE = false;
	}

	xx = (sin(interfaz.angulo * (M_PI / 180)) * radio);
	zz = (cos(interfaz.angulo * (M_PI / 180)) * radio);

	xrefN = xx;
	zrefN = zz;

	cout << xrefN << "\n";
	cout << yrefN << "\n";
	cout << zrefN << "\n";

	if (interfaz.NORTE)
	{
		cout << "NORTE";
	}

	if (interfaz.SUR)
	{
		cout << "SUR";
	}

	if (interfaz.ESTE)
	{
		cout << "ESTE";
	}

	if (interfaz.OESTE)
	{
		cout << "OESTE";
	}

	nuevoPuntoRef.c[0] = xrefN + xN;
	nuevoPuntoRef.c[1] = yrefN;
	nuevoPuntoRef.c[2] = zrefN + zN;

	interfaz.r = nuevoPuntoRef;
	interfaz.camara.r = nuevoPuntoRef;

	interfaz.camara.aplicar();
}
void igvInterfaz::rotacionDerecha()
{
	double xN;
	double yN;
	double zN;

	double xrefN;
	double yrefN;
	double zrefN;

	igvPunto3D nuevoPunto(0, 0, 0);
	igvPunto3D nuevoPuntoRef(0, 0, 0);

	double xTot;
	double yTot;
	double zTot;

	double radio;
	double alfa;

	double xx;
	double yy;
	double zz;

	xN = interfaz.p0.c[0];
	yN = interfaz.p0.c[1];
	zN = interfaz.p0.c[2];

	xrefN = interfaz.r.c[0];
	yrefN = interfaz.r.c[1];
	zrefN = interfaz.r.c[2];

	xTot = xrefN - xN;
	yTot = yrefN - yN;
	zTot = zrefN - zN;

	alfa = 15;

	if (interfaz.angulo > 0) // transformacion de angulo
	{
		int partes = 360 / alfa;
		int corte = interfaz.angulo / alfa;

		interfaz.angulo = -1 * ((partes - corte) * alfa); // Si el angulo viene positivo, invierte el angulo a negativo
	}

	radio = sqrt(pow(xTot, 2) + pow(yTot, 2) + pow(zTot, 2));

	interfaz.angulo = interfaz.angulo - alfa;

	if (interfaz.angulo == 360 || interfaz.angulo == -360)
	{
		interfaz.angulo = 0;
	}

	if ((interfaz.angulo <= 0 && interfaz.angulo > -45) || (interfaz.angulo > -359 && interfaz.angulo < -315))
	{
		interfaz.NORTE = true;
		interfaz.SUR = false;
		interfaz.ESTE = false;
		interfaz.OESTE = false;
	}
	else if ((interfaz.angulo <= -45 && interfaz.angulo > -135))
	{
		interfaz.NORTE = false;
		interfaz.SUR = false;
		interfaz.ESTE = true;
		interfaz.OESTE = false;
	}
	else if ((interfaz.angulo <= -135 && interfaz.angulo > -225))
	{
		interfaz.NORTE = false;
		interfaz.SUR = true;
		interfaz.ESTE = false;
		interfaz.OESTE = false;
	}
	else if ((interfaz.angulo <= -225 && interfaz.angulo > -315))
	{
		interfaz.NORTE = false;
		interfaz.SUR = false;
		interfaz.ESTE = false;
		interfaz.OESTE = true;
	}

	xx = (sin(interfaz.angulo * (M_PI / 180)) * radio);
	zz = (cos(interfaz.angulo * (M_PI / 180)) * radio);

	xrefN = xx;
	zrefN = zz;

	cout << xrefN << "\n";
	cout << yrefN << "\n";
	cout << zrefN << "\n";

	if (interfaz.NORTE)
	{
		cout << "NORTE";
	}

	if (interfaz.SUR)
	{
		cout << "SUR";
	}

	if (interfaz.ESTE)
	{
		cout << "ESTE";
	}

	if (interfaz.OESTE)
	{
		cout << "OESTE";
	}

	nuevoPuntoRef.c[0] = xrefN + xN;
	nuevoPuntoRef.c[1] = yrefN;
	nuevoPuntoRef.c[2] = zrefN + zN;

	interfaz.r = nuevoPuntoRef;
	interfaz.camara.r = nuevoPuntoRef;

	interfaz.camara.aplicar();
}

void igvInterfaz::mirarArriba()
{
	double xN;
	double yN;
	double zN;

	double xrefN;
	double yrefN;
	double zrefN;

	igvPunto3D nuevoPunto(0, 0, 0);
	igvPunto3D nuevoPuntoRef(0, 0, 0);

	xN = interfaz.p0.c[0]; // Guarda el punto de visión actual
	yN = interfaz.p0.c[1];
	zN = interfaz.p0.c[2];

	xrefN = interfaz.r.c[0]; // Guarda el punto de referencia actual
	yrefN = interfaz.r.c[1];
	zrefN = interfaz.r.c[2];

	if (yrefN < 80)
	{
		yrefN = yrefN + 10;
	}

	nuevoPuntoRef.c[0] = xrefN;
	nuevoPuntoRef.c[1] = yrefN;
	nuevoPuntoRef.c[2] = zrefN;

	interfaz.r = nuevoPuntoRef;
	interfaz.camara.r = nuevoPuntoRef;

	interfaz.camara.aplicar();
}
void igvInterfaz::mirarAbajo()
{
	double xN;
	double yN;
	double zN;

	double xrefN;
	double yrefN;
	double zrefN;

	igvPunto3D nuevoPunto(0, 0, 0);
	igvPunto3D nuevoPuntoRef(0, 0, 0);

	xN = interfaz.p0.c[0]; // Guarda el punto de visión actual
	yN = interfaz.p0.c[1];
	zN = interfaz.p0.c[2];

	xrefN = interfaz.r.c[0]; // Guarda el punto de referencia actual
	yrefN = interfaz.r.c[1];
	zrefN = interfaz.r.c[2];

	if (yrefN > -80)
	{
		yrefN = yrefN - 10;
	}

	nuevoPuntoRef.c[0] = xrefN;
	nuevoPuntoRef.c[1] = yrefN;
	nuevoPuntoRef.c[2] = zrefN;

	interfaz.r = nuevoPuntoRef;
	interfaz.camara.r = nuevoPuntoRef;

	interfaz.camara.aplicar();
}

void igvInterfaz::rotacionIzquierdaCS1()
{
	double xN;
	double yN;
	double zN;

	double xrefN;
	double yrefN;
	double zrefN;

	igvPunto3D nuevoPuntoRef(0, 0, 0);

	xN = interfaz.p1.c[0]; // Guarda el punto de visión actual
	yN = interfaz.p1.c[1];
	zN = interfaz.p1.c[2];

	xrefN = interfaz.r1.c[0]; // Guarda el punto de referencia actual
	yrefN = interfaz.r1.c[1];
	zrefN = interfaz.r1.c[2];

	if (zrefN > 20)
	{
		nuevoPuntoRef.c[0] = xrefN + 1.5;
		nuevoPuntoRef.c[1] = yrefN;
		nuevoPuntoRef.c[2] = zrefN - 1.5;

		igvPunto3D ref = igvPunto3D(nuevoPuntoRef.c[0], nuevoPuntoRef.c[1], nuevoPuntoRef.c[2]);

		interfaz.r1 = ref;
		interfaz.camaraSeguridad1.r = ref;

		interfaz.camaraSeguridad1.aplicar();
	}
}
void igvInterfaz::rotacionDerechaCS1()
{
	double xN;
	double yN;
	double zN;

	double xrefN;
	double yrefN;
	double zrefN;

	igvPunto3D nuevoPuntoRef(0, 0, 0);

	xN = interfaz.p1.c[0]; // Guarda el punto de visión actual
	yN = interfaz.p1.c[1];
	zN = interfaz.p1.c[2];

	xrefN = interfaz.r1.c[0]; // Guarda el punto de referencia actual
	yrefN = interfaz.r1.c[1];
	zrefN = interfaz.r1.c[2];

	if (zrefN < 60)
	{
		nuevoPuntoRef.c[0] = xrefN - 1.5;
		nuevoPuntoRef.c[1] = yrefN;
		nuevoPuntoRef.c[2] = zrefN + 1.5;

		igvPunto3D ref = igvPunto3D(nuevoPuntoRef.c[0], nuevoPuntoRef.c[1], nuevoPuntoRef.c[2]);

		interfaz.r1 = ref;
		interfaz.camaraSeguridad1.r = ref;

		interfaz.camaraSeguridad1.aplicar();
	}
}

void igvInterfaz::rotacionIzquierdaCS2()
{
	double xN;
	double yN;
	double zN;

	double xrefN;
	double yrefN;
	double zrefN;

	igvPunto3D nuevoPuntoRef(0, 0, 0);

	xN = interfaz.p5.c[0]; // Guarda el punto de visión actual
	yN = interfaz.p5.c[1];
	zN = interfaz.p5.c[2];

	xrefN = interfaz.r5.c[0]; // Guarda el punto de referencia actual
	yrefN = interfaz.r5.c[1];
	zrefN = interfaz.r5.c[2];

	if (zrefN < 60)
	{
		nuevoPuntoRef.c[0] = xrefN - 1.5;
		nuevoPuntoRef.c[1] = yrefN;
		nuevoPuntoRef.c[2] = zrefN + 1.5;

		igvPunto3D ref = igvPunto3D(nuevoPuntoRef.c[0], nuevoPuntoRef.c[1], nuevoPuntoRef.c[2]);

		interfaz.r5 = ref;
		interfaz.camaraSeguridad2.r = ref;

		interfaz.camaraSeguridad2.aplicar();
	}
}
void igvInterfaz::rotacionDerechaCS2()
{
	double xN;
	double yN;
	double zN;

	double xrefN;
	double yrefN;
	double zrefN;

	igvPunto3D nuevoPuntoRef(0, 0, 0);

	xN = interfaz.p5.c[0]; // Guarda el punto de visión actual
	yN = interfaz.p5.c[1];
	zN = interfaz.p5.c[2];

	xrefN = interfaz.r5.c[0]; // Guarda el punto de referencia actual
	yrefN = interfaz.r5.c[1];
	zrefN = interfaz.r5.c[2];

	if (zrefN > 28)
	{
		nuevoPuntoRef.c[0] = xrefN + 1.5;
		nuevoPuntoRef.c[1] = yrefN;
		nuevoPuntoRef.c[2] = zrefN - 1.5;

		igvPunto3D ref = igvPunto3D(nuevoPuntoRef.c[0], nuevoPuntoRef.c[1], nuevoPuntoRef.c[2]);

		interfaz.r5 = ref;
		interfaz.camaraSeguridad2.r = ref;

		interfaz.camaraSeguridad2.aplicar();
	}
}

void igvInterfaz::creacionCamaras()
{
	// CAMARA 1º PERSONA
	p0 = igvPunto3D(0, 33, 0);
	r = igvPunto3D(0, 0, 220);
	V = igvPunto3D(0, 1, 0);

	interfaz.camara.set(IGV_PERSPECTIVA, p0, r, V, -3, 3, -3, 3, 1, 500);

	interfaz.camara.angulo = 60.0;
	interfaz.camara.raspecto = 1.0;

	// CAMARA SEGURIDAD 1
	p1 = igvPunto3D(-78, 80, -98);
	r1 = igvPunto3D(30, 0, 40);
	V1 = igvPunto3D(0, 1, 0);

	interfaz.camaraSeguridad1.set(IGV_PERSPECTIVA, p1, r1, V1, -3, 3, -3, 3, 1, 500);

	interfaz.camaraSeguridad1.angulo = 60.0;
	interfaz.camaraSeguridad1.raspecto = 1.0;

	// CAMARA TECHO
	p2 = igvPunto3D(0, 1, 75);
	r2 = igvPunto3D(0, 40, 75);
	V2 = igvPunto3D(0, 0, -1);

	interfaz.camaraTecho.set(IGV_PERSPECTIVA, p2, r2, V2, -3, 3, -3, 3, 1, 500);

	interfaz.camaraTecho.angulo = 120.0;
	interfaz.camaraTecho.raspecto = 1.0;

	// CAMARA SUELO
	p3 = igvPunto3D(0, 40, 75);
	r3 = igvPunto3D(0, 0, 75);
	V3 = igvPunto3D(1, 0, 0);

	interfaz.camaraSuelo.set(IGV_PERSPECTIVA, p3, r3, V3, -3, 3, -3, 3, 1, 500);

	interfaz.camaraSuelo.angulo = 150.0;
	interfaz.camaraSuelo.raspecto = 1.0;

	// CAMARA SEGURIDAD 2
	p5 = igvPunto3D(78, 80, 198);
	r5 = igvPunto3D(30, 0, 40);
	V5 = igvPunto3D(0, 1, 0);

	interfaz.camaraSeguridad2.set(IGV_PERSPECTIVA, p5, r5, V5, -3, 3, -3, 3, 1, 500);

	interfaz.camaraSeguridad2.angulo = 60.0;
	interfaz.camaraSeguridad2.raspecto = 1.0;

	// CAMARA MODO SELECCION

	p6 = igvPunto3D(0, 210, 30);
	r6 = igvPunto3D(0, 210, 100);
	V6 = igvPunto3D(0, 1, 0);

	interfaz.camaraModoSeleccion.set(IGV_PERSPECTIVA, p6, r6, V6, -3, 3, -3, 3, 1, 500);

	interfaz.camaraModoSeleccion.angulo = 130.0;
	interfaz.camaraModoSeleccion.raspecto = 1.0;

	// CAMARA REC

	p7 = igvPunto3D(0, 250, 30);
	r7 = igvPunto3D(0, 250, 100);
	V7 = igvPunto3D(0, 1, 0);

	interfaz.camaraRec.set(IGV_PERSPECTIVA, p7, r7, V7, -3, 3, -3, 3, 1, 500);

	interfaz.camaraRec.angulo = 130.0;
	interfaz.camaraRec.raspecto = 1.0;

	// CAMARA ORBITA

	p8 = igvPunto3D(0, 25, 10);
	r8 = igvPunto3D(0, 0, 75);
	V8 = igvPunto3D(0, 1, 0);

	interfaz.camaraOrbita.set(IGV_PERSPECTIVA, p8, r8, V8, -3, 3, -3, 3, 1, 500);

	interfaz.camaraOrbita.angulo = 130.0;
	interfaz.camaraOrbita.raspecto = 1.0;
}
void igvInterfaz::creacionViewports()
{
	if (interfaz.objeto_seleccionado != -1)
	{
		glViewport(3, -25, interfaz.get_ancho_ventana() / 5, interfaz.get_alto_ventana() / 5);

		// establece los parámetros de la cámara y de la proyección
		interfaz.camaraModoSeleccion.aplicar();

		//visualiza la escena
		interfaz.escena.visualizar();
	}

	if (interfaz.cam == interfaz.CP)
	{
		glViewport(0, 0, interfaz.get_ancho_ventana(), interfaz.get_alto_ventana());

		// establece los parámetros de la cámara y de la proyección
		interfaz.camara.aplicar();

		//visualiza la escena
		interfaz.escena.visualizar();
	}

	if (interfaz.cam == interfaz.CS1)
	{
		//CAMARA REC
		glViewport(465, -5, interfaz.get_ancho_ventana() / 6, interfaz.get_alto_ventana() / 6);

		// establece los parámetros de la cámara y de la proyección
		interfaz.camaraRec.aplicar();

		//visualiza la escena
		interfaz.escena.visualizar();

		//CAMARA SEGURIDAD 1
		glViewport(0, 0, interfaz.get_ancho_ventana(), interfaz.get_alto_ventana()); // se establece el viewport

		interfaz.camaraSeguridad1.aplicar();

		interfaz.escena.visualizar(); // se visualiza la escena en el viewport
	}

	if (interfaz.cam == interfaz.CT)
	{
		glViewport(0, 0, interfaz.get_ancho_ventana(), interfaz.get_alto_ventana()); // se establece el viewport

		interfaz.camaraTecho.aplicar();

		interfaz.escena.visualizar(); // se visualiza la escena en el viewport
	}

	if (interfaz.cam == interfaz.CSu)
	{
		glViewport(0, 0, interfaz.get_ancho_ventana(), interfaz.get_alto_ventana()); // se establece el viewport

		interfaz.camaraSuelo.aplicar();

		interfaz.escena.visualizar(); // se visualiza la escena en el viewport
	}

	if (interfaz.cam == interfaz.CS2)
	{
		//CAMARA REC
		glViewport(465, -5, interfaz.get_ancho_ventana() / 6, interfaz.get_alto_ventana() / 6);

		// establece los parámetros de la cámara y de la proyección
		interfaz.camaraRec.aplicar();

		//visualiza la escena
		interfaz.escena.visualizar();

		//CAMARA SEGURIDAD 2
		glViewport(0, 0, interfaz.get_ancho_ventana(), interfaz.get_alto_ventana()); // se establece el viewport

		interfaz.camaraSeguridad2.aplicar();

		interfaz.escena.visualizar(); // se visualiza la escena en el viewport
	}

	// CAMARA ORBITA
	if (interfaz.cam == interfaz.ORB)
	{
		glViewport(0, 0, interfaz.get_ancho_ventana(), interfaz.get_alto_ventana()); // se establece el viewport

		interfaz.camaraOrbita.aplicar();

		interfaz.escena.visualizar(); // se visualiza la escena en el viewport
	}

	if (interfaz.cam == interfaz.MC)
	{
		glViewport(0, 250, interfaz.get_ancho_ventana() / 2, interfaz.get_alto_ventana() / 2); // ARRIBA IZQUIERDA (Cámara 1)

		// establece los parámetros de la cámara y de la proyección
		interfaz.camaraSeguridad1.aplicar();

		//visualiza la escena
		interfaz.escena.visualizar();

		glViewport(300, 250, interfaz.get_ancho_ventana() / 2, interfaz.get_alto_ventana() / 2); // ARRIBA DERECHA (Cámara 2)

		// establece los parámetros de la cámara y de la proyección
		interfaz.camaraSeguridad2.aplicar();

		//visualiza la escena
		interfaz.escena.visualizar();

		glViewport(0, 0, interfaz.get_ancho_ventana() / 2, interfaz.get_alto_ventana() / 2); // ABAJO IZQUIERDA (Cámara 3)

		// establece los parámetros de la cámara y de la proyección
		interfaz.camaraTecho.aplicar();

		//visualiza la escena
		interfaz.escena.visualizar();

		glViewport(300, 0, interfaz.get_ancho_ventana() / 2, interfaz.get_alto_ventana() / 2); // ABAJO DERECHA (Cámara 4)

		// establece los parámetros de la cámara y de la proyección
		interfaz.camaraSuelo.aplicar();

		//visualiza la escena
		interfaz.escena.visualizar();
	}
}

void igvInterfaz::set_glutMouseFunc(GLint boton, GLint estado, GLint x, GLint y) {

	if (boton == GLUT_LEFT_BUTTON)
	{
		if (estado == GLUT_DOWN)
		{
			interfaz.boton_retenido = true;
			interfaz.modo = IGV_SELECCIONAR;
			interfaz.cursorX = x;
			interfaz.cursorY = y;
			set_glutDisplayFunc();
			set_glutDisplayFunc();
		}
		else
		{
			interfaz.boton_retenido = false;
		}
	}
	// Apartado A: comprobar que se ha pulsado el botón izquierdo 

		// Apartado A: guardar que el boton se ha presionado o se ha soltado, si se ha pulsado hay que
		// pasar a modo IGV_SELECCIONAR

		// Apartado A: guardar el pixel pulsado

		// Apartado A: renovar el contenido de la ventana de vision 

}

void igvInterfaz::set_glutMotionFunc(GLint x, GLint y) {

	if (interfaz.boton_retenido && interfaz.objeto_seleccionado == 1)
	{
		if (interfaz.cursorX > x)
		{
			interfaz.escena.caja.rotacion = interfaz.escena.caja.rotacion - 15;
		}
		else
		{
			interfaz.escena.caja.rotacion = interfaz.escena.caja.rotacion + 15;
		}

		if (interfaz.cursorY > y)
		{
			interfaz.escena.caja.rotacionY = interfaz.escena.caja.rotacionY - 15;
		}
		else
		{
			interfaz.escena.caja.rotacionY = interfaz.escena.caja.rotacionY + 15;
		}
	}

	// Apartado B: si el botón está retenido y hay algún objeto seleccionado,
	// comprobar el objeto seleccionado y la posición del ratón y rotar
	// el objeto seleccionado utilziando el desplazamiento entre la posición 
	//inicial y final del ratón

	// Apartado B: guardar la nueva posición del ratón 

	// Apartado B: renovar el contenido de la ventana de vision 
	glutPostRedisplay();
}

void igvInterfaz::set_glutIdleFunc() {

	///// Apartado D: incluir el código para animar el modelo de la manera más realista posible

	if (interfaz.escena.m.ABREPUERTA)
	{
		if (interfaz.escena.m.rotacionPuerta < 90)
		{
			interfaz.escena.m.traslacionX = interfaz.escena.m.traslacionX + 0.08;
			interfaz.escena.m.traslacionZ = interfaz.escena.m.traslacionZ + 0.08;
			interfaz.escena.m.rotacionPuerta = interfaz.escena.m.rotacionPuerta + 5;
			glutPostRedisplay(); // renueva el contenido de la ventana de vision y redibuja la escena
		}

		if (interfaz.escena.m.rotacionPuerta == 90)
		{
			Sleep(3000);
			exit(1);
		}
	}
}