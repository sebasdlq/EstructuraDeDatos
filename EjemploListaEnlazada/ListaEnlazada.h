#pragma once
#include "Nodo.h"
#include <iostream>

using namespace std;
class ListaEnlazada
{
private:
	Nodo* inicio;
	Nodo* final;
public:
	ListaEnlazada();
	void agregarAnimal(string nombre, string habitat, string estado);
	void eliminarAnimal(string nombre);
	Nodo* buscarAnimal(string nombre);
	void mostrarLista();
};

