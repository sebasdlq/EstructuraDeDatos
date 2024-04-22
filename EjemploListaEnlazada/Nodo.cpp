#include "Nodo.h"
#include <iostream>

Nodo::Nodo(string n, string h, string est)
{
	this->nombre = n;
	this->habitat = h;
	this->estadoDeConservacion = est;

	siquiente = NULL;
}
