#include <iostream>
#include "ListaEnlazada.h"

int main()
{
    ListaEnlazada listaAnimales;
    string n, h, e;
    cout << "Ingresar animal: ";
    cin >> n;
    cout << "Habitat: ";
    cin >> h;
    cout << "Estado: ";
    cin >> e;

    listaAnimales.agregarAnimal(n, h, e);
    listaAnimales.mostrarLista();
}