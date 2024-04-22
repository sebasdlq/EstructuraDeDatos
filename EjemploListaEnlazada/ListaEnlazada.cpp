#include "ListaEnlazada.h"
#include <iostream>

using namespace std;


ListaEnlazada::ListaEnlazada()
{
	inicio = nullptr;
	final = nullptr;
}

void ListaEnlazada::agregarAnimal(string nombre, string habitat, string estado) {
	Nodo* nuevoA = new Nodo(nombre, habitat, estado);

	if (inicio == nullptr) {
		//Lista vacia
		inicio = nuevoA;
		final = nuevoA;
	}
	else {
		final->siquiente = nuevoA;
		final = nuevoA;
	}
}

void ListaEnlazada::eliminarAnimal(string nombre)
{
	if (inicio == nullptr) {
		cerr << "Lista vacia\n";
		return;
	}

	Nodo* act = inicio;
	Nodo* anterior = nullptr;

	while (act->nombre != nombre)
	{
		anterior = act;
		act = act->siquiente;
		if (act == nullptr) {
			//No encontro al animal
			cerr << "No existe el animal";
			return;
		}
	}
	//Encontro al animal si sale del ciclo
	if (anterior == nullptr) {
		//Animal buscado esta al inicio de la lista
		inicio = act->siquiente;
	}
	else if(final == act){
		//Nodo esta al final
		anterior->siquiente = nullptr;
		final = anterior;
	}
	else {
		//Nodo esta en medio
		anterior->siquiente = act->siquiente;
	}
	delete act;
	act = nullptr;
}

Nodo* ListaEnlazada::buscarAnimal(string nombre)
{
	Nodo* act = inicio;
	while (act != nullptr && act->nombre != nombre)
	{
		act = act->siquiente;
	}
	return act; // Retorna nullptr si no lo encontro
}

void ListaEnlazada::mostrarLista()
{
	Nodo* act = inicio;
	while (act != nullptr) {
		cout << "\nNombre: " << act->nombre;
		cout << "\nHabitat: " << act->habitat;
		cout << "\nEstado: " << act->estadoDeConservacion;
		cout << "\n\n";

		act = act->siquiente;
	}
}
