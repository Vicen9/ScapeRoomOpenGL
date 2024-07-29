#include "igvMaterial.h"

// Metodos constructores 

igvMaterial::igvMaterial () {
	
}

igvMaterial::~igvMaterial () {

}

igvMaterial::igvMaterial (const igvMaterial& p) {	//de copia
	Ka = p.Ka;
	Kd = p.Kd;
	Ks = p.Ks;
	Ns = p.Ns;
}

igvMaterial::igvMaterial(igvColor _Ka, igvColor _Kd, igvColor _Ks, double _Ns) {
	Ka = _Ka;
	Kd = _Kd;
	Ks = _Ks;
	Ns = _Ns;
}

// Metodos publicos 

void igvMaterial::aplicar(void) {

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Ka.cloneToFloatArray()); // REFLEXION LUZ AMBIENTAL
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Kd.cloneToFloatArray()); // REFLEXION LUZ AMBIENTAL
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, Ks.cloneToFloatArray()); // REFLEXION LUZ AMBIENTAL
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, Ns); // EXPONENTE DE PHONG

	float color[] = { 0.0, 0.0, 0.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, color); // EMISION DE COLOR

// APARTADO B
// Aplicar los valores de los atributos del objeto igvMaterial:
// - coeficiente de reflexi�n de la luz ambiental
// - coeficiente de reflexi�n difuso
// - coeficiente de reflesi�n especular
// - exponente de Phong

// establecer como color de emisi�n (0.0, 0.0, 0.0) (el objeto no es una fuente de luz)



}

void igvMaterial::set(igvColor _Ka, igvColor _Kd, igvColor _Ks, double _Ns) {
	Ka = _Ka;
	Kd = _Kd;
	Ks = _Ks;
	Ns = _Ns;
}



