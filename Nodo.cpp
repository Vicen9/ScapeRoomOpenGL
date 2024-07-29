#include "Nodo.h"

Nodo::Nodo() {
};

Nodo::~Nodo() {
};

Nodo::Nodo(std::string s) {

	_tipo = s;
};


Nodo* Nodo::getHijo1()
{
	return hijo1;
}

Nodo* Nodo::getHijo2()
{
	return hijo2;
}


void Nodo::setHijo1(Nodo* n)
{
	hijo1 = n;
}

void Nodo::setHijo2(Nodo* n)
{
	hijo2 = n;
}

std::string Nodo::getTipo()
{
	return _tipo;
}

void Nodo::setTipo(std::string s)
{
	_tipo = s;
}