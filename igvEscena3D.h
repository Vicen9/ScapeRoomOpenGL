#ifndef __IGVESCENA3D
#define __IGVESCENA3D

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#endif

#include "igvFuenteLuz.h"
#include "igvMaterial.h"
#include "igvTextura.h"
#include "Modelo.h"
#include "igvCamara.h"
#include "Tractor.h"

class igvEscena3D {
	protected:
		// Atributos

		bool ejes;

		double rojoDifuso = 0.5;
		double rojoEspecular = 0.5;
		double exponentePhong = 120;

		double xFoco = 3.0;
		double yFoco = 1.0;

	public:

		igvCamara* CAMDEMON;
		double* ANGULOO;
		int* VELOC;
		Modelo m;
		Modelo caja;
		Tractor tractor;
		bool reset;

		// Constructores por defecto y destructor
		igvEscena3D();
		~igvEscena3D();

		// Metodos estáticos

		// Métodos
		// método con las llamadas OpenGL para visualizar la escena
    void visualizar();

		bool get_ejes() {return ejes;};
		void set_ejes(bool _ejes){ejes = _ejes;};

		double getRD();
		void setRD(double rojoD);

		double getRE();
		void setRE(double rojoE);

		double getEP();
		void setEP(double ePhong);

		double getxFoco();
		void setxFoco(double x);

		double getyFoco();
		void setyFoco(double y);

		void suelo();
		void paredFondo();
		void paredDerecha();
		void paredIzquierda();
		void paredFrontal();
		void techo();
		
		void habitacion();
};

#endif
